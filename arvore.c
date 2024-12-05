#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static No* raiz = NULL;

void inicializar() {
    raiz = NULL;
}

No* novoNo(const char* cpf, Dados * registro) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novo->cpf, cpf);
    novo->registro = registro;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void adicionarCPF(const char * cpf, Dados * registro) {
    No* novo = novoNo(cpf, registro);
    if (raiz == NULL) {
        raiz = novo;
        return;
    }

    No* atual = raiz;
    No* anterior = NULL;
    while (atual != NULL) {
        anterior = atual;
        if (strcmp(cpf, atual->cpf) < 0) { // Vai para a esquerda
            atual = atual->esquerda;
        } else { // Vai para a direita
            atual = atual->direita;
        }
    }

    if (strcmp(cpf, anterior->cpf) < 0) {
        anterior->esquerda = novo;
    } else {
        anterior->direita = novo;
    }
}

Dados * localizarCPF(const char* cpf) {
    No* atual = raiz;
    while (atual != NULL) {
        int cmp = strcmp(cpf, atual->cpf);
        if (cmp == 0) { // CPF encontrado
            return atual->registro;
        } else if (cmp < 0) { // Vai para a esquerda
            atual = atual->esquerda;
        } else { // Vai para a direita
            atual = atual->direita;
        }
    }
    return NULL; // CPF não encontrado
}

No* excluirNo(No* raiz, const char* cpf) {
    if (raiz == NULL) return NULL;

    int cmp = strcmp(cpf, raiz->cpf);
    if (cmp < 0) {
        raiz->esquerda = excluirNo(raiz->esquerda, cpf);
    } else if (cmp > 0) {
        raiz->direita = excluirNo(raiz->direita, cpf);
    } else { // Nó encontrado
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Encontrar o menor nó na subárvore direita
        No* temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        // Substituir os valores do nó atual
        strcpy(raiz->cpf, temp->cpf);
        raiz->registro = temp->registro;

        // Remover o menor nó na subárvore direita
        raiz->direita = excluirNo(raiz->direita, temp->cpf);
    }

    return raiz;
}

void excluirCPF(const char* cpf) {
    raiz = excluirNo(raiz, cpf);
}

void finalizar(No* atual) {
    if (atual == NULL) return;

    finalizar(atual->esquerda);
    finalizar(atual->direita);
    free(atual);
}
