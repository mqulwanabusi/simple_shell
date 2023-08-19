#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(const char *command) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* Child process */
        if (execlp(command, command, NULL) == -1) {
            perror("Command execution error");
            exit(EXIT_FAILURE);
        }
    } else {
        /* Parent process */
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    
    while (1) {
        printf("#cisfun$ ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        
        /*  Remove the newline character */
        command[strlen(command) - 1] = '\0';
        
        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        execute_command(command);
    }

    return 0;
}