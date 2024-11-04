#ifndef UART_REGISTER_H
#define UART_REGISTER_H

/** UART - Register Layout Typedef */
typedef struct {
    volatile unsigned int CR;
    volatile unsigned int DR;
    volatile unsigned int BRR;
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int CR3;
    volatile unsigned int GTPR;
} UART_Type;

#define USART1_BASE 0x40011000
#define USART1   ((UART_Type *)USART1_BASE)
#define USART2_BASE 0x40004400
#define USART2   ((UART_Type *)USART2_BASE)
#define USART3_BASE 0x40004800
#define USART3   ((UART_Type *)USART3_BASE)
#define USART6_BASE 0x40011400
#define USART6   ((UART_Type *)USART6_BASE)
#define UART4_BASE 0x40004C00
#define UART4    ((UART_Type *)UART4_BASE)
#define UART5_BASE 0x40005000
#define UART5    ((UART_Type *)UART5_BASE)
#define UART7_BASE 0x40007800
#define UART7    ((UART_Type *)UART7_BASE)
#define UART8_BASE 0x40007C00
#define UART8    ((UART_Type *)UART8_BASE)
#endif

