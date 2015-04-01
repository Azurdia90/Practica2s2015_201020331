#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nodo_arbol.h" //importando el nodo del arbol
#include "Arbol_AVL.h" //importando los metodos del arbol
#include "Lista_simple.h"
/*********************************PROTOTIPOS DEL ARBOL AVL*****************************************/
void insertar(Node **raiz, int clave, int *h);
void rotacion_II(Node **node, Node *n1);
void rotacion_DD(Node **node, Node *n1);
void rotacion_ID(Node **node, Node *n1);
void rotacion_DI(Node **node, Node *n1);
void imprimir(Node **raiz,int graf);
void graficar(Node **raiz);
/***************************PROTOTIPOS DE LA LISTE SIMPLE******************************************/
void insertar_lista(Root_list Raiz, int clave);
/***********************VARIABLES GLOBLALES********************************************************/
int h=0;
char *path;
Node *root;
Root_list root_list;
FILE *archivo_entrada;
/*************************METODOS DEL MENU*********************************************/
void menu(){
    printf("\n BIENVENIDOS \n");
    printf("\n\n\n");
    printf("Ingrese una direccion: \n \n");
    path = (char *)malloc(128 *sizeof(char));
    scanf("%s", path);
    leer_archivo();
}//fin del metodo menu
void leer_archivo(){//metpdp qie se lee el archivo y se inserta en el arbol AVL
    archivo_entrada = fopen(path,"r");
    if(archivo_entrada != NULL){
        char a[5];
        root = NULL;
        root_list.first =NULL;
            while(!feof(archivo_entrada)){
                fgets(a,5,archivo_entrada);
                int b = atoi(a);
                insertar(&root,b,&h);
                insertar_lista(&root_list,b);
            }
    }else{
        printf("No existe");
    }
    fclose(archivo_entrada);
    resultados();
}//fin del metodo leer archivo

void resultados(){
    imprimir(&root,0);
    imprimir_lista(&root_list);
    graficar(&root);
}
/*********************************METODO MAIN DE LA PRACTICA************************************/
int main(){
    menu();
    return 0;
}
