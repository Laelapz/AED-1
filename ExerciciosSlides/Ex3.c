#include <stdio.h>
#include <malloc.h>

//gcc -Wall -Werror -g c:\Users\johnn\Documents\Facu\AED\SlideSemana1\Ex2.c -o SlideSemana1\Ex2.exe

void* AdicionarNome(void* dados)
{
    printf("Tamanho: %d", _msize(dados));
    char nome[10];

    dados = realloc(dados, (_msize(dados) + sizeof(char) * 10 + sizeof(int) * 2) );

    printf("Digite o nome da pessoa a ser inserida:\n\t");
    scanf("%s", nome);

    for(int i = 0; i < 10; i++)
    {
        *((char*)dados + _msize(dados) - ( (sizeof(char) * 10) + sizeof(int) * 2 ) + i ) = nome[i];
    }

    printf("Digite a idade da pessoa:\n\t");
    scanf("%d", (int*)dados + _msize(dados) - sizeof(int) * 2);

    printf("Digite o telefone da pessoa:\n\t");
    scanf("%d", (int*)dados + _msize(dados) - sizeof(int));

    printf("Tamanho: %d", _msize(dados));

    return dados;
}

void RemoverNome(void* nomes, int index)
{
 
}

void Listar(void* dados)
{
    printf("\n\t %s", ((char*)dados + _msize(dados) -  sizeof(char) * 10 - sizeof(int) * 2 ));
    printf("\n\t %d", *((int*)dados + _msize(dados) - sizeof(int) * 2));
    printf("\n\t %d", *((int*)dados + _msize(dados) - sizeof(int)));
}

int main()
{
    int op = 0;
    void *dados;
    dados = malloc(sizeof(int));
    *(int*)dados = 0;

    do{
        printf("Digite a opcao desejada:\n\t1 - Incluir\n\t2 - Apagar\n\t3 - Buscar\n\t4 - Listar\n\t5 - Sair\n");
        scanf(" %d", &op);
        
        if(op == 1){
            dados = AdicionarNome(dados);
        }   
        else if(op == 2)
        {
            printf("Digite a posicao a ser removida\n");
            RemoverNome(dados, op);
        }
        else if(op == 4)
        {
            Listar(dados);
        }

    }while (op != 5);

    free(dados);
    return 0;
}