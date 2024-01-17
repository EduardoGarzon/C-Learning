/*
    Typedef é uma palavra reservada que
    permite atribuir um nickname a um tipo de dado existente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef char user[25];

int main()
{
    user user1 = "Luiz Eduardo";

    printf("%s\n", user1);

    system("pause");
    return 0;
}