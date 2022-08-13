#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//gcc -Wall -Werror -g c:\Users\johnn\Documents\Facu\AED\SlideSemana1\Ex2.c -o SlideSemana1\Ex2.exe

void AdicionarNome(char* nomes)
{
    char nome[20];

    printf("Digite o novo nome a ser adicionado:\n");
    scanf("%s", &nome);
    printf("%d\n", strlen(nome));

    nomes = (char *)realloc(nomes, _msize(nomes) + sizeof(char) * strlen(nome)+1);

    for(int i = 0; i < strlen(nome); i++)
    {
        nomes[i + _msize(nomes) - strlen(nome) - 1] = nome[i];
    }

    nomes[_msize(nomes) - 1] = '\n';

    printf("Tamanho da memoria alocada: %d\n", _msize(nomes)-1);
}

void RemoverNome(char* nomes, int index)
{
    int numSeparadores = 0;
    int tamanhoDaPalavra = 0;
    int ajustar = 0;

    for(int i = 1; i < _msize(nomes); i++)
    {
        if(nomes[i] == '\n' && numSeparadores != index)
        {
            numSeparadores++;
        }
        else if(nomes[i] != '\n' && numSeparadores == index && !ajustar)
        {
            tamanhoDaPalavra++;
        }
        else if(nomes[i] == '\n' && numSeparadores == index  && !ajustar)
        {
            ajustar = 1;
        }
        

        if( ajustar )
        {
            nomes[i-(tamanhoDaPalavra+1)] = nomes[i];
        }
    }

    if(ajustar) nomes = (char *)realloc(nomes, _msize(nomes) - sizeof(char) * (tamanhoDaPalavra+1));
    printf("Tamanho da memoria alocada: %d\n", _msize(nomes)-1);
}

void Listar(char* nomes)
{
    for(int i = 1; i < _msize(nomes)-1; i++)
    {
        printf("%c", nomes[i]);
    }
}

int main()
{
    int op;
    char* nomes = (char *)malloc(sizeof(char));
    char* inicioNomes = nomes;

    do{
        printf("\nSeleciona a opcao:\n\t1-Adicionar nome\n\t2-Remover nome\n\t3-Listar\n\t4-Sair\n");
        scanf("%d", &op);
        
        if(op == 1)
        {
            AdicionarNome(nomes);
        }
        else if(op == 2)
        {
            printf("Digite o index da palavra que quer remover: \n");
            scanf("%d", &op);
            RemoverNome(nomes, op);
        }
        else if( op == 3)
        {
            Listar(inicioNomes);
        }

    }while (op != 4);
    
    free(nomes);
    free(inicioNomes);

    return 0;
}