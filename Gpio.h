#ifndef GPIO_H
#define GPIO_H

#include "Gpio_Registers.h"

typedef struct
{
    Gpio_Type         *      base;                  /*!< Gpio base pointer.  */
    unsigned char            GPIO_PinNumber;        /*!< Pin number.*/
    unsigned char            GPIO_PinMode;          /*!< Pin_mode */
    ........
} Gpio_ConfigType;

/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] ConfigPtr:  The configuration structure
 * @return 
 */
void Gpio_Init(const Gpio_ConfigType* ConfigPtr);
void Gpio_WriteToOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber, unsigned char value);
void Gpio_SetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);
void Gpio_ResetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);
void Gpio_ToggleOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);
unsigned char Gpio_ReadFromInputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);

#endif
