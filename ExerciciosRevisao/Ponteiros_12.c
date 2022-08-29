#include <stdio.h>

//As vezes me confundo sobre onde preciso usar o *
//Nos caso se estou trabalhando com um valor ou um endereço e se preciso castar para outros tipos

int OrdenarValores(int* a, int* b, int* c){
    int temp;

    if(*a > *b){
        temp = *b;
        *b = *a;
        *a = temp;
    }

    if(*b > *c){
        temp = *c;
        *c = *b;
        *b = temp;
    }

    if(*a > *b){
        temp = *b;
        *b = *a;
        *a = temp;
    }

    if (*a == *b && *a == *c) return 1;

    return 0;
}

int main(){
    int a, b, c;

    printf("Digite tres valores:\n");
    scanf("%d%d%d", &a, &b, &c);

    int result = OrdenarValores(&a, &b, &c);
    printf("Os valores ordenados: %d %d %d\n", a, b, c);

    if(result){
        printf("Os valores sao todos iguais\n");
    }
    else{
        printf("Existem valores diferentes");
    }

    
}