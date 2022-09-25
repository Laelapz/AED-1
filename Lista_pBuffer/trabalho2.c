#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define nome (sizeof(char) * 11)
#define idade (sizeof(int))
#define telefone (sizeof(int))

#define pessoaAnterior nome + idade + telefone
#define pessoaPosterior nome + idade + telefone + sizeof(void **)

#define tamanhoLista ((int*)pBuffer)[0]
#define op ((int*)pBuffer)[1]
#define i ((int*)pBuffer)[2]

#define cabeca *(void **)lista
#define cauda *(void **)(lista+(sizeof(void **)))

void Adicionar(void* pBuffer, void* lista)
{
    void *novaPessoa = malloc(nome + idade + telefone + sizeof(void **) + sizeof(void **)); 

    if(!novaPessoa)
    {
        printf("Falha ao alocar memoria\n");
        return;
    }

    *(void **)(novaPessoa + pessoaAnterior) = NULL;
    *(void **)(novaPessoa + pessoaPosterior) = NULL;

    printf("Digite o nome da pessoa:\n");
    scanf("%10s", (char*)novaPessoa);
    fflush(stdin);

    printf("Digite a idade da pessoa:\n");
    scanf("%d", (int*)(novaPessoa + nome));

    printf("Digite a idade da pessoa:\n");
    scanf("%d", (int*)(novaPessoa + nome + idade));



    if(tamanhoLista == 0)
    {
        printf("Lista vazia\n");
        cabeca = novaPessoa;
        cauda = novaPessoa;
        tamanhoLista++;
        return;
    }

    void* pessoaAtual = cabeca;

    while (pessoaAtual != NULL)
    {
        if( strcmp((char *)novaPessoa, (char *)pessoaAtual) > 0 )
        {
            if(*(void **)(pessoaAtual + pessoaPosterior) == NULL)
            {
                *(void **)(novaPessoa + pessoaAnterior) = pessoaAtual;
                *(void **)(pessoaAtual + pessoaPosterior) = novaPessoa;
                *(void **)(novaPessoa + pessoaPosterior) = NULL;
                cauda = novaPessoa;

                tamanhoLista++;
                return;
            }
            else if(strcmp((char *)(*(void **)(pessoaAtual+pessoaPosterior)), (char *)novaPessoa) > 0)
            {
                void* temp = *(void **)(pessoaAtual + pessoaPosterior);
                *(void **)(novaPessoa + pessoaAnterior) = pessoaAtual;
                *(void **)(novaPessoa + pessoaPosterior) = *(void **)(pessoaAtual + pessoaPosterior);
                *(void **)(pessoaAtual + pessoaPosterior) = novaPessoa;
                *(void **)(temp + pessoaAnterior) = novaPessoa;
                tamanhoLista++;
                return;

            }

        }
        else
        {
            *(void **)(pessoaAtual + pessoaAnterior) = novaPessoa;    
            *(void **)(novaPessoa + pessoaPosterior) = pessoaAtual;
            *(void **)(novaPessoa + pessoaAnterior) = NULL;
            cabeca = novaPessoa;
            tamanhoLista++;
            return;
        }
        

        pessoaAtual = *(void **)(pessoaAtual + pessoaPosterior);
    }

}

void Remover(void* pBuffer, void* lista)
{
    char *palavra = malloc(nome);
    if(!palavra)
    {
        printf("Falha ao alocar memoria\n");
        return;
    }
    
    printf("Digite o elemento a ser removido: ");
    scanf("%10s", palavra);
    fflush(stdin);

    void *aux = cabeca;
    while( aux != NULL )
    {
        if(strcmp(aux, palavra) == 0)
        {

            if(tamanhoLista == 1)
            {

                free(aux);
                free(palavra);
                cabeca = NULL;
                cauda = NULL;
                tamanhoLista--;
                return;
            }
            else if(*(void**)(aux + pessoaAnterior) == NULL)
            {
                void *temp = aux;
                cabeca = *(void **)(aux+pessoaPosterior);
                *(void **)(*(void **)(aux+pessoaPosterior)+pessoaAnterior) = *(void **)(aux+pessoaAnterior);
                free(temp);
                free(palavra);
                tamanhoLista--;
                return;
            }
            else if(*(void**)(aux + pessoaPosterior) == NULL)
            {
                void *temp = aux;
                cauda = *(void **)(aux+pessoaAnterior);
                *(void **)(*(void **)(aux+pessoaAnterior)+pessoaPosterior) = *(void **)(aux+pessoaPosterior);
                free(temp);
                free(palavra);
                tamanhoLista--;
                return;
            }

            void *temp = aux;
            *(void **)(*(void **)(aux+pessoaAnterior)+pessoaPosterior) = *(void **)(aux+pessoaPosterior);
            *(void **)(*(void **)(aux+pessoaPosterior)+pessoaAnterior) = *(void **)(aux+pessoaAnterior);
            free(temp);
            free(palavra);
            tamanhoLista--;
            return;
        }

        aux = *(void **)(aux+pessoaPosterior);
    }
    
    free(palavra);

}

void Buscar(void* pessoas, void* lista)
{
    char *palavra = malloc(nome);
    if(!palavra)
    {
        printf("Falha ao alocar memoria\n");
        return;
    }

    printf("Digite o elemento a ser buscado: ");
    scanf("%10s", palavra);
    fflush(stdin);

    void *aux = cabeca;

    while (aux != NULL)
    {   
        if(strcmp(palavra, (char*)aux) == 0)
        {
            printf("elemento encontrado:\n");

            printf("\tNome: %s", (char*)aux);
            printf(" - Idade: %d", *(int *)(aux + nome));
            printf(" - Idade: %d\n\n", *(int*)(aux + nome + idade));
            free(palavra);
            return;
        }

        aux = *(void **)(aux + pessoaPosterior);
    }
    
    free(palavra); 
}

void Listar(void* pessoas, void* lista)
{
    void *aux = cabeca;
    while (aux != NULL)
    {   
        printf("\tNome: %s", (char*)aux);
        printf(" - Idade: %d", *(int *)(aux + nome));
        printf(" - Idade: %d\n", *(int*)(aux + nome + idade));

        aux = *(void **)(aux + pessoaPosterior);
    }

    printf("\n");
}

void ListarAoContrario(void* pessoas, void* lista)
{
    void *aux = cauda;
    while (aux != NULL)
    {   
        printf("\tNome: %s", (char*)aux);
        printf(" - Idade: %d", *(int *)(aux + nome));
        printf(" - Idade: %d\n", *(int*)(aux + nome + idade));

        aux = *(void **)(aux + pessoaAnterior);
    }

    printf("\n");
}

void LiberarLista(void* pessoas, void* lista)
{
    void *aux = cabeca;
    while (aux != NULL)
    { 
        void* pessoaAtual = aux;
        aux = *(void **)(aux + pessoaPosterior);
        free(pessoaAtual);
    }

}

int main()
{

    void *lista = malloc(sizeof(void *) * 2);
    if(!lista)
    {
        printf("Erro ao alocar lista\n");
        return -1;
    }

    cabeca = NULL;
    cauda = NULL;

    void* pBuffer = malloc(sizeof(int) * 3);
    if(!pBuffer)
    {
        printf("Erro ao alocar pBuffer\n");
        return -1;
    }

    tamanhoLista = 0;
    op = 0;
    i = 0;
    

    while (op != 6)
    {
        printf("Digite a opcao desejada:\n");
        printf("\t1 - Adicionar\n\t2 - Remover\n\t3 - Buscar\n\t4 - Listar\n\t5 - ListarAoContrario\n\t6 - Sair\n");
        scanf("%d", &op);

        if(op == 1)
        {
            Adicionar(pBuffer, lista);
        }
        else if(op == 2)
        {
            Remover(pBuffer, lista);
        }
        else if(op == 3)
        {
            Buscar(pBuffer, lista);
        }
        else if(op == 4)
        {
            Listar(pBuffer, lista);
        }
        else if(op == 5)
        {
            ListarAoContrario(pBuffer, lista);
        }
    }
    
    LiberarLista(pBuffer, lista);
    free(lista);
    free(pBuffer);

    return 0;
}