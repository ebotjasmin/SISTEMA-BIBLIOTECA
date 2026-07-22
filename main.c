#include <stdio.h>
#include "biblioteca.h"

int main() {

    No *raiz = NULL;

    Livro livro1 = {
        100,
        "Estruturas de Dados",
        "Cormen",
        "9780262033848",
        2009,
        1
    };

    Livro livro2 = {
        50,
        "Programação em C",
        "Kernighan",
        "9780131103627",
        1988,
        1
    };

    Livro livro3 = {
        150,
        "Algoritmos",
        "Robert Sedgewick",
        "9780321573513",
        2011,
        1
    };

    raiz = inserirLivro(raiz, livro1);
    raiz = inserirLivro(raiz, livro2);
    raiz = inserirLivro(raiz, livro3);

    printf("====== LIVROS CADASTRADOS ======\n");

    listarLivros(raiz);

    printf("\n====== BUSCA ======\n");

    No *resultado = buscarLivro(raiz, 100);

    if (resultado != NULL) {
        printf("Livro encontrado: %s\n",
               resultado->livro.titulo);
    } else {
        printf("Livro não encontrado.\n");
    }

    raiz = removerLivro(raiz, 50);

    printf("\n====== APÓS REMOÇÃO ======\n");

    listarLivros(raiz);

    liberarArvore(raiz);

    return 0;
}