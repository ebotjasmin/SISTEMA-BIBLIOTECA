# SISTEMA-BIBLIOTECA

# 📚 Sistema de Biblioteca

Sistema de gerenciamento de livros desenvolvido em **C**, utilizando uma **Árvore Binária de Busca (BST)** para organizar e pesquisar os livros.

O projeto também possui uma interface web desenvolvida com **HTML, CSS e JavaScript**.

---

## 🎯 Objetivo

O objetivo deste projeto é desenvolver um sistema de biblioteca aplicando conceitos de:

* Programação em C;
* Estruturas de Dados;
* Árvores Binárias de Busca;
* Recursividade;
* Alocação dinâmica de memória;
* Manipulação de arquivos;
* Compilação utilizando Makefile;
* Desenvolvimento de interfaces web;
* Versionamento com Git e GitHub.

---

## 🚀 Funcionalidades

O sistema permite:

* [x] Inserir livros;
* [x] Listar livros;
* [x] Buscar livros pelo ID;
* [x] Remover livros;
* [x] Emprestar livros;
* [x] Devolver livros;
* [x] Carregar livros de um arquivo;
* [x] Salvar livros em um arquivo;
* [x] Interface web para gerenciamento visual.

---

## 🧠 Estrutura de Dados

A estrutura principal utilizada no projeto é uma **Árvore Binária de Busca**, conhecida como:

> Binary Search Tree — BST

Cada nó da árvore armazena um livro.

```text
                 100
                /   \
              50     150
             /  \       \
           25    75      200
```

A organização é feita utilizando o **ID do livro** como chave.

Para cada nó:

```text
ID menor
   ↓
subárvore esquerda

ID maior
   ↓
subárvore direita
```

---

## 📊 Complexidade

Para uma BST balanceada:

| Operação | Complexidade média | Pior caso |
| -------- | -----------------: | --------: |
| Busca    |           O(log n) |      O(n) |
| Inserção |           O(log n) |      O(n) |
| Remoção  |           O(log n) |      O(n) |

O pior caso ocorre quando a árvore fica completamente desbalanceada:

```text
100
  \
   150
     \
      200
        \
         300
```

Nesse caso, a árvore se comporta como uma lista encadeada.

---

## 📚 Estrutura do Livro

Cada livro possui:

```c
typedef struct {

    int id;

    char titulo[100];

    char autor[100];

    char isbn[20];

    int ano;

    int disponivel;

} Livro;
```

### Informações armazenadas

| Campo           | Descrição                    |
| --------------- | ---------------------------- |
| ID              | Identificador único do livro |
| Título          | Nome do livro                |
| Autor           | Autor da obra                |
| ISBN            | Código ISBN                  |
| Ano             | Ano de publicação            |
| Disponibilidade | Disponível ou emprestado     |

---

## 🌳 Estrutura do Nó

Cada nó da árvore contém um livro e dois ponteiros:

```c
typedef struct No {

    Livro livro;

    struct No *esquerda;

    struct No *direita;

} No;
```

Representação:

```text
        No
       /  \
      /    \
 esquerda  direita
```

---

## 🛠️ Tecnologias utilizadas

### Backend

* C;
* GCC;
* Makefile;
* Árvore Binária de Busca;
* Ponteiros;
* Recursividade;
* Alocação dinâmica;
* Manipulação de arquivos.

### Frontend

* HTML5;
* CSS3;
* JavaScript.

### Versionamento

* Git;
* GitHub.

---

## 📁 Estrutura do projeto

```text
SISTEMA-BIBLIOTECA/
│
├── biblioteca.c
├── biblioteca.h
├── main.c
├── Makefile
├── README.md
├── biblioteca.txt
│
├── index.html
├── style.css
└── script.js
```

---

## 📄 Arquivos do projeto

### `main.c`

Contém a função principal do programa e o menu interativo.

Responsável por:

* Inicializar a árvore;
* Carregar os livros do arquivo;
* Exibir o menu;
* Inserir livros;
* Listar livros;
* Buscar livros;
* Remover livros;
* Emprestar livros;
* Devolver livros;
* Salvar os dados ao sair.

---

### `biblioteca.h`

Contém:

* Constantes;
* Estrutura `Livro`;
* Estrutura `No`;
* Protótipos das funções.

Exemplo:

```c
typedef struct No {

    Livro livro;

    struct No *esquerda;

    struct No *direita;

} No;
```

---

### `biblioteca.c`

Contém a implementação das funções da árvore:

* Criação de nós;
* Inserção;
* Busca;
* Remoção;
* Listagem;
* Liberação da memória;
* Carregamento do arquivo;
* Salvamento do arquivo.

---

### `biblioteca.txt`

Arquivo utilizado para armazenar os livros.

Formato:

```text
ID|TITULO|AUTOR|ISBN|ANO|DISPONIBILIDADE
```

Exemplo:

```text
100|Estruturas de Dados|Cormen|9780262033848|2009|1
50|Programacao em C|Kernighan|9780131103627|1988|1
150|Algoritmos|Robert Sedgewick|9780321573513|2011|1
```

Onde:

```text
1 = Disponível

0 = Emprestado
```

---

## 💾 Persistência de dados

Quando o programa é iniciado:

```text
biblioteca.txt
       ↓
carregarArquivo()
       ↓
Árvore Binária de Busca
```

Durante a execução:

```text
Usuário
   ↓
Inserir / Remover / Emprestar / Devolver
   ↓
BST atualizada na memória
```

Quando o usuário escolhe sair:

```text
BST
 ↓
salvarArquivo()
 ↓
biblioteca.txt
```

Dessa forma, os livros permanecem armazenados mesmo depois que o programa é encerrado.

---

## 🖥️ Menu do sistema

O programa possui o seguinte menu:

```text
=====================================
       SISTEMA DE BIBLIOTECA
=====================================

1 - Inserir livro
2 - Listar livros
3 - Buscar livro
4 - Remover livro
5 - Emprestar livro
6 - Devolver livro
7 - Sair

=====================================
Escolha uma opcao:
```

---

## ➕ Inserção de livros

Ao inserir um livro, o usuário informa:

```text
ID
Título
Autor
ISBN
Ano de publicação
```

Um livro novo começa automaticamente como:

```text
Disponível
```

A inserção é realizada de acordo com o ID:

```text
Se ID < ID do nó atual
    ↓
Vai para a esquerda

Se ID > ID do nó atual
    ↓
Vai para a direita
```

---

## 🔍 Busca de livros

A busca utiliza o ID do livro.

Exemplo:

```text
Digite o ID do livro: 100
```

O algoritmo compara:

```text
100 == ID atual
```

Se for igual:

```text
Livro encontrado
```

Se for menor:

```text
Busca na subárvore esquerda
```

Se for maior:

```text
Busca na subárvore direita
```

---

## 🗑️ Remoção de livros

A remoção possui três casos principais.

### Caso 1 — Nó sem filhos

```text
     100
    /
   50
```

Removendo `50`:

```text
100
```

---

### Caso 2 — Nó com um filho

```text
     100
    /
   50
     \
      75
```

Após remover `50`:

```text
     100
     /
    75
```

---

### Caso 3 — Nó com dois filhos

```text
       100
      /   \
    50     150
          /
        125
```

Ao remover `100`, o algoritmo utiliza o sucessor em ordem.

---

## 📖 Empréstimo

Quando um livro é emprestado:

```text
Disponível
     ↓
Emprestado
```

Internamente:

```c
livro.disponivel = 0;
```

---

## 🔄 Devolução

Quando o livro é devolvido:

```text
Emprestado
     ↓
Disponível
```

Internamente:

```c
livro.disponivel = 1;
```

---

## 🧹 Gerenciamento de memória

A memória utilizada pelos nós da árvore é liberada antes do encerramento do programa.

A função:

```c
void liberarArvore(No *raiz);
```

percorre a árvore e libera todos os nós alocados dinamicamente.

A ordem é:

```text
1. Libera subárvore esquerda
2. Libera subárvore direita
3. Libera o nó atual
```

---

## ⚙️ Compilação utilizando Makefile

O projeto possui um `Makefile` para facilitar a compilação.

### Compilar

```bash
make
```

O comando compila:

```text
main.c
    ↓
main.o

biblioteca.c
    ↓
biblioteca.o

main.o + biblioteca.o
    ↓
biblioteca
```

---

### Executar

Linux:

```bash
./biblioteca
```

---

### Limpar os arquivos compilados

```bash
make clean
```

Esse comando remove:

```text
main.o
biblioteca.o
biblioteca
```

---

## 🧪 Compilação manual

Também é possível compilar sem utilizar o Makefile:

```bash
gcc -Wall -Wextra -std=c11 main.c biblioteca.c -o biblioteca
```

Depois:

```bash
./biblioteca
```

---

## 🌐 Interface Web

O projeto também possui uma interface web.

### `index.html`

Estrutura da página da aplicação.

### `style.css`

Responsável pela aparência visual.

### `script.js`

Responsável pelas interações da interface.

A interface permite:

* Cadastro de livros;
* Busca;
* Listagem;
* Empréstimo;
* Devolução;
* Remoção.

---

## 🖥️ Abrir a interface web

No Linux, execute:

```bash
xdg-open index.html
```

Ou abra o arquivo diretamente no navegador.

Também é possível utilizar o VS Code com a extensão:

```text
Live Server
```

---

## 🔀 Git

Para verificar o estado do projeto:

```bash
git status
```

Para adicionar os arquivos:

```bash
git add .
```

Para criar um commit:

```bash
git commit -m "Implementa sistema de biblioteca"
```

Para enviar para o GitHub:

```bash
git push
```

---

## 🔄 Fluxo de desenvolvimento

```text
Modificar código
       ↓
Testar
       ↓
make clean
       ↓
make
       ↓
./biblioteca
       ↓
Verificar funcionamento
       ↓
git status
       ↓
git add .
       ↓
git commit
       ↓
git push
```

---

## 🚀 Melhorias futuras

Algumas funcionalidades que podem ser adicionadas:

* [ ] Cadastro de usuários;
* [ ] Sistema completo de empréstimos;
* [ ] Data de empréstimo;
* [ ] Data de devolução;
* [ ] Controle de atrasos;
* [ ] Sistema de multas;
* [ ] Histórico de empréstimos;
* [ ] Pesquisa por título;
* [ ] Pesquisa por autor;
* [ ] Busca por prefixo;
* [ ] Sistema de login;
* [ ] Banco de dados;
* [ ] API para integração com a interface web.

---

## 🌳 Evolução das Estruturas de Dados

O projeto pode ser expandido utilizando outras estruturas estudadas:

### BST

Organização dos livros por ID.

```text
Livro
  ↓
BST
```

### Splay Tree

Livros frequentemente acessados podem ser movidos para a raiz.

```text
Livro mais acessado
        ↓
      Raiz
```

### Patricia Trie

Pode ser utilizada para buscas por:

* Título;
* Autor;
* Prefixo.

Exemplo:

```text
Estruturas...
      ↓
Patricia Trie
```

### B-Tree

Pode ser utilizada para armazenar grandes quantidades de livros.

```text
Biblioteca pequena
        ↓
       BST

Biblioteca grande
        ↓
      B-Tree
```

---

## 📈 Evolução planejada

```text
Versão 1.0
     ↓
BST para livros

Versão 2.0
     ↓
Persistência em arquivos

Versão 3.0
     ↓
Usuários e empréstimos

Versão 4.0
     ↓
Patricia Trie

Versão 5.0
     ↓
Splay Tree

Versão 6.0
     ↓
B-Tree e banco de dados
```

---

## 👨‍💻 Autor

Projeto desenvolvido para estudo de:

* Algoritmos;
* Estruturas de Dados;
* Programação em C;
* Árvores Binárias de Busca;
* Manipulação de arquivos;
* Desenvolvimento Web;
* Git e GitHub.

---

## 📄 Licença

Este projeto foi desenvolvido para fins educacionais.

---

⭐ Se este projeto foi útil para seus estudos, considere deixar uma estrela no repositório!
