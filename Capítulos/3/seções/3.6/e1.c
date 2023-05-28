#include <stdio.h>

int IterarNota(int i) {

    //Inicialização
    int NotaMax;

    //Nota maxima
    NotaMax = 10;

    //Condição
    if (i >= NotaMax) {
        printf("Aprovado\n");
        printf("%d",i);
        return 0;
    } else if ((i >= 0) && (i < NotaMax)){
        printf("Reprovado\n");
        //Update i
        i++;
        //Reinicie a função
        IterarNota(i);
    } else {
        printf("Coloque um número positivo");
    }
    }

int main(void) {
    int i ;
    //Valor inicial atribuido pelo usuário 
    printf("Digite o valor inicial i :\n ");
    scanf("%d",&i);

    //Chamada
    IterarNota(i);
}
