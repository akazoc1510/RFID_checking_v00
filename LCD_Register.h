#ifndef LTDC_REGISTER_H
#define LTDC_REGISTER_H

/** LTDC-TFT - Register Layout Typedef */
typedef struct
{
  volatile int RESERVED0[2];  
  volatile int SSCR;      
  volatile int BPCR;    
  volatile int AWCR;           
  volatile int TWCR;        
  volatile int GCR;         
  volatile int  RESERVED1[2]; 
  volatile int SRCR;        
  volatile int  RESERVED2[1];
  volatile int BCCR;         
  volatile int  RESERVED3[1];
  volatile int IER;
  volatile int ISR; 
  volatile int ICR;
  volatile int LIPCR;
  volatile int CPSR;
  volatile int CDSR;
} LTDC_TypeDef;

/* LTDC Layer 1-2 register layout*/
typedef struct
{
  volatile int CR;
  volatile int WHPCR;
  volatile int WVPCR;
  volatile int CKCR;
  volatile int PFCR;
  volatile int CACR;
  volatile int DCCR;
  volatile int BFCR;
  volatile int RESERVED0[2];
  volatile int CFBAR;
  volatile int CFBLR;
  volatile int CFBLNR;
  volatile int RESERVED1[3];
  volatile int CLUTWR;
} LTDC_Layer_TypeDef;

#define LTDC_BASE	            (0x40016800UL)
#define LTDC                  ((LTDC_TypeDef *)LTDC_BASE)
#define LTDC_Layer1_BASE      (LTDC_BASE + 0x84UL)
#define LTDC_L1               ((LTDC_Layer_TypeDef *)LTDC_Layer1_BASE)
#define LTDC_Layer2_BASE      (LTDC_BASE + 0x104UL)
#define LTDC_L2               ((LTDC_Layer_TypeDef *)LTDC_Layer2_BASE)
#endif



