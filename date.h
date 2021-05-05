#ifndef __DATE_H__
#define __DATE_H__

#include <time.h>
#include <stdlib.h>

typedef struct tm moment;

/**
 * @brief Funcao que cria uma estrura moment e retorna o seu endereco
 * 
 * @param (int) dia
 * @param (int) mes
 * @param (int) ano
 * @return (moment *) o endereco da estrutura
 */

moment * createMoment(int day, int month, int year);

/**
 * @brief Funcao para imprimir um data
 * 
 * @param (moment *) a estruta a ser impressa
 */
void printDate(moment * m);

/**
 * @brief Funcao para leitura de um data em um arquivo
 * 
 * @param (FILE *) o arquivo a ser lido
 * @return a estrutura de data lida
 */
moment * readDate(FILE * f);

/**
 * @brief Funcao para escrita de um data em um arquivo
 * 
 * @param (FILE *) o arquivo a ser escrito
 * @param (moment *) a estruta a ser armazenada
 */
void writeDate(FILE * f, moment * m);

#endif