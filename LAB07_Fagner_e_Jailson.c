#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
}; //fim lista
typedef struct lista Lista;

/* Compara elementos de uma lista
   e retorna o ponteiro referente
   ao elemento menor que novo elemento
   e cujo o próximo elemento é maior que o
   novo
*/
Lista* compare(Lista* inicio, int info){
    Lista* p = inicio;

    if(p != NULL){
        while(p->prox != NULL){
            if(p->info <= info && p->prox->info >= info) //verifica se p está entre dois números
                break;
            p = p->prox;
        } //fim while
    } //fim if
    return p; //retorna o ponteiro anterior
} //fim compare

Lista* inicializa(void){
    return NULL;
} //fim lista inicializa

Lista* inserir(Lista* inicio, int info){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    Lista* p = inicio;
    novo->info = info;

    if(p == NULL){ //Lista vazia
        inicio = novo;
        novo->prox = NULL;
    }else{
        if(p->info >= info){ //Novo elemento é menor que o primeiro elemento da lista
            novo->prox = p;
            inicio = novo;
        }else{
            p = compare(inicio, info);
            novo->prox = p->prox;
            p->prox = novo;
        } //fim else interno
    } //fim else externo

    return inicio;
} //fim inserir

/*
Exibi os elementos da lista
*/
void exibir(Lista* inicio){
    Lista* p = inicio;
    while(p->prox != NULL){
        printf("%d, ", p->info);
        p = p->prox;
    } //fim while
} //fim exibir

int main(){
    Lista* l = inicializa();
    int n, i;
    for(i = 1; i <= 10; i++){
        printf("Digite o %d numero: ", i);
        scanf("%d", &n);
        l = inserir(l, n);
    }

    exibir(l);

    return 0;
} //fim main
