/*
    Simulando recursao com uma estrutura de dados PILHA por meio de aquivos de cabecalho.
    Cada arquivo é um TAD - Tipo Abstrato de Dado.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.c" // puxa as funcoes e procedimentos

int pilha_fatorial(int numero)
{
    No *remover;
    No *topo = NULL;

    while (numero > 1)
    {
        topo = empilhar(topo, numero); // empilha cada numero do valor a ser fatorado
        numero--;                      // decrementa o valor informado
    }

    imprime_pilha(topo);

    while (topo)
    {
        remover = desempilhar(&topo);     // recebe o topo atual a ser removido
        numero = numero * remover->valor; // calculo do fatorial

        free(remover); // libera o topo atual
    }

    return numero;
}

int main()
{
    int valor = 0;

    printf("Informe um valor para calcular o fatorial: ");
    scanf("%d", &valor);

    printf("Fatorial por pilha: %d\n", pilha_fatorial(valor));

    system("pause");
    return 0;
}