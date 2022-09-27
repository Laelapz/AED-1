#include <stdio.h>
#include <stdlib.h>

int Search(int num, int* vetor, int tam)
{
    for ( int  i = 0; i < tam; i++)
    {
        if(num == *(vetor + i)) return 1;
    }
    
    return 0;
}

void Destroy(int num, int* vetor, int tam)
{
    int encolher = 0;
    for ( int  i = 0; i < tam-1; i++)
    {
        if(num == *(vetor + i)) encolher = 1;

        if( encolher ){
            *(vetor + i) = *(vetor+ i + 1);
        }
    }
}

int FindSum(int fim, int* vetor, int tam)
{
    int ini = 0;
    
    while(ini <= fim){
        if(Search(ini, vetor, tam) && Search(fim, vetor, tam)){
            printf("Removendo %d e %d\n", ini, fim);
            Destroy(ini, vetor, tam);
            tam--;

            Destroy(fim, vetor, tam);
            tam--;
            return 1;
        }
        ini++;
        fim--;
    }
    
    return 0;  
}

int main()
{
    int tam, num;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &tam);

    int* vetor = (int*)malloc(sizeof(int)*tam);

    for(int i = 0; i < tam; i++)
    {
        *(vetor+i) = rand();
    }
    
    for(int i = 0; i < tam; i++)
    {
        printf("Valor da posicao %d: %d\n", i, *(vetor + i));
    }

    printf("Digite um numero:\n");
    scanf("%d", &num);

    if( Search(num, vetor, tam))
    {
        Destroy(num, vetor, tam);
        tam--;
    }
    else
    {
        if(FindSum(num, vetor, tam)) tam -= 2;
    }

    vetor = (int*)realloc(vetor, sizeof(int)*tam);

    for(int i = 0; i < tam; i++)
    {
        printf("Valor da posicao %d: %d\n", i, *(vetor+i));
    }

    free(vetor);
}
