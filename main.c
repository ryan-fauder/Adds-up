#include "controller.h"

int main(int argc, char *argv[]){
	argc--;
	system("clear");
	char arg2[30], arg3[30];
	
	if (argc > 3 || argc == 0) {
		printf("Comando inválido\n");
		return 0;
	}

	if (argc == 1){
		if(!strcmp("-view", argv[1])){
			view();
		} 
		else if(!strcmp("-help", argv[1])){
			help();
		}
		else if(!strcmp("-add", argv[1])){
			add(NULL);
		}
		else if(!strcmp("-remsong", argv[1])){
			remsong(NULL);
		}
		else if(!strcmp("-playsong", argv[1])){
			playsong(NULL);
		}
		else if(!strcmp("-delete", argv[1])){
			delete_playlist(NULL);
		}
		else if(!strcmp("-play", argv[1])){
			play(NULL);
		}
		else if(!strcmp("-sort", argv[1])){
			define_sort(NULL);
		}
		else{
			printf("Comando inválido\n");
		}
	} else if (argc == 2){
		strncpy(arg2, argv[2], 28);

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
			create(arg2);
		}
		else if(!strcmp("-add", argv[1])){
			add(arg2);
		}
		else{
			printf("Comando inválido\n");
		}
	} 
	else if (argc == 3){
		strncpy(arg2, argv[2], 28);
		strncpy(arg3, argv[3], 28);

		if(!strcmp("-update", argv[1])){
			update_title(arg2, arg3);
		}
		else{
			printf("Comando inválido\n");
		}
	}
	
	return 0;
}