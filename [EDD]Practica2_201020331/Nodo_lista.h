#ifndef NODO_LISTA_H_INCLUDED
#define NODO_LISTA_H_INCLUDED

 typedef struct Nodo_lista{
    int clave;
    int pos;
    int stop;
    struct Nodo_lista *next;
    struct Nodo_lista *bak;
}Node_list;

#endif // NODO_LISTA_H_INCLUDED
