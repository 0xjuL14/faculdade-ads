
// Ex. 4

// Ex. 3BeC
let alunos = [
    {nome: 'Julia', nota: 10}, {nome: 'Ana', nota: 5}, {nome: 'Bruno', nota: 9}
]

for (let aluno of alunos) {
    console.log("Nome: " + aluno.nome + '   | Nota: ' + aluno.nota);
}

const textoaluno = JSON.stringify(alunos);
document.getElementById("aluno").innerHTML = textoaluno;
console.log(textoaluno);

const textoaluno2 = JSON.parse(textoaluno);
console.log(textoaluno2);
document.getElementById("aluno2").innerHTML = textoaluno2; // no console da certo mas no html n deu
//typeof textoaluno = 'string'
// typeof textoaluno2 = 'object'

// Qual a diferença entre objeto e array?
// O que significa JSON?
// Qual a função do JSON.stringify()? Transforma o JS em string/texto JSON
// Qual a função do JSON.parse()? Transforma a string/texto JSON em JS novamente
// JSON é a mesma coisa que banco de dados? Não, pois pode ser manipulado e adulterado, utilizado para estruturar, armazenar e trocar dados

// Ex. 3A
let aluno = {
    nome: 'Julia',
    idade: 20,
    curso: 'ADS',
    nota: 10,
    situacao: 'aprovado'
}
// aluno.nome
// aluno.curso
// aluno.nota = 2; aluno.nota
// aluno

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

