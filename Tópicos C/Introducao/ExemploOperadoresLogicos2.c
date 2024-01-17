#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    int idade;
    bool check;

    printf("Informe sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18 && idade <= 65)
    {
        printf("Voce pode fazer o emprestimo!.\n");
        check = false;
    }
    else if (idade > 65)
    {
        check = true;
    }
    else if (!(idade >= 18))
    {
        printf("Voce nao pode fazer o emprestimo!\n");
    }

    if (check == true)
    {
        printf("Voce pode fazer o emprestimo especial!\n");
    }

    system("pause");
    return 0;
}