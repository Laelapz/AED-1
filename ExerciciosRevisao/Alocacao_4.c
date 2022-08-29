#include <stdio.h>
#include <stdlib.h>
//Ex4 Alocação Dinamica

char* AlocarString(int tamanho, char* string)
{
    string = (char*)realloc(string, sizeof(char) * tamanho+1);

    printf("Digite a string  a ser lida:\n\t");

    for( int i = 0; i < tamanho; i++){
        scanf(" %c", &string[i]);
    }
    string[tamanho] = '\0';

    return string;
}

void ImprimirStringSemVogais(int tamanho, char* string){
    
    for(int i = 0; i < tamanho; i++)
    {
        if( string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u' )
        {
            printf("%c", string[i]);
        }
    }
    
}

int main()
{
    int tam = 0;

    printf("Digite o tamanho da string a ser modificada:\n\t");
    scanf("%d", &tam);

    char* string = (char*)malloc(sizeof(char) * tam);

    string = AlocarString(tam, string);

    ImprimirStringSemVogais(tam, string);

    free(string);
}