#include <stdio.h>
#include <stdlib.h>
#include "memalloc_j/memalloc_j.h"

#define TOKEN_BUF_SIZE 64
#define TOKEN_DELIM " \t\n\r\a"

char *read_line() {
  char *line = NULL;
  size_t buf_size = 0;
  
  if (getline(&line, &buf_size, stdin) == -1) {
    if (feof(stdin)) exit(0);
    perror("Error at read_line");
    exit(1);
  }
}

char **get_args(char *line) {
  int buf_size = TOKEN_BUF_SIZE;
  int position = 0;
  char **tokens = malloc_j(sizeof(char*) * buf_size);
  char *token;

  if (!tokens) {
    perror("Error allocating memory at get_args");
    exit(1);
  }
}

int execute_command(char **args) {

  return 0;
}

void shell_loop() {
  char *line;
  char **args;
  int status;

  do {
    printf("# ");
    line = read_line();
    args = get_args(line);
    status = execute_command(args);

    free_j(line);
    free_j(args);
  } while (status);
}

int main(int argc, char **argv) {
  
  shell_loop();

  return 0;
}
