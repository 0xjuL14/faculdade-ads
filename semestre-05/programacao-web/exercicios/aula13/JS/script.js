// para limpar os testes: localStorage.removeItem('aula-web-alunos-v1') e f5

const CHAVE = 'aula-web-alunos-v1'; // salvar e recuperar os dados no localStorage

let alunos = [];
let salvo = localStorage.getItem(CHAVE); // lê oq foi salvo no navegador
if (salvo) { // se foi salvo, converte o texto de volta para lista com JSON.parse
    alunos = JSON.parse(salvo);
}

const lista = document.querySelector('#lista');

function mostrarnoHTML() {
    lista.innerHTML = '';

    for (let aluno of alunos) {
        let tr = document.createElement('tr');

        tr.innerHTML = `<td>${aluno.nome}</td>
                        <td>${aluno.nota1}</td>
                        <td>${aluno.nota2}</td>
                        <td>${aluno.frequencia}%</td>
                        <td>${aluno.media}</td>
                        <td>${aluno.situacao}</td>`;

        lista.appendChild(tr);
    }
}

document.querySelector('#cadastrar').addEventListener('click', function() { // cadastramento
    let nome = document.querySelector('#nomealuno').value.trim();
    let textoNota1 = document.querySelector('#nota1').value;
    let textoNota2 = document.querySelector('#nota2').value;
    let textoFreq = document.querySelector('#frequencia').value;

    // algumas validações porque é muita coisa pra pensar:
    if (nome === '') {
        alert('O nome não pode estar vazio!');
        return;
    }

    if (textoNota1 === '' || textoNota2 === '' || textoFreq === '') {
        alert('Preencha as duas notas e a frequência!');
        return;
    }

    let nota1 = Number(textoNota1);
    let nota2 = Number(textoNota2);
    let frequencia = Number(textoFreq);

    if (isNaN(nota1) || isNaN(nota2) || isNaN(frequencia)) {
        alert('Notas e frequência devem ser números!!');
        return;
    }

    if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10) {
        alert('As notas devem estar entre 0 e 10!');
        return;
    }

    if (frequencia < 0 || frequencia > 100) {
        alert('A frequência deve estar entre 0 e 100!');
        return;
    }

    let media = (nota1 + nota2) / 2;
    let situacao;

    if (media >= 7 && frequencia >= 75) {
        situacao = "Aprovado!";
    } else if (media >= 5 && media < 7 && frequencia >= 75) {
        situacao = "Recuperação!";
    } else if (media < 5 && frequencia >= 75) {
        situacao = "Reprovado por nota :(";
    } else {
        situacao = "Reprovado por frequência :(";
    }

    let aluno = {
        nome: nome,
        nota1: nota1,
        nota2: nota2,
        frequencia: frequencia,
        media: media,
        situacao: situacao
    };

    alunos.push(aluno);
    localStorage.setItem(CHAVE, JSON.stringify(alunos)); // salva e transforma a lista em txt e guarda no localStorage
    mostrarnoHTML();
});

mostrarnoHTML();