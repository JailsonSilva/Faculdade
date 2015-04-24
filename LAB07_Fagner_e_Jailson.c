#include <stdio.h>
#include <stdlib.h>

struct lista{

    int aux;
    int* p;
    struct lista* prox;

};

Lista* inicia(void){
    return NULL;
};

Lista* inserir(Lista* l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;

    return novo;
