#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "collection.h"
#include "DLList.h"
#include "playlist.h"
#include "sort.h"
#include <stdio.h>


/**
 * @brief Exibe uma interface para incluir informações de uma nova música que será inserida
 *
 * @param (char *) namePlaylist: Nome da playlist
*/
void add ( char namePlaylist[30] );

/**
 * @brief Cria uma nova playlist
 *
 * @param (char *) namePlaylist: Nome da playlist
 */
void create ( char namePlaylist[30] );

/**
 * @brief Define o tipo de ordenação e ordena uma playlist
 *
 * @param (char *) namePlaylist: Nome da playlist
 */
void define_sort ( char namePlaylist[30] );


/**
 * @brief Deleta uma playlist
 *
 * @param (char *) namePlaylist: Nome da playlist
 */
void delete_playlist( char namePlaylist[30] );

/**
 * @brief Lê um índice até ele ser válido
 *
 * @param (int) start_range: índice inicial
 * @param (int) end_range: índice final
 * @param (int) escape: índice para encerrar a ação
 * @return (int) índice
 */
int getValidIndex( int start_range, int end_range, int escape );

/**
 * @brief Encontra e retorna uma playlist válida
 *
 * @param (char *) namePlaylist: Nome da playlist
 * @param (Collection *) collection: Endereço de uma estrutura do tipo Collection
 * @return (Playlist *) Endereço de uma estrutura do tipo Playlist
 */
Playlist * getValidPlaylist( char namePlaylist[30], Collection * collection );

/**
 * @brief Exibe todos comandos possíveis
 * 
 */
void help(); 

/**
 * @brief Toca uma playlist

 * @param (char *) namePlaylist: Estrutura de uma playlist
 */
void play ( char namePlaylist[30] );

/**
 * @brief Exibe uma interface com as músicas para escolher uma a ser tocada
 * 
 * @param (char *) namePlaylist: Estrutura de uma playlist
 */
void playsong ( char namePlaylist[30] );


/**
 * @brief Aparece uma interface para escolher a música a ser removida
 *
 * @param (char *) namePlaylist: Nome da playlist que contém a música
 */

void remsong ( char namePlaylist[30] );

/**
 * @brief Mostra uma lista de músicas para escolher e alterar o nome de uma delas

 * @param (char *) namePlaylist: Nome da playlist que contém a música
 */
 
void update ( char namePlaylist[30] ); 

/**
 * @brief Atualiza o nome de uma playlist
 *
 * @param (char *) namePlaylist: Nome de uma playlist
 * @param (char *) new_name: Novo nome da playlist
 */
void update_title ( char namePlaylist[30], char new_name[30] );

/**
 * @brief Exibe todas as playlists
 * 
 */
void view(void);

/**
 * @brief Exibe informações da Playlist e permite visualizar informações das musicas.
 *
 * @param (char *) namePlaylist: Nome da playlist
 */
void view_playlist ( char namePlaylist[30] );

#endif // __CONTROLLER_H__