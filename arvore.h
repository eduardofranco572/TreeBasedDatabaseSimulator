#ifndef ARVORE_H
#define ARVORE_H

#include "lista.h"

typedef struct no {
    char cpf[15];
    Dados * registro;
    struct no *esquerda;
    struct no *direita;
} No;

void inicializar();
No* novoNo(const char* cpf, Dados * registro);
void adicionarCPF(const char* cpf, Dados * registro);
Dados * localizarCPF(const char* cpf);
void excluirCPF(const char* cpf);
void finalizar(No *raiz);

#endif
