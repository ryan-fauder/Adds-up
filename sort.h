#ifndef __SORT_H_
#define __SORT_H_

#include "DLList.h"

typedef char (cmpFunction) (Song *, Song *);

char artistCmp(Song * song1, Song * song2);

char dateReleaseCmp(Song * song1, Song * song2);

char decreasenameCmp(Song * song1, Song * song2);

int findIndexDLList(DLinkedList * list, DNode * node, char type);

char genreCmp(Song * song1, Song * song2);

cmpFunction * getTypeSortDLList(char type);

int linearSearchDLList(DLinkedList * list, DNode * node, cmpFunction * cmp);

DLinkedList * mergeDLList(DLinkedList * first, DLinkedList * second, char (*cmpFunction) (Song *, Song *));

DLinkedList * mergeSort(DLinkedList * list, char (*cmpFunction) (Song *, Song *));

char nameCmp(Song * song1, Song * song2);

DLinkedList * sortDLList(DLinkedList * list, char type);

char strdiff(char * name1, char * name2);

#endif // __SORT_H_