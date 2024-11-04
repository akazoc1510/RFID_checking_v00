#ifndef GPIO_H
#define GPIO_H

#include "Gpio_Register.h"

/*! 
 * @brief GPIO pin configuration structure
 */
typedef struct {
    unsigned char PinNumber;     /*!< Pin number (0-15) */
    unsigned char Mode;          /*!< Mode (input/output) */
    unsigned char Type;          /*!< Type (push-pull/open-drain) */
    unsigned char Speed;         /*!< Speed (low/medium/high) */
    unsigned char Pull;          /*!< Pull (no pull/pull-up/pull-down) */
} Gpio_PinConfigType;

/*! 
 * @brief GPIO configuration structure
 */
typedef struct {
    Gpio_Type *GPIOx;            /*!< Base address of GPIO port */
    Gpio_PinConfigType *pins;    /*!< Array of pin configurations */
    unsigned int pinCount;       /*!< Number of configured pins */
} Gpio_ConfigType;

/*! 
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] ConfigPtr The configuration structure
 */
void Gpio_Init(const Gpio_ConfigType* ConfigPtr);

/*!
 * @brief Writes a value to the specified output pin
 *
 * @param[in] pGPIOx The GPIO port
 * @param[in] PinNumber The pin number (0-15)
 * @param[in] value The value to write (0 or 1)
 */
void Gpio_WriteToOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber, unsigned char value);

/*!
 * @brief Sets the specified output pin to high
 *
 * @param[in] pGPIOx The GPIO port
 * @param[in] PinNumber The pin number (0-15)
 */
void Gpio_SetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);

/*!
 * @brief Resets the specified output pin to low
 *
 * @param[in] pGPIOx The GPIO port
 * @param[in] PinNumber The pin number (0-15)
 */
void Gpio_ResetOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);

/*!
 * @brief Toggles the specified output pin
 *
 * @param[in] pGPIOx The GPIO port
 * @param[in] PinNumber The pin number (0-15)
 */
void Gpio_ToggleOutputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);

/*!
 * @brief Reads a value from the specified input pin
 *
 * @param[in] pGPIOx The GPIO port
 * @param[in] PinNumber The pin number (0-15)
 * @return The value read from the pin (0 or 1)
 */
unsigned char GPIO_ReadFromInputPin(Gpio_Type *pGPIOx, unsigned char PinNumber);

#endif /* GPIO_H */
