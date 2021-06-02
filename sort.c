#include "sort.h"

char artistCmp(Song * song1, Song * song2){
	return strdiff(song1->artistname, song2->artistname);
}

char dateAddedCmp(Song * song1, Song * song2){
	return !momentcmp(song1->date_added, song2->date_added);
}

char dateReleaseCmp(Song * song1, Song * song2){
	return momentcmp(song1->date_release, song2->date_release);
}

char decreasenameCmp(Song * song1, Song * song2){
	return !strdiff(song1->name, song2->name);
}

int findIndexDLList(DLinkedList * list, DNode * node, char type){
	cmpFunction * cmp = getTypeSortDLList(type);
	if(cmp != NULL){
		return linearSearchDLList(list, node, cmp);
	}
	return -1;
}

char genreCmp(Song * song1, Song * song2){
	return strdiff(song1->genre, song2->genre);
}

cmpFunction * getTypeSortDLList(char type){
	switch (type){
		case 0: // Data de adicao
			return dateAddedCmp;
		case 1: // Data de lancamento
			return dateReleaseCmp;
		case 2: // Alfabetica - Nome (Crescente)
			return nameCmp;
		case 3: // Alfabetica - Nome (Decrescente)
			return decreasenameCmp;
		case 4: // Alfabetica - Artista/Banda
			return artistCmp;
		case 5: // Alfabetica - Genero
			return genreCmp;
		default:
			return NULL;
	}
}

int linearSearchDLList(DLinkedList * list, DNode * node, cmpFunction * cmp){
	DNode * current = list->head;
	int index = 0;
	while(current != NULL && cmp(current->song, node->song) == 1){
		current = current->next;
		index++;
	}
	return index;
}

DLinkedList * mergeSort(DLinkedList * list, cmpFunction * cmp){
	if (list->length == 1) return list;
	DLinkedList *list1, *list2;
	int half = list->length / 2;
	
	list1 = createDLList();
	list2 = createDLList();

	splitDLList(list, list1, list2, half);
	return mergeDLList(mergeSort(list1, cmp), mergeSort(list2, cmp), cmp);
}

DLinkedList * mergeDLList(DLinkedList * first, DLinkedList * second, cmpFunction * cmp){
	DNode * currentFirst = first->head;
	DNode * currentSecond = second->head;
	DLinkedList * mergedList = createDLList();

	while (currentFirst != NULL || currentSecond != NULL){
		if (currentFirst == NULL ) {
			unshiftDLList(mergedList, currentSecond);
			currentSecond = currentSecond->next;
			continue;
		}
		if (currentSecond == NULL ) {
			unshiftDLList(mergedList, currentFirst);
			currentFirst = currentFirst->next;
			continue;
		}
		if (cmp(currentFirst->song, currentSecond->song) == 1) {
			unshiftDLList(mergedList, currentFirst);
			currentFirst = currentFirst->next;
		} else {
			unshiftDLList(mergedList, currentSecond);
			currentSecond = currentSecond->next;
		}
	}
	return mergedList;
}

char nameCmp(Song * song1, Song * song2){
	return strdiff(song1->name, song2->name);
}

DLinkedList * sortDLList(DLinkedList * list, char type){
	cmpFunction * cmp = getTypeSortDLList(type);
	if(cmp != NULL){
		return mergeSort(list, cmp);
	}
	return NULL;
}

char strdiff(char * name1, char * name2){
	if(strcmp(name1, name2) > 0){
		return 0;
	}
	return 1;
}