#ifndef __DLList_H__
#define __DLList_H__

#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct Estrutura de um nó duplamente encadeado

 * @attr (struct dnode *) previous: Ponteiro para o nó anterior
 * @attr (struct dnode *) next: Ponteiro para o próximo nó 
 * @attr (Song *) song: Estrutura de uma música
*/
typedef struct dnode {
	struct dnode * previous;
	struct dnode * next;
	Song * song;
} DNode;

/**
 * @struct Estrutura de uma lista duplamente encadeada

 * @attr (int) length: Quantidade de nós (elementos) presentes na lista
 * @attr (DNode *) head: Ponteiro para o primeiro nó da lista
 * @attr (Dnode *) tail: Ponteiro para o último nó da lista
*/
typedef struct dlinkedlist {
	int length;
	DNode * head;
	DNode * tail;
} DLinkedList;

/**
 * @brief Cria uma nova lista do tipo DLinkedList
 *
 * @return (DLinkedList) Endereço de uma estrutura do tipo DLinkedList
*/
DLinkedList * createDLList();

/**
 * @brief Cria um novo nó
 *
 * @param (Song *) song: Endereço de uma estrutura do tipo Song
 * @return (DNode *) Endereço de uma estrutura do tipo DNode 
*/
DNode * createDNode(Song * song);

/**
 * @brief Libera a memória alocada por uma lista
 *
 * @param (DLinkedList) list: Endereço de uma strutura do tipo DLinkedList
*/
void freeDLList(DLinkedList * list);

/**
 * @brief Libera a memória alocada por um nó
 *
 * @param (DNode *) node: Endereço de uma estrutura do tipo DNode
*/
void freeDNode(DNode * node);

/**
 * @brief Retorna o elemento (Song) pela sua posição na lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
 * @param (int) index: índice
 * @return (Song *) Endereço de uma estrutura do tipo Song 
*/
Song * getDLList(DLinkedList * list, int index);

/**
 * @brief Retorna o nó pela sua posição na lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
 * @param (int) index: índice
 * @return (DNode *) Endereço de uma estrutura do tipo DNode 
*/
DNode * getDNodeDLList(DLinkedList * list, int index);

/**
 * @brief Inserir um elemento na lista pela sua posição
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
 * @param (int) index: índice
 * @param (DNode *) node: Endereço de uma estrutura do tipo DNode 
*/
void insertDLList(DLinkedList * list, int index, DNode * node);

/**
 * @brief Imprime os elementos de uma lista na saída padrão
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
*/
void printDLList(DLinkedList * list);

/**
 * @brief Imprime os nomes de cada música de uma lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
*/
void printNameDLList(DLinkedList * list);

/**
 * @brief Imprime os elementos de uma lista na saída padrão na ordem inversa
 *
  * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
*/
void printReverseDLList(DLinkedList * list);

/**
 * @brief Remove o primeiro nó de uma lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
*/
void popDLList(DLinkedList * list);

/**
 * @brief Insere um novo elemento no início da lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
 * @param (DNode *) node: Endereço de uma estrutura do tipo DNode
*/
void pushDLList(DLinkedList * list, DNode * node);

/**
 * @brief Lê uma a estrutura de uma lista de um arquivo
 *
 * @param (FILE *) file: Arquivo a ser lido
 * @return (DLinkedList *) Endereço de uma estrutura do tipo DLinkedList
*/
DLinkedList * readDLList(FILE * file);

/**
 * @brief Remover um elemento pela sua posição na lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
 * @param (int) index: índice
*/
void removeDLList(DLinkedList * list, int index);

/**
 * @brief Procura um elemento (música) na lista pelo nome e retorna o índice
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
 * @param (char *) name: Nome do elemento (música)
 * @return (int) Índice do elemento
*/
int searchDLList(DLinkedList * list, char * name);

/**
 * @brief Remove o último nó de uma lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
*/
void shiftDLList(DLinkedList * list);

/**
 * @brief Divite uma lista em duas outras listas
 *
 * @param (DLinkedList *) list: Endereço da estrutura DLinkedList que será dividida
 * @param (DLinkedList *) first: Endereço da primeira estrutura DLinkedList formada após a divisão
 * @param (DLinkedList *) second: Endereço da segunda estrutura DLinkedList formada após a divisão
 * @param (int) index: índice
 * @return (tipo) 
*/
void splitDLList(DLinkedList * list, DLinkedList * first, DLinkedList * second, int index);

/**
 * @brief Imprime resumos de cada música de uma lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
*/
void summarizeDLList(DLinkedList * list);

/**
 * @brief Insere um novo nó ao final de uma lista
 *
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
 * @param (DNode *) node: Endereço de uma estrutura do tipo DNode
*/
void unshiftDLList(DLinkedList * list, DNode * node);

/**
 * @brief Escreve a estrutura de uma lista em um arquivo
 *
 * @param (FILE *) file: Arquivo onde será armazenada a estrutura
 * @param (DLinkedList *) list: Endereço de uma estrutura do tipo DLinkedList
*/
void writeDLList(FILE * file, DLinkedList * list);

#endif // __DLList_H__