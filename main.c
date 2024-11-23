#include <stdint.h>
#include "Gpio_Register.h"
#include "SPI_Register.h"
#include "RCC_Register.h"
#include "LCD_Driver.h"

#define WHITE 0xFFFF
#define BLACK 0x0000

// Cấu hình Clock HSE
void HSE_clock(void) {
    RCC->CR |= (1 << 16);  // Bật HSE
    while (!(RCC->CR & (1 << 17))) {} // Chờ HSE sẵn sàng
}

// Cấu hình PLL
void PLL_clock(void) {
    RCC->PLLCFGR = (8 << 0) | (360 << 6) | (0 << 16) | (1 << 22); // PLLM = 8, PLLN = 360, PLLP = 2, nguồn HSE
    RCC->CR |= (1 << 24);  // Bật PLL
    while (!(RCC->CR & (1 << 25))) {} // Chờ PLL sẵn sàng
}

// Cấu hình clock hệ thống
void System_clocks(void) {
    RCC->CFGR |= (2 << 0);  // Sử dụng PLL làm clock chính
    while ((RCC->CFGR & (3 << 2)) != (2 << 2)) {} // Chờ PLL được sử dụng
}

int main(void) {
    HSE_clock();        // Khởi tạo clock HSE
    PLL_clock();        // Cấu hình PLL
    System_clocks();    // Bật clock hệ thống
    GPIO_Init();        // Khởi tạo GPIO
    SPI5_Init();        // Khởi tạo SPI5
    LCD_Init();         // Khởi tạo LCD

    // Hiển thị chuỗi trên LCD
    LCD_DrawString(10, 10, "STM32 LCD", 0xFFFF, 0x0000);
    LCD_DrawString(10, 30, "19520596", 0xFFFF, 0x0000);

    while (1);
    return 0;
}
