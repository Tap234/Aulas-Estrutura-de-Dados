#include<stdio.h>
#include<stdlib.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

void inserirInicio(No **lista, int num){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
  }else{
    printf("Erro ao alocar memoria\n");
  }
}

void inserirFinal(No **lista, int num){
  No *aux, *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    if(*lista == NULL){
      novo->proximo = NULL;
      *lista = novo;
    }else{
      aux = *lista;
      while(aux->proximo){
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
  }else{
    printf("Erro ao alocar memoria\n");
  }
}

void inserirMeio(No **lista, int num, int posicao){
  No *aux, *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    if(*lista == NULL){
      novo->proximo = NULL;
      *lista = novo;
    }else{
      aux = *lista;
      while(aux->valor != posicao && aux->proximo){
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
  }else{
    printf("Erro ao alocar memoria\n");
  }
}

No* remover(No **lista, int num){
    No *aux, *remove = NULL;
    if (*lista){
        if((*lista)->valor == num){
            remove = *lista;
            *lista = remove->proximo;
        }else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remove = aux->proximo;
                aux->proximo = remove->proximo;
            }
        }
    }
return remove;
}

void imprimir(No *no){
  printf("\n\tLista: ");
  while(no){
    printf("%d ", no ->valor);
    no = no->proximo;
  }
  printf("\n\n");
}

int main(){
  No *rem, *lista = NULL;
  int op, valor, pos;
  do{
    printf("\n\t0 - Sair\n\t1 - InserirInicio\n\t2 - Imprimir\n\t3 - InserirFinal\n\t4 - InserirMeio\n\t");

    scanf("%d", &op);
    switch(op){
      case 1:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserirInicio(&lista, valor);
        break;
      case 2:
        imprimir(lista);
        break;
      case 3:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserirFinal(&lista, valor);
        break;
      case 4:
        printf("Digite um valor e a Posicao onde Inserir: ");
        scanf("%d%d", &valor, &pos);
        inserirMeio(&lista, valor, pos);
        break;
        case 5:
        printf("Digite um valor e a Posicao onde Inserir: ");
        scanf("%d", &valor);
        rem = remover(&lista, valor);
        if(rem){
            printf("Elemento a ser removido: %d\n", rem->valor);
            free(rem);
        }else{
                printf("Elemento inexistente");
                break;
            }
      default:
        if(op < 0 || op > 2){
          printf("Opcao invalida\n");
        }
    }
  }while(op != 0);
  return 0;
}
