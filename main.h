#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_INPUT_LENGTH 1024
#define MAX_PATH_LENGTH 1024
#define READ_SIZE 1024

extern char **environ;

/* Function prototypes */
char **tokenizer(char *input);
void execute_env_command(void);
void execute_command_from_path(char **args, char *path);
void execute_child_process(char **args);
void execute_regular_command(char **args);
void execute_command(char *command);
void interactive(void);
void non_interactive(void);
int command_exists(char *command);

/* Custom built-ins */
int custom_exit(char **args);
int custom_env(char **args);
int custom_cd(char **args);

/* String library function */
unsigned int _strlen(const char *str);
char *_strcpy(char *dest, const char *source);
int _strcmp(const char *s1, const char *s2);

#endif /* MAIN_H */
