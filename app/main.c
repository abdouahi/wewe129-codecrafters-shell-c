#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to check if a file exists and is executable
int is_executable(const char *path) { return access(path, X_OK) == 0; }

// Function to search for a command in the PATH
char *find_in_path(const char *command) {
  char *path_env = getenv("PATH");
  if (path_env == NULL) {
    return NULL;
  }
  char *path_copy = strdup(path_env);
  char *dir = strtok(path_copy, ":");
  static char full_path[1024];
  while (dir != NULL) {
    snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
    if (access(full_path, X_OK) == 0) {
      free(path_copy);
      return strdup(full_path);
    }
    dir = strtok(NULL, ":");
  }
  free(path_copy);
  return NULL;
}

int main() {
  while (1) {
    // Print the shell prompt
    printf("$ ");
    fflush(stdout);
    // Wait for user input
    char input[100];
    if (fgets(input, sizeof(input), stdin) == NULL) {
      break;
    }
    // Remove the trailing newline character from the input
    input[strcspn(input, "\n")] = 0;
    // Handle empty input
    if (strlen(input) == 0) {
      continue;
    }
    // Check if the command is "exit 0"
    if (strcmp(input, "exit 0") == 0) {
      return 0;
    }
    // Check if the command starts with "echo "
    if (strncmp(input, "echo ", 5) == 0) {
      printf("%s\n", input + 5);
      continue;
    }
    // Check if the command starts with "type "
    if (strncmp(input, "type ", 5) == 0) {
      char *command = input + 5;
      // Check for built-in commands
      if (strcmp(command, "echo") == 0 || strcmp(command, "exit") == 0 ||
          strcmp(command, "type") == 0) {
        printf("%s is a shell builtin\n", command);
      } else {
        char *path = find_in_path(command);
        if (path) {
          printf("%s is %s\n", command, path);
          free(path);
        } else {
          printf("%s: not found\n", command);
        }
      }
      continue;
    }
    // Print the command not found message
    printf("%s: command not found\n", input);

  }
  return 0;
}