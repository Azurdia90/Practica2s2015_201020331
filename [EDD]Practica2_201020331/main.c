#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nodo_arbol.h" //importando el nodo del arbol
#include "Arbol_AVL.h" //importando los metodos del arbol
/*********************************PROTOTIPOS DEL ARBOL AVL*****************************************/
void insertar(Node **raiz, int clave, int *h);
void rotacion_II(Node **node, Node *n1);
void rotacion_DD(Node **node, Node *n1);
void rotacion_ID(Node **node, Node *n1);
void rotacion_DI(Node **node, Node *n1);
void imprimir(Node **raiz,int graf);
void graficar(Node **raiz);
/***********************VARIABLES GLOBLALES*********************************************/
char *path;
Node *root;
FILE *archivo_entrada;
/*************************METODOS DEL MENU*********************************************/
void menu(){
    printf("\n BIENVENIDOS \n");
    printf("\n\n\n");
    printf("Ingrese una direccion: \n");
    path = (char *)malloc(128 *sizeof(char));
    scanf("%s", path);
    //leer_archivo();
}//fin del metodo menu
void leer_archivo(){
    archivo_entrada = fopen(path,"r");
    char *aux;
    int cont=0;
    while(!feof(archivo_entrada)){
        //fscanf(archivo_entrada,"%s \n", aux[cont]);
        cont++;
        printf("%s", aux);
    }
}//fin del metodo leer archivo

/*********************************METODO MAIN DE LA PRACTICA************************************/
int main(){
    int var1 = 100;
    int var2 = 15;
    int var3 = 56;
    int var4 = 9;
    int h = 0;
    Node *root = NULL;
    insertar(&root, var1, &h);
    insertar(&root, var2, &h);
    insertar(&root, var3, &h);
    insertar(&root, var4, &h);
    imprimir(&root, 0);
    graficar(&root);
    return 0;
}
