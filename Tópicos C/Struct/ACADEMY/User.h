#ifndef USER_H // Diretivas de pré-processamento, garante inclusao unica
#define USER_H // de bloco de codigo no programa evitando duplicacoes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração de enums
enum Curso
{
    COMPUTACAO,
    ENGENHARIA
};

enum Status
{
    BOLSISTA,
    VOLUNTARIO
};

// Declaração da estrutura User
typedef struct
{
    // Atributos
    char nome[50];
    int RA;
    enum Curso curso;
    enum Status status;
} User;

// Declaração dos métodos
char *getNome(User user)
{
    char *nome = malloc(sizeof(user.nome));
    strcpy(nome, user.nome);
    return nome;
}


void setNome(User *user)
{
    fgets(user->nome, 50, stdin);
}

void getRA(User *user);
void setRA(User *user, const char *RA);
void getCurso(User *user);
void setCurso(User *user, enum Curso curso);
void getStatus(User *user);
void setStatus(User *user, enum Status status);

#endif