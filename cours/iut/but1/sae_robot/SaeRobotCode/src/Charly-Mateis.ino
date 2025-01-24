#include <Arduino.h>

//===== Déclaration des broches =====================
const int PWMG = 10; // Signal PWM Gauche vers le pont en H
const int PWMD = 9;  // Signal PWM Droit vers le pont en H
const int SENSG = 8; // Signal SENS Gauche vers le pont en H
const int SENSD = 7; // Signal SENS Droit vers le pont en H
const int jack = 6;  // Entrée du Jack de démarrage du robot
const int Capteurs_IR1 = A1; // Capteur infrarouge gauche (Analog)
const int Capteurs_IR2 = 2; // Capteur infrarouge centre (Digital)
const int Capteurs_IR3 = A0; // Capteur infrarouge droit (Analog)
const int Capteur_Sol = A3;  // Détecteur de sol
const int Debug_LED = 4;

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6

unsigned char state = S1;


/**
 * @brief Retourne un NL haut si la ligne blanche est detectée.
 * 
 * @return unsigned char 
 */
unsigned char Detecter_Ligne_Blanche(void);

/**
 * @brief Fait avancer le robot tout droit
 * 
 */
void Robot_Avance(void);

/**
 * @brief Fait reculer le robot
 * 
 */
void Robot_Reculer(void);

/**
 * @brief Fait arreter le robot
 * 
 */
void Arret_Moteur(void);

/**
 * @brief Retourne un NL haut si le jack est retiré
 * 
 * @return unsigned char 
 */
unsigned char Jack_retire(void);

/**
 * @brief Retourne un NL haut si un obstacle est détecté
 * 
 * @return unsigned char 
 */
unsigned char Detecter_Obstacle(void);

/**
 * @brief Retourne un NL haut si un obstacle est détecté sur les côtés
 * 
 * @return unsigned char 
 */
unsigned char Detecter_Tourner(void);

/**
 * @brief Fait un virage à droit ou gauche au robot en fonction des obstacles
 * 
 */
void Effectuer_Tourner(void);

/**
 * @brief Fait un virage à gauche au robot
 * 
 */
void Robot_Tourner_Gauche(void);

/**
 * @brief Fait un virage à droite au robot
 * 
 */
void Robot_Tourner_Droite(void);



void setup()
{
    // Configuration des broches
    pinMode(SENSG, OUTPUT);
    pinMode(PWMG, OUTPUT);
    pinMode(SENSD, OUTPUT);
    pinMode(PWMD, OUTPUT);
    pinMode(jack, INPUT);  // Le jack est une entrée
    pinMode(Capteurs_IR1, INPUT);  // Capteur gauche
    pinMode(Capteurs_IR2, INPUT);  // Capteur centre
    pinMode(Capteurs_IR3, INPUT);  // Capteur droit
    pinMode(Capteur_Sol, INPUT);   // Détecteur de sol (lignes blanches)
    // pinMode(Capteur_Sol2, INPUT);  // Détecteur de sol supplémentaire (si utilisé)
    pinMode(Debug_LED, OUTPUT);

    Serial.begin(9600);
}


void loop()
{
  // Effectuer_Tourner();


  Serial.println(state);


    switch (state)
    {
        case S1: // Etat de defaut
        {
            if (Jack_retire() == HIGH)
            {
                state = S2;
            }

            break;
        }

        case S2: // Etat avance
        {
            if (Detecter_Ligne_Blanche() == HIGH)
            {
                state = S6;
            }
            else if (Detecter_Obstacle() == HIGH)
            {
                state = S3;
            }
            else
            {
                state = S2;
            }

            if (Detecter_Tourner()) {
                state = S4;
            }

            break;
        }

        case S3: // Etat Reculer
        {
            if (Detecter_Obstacle() == LOW)
            {
                state = S2;
            }
            else 
            {
                state = S3;
            }

            break;
        }

        case S4: // Etat tourner
        {
            if (Detecter_Tourner() == HIGH)
            {
                state = S4;
            }
            else
            {
                state = S2;
            }

            break;
        } 

        case S6: // Etat arret
        {
            if (Jack_retire() == LOW)
            {
                state = S1;
            }

            state = S6;

            break;
        }
    }

    switch (state)
    {
        case S1:
        {
            Arret_Moteur();

            break;
        }

        case S2:
        {
            Robot_Avance();

            break;
        }

        case S3:
        {
            Robot_Reculer();

            break;
        }

        case S4:
        {
            Effectuer_Tourner();
         
            break;
        }

        case S6:
        {
            Arret_Moteur();

            break;
        }
    }
}


unsigned char Detecter_Ligne_Blanche(void)
{
    // Lire l'état du détecteur de sol
    int sol = analogRead(Capteur_Sol);  // Le capteur de sol est en LOW pour une ligne blanche

    // Si le capteur détecte une ligne blanche (état LOW), renvoie 1
    if (sol > 150) 
    {
        Robot_Avance();

        return 0;  // Ligne blanche détectée
    } 
    else 
    {
        return 1;  // Pas de ligne blanche
    }
}


void Robot_Avance(void)
{
    analogWrite(PWMD, 110);  // Vitesse du moteur droit
    analogWrite(PWMG, 103);  // Vitesse du moteur gauche
    digitalWrite(SENSG, HIGH); // Moteur gauche en avant
    digitalWrite(SENSD, LOW);  // Moteur droit en avant
}


void Robot_Reculer(void)
{
    analogWrite(PWMD, 75);  // Vitesse du moteur droit
    analogWrite(PWMG, 90);  // Vitesse du moteur gauche
    digitalWrite(SENSG, LOW); // Moteur gauche en arrière
    digitalWrite(SENSD, HIGH);  // Moteur droit en arrière
    delay(200);  // Recule pendant 350 millisecondes (ajuster selon besoin)
    Arret_Moteur();  // Arrête les moteurs après le recul
}


void Arret_Moteur(void)
{
    analogWrite(PWMD, 0);  // Stop moteur droit
    analogWrite(PWMG, 0);  // Stop moteur gauche
}


unsigned char Jack_retire(void)
{
    if (digitalRead(jack) == LOW) {
        return 0; // Jack en place
    } else {
        return 1; // Jack retiré
    }
}


unsigned char Detecter_Obstacle(void)
{
    // Lire les capteurs infrarouges
    int ir1 = analogRead(Capteurs_IR1); // Capteur gauche
    int ir2 = digitalRead(Capteurs_IR2); // Capteur centre
    int ir3 = analogRead(Capteurs_IR3); // Capteur droit

    // Si un des capteurs détecte un obstacle (valeur LOW (digital) ou inferieur à 150 (analogic)), renvoie 1
    if (ir1 > 150 || ir2 == HIGH || ir3 > 150) {
        return 1;  // Obstacle détecté
    } else {
        return 0;  // Pas d'obstacle
    }
}

unsigned char Detecter_Tourner(void)
{
    int ir1 = analogRead(Capteurs_IR1); // Capteur gauche
    int ir2 = digitalRead(Capteurs_IR2); // Capteur centre
    int ir3 = analogRead(Capteurs_IR3); // Capteur droit

    // Si un des capteurs (IR1, IR2, IR3) est actif (c'est-à-dire LOW), il faut tourner
    if (ir1 > 150 || ir2 == HIGH || ir3 > 150) {
        return 1;  // Il faut tourner
    } else {
        return 0;  // Aucun virage nécessaire
    }
}


void Effectuer_Tourner(void)
{
    int ir1 = analogRead(Capteurs_IR1); // Capteur gauche
    int ir2 = digitalRead(Capteurs_IR2); // Capteur centre
    int ir3 = analogRead(Capteurs_IR3); // Capteur droit

    // Si seul le capteur du milieu et du droit détectent un obstacle, tourner à gauche
    if (ir2 == HIGH && ir3 > 150) {
        Robot_Tourner_Gauche();
        Serial.println("Gauche");
    }
    // Si seul le capteur du milieu et du gauche détectent un obstacle, tourner à droite
    else if (ir1 > 150 && ir2 == HIGH) {
        Robot_Tourner_Droite();
        Serial.println("Droite");
    }
    // Si seul le capteur du milieu détecte un obstacle, freiner
    else if (ir2 == HIGH) {
        Arret_Moteur();
        Serial.println("Arret");
    // Freiner
    }
    // Si le capteur droit détecte un obstacle, tourner à gauche
    else if (ir3 > 150) {
        Robot_Tourner_Gauche();
        Serial.println("Gauche");
    }
    // Si le capteur gauche détecte un obstacle, tourner à droite
    else if (ir1 > 150) {
        Robot_Tourner_Droite();
        Serial.println("Droite");
    }
}


void Robot_Tourner_Gauche(void)
{
    analogWrite(PWMD, 50);  // Vitesse du moteur droit
    analogWrite(PWMG, 83);  // Vitesse du moteur gauche
    digitalWrite(SENSG, LOW); // Moteur gauche en arrière
    digitalWrite(SENSD, LOW);  // Moteur droit en avant
    delay(30); // Ajuster la durée du virage si nécessaire
    Arret_Moteur();  // Arrêter les moteurs après le virage
}


void Robot_Tourner_Droite(void)
{
    analogWrite(PWMD, 83);  // Vitesse du moteur droit
    analogWrite(PWMG, 50);  // Vitesse du moteur gauche
    digitalWrite(SENSG, HIGH); // Moteur gauche en avant
    digitalWrite(SENSD, HIGH);  // Moteur droit en arrière
    delay(30); // Ajuster la durée du virage si nécessaire
    Arret_Moteur();  // Arrêter les moteurs après le virage
}