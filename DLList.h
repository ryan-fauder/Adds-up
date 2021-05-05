#ifndef __DLList_H__
#define __DLList_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

typedef struct dnode {
	struct dnode * previous;
	struct dnode * next;
	Song * song;
} DNode;

typedef struct {
	int length;
	DNode * head;
	DNode * tail;
} DLinkedList;

// Cria uma nova lista
DLinkedList * createDLList();

// Cria um nó
DNode * createDNode(Song * song);

// Procura a posicao para um novo elemento ser inserido e retorna o index.
int findIndexDLList(DLinkedList * list, DNode * node, char sort);

// Libera uma lista encadeada
void freeDLList(DLinkedList * list);

// Libera a memória alocada de um nó
void freeDNode(DNode * node);

// Retorna o valor armazenado pela posição
Song * getDLList(DLinkedList * list, int index);

// Retorna o nó pelo índice
DNode * getDNodeDLList(DLinkedList * list, int index);

// Inserir um elemento pela posição armazenada na lista
void insertDLList(DLinkedList * list, int index, DNode * node);

// Une duas listas
DLinkedList * mergeDLList(DLinkedList * first, DLinkedList * second);

// Realiza o Merge Sort em uma lista
DLinkedList * mergeSort(DLinkedList * list);

// Imprime os elementos de uma lista
void printDLList(DLinkedList * list);

// Imprime os elementos de uma lista na ordem inversa
void printReverseDLList(DLinkedList * list);

// Remove o primeiro nó de uma lista
void popDLList(DLinkedList * list);

// Insere um novo elemento no início da lista
void pushDLList(DLinkedList * list, DNode * node);

//Lê uma lista de um arquivo
DLinkedList * readDLList(FILE * file);

// Remover um elemento pela posição
void removeDLList(DLinkedList * list, int index);

// Procura o elemento e retorna o index
int searchDLList(DLinkedList * list, DNode * node);

// Remove o último nó de uma lista
void shiftDLList(DLinkedList * list);

// Ordena uma lista encadeada
void sortDLList(DLinkedList * list, int type);

// Divite uma lista em duas
void splitDLList(DLinkedList * list, DLinkedList * first, DLinkedList * second, int index);

// Insere um valor em uma lista
void unshiftDLList(DLinkedList * list, DNode * node);

// Armazena uma lista em um arquivo
void writeDLList(FILE * file, DLinkedList * list);

#endif // __DLList_H__