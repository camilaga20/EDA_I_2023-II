#include <stdio.h>
#include <stdlib.h>

// definiciónde un nodo de la lista ligada circular
struct Nodo {
    int val;
    struct Nodo* siguiente;
};

//insertar nodo al final de la lista ligada circular
void insertar(struct Nodo** cabeza, int val) {
    struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    newNodo->val = val;
    newNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = newNodo;
        newNodo->siguiente = newNodo;
        return;
    }

    // se busca el último nodo de la lista
    struct Nodo* ultimo = (*cabeza)->siguiente;
    while (ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }

    // se enlaza el nuevo nodo al final de la lista y se enlaza consigo mismo
    ultimo->siguiente = newNodo;
    newNodo->siguiente = *cabeza;
}

// función para imprimir la lista ligada circular
void imprimir(struct Nodo* cabeza) {
    // si la lista está vacía, se muestra un mensaje
    if (cabeza == NULL) {
        printf("La lista esta vacía.\n");
        return;
    }

    // se hace un recorrido para que se muestre cada valor
    printf("Lista ligada circular: ");
    struct Nodo* actual = cabeza;
    do {
        printf("%d ", actual->val);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("\n");
}

// función para buscar un valor en la lista ligada circular
void buscar(struct Nodo* cabeza, int valBuscar) {
    // si la lista está vacía, se muestra un mensaje y se termina la función
    if (cabeza == NULL) {
        printf("La lista esta vacia. No se puede buscar el valor.\n");
        return;
    }

    // se recorre la lista desde la cabeza y se compara cada valor con el valor buscado
    struct Nodo* final = cabeza;
    do {
        if (final->val == valBuscar) {
            printf("El valor %d se encuentra en la lista.\n", valBuscar);
            return;
        }
        final = final->siguiente;
    } while (final != cabeza);

    // si se llega al final de la lista sin encontrar el valor, se muestra un mensaje
    printf("El valor %d no esta en la lista.\n", valBuscar);
}

// función principal del programa
int main() {
    // se crea una lista ligada circular con valores predefinidos
    struct Nodo* cabeza = NULL;
    insertar(&cabeza, 2);
    insertar(&cabeza, 4);
    insertar(&cabeza, 6);
    insertar(&cabeza, 8);
    insertar(&cabeza, 7);

    
    imprimir(cabeza);

   
    int valBuscar;
    printf("Introduce un valor que quieras encontrar en la lista: ");
    scanf("%d", &valBuscar);

   
    buscar(cabeza, valBuscar);

   
    imprimir(cabeza);

    return 0;
}