#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Définition de la structure pour un nœud dans une liste chaînée
struct Node {
  char data;         // Donnée stockée dans le nœud
  struct Node *next; // Pointeur vers le prochain nœud dans la liste
};

// Signature de la fonction pour créer un nouveau nœud
struct Node *createNode(char data);

// Signature de la fonction pour insérer un nouveau nœud en tête de liste
void insertNode(struct Node **head, char data);

// Signature de la fonction pour supprimer un nœud spécifique de la liste
void deleteNode(struct Node **head, char data);

// Signature de la fonction pour afficher les données de la liste
void displayList(struct Node *head);

#endif
