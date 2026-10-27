#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char command[100];

    while(1) {
        printf(">> ");
        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }
        else{
            pid_t pid = fork();

            if (pid < 0) {
                perror("fork failed");
                return 1;
            }
            else if (pid == 0) {
                char *split = strtok(command, " ");
                char *array[100];
                int i = 0;
                while (split != NULL) {
                    array[i++] = split;
                    split = strtok(NULL, " ");
                }
                array[i] = NULL;
                execvp(array[0], array);
                perror("execvp failed");
                return 1;
            }
            else {
                wait(NULL);
            }
        }

    }


    return 0;
}

