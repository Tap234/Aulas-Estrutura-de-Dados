#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 5;
    int *ponteiro = &var;

    printf("o valor de var e: %d\n", var);
    printf("o valor da memoria de var e: %p\n", &var);
    printf("o valor do ponteiro e: %d\n", *ponteiro);
    printf("O valor do endereco do ponteiro e: %p\n", &ponteiro);
    *ponteiro = 2;
    printf("\n");
    printf("o valor de var e: %d\n", var);
    printf("o valor do ponteiro e: %d\n", *ponteiro);
}