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

Duration * readDuration(FILE * f){
	Duration * D = (Duration *) malloc(sizeof(Duration));
	fread(D, sizeof(Duration), 1, f);
	return D;
}

void writeDuration(FILE * f, Duration * D){
	fwrite(D, sizeof(Duration), 1, f);
}