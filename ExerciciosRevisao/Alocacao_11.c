#include <stdio.h>
#include <stdlib.h>

//Struct é uma coisa um pouco complicada pra mim, assim como o malloc nos usos mais básicos eu consigo me virar, mas conforme vai ficando
//mais complexo eu encontro bastante problemas e preciso de mais tempo para realizar as tarefas

typedef struct{
    int matricula;
    char sobrenome[20];
    int anoNascimento;
}alunos;

void LerDadosDosAlunos(int numAlunos, alunos* dadosAlunos){

    for(int i = 0; i < numAlunos; i++){
        printf("Digite o numero da matricula do %d aluno\n\t", i+1);
        scanf("%d", &dadosAlunos->matricula);

        printf("Digite o ano de nascimento do %d aluno\n\t", i+1);
        scanf("%d", &dadosAlunos->anoNascimento);

        printf("Digite o sobrenome do %d aluno\n\t", i+1);
        scanf("%s", &dadosAlunos->sobrenome);

        printf("\n");
        dadosAlunos += sizeof(alunos);
    }

}

void ImprimirDadosDosAlunos(int numAlunos, alunos* dadosAlunos){
    for(int i = 0; i < numAlunos; i++){
        printf("Numero da matricula do aluno: %d \n\t", dadosAlunos->matricula);
        printf("Ano de nascimento do aluno: %d \n\t", dadosAlunos->anoNascimento);
        printf("Sobrenome do aluno:  %s \n\n\t", dadosAlunos->sobrenome);

        dadosAlunos += sizeof(alunos);
    }
}

int main(){
    int numAlunos;

    printf("Digite o numero de alunos a serem inseridos: \n");
    scanf("%d", &numAlunos);

    alunos *dadosAlunos = malloc(sizeof(alunos) * numAlunos);

    LerDadosDosAlunos(numAlunos, dadosAlunos);
    ImprimirDadosDosAlunos(numAlunos, dadosAlunos);

    free(dadosAlunos);

}