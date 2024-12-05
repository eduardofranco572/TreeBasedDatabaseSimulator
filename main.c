#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "lista.h"
#include "lista_dupla.h"

enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_ALTERAR,
    OP_EXCLUIR,
    OP_PROCURAR,
    OP_RELATORIO,
    OP_SAIR
};

int menu();

int main(void) {
    int opcao = OP_NAO_SELECIONADA;

    inicializar();
    inicializarLista();
    inicializarListaDupla();

    while (opcao != OP_SAIR) {
        opcao = menu();

        switch (opcao) {
            case OP_ADICIONAR: {
                Dados dados;

                printf("Insira o CPF (xxx.xxx.xxx-xx):\n");
                fgets(dados.cpf, 16, stdin);
                dados.cpf[strcspn(dados.cpf, "\n")] = '\0';

                // Verificar se o CPF já existe na árvore binária
                if (localizarCPF(dados.cpf) != NULL) {
                    printf("CPF ja cadastrado.\n");
                } else {
                    // Solicitar os outros dados
                    printf("Insira o nome:\n");
                    fgets(dados.nome, 80, stdin);
                    dados.nome[strcspn(dados.nome, "\n")] = '\0';

                    printf("Insira o endereco:\n");
                    fgets(dados.endereco, 200, stdin);
                    dados.endereco[strcspn(dados.endereco, "\n")] = '\0';

                    printf("Insira o telefone (xx)xxxxx-xxxx:\n");
                    fgets(dados.telefone, 16, stdin);
                    dados.telefone[strcspn(dados.telefone, "\n")] = '\0';

                    printf("Insira o email:\n");
                    fgets(dados.email, 120, stdin);
                    dados.email[strcspn(dados.email, "\n")] = '\0';

                    // Adicionar à lista dinâmica e obter o número do registro
                    Dados * registro = addLista(dados);

                    // Adicionar na árvore binária e lista duplamente ligada
                    adicionarCPF(dados.cpf, registro);
                    adicionarOrdenado(registro,registro->nome);

                    printf("Cadastro realizado com sucesso.\n");
                }
                break;
            }
            case OP_ALTERAR: {
                char cpf[15];
                printf("Insira o CPF para alterar:\n");
                fgets(cpf, 16, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';


                Dados * registro = localizarCPF(cpf);
                if (registro == NULL) {
                    printf("CPF nao cadastrado.\n");
                } else {
                    Dados novosDados;
                    printf("Insira o novo nome:\n");
                    fgets(novosDados.nome, 80, stdin);
                    novosDados.nome[strcspn(novosDados.nome, "\n")] = '\0';

                    printf("Insira o novo endereco:\n");
                    fgets(novosDados.endereco, 200, stdin);
                    novosDados.endereco[strcspn(novosDados.endereco, "\n")] = '\0';

                    printf("Insira o novo telefone (xx)xxxxx-xxxx:\n");
                    fgets(novosDados.telefone, 16, stdin);
                    novosDados.telefone[strcspn(novosDados.telefone, "\n")] = '\0';

                    printf("Insira o novo email:\n");
                    fgets(novosDados.email, 120, stdin);
                    novosDados.email[strcspn(novosDados.email, "\n")] = '\0';

                    if(strcmp(registro->nome,novosDados.nome) != 0){
                        // Atualizar o nome na lista duplamente ligada
                        excluirListaDupla(registro->nome);
                        // Atualizar os dados na lista dinâmica
                        alterarLista(registro, &novosDados);
                        adicionarOrdenado(registro,registro->nome);
                    } else {
                        alterarLista(registro, &novosDados);
                    }

                    printf("Dados alterados com sucesso.\n");
                }
                break;
            }
            case OP_EXCLUIR: {
                char cpf[15];
                printf("Insira o CPF para excluir:\n");
                fgets(cpf, 16, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';

                Dados * registro = localizarCPF(cpf);
                if (registro == NULL) {
                    printf("CPF nao cadastrado.\n");
                } else {
                    // Remover da árvore binária e lista duplamente ligada

                    excluirListaDupla(registro->nome);
                    excluirCPF(cpf);

                    printf("Registro excluido com sucesso.\n");
                }
                break;
            }
            case OP_PROCURAR: {
                char cpf[15];
                printf("Insira o CPF para procurar:\n");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = '\0';

                Dados * registro = localizarCPF(cpf);
                if (registro == NULL) {
                    printf("CPF nao cadastrado.\n");
                } else {
                    // Exibir os dados da lista dinâmica
                    printf("Nome: %s\n", registro->nome);
                    printf("Endereco: %s\n", registro->endereco);
                    printf("Telefone: %s\n", registro->telefone);
                    printf("Email: %s\n", registro->email);
                }
                break;
            }
            case OP_RELATORIO: {
                imprimirLista();
                break;
            }
            case OP_SAIR:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    }

    return EXIT_SUCCESS;
}

int menu() {
    int op = OP_NAO_SELECIONADA;
    printf("\nMenu\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Alterar\n", OP_ALTERAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Procurar\n", OP_PROCURAR);
    printf("%d - Relatorio\n", OP_RELATORIO);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao:\n");
    scanf("%d%*c", &op);

    return op;
}
