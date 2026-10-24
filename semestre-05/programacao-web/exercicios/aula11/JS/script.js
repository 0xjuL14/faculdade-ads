/* ------------------------------------------------------------
   Funções de apoio (usadas em vários exercícios)
   ------------------------------------------------------------ */

// Escreve no console E na <pre> da página
function saida(idPre, texto) {
    console.log(texto);
    document.querySelector(idPre).textContent += texto + "\n";
}

// Neutraliza < > & antes de usar innerHTML (evita injeção de HTML pelo usuário)
function escapar(texto) {
    return texto.replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;");
}

/* 1) Funções */
{
    // 1ª versão (tudo dentro do calcular()):
    //   function calcular() {
    //     let a = Number(document.querySelector("#n1").value);
    //     let b = Number(document.querySelector("#n2").value);
    //     document.querySelector("#res-somar").textContent = "Resultado: " + (a + b);
    //   }

    // 2ª versão: a conta vai para somar(a, b), que DEVOLVE o valor com return
    function somar(a, b) {
        return a + b;
    }

    function calcular() {
        let a = Number(document.querySelector("#n1").value);   // Number(): input devolve texto
        let b = Number(document.querySelector("#n2").value);
        let resultado = somar(a, b);                           // chama a função e guarda o retorno
        document.querySelector("#res-somar").textContent = "Resultado: " + resultado;
    }

    // calcular SEM parênteses: passamos a função, não executamos agora
    document.querySelector("#btn-somar").addEventListener("click", calcular);
}

/* 2) Eventos com o addEventListener */
{
    const botao = document.querySelector("#btn-msg");

    botao.addEventListener("click", function () {
        let nome = document.querySelector("#nome-ev").value.trim(); // trim() tira espaços das pontas
        let area = document.querySelector("#res-msg");

        if (nome === "") {
            area.textContent = "Digite seu nome.";
        } else {
            area.textContent = "Olá, " + nome + "! Seja bem-vindo.";
        }
    });
}

/* 3e4) Formulário + preventDefault + classList  */
{
    const form = document.querySelector("#form-media");
    const resultado = document.querySelector("#res-media");

    form.addEventListener("submit", function (event) {
        event.preventDefault(); // impede o recarregamento da página

        // Limpa o estado anterior: remove TODAS as classes antes de adicionar a certa
        resultado.classList.remove("aprovado", "recuperacao", "reprovado", "erro");

        // Lemos como TEXTO primeiro, porque Number("") vira 0 e esconderia o campo vazio
        let texto1 = document.querySelector("#nota1").value;
        let texto2 = document.querySelector("#nota2").value;

        if (texto1 === "" || texto2 === "") {
            resultado.textContent = "Preencha as duas notas.";
            resultado.classList.add("erro");
            return; // sai da função: não calcula
        }

        let nota1 = Number(texto1);
        let nota2 = Number(texto2);

        if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10) {
            resultado.textContent = "As notas devem estar entre 0 e 10.";
            resultado.classList.add("erro");
            return;
        }

        let media = (nota1 + nota2) / 2;
        let situacao;
        let classe;

        if (media >= 7) {
            situacao = "Aprovado";
            classe = "aprovado";
        } else if (media >= 5) {
            situacao = "Recuperação";
            classe = "recuperacao";
        } else {
            situacao = "Reprovado";
            classe = "reprovado";
        }

        resultado.textContent = "Média: " + media.toFixed(1) + " - " + situacao;
        resultado.classList.add(classe); // o visual vem do CSS, o JS só escolhe a classe
    });
}

/* 5) Arrays*/
{
    let linguagens = ["HTML", "CSS", "JavaScript"];

    saida("#saida-5", "Primeiro item: " + linguagens[0]);
    saida("#saida-5", "Segundo item: " + linguagens[1]);
    saida("#saida-5", "Último item: " + linguagens[linguagens.length - 1]);
    saida("#saida-5", "Quantidade: " + linguagens.length);
    saida("#saida-5", "linguagens[3] antes do push: " + linguagens[3]); // undefined

    linguagens.push("React");

    saida("#saida-5", "Quantidade depois do push: " + linguagens.length);
    saida("#saida-5", "linguagens[3] depois do push: " + linguagens[3]);

    // Qual é o índice do primeiro elemento?
    // R: 0. A contagem dos índices começa no zero.

    // Por que linguagens[3] inicialmente não existe?
    // R: O array tinha 3 itens, com índices 0, 1 e 2. O índice 3 seria a
    //    "quarta gaveta", que ainda não existia, então o resultado é undefined.

    // O que acontece com length depois de utilizar push()?
    // R: push() adiciona no final, então length aumenta em 1 (de 3 para 4).
}

/* 6) Percorrendo um Array com for */
{
    let frutas = ["Maçã", "Banana", "Uva", "Laranja", "Melancia"];

    saida("#saida-6", "--- só as frutas ---");
    for (let i = 0; i < frutas.length; i++) {
        saida("#saida-6", frutas[i]);
    }

    saida("#saida-6", "--- com a posição (começa em 0) ---");
    for (let i = 0; i < frutas.length; i++) {
        saida("#saida-6", i + " - " + frutas[i]);
    }

    saida("#saida-6", "--- desafio: numeração começando em 1 ---");
    for (let i = 0; i < frutas.length; i++) {
        saida("#saida-6", (i + 1) + " - " + frutas[i]); // o array continua começando em 0, só o TEXTO soma 1
    }
}

/* 7) for...of */
{
    let frutas = ["Maçã", "Banana", "Uva", "Laranja"];

    for (let fruta of frutas) {
        saida("#saida-7", fruta);
    }

    // Qual dos dois códigos ficou menor?
    // R: o for...of. Não precisa de contador, de condição nem de frutas[i].

    // Qual deles permite acessar facilmente o número do índice?
    // R: o for clássico, porque o próprio i é o índice.

    // Se você precisar apenas do valor, qual parece mais simples?
    // R: o for...of, que entrega direto o valor de cada item.
}

/* 8) Array + DOM */
{
    let nomes = []; // fora da função pq senão zeraria a cada clique

    const campo = document.querySelector("#aluno");
    const botao = document.querySelector("#btn-add-aluno");
    const lista = document.querySelector("#lista-alunos");

    function adicionar() {
        let nome = campo.value.trim();

        if (nome === "") {
            campo.focus();
            return; // campo vazio: não adiciona
        }

        nomes.push(nome);
        campo.value = "";
        campo.focus();

        // Reconstrói a lista inteira a cada novo nome
        let html = "<p>Alunos cadastrados:</p>";
        for (let n of nomes) {
            html = html + "<p>• " + escapar(n) + "</p>";
        }
        lista.innerHTML = html;
    }

    botao.addEventListener("click", adicionar);
}

/* 9) Sistema de Compras */
{
    let produtos = []; // fora da função, para guardar entre um envio e outro

    const form = document.querySelector("#form-compras");
    const erro = document.querySelector("#erro-compras");
    const lista = document.querySelector("#lista-compras");
    const contador = document.querySelector("#qtd-compras");

    function adicionarProduto(event) {
        event.preventDefault();
        erro.textContent = "";

        // 1) ler (ainda como texto)
        let nome = document.querySelector("#produto").value.trim();
        let textoPreco = document.querySelector("#preco").value;
        let textoQtd = document.querySelector("#qtd").value;

        // 2) validar
        if (nome === "" || textoPreco === "" || textoQtd === "") {
            erro.textContent = "Preencha nome, preço e quantidade.";
            return;
        }

        // 3) converter
        let preco = Number(textoPreco);
        let qtd = Number(textoQtd);

        if (preco <= 0 || qtd <= 0) {
            erro.textContent = "Preço e quantidade devem ser maiores que zero.";
            return;
        }

        // 4) calcular e guardar como texto, como o enunciado permite
        let total = preco * qtd;
        produtos.push(nome + " - R$ " + total);

        // 5) limpar os campos
        form.reset();
        document.querySelector("#produto").focus();

        // 6) renderizar a lista inteira a partir do array
        let html = "<p><strong>Produtos adicionados:</strong></p>";
        for (let item of produtos) {
            html = html + "<p>" + escapar(item) + "</p>";
        }
        lista.innerHTML = html;

        // 7) mostrar a quantidade
        contador.textContent = "Quantidade de produtos: " + produtos.length;
    }

    form.addEventListener("submit", adicionarProduto);
}