/*
 * Afficheur_LCD.h
 */ 

#ifndef  AFFICHEUR_LCD_H_
#define  AFFICHEUR_LCD_H_

/**
 * @brief Initialise la liaison s�rie
 * 
 */
void InitUSART(void);

/**
 * @brief Envoie un caract�re ASCII au LCD et renvoie le caract�re envoy�
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
 * @brief Envoie un caract�re dans le LCD via la fonction printf
 * 
 */
int sendOneChar(char codeASCII, FILE *unused);  // appel�e par printf()

/**
 * @brief Place le curseur � la position x y 
 * 
 * @param { char } x
 * @param { char } y
 * 
 */
void placeCursor (char x, char y);

/**
 * @brief Envoi une chaine de caract�re dans le LCD
 * 
 * @param { unsigned char[] } message 
 * 
 * @returns
 */
void print (unsigned char message[]);

#endif   /* AFFICHEUR_LCD_H_ */