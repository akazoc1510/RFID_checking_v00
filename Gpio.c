#include "Gpio.h"

/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pinCount The number of configured pins in structure
 * @param[in] config The configuration structure
 * @return 
 */
void Gpio_Init(const Gpio_ConfigType* ConfigPtr)
{
    if (ConfigPtr == NULL) return; // Kiểm tra con trỏ cấu hình

    for (unsigned int i = 0; i < ConfigPtr->pinCount; i++) {
        // Cấu hình chế độ
        GPIO_SetMode(ConfigPtr->GPIOx, ConfigPtr->pins[i].PinNumber, ConfigPtr->pins[i].Mode);
        // Cấu hình kiểu
        GPIO_SetType(ConfigPtr->GPIOx, ConfigPtr->pins[i].PinNumber, ConfigPtr->pins[i].Type);
        // Cấu hình tốc độ
        GPIO_SetSpeed(ConfigPtr->GPIOx, ConfigPtr->pins[i].PinNumber, ConfigPtr->pins[i].Speed);
        // Cấu hình pull
        GPIO_SetPull(ConfigPtr->GPIOx, ConfigPtr->pins[i].PinNumber, ConfigPtr->pins[i].Pull);
    }
}

void Gpio_WriteToOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber, unsigned char value)
{
    if (pGPIOx == NULL || PinNumber > 15) return; // Kiểm tra tham số

    GPIO_WritePin(pGPIOx, PinNumber, value); // Ghi giá trị vào chân
}

void Gpio_SetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)
{
    if (pGPIOx == NULL || PinNumber > 15) return; // Kiểm tra tham số

    GPIO_WritePin(pGPIOx, PinNumber, 1); // Đặt chân lên 1
}

void Gpio_ResetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)
{
    if (pGPIOx == NULL || PinNumber > 15) return; // Kiểm tra tham số

    GPIO_WritePin(pGPIOx, PinNumber, 0); // Đặt chân xuống 0
}

void Gpio_ToggleOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)
{
    if (pGPIOx == NULL || PinNumber > 15) return; // Kiểm tra tham số

    GPIO_TogglePin(pGPIOx, PinNumber); // Đảo giá trị chân
}

unsigned char GPIO_ReadFromInputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)             
{
    if (pGPIOx == NULL || PinNumber > 15) return 0; // Kiểm tra tham số

    return GPIO_ReadPin(pGPIOx, PinNumber); // Đọc giá trị từ chân
}
