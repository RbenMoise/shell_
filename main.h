#ifndef MAIN_H
#define MAIN_H

/* Include necessary libraries and define constants*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/* Declare functions used in main.c*/
void executeCommand(char *input);

#endif

