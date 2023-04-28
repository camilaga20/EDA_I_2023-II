// Ejemplo de implementación de lista doblemente ligada
#include <stdio.h>
#include <stdlib.h>

// creación de nodo
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// insertar nodo por el frente
void insertFront(struct Node** head, int data) {
  // asignar memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // asignar dato al nuevo nodo
  newNode->data = data;

  // hacer al nuevo nodo como la cabeza
  newNode->next = (*head);

  // asignar como null al nodo prev
  newNode->prev = NULL;

  // previo a cabeza (ahora cabeza es el segundo nodo) es el nuevo nodo
  if ((*head) != NULL)
    (*head)->prev = newNode;

  // cabeza apunta al nuevo nodo
  (*head) = newNode;
}

// insertar un nodo después de un nodo específico
void insertAfter(struct Node* prev_node, int data) {
  // comprobar si el nodo previo está null
  if (prev_node == NULL) {
    printf("Nodo previo no puede ser null");
    return;
  }

  // asignar memoria para el nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // asignar dato al nuevo nodo
  newNode->data = data;

  // establecer next del nuevo nodo al next del nodo prev
  newNode->next = prev_node->next;

  // establecer next del nodo prev como nuevo nodo
  prev_node->next = newNode;

  // establecer prev del nuevo nodo al nodo previo
  newNode->prev = prev_node;

  // establecer prev del nuevo nodo a next del nuevo nodo
  if (newNode->next != NULL)
    newNode->next->prev = newNode;
}

// insertar un nuevo nodo al final de la lista
void insertEnd(struct Node** head, int data) {
  // asignar memoria para el nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // asignar dato al nuevo nodo
  newNode->data = data;

  // asignar null al siguiente del nuevo nodo
  newNode->next = NULL;

  // almacenar el nodo cabeza temporalmente (para uso posterior)
  struct Node* temp = *head;

  // si la lista ligada está vacía, hacer el nuevo nodo como cabeza
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  // si la lista ligada no está vacía, recorrer hasta el final de la lista ligada
  while (temp->next != NULL)
    temp = temp->next;

  // ahora, el último nodo de la lista ligada es un nodo temporal

  // se asigna next del último nodo (temp) al nuevo nodo
  temp->next = newNode;

  // se asigna prev del nuevo nodo a temp
  newNode->prev = temp;
}

// eliminar un nodo de la lista doblemente ligada
void deleteNode(struct Node** head, struct Node* del_node) {
  // si cabeza o del es null, no se puede borrar
  if (*head == NULL || del_node == NULL)
    return;

  // si del_node es el nodo cabeza, apuntar el apuntador de la cabeza al siguiente de del_node
  if (*head == del_node)
    *head = del_node->next;

  // si del_node no está en el último nodo, apuntar prev del nodo al next de del_node del previo de del_node
  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;

  // si del_node no es el primer nodo, apuntar next del nodo previo al next de del_node
  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

  // se libera memoria de del_node
  free(del_node);
}

// imprimir la lista doblemente ligada
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {
  // se inicializa un nodo vacío
  struct Node* head = NULL;

  insertEnd(&head, 5);
  insertFront(&head, 1);
  insertFront(&head, 6);
  insertEnd(&head, 9);

  // se inserta 11 después de cabeza
  insertAfter(head, 11);

  // se inserta 15 después del segundo nodo
  insertAfter(head->next, 15);

  displayList(head);

  // se borra el último nodo
  deleteNode(&head, head->next->next->next->next->next);

  displayList(head);
}