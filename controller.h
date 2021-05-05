#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <stdio.h>
#include "playlist.h"
#include "collection.h"
#include "DLList.h"

void add (char * namePlaylist);

/**
 * @brief Cria uma playlist
 * @param name: criar uma playlist com essa nome
 * @return
 */
/**
 * @brief Aparece uma interface para adicionar as informações da música
 * @param namePlaylist: Nome de uma playlist
 * @return
*/

void create (char namePlaylist[30]);

/**
 * @brief Ordena uma playlist
 * @param playlist: Nome de uma playlist
 * @return
 */

void define_sort (char * namePlaylist);

/**
 * @brief Aparece uma interface para escolher a música a ser removida
 *
 * @param playlist: Nome de uma playlist
 * @return
 */

void delete_playlist(char * namePlaylist);

/**
 * @brief Exibe todos comandos possíveis
 * 
 * @return
 */
 
void help(); 

/**
 * @brief Toca uma playlist
 * @param namePlaylist: Estrutura de uma playlist
 * @return
 */
void play (char * namePlaylist);

/**
 * @brief Exibe uma interface com todas as musicas para a escolha da musica a ser tocada.
 * 
 * @param namePlaylist: Estrutura de uma playlist
 * @return
 */
void playsong ( char * namePlaylist );

/**
 * @brief Deleta a playlist
 *
 * @param playlist: Nome de uma playlist
 * @return
 */

void remsong (char * namePlaylist);

/**
 * @brief Mostra uma lista de músicas para alterar os nomes dessas.
 * @param playlist: Nome de uma playlist
 * @return
 */
 
void update (char * namePlaylist); 

/**
 * @brief Atualiza o nome da playlist
 *
 * @param playlist: Nome de uma playlist
 * @param new_name: Novo nome da playlist
 * @return
 */
void update_title ( char * namePlaylist, char new_name[30]);

/**
 * @brief Exibe todas as playlists
 * 
 * @return
 */
void view( void );

/**
 * @brief Exibe informações da Playlist e permite visualizar informações das musicas.
 *
 * @param namePlaylist: Estrutura de uma playlist
 * @return
 */
void view_playlist ( char * namePlaylist );

void testingDLList();

#endif // __CONTROLLER_H__