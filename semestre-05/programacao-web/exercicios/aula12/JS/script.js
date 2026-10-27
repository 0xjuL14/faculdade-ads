// Ex. 4


// Ex. 3

/*Atividade 3 – Objetos e JSON
Objetivo: compreender como armazenar informações relacionadas em objetos e como transformá-las em JSON.

Parte A – Criando objetos
Crie um objeto chamado aluno contendo:

nome;
idade;
curso;
nota.
Depois realize as operações:

Mostre o nome no console.
Mostre o curso.
Altere a nota do aluno.
Adicione uma propriedade chamada situacao.
Mostre o objeto completo.
Parte B – Array de objetos
Crie um array chamado alunos contendo três objetos, cada um representando um aluno.

Utilize for...of para apresentar o nome e a nota de cada aluno no console.

Parte C – JSON
Utilize JSON.stringify() para transformar o array de alunos em um texto JSON.

Depois utilize JSON.parse() para transformar o texto novamente em dados JavaScript.

Verificações obrigatórias:

Mostrar o array original.
Mostrar o texto JSON gerado.
Mostrar o resultado de JSON.parse().
Comparar os tipos utilizando typeof.
Responda em comentários no código:

Qual a diferença entre objeto e array?
O que significa JSON?
Qual a função do JSON.stringify()?
Qual a função do JSON.parse()?
JSON é a mesma coisa que banco de dados? */




// Ex. 2
function participante() {
    let participantes = [];

    function atualizarTela() {
        let lista = '';

        participantes.forEach(function (nome) {
            lista += nome + '\n';
        });

        document.querySelector('#nomes').textContent = lista;
        document.querySelector('#qtdnomes').textContent = participantes.length;
    }

    document.querySelector('#adicionar').addEventListener('click', function(){
        let nome = document.querySelector('#participante').value;

        if (nome !== null) {
            nome = nome.trim();
        }
        if (nome !== ' '){
            participantes.push(nome);
            atualizarTela();
        }
    })

    document.querySelector('#remover').addEventListener('click', function(){
        participantes.pop();
        atualizarTela();
    })

    document.querySelector('#remover1').addEventListener('click', function(){
        participantes.shift();
        atualizarTela();
    })
    atualizarTela();
}
participante();
/*
Desafio adicional
Inclua um campo para pesquisar o nome de um participante.
Utilize includes() ou indexOf().
Mostre uma mensagem informando se foi encontrado.
Permita remover um nome específico utilizando indexOf() e splice().
Utilize toLowerCase() para facilitar comparações de nomes
 */


// Ex. 1D
document.querySelector('#comecar').addEventListener('click', function(){
    let opcao;

    do {
       opcao = prompt("Escolha uma opção:\n" +
           "1- Mostrar uma mensagem\n" +
           "2- Mostrar um nº aleatório\n" +
           "3- Sair...");

       switch (opcao){
           case "1":
               alert("OLAAAAAAAAAAAAAAAAAAAAAAAAA!!!!");
               break;
           case "2":
               let numero = Math.floor(Math.random() * 10) + 1;
               alert("Número da vez: " + numero);
               break;
           case "3":
               break
           default:
               alert("Opção inválida!")
               break;
       }
    } while (i !== 3);

})



// Ex. 1C
document.querySelector('#executar').addEventListener('click', function(){
    let html = '';

    for (let i = 1; i <= 20; i++) {
        if (i === 5) {
            continue;
        }

        if (i === 15) {
            break;
        }
        html = html + i + '<br>';
    }
    document.querySelector('#resultado1c').innerHTML = html;
});

// Ex. 1B
document.querySelector('#contarpar').addEventListener('click', function(){
    let limite = Number(document.querySelector('#n2').value);
    let html = '';
    let i = 1;

    for (i = 0; i <= limite; i++) {
        if(i%2 == 0 && i > 0) {
            html += ' ' +i + ' ' + '<br>';
            document.querySelector('#resultadopar').innerHTML = html;
        }
    }

})


// Ex. 1A
document.querySelector('#contar').addEventListener('click', function(){

    let limite = Number(document.querySelector('#n1').value);
    let html = '';
    let i = 1;

    //do {
    //   html = html + i + '<br>';
    //   i++;
    //} while (i <= limite);

    for (i = 0; i <= limite; i++) {
        html = html + ' '+i + ' '  + '<br>';
     }

    document.querySelector('#resultado').innerHTML = html;
})

