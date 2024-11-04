#define RCC_AHB1ENR (*(unsigned int *) 0x40023830)
#define GPIOG_MODER (*(unsigned int *) 0x40021800)
#define GPIOG_OSPEEDR (*(unsigned int *) 0x40021808)
#define GPIOG_OTYPER (*(unsigned int *) 0x40021804)
#define GPIOG_ODR (*(unsigned int *) 0x40021814)
#define GPIOA_MODER (*(unsigned int *) 0x40020000)
#define GPIOA_PUPDR (*(unsigned int *) 0x4002000C)
#define GPIOA_IDR (*(unsigned int *) 0x40020010)
#define GPIOA_OSPEEDR (*(unsigned int *) 0x40020008)
#define RCC_APB2ENR (*(unsigned int *) 0x40023844)
#define SYSCFG_EXTICR1 (*(unsigned int *) 0x40013808)
#define NVIC_ISER0 (*(unsigned int *) 0xE000E100)
#define EXTI_RTSR (*(unsigned int *) 0x40013C08)
#define EXTI_IMR (*(unsigned int *) 0x40013C00)
#define EXTI_PR (*(unsigned int *) 0x40013C14)
#define RCC_CR (*(unsigned int *) 0x40023800)
#define RCC_PLLCFGR (*(unsigned int *) 0x40023804)
#define RCC_CFGR (*(unsigned int *) 0x40023808)

	

unsigned int interrupt_flag = 0;


void EXTI0_IRQHandler(void) {
    interrupt_flag = 1;  
    EXTI_PR = 1;
}

void HSE_clock(void) {
		RCC_CR |= 1 << 16;  // Enable clock HSE

    unsigned int time_out = 10;
    while (!(RCC_CR & (1 << 17))) {
        if (time_out == 0) { 
            break;
        }
        time_out--; // Decrement timeout counter
    }
}

void MCO1_init(void)
{
		RCC_AHB1ENR |= 1 << 0;	// Enable clock for port A
		GPIOA_MODER |= 2 << 16;			// Set alt function
		GPIOA_OSPEEDR |= (3 << 16);	// set speed 
		RCC_CFGR |= (2 << 21);			// select HSE is source clock
		RCC_CFGR |= (6 << 24);			// MCO1 = 8MHz/4 
}

void System_clocks(void) {
    RCC_CFGR |= (0 << 4);   // AHBx_CLK = 180 MHz (no division, 0b000)
    RCC_CFGR |= (6 << 10);  // APB1_CLK = 22.5 MHz (divide by 8, 0b101)
    RCC_CFGR |= (5 << 13);  // APB2_CLK = 45 MHz (divide by 4, 0b100)
		RCC_CFGR |= (2 << 0);
		while ((RCC_CFGR & (3 << 2)) != (2 << 2)) {}
}

void PLL_clock(void) {
    RCC_PLLCFGR = 0; 
    RCC_PLLCFGR = (8 << 0)   // PLLM = 8
                | (360 << 6) // PLLN = 360
                | (0 << 16)  // PLLP = 2 (00 corresponds to /2)
                | (1 << 22); // HSE source for PLL

    RCC_CR |= (1 << 24); // PLL ON
    while (!(RCC_CR & (1 << 25))){}
}

int main() {
    HSE_clock();
    PLL_clock();
		System_clocks();
    RCC_AHB1ENR |= (1 << 0);    // Enable clock for port A
    RCC_AHB1ENR |= (1 << 6);    // Enable clock for port G
    RCC_APB2ENR |= (1 << 14);   // Enable clock for SYSCFG
    GPIOA_MODER &= ~(3 << 0);  
    GPIOA_PUPDR &= ~(3 << 0);

    GPIOG_MODER |= (1 << 26) | (1 << 28);  // set mode for port 13/14
    GPIOG_OSPEEDR |= (1 << 26) | (1 << 28);  
    GPIOG_OTYPER &= ~((1 << 13) | (1 << 14));  

    SYSCFG_EXTICR1 &= ~(15 << 0);  
    EXTI_IMR |= (1 << 0);  
    EXTI_RTSR |= (1 << 0);
    NVIC_ISER0 |= (1 << 6);

    GPIOG_ODR |= (1 << 13); 
    GPIOG_ODR &= ~(1 << 14);

    while (1) {
        if (interrupt_flag == 1) {  
            GPIOG_ODR ^= (1 << 13); 
            GPIOG_ODR ^= (1 << 14);  
            interrupt_flag = 0;
        }
    }
}
