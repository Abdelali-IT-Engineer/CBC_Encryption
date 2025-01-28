#ifndef FILEIO_H
#define FILEIO_H

#include "../include/linkedlist.h"

// Fonction pour lire les données d'un fichier et les stocker dans une liste chaînée
struct Node *readFile(const char *filename);

// Fonction pour écrire les données d'une liste chaînée dans un fichier
void writeFile(const char *filename, struct Node *data);

#endif 
