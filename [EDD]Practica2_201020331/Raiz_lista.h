#ifndef RAIZ_LISTA_H_INCLUDED
#define RAIZ_LISTA_H_INCLUDED

#include "Nodo_lista.h"

typedef struct Raiz_lista{
    struct Nodo_lista *first;
    struct Nodo_lista *last;
}Root_list;

#endif // RAIZ_LISTA_H_INCLUDED
