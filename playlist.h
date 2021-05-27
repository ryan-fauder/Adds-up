#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "DLList.h"
#include <unistd.h>

typedef struct {
	char name[30];
	int size;
	char sort;
	DLinkedList * album;
} Playlist;

/**
 * @brief Cria uma playlist
 * 
 * @param name: Nome da playlist
 * @return O endereco de memoria de uma estrutura de playlist
 */
Playlist * createPlaylist(char name[30], int size);

/**
 * @brief Procura alguma música
 * 
 * @param name: Nome da musica
 * @param playlist: Estrutura de uma playlist
 * @return Ponteiro de uma musica
 */
Song * findSong(char name[30], Playlist * playlist);

/**
 * @brief Libera a memoria de uma estrutura de playlist
 * 
 * @param playlist: estrutura da playlist
 * @return
 */
Playlist * freePlaylist(Playlist * playlist);

// /**
//  * @brief Procura o indice de alguma musica
//  * 
//  * @param name: Nome da musica
//  * @param playlist: Estrutura de uma playlist
//  * @return indice da musica
//  */
// int getIndexSong(char name[30], Playlist * playlist);

/**
 * @brief Insere uma musica em uma playlist
 * 
 * @param song: Estrutura de uma musica
 * @param play: estrutura da playlist
 * @return
 */
void insertSong(Song * s, Playlist * play);

/**
 * @brief Toca as musicas de um playlist
 * 
 * @param (Playlist *) estrutura da playlist
 */
void listenPlaylist(Playlist * play);

/**
 * @brief Imprime o tipo de ordenação de uma playlist
 * 
 * @param (Playlist *) estrutura da playlist
 */
void printSort(Playlist * play);

/**
 * @brief Le a estrutura da playlist de um arquivo
 * 
 * @param (FILE *) arquivo
 * @return O endereco de memoria de uma estrutura de playlist
 */
Playlist * readPlaylist(FILE * f);

/**
 * @brief Remove uma musica de uma playlist
 * 
 * @param index: Posicao da musica na playlist
 * @param (Playlist *) estrutura da playlist
 */
void removeSong(int index, Playlist * playlist);

/**
 * @brief Ordena a playlist de acordo com o tipo
 * 
 * @param play: estrutura da playlist
 * @param sort: Tipo de ordenacao
 * @return
 */

void sortPlaylist(Playlist * playlist, char sort);

/**
 * @brief Altera o nome de uma playlist ja existente
 * 
 * @param (char *) novo nome da playlist
 * @param (Playlist *) estrutura da playlist
 */
void updateName(char * name, Playlist * playlist);

/**
 * @brief Escreve a estrutura da playlist em um arquivo
 * 
 * @param (FILE *) arquivo
 * @param (Playlist *) estrutura da playlist
 */
void writePlaylist(FILE * f, Playlist * playlist);

#endif // __PLAYLIST_H__