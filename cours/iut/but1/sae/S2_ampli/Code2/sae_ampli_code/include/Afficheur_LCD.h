/*
 * Afficheur_LCD.h
 */ 

#ifndef  AFFICHEUR_LCD_H_
#define  AFFICHEUR_LCD_H_

/**
 * @brief Initialise la liaison série
 * 
 */
void InitUSART(void);

/**
 * @brief Envoie un caractère ASCII au LCD et renvoie le caractère envoyé
 * 
 * @param { char } codeASCIII
 * 
 * @returns
 */
char putCharToLCD(char codeASCII);

/**
 * @brief Initialise le LCD
 * 
 */
void InitLCD(void);


/**
 * @brief Place le curseur à la position x y 
 * 
 * @param { char } x
 * @param { char } y
 * 
 */
void placeCursor (char x, char y);

/**
 * @brief Envoi une chaine de caractère dans le LCD
 * 
 * @param { unsigned char[] } message 
 * 
 * @returns
 */
void print (unsigned char message[]);


#endif   /* AFFICHEUR_LCD_H_ */