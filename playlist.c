#include "playlist.h"
#include "song.h"
#include <unistd.h>

Playlist * createPlaylist(char name[30], int size){
	Playlist * playlist = (Playlist *) malloc(sizeof(Playlist));
	strcpy (playlist->name, name);
 	playlist->size = size;
	if(!size){
		size = 0;
	}
	playlist->album = (Song **) malloc(sizeof(Song *));
	playlist->sort = 0;
	return playlist;
}

Song * findSong(char name[30], Playlist * playlist){
	int i;
	for(i = 0; i < playlist->size; i++){
		if(!strcmp(playlist->album[i]->name, name)){
			return playlist->album[i];
		}
	}
	return NULL;
}

void freePlaylist(Playlist * playlist){
	int i;
	for(i = 0; i < (playlist->size); i++) {
		freeSong(playlist->album[i]);
		playlist->album[i] = NULL;
	}
	playlist->size = 0;
	free(playlist->album);
	playlist->album = NULL;
	free(playlist);
	playlist = NULL;
}

int getIndexSong(char name[30], Playlist * playlist){
	int i;
	for(i = 0; i < playlist->size; i++){
		if(!strcmp(playlist->album[i]->name, name)){
			return i;
		}
	}
	return -1;
}

void insertSong(Song * s, Playlist * playlist){
	playlist->size += 1;
	playlist->album = (Song **) realloc(playlist->album, playlist->size * sizeof(Song *));
	playlist->album[(playlist->size) - 1] = s;
}

void listenPlaylist(Playlist * playlist){
	int i;
	for(i = 0; i < playlist->size; i++){
		printf("PLAYLIST %s ", playlist->name);
		printf("com %d música(s) disponíveis\n\n", playlist->size);
		playSong(playlist->album[i]);
		sleep(5);
		system("clear");
	}
	printf("Obrigado por ouvir o Adds Up!\n\n");
	printf("Por apenas R$ 9,90 por mês você terá acesso\n");
	printf("ilimitado e sem propagandas! Clique no botão\n");
	printf("para saber mais\n\n[PREMIUM]\n");
}

void printSort(Playlist * playlist){
	switch (playlist->sort) {
		case 0:
			printf("Data de adição");
			break;
		case 1:
			printf("Data de lançamento");
			break;
		case 2:
			printf("Alfabética - Nome");
			break;
		case 3:
			printf("Alfabética - Nome");
			break;
		case 4:
			printf("Alfabética - Artista/Banda");
			break;
		case 5:
			printf("Alfabética - Gênero");
			break;
		default:
			return;
	}
	return;
}

Playlist * readPlaylist(FILE * f){
	int i;
	Playlist * playlist = (Playlist *) malloc(sizeof(Playlist));
	playlist->album = ( Song ** ) malloc(sizeof(Song *) * playlist->size);
	
	fread(&(playlist->name), sizeof(char), 30, f);
	fread(&(playlist->size), sizeof(int), 1, f);
	fread(&(playlist->sort), sizeof(char), 1, f);
	for(i = 0; i < playlist->size; i++){
		playlist->album[i] = readSong(f);
	}
	return playlist;
}

void removeSong(int index, Playlist * playlist){
	int i;
	for (i = index; i < playlist->size - 1; i++){
		playlist->album[i] = playlist->album[i + 1];
	}
	playlist->size -= 1;
	playlist->album = (Song **) realloc(playlist->album, playlist->size * sizeof(Song));
}

void sort(Playlist * playlist, char sort);

void updateName(char * name, Playlist * playlist){
	strcpy(playlist->name, name);
}

void writePlaylist(FILE * f, Playlist * playlist){
	int i;
	fwrite(&(playlist->name), sizeof(char), 30, f);
	fwrite(&(playlist->size), sizeof(int), 1, f);
	fwrite(&(playlist->sort), sizeof(char), 1, f);
	for(i = 0; i < playlist->size; i++){
		writeSong(f, playlist->album[i]);
	}
}
