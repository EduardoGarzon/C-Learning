#ifndef SISTEMA_H // Diretivas de pré-processamento, garante inclusao unica
#define SISTEMA_H // de bloco de codigo no programa evitando duplicacoes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"
#include "BD.h"

typedef struct System
{
    database database;
} sistema;

void cadastrarUsuario(sistema *sis)
{
    User newuser;
    setNome(&newuser);
    sis->database.users[0] = newuser;
}

void exibirUsuario(sistema *sis)
{
    int users = sis->database.usuarios;
    User current = sis->database.users[0];
    printf("%s", getNome(current));
}

#endif