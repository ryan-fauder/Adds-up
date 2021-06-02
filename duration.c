#include "duration.h"

Duration * createDuration(int hour, int min, int sec){
	Duration * D = (Duration *)malloc(sizeof(Duration));
	D->hour = hour;
	D->min = min;
	D->sec = sec;
	return D;
}

void freeDuration(Duration * D){
	free(D);
}

void printDuration(Duration * D){
	if (D->hour != 0) printf("%02d:", D->hour);
	printf("%02d:", D->min);
	printf("%02d", D->sec);
}

Duration * getRandomDuration(void){
	Duration * D = NULL;
	int hour, min, sec;
	
	srand((unsigned)time(NULL));
	
	hour = rand() % 10;
	if (hour <= 7) hour = 0;
	else hour = 1;
	
	min = (rand() % 8) + 1;
	sec = (rand() % 59) + 1;
	
	D = createDuration(hour, min, sec);
	return D;
}

Duration * readDuration(FILE * f){
	Duration * D = (Duration *) malloc(sizeof(Duration));
	fread(D, sizeof(Duration), 1, f);
	return D;
}

void writeDuration(FILE * f, Duration * D){
	fwrite(D, sizeof(Duration), 1, f);
}
