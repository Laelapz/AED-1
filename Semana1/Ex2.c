#include <stdio.h>
#include <stdlib.h>

//As funções de malloc calloc e realloc ainda não estão gravadas na minha mente
//Entendo o conceito mas a sintaxe as vezes me foge a mente
//Também acho que em usos mais avançados eu engasgo um pouco

int main(){
    int* p = malloc(sizeof(int)*5);
    int num;

    for(int i = 0; i < 5; i++){
        printf("Digite o valor a ser inserido na posicao: %d\n", i);
        scanf("%d", &p[i]);
    }

    printf("Valores inseridos: \n\t");
    for(int i = 0; i < 5; i++){
        printf("%d ", p[i]);
    }

    free(p);
}