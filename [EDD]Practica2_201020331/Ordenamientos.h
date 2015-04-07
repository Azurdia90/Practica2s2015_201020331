#ifndef ORDENAMIENTOS_H_INCLUDED
#define ORDENAMIENTOS_H_INCLUDED
#include <time.h>

void ordenar_burbuja(long int *buble, long int n, FILE *grafica3, clock_t inicio){
    long int i,j;
    long int temp;
    int datos = 1;
    for(i = 0; i<(n -1); i++){
        for(j = 0; j < (n-i-1); j++){
            if(buble[j]>buble[j+1]){
                temp = buble[j];
                buble[j] = buble[j+1];
                buble[j+1] = temp;
            }
        }
        clock_t aux_f = clock();
        fprintf(grafica3,"%f %i \n",((aux_f-inicio)/(float)CLOCKS_PER_SEC),datos);
        datos++;
    }
}
void ordenamiento_quick(long int *quicksort, long int primero, long int ultimo,clock_t inicio,long int *datos, FILE *grafica4){
    long int i, j, central;
    long int pivote;

    central = (primero+ultimo)/2;
    pivote = quicksort[central];
    i = primero;
    j = ultimo;

    do{
        while(quicksort[i] < pivote) i++;
        while(quicksort[j] > pivote) j--;

        if(i<=j){
            long int temp;
            temp = quicksort[i];
            quicksort[i] = quicksort[j];
            quicksort[j] = temp;
            i++;
            j--;
        }
    }while(i<=j);
        if(primero<j){
            ordenamiento_quick(quicksort, primero, j, inicio, datos, grafica4);
            clock_t aux_f = clock();
            fprintf(grafica4,"%f %i \n",((aux_f-inicio)/(float)CLOCKS_PER_SEC),*datos);
            (*datos)++;
        }
        if(i<ultimo){
            ordenamiento_quick(quicksort, i, ultimo, inicio, datos, grafica4);
            clock_t aux_f = clock();
            fprintf(grafica4,"%f %i \n",((aux_f-inicio)/(float)CLOCKS_PER_SEC),*datos);
            (*datos)++;
        }

}


#endif // ORDENAMIENTOS_H_INCLUDED
