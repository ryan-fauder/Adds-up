#include "DLList.h"

DLinkedList * createDLList(){
	DLinkedList * list = (DLinkedList *) malloc(sizeof(DLinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

DNode * createDNode(Song * song){
	DNode * node = (DNode *) malloc(sizeof(DNode));
	node->song = song;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

void freeDLList(DLinkedList * list){
	DNode * currentHead, * left;
	currentHead = list->head;

	while (currentHead != NULL){
		left = currentHead;
		currentHead = currentHead->next;
		freeDNode(left);
		left = NULL;
	}

	free(list);
}

void freeDNode(DNode * node){
	freeSong(node->song);
	free(node);
}

Song * getDLList(DLinkedList * list, int index){
	DNode * current = getDNodeDLList(list, index);

	if (current == NULL) return NULL;
	return current->song;
}

DNode * getDNodeDLList(DLinkedList * list, int index){
	if (index >= list->length || index < 0) return NULL;

	int half = list->length / 2;
	DNode * current;

	if (index <= half){
		current = list->head;
		int i = 0;
		while(i < index){
			current = current->next;
			i++;
		}
	}
	else{
		current = list->tail;
		int i = list->length - 1;
		while(i > index){
			current = current->previous;
			i--;
		}
	}
	return current;
}

void insertDLList(DLinkedList * list, int index, DNode * node){
	if (index < 0 || index > list->length) return;

	DNode * left = NULL;
	DNode * right = NULL;

	if (index == list->length){
		unshiftDLList(list, node);
		return;
	} 
	else if (index == 0){
		pushDLList(list, node);
		return;
	}

	list->length += 1;
	right = getDNodeDLList(list, index);
	left = right->previous;

	if (left == NULL || right == NULL) return;

	node->previous = left;
	left->next = node;
	node->next = right;
	right->previous = node;
}

void popDLList(DLinkedList * list){
	if(list->length == 0) return;

	DNode * right = list->head->next;
	
	if (list->length != 1) {
		right->previous = NULL;
	} else {
		list->tail = NULL;
	}

	freeDNode(list->head);
	
	list->head = right;

	list->length--;
}

void printDLList(DLinkedList * list){
	DNode * current = list->head;

	while(current != NULL){
		printSong(current->song);
		current = current->next;
	}
	printf("\n");
}

void printNameDLList(DLinkedList * list){
	DNode * current = list->head;
	int index = 1;

	while(current != NULL){
		printf("%d - ", index);
		printf("%s\n", current->song->name);
		current = current->next;
		index++;
	}
	printf("\n");
}

void printReverseDLList(DLinkedList * list){
	DNode * current = list->tail;

	while(current != NULL){
		printSong(current->song);
		current = current->previous;
	}
	printf("\n");
}

void pushDLList(DLinkedList * list, DNode * node){
	list->length++;

	if (list->length == 1){
		list->head = node;
		list->tail = list->head;
		return;
	}

	DNode * current = list->head;
	node->next = current;
	current->previous = node;
	list->head = node;
}

DLinkedList * readDLList(FILE * file){
	int size;
	Song * current_song;
	DLinkedList * list = createDLList();

	fread(&size, 1, sizeof(int), file);

	while (size-- > 0){
		current_song = readSong(file);
		unshiftDLList(list, createDNode(current_song));
	}

	return list;
}


void removeDLList(DLinkedList * list, int index){
	if (list->length == 0 || index >= list->length) return;

	if (index == 0){
		popDLList(list);
		return;
	}
	if (index == list->length - 1){
		shiftDLList(list);
		return;
	}

	DNode * current = getDNodeDLList(list, index);

	if (current == NULL) return;

	DNode * left, * right;

	left = current->previous;
	right = current->next;

	left->next = right;
	right->previous = left;

	freeDNode(current);
	list->length--;
	return;
}

int searchDLList(DLinkedList * list, char * name){
	int index = 0;
	DNode * current = list->head;

	while(current != NULL){
		if(!strcmp(name, current->song->name)){
			return index;
		}
		index++;
		current = current->next;
	}
	return -1;
}

void shiftDLList(DLinkedList * list){
	if (list->length == 0) return;

	DNode * left = list->tail->previous;

	if(list->length != 1){
		left->next = NULL;
	} else{
		list->head = NULL;
	}

	freeDNode(list->tail);
	list->tail = left;
	list->length--;
}

void summarizeDLList(DLinkedList * list){
	DNode * current = list->head;
	int index = 1;

	while(current != NULL){
		printf("%2d - ", index);
		summarizeSong(current->song);
		
		current = current->next;
		index++;
	}
}

void splitDLList(DLinkedList * list, DLinkedList * first, DLinkedList * second, int size){
	if (size < 0 || size > list->length) return;

	if (size == 0){
		second->head = list->head;
		second->tail = list->tail;
		second->length = list->length;
		return;
	}
	if (size == list->length){
		first->head = list->head;
		first->tail = list->tail;
		first->length = list->length;
		return;
	}

	int index = size - 1;
	DNode * firstTail = getDNodeDLList(list, index);
	DNode * secondHead = firstTail->next;
	
	if (firstTail != NULL)
		firstTail->next = NULL;
	if (secondHead != NULL)
		secondHead->previous = NULL;

	first->tail = firstTail;
	first->length = size;
	first->head = list->head;

	second->tail = list->tail;
	second->head = secondHead;
	second->length = list->length - size;
}

void unshiftDLList(DLinkedList * list, DNode * node){
	list->length += 1;
	DNode * left;

	if (list->length == 1){
		list->head = node;
		list->tail = list->head;
		return;
	}
	
	left = list->tail;

	left->next = node;
	node->previous = left;
	list->tail = node;
}

void writeDLList(FILE * file, DLinkedList * list){
	DNode * current = list->head;
	
	fwrite(&(list->length), 1, sizeof(int), file);

	while(current != NULL){
		writeSong(file, current->song);
		current = current->next;
	}

}