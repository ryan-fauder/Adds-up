# Comandos

gcc main.c date.c -o main -lm && ./main

gcc test.c duration.c -o test && ./test

gcc main.c playlist.c song.c date.c duration.c -lm -o main && ./main

gcc *.c -lm -o main

gcc *.c -lm -o main && ./main

# Testes Unitários
- 
- 
// Testes


	struct tm * moment;
	time_t now;
	time(&now);
	moment = localtime(&now);

	FILE * file = fopen("Data.bin", "wb+");
	Song * S = NULL;
	Playlist * play = NULL;
	Duration * D = createDuration(0, 10, 2);
	
	play = createPlaylist("OnlyTopSongs", 0);
	S = newSong("NiceSong", "StreetArtist", D, "StreetRap", moment, 2.75);
	insertSong(S, play);
	S = newSong("AweSong", "AweArtist", D, "AweStyle", moment, 1.12);
	insertSong(S, play);
	S = newSong("StupendousSong", "StupidArtist", D, "StStyle", moment, 1.12);
	insertSong(S, play);
	removeSong("StupendousSong", play);
	
	writePlaylist(file, play);
	rewind(file);
	play = readPlaylist(file);

	system("clear");

	// RELATÓRIO DEBUG:
	printf("\t\t\tRELATÓRIO DEBUG:\n");
	// printf("Nome da Playlist: %s\n", play->name);
	// printf("Qtd de músicas: %d\n", play->size);
	// printf("Tipo de ordenação: %d\n", play->sort);
	// printf("-- Segue abaixo as músicas: --\n");
	
	// int i;
	// for(i = 0; i < play->size; i++){
	// 	printf("\n--");
	// 	printSong(play->list[i]);
	// 	printf("--\n");
	// }
	
	Song * Song2 = NULL;
	Song2 = newSong("Debong", "ArtistDebug", D, "Genrebug", moment, 1.90);
	// Song2 = findSong("NiceSong", play);

	// insertSong(S, play);
	freeSong(Song2);
	if(Song2 == NULL) printf("VAZIO");
	printSong(Song2);

	//freePlaylist(play);
	printf("\n-- DEBUG END --\n");
	return 0;



	/**
	./main -create Samba
	./main -add Samba
	Digite
	Artista1
	Samba
	1:1:1
	1.1.1
	1.1
	
	*/