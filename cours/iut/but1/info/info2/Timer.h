/*
 * Timer.h
 *
 * Created: 27/03/2025 15:03:01
 *  Author: Etudiant-admin
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/**
 * @brief Initialise le Timer0
 * 
 */
void InitTimer (void);

/**
 * @brief Attends 1 ms avec Timer0, fonction bloquante, car il y a un while
 * 
 */
void Attendre1ms (void);


#endif /* TIMER_H_ */