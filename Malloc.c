#include <stdio.h>
#include <stdlib.h>

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

    return 0;
   }
   