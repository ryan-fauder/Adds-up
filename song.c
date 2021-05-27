#include "song.h"

void endSong(Song * song){
	if (song == NULL) return;

	int i, len;
	len = strlen(song->name) + strlen(song->artistname);

	if (song->duration->hour == 0){
		printf("%s", song->name);
		for (i = 0; i < (35 - len); i++) printf(" ");
		printf("%s\n", song->artistname);
		printf("──────────────────────────────────⚪\n");
		printf("◄◄⠀▐▐ ⠀►►⠀⠀ ⠀ ");
		printDuration(song->duration);
		printf(" / ");
	} else {
		printf("%s", song->name);
		for (i = 0; i < (42 - len); i++) printf(" ");
		printf("%s\n", song->artistname);
		printf("────────────────────────────────────────⚪\n");
		printf("◄◄⠀▐▐ ⠀►►⠀⠀ ⠀ ");
		printDuration(song->duration);
		printf(" / ");
	}

	printDuration(song->duration);
	printf("  ───○ 🔊\n");
}

Song * freeSong(Song * song){
	freeDuration(song->duration);
	song->duration = NULL;
	free(song->date_release);
	song->date_release = NULL;
	free(song->date_added);
	song->date_added = NULL;
	
	free(song);
	return NULL;
}

double getRandomSize(){
	double size;
	int integer, floating;

	srand((unsigned)time(NULL));
	integer = rand() % 5 + 1;
	floating = rand() % 99 + 1;
	size = integer + (floating / (double) 100);

	return size;
}

Song * newSong(char name[30], char artistname[30], Duration * duration, char genre[30], moment * date_release, double size){
	Song * song = (Song *) malloc(sizeof(Song));

	song->duration = (Duration * ) malloc(sizeof(Duration));
	song->date_release = (moment * ) malloc(sizeof(moment));
	song->date_added = (moment * ) malloc(sizeof(moment));

	strncpy(song->name, name, 28);
	strncpy(song->artistname, artistname, 28);
	strncpy(song->genre, genre, 28);
	
	song->duration = duration;

	*song->date_release = *date_release;

	*(song->date_added) = *createMoment(-1, -1, -1);

	song->size = size;
	return song;
}

void playSong(Song * song){
	if (song == NULL) return;

	int i, len;
	len = strlen(song->name) + strlen(song->artistname);

	if (song->duration->hour == 0){
		printf("%s", song->name);
		for (i = 0; i < (35 - len); i++) printf(" ");
		printf("%s\n", song->artistname);
		printf("⚪──────────────────────────────────\n");
		printf("◄◄⠀▐▐ ⠀►►⠀⠀ ⠀ 0:00 / ");
	} else {
		printf("%s", song->name);
		for (i = 0; i < (42 - len); i++) printf(" ");
		printf("%s\n", song->artistname);
		printf("⚪─────────────────────────────────────────\n");
		printf("◄◄⠀▐▐ ⠀►►⠀⠀ ⠀ 00:00:00 / ");
	}

	printDuration(song->duration);
	printf("  ───○ 🔊\n");
}

void printSong(Song * song){
	if (song == NULL) return;
	
	int i, len;
	len = strlen(song->name) + strlen(song->artistname);

	printf("%s", song->name);
	for (i = 0; i < (25 - len); i++) printf(" ");
	printf("%s\n", song->artistname);
	printf("Genero: %10s\t| ", song->genre);
	printf("Duracao: ");
	printDuration(song->duration);
	printf("\nData de adicao: ");
	printDate(song->date_added);
	printf("\nData de lancamento: ");
	printDate(song->date_release);
	printf("\nTamanho: %.2lf MB\n", song->size);
}

Song * readSong(FILE * f){
	Song * song = (Song *) malloc(sizeof(Song));
	
	fread(&(song->name), sizeof(char), 30, f);
	fread(&(song->artistname), sizeof(char), 30, f);

	song->duration = readDuration(f);

	fread(&(song->genre), sizeof(char), 30, f);

	song->date_release = readDate(f);
	song->date_added = readDate(f);

	fread(&(song->size), sizeof(double), 1, f);
	return song;
}

void summarizeSong(Song * song){
	printf("%s\t\t", song->name);
	printf("%s\t", song->artistname);
	printDuration(song->duration);
	printf("\n");
}

void updateNameSong(char name[30], Song * song){
	strcpy(song->name, name);
}

void writeSong(FILE * f, Song * song){
	fwrite(&(song->name), sizeof(char), 30, f);
	fwrite(&(song->artistname), sizeof(char), 30, f);

	writeDuration(f, song->duration);

	fwrite(&(song->genre), sizeof(char), 30, f);

	writeDate(f, song->date_release);
	writeDate(f, song->date_added);

	fwrite(&(song->size), sizeof(double), 1, f);
}