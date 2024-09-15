#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[100];
    while (1) {
        printf("$ ");
        fflush(stdout);
        fgets(input, 100, stdin);
        int n = strlen(input);
        input[n - 1] = '\0';
        if (!strcmp(input, "exit 0"))
            exit(0);
        if (!strncmp(input, "echo ", 5)) {
            printf("%s\n", input + 5);
            continue;
        }
        printf("%s: command not found\n", input);
    }
    return 0;
}
