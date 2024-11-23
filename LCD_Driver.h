#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include <stdint.h>
#include "Gpio_Register.h"
#include "SPI_Register.h"

// Định nghĩa chân GPIO
#define LCD_CS_PIN    6  // PF6
#define LCD_DCX_PIN   8  // PF8
#define LCD_RESET_PIN 10 // PF10

// GPIO Utilities
void GPIO_Init(void);
void GPIO_WritePin(Gpio_TypeDef *GPIO, int pin, int state);
int GPIO_ReadPin(Gpio_TypeDef *GPIO, int pin);

// SPI Utilities
void SPI5_Init(void);
void SPI_Send(uint8_t data);

// LCD Utilities
void LCD_Init(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void LCD_DrawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bgcolor);
void LCD_DrawString(uint16_t x, uint16_t y, const char *str, uint16_t color, uint16_t bgcolor);

#endif
