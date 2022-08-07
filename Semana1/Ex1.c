#include <stdio.h>

//As vezes me confundo sobre onde preciso usar o *
//Nos caso se estou trabalhando com um valor ou um endereço e se preciso castar para outros tipos

void OrdenarValores(int* a, int* b, int* c){
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
}

int main(){
    int a, b, c;

    printf("Digite tres valores:\n");
    scanf("%d%d%d", &a, &b, &c);

    OrdenarValores(&a, &b, &c);
    printf("Os valores digitado: %d %d %d\n", a, b, c);
}