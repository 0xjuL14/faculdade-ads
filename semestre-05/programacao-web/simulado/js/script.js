const form = document.querySelector('#form-orcamento'); // busca o formulário no DOM


function formatar(numero) { // transforma 123 em R$ 123,00
  return 'R$ ' + numero.toFixed(2).replace('.', ',');
}

form.addEventListener('submit', function (event) { // click no botão
  event.preventDefault(); // evita recarregar a página

  const nome = document.querySelector('#nome').value; // le os valores do formulário, .value devolve txt
  const email = document.querySelector('#email').value;
  const servico = document.querySelector('#servico').value;

  const quantidade = Number(document.querySelector('#quantidade').value); // converter para número com Number()
  const valor = Number(document.querySelector('#valor').value);
  const adicional = Number(document.querySelector('#adicional').value);

  const valorServicos = valor * quantidade; // cálculos
  const subtotal = valorServicos + adicional;


  let desconto = 0;
  let mensagem = '';

  if (subtotal >= 500) {   // 10% de desconto a partir de R$ 500,00
    desconto = subtotal * (10 / 100);
    mensagem = 'Desconto de 10% aplicado! Seu orçamento passou de R$ 500,00!';
  } else {
    mensagem = 'Faltam ' + formatar(500 - subtotal) + ' para ganhar 10% de desconto!';
  }

  const total = subtotal - desconto;

  document.querySelector('#res-cliente').textContent = 'Cliente: ' + nome + ' (' + email + ')';   // resultado na página com .textContent
  document.querySelector('#res-servico').textContent = 'Serviço: ' + servico;
  document.querySelector('#res-calculo').textContent = 'Cálculo: ' + formatar(valor) + ' × ' + quantidade + ' = ' + formatar(valorServicos);
  document.querySelector('#res-adicional').textContent = 'Adicional: ' + formatar(adicional);
  document.querySelector('#res-subtotal').textContent = 'Subtotal: ' + formatar(subtotal);
  document.querySelector('#res-desconto').textContent = 'Desconto: ' + formatar(desconto);
  document.querySelector('#res-total').textContent = 'Total: ' + formatar(total);
  document.querySelector('#res-mensagem').textContent = mensagem;
});
