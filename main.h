#ifndef MAIN_H
#define MAIN_H

/*headerfiles*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*prototypes*/
void execmd(char **argv);
char *get_location(char *command);
void get_env(void);

#endif
