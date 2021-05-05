#include "controller.h"

int main(int argc, char *argv[]){
	// system("clear");
	// testingDLList();
	// return 0;
	
	argc--;
	system("clear");
	char arg2[30], arg3[30];
	
	if (argc > 3 || argc == 0) {
		printf("Comando inválido\n");
		return 0;
	}

	if(argc == 1){
		if(!strcmp("-view", argv[1])){
			view();
		} 
		else if(!strcmp("-help", argv[1])){
			help();
		}
		else{
			printf("Comando inválido\n");
		}
	} else if(argc == 2){
		strncpy(arg2, argv[2], 30);
		if (!strcmp("-view", argv[1])){
			view_playlist (arg2);
		}
		else if(!strcmp("-update", argv[1])){
			update(arg2);
		}
		else if(!strcmp("-play", argv[1])){
			play(arg2);
		}
		else if(!strcmp("-playsong", argv[1])){
			playsong(arg2);
		}
		else if(!strcmp("-delete", argv[1])){
			delete_playlist(arg2);
		}
		else if(!strcmp("-remsong", argv[1])){
			remsong(arg2);
		}
		else if(!strcmp("-sort", argv[1])){
			define_sort(arg2);
		}
		else if(!strcmp("-create", argv[1])){
			// verificar tamanho da string
			// if (strlen(argv[1]) > 30){
			// 	printf("O nome excedeu o limite de 30 caracteres!\n");
			// 	return 0;
			// }
			create(arg2);
		}
		else if(!strcmp("-add", argv[1])){
			add(arg2);
		}
		else{
			printf("Comando inválido\n");
		}
	} 
	else if(argc == 3){
		strncpy(arg2, argv[2], 30);
		strncpy(arg3, argv[3], 30);
		if(!strcmp("-update", argv[1])){
			update_title(arg2, arg3);
		}
		else{
			printf("Comando inválido\n");
		}
	}
	
	return 0;
}
