#include "../include/cbc.h" /*Noms des fichiers*/
#include "../include/fileio.h"
#include "../include/linkedlist.h"
#include <stdio.h> // Cette bibliothèque fournit des fonctions pour les opérations d'entrée/sortie standard, comme printf et scanf.
#include <stdlib.h> // Cette bibliothèque offre des fonctions pour la gestion de la mémoire dynamique, telles que malloc et free.
#include <string.h> // Cette bibliothèque contient des fonctions pour manipuler des chaînes de caractères, telles que strcpy et strlen.

int main() {
  // Lire les données d'un fichier dans une liste chaînée
  struct Node *data = readFile("project/Makefiles/input.txt");
  printf("Original Data: ");
  displayList(data);

  // Coder une liste chaînée par CBC encryption
  struct Node *iv = createNode('0');
  struct Node *current = data;
  while (current != NULL) {
    encryptBlock(&current, iv);
    current = current->next;
  }
  printf("Encrypted Data: ");
  displayList(data);

  // Ecrire les données codées dans un fichier
  writeFile("project/Makefiles/encrypted.txt", data);

  // Vider la memoire
  while (data != NULL) {
    struct Node *temp = data;
    data = data->next;
    free(temp);
  }

  free(iv);

  return 0;
}
