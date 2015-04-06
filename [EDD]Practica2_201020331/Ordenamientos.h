#ifndef ORDENAMIENTOS_H_INCLUDED
#define ORDENAMIENTOS_H_INCLUDED

void ordenar_burbuja(long int buble[], long int n){
    long int i,j;
    long int temp;

    for(i = 0; i<(n -1); i++){
        for(j = 0; j < (n-i-1); j++){
            if(buble[j]>buble[j+1]){
                temp = buble[j];
                buble[j] = buble[j+1];
                buble[j+1] = temp;
            }
        }
    }
}
void ordenamiento_quick(long int quicksort[], long int primero, long int ultimo){
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
            ordenamiento_quick(quicksort, primero, j);
        }
        if(i<ultimo){
            ordenamiento_quick(quicksort, i, ultimo);
        }
}


#endif // ORDENAMIENTOS_H_INCLUDED
