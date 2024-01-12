#ifndef _board_h_
#define _board_h_


/* 8086 Demo Board support functions and macros */


// Absolute value of an argument
#define ABS(a) ((a>=0)?a:-a)

// Set an Interrupt Handler
void set_int(unsigned char int_no, void * service_proc);

// I/O Ports input and output
void outp(unsigned int addr, char data);
char inp(unsigned int addr);


/* I/O Address Bus decode - every device gets 0x200 addresses */

#define IO0  0x0000
#define IO1  0x0200
#define IO2  0x0400
#define IO3  0x0600
#define IO4  0x0800
#define IO5  0x0A00
#define IO6  0x0C00
#define IO7  0x0E00
#define IO8  0x1000
#define IO9  0x1200
#define IO10 0x1400
#define IO11 0x1600
#define IO12 0x1800
#define IO13 0x1A00
#define IO14 0x1C00
#define IO15 0x1E00

/* 8251A USART */
 
#define ADR_USART_DATA (IO0 + 0x00)
#define ADR_USART_CMD  (IO0 + 0x02)
#define ADR_USART_STAT ADR_USART_CMD

/* 8253A Timer */

#define ADR_TIMER_CONTROL (IO2 + 0x06)
#define ADR_TIMER_DATA0   (IO2 + 0x00)
#define ADR_TIMER_DATA1   (IO2 + 0x02)
#define ADR_TIMER_DATA2   (IO2 + 0x04)

#define TIMER_COUNTER0	0x00
#define TIMER_COUNTER1	0x40
#define TIMER_COUNTER2	0x80

#define TIMER_LATCH	0x00
#define TIMER_LSB	0x10
#define TIMER_MSB	0x20
#define TIMER_LSB_MSB	0x30

#define TIMER_MODE0	0x00
#define TIMER_MODE1	0x02
#define TIMER_MODE2	0x04
#define TIMER_MODE3	0x06
#define TIMER_MODE4	0x08
#define TIMER_MODE5	0x09

#define TIMER_BCD	0x01

/* 8255A PIO */

#define ADR_PPI_PORTA	(IO1)
#define ADR_PPI_PORTB	(IO1 + 0x02)
#define ADR_PPI_PORTC	(IO1 + 0x04)
#define ADR_PPI_CONTROL	(IO1 + 0x06)

#define PPI_PORTA_INP	0x10
#define PPI_PORTA_OUT	0x00
#define PPI_PORTB_INP	0x02
#define PPI_PORTB_OUT	0x00
#define PPI_PORTCL_INP	0x01
#define PPI_PORTCL_OUT	0x00
#define PPI_PORTCH_INP	0x08
#define PPI_PORTCH_OUT	0x00
#define PPI_MODE_BCL_0	0x00
#define PPI_MODE_BCL_1	0x04
#define PPI_MODE_ACH_0	0x00
#define PPI_MODE_ACH_1	0x20
#define PPI_MODE_ACH_2	0x40
#define PPI_ACTIVE	0x80

#endif
