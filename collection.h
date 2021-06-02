#ifndef __COLLECTION_H__
#define __COLLECTION_H__

#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include <dirent.h>

/**
 * @struct Estrutura que armazena as playlists - coleção

 * @attr (Playlist **) playlists: Endereço para as estruturas do tipo Playlist
 * @attr (int) size: Quantidade de playlists
*/
typedef struct {
	Playlist ** playlists;
	int size;
} Collection;

/**
 * @brief Acrescenta uma nova playlist na collection
 *
 * @param list: Estrutura da Collection
 * @param name: Estrutura da Playlist
 * @return
*/
void appendPlaylist( Collection * collection, Playlist * play );

/**
 * @brief Captura a estrutura de uma playlist
 *
 * @param (Collection *) Estrutura da Collection
 * @param (char *) nome
 * @return Endereço de uma estrutura do tipo Playlist
*/
Playlist * findPlaylist( Collection * collection, char name[30] );

/**
 * @brief Libera a memoria da Collection
 *
 * @param (Collection *) Estrutura da Collection
*/
void freeCollection( Collection * collection );

/**
 * @brief Acessa o arquivo de Data
 *	
 * @param format: Formato do acesso ao arquivo
 * @return (FILE *) ponteiro de arquivo
*/

FILE * getDataFile( char * format );

/**
 * @brief Encontra o indice de uma playlist
 *
 * @param (char *) Nome da Playlist
 * @param (Collection *) Estrutura da Collection
 * @return Valor do indice
*/
int getIndexPlaylist( char name[30], Collection * collection );

/**
 * @brief Imprime o nome das playlists presentes no arquivo
 *
 * @param (Collection *) Endereço de uma estrutura Collection
*/
void printCollection( Collection * collection );

/**
 * @brief Faz a leitura de coleção em um arquivo
 *
 * @return (Collection *) Endereço de uma estrutura Collection
*/
Collection * readCollection(void);

/**
 * @brief Apaga uma playlist dentro de uma collection
 *
 * @param list: Collection de playlist
 * @param name: Nome da playlist a ser apagada
 * @return
*/
void removePlaylist( Collection * list, int index );

/**
 * @brief Escreve a coleção em um arquivo
 *
 * @param (Collection *) Endereço de uma estrutura Collection
*/
void writeCollection( Collection * list );

#endif // __COLLECTION_H__