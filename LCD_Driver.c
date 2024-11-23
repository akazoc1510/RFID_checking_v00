#include "LCD_Driver.h"
#include "Gpio_Register.h"
#include "SPI_Register.h"
#include "RCC_Register.h"
#include <stdint.h>

// Font dữ liệu 5x7 cho các ký tự ASCII
const uint8_t Font5x7[96][5] = {
    {0x00, 0x00, 0x00, 0x00, 0x00}, // Space
    {0x00, 0x00, 0x5F, 0x00, 0x00}, // !
    // Thêm các ký tự khác nếu cần...
};

void GPIO_Init(void) {
    RCC->AHB1ENR |= (1 << 5); // Bật clock cho GPIOF
    GPIOF->MODER &= ~((3 << (6 * 2)) | (3 << (8 * 2)) | (3 << (10 * 2)));
    GPIOF->MODER |= ((1 << (6 * 2)) | (1 << (8 * 2)) | (1 << (10 * 2)));
    GPIOF->BSRR = (1 << 6) | (1 << 8) | (1 << 10); // Đặt CS, DCX, RESET ở mức HIGH
}

// Ghi dữ liệu vào một chân GPIO
void GPIO_WritePin(Gpio_TypeDef *GPIO, int pin, int state) {
    if (state) {
        GPIO->BSRR = (1 << pin);       // Set bit
    } else {
        GPIO->BSRR = (1 << (pin + 16)); // Reset bit
    }
}

void SPI5_Init(void) {
    RCC->APB2ENR |= (1 << 20); // Bật clock cho SPI5
    SPI5->CR1 = (1 << 2) | (3 << 3); // Chế độ Master, Baud Rate fPCLK/16
    SPI5->CR2 = 0;
    SPI5->CR1 |= (1 << 6); // Bật SPI
}


// Gửi một byte qua SPI
void SPI_Send(uint8_t data) {
    while (!(SPI5->SR & (1 << 1))) {} // Chờ TXE sẵn sàng
    SPI5->DR = data;
    while (!(SPI5->SR & (1 << 0))) {} // Chờ RXNE sẵn sàng
}

void LCD_Init(void) {
    GPIO_WritePin(GPIOF, LCD_RESET_PIN, 0); // RESET = LOW
    for (volatile int i = 0; i < 100000; i++);
    GPIO_WritePin(GPIOF, LCD_RESET_PIN, 1); // RESET = HIGH
    for (volatile int i = 0; i < 100000; i++);

    LCD_SendCommand(0x01); // Software Reset
    for (volatile int i = 0; i < 100000; i++);
    LCD_SendCommand(0x28); // Display OFF
    LCD_SendCommand(0x3A); // Pixel Format Set
    LCD_SendData(0x55);    // RGB565
    LCD_SendCommand(0x29); // Display ON
}


// Gửi lệnh đến LCD
void LCD_SendCommand(uint8_t cmd) {
    GPIO_WritePin(GPIOF, LCD_DCX_PIN, 0); // DCX = LOW (Command mode)
    GPIO_WritePin(GPIOF, LCD_CS_PIN, 0);  // CS = LOW (Kích hoạt)
    SPI_Send(cmd);
    GPIO_WritePin(GPIOF, LCD_CS_PIN, 1);  // CS = HIGH (Không kích hoạt)
}

// Gửi dữ liệu đến LCD
void LCD_SendData(uint8_t data) {
    GPIO_WritePin(GPIOF, LCD_DCX_PIN, 1); // DCX = HIGH (Data mode)
    GPIO_WritePin(GPIOF, LCD_CS_PIN, 0);  // CS = LOW (Kích hoạt)
    SPI_Send(data);
    GPIO_WritePin(GPIOF, LCD_CS_PIN, 1);  // CS = HIGH (Không kích hoạt)
}

void LCD_DrawString(uint16_t x, uint16_t y, const char *str, uint16_t color, uint16_t bgcolor) {
    while (*str) {
        LCD_DrawChar(x, y, *str, color, bgcolor);
        x += 6; // Khoảng cách giữa các ký tự
        str++;
    }
}

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
    LCD_SendCommand(0x2A); // Column Address Set
    LCD_SendData(x >> 8); LCD_SendData(x & 0xFF);
    LCD_SendCommand(0x2B); // Page Address Set
    LCD_SendData(y >> 8); LCD_SendData(y & 0xFF);
    LCD_SendCommand(0x2C); // Memory Write
    LCD_SendData(color >> 8); LCD_SendData(color & 0xFF);
}


// Vẽ ký tự lên LCD
void LCD_DrawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bgcolor) {
    const uint8_t *bitmap = Font5x7[c - ' ']; // Lấy font của ký tự
    for (uint8_t i = 0; i < 5; i++) {
        uint8_t line = bitmap[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (line & (1 << j)) {
                LCD_DrawPixel(x + i, y + j, color); // Vẽ pixel màu
            } else {
                LCD_DrawPixel(x + i, y + j, bgcolor); // Vẽ pixel nền
            }
        }
    }
}
