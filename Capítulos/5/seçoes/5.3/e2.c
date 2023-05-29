#include <stdio.h>

int Calculadora(int i) {

    //Inicialização
    int Soma = 1, Subtração = 2, Multiplicação = 3, Divisão = 4, Sair = 0;

    //Condição
    if (i == Soma) {

        int res, v1, v2;

        printf("Digite o primeiro valor da soma\n");
        scanf("%d",&v1);
        printf("Digite o segundo valor da soma\n");
        scanf("%d",&v2);
        res = v1 + v2;
        printf("O resultado é %d\n",res);

        return 0;

    } else if (i == Multiplicação){

        int res, v1, v2;

        printf("Digite o primeiro valor da Multiplicação\n");
        scanf("%d",&v1);
        printf("Digite o segundo valor da Multiplicação\n");
        scanf("%d",&v2);
        res = v1*v2;
        printf("O resultado é %d",res);

        return 0;

    } else if (i == Subtração){

        int res, v1, v2;

        printf("Digite o primeiro valor da Subtração\n");
        scanf("%d",&v1);
        printf("Digite o segundo valor da Subtração\n");
        scanf("%d",&v2);
        res = v1 - v2;
        printf("O resultado é %d",res);

        return 0;

    } else if (i == Divisão){

        int res, v1, v2;

        printf("Digite o primeiro valor da Divisão\n");
        scanf("%d",&v1);
        printf("Digite o segundo valor da Divisão\n");
        scanf("%d",&v2);
        res = v1/v2;
        printf("O resultado é %d",res);

        return 0;
        
    }
    else if (i == Sair) {
        printf("Saindo do Programa");
        return 0;
    }
    }

int main(void) {
    int ope ;
    //Valor inicial atribuido pelo usuário 
    printf("Digite o tipo de operação :\n ");
    scanf("%d",&ope);

    //Chamada
    Calculadora(ope);
}
