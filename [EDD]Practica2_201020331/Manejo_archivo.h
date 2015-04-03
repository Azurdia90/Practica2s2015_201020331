#ifndef MANEJO_ARCHIVO_H_INCLUDED
#define MANEJO_ARCHIVO_H_INCLUDED

#include "Arbol_AVL.h"
#include "Lista_simple.h"

int h=0;
int cont=0;
char *path;
Node *root;
//raiz que maneja la lista de ordenamiento burbuja
Node_list *first_buble;
Node_list *last_buble;
//raiz que menja la lista de ordenamiento quicksort
Node_list *first_quick;
Node_list *last_quick;
//puntero que maneja el archivo de entrada
FILE *archivo_entrada;

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
        cargar_datos();
    }else{
        system("CLS");
        fclose(archivo_entrada);
        menu();
    }
}//fin del metodo leer archivo

void cargar_datos(){
    char a[5];
    root = NULL;
    first_buble = NULL;
    last_buble = NULL;
    while(!feof(archivo_entrada)){
        fgets(a,5,archivo_entrada);
        int b = atoi(a);
        insertar(&root,b,&h);
        insertar_lista(&first_buble,&last_buble,b,cont);
        insertar_lista(&first_quick,&last_quick,b,cont);
        cont = cont + 1;
    }
    fclose(archivo_entrada);
    resultados();
}

void resultados(){
    imprimir(&root,0);
    ordenar_burbuja(&first_buble);
    ordenamiento_quicksort(&first_quick,&last_quick, first_quick->pos,last_quick->pos);
    imprimir_lista(&first_buble);
    imprimir_lista(&first_quick);
    graficar(&root);
}//fin de resultados

#endif // MANEJO_ARCHIVO_H_INCLUDED
