// Proyecto examen
// Vazquez de la Rosa Jonathan Adrian

#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
  int valor
  struct nodo *izquierdo;
  struct nodo *derecho;
} Nodo;

Nodo* crearNodo (int valor)
  {
  Nodo* nuevonodo = (Nodo*)
}
int main ()
{
  Nodo* raiz = NULL;
  int opcion, valor;
  do{
    printf("\nMenu de opciones\n");
    printf("1. Insertar un elemento\n");
    printf("2. Buscar un elemento\n");
    printf("3. Eliminar un elemento\n");
    printf("4. Recorrido en amplitud\n");
    printf("5. Recorrido en preorden\n");
    printf("6. Recorrido en inorden\n");
    printf("7. Recorrido posorden\n");
    printf("8. Imprimir el arbol\n");
    printf("9. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    
    switch (opcion){
      case 1
    }
  }
}

