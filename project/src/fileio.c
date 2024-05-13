#include "../include/fileio.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour lire les données d'un fichier et les stocker dans une liste
// chaînée
struct Node *readFile(const char *filename) {
  // Ouvre le fichier en mode lecture
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("readFile");
    exit(EXIT_FAILURE);
  }

  // Initialise la liste chaînée
  struct Node *head = NULL;
  char c;

  // Lit chaque caractère du fichier et insère dans la liste chaînée
  while ((c = fgetc(file)) != EOF) {
    insertNode(&head, c);
  }

  // Ferme le fichier après lecture
  fclose(file);
  return head;
}

// Fonction pour écrire les données d'une liste chaînée dans un fichier
void writeFile(const char *filename, struct Node *data) {
  // Ouvre le fichier en mode écriture
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("writeFile");
    exit(EXIT_FAILURE);
  }

  // Écrit chaque nœud de la liste chaînée dans le fichier
  while (data != NULL) {
    fputc(data->data, file);
    data = data->next;
  }

  // Ferme le fichier après écriture
  fclose(file);
}
