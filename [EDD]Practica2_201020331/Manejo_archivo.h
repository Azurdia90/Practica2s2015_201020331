#ifndef MANEJO_ARCHIVO_H_INCLUDED
#define MANEJO_ARCHIVO_H_INCLUDED
#include <time.h>
#include "Arbol_AVL.h"
#include "Lista_simple.h"

int h=0;
long int cont=0;
char *path;
Node *root;
clock_t inicio_1;
clock_t inicio_2;
clock_t inicio_3;
clock_t fin_1;
clock_t fin_2;
clock_t fin_3;
double total1;
double total2;
double total3;
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
        cargar_datos1();
    }else{
        system("CLS");
        fclose(archivo_entrada);
        menu();
    }
}//fin del metodo leer archivo
void cargar_datos1(){
    char a[2000];
    root = NULL;
    inicio_1 = clock();
    while(!feof(archivo_entrada)){
        fgets(a,2000,archivo_entrada);
        long int b = atoi(a);
        insertar(&root,b,&h);
    }
    fclose(archivo_entrada);
    fin_1 = clock();
    total1 = ((double)fin_1 - inicio_1)/CLOCKS_PER_SEC;
    cargar_datos2();
}
void cargar_datos2(){
    archivo_entrada = fopen(path,"r");
    cont = 0;
    char a[15];
    first_buble = NULL;
    last_buble = NULL;
    inicio_2 = clock();
    while(!feof(archivo_entrada)){
        fgets(a,15,archivo_entrada);
        long int b = atoi(a);
        insertar_lista(&first_buble,&last_buble,b,cont);
        cont = cont + 1;
    }
    fclose(archivo_entrada);
    fin_2 = clock();
    total2 = ((double)fin_2 - inicio_2)/CLOCKS_PER_SEC;
    cargar_datos3();
}
void cargar_datos3(){
    archivo_entrada = fopen(path,"r");
    char a[15];
    first_quick = NULL;
    last_quick = NULL;
    inicio_3 = clock();
    while(!feof(archivo_entrada)){
        fgets(a,15,archivo_entrada);
        long int b = atoi(a);
        insertar_lista(&first_quick,&last_quick,b,cont);
        cont = cont + 1;
    }
    fclose(archivo_entrada);
    fin_3 = clock();
    total3 = ((double)fin_3 - inicio_3)/CLOCKS_PER_SEC;
    resultados();
}
void resultados(){
    printf("\nEl recorrido In Orden es:\n");
    imprimir(&root,0);

    ordenar_burbuja(&first_buble);
    ordenamiento_quicksort(&first_quick,&last_quick, first_quick->pos,last_quick->pos);
    printf("\nREsultado ordenamiento burbuja es:\n");
    imprimir_lista(&first_buble);
    printf("\nREsultado ordenamiento quicksort es:\n");
    imprimir_lista(&first_quick);
    //graficar(&root);
    system("PAUSE");
}//fin de resultados

#endif // MANEJO_ARCHIVO_H_INCLUDED
