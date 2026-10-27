#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];

    while(1) {
        printf("Enter your name (or type 'exit' to quit): ");
        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = 0;

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Hello, %s!\n", name);
    }


    return 0;
}

