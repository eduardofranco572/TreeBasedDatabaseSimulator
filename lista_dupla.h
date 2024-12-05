#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

// Constantes
struct no_dupla {
    struct no_dupla * anterior;
    char * nome;
    Dados * registro;
    struct no_dupla *proximo;
};

// Variáveis
extern struct no_dupla *inicio;
extern struct no_dupla *novo;
extern struct no_dupla *aux;
extern struct no_dupla *anterior;
extern struct no_dupla *proximo;
extern struct no_dupla *noCorrente;

// Protótipos
void inicializarListaDupla();
void finalizarDupla(struct no_dupla *quem);
struct no_dupla * novoNoDupla(Dados * dado, char * nome);
void adicionarOrdenado(Dados * dado, char * nome);
void adicionarNoInicio();
void adicionarNoFinal();
void adicionarNoMeio();
void excluirListaDupla(char * nome);
void excluirNoInicio();
void excluirNoFinal();
void excluirNoMeio();

void imprimirLista();

void paraInicio();
bool paraProximo();

#endif