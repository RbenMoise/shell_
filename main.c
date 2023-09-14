#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    int should_run = 1;
    pid_t pid; /* Move the declaration here */

    while (should_run) {
        printf("#cisfun$ "); /* Display the prompt */
        fflush(stdout); /* Make sure the prompt is displayed */

        /* Read user input */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; /* Exit on Ctrl+D */
        }

        /* Remove trailing newline */
        input[strcspn(input, "\n")] = '\0';

        /* Check for the "exit" command */
        if (strcmp(input, "exit") == 0) {
            should_run = 0;
            continue; /* Skip the fork/exec process */
        }

        /* Fork a new process */
        pid = fork();

        if (pid < 0) {
            perror("Fork failed");
        } else if (pid == 0) {
            /* Child process */
            if (execlp(input, input, NULL) == -1) {
                perror("Execution failed");
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                if (WEXITSTATUS(status) != 0) {
                    printf("Command exited with non-zero status %d\n", WEXITSTATUS(status));
                }
            } else {
                printf("Command terminated abnormally\n");
            }
        }
    }

    return 0;
}

