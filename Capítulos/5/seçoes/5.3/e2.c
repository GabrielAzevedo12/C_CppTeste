#include <stdio.h>

int Calculadora(int i) {

    //Inicialização
    int Soma = 1, Subtração = 2, Multiplicação = 3, Divisão = 4, Sair = 0;

    //Condição
    if (i == Soma) {

        float v1, v2;
        float res;

        printf("Digite o primeiro valor da soma\n");
        scanf("%f",&v1);
        printf("Digite o segundo valor da soma\n");
        scanf("%f",&v2);
        res = v1 + v2;
        printf("O resultado é %f\n",res);

        return 0;

    } else if (i == Multiplicação){

        float res, v1, v2;

        printf("Digite o primeiro valor da Multiplicação\n");
        scanf("%f",&v1);
        printf("Digite o segundo valor da Multiplicação\n");
        scanf("%f",&v2);
        res = v1*v2;
        printf("O resultado é %f\n",res);

        return 0;

    } else if (i == Subtração){

        float res, v1, v2;

        printf("Digite o primeiro valor da Subtração\n");
        scanf("%f",&v1);
        printf("Digite o segundo valor da Subtração\n");
        scanf("%f",&v2);
        res = v1 - v2;
        printf("O resultado é %f\n",res);

        return 0;

    } else if (i == Divisão){

        float res, v1, v2;

        printf("Digite o primeiro valor da Divisão\n");
        scanf("%f",&v1);
        printf("Digite o segundo valor da Divisão\n");
        scanf("%f",&v2);
        res = v1/v2;
        printf("O resultado é %f\n",res);

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
    printf("Escolha um tipo de operação, sendo que cada uma tem os seguintes valores : \n Soma = 1, Subtração = 2, Multiplicação = 3, Divisão = 4, Sair = 0 \n Digite o tipo de operação :\n ");
    scanf("%d",&ope);

    //Chamada
    Calculadora(ope);
}
