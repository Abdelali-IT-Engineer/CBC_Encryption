#include "../include/fileio.h"
#include <stdio.h>
#include <stdlib.h>

struct Node *readFile(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("readFile");
    exit(EXIT_FAILURE);
  }

  struct Node *head = NULL;
  char c;

  while ((c = fgetc(file)) != EOF) {
    insertNode(&head, c);
  }

  fclose(file);
  return head;
}

void writeFile(const char *filename, struct Node *data) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("writeFile");
    exit(EXIT_FAILURE);
  }

  while (data != NULL) {
    fputc(data->data, file);
    data = data->next;
  }

  fclose(file);
}
