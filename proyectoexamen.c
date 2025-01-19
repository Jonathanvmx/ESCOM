// Proyecto examen
// Vazquez de la Rosa Jonathan Adrian

#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
  int valor
  struct nodo *izquierdo;
  struct nodo *derecho;
} Nodo;
//funciones del árbol
nodo* insertar(nodo* raiz, int valor);
nodo* buscar(nodo* raiz, int valor);
nodo* eliminar(nodo* raiz, int valor);
nodo* encontrarMin(nodo* raiz);
void recorridoInorden(nodo* raiz);
void recorridoPreorden(nodo* raiz);
void recorridoPosorden(nodo* raiz);
void recorridoAmplitud(nodo* raiz);
void imprimirArbol(nodo* raiz, int nivel);
//funcion para crear un nuevo nodo
nodo* crearnodo(int valor){
  nodo* nuevonodo = (nodo*)malloc(sizeof(nodo));
  nuevonodo->valor = valor;
  nuevonodo->izquierda = NULL;
  nuevonodo->derecha = NULL;
  return nuevonodo;
}
nodo* insertar(nodo* raiz, int valor){
  if (raiz == NULL){
    return crearnodo(valor);
  }
  if (valor < raiz->valor){
    raiz->izquierda = insertar(raiz->izquierda, valor);
  } else if (valor > raiz->valor){
    raiz->derecha = insertar(raiz->derecha);
  }
  return raiz;
}
//funcion para buscar en el arbol
nodo* buscar(nodo* raiz, valor){
  if (raiz == NULL || raiz-> valor == valor){
    return raiz;
  }
  if (valor < raiz->valor){
    return buscar (raiz->izquierda,valor)
  }
  return buscar (raiz->derecha, valor);
}
nodo* encontrarMin(nodo* nodo){
  nodo* atual = nodo;
  while (actual && actual->izquierda !=NULL){
    actual =actual->iquierda;
  }
  return actual;
}
nodo* eliminar(nodo* raiz, int valor){
  if (raiz == NULL){
    return raiz;
  }
  if (valor < raiz->valor){
    raiz->izquierda = eiminar(raiz->iquierda, valor);
  } else if (valor > raiz->valor){
    raiz->derecha = eliminar(raiz->derecha, valor);
  } else {
    if (raiz->izquierda == NULL){
      nodo* temp = raiz->derecha;
      free(raiz);
      return temp;
    } else if (raiz->dereha == NULL){
      nodo* temp = raiz->izquierda;
      free(raiz);
      return temp;
    }
    nodo* temp = encontrarMin(raiz->derecha);
    raiz->valor = temp =valor;
    raiz->derecha =eliminar(raiz->derecha, temp->valor);
  }
  return raiz;
}

void mostrarmenu(){
  printf("\nMenu\n");
  printf("1. Insertar un elemento\n");
  printf("2. Buscar un elemento\n");
  printf("3. Eliminar un elemento\n");
  printf("4. Recorrido en amplitud\n");
  printf("5. Recorrido en preorden\n");
  printf("6. Recorrido en inorden\n");
  printf("7. Recorrido posorden\n");
  printf("8. Imprimir el árbol\n");
  printf("9. Salir\n");
}
int main(){

}

