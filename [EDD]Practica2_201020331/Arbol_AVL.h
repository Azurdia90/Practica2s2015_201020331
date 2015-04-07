#ifndef ARBOL_AVL_H_INCLUDED
#define ARBOL_AVL_H_INCLUDED
#include <time.h>
#include "Nodo_arbol.h"
FILE *arbol;
FILE *grafica2;

int altura(Node *n){
    if (n==NULL){
        return -1;
    }else{
        return n->a;
    }
}
void actualizar_altura(Node *n){
    if (n==NULL){
        int x = altura(n->left_son);
        int y = altura(n->right_son);
        if( x > y){
            n->a = x + 1;
        }else if(x>y){
            n->a = y + 1;
        }else{
            n->a = 0;
        }
    }
}

void rotacion_simple(Node **n, int izquierda){
    Node *n1;
    if(izquierda == 1){
        n1 = (*n)->left_son;
        (*n)->left_son = n1->right_son;
        n1->right_son = (*n);
    }else{
        n1 = (*n)->right_son;
        (*n)->right_son = n1->left_son;
        n1->left_son = (*n);
    }
    actualizar_altura(*n);
    actualizar_altura(n1);
    (*n)=n1;
}
void rotacion_doble(Node **n, int izquierda){
    if(izquierda == 1){
        rotacion_simple(&(*n)->left_son, 0);
        rotacion_simple(n,1);
    }else{
        rotacion_simple(&(*n)->right_son, 1);
        rotacion_simple(n, 0);
    }
}
void balancear(Node **n){
    if((*n)){
        if(altura((*n)->left_son)-altura((*n)->right_son) == 2){
            if(altura((*n)->left_son->left_son)>=altura((*n)->left_son->right_son)){
                rotacion_simple(n,1);
            }else{
                rotacion_simple(n,1);
            }
        }else if(altura((*n)->right_son)-altura((*n)->left_son) ==2){
            if(altura((*n)->right_son->right_son)>=altura((*n)->right_son->left_son)){
                    rotacion_simple(n,0);
               }else{
                   rotacion_simple(n,0);
               }
        }
    }
}
void insertar(Node **raiz, long int clave){
    if(!(*raiz)){
        Node *nuevo;
        nuevo = (Node*)malloc(sizeof(Node));
        if(nuevo != NULL){//si es posible reservar memoria
            nuevo->iden = clave;
            nuevo->a =0;
            nuevo->left_son = NULL;
            nuevo->right_son = NULL;
            *raiz = nuevo;
        }else{
            printf("NO PUDO SER RESERVADA LA MEMORIA");
        }
    }else{
        if((*raiz)->iden > clave){
            insertar(&(*raiz)->left_son,clave);
        }else if((*raiz)->iden<clave){
            insertar(&(*raiz)->right_son,clave);
        }
       balancear(raiz);
       actualizar_altura((*raiz));
    }//fin de la verficacion de la clave entrante
}//fin del metodo de inserccion

void imprimir(Node **raiz,clock_t inicio, long int *datos, FILE *grafica2){
    if((*raiz)){//si la raiz tiene contenido
        imprimir(&(*raiz)->left_son,inicio, datos, grafica2);
        printf("%li,",(*raiz)->iden);//se coloca en comillas que se imprimira un enteroo
        clock_t aux_f =clock();
        fprintf(grafica2,"%f %li \n",((aux_f - inicio)/(float)CLOCKS_PER_SEC),*datos);
        (*datos)++;
        imprimir(&(*raiz)->right_son,inicio, datos, grafica2);
    }//fin del if
}//fin del metodo imprimir

void destructor_arbol(Node **raiz){
    if((*raiz)){
        destructor_arbol(&(*raiz)->left_son);
        destructor_arbol(&(*raiz)->right_son);
        free((*raiz));
    }
}
void graficar(Node **raiz){
    arbol = fopen("C:\\Practica2\\grafica.dot","w");
    if(arbol!=NULL){
        fprintf(arbol,"digraph Arbol {\n");
        graficar2(&(*raiz));
        fprintf(arbol,"}");
        fclose(arbol);
        system("%GRAFICAR% -Tjpg C:\\Practica2\\grafica.dot -o C:\\Practica2\\grafica.jpg");
    }
}//fin del metodo graficar
void graficar2(Node **raiz){
    graficar2(&(*raiz)->left_son);
    fprintf(arbol,"nodo%li[shape=ellipse,label=\"nodo %li\"];\n", (*raiz)->iden, (*raiz)->iden);
    if((*raiz)->left_son != NULL){//si el subarbol izquierdo no esta vacio
        fprintf(arbol,"nodo%li->nodo%li;\n",(*raiz)->iden,(*raiz)->left_son->iden);
    }//fin de la comprobacion
    if((*raiz)->right_son != NULL){//si el subarbol derecho no esta vacio
        fprintf(arbol,"nodo%li->nodo%li;\n",(*raiz)->iden,(*raiz)->right_son->iden);
    }//fin de la comprobacion
    graficar2(&(*raiz)->right_son);
}
#endif // ARBOL_AVL_H_INCLUDED
