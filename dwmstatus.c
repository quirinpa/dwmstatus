#define _BSD_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <X11/Xlib.h>

#include "mktimes.h"
#include "load.h"
#include "bat.h"

static Display *dpy;

int main(void) {
	char *status;

	if (!(dpy = XOpenDisplay(NULL))) {
		fprintf(stderr, "dwmstatus: cannot open display.\n");
		return 1;
	}

	for (;;sleep(30)) {
		status = smprintf("%d %d %s", getBat(), getLoad(), mktimes("%x %X", "UTC"));
		
		XStoreName(dpy, DefaultRootWindow(dpy), status);
		XSync(dpy, False);

		free(status);
	}

	XCloseDisplay(dpy);

	return 0;
}

