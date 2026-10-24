const form = document.querySelector("#form");
const resultado = document.querySelector("#resultado");

form.addEventListener("submit", 
    function(event) { 
        event.preventDefault(); // Evita recarregar a página
        const produto = document.querySelector("#produto").value; // nome do produto
        const preco = Number(document.querySelector("#preco").value); // preço original
        const perdesc = Number(document.querySelector("#perdesc").value); // percentual de desconto

        if((preco <= 0) || (perdesc <= -1)) {
            alert("Valores inválidos!");
            return; // não mostra informação caso apresentar o primeiro erro
        } 

        desconto = preco * (perdesc/100);
        valorFinal = preco - desconto;

        const escrita = `Produto: ${produto} <br>
        Preço Original: ${preco} <br>
        Valor Final: ${valorFinal}`; // shift ´ = `

        resultado.innerHTML = escrita;
        
        //document.querySelector("#resultado").textContent = "Produto: " + produto + " | Preço Original: " + preco +  " | Valor Final: " + valorFinal;
        

    });
        






    

/*
let botao = document.querySelector("#botao");
let titulo = document.querySelector("#titulo"); // # busca ID do elemento (único) | . busca pela classe do elemento (vários)
botao.addEventListener("click", function() { 
    event.preventDefault(); // trava o recarregamento, captura os dados  
    titulo.textContent = "JavaScript alterou esta página!"; }); 

    */
    