#ifndef __SONG_H__
#define __SONG_H__

#include "date.h"
#include "duration.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @struct Estrutura de uma música

 * @attr (char *) name: Nome da música
 * @attr (char *) artistname: Nome do artista ou da banda
 * @attr (Duration *) duration: Duração da música
 * @attr (char *) genre: Gênero musical
 * @attr (moment *) date_release: Data de lançamento da música
 * @attr (moment *) date_added: Data de adição
 * @attr (double) size: Tamanho da música (MB)
*/
typedef struct {
	char name[30];
	char artistname[30];
	Duration * duration;
	char genre[30];
	moment * date_release;
	moment * date_added;
	double size;
} Song;

/**
 * @brief Impressão a ser exibida após uma música ser tocada

 * @param (Song *) song: Endereço da estrutura da música
*/
void endSong(Song * song);

/**
 * @brief Libera a memória de uma estrutura de música
 * 
 * @param (Song *) song: Endereço da estrutura da música
 * @return (Song *) Endereço da estrutura da música
*/
Song * freeSong(Song * song);

double getRandomSize();

/**
 * @brief Retorna uma estrutura de Song

 * @param (char *) name: Nome da música
 * @param (char *) artistname: Nome do artista ou da banda
 * @param (Duration *) duration: Duração da música
 * @param (char *) genre: Gênero musical
 * @param (moment *) date_release: Data de lancamento da música
 * @param (double) size: Tamanho da música (MB)

 * @return (Song *) Endereço da estrutura da música
*/
Song * newSong(char name[30], char artistname[30], Duration * duration, char genre[30], moment * date_release, double size);

/**
 * @brief Toca uma música

 * @param (Song *) song: Endereço da estrutura da música
*/
void playSong(Song * song);

/**
	* @brief Imprime as informações da música
	*
	* @param (Song *) song: Endereço da estrutura da música
*/
void printSong(Song * song);

/**
 * @brief Lê a estrutura de uma música de um arquivo
 *
 * @param (FILE *) f: Arquivo a ser lido
 * @return (Song *) Endereço da estrutura da música
*/
Song * readSong(FILE * f);

/**
 * @brief Imprime o resumo das informações de uma música
 *
 * @param (Song *) song: Endereço da estrutura da música
*/
void summarizeSong(Song * song);

/**
 * @brief Altera o nome de uma música
 *
 * @param (char *) name: Nome da música
 * @param (Song *) song: Endereço da estrutura da música
 * @return
*/
void updateNameSong(char name[30], Song * song);

/**
 * @brief Escreve uma estrutura de música em um arquivo

 * @param (FILE *) f: Arquivo onde será armazenada a estrutura
 * @param (Song *) song: Endereço da estrutura da música
*/
void writeSong(FILE * f, Song * song);

#endif // __SONG_H__