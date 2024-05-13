#include "../include/linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour créer un nouveau nœud dans la liste chaînée
struct Node *createNode(char data) {
  // Allocation de mémoire pour le nouveau nœud
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    // En cas d'échec de l'allocation de mémoire
    perror("createNode");
    exit(EXIT_FAILURE);}
  // Initialisation des données du nouveau nœud
  newNode->data = data;
  newNode->next = NULL;
  return newNode;}
// Fonction pour insérer un nouveau nœud en tête de la liste chaînée
void insertNode(struct Node **head, char data) {
  // Création d'un nouveau nœud
  struct Node *newNode = createNode(data);
  // Mise à jour des liens pour insérer le nouveau nœud en tête
  newNode->next = *head;
  *head = newNode;}
// Fonction pour supprimer un nœud spécifique de la liste chaînée
void deleteNode(struct Node **head, char data) {
  // Initialisation des pointeurs actuel et précédent
  struct Node *current = *head;
  struct Node *prev = NULL;
  // Recherche du nœud à supprimer
  while (current != NULL && current->data != data) {
    prev = current;
    current = current->next;}
  // Si le nœud n'est pas trouvé
  if (current == NULL) {
    return; }
  // Mise à jour des liens pour supprimer le nœud de la liste
  if (prev == NULL) {
    *head = current->next;
  } else {
    prev->next = current->next;
  }
  // Libération de la mémoire du nœud supprimé
  free(current);}
// Fonction pour afficher les données de la liste chaînée
void displayList(struct Node *head) {
  while (head != NULL) {
    // Affichage des données du nœud
    printf("%c ", head->data);
    head = head->next; }
  printf("\n");}
