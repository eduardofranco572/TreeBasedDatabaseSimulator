//
// Created by Eduardo on 26/11/2024.
//

#include <string.h>
#include "lista_dupla.h"
// variáveis
struct no_dupla *inicio = NULL;
struct no_dupla *novo = NULL;
struct no_dupla *aux = NULL;
struct no_dupla *anterior = NULL;
struct no_dupla *proximo = NULL;
struct no_dupla *noCorrente = NULL;

// funções
void inicializarListaDupla() {
    inicio = NULL;
}

void finalizarDupla(struct no_dupla *quem) {
    if(quem->proximo != NULL) {
        finalizarDupla(quem->proximo);
    }
    free(quem);
}

struct no_dupla * novoNoDupla(Dados * dado, char * nome) {
    struct no_dupla *p = malloc(sizeof(struct no_dupla));
    if(!p) {
        printf("Erro na alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
    p->anterior = NULL;
    p->nome = nome;
    p->registro = dado;
    p->proximo = NULL;

    return p;
}

void adicionarOrdenado(Dados * dado, char * nome) {
    novo = novoNoDupla(dado, nome);

    if(inicio == NULL) {
        inicio = novo;
    }
    else {
        if(strcmp(novo->nome,inicio->nome) == -1) {
            adicionarNoInicio();
        }
        else {
            aux = inicio;
            anterior = inicio;
            while(strcmp(aux->nome,novo->nome) == -1 && aux->proximo != NULL) {
                anterior = aux;
                aux = aux->proximo;
            }
            if(strcmp(novo->nome,aux->nome) == 1) {
                adicionarNoFinal();
            }
            else {
                adicionarNoMeio();
            }
        }
    }
}

void adicionarNoInicio() {
    novo->proximo = inicio;
    inicio->anterior = novo;
    inicio = novo;
}

void adicionarNoFinal() {
    aux->proximo = novo;
    novo->anterior = aux;
}

void adicionarNoMeio() {
    novo->proximo = aux;
    anterior->proximo = novo;

    aux->anterior = novo;
    novo->anterior = anterior;
}

void excluirListaDupla(char * nome) {
    if(inicio != NULL) {
        if(strcmp(nome,inicio->nome) == 0) {
            excluirNoInicio();
        }
        else {
            aux = inicio;
            anterior = inicio;
            while(strcmp(aux->nome,nome) != 0 && aux->proximo != NULL) {
                anterior = aux;
                aux = aux->proximo;
            }
            if(strcmp(aux->nome,nome) == 0) {
                if(aux->proximo == NULL) {
                    excluirNoFinal();
                }
                else {
                    excluirNoMeio();
                }
            }
        }
    }
}

void excluirNoInicio() {
    if(inicio->proximo == NULL) {
        free(inicio);
        inicio = NULL;
    }
    else {
        aux = inicio;
        inicio = inicio->proximo;
        free(aux);
    }
}

void excluirNoFinal() {
    anterior->proximo = NULL;
    free(aux);
}

void excluirNoMeio() {
    proximo = aux->proximo;

    anterior->proximo = proximo;
    proximo->anterior = anterior;
    free(aux);
}

void imprimirLista(){
    aux = inicio;
    while (1){
        printf("%s\n",aux->nome);
        aux = aux->proximo;
        if(aux == NULL){
            break;
        }
    }
}

void paraInicio() {
    noCorrente = inicio;
}

bool paraProximo() {
    if(noCorrente == NULL) {
        return false;
    }
    noCorrente = noCorrente->proximo;

    return true;
}