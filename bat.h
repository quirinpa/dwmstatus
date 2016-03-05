#ifndef BAT_H
#define BAT_H
#include <stdio.h>
#include <stdlib.h>
#define bat0 "/sys/class/power_supply/BAT0/"
char getBat(void) {
	FILE *cf = fopen(bat0 "charge_full", "r"),
			 *cn = fopen(bat0 "charge_now", "r");

	unsigned int icn, icf;
	fscanf(cf, "%u", &icf);
	fscanf(cn, "%u", &icn);

	fclose(cf);
	fclose(cn);

	return (char)100*icn/icf;
}
#endif
