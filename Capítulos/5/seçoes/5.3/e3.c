#include <stdio.h>

int main(void) {
    char ope[] = "operação";
    char ope2;
    printf("%s\n",ope);

    scanf("%s",&ope2);
    printf("%s\n",&ope2);

    char opeT;
    opeT = "operação";
    if (opeT == &ope2) {
        printf("%s\n","são iguais");
    } else {
        printf("%s\n","algo está errado");
    }

    return 0;
}
