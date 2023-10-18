#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>



extern char **environ;

void handle_logical_operators(char *line);
void *safe_malloc(size_t size);
void print_all_aliases(void);
char *get_alias_value(const char *name);
void add_alias(const char *name, const char *value);
void update_alias(const char *name, const char *value);
char *get_current_directory(void);
char *_strcat(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdup(char *str);
int _atoi(char *s);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int count_input(char *str);
int count_delims(char *str, char *del);
char *remove_new_line(char *str);
void signal_handler(int sig_id);
void _open_help(void);
void _print_env(void);
void _handle_exit(char **u_tokns, char *line);
int execBuiltInCommands(char **u_tokns, char *line);
void frees_get_env(char *env_path);
void frees_tokens(char **tokns);
int exec(char *cname, char **opts);
char *_getenv(const char *name);
char **tokenize(char *str, char *del, int len);
char *find(char *cname);

#endif /* SHELL_H */
