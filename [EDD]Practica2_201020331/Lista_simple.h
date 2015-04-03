#ifndef LISTA_SIMPLE_H_INCLUDED
#define LISTA_SIMPLE_H_INCLUDED

#include "Nodo_lista.h"
/************************************METODOS DE LA LISTA SIMPLE ENLAZADA***********************************************************/
void insertar_lista(Node_list **first, Node_list **last, int clave, int pos){
    Node_list *nuevo = (Node_list*)malloc(sizeof(Node_list));
    nuevo->clave = clave;
    nuevo->pos = pos;
    nuevo->stop = 0;
    nuevo->next = NULL;
    nuevo->bak = NULL;
    if((*first)){//si la lista no esta vacia
        nuevo->bak = (*last); //el nuevo apunta al ultimo
        (*last)->next = nuevo; //el ultimo apunta al nuevo
        (*last) = nuevo; //el nuevo pasa a ser el ultimo
    }else{//de lo contrario si esta vacia
        (*first) = nuevo; //el nuevo sera primero
        (*last)= nuevo;  //el nuevo sera ultimo
    }//fin de la comprobacon si la lista esta vacia
}//fin del metodo insertar de  la lista
void imprimir_lista(Node_list **first){
    if((*first)){//si la lista no esta vacia
        Node_list *aux = (*first);//nodo para recorrer la lista
        printf("valores de la raiz:\n");
        while(aux != NULL){//mientras el nodo no este vacio
            printf("%i\n",aux->clave);
            aux = aux->next;
        }//fin del recorrido de la lista
    }//fin de la comprobacion si a lista no esta vacia
}//fin del mentodo imprimir lista
Node_list* buscar_lista_izquierda(Node_list **first, int pos){
    Node_list *aux = NULL;
    if((*first)){//si la lista no esta vacia
        Node_list *aux2 = (*first);//nos colocamos al inicio de la lista
        while(aux2!=NULL){//reocorremos la lista
            if(aux2->pos != pos){
                aux2 = aux2->next;//pasamos al siguiente nodo
            }else{
                aux = aux2;
                break;
            }
        }//fin del recorrido de la lista
    }//fin de la comprobaion si la lista esta vacia
    return aux;
}//fin del metodo buscar en la lista
Node_list* buscar_lista_derecha(Node_list **last, int pos){
    Node_list *aux = NULL;
    if((*last)){//si la lista no esta vacia
        Node_list *aux2 = (*last);//nos colocamos al inicio de la lista
        while(aux2!=NULL){//reocorremos la lista
            if(aux2->pos != pos){
                aux2 = aux2->bak;//pasamos al siguiente nodo
            }else{
                aux = aux2;
                break;
            }
        }//fin del recorrido de la lista
    }//fin de la comprobaion si la lista esta vacia
    return aux;
}//fin del metodo buscar en la lista
/***********************************************ORDENAMIENTO BURBUJA**************************************************************/
void ordenar_burbuja(Node_list **first){
    if((*first)->stop == 0 && (*first)){//comprobamos que no este vacia la lista o todos esten tachados
        Node_list *aux = (*first);//creamos un ndoo auxiliar para recorrer la lista
        while(aux != NULL ){//si el siguiente es vacio
        if(aux->stop != 1){//si ya esta tachado el nodo cortamos el recorrido
            if(aux->next != NULL){//si el siguiente valor no es nulo
                if((aux->clave)>(aux->next->clave)){//si el primer valor es mayor que el segundo
                    int a = aux->clave;
                    int b = aux->next->clave;
                    aux->clave = b;
                    aux->next->clave = a;
                }//fin de la comprobacion del intercambio
            }//realizamos el cambio de datos
            //actualizamos el factor de cambio
            if(aux->next == NULL && aux->stop == 0){
                aux->stop = 1;
            }else if(aux->next->stop == 1){
                aux->stop = 1;
            }//se termina de actualizar el factor de cambio
                aux = aux->next;//pasamos al siguiente valor
            }else{//si el valor esta tachado
            break; //terminamos el ciclo
            }//fin de la comprobacion si esta tachado
        }//fin del recorrido de la lista
        ordenar_burbuja(&(*first));//volvemos a iterar hasta que toos esten tachados
    }//FIN de la comprobacion si esta vacia o todos bloqueados
}//fin del metodo del ordenamiento burbuja
/*************************************************ORDENAMIENTO QUICKSORT**************************/
void ordenamiento_quicksort(Node_list **first, Node_list **last,int primero, int ultimo){
    int primas, ultimas, centro;
    int pivote; //guardara el valor del centro de la lista o sublista

    centro = (primero+ultimo)/2;
    pivote = buscar_lista_izquierda(&(*first), centro)->clave;
    primas = primero;
    ultimas = ultimo;

    do{
        while(buscar_lista_izquierda(&(*first),primas)->clave < pivote && primas < ultimo) primas++;//recorriendo de izquierda a derecha
        while(buscar_lista_derecha(&(*last),ultimas)->clave > pivote && ultimas > primero) ultimas--;//recorriendo de derecha a izquierda
        if(primas<=ultimas){//si los elementos se cruzan intercambiar
            int temp;
            temp = buscar_lista_izquierda(&(*first),primas)->clave;
            buscar_lista_izquierda(&(*first),primas)->clave = buscar_lista_derecha(&(*last),ultimas)->clave;
            buscar_lista_derecha(&(*last),ultimas)->clave = temp;
            primas++;
            ultimas--;
        }//fin del if
    }while(primas <= ultimas);//fin del do while
    if(primero < ultimas){//si quedaron aun elementos que ordenar por la izquierda
        ordenamiento_quicksort(&(*first),&(*last),primero,ultimas);
    }//fin del if(primero < ultimas)
    if(primas < ultimo){//si quedaron aun elementos que ordenar por la derecha
        ordenamiento_quicksort(&(*first),&(*last),primas,ultimo);
    }//fin del if(primas < ultimo)
}//fin del metodo quisort

#endif // LISTA_SIMPLE_H_INCLUDED
