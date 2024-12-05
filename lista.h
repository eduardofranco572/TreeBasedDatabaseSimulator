#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char cpf[15];
    char nome[80];
    char endereco[200];
    char telefone[15];
    char email[120];
} Dados;

// Variáveis
extern Dados * lista;
extern int posicao;
extern int tamanho;

// Funções
Dados * addLista(Dados valor);
int size();
bool searchByIndex(int indice, Dados *valor);
int searchByValue(Dados valor);
void delete(Dados valor);
void sort();
bool alterarLista(Dados * registro, Dados * valor);
void expand();
void inicializarLista();
void destroy();
#endif

