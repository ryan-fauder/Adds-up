#include "controller.h"

void add ( char namePlaylist[30] ){
	Collection * collection = readCollection();
	Playlist * playlist = NULL;
	Song * song;
	char nameSong[30], artistname[30], genre[30];
	double size;
	int hour, min, sec, day, month, year;
	
	printf("-- Inserindo uma musica --\n");
	playlist = getValidPlaylist(namePlaylist, collection);
	if (playlist == NULL){
		freeCollection(collection);
		return;
	}

	printf("Digite o nome da musica:\n");
	scanf("%[^\n]s", nameSong);
	scanf("%*c");

	while (findSong(nameSong, playlist) != NULL){
		printf("Nome ja existente! Por favor escolha outro nome:\n");
		scanf("%[^\n]s", nameSong);
		scanf("%*c");
	}
	
	printf("Digite o nome do artista ou da banda:\n");
	scanf("%[^\n]s", artistname);
	scanf("%*c");
	printf("Digite o nome do genero musical:\n");
	scanf("%[^\n]s", genre);
	scanf("%*c");

	song = newSong(nameSong, artistname, getRandomDuration(), genre, getRandomMoment(), getRandomSize());

	insertSong(song, playlist);

	printf("Musica criada com sucesso!\n");

	writeCollection(collection);
	freeCollection(collection);
}

void create ( char namePlaylist[30] ){
	Collection * collection = readCollection();
	Playlist * playlist = NULL;
	
	if (findPlaylist(collection, namePlaylist) != NULL){
		printf("Nome ja existente! Por favor escolha outro nome.\n");
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

void define_sort( char namePlaylist[30] ){
	int sort;
	Collection * collection = readCollection();
	Playlist * playlist;
	
	printf("-- Ordenar uma playlist --\n");
	playlist = getValidPlaylist(namePlaylist, collection);
	if (playlist == NULL){
		freeCollection(collection);
		return;
	}
	
	system("clear");
	printf("───────────────────────────────────────\n");
	printf("Playlist \"%s\" - Ordenacao das musicas", playlist->name);
	printf("\n───────────────────────────────────────\n");
	printf("Escolha o indice do tipo de ordenacao:\n\n");
	printf("1 - Data de adicao\n");
	printf("2 - Data de lancamento\n");
	printf("Alfabetica:\n");
	printf("\t3 - Nome (Crescente)\n");
	printf("\t4 - Nome (Decrescente)\n");
	printf("\t5 - Artista/Banda\n");
	printf("\t6 - Genero\n");
	printf("Digite 0 para sair...\n");
	
	sort = getValidIndex(1, 6, 0) - 1;
	if (sort == -1){
		freeCollection(collection);
		return;
	}

	sortPlaylist(playlist, sort);
	writeCollection(collection);
	
	printf("\nPlaylist ordenada com sucesso!\n");
	freeCollection(collection);
	return;
}

void delete_playlist( char namePlaylist[30] ){
	int index;
	Collection * collection = readCollection();
	if (namePlaylist == NULL){
		printf("-- Remover uma playlist --\n");
		printCollection(collection);
		printf("Escolha o indice da playlist: ");
		index = getValidIndex(1, collection->size, 0) - 1;
	} else {
		index = getIndexPlaylist(namePlaylist, collection);
	}
	
	if (index == -1){
		printf("Playlist nao encontrada!\n");
		freeCollection(collection);
		return;
	}

	removePlaylist(collection, index);
	writeCollection(collection);
	printf("\nPlaylist removida com sucesso!\n");

	freeCollection(collection);
}

int getValidIndex( int start_range, int end_range, int escape ){
	int index;
	while (1){
		scanf("%d%*c", &index);
		if (index == escape) return escape;
		if (index >= start_range && index <= end_range) break;
		printf("Indice invalido! Digite novamente: ");
	}
	return index;
}

Playlist * getValidPlaylist( char namePlaylist[30], Collection * collection ){
	Playlist * playlist = NULL;

	if (collection->size == 0) {
		printf("Nenhuma playlist foi criada\n");
		return NULL;
	}

	if (namePlaylist == NULL){
		int index;
		printCollection(collection);

		printf("\nEscolha o indice da playlist:\n");
		printf("Digite 0 para sair...\n");
		
		index = getValidIndex(1, collection->size, 0) - 1;

		if (index == -1){
			return NULL;
		}

		playlist = collection->playlists[index];
	}
	else {
		playlist = findPlaylist(collection, namePlaylist);

		if (playlist == NULL){
			printf("Playlist nao encontrada!\n");
			return NULL;
		}
	}

	return playlist;
}

void help(){
	printf("%23s\n", "HELP");
	printf("────────────────────────────────────────────────────\n\n");
	printf("() = parametros obrigatorios\n");
	printf("[] = parametros opcionais\n\n");
	printf("-help: Exibe todos comandos possiveis\n\n");
	printf("-play [playlist]: Toca uma playlist\n\n");
	printf("-playsong [playlist]: Exibe uma interface com todas as musicas para a escolha da musica a ser tocada\n\n");
	printf("-view: Exibe todas as playlists\n\n");
	printf("-view (playlist): Exibe informacoes da playlist e permite visualizar informacoes das musicas\n\n");
	printf("-create (nome): Cria uma nova playlist\n\n");
	printf("-add [playlist]: Exibe uma interface para adicionar as informacoes da musica\n\n");
	printf("-sort [playlist]: Ordena a playlist\n\n");
	printf("-update (playlist): Exibe uma lista de musicas para alterar o nome de uma delas\n\n");
	printf("-update (playlist) (novo nome): Atualiza o nome da playlist\n\n");
	printf("-delete [playlist]: Deleta a playlist\n\n");
	printf("-remsong [playlist]: Exibe uma interface para escolher a musica a ser removida\n\n");
	printf("────────────────────────────────────────────────────\n\n");
}

void play ( char namePlaylist[30] ){	
	Collection * collection = readCollection();
	Playlist * playlist = NULL;

	printf("-- Tocar uma playlist --\n");

	playlist = getValidPlaylist(namePlaylist, collection);

	if (playlist == NULL){
		freeCollection(collection);
		return;
	}
	
	if (playlist->size == 0){
		printf("Nao ha musicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}

	system("clear");
	listenPlaylist(playlist);
	freeCollection(collection);
}

void playsong ( char namePlaylist[30] ){
	Collection * collection = readCollection();
	Playlist * playlist = NULL;
	Song * song = NULL;

	int index;

	printf("-- Tocar uma musica --\n");
	playlist = getValidPlaylist(namePlaylist, collection);
	
	if (playlist == NULL){
		freeCollection(collection);
		return;
	}
	else if (playlist->size == 0){
		printf("Nao ha musicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}

	printf("Digite o indice para escolher a musica a ser tocada:\n\n");
	summarizeDLList(playlist->album);
	printf("\nDigite 0 para sair\n");
	index = getValidIndex(1, playlist->size, 0) - 1;

	if (index == -1){
		printf("Ate uma proxima vez...\n");
		freeCollection(collection);
		return;
	}
	
	song = getDLList(playlist->album, index);

	system("clear");
	printf("♫ Tocando agora ♫\n\n");
	playSong(song);
	sleep(5);

	system("clear");
	printf("Obrigado por ouvir \"%s\"!\n\n", song->name);
	endSong(song);

	freeCollection(collection);
}

void remsong ( char namePlaylist[30] ){
	Collection * collection = readCollection();
	Playlist * playlist = NULL;
	int index, i;

	printf("-- Remover uma musica --\n");
	playlist = getValidPlaylist(namePlaylist, collection);
	
	if (playlist == NULL){
		freeCollection(collection);
		return;
	}

	if (playlist->size == 0){
		printf("Nao ha musicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}

	printf("\nDigite o indice da musica:\n");
	summarizeDLList(playlist->album);
	printf("\nDigite 0 para sair\n");
	index = getValidIndex(1, playlist->size, 0) - 1;

	if(index == -1){
		freeCollection(collection);
		return;
	}

	removeSong(index, playlist);
	writeCollection(collection);

	printf("\nMusica removida com sucesso!\n");

	freeCollection(collection);
}

void update ( char namePlaylist[30] ){
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);
	Song * song = NULL;
	
	int index, i, boolean;
	char nameSong[30];

	if (playlist == NULL){
		printf("Playlist nao encontrada\n");
		freeCollection(collection);
		return;
	} else if (playlist->size == 0){
		printf("Nao ha musicas nessa playlist!\n");
		freeCollection(collection);
		return;
	}

	printf("-- Alterar o nome --\n");
	printf("Lista de musicas da playlist \"%s\":\n\n", playlist->name);
	summarizeDLList(playlist->album);
	printf("\nEscolha o indice da musica: (0 para sair) ");
	index = getValidIndex(1, playlist->size, 0) - 1;

	if(index == -1){
		freeCollection(collection);
		return;
	}

	song = getDLList(playlist->album, index);
	
	printf("Digite o novo nome para a musica \"%s\":\n", song->name);
	scanf("%[^\n]s", nameSong);
	scanf("%*c");
	while (findSong(nameSong, playlist) != NULL){
		printf("Nome ja existente! Por favor escolha outro nome:\n");
		scanf("%[^\n]s", nameSong);
		scanf("%*c");
	}

	printf("\nO novo nome pode ser \"%s\"?\n", nameSong);
	printf("1 - SIM\n2 - NAO\nDigite o numero para confirmar: ");

	boolean = getValidIndex(1, 2, 2);

	if (boolean == 2) {
		printf("\nAlteracao cancelada\n");
		freeCollection(collection);
		return;
	}

	system("clear");
	updateNameSong(nameSong, song);
	writeCollection(collection);

	printf("Nome alterado com sucesso!\n");

	freeCollection(collection);
}

void update_title( char namePlaylist[30], char new_name[30] ){
	Collection * collection = readCollection();
	Playlist * playlist = NULL;

	playlist = findPlaylist(collection, namePlaylist);

	if (playlist == NULL){
		printf("Playlist nao encontrada\n");
		freeCollection(collection);
		return;
	} 
	else if ( findPlaylist(collection, new_name) != NULL ){
		printf("Nome ja existente! Por favor escolha outro nome.\n");
		freeCollection(collection);
		return;
	}

	strncpy(playlist->name, new_name, 28);

	writeCollection(collection);
	printf("Nome alterado com sucesso!\n");

	freeCollection(collection);
}

void view( void ){
	Collection * collection = readCollection();
	printCollection(collection);
	if (!collection->size)
		printf("Nenhuma playlist foi criada\n");
	freeCollection(collection);
}

void view_playlist ( char namePlaylist[30] ){
	int i, index;
	Collection * collection = readCollection();
	Playlist * playlist = findPlaylist(collection, namePlaylist);

	if (playlist == NULL){
		printf("Playlist inexistente\n");
		freeCollection(collection);
		return;
	}
	
	printf("───────────────────────────────────\n");
	printf("Nome da playlist: %s\n", playlist->name);
	if (playlist->size == 0){
		printf("Nao possui musicas\n");
		printf("───────────────────────────────────\n");
		freeCollection(collection);
		return;
	}
	else {
		printf("Quantidade de musicas: %d\n", playlist->size);
		printf("Ordenacao: ");
		printSort(playlist);
		printf("\n");
	}
	printf("───────────────────────────────────\n");

	while (1){
		printf("Visualizar informacoes de uma musica:\n");
		printNameDLList(playlist->album);
		printf("Digite o indice: (0 para sair) ");
		index = getValidIndex(1, playlist->size, 0) - 1;
		
		system("clear");
		if (index == -1) break;
		printSong(getDLList(playlist->album, index));
		printf("\n");
	}
	
	freeCollection(collection);
}