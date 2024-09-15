#include <stdio.h>
#include <string.h>
int repl() {
  printf("$ ");
  fflush(stdout);
  // Wait for user input
  char input[100];
  char *s = fgets(input, 100, stdin);
  if (s == 0) {
    return 0;
  }
  int l = strlen(input);
  input[l - 1] = 0;
  char *cmd = input;
  char *args = input;
  for (int i = 0; i < l; i++) {
    if (input[i] == ' ') {
      input[i] = 0;
      if (i < l - 1) {
        args += i + 1;
      }
      break;
    }
  }
  if (0 == strcmp("exit", cmd)) {
    return 0;
  } else if (0 == strcmp("type", cmd)) {
    if (0 == strcmp("echo", args) || 0 == strcmp("exit", args) ||
        0 == strcmp("type", args)) {
      printf("%s is a shell builtin\n", args);
    } else {
      printf("%s not found\n", args);
    }
  } else if (0 == strcmp("echo", cmd)) {
    puts(args);
    fflush(stdout);
  } else {
    printf("%s: command not found\n", input);
    fflush(stdout);
  }
  fflush(stdout);
  return 1;
}
int main() {
  while (repl())
    ;
  return 0;
}

