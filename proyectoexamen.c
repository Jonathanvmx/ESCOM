// Proyecto examen
// Vazquez de la Rosa Jonathan Adrian
#include <stdio.h>
#include <stdlib.h>
// Estructura del nodo del árbol
typedef struct Nodo {
    int valor;
    struct Nodo* izquierda;
    struct Nodo* derecha;
} Nodo;

// Funciones del árbol
Nodo* insertar(Nodo* raiz, int valor);
Nodo* buscar(Nodo* raiz, int valor);
Nodo* eliminar(Nodo* raiz, int valor);
Nodo* encontrarMin(Nodo* raiz);
void recorridoInorden(Nodo* raiz);
void recorridoPreorden(Nodo* raiz);
void recorridoPostorden(Nodo* raiz);
void recorridoAmplitud(Nodo* raiz);
void imprimirArbol(Nodo* raiz, int nivel);

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Insertar un elemento en el árbol
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }
    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }
    return raiz;
}

// Buscar un elemento en el árbol
Nodo* buscar(Nodo* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->izquierda, valor);
    }
    return buscar(raiz->derecha, valor);
}

// Encontrar el nodo con el valor mínimo
Nodo* encontrarMin(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual && actual->izquierda != NULL) {
        actual = actual->izquierda;
    }
    return actual;
}

// Eliminar un elemento del árbol
Nodo* eliminar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }
    if (valor < raiz->valor) {
        raiz->izquierda = eliminar(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = eliminar(raiz->derecha, valor);
    } else {
        if (raiz->izquierda == NULL) {
            Nodo* temp = raiz->derecha;
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {
            Nodo* temp = raiz->izquierda;
            free(raiz);
            return temp;
        }
        Nodo* temp = encontrarMin(raiz->derecha);
        raiz->valor = temp->valor;
        raiz->derecha = eliminar(raiz->derecha, temp->valor);
    }
    return raiz;
}

// Recorrido en amplitud del árbol
void recorridoAmplitud(Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }
    Nodo** cola = (Nodo**)malloc(100 * sizeof(Nodo*));
    int frente = 0, final = 0;
    cola[final++] = raiz;
    while (frente < final) {
        Nodo* actual = cola[frente++];
        printf("%d ", actual->valor);
        if (actual->izquierda != NULL) {
            cola[final++] = actual->izquierda;
        }
        if (actual->derecha != NULL) {
            cola[final++] = actual->derecha;
        }
    }
    free(cola);
}

// Recorrido en preorden del árbol
void recorridoPreorden(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        recorridoPreorden(raiz->izquierda);
        recorridoPreorden(raiz->derecha);
    }
}

// Recorrido en inorden del árbol
void recorridoInorden(Nodo* raiz) {
    if (raiz != NULL) {
        recorridoInorden(raiz->izquierda);
        printf("%d ", raiz->valor);
        recorridoInorden(raiz->derecha);
    }
}

// Recorrido en postorden del árbol
void recorridoPostorden(Nodo* raiz) {
    if (raiz != NULL) {
        recorridoPostorden(raiz->izquierda);
        recorridoPostorden(raiz->derecha);
        printf("%d ", raiz->valor);
    }
}

// Imprimir el árbol (en inorden)
void imprimirArbol(Nodo* raiz, int nivel) {
    if (raiz != NULL) {
        imprimirArbol(raiz->izquierda, nivel + 1);
        printf("%*s%d\n", nivel * 4, "", raiz->valor);
        imprimirArbol(raiz->derecha, nivel + 1);
    }
}
// Mostrar el menú
void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Insertar elemento\n");
    printf("2. Buscar elemento\n");
    printf("3. Eliminar elemento\n");
    printf("4. Recorrido en amplitud\n");
    printf("5. Recorrido en preorden\n");
    printf("6. Recorrido en inorden\n");
    printf("7. Recorrido en postorden\n");
    printf("8. Imprimir árbol\n");
    printf("9. Salir\n");
}

int main() {
    Nodo* raiz = NULL;
    int opcion, valor;

    do {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                raiz = insertar(raiz, valor);
                break;
            case 2:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                Nodo* encontrado = buscar(raiz, valor);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado.\n", valor);
                } else {
                    printf("Elemento %d no encontrado.\n", valor);
                }
                break;
            case 3:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                raiz = eliminar(raiz, valor);
                break;
            case 4:
                printf("Recorrido en amplitud: ");
                recorridoAmplitud(raiz);
                printf("\n");
                break;
            case 5:
                printf("Recorrido en preorden: ");
                recorridoPreorden(raiz);
                printf("\n");
                break;
            case 6:
                printf("Recorrido en inorden: ");
                recorridoInorden(raiz);
                printf("\n");
                break;
            case 7:
                printf("Recorrido en postorden: ");
                recorridoPostorden(raiz);
                printf("\n");
                break;
            case 8:
                printf("Árbol en inorden: ");
                imprimirArbol(raiz, 0);
                printf("\n");
                break;
            case 9:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 9);

    return 0;
}
