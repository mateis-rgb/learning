/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * General stdiodemo defines
 *
 * $Id: defines.h,v 1.1.2.1 2005/12/28 22:35:08 joerg_wunsch Exp $
 */

/* CPU frequency */
#define F_CPU 8000000UL

/* UART baud rate */
//#define UART_BAUD  9600

//Nous avons change le nom des variables par rapport à notre Application

/* HD44780 LCD port connections */
#define HD44780_PORTc A
#define HD44780_PORT D
#define HD44780_RS PA7  //première carte d'essai
#define HD44780_RW PA6
#define HD44780_E  PA5
#define HD44780_D4 PD4
#define HD44780_D5 PD5
#define HD44780_D6 PD6
#define HD44780_D7 PD7
#define RANG_LSB    4   //définit le rang dans l'octet du LSB du quartet de données
