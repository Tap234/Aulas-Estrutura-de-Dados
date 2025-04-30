#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int conteudoNO;
    struct no *esquerda, *direita;
} No;

typedef struct {
    No *raiz;
} ArvoreBinaria;

void inserirEsquerda(No *no, int valor){
    if(no->esquerda == NULL){
        No *novoNO = (No*)malloc(sizeof(No));
        novoNO->conteudoNO = valor;
        novoNO->esquerda = NULL;
        novoNO->direita = NULL;
        no->esquerda = novoNO;
    }else{
        if(valor < no->esquerda->conteudoNO)
            inserirEsquerda(no->esquerda, valor);
        if(valor > no->esquerda->conteudoNO)
            inserirDireita(no->esquerda, valor);
    }
}

void inserirDireita(No *no, int valor){
    if(no->direita == NULL){
        No *novoNO = (No*)malloc(sizeof(No));
        novoNO->conteudoNO = valor;
        novoNO->esquerda = NULL;
        novoNO->direita = NULL;
        no->direita = novoNO;
    }else{
        if(valor > no->direita->conteudoNO)
            inserirDireita(no->direita, valor);
        if(valor < no->direita->conteudoNO)
            inserirEsquerda(no->direita, valor);
    }
}

void inserirno(ArvoreBinaria *arvorebinaria, int valor){
    if(arvorebinaria-> raiz == NULL){
        No *novoNO = malloc(sizeof(No));
        novoNO->conteudoNO = valor;
        novoNO->esquerda = NULL;
        novoNO->direita = NULL;
        arvorebinaria->raiz = novoNO;
    }else{
        if(valor < arvorebinaria->raiz->conteudoNO)
            inserirEsquerda(arvorebinaria->raiz, valor);
        if (valor > arvorebinaria->raiz->conteudoNO)
            inserirDireita(arvorebinaria->raiz, valor);
        
    }
}

void imprimir(No *raiz){
    if(raiz !=NULL){
        imprimir(raiz-> esquerda);
        printf("%d", raiz->conteudoNO);
        imprimir(raiz-> direita);
    }
}

int main(){
    int op, valor;
    ArvoreBinaria arvorebinaria;
    arvorebinaria.raiz = NULL;
    do{
        printf("\n0 - Sair \n1 - Inserir\n2 - Imprimir \nEscolha uma opcao: ");
        scanf("%d", &op);
        switch(op){
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirno(&arvorebinaria, valor);
                break;
            case 2:
                imprimir(arvorebinaria.raiz);
                printf(" \n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(op != 0);
}