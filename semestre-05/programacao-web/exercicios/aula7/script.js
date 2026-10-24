//console.log("JavaScript funcionando!");
/*
var nome = "Julia" // var está disponível para todo escopo
let idade = 29; // let está disponível apenas parte do escopo, específico, utiliza menos memória
const aluno = true;
console.log(nome, idade, aluno);  

if (idade >= 18) { // "1" == 1 -> TRUE "1" === 1 -> FALSE 1 == true -> TRUE 1 === true -> false
    console.log("Maior de idade!");
} 
else {
    console.log("Menor de idade");
} 
*/

const form = document.querySelector("#form");
const resultado = document.querySelector("#resultado");

form.addEventListener("submit", 
    function(event) { 
        event.preventDefault(); // Evita recarregar a página
        const nome = document.querySelector("#nome").value;
        const idade = document.querySelector("#idade").value;

        if (idade >= 18) {
            resultado.textContent = nome + ", cadastro realizado!";
            } else {
            resultado.textContent = nome + ", você é menor de idade.";
            }
        });









/*

const nome = document.querySelector("#nome").value;



document.querySelector("#titulo"); // # busca ID do elemento (único) | . busca pela classe do elemento (vários)
botao.addEventListener("click", function() { alert("Botão clicado") }); // aciona um alerta 
event.preventDefault(); // trava o recarregamento, captura os dados
//titulo.textContent = "JavaScript alterou esta página!";
*/

