#include <stdio.h>
#include <stdlib.h>

int calcular(int *calcular){
    printf("Digite o valor a ser multiplicado por 2: ");
    scanf("%d", calcular);
    printf("O valor multiplicado por 2 e: %d\n", *calcular * 2);

    return 0;
}

int apresentar(int *variavel){
    printf("Digite o valor da variavel: ");
    scanf("%d", variavel);
    printf("Valor: %d\n", *variavel);

    return 0;
}

int main() {
    int *a;
    a = (int*) malloc(sizeof(int));
    printf("Digite um valor: ");
    scanf("%d",a);
    printf("Valor: %d",*a);
    free(a);

    printf("\n-----------------------------------\n");

    double *b;
    b = (double*) malloc(sizeof(double));
    printf("Digite um valor double: ");
    scanf("%lf", b);
    printf("O valor e: %lf", *b);
    free(b);

    printf("\n-----------------------------------\n");

    char *c;
    c = (char*) malloc (sizeof(char));
    printf("Digite um valor char: ");
    scanf(" %c",c);
    printf("O valor e: %c", *c);
    free(c);

    printf("\n-----------------------------------\n");

    int *d;
    d = (int*)malloc (sizeof(int));
    apresentar(d);
    free(d);

    printf("\n-----------------------------------\n");

    int *e;
    e = (int*)malloc (sizeof(int));
    apresentar(e);
    free(e);

    printf("\n-----------------------------------\n");

    int *f;
    f = (int*)malloc (sizeof(int));
    calcular(f);
    return 0;
   }
   