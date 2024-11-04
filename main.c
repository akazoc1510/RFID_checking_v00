#define RCC_AHB1ENR (*(unsigned int *) 0x40023830)
#define GPIOG_MODER (*(unsigned int *) 0x40021800)
#define GPIOG_OSPEEDR (*(unsigned int *) 0x40021800)
#define GPIOG_OTYPER (*(unsigned int *) 0x40021804)
#define GPIOG_ODR (*(unsigned int *) 0x40021814)
#define GPIOA_MODER (*(unsigned int *) 0x40020000)
#define GPIOA_OSPEEDR (*(unsigned int *) 0x40020008)
#define GPIOA_PUPDR (*(unsigned int *) 0x4002000C)
#define GPIOA_OTYPES (*(unsigned int *) 0x40020004)
#define GPIOA_IDR (*(unsigned int *) 0x40020010)


void delay(int ms) {
    for (int i = 0; i < ms * 4000; i++) {

    }
}


int main() {

	RCC_AHB1ENR |= 1<<0; 	//Enable clock for port A
	RCC_AHB1ENR |= 1<<6;	//Enable clock for port G

	//GPIOA setting
	GPIOA_MODER &= ~(3 << 0);
	GPIOA_PUPDR &= ~(3 << 0);
	
    //GPIOG setting
    GPIOG_MODER |= (1 << 26) | (1 << 28);
    GPIOG_OSPEEDR |= (1 << 26) | (1 << 28);
    GPIOG_OTYPER &= ~((1 << 13) | (1 << 14));

    for(;;) {
        if (GPIOA_IDR & (1 << 0)) {
            GPIOG_ODR |= (1 << 13);  //Enable led green
            GPIOG_ODR &= ~(1 << 14); //Disable led red
        } else {
            GPIOG_ODR |= (1 << 14);	 //Enable led red
            GPIOG_ODR &= ~(1 << 13); //Disabel led green 
        }
        delay(50);
    }
}