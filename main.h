#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/* Function prototypes for main.c */
void execute_command(char *command);

/* Function prototypes for getline.c */
char *get_input(void);

/* Function prototypes for tokenizer.c */
char **tokenize_input(char *input);

/* Function prototypes for executor.c */
int execute(char **args);

/* Function prototypes for env.c */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);

/* Function prototypes for alias.c */
int set_alias(char **args);
int unset_alias(char **args);

/* Function prototypes for comments.c */
void remove_comments(char *input);

/* Function prototypes for commands-separator.c */
char **split_commands(char *input);

/* Function prototypes for filehandler.c */
void redirect_output(char *output_file);
void redirect_input(char *input_file);

/* Function prototypes for prompt.c */
void display_prompt(void);

/* Function prototypes for errorhandler.c */
void handle_error(char *message);

#endif /* MAIN_H */

