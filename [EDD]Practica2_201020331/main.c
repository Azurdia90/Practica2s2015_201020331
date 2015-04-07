#include <stdio.h>
#include <stdlib.h>
#include "Manejo_archivo.h"

/***********************PROTOTIPOS DEL MANEJO DEL ARCHIVO*******************************************/
void menu();
void leer_archivo();
void cargar_datos1();
void cargar_datos2();
void cargar_datos3();
void resultados();
/*********************************PROTOTIPOS DEL ARBOL AVL*****************************************/
void insertar(Node **raiz,long int clave);
void rotacion_II(Node **node, Node *n1);
void rotacion_DD(Node **node, Node *n1);
void rotacion_ID(Node **node, Node *n1);
void rotacion_DI(Node **node, Node *n1);
void imprimir(Node **raiz,clock_t inicio, long int *datos, FILE *grafica2);
void graficar(Node **raiz);

/*********************************METODO MAIN DE LA PRACTICA************************************/
int main(){
    menu();
    return 0;
}
