#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char tipo[100];
    char marca[50];
    char modelo[25];
    char energia;
    char descricao[500];
    int quantidade;
    int codigo;
} Eletronico;

// procedimento que imprime as informações de um Eletrônico
void imprimirEletronico(Eletronico e)
{
    printf("\tTipo: %s", e.tipo);
    printf("\tMarca: %s", e.marca);
    printf("\tModelo: %s", e.modelo);
    printf("\tEnergia: %c\tQuantidade: %d\n", e.energia, e.quantidade);
    printf("\tDescricao: %s", e.descricao);
}

// função que lê os dados de um eletrônico e retorna para quem chamou
Eletronico lerEletronico()
{
    Eletronico e;

    printf("Digite o tipo: ");
    fgets(e.tipo, 100, stdin);

    printf("Marca: ");
    fgets(e.marca, 50, stdin);

    printf("Modelo: ");
    fgets(e.modelo, 25, stdin);

    printf("Eficiencia energetica: ");
    scanf("%c", &e.energia);
    scanf("%c");

    printf("Descricao: ");
    fgets(e.descricao, 500, stdin);

    printf("Quantidade e codigo: ");
    scanf("%d%d", &e.quantidade, &e.codigo);

    return e;
}

int main()
{
    Eletronico ele;

    ele = lerEletronico();
    imprimirEletronico(ele);

    system("pause");
    return 0;
}