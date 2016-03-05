#ifndef MKTIMES_H
#define MKTIMES_H
#define _BSD_SOURCE
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include "smprintf.h"

char *
mktimes(char *fmt, char *tzname)
{
	char buf[129];
	time_t tim;
	struct tm *timtm;

	memset(buf, 0, sizeof(buf));
	setenv("TZ", tzname, 1);
	tim = time(NULL);
	timtm = localtime(&tim);
	if (timtm == NULL) {
		perror("localtime");
		exit(1);
	}

	if (!strftime(buf, sizeof(buf)-1, fmt, timtm)) {
		fprintf(stderr, "strftime == 0\n");
		exit(1);
	}

	return smprintf("%s", buf);
}
#endif
