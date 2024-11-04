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
    /* Check parameter */
    

}

void Gpio_WriteToOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber, unsigned char value)
{
    /* Check parameter */
}


void Gpio_SetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */

}

void Gpio_ResetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */

}

void Gpio_ToggleOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */

}


unsigned char GPIO_ReadFromInputPin(Gpio_Type *pGPIOx, unsigned char PinNumber)             
{
    /* Check parameter */               
}


