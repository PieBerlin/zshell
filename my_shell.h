#ifndef MY_SHELL_H
#define MY_SHELL_H 

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_INPUT 1024
#define MAX_PATH 256

// function definitions
char** parse_input(char*);
int shell_builts(char**,char**,char*);
void free_tokens(char** );
    

// Builtins function implementations
int command_cd(char**,char*);
int command_pwd();
int command_echo(char**,char**);
int command_env(char**);
int command_which(char**,char**);

char** command_setenv(char**,char**);
char** command_unsetenv(char**,char**);


// Helper functions 
int my_strcmp(const char*,const char*);
char* my_getenv(const char *name,char** env);
int my_strlen(const char* str);
int my_strncmp(const char* str1,const char *str2, size_t n);
char* my_strdup(const char*);
char* my_strcpy(char* ,const char*);
char* my_strtok(char* str,const char* delimiter);
char* my_strchr(const char*,char);


#endif
