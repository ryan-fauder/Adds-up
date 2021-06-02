#include "playlist.h"
#include "DLList.h"

Playlist * createPlaylist(char name[30], int size){
	Playlist * playlist = (Playlist *) malloc(sizeof(Playlist));
	strncpy (playlist->name, name, 28);
 	playlist->size = size;
	if(!size){
		size = 0;
	}
	playlist->album = createDLList();
	playlist->sort = 0;
	return playlist;
}

Song * findSong(char name[30], Playlist * playlist){
	int index = searchDLList(playlist->album, name);
	Song * song = NULL;
	song = getDLList(playlist->album, index);
	return song;
}

Playlist * freePlaylist(Playlist * playlist){
	playlist->size = 0;
	freeDLList(playlist->album);
	playlist->album = NULL;
	
	free(playlist);
	return NULL;
}

void insertSong(Song * s, Playlist * playlist){
	int index;
	DNode * node = createDNode(s);
	playlist->size += 1;
	index = findIndexDLList(playlist->album, node, playlist->sort);
	insertDLList(playlist->album, index, node);
}

void listenPlaylist(Playlist * playlist){
	if (playlist->size == 0){
		printf("Insira musicas para poder ouvi-las!");
		return;
	}
	int i;
	for (i = 0; i < playlist->size; i++){
		printf("Playlist \"%s\" ", playlist->name);
		if (playlist->size == 1) printf("com 1 musica disponivel\n\n");
		else printf("com %d musicas disponiveis\n\n", playlist->size);
		playSong(getDLList(playlist->album, i));
		sleep(5);
		system("clear");
	}
	printf("Obrigado por ouvir a playlist \"%s\"!\n", playlist->name);
}

void printSort(Playlist * playlist){
	switch (playlist->sort) {
		case 0:
			printf("Data de adicao");
			break;
		case 1:
			printf("Data de lancamento");
			break;
		case 2:
			printf("Alfabetica - Nome (Crescente)");
			break;
		case 3:
			printf("Alfabetica - Nome (Decrescente)");
			break;
		case 4:
			printf("Alfabetica - Artista/Banda");
			break;
		case 5:
			printf("Alfabetica - Genero");
			break;
		default:
			return;
	}
	return;
}

Playlist * readPlaylist(FILE * f){
	int i;
	Playlist * playlist = (Playlist *) malloc(sizeof(Playlist));
	
	fread(&(playlist->name), sizeof(char), 30, f);
	fread(&(playlist->size), sizeof(int), 1, f);
	fread(&(playlist->sort), sizeof(char), 1, f);

	playlist->album = readDLList(f);
	return playlist;
}

void removeSong(int index, Playlist * playlist){
	if (index >= playlist->size || index < 0) return;
	playlist->size -= 1;
	removeDLList(playlist->album, index);
}

void sortPlaylist(Playlist * playlist, char sort){
	DLinkedList * list;
	playlist->sort = sort;
	list = sortDLList(playlist->album, sort);
	if(list != NULL){
		playlist->album = list;
	}
}

void updateName(char * name, Playlist * playlist){
	strcpy(playlist->name, name);
}

void writePlaylist(FILE * f, Playlist * playlist){
	int i;
	fwrite(&(playlist->name), sizeof(char), 30, f);
	fwrite(&(playlist->size), sizeof(int), 1, f);
	fwrite(&(playlist->sort), sizeof(char), 1, f);
	writeDLList(f, playlist->album);
}