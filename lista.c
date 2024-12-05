#include "Lista.h"

#include <stdio.h>
#include <string.h>

// Variáveis
Dados * lista = NULL;
int posicao = 0;
int tamanho = 5;

// Funções
Dados * addLista(Dados valor) {

    if (posicao == tamanho) {
        expand();
    }
    lista[posicao] = valor;
    posicao++;
    return &lista[posicao-1];
}

int size() {
    return posicao;
}

bool searchByIndex(int indice, Dados * valor)
{
    if(indice < 0 || indice >= posicao) {
        return false;
    }
    *valor = lista[indice];
    return true;
}

int searchByValue(Dados valor) {
    int retorno = -1;
    for(int i = 0; i < posicao; i++) {
        if(strcmp(lista[i].cpf,valor.cpf) == 0) {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void delete(Dados valor)
{
    int indice = searchByValue(valor);
    if(indice == -1) {
        return;
    }
    for(int i = indice; i < posicao - 1; i++) {
        lista[i] = lista[i + 1];
    }
    posicao--;
}

void sort() {
    Dados temp;
    for(int i = 0; i < posicao - 1; i++) {
        for(int j = i + 1; j < posicao; j++) {
            if(strcmp(lista[i].nome,lista[j].nome) > 0) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

bool alterarLista(Dados * registro, Dados * valor) {
    strcpy(registro->nome,valor->nome);
    strcpy(registro->email,valor->email);
    strcpy(registro->endereco,valor->endereco);
    strcpy(registro->telefone,valor->telefone);
    return true;
}

void inicializarLista() {
    lista = malloc(tamanho * sizeof(Dados));
    if(!lista) {
        printf("Erro alocando memoria\n");
        exit(EXIT_FAILURE);
    }
}

void destroy() {
    free(lista);
}

void expand() {
    Dados *temp;

    tamanho = tamanho + 5;

    temp = malloc(tamanho * sizeof(Dados));
    if(!temp) {
        printf("Erro alocando memoria\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < posicao; i++) {
        temp[i] = lista[i];
    }


    lista = temp;
    free(lista);
}