#ifndef LISTA_SIMPLE_H_INCLUDED
#define LISTA_SIMPLE_H_INCLUDED

#include "Nodo_lista.h"
#include "Raiz_lista.h"

void insertar_lista(Root_list raiz, int clave){
    Node_list *nuevo = (Node_list*)malloc(sizeof(Node_list));
    nuevo->clave = clave;
    nuevo->stop = 0;
    nuevo->next = NULL;
    nuevo->bak = NULL;
    if(raiz.first != NULL){
        nuevo->bak = raiz.last;
        raiz.last->next = nuevo;
        raiz.last = nuevo;
    }else{
        raiz.first = nuevo;
        raiz.last = nuevo;
    }
}//fin del metodo insertar de  la lista

void imprimir_lista(Root_list **raiz){
    Node_list *aux = NULL;
    if(*raiz){
        aux = (*raiz)->first;
        printf("valores de la raiz:\n");
        while(aux!=NULL){
            printf("%i\n",aux->clave);
            aux = aux->next;
        }//fin del recorrico
    }//fin de la verificacion si la raiz esta vacia
}//fin del recorrido de la lista

#endif // LISTA_SIMPLE_H_INCLUDED
