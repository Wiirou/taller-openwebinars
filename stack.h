/**
 * \file
 *
 * Módulo para gestionar un stack 
 */

#ifndef STACK_H
#define STACK_H
/**
 * Número máximo de elementos que pueden almacenarse en el stack auxiliar.
 *
 * 
 */
#define max 20

/**
 * Variable que contiene el índice del último elemento introducido en el stack
 */ 
extern int top;

/**
 * Array que se utiliza para hacer el cálculo que permite saber si un número
 * es un número de Armstrong.
 * 
 */
extern int stack[max];

/**
 * Introduce un elemento en el stack
 */ 
void push(int);


/**
 * Saca un elemento del stack
 */
int pop();
#endif /* STACK_H */
