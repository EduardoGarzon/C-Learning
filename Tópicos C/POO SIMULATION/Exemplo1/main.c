#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main() {
    Pessoa* pessoa = criarPessoa("João", 25);
    
    pessoa->apresentar(pessoa);
    
    destruirPessoa(pessoa);
    
    pessoa->maioridade = maioridade;
    
    pessoa->maioridade(pessoa->idade);

    system("pause");
    return 0;
}
