#include <stdio.h>
#include <stdlib.h>
#include "date.h"

moment * createMoment(int day, int month, int year){
	time_t now;
	moment * date;

	time(&now);
	date = localtime(&now);
	
	if (day == -1 && month == -1 && year == -1){
		return date;
	}

	date->tm_mday = day;
	date->tm_mon = month - 1;
	date->tm_year = year - 1900;
	mktime(date);

	return date;
}

moment * getRandomMoment(){
	moment * date;
	int day, month, year;

	srand((unsigned)time(NULL));
	
	day = rand() % 30 + 1;
	month = rand() % 12 + 1;
	year = rand() % 21 + 2000;
	date = createMoment(day, month, year);
	return date;
}

char momentcmp(moment * moment1, moment * moment2){
	if(difftime(mktime(moment1), mktime(moment2)) > 0){
		return 1;
	}
	return 0;
}

void printDate(moment * m){
	char months[12][5] = {
		"jan", "fev", "mar", "abr", "maio", "jun",
		"jul", "ago", "set", "out", "nov", "dez"
	};
	printf("%d de ", m->tm_mday);
	printf("%s", months[m->tm_mon]);
	printf(" de %d", (m->tm_year + 1900));
}

moment * readDate(FILE * f){
	moment * m = (moment *) malloc(sizeof(moment));
	fread(m, sizeof(moment), 1, f);
	return m;
}

void writeDate(FILE * f, moment * m){
	fwrite(m, sizeof(moment), 1, f);
}