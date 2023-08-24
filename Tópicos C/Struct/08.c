/*
8. Construa um programa para ler e manipular informações de 3 cadastros de clientes.
São necessárias duas estruturas: cliente e endereco. Todos os dados de um cliente
devem ser lidos e depois impressos. Os campos das estruturas são: cliente:
matricula (int), nome (char), endereço (endereco); endereco: logradouro (char),
numero (int), bairro (char), cep (long int).
*/

#include <stdio.h>

int main()
{
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
    } cliente;

    printf("Informe o nome do cliente: ");
    fgets(cliente.nome, 100, stdin);
    fflush(stdin);

    return 0;
}