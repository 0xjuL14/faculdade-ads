
let alunos = [];

document.querySelector('#cadastrar').addEventListener('click', function() {
    let nome = document.querySelector('#nomealuno').value;
    let nota1 = Number(document.querySelector('#nota1').value);
    let nota2 = Number(document.querySelector('#nota2').value);
    let frequencia = Number(document.querySelector('#frequencia').value);


    let media = (nota1 + nota2)/2;

    if(media >= 7 && frequencia >= 75) {
        situacao = "Aprovado!"
    } else if(media >= 5 && media < 7 && frequencia >= 75) {
        situacao = "Recuperação!"
    } else if(media < 5 && frequencia >= 75) {
        situacao = "Reprovado por nota :("
    } else {
        situacao = "Reprovado por frequência :("
    };

    let aluno = {
        nome: nome,
        nota1: nota1,
        nota2: nota2,
        frequencia: frequencia,
        media: media,
        situacao: situacao
    };

    alunos.push(aluno);

    function mostrarnoHTML() { // AJUSTAR AQUI MINHA CABEÇA PIFOU
        lista.innerHTML = '';

        for (aluno of alunos) {
            let tr = document.createElement('tr');

            tr.innerHTML = `<td>${aluno.nome}</td>
                            <td>${aluno.nota1}</td>
                            <td>${aluno.nota2}</td>
                            <td>${aluno.media}</td>
                            <td>${aluno.situacao}</td>`;

            console.log(lista, tr);
            lista.appendChild(tr);
        };
    };

    mostrarnoHTML();

})








// Etapa 4 – Validação
// Antes de cadastrar, verifique:
//
// Nome não pode estar vazio.
// Notas devem estar entre 0 e 10.
// Frequência deve estar entre 0 e 100.
// Valores devem ser num


// function faluno() {
//     let alunos = [
//         {nome: '', nota1: '', nota2: '', frequencia:'', media:'', situacao:''}
//     ];
//
//     function atualizarTela() {
//         let lista = '';
//
//         alunos.forEach(function (nome) {
//             lista += nome + '\n';
//         });
//
//         document.querySelector('#nomealuno').textContent = lista;
//         //document.querySelector('#qtaluno').textContent = aluno.length;
//     }
//
//     document.querySelector('#cadastrar').addEventListener('click', function(){
//         let nome = document.querySelector('#nomealuno').value;
//
//         if (nome !== null) {
//             nome = nome.trim();
//         }
//         if (nome !== ' '){
//             alunos.push(nome);
//             atualizarTela();
//         }
//     })
//
//     //document.querySelector('#remover').addEventListener('click', function(){
//     //    alunos.pop();
//     //    atualizarTela();
//     //})
//
//     //document.querySelector('#remover1').addEventListener('click', function(){
//     //    alunos.shift();
//     //    atualizarTela();
//     //})
//
//     atualizarTela();
// }
// faluno();






