#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  int mayorNum = arr[0];
  for (int i = 0; i < size; i++)
    if (mayorNum < arr[i]) {
      mayorNum = arr[i];
    }
  return mayorNum;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  for (int i = 0; i < size / 2; i++){
    int num = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = num;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una direccion valida que no ha sido inicializada con ningun valor especifico.
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) {
  *newSize = 0;
  int *paresArr = (int *)malloc(size * sizeof(int));
  if(paresArr == NULL) exit(EXIT_FAILURE);
  
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      paresArr[*newSize] = arr[i];
      (*newSize)++;
    }
  }
  return paresArr;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos arreglos
en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
  int x = 0;
  int y = 0;
  int sumSize = size1 + size2;
  for (int i = 0; i < sumSize; i++) {
    if (y < size1 && (x >= size2 || arr1[y] <= arr2[x])){
      result[i] = arr1[y++];
    } 
    else{
      result[i] = arr2[x++];
    }
  }
}
/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int ascendente = 1;
  int descendente = 1;

  for (int i = 0; i < size-1; i++){
    if (arr[i] > arr[i + 1]) {
      ascendente = 0;
      break;
    }
  }
  for (int i = 0; i < size-1; i++){
    if (arr[i] < arr[i+1]) {
      descendente = 0;
       break;
    }
  }
  if (ascendente) return 1;
  else if (descendente)  return -1;
  else  return 0;
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/
typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;

}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente;
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  Nodo *head = NULL;
  Nodo *actual = NULL;
  for (int i = 0; i < size; i++){
    Nodo *lista = (Nodo *)malloc(sizeof(Nodo));
    if (lista == NULL) exit(EXIT_FAILURE);
    lista->numero = arr[i];
    lista->siguiente = NULL;

    if(head == NULL){
      head = lista;
      actual = lista;
    }
    else{
      actual->siguiente = lista;
      actual = actual->siguiente;
    }
  }
  return head;
}
