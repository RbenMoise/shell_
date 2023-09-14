#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_INPUT_SIZE / 2 + 1];
    int should_run = 1;

    char *token; // Declare token here
    int arg_count;

    while (should_run) {
        printf("Shell > ");
        fflush(stdout);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF (Ctrl+D)
        }

        // Tokenize the input
        token = strtok(input, " \n");
        arg_count = 0;

        while (token != NULL) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " \n");
        }

        args[arg_count] = NULL;

        // Check for exit command
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            printf("Exiting the shell...\n");
        } else {
            // Fork a new process
            pid_t pid = fork();

            if (pid < 0) {
                perror("Fork failed");
            } else if (pid == 0) {
                // Child process
                if (execvp(args[0], args) == -1) {
                    perror("Execution failed");
                    exit(EXIT_FAILURE);  // Exit the child process on failure
                }
            } else {
                // Parent process
                int status;
                waitpid(pid, &status, 0);

                if (WIFEXITED(status)) {
                    printf("Child process exited with status %d\n", WEXITSTATUS(status));
                } else {
                    printf("Child process terminated abnormally\n");
                }
            }
        }
    }

    return 0;
}
