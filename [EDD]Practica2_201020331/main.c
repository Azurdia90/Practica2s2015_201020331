#include <stdio.h>
#include <stdlib.h>
#include "Manejo_archivo.h"

/***********************PROTOTIPOS DEL MANEJO DEL ARCHIVO*******************************************/
void menu();
void leer_archivo();
void cargar_datos();
void resultados();
/***************************PROTOTIPOS DE LA LISTE SIMPLE******************************************/
void insertar_lista(Node_list **first, Node_list **last, int clave, int pos);
void imprimir_lista(Node_list **first);
void ordenar_burbuja(Node_list **first);
void ordenamiento_quicksort(Node_list **first, Node_list **last, int primero, int ultimo);
/*********************************PROTOTIPOS DEL ARBOL AVL*****************************************/
void insertar(Node **raiz, int clave, int *h);
void rotacion_II(Node **node, Node *n1);
void rotacion_DD(Node **node, Node *n1);
void rotacion_ID(Node **node, Node *n1);
void rotacion_DI(Node **node, Node *n1);
void imprimir(Node **raiz,int graf);
void graficar(Node **raiz);

/*********************************METODO MAIN DE LA PRACTICA************************************/
int main(){
    menu();
    return 0;
}
