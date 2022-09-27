#include <stdio.h>
#include <stdlib.h>

#define tamanhoLista *(int *)lista
#define cabeca *(void **)(lista+sizeof(int))
#define proximo sizeof(char)

void Pop(void* lista)
{
    void* temp = cabeca;
    cabeca = *(void**)(temp+proximo);
    tamanhoLista -= 1;
    free(temp);
}

int Push(char letra, void* lista)
{
    if(letra == '(')
    {
        if(tamanhoLista == 0){
            void * novoElemento = malloc(sizeof(char) + sizeof(void **));
            *(char *)novoElemento = '(';
            *(void **)(novoElemento+proximo) = NULL;
            cabeca = novoElemento;
            tamanhoLista += 1;
        }
        else
        {
            void * novoElemento = malloc(sizeof(char) + sizeof(void **));
            *(char *)novoElemento = '(';
            *(void **)(novoElemento+proximo) = cabeca;
            cabeca = novoElemento;
            tamanhoLista += 1;
        }
    }
    else if(letra == ')')
    {
        if(tamanhoLista == 0){
            return -1;
        }
        else{
            Pop(lista);
        }
    }

    return 0;
}

void Listar(void* lista)
{
    void* temp = cabeca;
    printf("\n\tListando\n");
    while(temp != NULL)
    {
        printf("Elemento: %c\n", *(char*)cabeca);

        temp = *(void**)(temp+proximo);
    }
}

void LiberarLista(void* lista)
{
    void* temp = cabeca;
    printf("\n\tLiberando\n");
    while(temp != NULL)
    {
        printf("Elemento: %c\n", *(char*)temp);
        
        cabeca = temp;
        temp = *(void**)(temp+proximo);
        free(cabeca);
    }
}

int main()
{
    void* lista = malloc(sizeof(int) + sizeof(void **));
    cabeca = NULL;
    int result = 0;
    tamanhoLista = 0;

    char letra, letraAnterior;
    letra = ' ';
    letraAnterior = ' ';

    printf("Digite a sentenca a ser lida:\n");

    while (letraAnterior != 'x' || letra != '\n')
    {
        letraAnterior = letra;
        scanf("%1c", &letra);
        result = Push(letraAnterior, lista);

        if(result == -1) break;
    }
    
    if((tamanhoLista > 0 || tamanhoLista < 0) || result == -1){
        printf("Expressao invalida!!!\n");
    }
    else{
        printf("Expressao valida\n");
    }

    LiberarLista(lista);
    free(lista);

    return 0;
}