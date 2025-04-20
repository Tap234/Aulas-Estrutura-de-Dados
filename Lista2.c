#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserirInicio(No **lista, int numero){
    No *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = numero;
        novo->proximo = *lista;
        *lista = novo;
    }else
        printf("Erro ao alocar memoria\n");
}

void inserirFinal(No **lista, int numero){
    No *aux, *novo = malloc(sizeof(No));
    if (novo){
        novo->valor =  numero;
        novo->proximo = NULL;
        if (*lista == NULL){
            *lista = novo;
        } else{
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
    else 
        printf("Erro ao alocar memoria\n");
}

int main(){

}