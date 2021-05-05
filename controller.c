#include "controller.h"

void add(char * namePlaylist){
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);
	Song * song;
	char nameSong[30], artistname[30], genre[30];
	moment * date_release;
	double size;
	int hour, min, sec, day, month, year;
	time_t now;
	if (playlist == NULL){
		printf("Playlist não encontrada!\n");
		freeCollection(collection);
		return;
	}

	time(&now);
	date_release = localtime(&now);
	printf("INSERINDO MÚSICA:\n");
	printf("Digite o nome da musica:\n");
	scanf("%[^\n]s", nameSong);
	scanf("%*c");

	while (findSong(nameSong, playlist) != NULL){
			printf("Nome já existente! Por favor escolha outro nome:\n");
			scanf("%[^\n]s", nameSong);
			scanf("%*c");
	}

	// printf("Digite o nome o artista:\n");
	// scanf("%[^\n]s", artistname);
	// scanf("%*c");
	// printf("Digite o nome do genero musical:\n");
	// scanf("%[^\n]s", genre);
	// scanf("%*c");
	// printf("Digite a duracao da musica no formato (hora:minuto:segundo) ");
	// scanf("%d%*c%d%*c%d", &hour, &min, &sec);
	// printf("Digite a data de lancamento no formato (dia.mes.ano) ");
	// scanf("%d%*c%d%*c%d", &day, &month, &year);
	day = 1;
	month = 4;
	year = 2000;
	// printf("Digite o tamanho do arquivo: (MB) ");
	// scanf("%lf", &size);

	
	strcpy(artistname, "Nome");
	size = 1.50;
	strcpy(genre, "TipoMusical");
	hour = min = 0;
	sec = 30;

	date_release->tm_mday = day;
	date_release->tm_mon = month - 1;
	date_release->tm_year = year - 1900;
	mktime(date_release);

	song = newSong(nameSong, artistname, createDuration(hour, min, sec), genre, date_release, size);
	insertSong(song, playlist);

	writeCollection(collection);

	freeCollection(collection);
	printf("Musica criada com sucesso!\n");
}

void create (char namePlaylist[30]){
	Collection * collection = readCollection();
	Playlist * playlist = NULL;
	
	if ( findPlaylist(collection, namePlaylist) != NULL ){
		printf("Nome já existente! Por favor escolha outro nome.\n");
		freeCollection(collection);
		return;
	}

	playlist = createPlaylist(namePlaylist, 0);
	appendPlaylist(collection, playlist);
	writeCollection(collection);

	printf("Playlist criada com sucesso!\n");

	freeCollection(collection);
	return;
}

void define_sort(char * namePlaylist){
	printf("EM MANUTENCAO\n");
	return;
}

void delete_playlist(char * namePlaylist){
	int i;
	int index;
	Collection * collection = readCollection();
	index = getIndexPlaylist(namePlaylist, collection);
	
	if (index == -1){
		printf("Playlist não encontrada!\n");
		freeCollection(collection);
		return;
	}
	removePlaylist(collection, index);
	writeCollection(collection);

	printf("Playlist \"%s\" removida com sucesso!\n", namePlaylist);

	freeCollection(collection);
}

void help(){
	printf("---------------------------------------------\n");
	printf("-help: Exibe todos comandos possíveis.\n");
	printf("-play (playlist): Toca uma playlist.\n");
	printf("-playsong (playlist): Exibe uma interface com todas as músicas para a escolha da música a ser tocada.\n");
	printf("-view: Exibe todas as playlists.\n");
	printf("-view (playlist): Exibe informações da playlist e permite visualizar informações das músicas.\n");
	printf("-create (nome): Cria uma playlist\n");
	printf("-add (playlist): Aparece uma interface para adicionar as informações da música.\n");
	printf("-sort (playlist): Ordena uma playlist.\n");
	printf("-update (playlist): Mostra uma lista de músicas para alterar os nomes.\n");
	printf("-update (playlist) (novo nome): Atualiza o nome da playlist\n");
	printf("-delete (playlist): Deleta a playlist.\n");
	printf("-remsong (playlist): Aparece uma interface para escolher a música a ser removida.\n");
	printf("---------------------------------------------\n");
}

void play (char * namePlaylist){
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);
	
	if (playlist == NULL){
		printf("Playlist nao encontrada\n");
		freeCollection(collection);
		return;
	} else if (playlist->size == 0){
		printf("Não há músicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}

	listenPlaylist(playlist);
	freeCollection(collection);
}

void playsong ( char * namePlaylist ){
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);
	int index, i;

	if(playlist == NULL){
		printf("Playlist nao encontrada\n");
		freeCollection(collection);
		return;
	} else if (playlist->size == 0){
		printf("Não há músicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}

	while(1){
		printf("Digite o indice para escolher a musica a ser tocada:\n");
		for(i = 0; i < playlist->size; i++){
			printf("%d - %s\t\t", i + 1, playlist->album[i]->name);
			printf("%s\t", playlist->album[i]->artistname);
			printDuration(playlist->album[i]->duration);
			printf("\n");
		}
		printf("Digite 0 para sair\n");
		scanf("%d", &index);
		if(index >= 0 && index <= playlist->size) break;
		else {
			printf("\n\n\n\n\n");
			printf("Valor inválido, digite novamente!");
		}
	}
	if(index == 0){
		printf("Ate uma proxima vez...\n");
		freeCollection(collection);
		return;
	}
	
	index--;
	playSong(playlist->album[index]);
	freeCollection(collection);
}

void remsong (char * namePlaylist){
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);
	int index, i;
	
	if (playlist == NULL){
		printf("Playlist não encontrada!\n");
		freeCollection(collection);
		return;
	} else if (playlist->size == 0){
		printf("Não há músicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}

	while(1){
		printf("Digite o indice para escolher a musica a ser removida:\n");
		for(i = 0; i < playlist->size; i++){
			printf("%d - %s\t\t", i + 1, playlist->album[i]->name);
			printf("%s\t", playlist->album[i]->artistname);
			printDuration(playlist->album[i]->duration);
			printf("\n");
		}
		printf("Digite 0 para sair\n");
		scanf("%d", &index);
		if(index >= 0 && index <= playlist->size) break;
		else {
			printf("\n\n\n\n\n");
			printf("Valor inválido, digite novamente!");
		}
	}
	if(index == 0){
		printf("Ate uma proxima vez...\n");
		freeCollection(collection);
		return;
	}

	index--;
	removeSong(index, playlist);
	writeCollection(collection);

	printf("Música removida com sucesso\n");

	freeCollection(collection);
}

void update (char * namePlaylist){
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);
	int index, i, boolean;
	char nameSong[30];

	if (playlist == NULL){
		printf("Playlist nao encontrada\n");
		freeCollection(collection);
		return;
	} else if (playlist->size == 0){
		printf("Não há músicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}
	
	while(1){
		printf("Digite o indice para escolher a musica a ser alterada:\n");
		for(i = 0; i < playlist->size; i++){
			printf("%d - %s\t\t", i + 1, playlist->album[i]->name);
			printf("%s\t", playlist->album[i]->artistname);
			printDuration(playlist->album[i]->duration);
			printf("\n");
		}
		printf("\nDigite 0 para sair\n");
		scanf("%d", &index);
		if(index >= 0 && index <= playlist->size) break;
		else {
			printf("\n\n\n\n\n");
			printf("Valor inválido, digite novamente!");
		}
	}
	if(index == 0){
		printf("Ate uma proxima vez...\n");
		freeCollection(collection);
		return;
	}

	index--;
	scanf("%*c");
	while(1){
		printf("Digite o novo nome para a musica %s:\n", playlist->album[index]->name);
		scanf("%[^\n]s", nameSong);
		scanf("%*c");
		while (findSong(nameSong, playlist) != NULL){
			printf("Nome já existente! Por favor escolha outro nome:\n");
			scanf("%[^\n]s", nameSong);
			scanf("%*c");
		}
		printf("O novo nome pode ser %s?\n", nameSong);
		printf("Digite o numero para confirmar:\n 1 - SIM\n 2 - NAO\n");
		scanf("%d", &boolean);
		if(boolean == 1) break;
		printf("\n\n\n\n\n");
	}
	updateTitle(nameSong, playlist->album[index]);
	writeCollection(collection);

	freeCollection(collection);
}

void update_title ( char * namePlaylist, char new_name[30]){
	Collection * collection = readCollection();
	Playlist * playlist = NULL;

	playlist = findPlaylist(collection, namePlaylist);

	if (playlist == NULL){
		printf("Playlist não encontrada\n");
		freeCollection(collection);
		return;
	} else if ( findPlaylist(collection, new_name) != NULL ){
		printf("Nome já existente! Por favor escolha outro nome.\n");
		freeCollection(collection);
		return;
	}
	strcpy(playlist->name, new_name);

	writeCollection(collection);
	printf("Nome alterado com sucesso!\n");

	freeCollection(collection);
}

void view( void ){
	int i;
	Collection * collection = readCollection();

	printf("────────────────────────────────\n");
	printf("\t\t\tPLAYLISTS\n");
	for (i = 0; i < collection->size; i++){
		printf("• %02d:  %s\n", i+1, collection->playlists[i]->name);
	}
	printf("────────────────────────────────\n");

	freeCollection(collection);
}

void view_playlist ( char * namePlaylist ){
	int i, index;
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);

	if (playlist == NULL){
		printf("Playlist inexistente\n");
		freeCollection(collection);
		return;
	}
	
	printf("────────────────────────────────\n");
	printf("Nome da playlist: %s\n", playlist->name);
	if (playlist->size == 0) printf("Não possui nenhuma música\n");
	else printf("Quantidade de músicas: %d\n", playlist->size);
	printf("Ordenação: ");
	printSort(playlist);
	printf("\n────────────────────────────────\n");

	if (playlist->size == 0) {
		freeCollection(collection);
		return;
	}

	while (1){
		printf("Visualizar informações de uma música:\n");
		for (i = 0; i < playlist->size; i++){
			printf("%d: %s\n", i+1, playlist->album[i]->name);
		}
		printf("Digite o índice: (0 para sair) ");
		while (1){
			scanf("%d", &index);
			if ((index >= 0) && (index <= playlist->size)) break;
			printf("Índice inválido! Digite outra vez: ");
		}
		if (index == 0) {
			system("clear");
			break;
		}
		system("clear");
		printSong(playlist->album[index-1]);
		printf("\n");
	}
	
	
	// freeCollection(collection);
	// printSong(playlist->album[0]);
	// printf("%s\n", playlist->name);
	// printf("%d\n", playlist->size);
	// printf("------ Debug end ------\n");
}

void testingDLList(){
	int hour = 0, min = 0, sec = 30;
	Song * S = NULL;	
	DLinkedList * list = createDLList();
	// Duration * D = createDuration(0, 0, 30);
	moment * date_release = createMoment(5, 5, 2021);

	// time_t now;
	// moment * date_release;

	// time(&now);
	// date_release = localtime(&now);
	
	// date_release->tm_mday = day;
	// date_release->tm_mon = month - 1;
	// date_release->tm_year = year - 1900;
	// mktime(date_release);

	S = newSong("Song_A", "ArtONE", createDuration(0, 0, 30), "Gen1", date_release, 10);
	insertDLList(list, 0, createDNode(S));

	S = newSong("Song_D", "ArtFOUR", createDuration(0, 0, 30), "Gen4", date_release, 40);
	insertDLList(list, 0, createDNode(S));

	S = newSong("Song_C", "ArtTHREE", createDuration(0, 0, 30), "Gen3", date_release, 30);
	insertDLList(list, 0, createDNode(S));

	S = newSong("Song_E", "ArtFIVE", createDuration(0, 0, 30), "Gen5", date_release, 50);
	insertDLList(list, 0, createDNode(S));

	S = newSong("Song_B", "ArtTWO", createDuration(0, 0, 30), "Gen2", date_release, 20);
	insertDLList(list, 0, createDNode(S));

	list = mergeSort(list);

	printf("\n-- TESTE --\n");
	printDLList(list);
  
	freeDLList(list);
	printf("\n-- Debug End --\n");
	return;
}
