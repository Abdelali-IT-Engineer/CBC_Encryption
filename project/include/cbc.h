#ifndef CBC_H
#define CBC_H

#include "../include/linkedlist.h"

// Structure représentant le contexte du chiffrement CBC
struct CBC {
  struct Node *iv; // Vecteur d'initialisation
};

// Fonction pour chiffrer un bloc de données en utilisant le mode CBC
void encryptBlock(struct Node **block, struct Node *iv);

// Fonction pour déchiffrer un bloc de données en utilisant le mode CBC
void decryptBlock(struct Node **block, struct Node *iv);

#endif 
