// ============================================
// SISTEMA DE BIBLIOTECA
// ============================================


// ============================================
// ELEMENTOS DO HTML
// ============================================

const formulario = document.getElementById("form-livro");

const campoId = document.getElementById("id");
const campoTitulo = document.getElementById("titulo");
const campoAutor = document.getElementById("autor");
const campoIsbn = document.getElementById("isbn");
const campoAno = document.getElementById("ano");

const campoBusca = document.getElementById("campo-busca");
const btnBuscar = document.getElementById("btn-buscar");

const listaLivros = document.getElementById("lista-livros");
const totalLivros = document.getElementById("total-livros");


// ============================================
// ARRAY DE LIVROS
// ============================================

let livros = [];


// ============================================
// CADASTRAR LIVRO
// ============================================

formulario.addEventListener("submit", function (evento) {

    evento.preventDefault();


    const id = Number(campoId.value);

    const titulo = campoTitulo.value.trim();

    const autor = campoAutor.value.trim();

    const isbn = campoIsbn.value.trim();

    const ano = Number(campoAno.value);


    // Verifica se o ID já existe

    const livroExistente = livros.find(function (livro) {

        return livro.id === id;

    });


    if (livroExistente) {

        alert("Já existe um livro com esse ID.");

        return;
    }


    const livro = {

        id: id,

        titulo: titulo,

        autor: autor,

        isbn: isbn,

        ano: ano,

        disponivel: true

    };


    livros.push(livro);


    salvarLivros();


    mostrarLivros();


    formulario.reset();


    alert("Livro cadastrado com sucesso!");

});


// ============================================
// MOSTRAR LIVROS
// ============================================

function mostrarLivros(lista = livros) {


    listaLivros.innerHTML = "";


    if (lista.length === 0) {

        listaLivros.innerHTML = `

            <p class="mensagem-vazia">

                Nenhum livro encontrado.

            </p>

        `;

        atualizarTotal(lista);

        return;
    }


    lista.forEach(function (livro) {


        const elementoLivro =
            document.createElement("div");


        elementoLivro.classList.add("livro");


        elementoLivro.innerHTML = `

            <div class="informacoes-livro">

                <h3>
                    ${livro.titulo}
                </h3>

                <p>
                    <strong>ID:</strong>
                    ${livro.id}
                </p>

                <p>
                    <strong>Autor:</strong>
                    ${livro.autor}
                </p>

                <p>
                    <strong>ISBN:</strong>
                    ${livro.isbn}
                </p>

                <p>
                    <strong>Ano:</strong>
                    ${livro.ano}
                </p>

                <p>

                    <strong>Status:</strong>

                    <span class="${livro.disponivel
                        ? "disponivel"
                        : "emprestado"}">

                        ${livro.disponivel
                            ? "Disponível"
                            : "Emprestado"}

                    </span>

                </p>

            </div>


            <div class="acoes-livro">

                <button
                    class="btn-emprestar"
                    onclick="alternarDisponibilidade(${livro.id})">

                    ${livro.disponivel
                        ? "Emprestar"
                        : "Devolver"}

                </button>


                <button
                    class="btn-remover"
                    onclick="removerLivro(${livro.id})">

                    Remover

                </button>

            </div>

        `;


        listaLivros.appendChild(elementoLivro);

    });


    atualizarTotal(lista);

}


// ============================================
// BUSCAR LIVROS
// ============================================

function buscarLivros() {


    const termo =
        campoBusca.value.toLowerCase().trim();


    const resultado = livros.filter(function (livro) {


        return (

            livro.titulo
                .toLowerCase()
                .includes(termo)

            ||

            livro.autor
                .toLowerCase()
                .includes(termo)

            ||

            livro.isbn
                .toLowerCase()
                .includes(termo)

        );

    });


    mostrarLivros(resultado);

}


// ============================================
// EVENTOS DE BUSCA
// ============================================

btnBuscar.addEventListener(
    "click",
    buscarLivros
);


campoBusca.addEventListener(
    "input",
    buscarLivros
);


// ============================================
// EMPRESTAR / DEVOLVER
// ============================================

function alternarDisponibilidade(id) {


    const livro =
        livros.find(function (livro) {

            return livro.id === id;

        });


    if (!livro) {

        return;
    }


    livro.disponivel =
        !livro.disponivel;


    salvarLivros();


    mostrarLivros();

}


// ============================================
// REMOVER LIVRO
// ============================================

function removerLivro(id) {


    const confirmar =
        confirm(
            "Deseja realmente remover este livro?"
        );


    if (!confirmar) {

        return;
    }


    livros =
        livros.filter(function (livro) {

            return livro.id !== id;

        });


    salvarLivros();


    mostrarLivros();

}


// ============================================
// ATUALIZAR CONTADOR
// ============================================

function atualizarTotal(lista) {


    totalLivros.textContent =

        `${lista.length} livro(s)`;

}


// ============================================
// SALVAR NO NAVEGADOR
// ============================================

function salvarLivros() {


    localStorage.setItem(

        "livros",

        JSON.stringify(livros)

    );

}


// ============================================
// CARREGAR LIVROS
// ============================================

function carregarLivros() {


    const dados =
        localStorage.getItem("livros");


    if (dados) {


        livros =
            JSON.parse(dados);


    }


    mostrarLivros();

}


// ============================================
// INICIALIZAÇÃO
// ============================================

carregarLivros();