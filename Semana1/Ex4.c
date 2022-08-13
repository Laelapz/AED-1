#include <stdio.h>

int Fat(int fatNum){
    if(fatNum == 1 || fatNum == 0) return 1;

    return fatNum * Fat(fatNum-1);
}

int main(){
    int num;

    printf("Digite o fatorial a ser calculado: \n\t");
    scanf("%d", &num);

    printf("Resultado do fatorial: %d\n", Fat(num));
}