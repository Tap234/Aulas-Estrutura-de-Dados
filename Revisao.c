#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void criarListaCircular(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

void inserirInicio(Lista *lista, int num) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        if (lista->inicio == NULL) {
            lista->inicio = novo;
            lista->fim = novo;
            novo->proximo = novo;
        } else {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
            lista->fim->proximo = lista->inicio;
        }
        lista->tamanho++;
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void inserirFim(Lista *lista, int num) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        if (lista->inicio == NULL) {
            lista->inicio = novo;
            lista->fim = novo;
            novo->proximo = novo;
        } else {
            lista->fim->proximo = novo;
            lista->fim = novo;
            novo->proximo = lista->inicio;
        }
        lista->tamanho++;
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void inserirOrdenado(Lista *lista, int num) {
    No *aux, *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;

        if (lista->inicio == NULL) { // lista vazia
            novo->proximo = novo;
            lista->inicio = novo;
            lista->fim = novo;
        } else if (num < lista->inicio->valor) { // inserir no início
            novo->proximo = lista->inicio;
            lista->fim->proximo = novo;
            lista->inicio = novo;
        } else {
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && aux->proximo->valor < num) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;

            if (aux == lista->fim) {
                lista->fim = novo;
            }
        }

        lista->tamanho++;
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

No *remover(Lista *lista, int num) {
    No *aux, *rem = NULL;
    if (lista->inicio) {
        if (lista->inicio == lista->fim && lista->inicio->valor == num) {
            rem = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tamanho--;
        } else if (lista->inicio->valor == num) {
            rem = lista->inicio;
            lista->inicio = rem->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tamanho--;
        } else {
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && aux->proximo->valor != num) {
                aux = aux->proximo;
            }
            if (aux->proximo->valor == num) {
                rem = aux->proximo;
                aux->proximo = rem->proximo;

                if (rem == lista->fim) {
                    lista->fim = aux;
                }

                lista->tamanho--;
            }
        }
    }
    return rem;
}

No *buscar(Lista *lista, int num) {
    No *aux = lista->inicio;
    if (aux) {
        do {
            if (aux->valor == num) {
                return aux;
            }
            aux = aux->proximo;
        } while (aux != lista->inicio);
    }
    return NULL;
}

void imprimir(Lista lista) {
    No *no = lista.inicio;
    printf("\n\tLista tamanho: %d\n\t", lista.tamanho);
    if (no) {
        do {
            printf("%d ", no->valor);
            no = no->proximo;
        } while (no != lista.inicio);
        printf("\nInicio: %d\n", lista.inicio->valor);
    }
    printf("\n");
}

int main() {
    int op, valor;
    Lista lista;
    No *removido, *pesquisando;
    criarListaCircular(&lista);

    do {
        printf("\n0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t3 - Inserir ordenando\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Buscar\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFim(&lista, valor);
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirOrdenado(&lista, valor);
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removido = remover(&lista, valor);
                if (removido) {
                    printf("Valor %d removido com sucesso!\n", removido->valor);
                    free(removido);
                } else {
                    printf("Valor nao encontrado!\n");
                }
                break;
            case 5:
                imprimir(lista);
                break;
            case 6:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                pesquisando = buscar(&lista, valor);
                if (pesquisando) {
                    printf("Valor %d encontrado!\n", pesquisando->valor);
                } else {
                    printf("Valor nao encontrado!\n");
                }
                break;
            default:
                if (op < 0 || op > 6) {
                    printf("Opcao invalida!\n");
                }
        }
    } while (op != 0);
    
    return 0;
}
