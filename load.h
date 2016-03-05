#ifndef LOAD_H
#define LOAD_H

#define _BSD_SOURCE
#include <stdlib.h>
#include <stdio.h>

char getLoad(void){
	double avgs[1];

	if (getloadavg(avgs, 1) < 0) {
		perror("getloadavg");
		exit(1);
	}

	return (char)100*avgs[0];
}

#endif
