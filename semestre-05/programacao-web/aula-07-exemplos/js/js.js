const nome = 'Renan';
let idade = '17';
const aluno = true;

console.log(nome,idade,aluno)

if(idade >=18){
    console.log(' Maior de idade.')
}else{
    console.log(' Menor de idade.')
}

let botao = document.querySelector("#botao");


botao.addEventListener("click",function(){
    const titulo = document.querySelector("#titulo");
    titulo.textContent = "JavaScript alterou esta página!"

})


let botaoMostraNome = document.querySelector("#mostrarNome");


botaoMostraNome.addEventListener("click",function(){
    const nomeUsuario = document.querySelector("#nomeUsuario");
    const resultado = document.querySelector("#resultado");
    resultado.innerHTML = "<h1>Olá <br> "+ nomeUsuario.value + "</h1>"

})

const form = document.querySelector('form');

form.addEventListener("submit",function(event){
    event.preventDefault();
    const nome = document.querySelector('#nome').value;
    const idade = document.querySelector("#idade").value;
    const mensagem = document.querySelector("#mensagem");

    if(nome == ''){
        alert('Digite o nome');
        return;
    }

 if(idade != ''){
    if(idade >=18){
        mensagem.textContent = nome + ' Maior de idade.'
    }else{
        mensagem.textContent =  nome +' Menor de idade.'
    }
}else{
    alert('digite a idade')
}

    console.log('nome e idade',nome,idade);
    

})


const formnota = document.querySelector('#notas');

formnota.addEventListener("submit",function(event){
    event.preventDefault();
    const nome = document.querySelector('#nome').value;
    const nota1 = Number(document.querySelector('#nota1').value);
    const nota2 = Number(document.querySelector("#nota2").value);
    const mensagem = document.querySelector("#mensagem");

    const media =  (nota1 + nota2) / 2;

    if ((nota1 < 0 || nota1>10) || (nota2 < 0 || nota2>10)  ){
        alert('nota nao permitida')
    }

   /*  if (nota2 < 0 || nota2>10){
        alert('nota 2 nao permitida')
    }*/

   if(isNaN(media)){
        alert('precisa ser apenas numeros');
        return;
    }
    let situacao = 'Reprovado';
    if(media >= 7){
        situacao = 'Aprovado ' ;
    }else if(media >= 5 && media <7){
         situacao = 'Recuperação ';
    }else{
        situacao = 'Reprovado ';
    }

    const escrita = `Aluno: ${nome} <br>
Média: ${media}<br>
Situação: ${situacao}`;

mensagem.innerHTML = escrita;

})



