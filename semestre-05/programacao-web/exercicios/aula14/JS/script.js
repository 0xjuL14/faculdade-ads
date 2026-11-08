// limpar testes: localStorage.removeItem('alunos') e f5

let alunos = lerLocal();

const lista = document.querySelector('#lista');

let indiceEdicao = null; // guarda o índice do aluno sendo editado
// null = estou cadastrando | número = estou editando esse aluno

const botaoCancelar = document.createElement('button'); // só aparece na edição
    botaoCancelar.type = 'button';
    botaoCancelar.textContent = 'Cancelar';
    botaoCancelar.style.display = 'none';
    document.querySelector('#cadastrar').after(botaoCancelar);

botaoCancelar.addEventListener('click', function() {
    sairDaEdicao(); // sai sem alterar nenhum dado
});

function sairDaEdicao() {
    indiceEdicao = null;
    document.querySelector('#cadastrar').textContent = 'Cadastrar aluno!';
    botaoCancelar.style.display = 'none';
    document.querySelector('#nomealuno').value = '';
    document.querySelector('#nota1').value = '';
    document.querySelector('#nota2').value = '';
    document.querySelector('#frequencia').value = '';
    limparEndereco();
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
        situacao: situacao,
        endereco: {
            cep: document.querySelector('#cep').value.replace(/\D/g, ''),
            rua: document.querySelector('#rua').value.trim(),
            numero: document.querySelector('#numero').value.trim(),
            complemento: document.querySelector('#complemento').value.trim(),
            bairro: document.querySelector('#bairro').value.trim(),
            cidade: document.querySelector('#cidade').value.trim(),
            uf: document.querySelector('#uf').value.trim().toUpperCase()
        }
    };

    if (indiceEdicao !== null) {
        alunos[indiceEdicao] = aluno; // sobrescreve
        sairDaEdicao();
    } else {
        alunos.push(aluno); // cadastro novo
    }
    salvarLocal(alunos);  // salva no localStorage
    mostrarnoHTML();
});


function mostrarnoHTML() {
    lista.innerHTML = '';

    for (let aluno of alunos) {
        let tr = document.createElement('tr');

        let end = aluno.endereco || {}; // aluno antigo não tem endereço
        let textoEnd = '—';
        if (end.rua) {
            textoEnd = end.rua + ', ' + end.numero + ' ' + end.complemento + ' - ' + end.bairro + ', ' + end.cidade + '/' + end.uf;
        }

        tr.innerHTML = `<td>${aluno.nome}</td>
                        <td>${aluno.nota1}</td>
                        <td>${aluno.nota2}</td>
                        <td>${aluno.frequencia}%</td>
                        <td>${aluno.media}</td>
                        <td>${aluno.situacao}</td>
                        <td>${textoEnd}</td>
                        <td><button class="editar">Editar</button> <button class="excluir">Excluir</button> </td>`

        // var aluno2 = aluno; -> eu imbecil idiota tinha deixado var e por isso não excluia qual eu queria :D
        let aluno2 = aluno;
        tr.querySelector('.editar').addEventListener('click',function(){
            indiceEdicao = alunos.indexOf(aluno2); // guarda o índice exato do aluno

            document.querySelector('#nomealuno').value = aluno2.nome; // dados atuais
            document.querySelector('#nota1').value = aluno2.nota1;
            document.querySelector('#nota2').value = aluno2.nota2;
            document.querySelector('#frequencia').value = aluno2.frequencia;

            let e = aluno2.endereco || {};
            document.querySelector('#cep').value = e.cep || '';
            document.querySelector('#rua').value = e.rua || '';
            document.querySelector('#numero').value = e.numero || '';
            document.querySelector('#complemento').value = e.complemento || '';
            document.querySelector('#bairro').value = e.bairro || '';
            document.querySelector('#cidade').value = e.cidade || '';
            document.querySelector('#uf').value = e.uf || '';


            document.querySelector('#cadastrar').textContent = 'Salvar'; // muda salvar > cancelar
            botaoCancelar.style.display = 'inline';
        });

        tr.querySelector('.excluir').addEventListener('click', function () {
            let index = alunos.indexOf(aluno2);
            alunos.splice(index,1)
            salvarLocal(alunos)
            sairDaEdicao() // evita editar um índice que mudou depois de excluir
            mostrarnoHTML()
        })

        console.log(lista,tr);
        lista.appendChild(tr);
    }
}

mostrarnoHTML();

function salvarLocal(dados){
    let dadosString = JSON.stringify(dados);
    localStorage.setItem('alunos',dadosString)
}

function lerLocal(){
    let dados = localStorage.getItem('alunos'); // lê oq foi salvo no navegador
    if(dados == null) // se foi salvo, converte o texto de volta para lista com JSON.parse
        return []
    return JSON.parse(dados);
}

async function buscarCep() { // busca de CEP
    let cep = document.querySelector('#cep').value.replace(/\D/g, ''); // tira o que n é nº
    let mensagem = document.querySelector('#mensagemcep');
    let botao = document.querySelector('#buscarcep');

    if (cep.length !== 8) {
        mensagem.textContent = 'CEP inválido!! Digite 8 números.';
        return;
    }

    mensagem.textContent = 'Consultando CEP...';
    botao.disabled = true;

    try {
        let resposta = await fetch('https://viacep.com.br/ws/' + cep + '/json/');
        if (!resposta.ok) {
            throw new Error('Erro HTTP ' + resposta.status);
        }
        let dados = await resposta.json();

        if (dados.erro) {
            mensagem.textContent = 'CEP não encontrado.';
            return;
        }
        document.querySelector('#rua').value = dados.logradouro;
        document.querySelector('#bairro').value = dados.bairro;
        document.querySelector('#cidade').value = dados.localidade;
        document.querySelector('#uf').value = dados.uf;
        mensagem.textContent = 'Endereço preenchido! Informe o número e o complemento.';
    } catch (erro) {
        mensagem.textContent = 'Falha na consulta. Verifique a conexão!';
    } finally {
        botao.disabled = false;
    }
}

document.querySelector('#buscarcep').addEventListener('click', buscarCep);

function limparEndereco() {
    document.querySelector('#cep').value = '';
    document.querySelector('#rua').value = '';
    document.querySelector('#numero').value = '';
    document.querySelector('#complemento').value = '';
    document.querySelector('#bairro').value = '';
    document.querySelector('#cidade').value = '';
    document.querySelector('#uf').value = '';
    document.querySelector('#mensagemcep').textContent = '';
}





