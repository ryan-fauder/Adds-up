#ifndef __DURATION_H__
#define __DURATION_H__

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Estrutura da duracao de uma musica

 * @attr hour: (int) horas
 * @attr min: (int) minutos
 * @attr sec: (int) segundos
*/
typedef struct {
	int hour, min, sec;
} Duration;

/**
 * @brief Funcao que cria uma estrutura
 * 
 * @param (int) horas 
 * @param (int) minutos
 * @param (int) segundos
 * @return Endereço para uma estrutura do tipo Duration
 */
Duration * createDuration(int hour, int min, int sec);

/**
 * @brief Funcao que libera a memoria alocada por uma
 * estrutura Duration 
 *
 * @param Endereço para uma estrutura do tipo Duration
 */
void freeDuration(Duration * D);

/**
 * @brief Funcao que imprime a duracao na saida padrao
 * 
 * @param Estrutura do tipo Duration
 */
void printDuration(Duration * D);

/**
 * @brief Le a duracao atraves de um arquivo
 * 
 * @param (FILE *) arquivo
 * @return Endereço para uma estrutura do tipo Duration
 */
Duration * readDuration(FILE * f);

/**
 * @brief Escreve a duracao em um arquivo
 * 
 * @param (FILE  *) arquivo
 * @param Endereço para uma estrutura do tipo Duration
 */
void writeDuration(FILE * f, Duration * D);

#endif // __DURATION_H__