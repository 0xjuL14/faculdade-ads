// limpar testes: localStorage.removeItem('alunos') e f5

let alunos = lerLocal(); // BASE ORIGINAL: nunca é ordenada nem trocada pela lista filtrada!!!!

const lista = document.querySelector('#lista');
const inputBusca = document.querySelector('#busca');
const selectSituacao = document.querySelector('#filtrosituacao');
const selectOrdem = document.querySelector('#ordem');
const contador = document.querySelector('#contador');

let idEdicao = null; // guarda o ID do aluno sendo editado
// null = estou cadastrando | número = estou editando o aluno com esse id

const botaoCancelar = document.createElement('button'); // só aparece na edição
    botaoCancelar.type = 'button';
    botaoCancelar.textContent = 'Cancelar';
    botaoCancelar.style.display = 'none';
    document.querySelector('#cadastrar').after(botaoCancelar);

botaoCancelar.addEventListener('click', function() {
    sairDaEdicao(); // sai sem alterar nenhum dado
});

function sairDaEdicao() {
    idEdicao = null;
    document.querySelector('#cadastrar').textContent = 'Cadastrar aluno!';
    botaoCancelar.style.display = 'none';
    document.querySelector('#nomealuno').value = '';
    document.querySelector('#nota1').value = '';
    document.querySelector('#nota2').value = '';
    document.querySelector('#frequencia').value = '';
    limparEndereco();
}

function calcularSituacao(aluno) { // situação calculada por função
    if (aluno.frequencia < 75) {
        return 'Reprovado por frequência'; // cada return sai da função, então a ordem dos ifs já garante o resto
    }
    if (aluno.media < 5) { // se passou do 1º if, a frequência é >= 75; se passou do 2º, a média é >= 5
        return 'Reprovado por nota';
    }
    if (aluno.media < 7) {
        return 'Recuperação';
    }
    return 'Aprovado';
}

function proximoId() { // id novo = maior id que existe + 1, assim nunca repete, mesmo depois de excluir
    let maior = 0;
    for (const a of alunos) {
        if (a.id > maior) maior = a.id;
    }
    return maior + 1;
}

function mediaMinima6(aluno) { // função normal
    return aluno.media >= 6;
}

const mediaMinima6Arrow = aluno => aluno.media >= 6; // função arrow function com retorno, sem chaves

const mediaMinima6Chaves = aluno => { // função arrow function com chaves = return é obrigatório
    return aluno.media >= 6; // se tirar o return da versão com chaves, a função retorna undefined
}; // no filter, undefined conta como falso = a lista volta vazia

// comparando os retornos no console ao abrir a pág
console.log('forEach retorna:', alunos.forEach(aluno => aluno.nome)); // undefined
console.log('map retorna:', alunos.map(aluno => aluno.nome)); // array novo, mesmo tamanho
console.log('filter retorna:', alunos.filter(mediaMinima6)); // array novo só com quem passou (ou [])
console.log('find retorna:', alunos.find(mediaMinima6Arrow)); // o 1º objeto que passou (ou undefined)
console.log('sem return:', alunos.filter(aluno => { aluno.media >= 6; })); // [] porque tudo vira undefined

// cadastro
document.querySelector('#cadastrar').addEventListener('click', function() {
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

    let aluno = {
        id: null, // array
        nome: nome,
        nota1: nota1,
        nota2: nota2,
        frequencia: frequencia,
        media: (nota1 + nota2) / 2,
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

    if (idEdicao !== null) {
        aluno.id = idEdicao; // edição = mantém o mesmo id
        alunos = alunos.map(a => a.id === idEdicao ? aluno : a); // troca só o aluno com esse id, os outros voltam iguais
        sairDaEdicao();
    } else {
        aluno.id = proximoId(); // cadastro novo
        alunos.push(aluno);
    }
    salvarLocal(alunos); // salva a base completa, nunca a lista filtrada!!!!
    atualizarTela();
});

// o fluxo é base original -> filtros -> cópia/ordenação -> renderizar lista
function atualizarTela() {
    const termoBusca = inputBusca.value.trim().toLowerCase(); // busca normalizada, A -> a
    const filtroSit = selectSituacao.value;

    const filtrados = alunos.filter(aluno => { // nome & situação = todos: deixa qualquer situação passar)
        const bateuNome = aluno.nome.toLowerCase().includes(termoBusca);
        const bateuSit = filtroSit === 'Todos' || calcularSituacao(aluno) === filtroSit;
        return bateuNome && bateuSit;
    });

    const copia = filtrados.slice();  // ordenação sempre numa CÓPIA!!!! > sort altera o array em que é chamado <
    const ordem = selectOrdem.value;
    if (ordem === 'nome') {
        copia.sort((a, b) => a.nome.localeCompare(b.nome));
    } else if (ordem === 'cresc') {
        copia.sort((a, b) => a.media - b.media); // negativo = a antes de b
    } else if (ordem === 'decresc') {
        copia.sort((a, b) => b.media - a.media);
    }

    if (ordem !== 'cadastro') { // cadastro n ordena nada, igual a ordem da base
        console.log('Base original depois de ordenar (a ordem tem que continuar a do cadastro):');
        console.table(alunos);
    }

    if (copia.length === 0) {
        contador.textContent = 'Nenhum aluno encontrado!';
    } else {
        contador.textContent = 'Resultados: ' + copia.length;
    }

    renderizar(copia);
}

function criarTd(texto) { // cria um td com textContent > o texto nunca é interpretado como HTML <
    const td = document.createElement('td');
    td.textContent = texto;
    return td;
}

function renderizar(listaAlunos) {
    lista.innerHTML = ''; // limpa a tabela antes de montar de novo

    if (listaAlunos.length === 0) {
        const tr = document.createElement('tr');
        const td = criarTd('Nenhum aluno encontrado');
        td.colSpan = 9;
        tr.appendChild(td);
        lista.appendChild(tr);
        return;
    }

    for (const aluno of listaAlunos) {
        const tr = document.createElement('tr');

        let end = aluno.endereco || {}; // os alunos da base de teste não tem endereço
        let textoEnd = '—';
        if (end.rua) {
            textoEnd = end.rua + ', ' + end.numero + ' ' + end.complemento + ' - ' + end.bairro + ', ' + end.cidade + '/' + end.uf;
        }

        tr.appendChild(criarTd(aluno.id));
        tr.appendChild(criarTd(aluno.nome));
        tr.appendChild(criarTd(aluno.nota1 === undefined ? '—' : aluno.nota1)); // os alunos da base de teste n tem notas
        tr.appendChild(criarTd(aluno.nota2 === undefined ? '—' : aluno.nota2));
        tr.appendChild(criarTd(aluno.frequencia + '%'));
        tr.appendChild(criarTd(aluno.media));
        tr.appendChild(criarTd(calcularSituacao(aluno)));
        tr.appendChild(criarTd(textoEnd));

        const botaoEditar = document.createElement('button');
        botaoEditar.type = 'button';
        botaoEditar.textContent = 'Editar';

        const botaoExcluir = document.createElement('button');
        botaoExcluir.type = 'button';
        botaoExcluir.textContent = 'Excluir';

        const tdOpcoes = document.createElement('td');
        tdOpcoes.appendChild(botaoEditar);
        tdOpcoes.append(' ');
        tdOpcoes.appendChild(botaoExcluir);
        tr.appendChild(tdOpcoes);

        botaoEditar.addEventListener('click', function() {
            idEdicao = aluno.id; // guarda o ID, não a posição na tela

            document.querySelector('#nomealuno').value = aluno.nome; // dados atuais
            document.querySelector('#nota1').value = aluno.nota1 === undefined ? '' : aluno.nota1;
            document.querySelector('#nota2').value = aluno.nota2 === undefined ? '' : aluno.nota2;
            document.querySelector('#frequencia').value = aluno.frequencia;

            let e = aluno.endereco || {};
            document.querySelector('#cep').value = e.cep || '';
            document.querySelector('#rua').value = e.rua || '';
            document.querySelector('#numero').value = e.numero || '';
            document.querySelector('#complemento').value = e.complemento || '';
            document.querySelector('#bairro').value = e.bairro || '';
            document.querySelector('#cidade').value = e.cidade || '';
            document.querySelector('#uf').value = e.uf || '';

            document.querySelector('#cadastrar').textContent = 'Salvar';
            botaoCancelar.style.display = 'inline';
        });

        botaoExcluir.addEventListener('click', function() {  // fica geral, menos o aluno com esse id
            alunos = alunos.filter(a => a.id !== aluno.id);
            salvarLocal(alunos);
            sairDaEdicao(); // evita salvar a edição de um aluno que não existe mais
            atualizarTela();
        });

        lista.appendChild(tr);
    }
}

inputBusca.addEventListener('input', atualizarTela); // eventos: input a cada letra digitada, change quando escolhe no select
selectSituacao.addEventListener('change', atualizarTela);
selectOrdem.addEventListener('change', atualizarTela);

document.querySelector('#limpar').addEventListener('click', function() {
    inputBusca.value = '';
    selectSituacao.value = 'Todos';
    selectOrdem.value = 'cadastro';
    atualizarTela();
});

document.querySelector('#consultarid').addEventListener('click', function() { // find pra encontrar aluno por id
    const resultadoId = document.querySelector('#resultadoid');
    const id = Number(document.querySelector('#buscaid').value); // .value é sempre texto, '3' === 3 dá false, por isso o Number()

    const encontrado = alunos.find(aluno => aluno.id === id); // procura pelo id e n pela posição

    if (encontrado === undefined) { // find retorna UM objeto ou undefined (filter retornaria um array, mesmo vazio)
        resultadoId.textContent = 'Aluno não encontrado';
    } else {
        resultadoId.textContent = 'ID ' + encontrado.id + ' — ' + encontrado.nome +
            ' — média ' + encontrado.media + ' — frequência ' + encontrado.frequencia + '% — ' +
            calcularSituacao(encontrado);
    }
});

document.querySelector('#gerarrelatorio').addEventListener('click', function() { // transforma dados com map
    const relatorio = alunos.map(aluno => ({ // ({}) = JS entende q é um objeto e n um bloco
        nome: aluno.nome, // objetos novos, os originais em alunos não mudam
        media: aluno.media,
        situacao: calcularSituacao(aluno)
    }));

    console.table(relatorio);

    const ul = document.querySelector('#relatorio');
    ul.innerHTML = '';
    for (const item of relatorio) { // mostrar no html o relatório, dai se usa for..of
        const li = document.createElement('li');
        li.textContent = item.nome + ' — média ' + item.media + ' — ' + item.situacao;
        ul.appendChild(li);
    }
});

atualizarTela(); // primeira renderização

function salvarLocal(dados){
    let dadosString = JSON.stringify(dados);
    localStorage.setItem('alunos-aula15', dadosString)
}

function lerLocal(){
    let dados = localStorage.getItem('alunos-aula15'); // lê oq foi salvo no navegador
    if(dados == null) { // nada salvo ainda: começa com a base de teste
        return [
            { id: 1, nome: 'Ana',    media: 8.5, frequencia: 80 },
            { id: 2, nome: 'Bruno',  media: 4,   frequencia: 90 },
            { id: 3, nome: 'Carla',  media: 6.2, frequencia: 60 },
            { id: 4, nome: 'Daniel', media: 6,   frequencia: 85 },
            { id: 5, nome: 'Elisa',  media: 7,   frequencia: 75 },
            { id: 6, nome: 'Fabio',  media: 5,   frequencia: 75 }
        ];
    }
    return JSON.parse(dados); // se foi salvo, converte o texto de volta para lista
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