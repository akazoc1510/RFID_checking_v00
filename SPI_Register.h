#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

/** SPI - Register Layout Typedef */
typedef struct {
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int SR;
    volatile unsigned int DR;
    volatile unsigned int CRCPR;
    volatile unsigned int RXCRCR;
    volatile unsigned int TXCRCR;
    volatile unsigned int CFGR;
    volatile unsigned int PR;
} SPI_Type;

#define SPI1_BASE	(0x40013000)
#define SPI1   ((SPI_Type *)SPI1_BASE)
#define SPI2_BASE   (0x40003800)
#define SPI2   ((SPI_Type *)SPI2_BASE)
#define SPI3_BASE   (0x40003C00)
#define SPI3   ((SPI_Type *)SPI3_BASE)
#define SPI4_BASE   (0x40013400)
#define SPI4   ((SPI_Type *)SPI4_BASE)
#define SPI5_BASE   (0x40015000)
#define SPI5  ((SPI_Type *)SPI5_BASE)
#define SPI6_BASE   (0x40015400)
#define SPI6  ((SPI_Type *)SPI6_BASE)


#endif
