#ifndef __DURATION_H__
#define __DURATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @struct Estrutura da duração de uma música

 * @attr (int) hour: Horas
 * @attr (int) min: Minutos
 * @attr (int) sec: Segundos
*/
typedef struct {
	int hour, min, sec;
} Duration;

/**
 * @brief Cria uma estrutura do tipo Duration
 * 
 * @param (int) hour: Horas
 * @param (int) min: Minutos
 * @param (int) sec: Segundos
 * @return (Duration *) Endereço de uma estrutura do tipo Duration
 */
Duration * createDuration(int hour, int min, int sec);

/**
 * @brief Libera a memória alocada por uma estrutura do tipo Duration 
 *
 * @param (Duration *) D: Endereço de uma estrutura do tipo Duration
 */
void freeDuration(Duration * D);

/**
 * @brief Imprime a duração uma música na saída padrão
 * 
 * @param (Duration *) D: Endereço de uma estrutura do tipo Duration
 */
void printDuration(Duration * D);

/**
 * @brief Cria uma estrutura do tipo Duration com valores aleatórios
 * 
 * @reeturn (Duration *) duration: Endereço de uma estrutura do tipo Duration
 */
Duration * getRandomDuration(void);

/**
 * @brief Lê uma estrutura do tipo Duration em um arquivo binário
 * 
 * @param (FILE *) f: arquivo a ser lido
 * @return (Duration *) Endereço de uma estrutura do tipo Duration
 */
Duration * readDuration(FILE * f);

/**
 * @brief Escreve uma estrutura do tipo Duration em um arquivo binário
 * 
 * @param (FILE *) f: arquivo
 * @param (Duration *) D: Endereço de uma estrutura do tipo Duration
 */
void writeDuration(FILE * f, Duration * D);

#endif // __DURATION_H__