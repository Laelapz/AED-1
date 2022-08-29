#include <stdio.h>
#include <stdlib.h>

struct Cidades
{
    char nome[10];
    int posX;
    int posY;
};

void CriarMatriz(int nmroCidades,  struct Cidades* cidades)
{
    int** linhas  = (int**)malloc(sizeof(int) * nmroCidades);
    int* colunas = (int*)malloc(sizeof(int) * nmroCidades);
    
    int i = 0, j = 0; 
    
    for(i = 0; i < nmroCidades; i++)
    {
        linhas[i] = &colunas[j];
        for(j = 0; j < nmroCidades; j++)
        {
            colunas[j] = i + j;
        }
    }

    for(i = 0; i < nmroCidades; i++)
    {
        for(j = 0; j < nmroCidades; j++)
        {
            printf("%n ", *((linhas+i)+j));
        }
    }

    free(linhas);
    free(colunas);
}

void LerDados(int nmroCidades)
{
    printf("O numero de cidades: %d\n", nmroCidades);

    struct Cidades* cidades  = (struct Cidades*)malloc(sizeof(struct Cidades) * nmroCidades);

    for(int i = 0; i < nmroCidades; i++)
    {
        printf("Digite o nome da cidade:\n\t");
        scanf("%s", cidades[i].nome);

        printf("Digite a posicao x da cidade:\n\t");
        scanf("%d", &cidades[i].posX);

        printf("Digite a posicao y da cidade:\n\t");
        scanf("%d", &cidades[i].posY);
    }

    CriarMatriz(nmroCidades, cidades);

    free(cidades);
}

int main()
{
    int nmroCidades;

    printf("Digite o numero de cidades a serem inseridas:\n");
    scanf("%d", &nmroCidades);

    LerDados(nmroCidades);

    return 0;
}