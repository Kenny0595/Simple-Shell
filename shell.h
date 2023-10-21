#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* read/write buffers */
#define READ_BUFFER 1024
#define WRITE_BUFFER 1024
#define BUFFER_FLUSH -1

/* command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX        4096


extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * structure passinfo - itcontains pseudo-arguements that pass into a function,
 * allowing uniform prototype for function struture pointer 
 * @arg: string generated from getline containing arguements
 * @argv:array of strings generated from arguements
 * @path: string path for current command
 * @argc: argument count
 * @line_count: rror count
 * @err_num: error code to exit()s
 * @linecount_flag: if it count the line of input
 * @fname: program filename
 * @env: linked list local copy of environment
 * @environ: modified custom copy of environ from LL envronment
 * @history: history node
 * @alias: alias node
 * @env_changed: if environ was changed
 * @status: return status of last exec'd command
 * @cmd_buf: pointer address to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd from which to read line input
 * @histcount: history line number count
 */
typedef struct passinfo
{
	char *argv;
        char *argc;
	char *path;
	int arg;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
        list_t *alias;
	list_t *history;
	list_t *env;
	char **environ;
	int status;
        int env_changed;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int histcount;
        int readfd;
} info_t;

#define INFO_INIT \
{0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0,NULL, NULL, NULL}

/**
 * struct builtin -it contains a builtin string and related function
 * @type: builtin command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* already created functions */
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
void *_realloc(void *, unsigned int, unsigned int);

/* _shloop.c */
int find_builtin(info_t *);
int hsh(info_t *, char **);
void fork_cmd(info_t *);
void find_cmd(info_t *);

/* _loophsh.c */
int loophsh(char **);


/* view.c */
char *get_path(info_t *, char *, char *);
int exe_cmd(info_t *, char *);
char *_duplicated(char *, int, int);

/* _errors.c */
int _putsfd(char *str, int fd);
void _eputs(char *);
int _putfd(char c, int fd);
int _eputchar(char);

/* _string.c */
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int _strlen(char *);
int _strcmp(char *, char *);

/* _string1.c */
void _puts(char *);
int _putchar(char);
char *_strcpy(char *, char *);
char *_strdup(const char *);

/* free_mem.c */
int free_mem(void **);

/* _tokenizer.c */
char **strtow2(char *, char);
char **strtow(char *, char *);

/* set_mem.c */
char *set_mem(char *, char, unsigned int);

/* free_str.c */
void free_str(char **);

/* _getinput.c */
int _isalpha(int);
int _getinput(char *);
int interactive(info_t *);
int is_delim(char, char *);

/* handle-builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* _errors1.c */
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _errgetinput(char *);
void print_error(info_t *, char *);

/* handle-builtin.c */
int _mycd(info_t *);
int _myhelp(info_t *);
int _myexit(info_t *);

/* read_input.c */
void sig_handler(int);
ssize_t read_input(info_t *);
int _getline(info_t *, char **, size_t *);

/* set_struct.c */
void pop_st(info_t *, char **);
void free_st(info_t *, int);
void init_st(info_t *);

/* _environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* set_env.c */
int un_set_env(info_t *, char *);
int set_env(info_t *, char *, char *);
char **get_env(info_t *);

/* exe_hist.c */
int read_hist(info_t *info);
int hist_list(info_t *info, char *buf,int linecount);
int hist_line_num(info_t *info);
char *get_hist(info_t *info);
int create_hist(info_t *info);

/* list_struct.c */
size_t print_str(const list_t *);
int delete_node(list_t **, unsigned int);
void free_nodes(list_t **);
list_t *start_new_node(list_t **, const char *, int);
list_t *end_new_node(list_t **, const char *, int);

/* linked_lists.c */
size_t _print(const list_t *);
list_t *prefix_node(list_t *, char *, char);
ssize_t get_node(list_t *, list_t *);
size_t _len(const list_t *);
char **_to_strings(list_t *);

/* _vars.c */
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

extern char **environ;

#define MAX_ALIASES 50

typedef struct Alias
{
	char *name;
	char *value;
} Alias;

void run_shell(void);
char *get_input(void);
char **strsplit(const char *str, const char *delim);
void free_tokens(char **tokens);
int count_tokens(char **tokens);
void execute_command(char **args);
void handle_logical_operators(char *line);
void *safe_malloc(size_t size);
char *safe_strdup(const char *str);
void execute_setenv(char **args);
void execute_env(void);
int execute_cd(char **args);
void execute_alias(char **args);
void print_all_aliases(void);
char *get_alias_value(const char *name);
void add_alias(const char *name, const char *value);
void update_alias(const char *name, const char *value);
void execute_unsetenv(char **args);
char *get_current_directory(void);
void execute_exit(char **args);
#endif/* SHELL_H */
