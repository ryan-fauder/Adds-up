#include "collection.h"

void appendPlaylist(Collection * collection, Playlist * play){
	int i;

	if (collection->size == 0){
		collection->size = 1;
		collection->playlists = (Playlist **) malloc(sizeof(Playlist));
		collection->playlists[0] = play;
		return;
	}

	collection->size += 1;
	collection->playlists = (Playlist **) realloc(collection->playlists, collection->size * sizeof(Playlist *));
	collection->playlists[collection->size - 1] = play;
}

Playlist * findPlaylist(Collection * collection, char name[30]){
	int i;
	for (i = 0; i < collection->size; i++){
		if(!strcmp(collection->playlists[i]->name, name)){
			return collection->playlists[i];
		}
	}
	return NULL;
}

void freeCollection(Collection * collection){
	int i;
	for(i = 0; i < collection->size; i++) collection->playlists[i] = freePlaylist(collection->playlists[i]);
	free(collection);
	collection = NULL;
}

FILE * getDataFile(char * format){
	FILE * f = fopen("Data.bin", format);
	return f;
}

int getIndexPlaylist(char name[30], Collection * collection){
	int i;
	for(i = 0; i < collection->size; i++){
		if(!strcmp(collection->playlists[i]->name, name)){
			return i;
		}
	}
	return -1;
}


void printCollection(Collection * collection){
	int i;
	printf("───────────────────────────────────\n");
	printf("\t\t\tPLAYLISTS\n");
	for (i = 0; i < collection->size; i++){
		printf("• %02d:  %s\n", i+1, collection->playlists[i]->name);
	}
	printf("───────────────────────────────────\n");
}

Collection * readCollection(){
	Collection * collection = (Collection *) malloc(sizeof(Collection));
	FILE * f = getDataFile("rb+");
	int i;
	
	if (f == NULL){
		f = getDataFile("wb+");
		collection->size = 0;
		return collection;
	}

	fread(&(collection->size), sizeof(int), 1, f);
	collection->playlists = (Playlist **) malloc(sizeof(Playlist *) * collection->size);
	
	for(i = 0; i < collection->size; i++){
		collection->playlists[i] = readPlaylist(f);
	}
	
	return collection;
}

void removePlaylist(Collection * collection, int index){
	int i;

	if(index >= collection->size) return;
	for(i = index; i < collection->size - 1; i++){
		collection->playlists[i] = collection->playlists[i + 1];
	}

	collection->size -= 1;
	collection->playlists = (Playlist **) realloc(collection->playlists, collection->size * sizeof(Playlist *));
}

void writeCollection(Collection * collection){
	FILE * f = getDataFile("wb+");
	int i;
	
	if(f == NULL) return;

	fwrite(&(collection->size), sizeof(int), 1, f);

	for(i = 0; i < collection->size; i++){
		writePlaylist(f, collection->playlists[i]);
	}
}