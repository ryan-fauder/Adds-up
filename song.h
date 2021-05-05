#ifndef __SONG_H__
#define __SONG_H__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "date.h"
#include "duration.h"

/**
 * @struct Estrutura de uma musica

 * @attr name: Nome da musica
 * @attr artistname: Nome do artista ou banda
 * @attr duration: Duracao da musica
 * @attr genre: genero musical da musica
 * @attr date_release: data de lancamento da musica
 * @attr date_added: data de adicao
 * @attr size: Tamanho da musica (MB)
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
 * @brief Libera a memoria de uma estrutura de musica
 * 
 * @param song: Estrutura a ser liberada
 * @return
*/
void freeSong(Song * song);

/**
 * @brief Retorna uma estrutura de Song

 * @param name: Nome da musica
 * @param artistname: Nome do artista ou banda
 * @param duration: Duracao da musica
 * @param genre: genero musical da musica
 * @param date_release: data de lancamento da muisca
 * @param size: Tamanho da musica (MB)

 * @return Estrutura Song criadaparam 
*/
Song * newSong(char name[30], char artistname[30], Duration * duration, char genre[30], moment * date_release, double size);

/**
 * @brief Realiza a execucao de uma musica
 * @param song: Estrutura a ser tocada
 * @return
*/
void playSong(Song * song);

/**
	* @brief Imprime as informações da música
	*
	* @param song: Estrutura a ser impressa
*/
void printSong(Song * song);

/**
 * @brief Leitura de um song em um arquivo binario
 *
 * @param f: Arquivo a ser lido
 * @return Retorna uma estrutura de Song
*/
Song * readSong(FILE * f);

/**
 * @brief Altera o nome da musica
 *
 * @param name: Nome da musica
 * @param song: estrutura Song a ter o nome alterado
 * @return
*/
void updateTitle(char name[30], Song * song);

/**
 * @brief Escrita de uma estrutura de Song em um arquivo de forma binaria
 * @param (FILE *) Arquivo
 * @param (Song *) Estrutura do tipo Song
*/
void writeSong(FILE * f, Song * song);

#endif // __SONG_H__