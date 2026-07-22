#include <stdio.h>
#include "biblioteca.h"

int main() {

    No *raiz = NULL;
    No *livroEncontrado;

    FILE *arquivo;

    int opcao;

    /*
     * Carrega os livros existentes no arquivo
     */

    arquivo = fopen("biblioteca.txt", "r");

    if (arquivo != NULL) {

        raiz = carregarArquivo(raiz, arquivo);

        fclose(arquivo);
    }


    do {

        printf("\n=====================================\n");
        printf("       SISTEMA DE BIBLIOTECA\n");
        printf("=====================================\n");

        printf("1 - Inserir livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro\n");
        printf("4 - Remover livro\n");
        printf("5 - Emprestar livro\n");
        printf("6 - Devolver livro\n");
        printf("7 - Sair\n");

        printf("=====================================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);


        switch (opcao) {


        /* =================================
           INSERIR LIVRO
           ================================= */

        case 1: {

            Livro livro;

            printf("\n===== CADASTRO DE LIVRO =====\n");

            printf("ID: ");
            scanf("%d", &livro.id);

            /*
             * Verifica se o ID já existe
             */

            if (buscarLivro(raiz, livro.id) != NULL) {

                printf("\nJa existe um livro com esse ID.\n");

                break;
            }


            printf("Titulo: ");

            scanf(" %99[^\n]",
                  livro.titulo);


            printf("Autor: ");

            scanf(" %99[^\n]",
                  livro.autor);


            printf("ISBN: ");

            scanf(" %19s",
                  livro.isbn);


            printf("Ano de publicacao: ");

            scanf("%d",
                  &livro.ano);


            /*
             * Todo livro novo começa disponível
             */

            livro.disponivel = 1;


            raiz = inserirLivro(
                raiz,
                livro
            );


            printf("\nLivro cadastrado com sucesso.\n");

            break;
        }


        /* =================================
           LISTAR LIVROS
           ================================= */

        case 2:

            printf("\n===== LIVROS CADASTRADOS =====\n");


            if (raiz == NULL) {

                printf("A biblioteca esta vazia.\n");

            } else {

                listarLivros(raiz);
            }

            break;


        /* =================================
           BUSCAR LIVRO
           ================================= */

        case 3: {

            int id;


            printf("\nDigite o ID do livro: ");

            scanf("%d",
                  &id);


            livroEncontrado =
                buscarLivro(
                    raiz,
                    id
                );


            if (livroEncontrado == NULL) {

                printf("\nLivro nao encontrado.\n");

            } else {

                printf("\n===== LIVRO ENCONTRADO =====\n");

                printf("ID: %d\n",
                       livroEncontrado->livro.id);

                printf("Titulo: %s\n",
                       livroEncontrado->livro.titulo);

                printf("Autor: %s\n",
                       livroEncontrado->livro.autor);

                printf("ISBN: %s\n",
                       livroEncontrado->livro.isbn);

                printf("Ano: %d\n",
                       livroEncontrado->livro.ano);


                if (livroEncontrado->livro.disponivel) {

                    printf("Status: Disponivel\n");

                } else {

                    printf("Status: Emprestado\n");
                }
            }

            break;
        }


        /* =================================
           REMOVER LIVRO
           ================================= */

        case 4: {

            int id;


            printf("\nID do livro a remover: ");

            scanf("%d",
                  &id);


            livroEncontrado =
                buscarLivro(
                    raiz,
                    id
                );


            if (livroEncontrado == NULL) {

                printf("\nLivro nao encontrado.\n");

            } else {

                raiz =
                    removerLivro(
                        raiz,
                        id
                    );


                printf("\nLivro removido com sucesso.\n");
            }

            break;
        }


        /* =================================
           EMPRESTAR LIVRO
           ================================= */

        case 5: {

            int id;


            printf("\nID do livro: ");

            scanf("%d",
                  &id);


            livroEncontrado =
                buscarLivro(
                    raiz,
                    id
                );


            if (livroEncontrado == NULL) {

                printf("\nLivro nao encontrado.\n");

            } else if (!livroEncontrado->livro.disponivel) {

                printf("\nO livro ja esta emprestado.\n");

            } else {

                livroEncontrado->livro.disponivel = 0;

                printf("\nLivro emprestado com sucesso.\n");
            }

            break;
        }


        /* =================================
           DEVOLVER LIVRO
           ================================= */

        case 6: {

            int id;


            printf("\nID do livro: ");

            scanf("%d",
                  &id);


            livroEncontrado =
                buscarLivro(
                    raiz,
                    id
                );


            if (livroEncontrado == NULL) {

                printf("\nLivro nao encontrado.\n");

            } else if (livroEncontrado->livro.disponivel) {

                printf("\nO livro ja esta disponivel.\n");

            } else {

                livroEncontrado->livro.disponivel = 1;

                printf("\nLivro devolvido com sucesso.\n");
            }

            break;
        }


        /* =================================
           SAIR E SALVAR
           ================================= */

        case 7:

            arquivo =
                fopen(
                    "biblioteca.txt",
                    "w"
                );


            if (arquivo == NULL) {

                printf("\nErro ao salvar arquivo.\n");

            } else {

                salvarArquivo(
                    raiz,
                    arquivo
                );


                fclose(arquivo);


                printf("\nLivros salvos com sucesso.\n");
            }


            printf("\nPrograma encerrado.\n");

            break;


        default:

            printf("\nOpcao invalida.\n");
        }


    } while (opcao != 7);


    /*
     * Libera a memória da árvore
     */

    liberarArvore(raiz);


    return 0;
}