#ifndef MANEJO_ARCHIVO_H_INCLUDED
#define MANEJO_ARCHIVO_H_INCLUDED
#include <time.h>
#include "Arbol_AVL.h"
#include "Ordenamientos.h"

long int cont=1;
long int datos=1;
char *path;
//raiz del arbol avl
Node *root;
long int *buble;
long int *quick;
//variables para el conteo de tiempo
clock_t inicio_1;//inicio de la inserccion en el arbol
clock_t inicio_2;//inicio del recorrido del arbol
clock_t inicio_3;//inicio del ordenamiento burbuja
clock_t inicio_4;//inicio del ordenamiento quicksort
clock_t fin_1;//fin de la inserccion del arbol
clock_t fin_2;//fin del recorrido del arbol
clock_t fin_3;//fin del ordenamiento burbuja
clock_t fin_4;//fin del ordenamiento quicksort
float total1;//tiempo total de la inserccion en el arbol
float total2;//tiempo total del recorrido del arbol
float total3;//tiempo total del ordenamiento burbuja
float total4;//teimpo total del ordenamiento quickaort
//puntero que maneja el archivo de entrada
FILE *archivo_entrada;
FILE *grafica1;
FILE *grafica2;
FILE *grafica3;
FILE *grafica4;
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
    if(archivo_entrada != NULL ){
        char a[15];
        while(!feof(archivo_entrada)){
        fgets(a,sizeof(a),archivo_entrada);
        cont = cont + 1;
        }
        fclose(archivo_entrada);
        cont = cont -1;
        inicio_1 = clock();
        cargar_datos1();
    }else{
        system("CLS");
        fclose(archivo_entrada);
        menu();
    }
}//fin del metodo leer archivo
void cargar_datos1(){
    archivo_entrada = fopen(path,"r");
    grafica1 = fopen("C:\\Practica2\\inserccion_avl.dat","w");
    char a[25];
    root = NULL;
    while(!feof(archivo_entrada)){
        fgets(a,sizeof(a),archivo_entrada);
        long int b = atoi(a);
        insertar(&root,b);
        clock_t aux_f = clock();
        fprintf(grafica1,"%f %li \n",((aux_f - inicio_1)/(float)CLOCKS_PER_SEC),datos);
        datos++;
    }
    fclose(grafica1);
    fclose(archivo_entrada);
    fin_1 = clock();
    grafica2 = fopen("C:\\Practica2\\recorrido_avl.dat","w");
    printf("\nEl recorrido In Orden del arbol es:\n");
    datos = 1;
    inicio_2 = clock();
    imprimir(&root,inicio_2, &datos,grafica2);
    fin_2 =clock();
    fclose(grafica2);
    int decision;
    printf("\n\nDesea graficar el arbol? (1=si/0=no): \n");
    scanf("%i", &decision);
    if ( decision == 1){
        graficar(&root);
    }
    cargar_datos2();
}
void cargar_datos2(){
    destructor_arbol(&root);
    archivo_entrada = fopen(path,"r");
    buble = (int*)malloc(cont *sizeof(int));
    long int c = 0;
    char a[15];
    while(!feof(archivo_entrada)){
        fgets(a,sizeof(a),archivo_entrada);
        long int b = atoi(a);
        buble[c] = b;
        c++;
    }
    fclose(archivo_entrada);
    grafica3 = fopen("C:\\Practica2\\ordenamiento_bubble.dat","w");
    datos = cont;
    inicio_3 = clock();
    ordenar_burbuja(buble,cont,grafica3,inicio_3);
    fin_3 = clock();
    fclose(grafica3);
    cargar_datos3();
}
void cargar_datos3(){
    free(buble);
    archivo_entrada = fopen(path,"r");
    quick = (int*)malloc(cont*sizeof(int));
    long int c = 0;
    char a[25];
    while(!feof(archivo_entrada)){
        fgets(a,sizeof(a),archivo_entrada);
        long int b = atoi(a);
        quick[c] = b;
        c++;
    }
    fclose(archivo_entrada);
    resultados();
}
void resultados(){
    int long c=0;
    grafica4 = fopen("C:\\Practica2\\ordenamiento_quick.dat","w");
    datos = 1;
    inicio_4 = clock();
    ordenamiento_quick(quick, 0, cont,datos, &datos, grafica4);
    fin_4 = clock();
    fclose(grafica4);
    printf("\nREsultado ordenamiento quicksort es:\n");
    for(c; c<cont; c++){
        printf("%li,",quick[c]);
    }
    free(quick);
    total1 = ((float)(fin_1 - inicio_1)/CLOCKS_PER_SEC);
    total2 = ((float)(fin_2 - inicio_2)/CLOCKS_PER_SEC);
    total3 = ((float)(fin_3 - inicio_3)/CLOCKS_PER_SEC);
    total4 = ((float)(fin_4 - inicio_4)/CLOCKS_PER_SEC);
    printf("\nTiempo de inserccion en el arbol es: %f segundos \n", total1);
    printf("\nTiempo de recorrido del arbol es: %f segundos \n", total2);
    printf("\nTiempo de ordenamiento bubblesort es: %f segundos \n", total3);
    printf("\nTiempo de ordenamiento quicksort es: %f segundos \n", total4);
    system("PAUSE");
}//fin de resultados

#endif // MANEJO_ARCHIVO_H_INCLUDED
