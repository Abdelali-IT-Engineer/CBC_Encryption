#include "../include/cbc.h"
#include <stdio.h>

// Fonction pour chiffrer un bloc de données en utilisant le mode CBC
void encryptBlock(struct Node **block, struct Node *iv) {
  // Vérification si le bloc est nul
  if (*block == NULL) {
    return;
  }

  // Opération de chiffrement XOR avec le vecteur d'initialisation (IV)
  (*block)->data ^= iv->data;
  // Met à jour le vecteur d'initialisation avec la donnée chiffrée actuelle
  iv->data = (*block)->data;
}

// Fonction pour déchiffrer un bloc de données en utilisant le mode CBC
void decryptBlock(struct Node **block, struct Node *iv) {
  // Vérification si le bloc est nul
  if (*block == NULL) {
    return;
  }

  // Opération de déchiffrement XOR avec le vecteur d'initialisation (IV)
  (*block)->data ^= iv->data;
  // Met à jour le vecteur d'initialisation avec la donnée déchiffrée actuelle
  iv->data = (*block)->data;
}
