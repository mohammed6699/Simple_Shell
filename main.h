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

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*prototypes*/
void execmd(char **argv);
char *get_location(char *command);
int get_env(void);
char *get_path(char *token, char *command);
char **get_tokens(char *lineptr, int *number_tokens);
char **allocate_memory_for_tokens(char *line_copy, int *number_tokens, const char *limit);
#endif
