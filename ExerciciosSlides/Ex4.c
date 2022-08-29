#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void* myRealloc(void* vetor, int tamanho)
{
    void* newPointer = malloc(tamanho);
    memcpy(newPointer, vetor, _msize(vetor));
    free(vetor);
    return newPointer;
}

int main()
{
    int tam;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &tam);

    int* vetor = (int*)malloc(sizeof(int) * tam);

    for(int i = 0; i < tam; i++)
    {
        printf("Digite o valor %d: ", i);
        scanf("%d", vetor+i);
    }
    
        tam++;
        vetor = (int*)myRealloc((void*)vetor, sizeof(int)*tam);
        printf("Digite o novo valor: ");
        scanf(" %d", vetor+tam-1);

        for(int i = 0; i < tam; i++)
        {
            printf("Valor %d: %d\n", i, vetor[i]);
        }

    free(vetor);

}