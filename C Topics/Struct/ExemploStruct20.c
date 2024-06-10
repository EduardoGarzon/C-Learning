/*
    Construa um programa para ler e manipular informações de 3 cadastros de clientes.

    São necessárias duas estruturas: cliente e endereco.

    Todos os dados de um cliente devem ser lidos e depois impressos.

    Os campos das estruturas são:
    cliente: matricula (int), nome (char), endereço (endereco);
             endereco: logradouro (char), numero (int), bairro (char), cep (long int).
*/

#include <stdio.h>
#include <stdlib.h>

struct end
{
    char logradouro[20];
    char bairro[20];
    int numero;
    long int cep;
};

struct clientes
{
    char nome[100];
    int matricula;
    struct end endereco;
} cliente[3];

int main()
{
    for (int i = 0; i <= 2; i++)
    {
        printf("Informe o nome do cliente: ");
        fgets(cliente[i].nome, 100, stdin);
        getchar();

        printf("Informe a matricula do cliente: ");
        scanf("%d", &cliente[i].matricula);
        getchar();

        printf("Informe: Logradouro/Bairro/Numero/Cep: ");
        scanf("%s/%s/%d/%ld", &cliente[i].endereco.logradouro, &cliente[i].endereco.bairro,
              &cliente[i].endereco.numero, &cliente[i].endereco.cep);
        getchar();

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i <= 2; i++)
    {
        printf("Nome: %s", cliente->nome);
        printf("Matricula: %d\n", cliente->matricula);
        printf("Logradouro: %s | Bairro: %s | Numero: %d | CEP: %ld\n", cliente[i].endereco.logradouro, cliente[i].endereco.bairro, cliente[i].endereco.numero, cliente[i].endereco.cep);

        printf("\n");
    }

    system("pause");
    return 0;
}