#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  // You can use print statements as follows for debugging, they'll be visible
Expand 9 lines
    fgets(input, 100, stdin);
    int n = strlen(input);
    input[n - 1] = '\0';
    if (!strcmp(input, "exit 0"))
      exit(0);
    printf("%s: command not found\n", input);
  }
  return 0;