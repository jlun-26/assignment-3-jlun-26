#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID, LOG_USER);
    if (argc != 3) {
	syslog(LOG_ERR, "Invalid number of arguments: %d", argc - 1);
	closelog();
	return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
	syslog(LOG_ERR, "Error opening file %s: %s", writefile, strerror(errno));
	closelog();
	return 1;
    }

    if (fputs(writestr, fp) == EOF) {
	syslog(LOG_ERR, "Error writing to file %s", writefile);
	fclose(fp);
	closelog();
	return 1;
    }

    fclose(fp);
    closelog();
    return 0;
}
