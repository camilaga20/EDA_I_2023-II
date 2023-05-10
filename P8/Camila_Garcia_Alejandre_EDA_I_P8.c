#include <stdio.h>
#include <stdlib.h>

//Definir nodo
struct Nodo {
  int dato;
  struct Nodo *anterior;
  struct Nodo *siguiente;
};

//Función para hacer nuevo nodo
struct Nodo* hacerNodo(int dato) {
  struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->anterior = NULL;
  nuevoNodo->siguiente = NULL;
  return nuevoNodo;
}

// Función para añadir nodo al inicio
void addInicio(struct Nodo** cabeza, int dato) {
  struct Nodo* nuevoNodo = hacerNodo(dato);
    if (*cabeza == NULL) {
      nuevoNodo->siguiente = nuevoNodo;
      nuevoNodo->anterior = nuevoNodo;
    *cabeza = nuevoNodo;
    } else {
      nuevoNodo->siguiente = *cabeza;
      nuevoNodo->anterior = (*cabeza)->anterior;
      (*cabeza)->anterior->siguiente = nuevoNodo;
      (*cabeza)->anterior = nuevoNodo;
      *cabeza = nuevoNodo;
      }
}

// Función para añadir nodo al final 
void addFinal(struct Nodo** cabeza, int dato) {
  struct Nodo* nuevoNodo = hacerNodo(dato);
  if (*cabeza == NULL) {
    nuevoNodo->siguiente = nuevoNodo;
    nuevoNodo->anterior = nuevoNodo;
    *cabeza = nuevoNodo;
  } else {
    nuevoNodo->anterior = (*cabeza)->anterior;
    nuevoNodo->siguiente = *cabeza;
    (*cabeza)->anterior->siguiente = nuevoNodo;
    (*cabeza)->anterior = nuevoNodo;
  }
}

// Función para agregar nodo en la posición que se quiera en la lista
void addEspecifica(struct Nodo** cabeza, int dato, int posicion) {
  struct Nodo* nuevoNodo = hacerNodo(dato);
    if (*cabeza == NULL) {
    nuevoNodo->siguiente = nuevoNodo;
    nuevoNodo->anterior = nuevoNodo;
    *cabeza = nuevoNodo;
    } else {
      struct Nodo* actual = *cabeza;
      int i = 1;
      while (i < posicion && actual->siguiente != *cabeza) {
      actual = actual->siguiente;
      i++;
       }
    if (i == posicion) {
      nuevoNodo->siguiente = actual->siguiente;
      nuevoNodo->anterior = actual;
      actual->siguiente->anterior = nuevoNodo;
      actual->siguiente = nuevoNodo;
    } else
      {
      printf("La posición seleccionada no forma parte de la lista.\n");
      }
  }
}

// Función para eliminar el nodo que encabeza la lista (primero)
void deleteInicio(struct Nodo** cabeza) {
  if (*cabeza == NULL) {
    printf("La lista está vacía.\n");
  } else 

  if ((*cabeza)->siguiente == *cabeza) {
    free(*cabeza);
    *cabeza = NULL;
  } 
  else {
    struct Nodo* temp = *cabeza;

     (*cabeza)->siguiente->anterior = (*cabeza)->anterior;
     (*cabeza)->anterior->siguiente = (*cabeza)->siguiente;
     *cabeza = (*cabeza)->siguiente;
     free(temp);
   }
}

// Función para eliminar nodo que cierra la lista (último)
void deleteFinal(struct Nodo** cabeza) {
  if (*cabeza == NULL) {
   printf("La lista está vacía.\n");
   } else 
   
   if ((*cabeza)->siguiente == *cabeza) {
    free(*cabeza);
    cabeza = NULL;
    } 
    
    else {
      struct Nodo *temp = (*cabeza)->anterior;
      (*cabeza)->anterior = (*cabeza)->anterior->anterior;
      (*cabeza)->anterior->siguiente = *cabeza;
      free(temp);
    }
}

// Función para eliminar nodo de posición especifica
void deleteEnPosicion(struct Nodo** cabeza, int posicion) {

      if (cabeza == NULL) {
       printf("La lista está vacía.\n");
       }
       
      else {
      struct Nodo *actual = *cabeza;
      int i=1;
       while (i < posicion && actual->siguiente != *cabeza) {
       actual = actual->siguiente;
       i++;
      }

      if (i == posicion) {
      actual->anterior->siguiente = actual->siguiente;
      actual->siguiente->anterior = actual->anterior;

       if (actual == *cabeza) {
        *cabeza = actual->siguiente;
        }
         free(actual);
      } 
      else {
       printf("La posición no existe en la lista.\n");
       }
    }
}

//Función para imprimir la lista desde el principio
void printInicio(struct Nodo* cabeza) {

    if (cabeza == NULL) {
      printf("La lista está vacía.\n");
    } 
    
    else {
     struct Nodo* actual = cabeza;
      do {
      printf("%d ", actual->dato);
      actual = actual->siguiente;
    } while (actual != cabeza);
  }
   printf("\n");
}


//Función para imprimir la lista desde el último
void printFinal(struct Nodo* cabeza) {

  if (cabeza == NULL) {
  printf("La lista está vacía.\n");
  } 
  else {
  struct Nodo* actual = cabeza->anterior;
   do {
     printf("%d ", actual->dato);
     actual = actual->anterior;
    } while (actual != cabeza->anterior);
   printf("\n");
   }
}

int main() {
struct Nodo* cabeza = NULL;
int op = 0;
int dato = 0;
int posicion = 0;

// Valores iniciales de la lista
addInicio(&cabeza, 1);
addFinal(&cabeza, 2);
addFinal(&cabeza, 3);
addFinal(&cabeza, 4);

while (op != 7) {
printf("\nMenú de opciones:\n");
printf("1. Añadir elemento al principio\n");
printf("2. Añadir un elemento al final \n");
printf("3. Añadir un elemento en una posición específica \n");
printf("4. Eliminar el primer elemento\n");
printf("5. Eliminar el último elemento\n");
printf("6. Eliminar un elemento en una posición específica\n");
printf("7. Salir del programa\n");


printf("Ingrese la opción que desea realizar: ");
scanf("%d", &op);

switch (op) {
  case 1:
    printf("Ingrese un numero para el principio de la lista: ");
    scanf("%d", &dato);
    addInicio(&cabeza, dato);
    printf("Se agregó el elemento %d al inicio de la lista.\n", dato);
    printf("La lista actual es: ");
    printInicio(cabeza);
    break;
  case 2:
    printf("Ingrese numero para el final de la lista: ");
    scanf("%d", &dato);
    addFinal(&cabeza, dato);
    printf("Se agregó el elemento %d al final de la lista.\n", dato);
    printf("La lista actual es: ");
    printInicio(cabeza);
    break;
  case 3:
    printf("Ingrese el numero que desea agregar: ");
    scanf("%d", &dato);
    printf("Ingrese la posición donde desea agregar el elemento: ");
    scanf("%d", &posicion);
    addEspecifica(&cabeza, dato, posicion);
    printf("Se agregó el elemento %d en la posición %d de la lista.\n", dato, posicion);
    printf("La lista actual es: ");
    printInicio(cabeza);
    break;
  case 4:
    deleteInicio(&cabeza);
    printf("Se eliminó el primer elemento de la lista correctamente.\n");
    printf("La lista actual es: ");
    printInicio(cabeza);
    break;
  case 5:
    deleteFinal(&cabeza);
    printf("Se eliminó el último elemento de la lista correctamente.\n");
    printf("La lista actual es: ");
    printInicio(cabeza);
    break;
  case 6:
    printf("Ingrese la posición del elemento que desea eliminar: ");
    scanf("%d", &posicion);
    deleteEnPosicion(&cabeza, posicion);
    printf("Se eliminó el elemento en la posición %d de la lista correctamente.\n", posicion);
    printf("La lista actual es: ");
    printInicio(cabeza);
    break;
  case 7:
    printf("Gracias por usar el programa. \n");
    break;
  default:
    printf("Opción inválida.\n");
    break;
}
}

return 0;
}