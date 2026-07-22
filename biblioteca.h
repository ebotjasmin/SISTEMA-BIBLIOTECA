#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define TAM_TITULO 100
#define TAM_AUTOR 100
#define TAM_ISBN 20

typedef struct {
    int id;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    char isbn[TAM_ISBN];
    int ano;
    int disponivel;
} Livro;

typedef struct No {
    Livro livro;
    struct No *esquerda;
    struct No *direita;
} No;

/* Funções da biblioteca */

No *criarNo(Livro livro);

No *inserirLivro(No *raiz, Livro livro);

No *buscarLivro(No *raiz, int id);

No *removerLivro(No *raiz, int id);

void listarLivros(No *raiz);

void liberarArvore(No *raiz);

#endif