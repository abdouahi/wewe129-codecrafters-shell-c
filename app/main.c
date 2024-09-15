#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
    char input_buffer[100];

    for (;;) {
        printf("$ ");
        fflush(stdout);

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            return 1;
        }

        size_t input_length = strlen(input_buffer);
        if (input_length > 0 && input_buffer[input_length - 1] == '\n') {
            input_buffer[--input_length] = '\0';
        }

        if (input_length == 0) {
            continue;
        }

        if (strcmp(input_buffer, "exit") == 0) {
            return 0;
        }

        printf("%s: command not found\n", input_buffer);
    }
    return 0;

}

