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
