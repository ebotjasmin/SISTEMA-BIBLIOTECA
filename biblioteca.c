#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

/* ============================================
   CRIAÇÃO DE UM NOVO NÓ
   ============================================ */

No *criarNo(Livro livro) {

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: memória insuficiente.\n");
        exit(EXIT_FAILURE);
    }

    novo->livro = livro;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}


/* ============================================
   INSERÇÃO DE LIVRO NA BST
   ============================================ */

No *inserirLivro(No *raiz, Livro livro) {

    if (raiz == NULL) {
        return criarNo(livro);
    }

    if (livro.id < raiz->livro.id) {

        raiz->esquerda =
            inserirLivro(raiz->esquerda, livro);

    } else if (livro.id > raiz->livro.id) {

        raiz->direita =
            inserirLivro(raiz->direita, livro);

    } else {

        printf("Erro: já existe um livro com esse ID.\n");
    }

    return raiz;
}


/* ============================================
   BUSCA DE LIVRO
   ============================================ */

No *buscarLivro(No *raiz, int id) {

    if (raiz == NULL) {
        return NULL;
    }

    if (id == raiz->livro.id) {
        return raiz;
    }

    if (id < raiz->livro.id) {
        return buscarLivro(raiz->esquerda, id);
    }

    return buscarLivro(raiz->direita, id);
}


/* ============================================
   MENOR NÓ DA ÁRVORE
   ============================================ */

No *menorNo(No *raiz) {

    No *atual = raiz;

    while (atual != NULL &&
           atual->esquerda != NULL) {

        atual = atual->esquerda;
    }

    return atual;
}


/* ============================================
   REMOÇÃO DE LIVRO
   ============================================ */

No *removerLivro(No *raiz, int id) {

    if (raiz == NULL) {
        return NULL;
    }

    if (id < raiz->livro.id) {

        raiz->esquerda =
            removerLivro(raiz->esquerda, id);

    } else if (id > raiz->livro.id) {

        raiz->direita =
            removerLivro(raiz->direita, id);

    } else {

        /*
         * Caso 1:
         * Nó sem filho esquerdo
         */

        if (raiz->esquerda == NULL) {

            No *aux = raiz->direita;

            free(raiz);

            return aux;
        }

        /*
         * Caso 2:
         * Nó sem filho direito
         */

        if (raiz->direita == NULL) {

            No *aux = raiz->esquerda;

            free(raiz);

            return aux;
        }

        /*
         * Caso 3:
         * Nó com dois filhos
         */

        No *sucessor =
            menorNo(raiz->direita);

        raiz->livro =
            sucessor->livro;

        raiz->direita =
            removerLivro(
                raiz->direita,
                sucessor->livro.id
            );
    }

    return raiz;
}


/* ============================================
   LISTAGEM EM ORDEM
   ============================================ */

void listarLivros(No *raiz) {

    if (raiz == NULL) {
        return;
    }

    listarLivros(raiz->esquerda);

    printf("\n");
    printf("ID: %d\n", raiz->livro.id);
    printf("Título: %s\n", raiz->livro.titulo);
    printf("Autor: %s\n", raiz->livro.autor);
    printf("ISBN: %s\n", raiz->livro.isbn);
    printf("Ano: %d\n", raiz->livro.ano);

    if (raiz->livro.disponivel) {
        printf("Status: Disponível\n");
    } else {
        printf("Status: Emprestado\n");
    }

    printf("-----------------------------\n");

    listarLivros(raiz->direita);
}


/* ============================================
   LIBERAÇÃO DA MEMÓRIA
   ============================================ */

void liberarArvore(No *raiz) {

    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);

    liberarArvore(raiz->direita);

    free(raiz);
}



/* ============================================
   CARREGAR LIVROS DO ARQUIVO
   ============================================ */

No *carregarArquivo(No *raiz, FILE *arquivo) {

    Livro livro;

    while (fscanf(
        arquivo,
        "%d|%99[^|]|%99[^|]|%19[^|]|%d|%d\n",
        &livro.id,
        livro.titulo,
        livro.autor,
        livro.isbn,
        &livro.ano,
        &livro.disponivel
    ) == 6) {

        raiz = inserirLivro(raiz, livro);
    }

    return raiz;
}


/* ============================================
   SALVAR LIVROS NO ARQUIVO
   ============================================ */

void salvarArquivo(No *raiz, FILE *arquivo) {

    if (raiz == NULL) {

        return;
    }

    salvarArquivo(raiz->esquerda, arquivo);

    fprintf(
        arquivo,
        "%d|%s|%s|%s|%d|%d\n",
        raiz->livro.id,
        raiz->livro.titulo,
        raiz->livro.autor,
        raiz->livro.isbn,
        raiz->livro.ano,
        raiz->livro.disponivel
    );

    salvarArquivo(raiz->direita, arquivo);
}