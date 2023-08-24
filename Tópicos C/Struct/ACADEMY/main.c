#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"

sistema sis;    

void menu();

int main()
{
    //menu();

    inicializarDataBase(&sis.database);
    cadastrarUsuario(&sis);
    exibirUsuario(&sis);


    return 0;
}