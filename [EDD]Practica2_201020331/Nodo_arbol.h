#ifndef NODO_ARBOL_H_INCLUDED
#define NODO_ARBOL_H_INCLUDED

typedef struct node{
    long int iden;
    int a;
    struct node *left_son;
    struct node *right_son;
}Node;


#endif // NODO_ARBOL_H_INCLUDED
