#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

/** GPIO - Register Layout Typedef */
typedef struct {
    volatile unsigned int MODER;
	volatile unsigned int OTYPER;
	volatile unsigned int OSPEEDR;
	volatile unsigned int PUPDR;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
	volatile unsigned int BSRR;
	volatile unsigned int LCKR;
	volatile unsigned int AFRL;
	volatile unsigned int AFRH;
} Gpio_TypeDef;

#define GPIOA_BASE	(0x40020000UL)
#define GPIOA       ((Gpio_TypeDef *)GPIOA_BASE)
#define GPIOB_BASE	(0x40020400UL)
#define GPIOB       ((Gpio_TypeDef *)GPIOB_BASE)
#define GPIOC_BASE	(0x40020800UL)
#define GPIOC       ((Gpio_TypeDef *)GPIOC_BASE)
#define GPIOD_BASE	(0x40020C00UL)
#define GPIOD       ((Gpio_TypeDef *)GPIOD_BASE)
#define GPIOE_BASE  (0x40021000UL)
#define GPIOE       ((Gpio_TypeDef *)GPIOE_BASE)
#define GPIOF_BASE  (0x40021400UL)
#define GPIOF       ((Gpio_TypeDef *)GPIOF_BASE)
#define GPIOG_BASE  (0x40021800UL)
#define GPIOG       ((Gpio_TypeDef *)GPIOG_BASE)
#define GPIOH_BASE  (0x40021C00UL)
#define GPIOH       ((Gpio_TypeDef *)GPIOH_BASE)
#define GPIOI_BASE  (0x40022000UL)
#define GPIOI       ((Gpio_TypeDef *)GPIOI_BASE)
#define GPIOJ_BASE  (0x40022400UL)
#define GPIOJ       ((Gpio_TypeDef *)GPIOJ_BASE)
#define GPIOK_BASE  (0x40022800UL)
#define GPIOK       ((Gpio_TypeDef *)GPIOK_BASE)

#endif
