#ifndef ARBOL_AVL_H_INCLUDED
#define ARBOL_AVL_H_INCLUDED

#include "Nodo_arbol.h"
FILE *arbol;

void insertar(Node **raiz, int clave, int *h){
    Node *n1;
    Node *nuevo;
    if(!(*raiz)){
        nuevo = (Node*)malloc(sizeof(Node));
        nuevo->iden = clave;
        *raiz = nuevo;
        (*raiz)->left_son = NULL;
        (*raiz)->right_son = NULL;
        *h = 1;
    }else if(clave < (*raiz)->iden){/*********SI LA CLAVE ES MENOR QUE LA RAIZ VAMOS POR LA IZQUIERDA**********/
        insertar(&(*raiz)->left_son, clave, h);
        //cuando regrese verificamos el factor de equilibrio
        if(*h){//reducimos el factor de equilibrio
            switch((*raiz)->fe){
                case 1:
                    (*raiz)->fe = 0;
                    (*h)=0;
                break;
                case 0:
                    (*raiz)->fe = -1;
                    break;
                case -1:
                    n1 = (*raiz)->left_son;
                    if(n1->fe == -1){
                        rotacion_II(raiz,n1);
                    }else{
                        rotacion_ID(raiz,n1);
                    }
                    (*h) = 0;
                    break;
            }//fin del switch
        }//fin de la comprobacion si h no cambio
    }else if(clave > (*raiz)->iden){ /********SI LA CLAVE ES MAYOR QUE LA RAIZ VAMOS POR LA DERECHA*********/
        insertar(&(*raiz)->right_son, clave, h);
        if(*h){//verificamos que haya un cambio en la altura
            switch((*raiz)->fe){//aumentamos el factor de equilibrio
                case 1:
                    n1 = (*raiz)->right_son;
                    if(n1->fe == 1){
                        rotacion_DD(raiz, n1);
                    }else{
                        rotacion_DI(raiz, n1);
                    }
                    (*h) = 0;
                    break;
                case 0:
                    (*raiz)->fe = 1;
                    break;
                case -1:
                    (*raiz)->fe = 0;
                    (*h) = 0;
                    break;
            }//fin del switch
        }//fin de la comprobacion de h
    }else{
        printf("clave repetida");
        (*h)=0;
    }//fin de la verficacion de la clave entrante
}//fin del metodo de inserccion
void rotacion_II(Node **node, Node *n1){
    (*node)->left_son = n1->right_son;
    n1->right_son = (node);

    if(n1->fe == -1){
        (*node)->fe = 0;
        n1->fe = 0;
    }else{
        (*node)->fe=-1;
        n1->fe = 1;
    }
    (*node) = n1;
}//fin de la roatcion izquierda izquierda
void rotacion_DD(Node **node, Node *n1){
    (*node)->right_son = n1->left_son;
    n1->left_son = (*node);
    if(n1->fe == +1){
        (*node)->fe=0;
        n1->fe=0;
    }else{
        (*node)->fe=+1;
        n1->fe=-1;
    }
    (*node) = n1;
}
void rotacion_ID(Node **node, Node *n1){
    Node *n2;

    n2 = n1->right_son;
    (*node)->left_son = n2->right_son;
    n2->right_son = *node;
    n1->right_son = n2->left_son;
    n2->left_son = n1;
    //se empieza a actualizar los factores de equilibrio
    if (n2->fe == +1){
        n1->fe = -1;
    }else{
        n1->fe=0;
    }
    if(n2->fe == -1){
        (*node)->fe = 1;
    }else{
        n1->fe = 0;
    }
    n2->fe = 0;
    (*node)=n2;
}
void rotacion_DI(Node **node, Node *n1){
    Node *n2;
    n2 = n1->left_son;
    (*node)->right_son = n2->left_son;
    n2->left_son = *node;
    n1->left_son = n2->right_son;
    n2->right_son = n1;
    //actualizando los factores de equilibrio;
    if(n2->fe == 1){
        (*node)->fe =-1;
    }else{
        (*node)->fe = 0;
    }
    if(n2->fe == -1){
        n1->fe = 1;
    }else{
        n1->fe = 0;
    }
    n2->fe = 0;
    (*node) = n2;
}//fin de la rotacion derecha izquierda
void imprimir(Node **raiz,int graf){
    if((*raiz)){//si la raiz tiene contenido
        imprimir(&(*raiz)->left_son,graf);
        if(graf !=1){//si el parametro es 0 solo imprime en consola
            printf("%i\n",(*raiz)->iden);//se coloca en comillas que se imprimira un entero
        }else{              //luego de eso se coloca como parametro el entero que se enviara
            fprintf(arbol,"nodo%i[shape=ellipse,label=\"nodo %i\"];\n", (*raiz)->iden, (*raiz)->iden);
            if((*raiz)->left_son != NULL){//si el subarbol izquierdo no esta vacio
                fprintf(arbol,"nodo%i->nodo%i;\n",(*raiz)->iden,(*raiz)->left_son->iden);
            }//fin de la comprobacion
            if((*raiz)->right_son != NULL){//si el subarbol derecho no esta vacio
                //fprintf(arbol,"nodo%i->nodo%i;\n",(*raiz)->iden,(*raiz)->right_son->iden);
            }//fin de la comprobacion
        }//si el valor era 1 se tuvo que imprimir en el archivo
        imprimir(&(*raiz)->right_son,graf);
    }//fin del if
}//fin del metodo imprimir

void graficar(Node **raiz){
    arbol = fopen("C:\\Practica2\\grafica.dot","w");
    if(arbol!=NULL){
        fprintf(arbol,"digraph Arbol {\n");
        imprimir(&(*raiz),1);
        fprintf(arbol,"}");
        fclose(arbol);
        system("%GRAFICAR% -Tjpg C:\\Practica2\\grafica.dot -o C:\\Practica2\\grafica.jpg");
    }
}//fin del metodo graficar

#endif // ARBOL_AVL_H_INCLUDED
