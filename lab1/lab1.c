#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Enter your command:\n> ");

  char *buff = NULL;
  size_t size = 0;

  // getline() allocates buffer, which we must free
  if (getline(&buff, &size, stdin) != -1L) {

    // Tokenize the string
    char *inputStr = buff;
    char *delim = " \t\n\r";
    char *token = NULL;
    char *saveptr = NULL;

    // inputStr must contain the real string on the first call, but be NULL later
    // saveptr must be null the first time, and is set later
    // stores status so call is reentrant

    while ((token = strtok_r(inputStr, delim, &saveptr))) {
      printf("Token: '%s'\n", token);

      inputStr = NULL;
    }
  } else {
    printf("Getline failure.\n");
  }
  free(buff);
}
