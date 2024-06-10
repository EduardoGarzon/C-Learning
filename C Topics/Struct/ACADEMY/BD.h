#ifndef BD_H // Diretivas de pré-processamento, garante inclusao unica
#define BD_H // de bloco de codigo no programa evitando duplicacoes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"

typedef struct BD
{
    int usuarios;
    User users[10];
} database;

void inicializarDataBase(database *BD)
{
    BD->usuarios = 0;
}

#endif