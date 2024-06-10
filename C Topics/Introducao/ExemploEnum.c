#include <stdio.h>
#include <stdlib.h>

enum Day
{
    Segunda = 1,
    Terca = 2,
    Quarta = 3,
    Quinta = 4,
    Sexta = 5,
    Sabado = 6,
    Domingo = 7
};

int main()
{
    enum Day today = Sabado;

    if (today == 6 || today == Domingo)
    {
        printf("Ja e fim de semana! Party Time!\n");
    }
    else
    {
        printf("I have to work today...\n");
    }

    system("pause");
    return 0;
}