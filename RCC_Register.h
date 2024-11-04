#ifndef RCC_REGISTER_H
#define RCC_REGISTER_H

/** RCC - Register Layout Typedef */
typedef struct {
    volatile unsigned int CR;
    volatile unsigned int PLLCFGR;
    volatile unsigned int CFGR;
    volatile unsigned int AHB1RSTR;
    volatile unsigned int AHB2RSTR;
    volatile unsigned int AHB3RSTR;
    volatile unsigned int APB1RSTR;
    volatile unsigned int APB2RSTR;
    volatile unsigned int AHB1ENR;
    volatile unsigned int AHB2ENR;
    volatile unsigned int AHB3ENR;
    volatile unsigned int APB1ENR;
    volatile unsigned int APB2ENR;
    volatile unsigned int AHB1LPENR;
    volatile unsigned int AHB2LPENR;
    volatile unsigned int AHB3LPENR;
    volatile unsigned int APB1LPENR;
    volatile unsigned int APB2LPENR;
    volatile unsigned int BDCR;
    volatile unsigned int CSR;
    volatile unsigned int SSCGR;
    volatile unsigned int PLLI2SCFGR;
    volatile unsigned int PLLSAICFGR;
    volatile unsigned int DCKCFGR;
} RCC_Type;

#define RCC_BASE	(0x40023800)
#define RCC   ((RCC_Type *)RCC_BASE)


#endif
