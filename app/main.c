#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUILTIN_CMDS_NUM 3
const char *builtin_cmds[BUILTIN_CMDS_NUM] = {"echo", "exit", "type"};

int is_builtin(const char *cmd) {
    for (int i = 0; i < BUILTIN_CMDS_NUM; ++i) {
        if (!strcmp(builtin_cmds[i], cmd))
            return 1;
    }
    return 0;
}

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
        if (!strncmp(input, "type ", 5)) {
            const char *cmd = input + 5;
            if (is_builtin(cmd))
                printf("%s is a shell builtin\n", cmd);
            else
                printf("%s: not found\n", cmd);
            continue;
        }
        printf("%s: command not found\n", input);
    }
    return 0;
}

