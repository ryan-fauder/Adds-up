#ifndef __SORT_H_
#define __SORT_H_

#include "DLList.h"

/**
 * @brief Definir um tipo de funcao de comparacao
*/
typedef char (cmpFunction) (Song *, Song *);

/**
 * @brief Funcao para comparacao do atributo do nome do artista entre musicas
 * 
 * @param (Song * song1) song: Endereço da estrutura da música
 * @param (Song * song2) song: Endereço da estrutura da música
 * @return Retorna 1 para representar que song1 > song2. caso contrario, retorna 0
*/
char artistCmp(Song * song1, Song * song2);

/**
 * @brief Funcao para comparacao do atributo do data de lancamento entre musicas
 * 
 * @param (Song * song1) song: Endereço da estrutura da música
 * @param (Song * song2) song: Endereço da estrutura da música
 * @return Retorna 1 para representar que song1 > song2. caso contrario, retorna 0
*/
char dateReleaseCmp(Song * song1, Song * song2);

/**
 * @brief Funcao para retorna o inverso da funcao nameCmp
 * 
 * @param (Song * song1) song: Endereço da estrutura da música
 * @param (Song * song2) song: Endereço da estrutura da música
 * @return Retorna 1 para representar que song1 < song2. caso contrario, retorna 0
*/
char decreasenameCmp(Song * song1, Song * song2);

/**
 * @brief Funcao para procurar um no em uma lista duplamente encadeada atraves de uma funcao de comparacao
 * 
 * @param (char) type: Caractere que representa o tipo de ordenacao
 * @return Retorna a funcao responsavel de gerenciar esse tipo de ordenacao
*/
int findIndexDLList(DLinkedList * list, DNode * node, char type);

/**
 * @brief Estrutura para comparacao do atributo de genero musical entre musicas
 * 
 * @param (Song * song1) song: Endereço da estrutura da música
 * @param (Song * song2) song: Endereço da estrutura da música
 * @return Retorna 1 para representar que song1 > song2. caso contrario, retorna 0
*/
char genreCmp(Song * song1, Song * song2);

/**
 * @brief Funcao para procurar um no em uma lista duplamente encadeada atraves de uma funcao de comparacao
 * 
 * @param (char) type: Caractere que representa o tipo de ordenacao
 * @return Retorna a funcao responsavel de gerenciar esse tipo de ordenacao
*/
cmpFunction * getTypeSortDLList(char type);

/**
 * @brief Funcao para procurar um no em uma lista duplamente encadeada atraves de uma funcao de comparacao
 * 
 * @param (DLinkedList *) list: Endereço da estrutura da lista
 * @param (DNode *) dnode: Endereço da estrutura do no
 * @param (char (*cmpFunction) (Song *, Song *)): Endereço da funcao de comparacao
 * @return Retorna o indice do no dentro da lista encadeada
*/
int linearSearchDLList(DLinkedList * list, DNode * node, cmpFunction * cmp);

/**
 * @brief Funcao para mesclar duas listas duplamente encadeadas
 * 
 * @param (DLinkedList *) first: Endereço da estrutura da lista
 * @param (DLinkedList *) second: Endereço da estrutura da lista
 * @param (char (*cmpFunction) (Song *, Song *)): Endereço da funcao de comparacao
 * @return Retorna lista duplamente encadeada que contem as listas passadas como parametro
*/
DLinkedList * mergeDLList(DLinkedList * first, DLinkedList * second, char (*cmpFunction) (Song *, Song *));

/**
 * @brief Funcao para ordenacao de uma lista duplamente encadeada
 * 
 * @param (DLinkedList * list): Endereço da estrutura da lista
 * @param (char (*cmpFunction) (Song *, Song *)): Endereço da funcao de comparacao
 * @return Retorna lista duplamente encadeada ordenada conforme a funcao passada
*/
DLinkedList * mergeSort(DLinkedList * list, char (*cmpFunction) (Song *, Song *));

/**
 * @brief Funcao para comparacao do atributo nome entre musicas
 * 
 * @param (Song * song1) song: Endereço da estrutura da música
 * @param (Song * song2) song: Endereço da estrutura da música
 * @return Retorna 1 para representar que song1 > song2. caso contrario, retorna 0
*/
char nameCmp(Song * song1, Song * song2);

/**
 * @brief Funcao para comparacao do atributo nome entre musicas
 * 
 * @param (DLinkedList *) list: Endereco da estrutura de uma playlist
 * @param (char) type: Caractere que representa o tipo de ordenacao
 * @return REtorna a lista duplamente encadeada ordenada conforme o caractere informado
*/
DLinkedList * sortDLList(DLinkedList * list, char type);

/**
 * @brief Funcao para verificar se o primeiro nome e maior que o segundo nome
 * 
 * @param (char *) name1: String
 * @param (char *) name2: String
 * @return Retorna a lista duplamente encadeada ordenada conforme o caractere informado
*/
char strdiff(char * name1, char * name2);

#endif // __SORT_H_