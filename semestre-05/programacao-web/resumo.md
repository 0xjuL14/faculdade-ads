# Resumo de consulta: Programação Web (HTML, CSS, JS)

> **Como achar rápido:** cada seção tem um código `§N`. Use `Ctrl+F` e digite, por exemplo, `§9` para ir direto ao Flexbox.
> Cada bloco indica a **fonte** (qual PDF) entre parênteses.

---

## 0. Índice rápido: "Preciso de..."

| Preciso de... | Vá para | Busque por |
|---|---|---|
| Entender como a web funciona | §1 | `cliente-servidor` |
| Estrutura mínima de uma página | §2 | `DOCTYPE` |
| Título, parágrafo, link, imagem | §3 | `img` / `href` |
| Listas e tabelas | §3 | `ul` / `colspan` |
| `header`, `main`, `footer`, `aside`... | §4 | `semântic` |
| Formulário e validação | §5 | `required` |
| Ligar o CSS ao HTML | §6 | `link rel` |
| Seletores e especificidade | §6 | `especificidade` |
| Margem, padding, borda | §7 | `box model` |
| `position` e `float` | §8 | `sticky` |
| Colocar itens lado a lado | §9 | `justify-content` |
| Colunas e linhas (grade) | §10 | `grid-template` |
| Flex ou Grid? | §11 | `regra de ouro` |
| Site que se adapta ao celular | §12 | `@media` |
| Ler campo, calcular, mostrar na tela | §13 | `addEventListener` |
| Funções, arrays e loops (`for`, `for...of`) | §14 | `for...of` |
| Montar lista na tela com JS (`innerHTML`) | §14 | `innerHTML` |
| Trocar classe/cor pelo JS (`classList`) | §14 | `classList` |
| Buscar, filtrar, transformar e ordenar lista de objetos | §15 | `filter` |
| Callback e arrow function (`=>`) | §15 | `arrow` |
| Busca por texto (`trim`, `toLowerCase`, `includes`) | §15 | `includes` |
| Ordenar sem estragar a lista original (`slice().sort`) | §15 | `slice` |
| `while`, `do...while`, `switch`, `break`, `continue` | §16 | `switch` |
| Métodos de array (`push`, `pop`, `shift`, `splice`, `indexOf`) | §16 | `splice` |
| Objetos e JSON (`stringify`, `parse`) | §16 | `JSON` |
| Validar campos e montar matriz de testes | §17 | `isNaN` |
| Guardar dados no navegador (`localStorage`) | §17 | `localStorage` |
| `try / catch` e dados corrompidos | §17 | `catch` |
| Editar cadastro sem duplicar | §18 | `modoEdicao` |
| Consultar API (`fetch`, `async/await`, ViaCEP) | §18 | `fetch` |
| Meu Perfil (projeto das aulas 2 e 3) | §19 | `perfil` |
| Site TecnoFix (código completo) | §20 | `TecnoFix` |
| "Por que não funciona?" | §21 | `sintoma` |
| Revisão final | §22 | `revisão` |

---

## §1. Fundamentos da Web

*(Fonte: Aula1.pdf)*

### 1.1 Site × Sistema Web × App

| | Site | Sistema Web | App Mobile |
|---|---|---|---|
| Foco | Informação, exibir conteúdo | Interação, regras de negócio | Uso nativo, acesso ao hardware (câmera, GPS) |
| Onde roda | Navegador | Navegador | Instalado no S.O. (Android/iOS) |
| Exemplo | Portal de notícias, blog | Gmail, Netflix, Internet Banking | WhatsApp (app), Uber, Waze |

### 1.2 Modelo cliente-servidor (analogia do restaurante)

| Mundo digital | Restaurante |
|---|---|
| Cliente (navegador) | Você na mesa lendo o cardápio |
| Requisição (internet) | Garçom levando o pedido |
| Servidor (back-end) | Cozinha processando |
| Banco de dados | Despensa com os ingredientes |
| Resposta (página web) | Prato entregue na mesa |

### 1.3 O que acontece ao digitar um endereço (5 passos)

1. **Ação:** o usuário digita `www.site.com`.
2. **DNS:** traduz o domínio para um **endereço IP**.
3. **Requisição (Request):** o navegador envia uma mensagem **HTTP** pedindo a página.
4. **Processamento:** o servidor aprova, monta os dados e devolve **status 200 OK**.
5. **Resposta (Response):** o navegador recebe o código e desenha a tela.

### 1.4 Dicionário da Web

- **URL:** endereço completo e exato de um recurso (`https://www.site.com/contato`).
- **Domínio:** nome amigável do site (`site.com`), a "placa da casa".
- **Hospedagem:** computador remoto (servidor) onde os arquivos ficam 24h.
- **Navegador:** software (Chrome, Edge, Safari) que traduz código em interface visual.

### 1.5 Front-end × Back-end

- **Front-end (o palco):** parte visual e interativa, roda no navegador do usuário.
- **Back-end (os bastidores):** regras de negócio, cálculos, segurança, banco de dados; roda no servidor.

### 1.6 A trindade do Front-end

| Linguagem | Papel | Analogia da casa |
|---|---|---|
| **HTML** | Estrutura e significado | Tijolos e paredes |
| **CSS** | Aparência e layout | Pintura e decoração |
| **JavaScript** | Comportamento | Energia elétrica e encanamento |

### 1.7 Ferramentas e organização

- **VS Code** (editor), **DevTools (F12)** (testar estilos e erros ao vivo), **Git/GitHub** (histórico e portfólio), **Live Server** (atualiza o navegador ao salvar).
- Escrevemos o `.html` no editor, salvamos e abrimos no navegador (não precisa de internet).

```
meu-projeto/
├── index.html      (página principal: sempre esse nome)
├── css/            (estilos)
├── js/             (comportamentos)
└── imagens/        (fotos e ícones)
```

**Regras de ouro para nomes de arquivos:** minúsculas, **sem espaços e sem acentos**. Use `minha-pagina.html`, **nunca** `Minha Página Final.html`.

### 1.8 Carreiras

Front-end, Back-end, Full-stack, Mobile (ex.: React Native).

---

## §2. HTML: base da linguagem

*(Fontes: Slide_HTML p.2-8, HTML.pdf, Guia_aula_2)*

- **HTML = HyperText Markup Language**, linguagem de **marcação**.
- **Mito:** HTML **não é linguagem de programação** (não tem `if/else`, nem laços, nem lógica).
- Criado por **Tim Berners-Lee** (início dos anos 1990) para compartilhar documentos científicos. **Hipertexto** = documentos ligados por links.
- Finalidade: definir a **estrutura e o significado** do conteúdo para navegador, leitores de tela e buscadores (SEO). A aparência é do CSS.

### 2.1 Elementos, tags e aninhamento

```html
<p>Texto</p>        <!-- abertura + conteúdo + fechamento -->

<ul>                 <!-- ul = elemento PAI -->
  <li>Item 1</li>    <!-- li = elementos FILHOS (aninhados) -->
  <li>Item 2</li>
</ul>
```

**Tags vazias** (sem conteúdo nem fechamento): `<img>`, `<br>`, `<hr>`.

### 2.2 Atributos

Ficam **sempre na tag de abertura**, no formato `nome="valor"`, separados por espaço.

```html
<a href="https://www.site.com" title="Ir ao site">Acessar</a>
<img src="logo.png" alt="Logomarca da Educação">
<input type="email" placeholder="seu@email.com" required>  <!-- required = booleano -->
```

**Atributos globais:** `id`, `class`, `title`, `style`.

### 2.3 Estrutura básica do documento

```html
<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Minha Página</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <h1>Olá Mundo</h1>
  <p>Este é um parágrafo.</p>
</body>
</html>
```

| Elemento | Função |
|---|---|
| `<!DOCTYPE html>` | Declara HTML5 |
| `<html>` | Elemento raiz, envolve tudo |
| `<head>` | Metadados (não visíveis) |
| `<title>` | Título na aba |
| `<meta>` | Charset, viewport, descrição, autor |
| `<body>` | Conteúdo visível |

> Só pode haver **um** `<html>`, **um** `<head>` e **um** `<body>`.

### 2.4 Comentários

```html
<!-- Isto fica invisível no site -->
```

Referências oficiais: **MDN Web Docs** (enciclopédia) e **W3Schools** (testar códigos rápido).

---

## §3. HTML: conteúdo (texto, mídia, links, listas, tabelas)

*(Fontes: Slide_HTML p.9-21, HTML.pdf, Aula3)*

### 3.1 Títulos, parágrafos e quebras

```html
<h1>Título principal (1 por página)</h1>
<h2>Seção</h2>   <!-- até <h6> -->
<p>Bloco de texto.</p>
Linha 1<br>Linha 2     <!-- br: quebra de linha (tag vazia) -->
<hr>                   <!-- linha horizontal (tag vazia) -->
<pre>
  Mantém   espaços
  e quebras
</pre>
```

- **Não** use `h1`–`h6` só para mudar tamanho de fonte (use CSS).
- **Não** use vários `<br>` para criar espaço (use `margin`/`padding`).

### 3.2 Formatação: visual × semântica

| Visual | Semântica | O leitor de tela entende |
|---|---|---|
| `<b>` negrito | `<strong>` | "importante" |
| `<i>` itálico | `<em>` | ênfase no tom |
| `<u>` | (usar CSS) | só um traço |

**Boa prática:** prefira `strong` e `em` (SEO e acessibilidade).

Outras tags:

```html
<p>Preço: R$ 99 <small>(válido até 20/12)</small></p>   <!-- texto menor -->
<p>Água: H<sub>2</sub>O</p>                              <!-- subscrito -->
<p>x<sup>2</sup> + y<sup>2</sup> = z<sup>2</sup></p>     <!-- sobrescrito -->
<p>Execute <code>npm start</code>.</p>                   <!-- código inline -->
```

`<big>` é **obsoleto** (use `font-size`). Para bloco de código, use `<pre><code>...</code></pre>`.

### 3.3 Imagens

```html
<img src="imagens/foto-ana.jpg" alt="Foto de perfil de Ana sorrindo" width="200" height="80">

<figure>
  <img src="https://site.com/foto.jpg" alt="Foto do campus">
</figure>
```

- `src` = caminho (local ou URL). `alt` = texto alternativo.
- **Por que o `alt` é crucial:** leitores de tela leem para pessoas com deficiência visual e o texto aparece se a imagem quebrar.
- `width`/`height` ajudam o navegador a reservar espaço.

### 3.4 Links (`<a>`)

```html
<a href="sobre.html">Nossa História</a>                         <!-- página do mesmo site -->
<a href="http://google.com" target="_blank">Google</a>          <!-- externo, nova aba -->

<a href="#contato">Ir para Fale Conosco</a>                     <!-- âncora: origem -->
<h2 id="contato">Fale Conosco</h2>                              <!-- âncora: destino (mesmo id) -->
```

Tudo que está dentro do `<a>` (texto, imagem) vira **área clicável**.

### 3.5 Listas

```html
<!-- Não ordenada: ordem NÃO importa (menus, características) -->
<ul>
  <li>Gabinete</li>
  <li>Monitor</li>
</ul>

<!-- Ordenada: ordem importa (passos, receitas). type: "1", "A", "a", "I", "i" -->
<ol>
  <li>Ligar o computador</li>
  <li>Abrir o navegador</li>
</ol>

<!-- Descrição: termo + definição (glossários) -->
<dl>
  <dt>Sistemas para Internet</dt>
  <dd>Curso para formar profissionais Web.</dd>
</dl>
```

### 3.6 Tabelas

```html
<table border="1">
  <thead>
    <tr><th colspan="2">Grade Curricular</th></tr>   <!-- colspan: mescla COLUNAS -->
    <tr><th>Disciplina</th><th>Carga</th></tr>
  </thead>
  <tbody>
    <tr><td rowspan="2">Programação</td><td>HTML - 60h</td></tr>  <!-- rowspan: mescla LINHAS -->
    <tr><td>CSS - 60h</td></tr>
  </tbody>
</table>
```

| Tag | Papel |
|---|---|
| `table` | Recipiente |
| `thead` / `tbody` | Cabeçalho / corpo |
| `tr` | Linha |
| `th` | Célula de título |
| `td` | Célula de dado |

> **Regra de ouro:** tabela é **só para dados**. **Nunca** use tabela para montar o layout.

### 3.7 `div` e `span` (genéricos)

```html
<div>                       <!-- BLOCO: ocupa a largura toda, semântica neutra -->
  <h1>Título</h1>
  <p>Conteúdo.</p>
</div>

<p>Este é um <span>destaque</span> no texto.</p>   <!-- INLINE: não quebra a linha -->
```

> Prefira sempre o elemento **semântico**, quando existir, em vez de `div`/`span`.

### 3.8 Áudio, vídeo e iframe

```html
<audio controls>
  <source src="musica.mp3" type="audio/mpeg">
  <source src="musica.ogg" type="audio/ogg">
  Seu navegador não suporta áudio.            <!-- fallback -->
</audio>

<video width="640" height="360" controls>
  <source src="aula.mp4" type="video/mp4">
  <source src="aula.webm" type="video/webm">
  Seu navegador não suporta vídeo.
</video>

<iframe width="560" height="315" src="URL_DO_VIDEO"></iframe>   <!-- "janela" para outro site (ex.: YouTube) -->
```

Atributos de mídia: `src`, `controls`, `autoplay`, `loop`, `width/height` (só vídeo).

---

## §4. HTML semântico

*(Fontes: Slide_HTML p.22-31, HTML.pdf, Aula3)*

**Semântica** = tags com significado claro, que **substituem o excesso de `div`**. Benefícios: código mais organizado, **SEO** melhor, **acessibilidade** (leitores de tela).

| Tag | Uso | Regra importante |
|---|---|---|
| `<header>` | Topo da página ou da seção (logo, título, navegação) | Pode haver vários; não aninhar dentro de `footer`, `address` ou outro `header` |
| `<nav>` | Blocos importantes de navegação | Não precisa envolver todo link; combina com `ul` |
| `<main>` | Conteúdo dominante do `body` | **Apenas um** por página; não dentro de `header`, `nav`, `article`, `aside`, `footer` |
| `<section>` | Agrupamento **temático** | Inclua um título (`h1`–`h6`); não use só para estilizar (aí é `div`) |
| `<article>` | Conteúdo **independente** (notícia, post, card de produto) | Se dá para publicar em outro lugar sem perder o sentido, é `article` |
| `<aside>` | Conteúdo **complementar** (sidebar, links relacionados) | Se for removido, o principal ainda faz sentido |
| `<footer>` | Rodapé da página ou de uma seção | Copyright, contatos, políticas |

```html
<body>
  <header>Topo da Página</header>
  <nav>Menu Principal</nav>
  <main>
    <section>
      <article>Conteúdo 1</article>
      <article>Conteúdo 2</article>
    </section>
    <aside>Lateral/Relacionado</aside>
  </main>
  <footer>Rodapé da Página</footer>
</body>
```

```html
<nav>
  <ul>
    <li><a href="index.html">Início</a></li>
    <li><a href="cursos.html">Cursos</a></li>
  </ul>
</nav>
```

---

## §5. Formulários

*(Fontes: Formularios.pdf, Slide_HTML p.20, Guia_aula_2)*

### 5.1 A tag `<form>`

```html
<form action="/servidor" method="POST">   <!-- action = para onde vão os dados; method = como viajam (GET × POST) -->
  <input type="text" name="usuario">
  <button type="submit">Enviar</button>
</form>
```

### 5.2 `label`, `id` e `name` (3 papéis diferentes)

```html
<label for="nome">Nome:</label>
<input type="text" id="nome" name="usuario_nome" placeholder="ex: João Silva">
```

- `for` + `id` = **ligação de acessibilidade** (clicar no label foca o campo).
- `name` = **"chave da variável"** que o servidor lê. Sem `name`, o dado **não viaja**.
- `placeholder` = dica efêmera. **Nunca** substitui o `label`.

### 5.3 Tipos de `input`

| `type` | Efeito |
|---|---|
| `text` | Texto comum |
| `email` | Exige formato de e-mail, teclado com `@` |
| `password` | Esconde os caracteres |
| `number` | Só números, teclado numérico |
| `date` | Seletor de data |
| `tel` | Teclado de telefone |
| `radio` / `checkbox` | Escolha (veja 5.5) |

### 5.4 Validações nativas do HTML5

```html
<input required>                                  <!-- obrigatório (booleano) -->
<input type="number" min="18" max="100">          <!-- limites numéricos -->
<input minlength="3" maxlength="50">              <!-- limites de caracteres -->
<input type="tel" pattern="[0-9]{10,11}">         <!-- regex -->
```

Outro atributo útil: `disabled`.

### 5.5 `textarea`, `select`, `radio`, `checkbox`

```html
<textarea rows="4" maxlength="200"></textarea>

<select required>
  <option value="">Selecione...</option>   <!-- vazio força escolha ativa -->
  <option value="sp">São Paulo</option>
  <option value="rj">Rio de Janeiro</option>
</select>

<!-- RADIO: mesmo name = grupo excludente (escolha única) -->
<input type="radio" name="tipo_cliente" value="pf"> PF
<input type="radio" name="tipo_cliente" value="pj"> PJ

<!-- CHECKBOX: opções independentes -->
<input type="checkbox" name="int_site"> Site
<input type="checkbox" name="termos" required> Aceito os termos
```

### 5.6 Botões

| Código | O que faz |
|---|---|
| `<button type="submit">` | Envia o formulário |
| `<button type="reset">` | **Apaga tudo** (use com cuidado) |
| `<button type="button">` | Não faz nada sozinho; espera o JavaScript |

Use sempre `<button>` (tem acessibilidade por teclado), **nunca** uma `div` estilizada.

### 5.7 Agrupar com `fieldset` e `legend`

```html
<fieldset>
  <legend>Dados Pessoais</legend>
  <div>
    <label for="nome">Nome Completo:</label>
    <input type="text" id="nome" name="nome" required>
  </div>
</fieldset>
```

### 5.8 Estilizando formulário (CSS)

```css
input, select, textarea {
  padding: 10px;
  margin-bottom: 15px;
  border: 1px solid #ccc;
  border-radius: 5px;
  font-size: 16px;
  width: 100%;
}
input:focus {                       /* clique ou Tab */
  border-color: #007BFF;
  outline: none;
  box-shadow: 0 0 5px #007BFF;
}
button:hover { background-color: #0056b3; cursor: pointer; }

.form-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 20px; }
.campo-completo { grid-column: 1 / -1; }          /* ocupa da 1ª até a última linha da grade */

@media (max-width: 600px) {
  .form-grid { grid-template-columns: 1fr; }      /* 2 colunas viram 1 */
}
```

### 5.9 Erros comuns em formulários

- Esquecer o `name` no `<input>` (o dado não viaja).
- `id` duplicado em campos diferentes.
- Usar só `placeholder` em vez de `<label>`.
- Radios do mesmo grupo com `name` diferentes.
- Botão de envio sem `type="submit"`.
- Largura fixa em pixels (quebra no celular).

---

## §6. CSS: fundamentos

*(Fontes: Slide_CSS p.2-16, Guia_aula_2)*

- **CSS = Cascading Style Sheets**, linguagem de **estilização** (não de programação).
- Separa responsabilidades: **HTML** = estrutura e conteúdo; **CSS** = apresentação.

### 6.1 Sintaxe

```css
/* comentário */
seletor {
  propriedade: valor;   /* cada declaração termina com ; */
}

p {
  color: red;
  font-size: 16px;
}
```

### 6.2 Três formas de aplicar

```html
<!-- 1. Inline (evitar) -->
<p style="color: red;">Texto</p>

<!-- 2. Interno (no head) -->
<style> p { color: red; } </style>

<!-- 3. Externo (RECOMENDADO) -->
<link rel="stylesheet" href="style.css">
```

> O `<link>` vai **dentro do `<head>`**. Externo facilita manutenção e cache.

### 6.3 Seletores básicos

```css
p { color: blue; }            /* elemento (tag): todos os <p> */
.texto { color: green; }      /* classe: reutilizável, começa com ponto */
#titulo { font-size: 24px; }  /* id: único na página, começa com # */
```

```html
<p class="texto">...</p>
<h1 id="titulo">...</h1>
```

### 6.4 Combinadores

| Seletor | Sintaxe | O que pega |
|---|---|---|
| Descendente | `div p` | Todos os `p` dentro de `div`, em qualquer nível |
| Filho direto | `div > p` | Só `p` filhos diretos (exclui netos) |
| Irmão adjacente | `h1 + p` | **Só o primeiro** `p` logo após o `h1` |
| Irmão geral | `h1 ~ p` | **Todos** os `p` irmãos depois do `h1` |

### 6.5 Cascata, `!important` e especificidade

**Ordem crescente de prioridade:**
1. Folha padrão do navegador
2. Folha do usuário
3. Folha do autor (externo, interno, inline)
4. Declarações do autor com `!important`
5. Declarações do usuário com `!important`

```css
p { color: #000 !important; }   /* precedência absoluta; usar com moderação */
```

**Pontuação de especificidade:**

| Tipo | Pontos |
|---|---|
| `style` inline | 1000 |
| `#id` | 100 |
| `.classe`, `[atributo]`, `:pseudo-classe` | 10 |
| elemento, `::pseudo-elemento` | 1 |

```css
p { color: blue; }                        /* 1 */
.texto { color: green; }                  /* 10 */
#destaque { color: red; }                 /* 100 */
#destaque .texto p { color: purple; }     /* 111 -> vence (texto roxo) */
```

**Desempate:** maior pontuação vence; empate = vale a **última** declaração lida.

### 6.6 Pseudo-classes (estados)

```css
a:hover { color: #06b6d4; }                      /* mouse em cima */
input:focus { outline: 2px solid #06b6d4; }      /* campo em foco */
li:nth-child(odd) { background: #f1f5f9; }       /* linhas ímpares (listras de tabela/lista) */
button:disabled { opacity: 0.5; cursor: not-allowed; }
```

Categorias: **interação** (`:hover`, `:active`, `:focus`, `:visited`), **posição** (`:first-child`, `:last-child`, `:nth-child`), **formulário** (`:checked`, `:disabled`, `:required`), **negação** (`:not()`). Sintaxe com **um** dois-pontos.

### 6.7 Pseudo-elementos (partes do elemento)

```css
.card::before { content: ""; display: block; height: 6px; background: #06b6d4; }
p::first-letter { font-size: 2rem; font-weight: 700; }
p::first-line { text-transform: uppercase; }
::selection { background: #06b6d4; color: #fff; }
```

Sintaxe com **dois** dois-pontos `::`. `::before`/`::after` **exigem `content`**.

### 6.8 Ligar o CSS e centralizar (Guia aula 2)

```css
.perfil {
  max-width: 650px;
  margin: auto;          /* centraliza horizontalmente */
}
```

```html
<main class="perfil">...</main>   <!-- classe no HTML; no CSS começa com ponto -->
```

---

## §7. CSS: propriedades e Box Model

*(Fontes: Slide_CSS p.17-23, Guia_aula_2, Aula 5)*

### 7.1 Box Model (4 camadas, de dentro para fora)

**Content** → **Padding** (espaço interno) → **Border** (borda) → **Margin** (espaço externo).

```css
.box {
  margin: 16px 24px;          /* 16px em cima/baixo, 24px nas laterais */
  padding: 12px;
  border: 2px solid #1e3a8a;
}
```

> As margens verticais entre blocos adjacentes podem **colapsar**.

### 7.2 `box-sizing`

```css
* { box-sizing: border-box; }   /* reset comum: width inclui padding e borda */

.box { width: 300px; padding: 20px; border: 5px solid #000; box-sizing: border-box; }
/* largura final: exatamente 300px */
```

- `content-box` (padrão): width vale só o conteúdo; padding e borda somam por fora.
- `border-box`: width já **inclui** padding e borda (cálculo previsível).

### 7.3 Texto

```css
body { font-family: 'Open Sans', sans-serif; color: #333333; }
h1 { font-size: 32px; font-weight: 700; text-transform: uppercase; }
p  { line-height: 1.6; text-align: justify; letter-spacing: 0.2px; }
a  { text-decoration: none; }
```

### 7.4 Fundo

```css
.header {
  background-color: #f1f5f9;
  background-image: url('img/pattern.png');
  background-size: cover;            /* cover, contain ou valor fixo */
  background-position: center;
  background-repeat: no-repeat;
}
.banner {
  background-image: linear-gradient(90deg, #06b6d4, #1e3a8a);
  color: #fff;
}
```

### 7.5 Layout e aparência

```css
.card {
  width: 320px; min-height: 180px;
  display: flex; align-items: center;
  border-radius: 12px;
  box-shadow: 0 8px 20px rgba(0,0,0,0.12);
  overflow: hidden;
}
.badge { display: inline-block; border-radius: 999px; opacity: 0.9; cursor: pointer; }
.img { width: 100%; height: 200px; object-fit: cover; }
```

| Propriedade | Para quê |
|---|---|
| `width/height` | Dimensões |
| `max-*/min-*` | Limites seguros |
| `display` | `block`, `flex`, `grid`, `none` |
| `overflow` | Oculta ou rola o que excede |
| `border-radius` | Cantos arredondados |
| `box-shadow` | Sombra |
| `opacity` | 0 invisível, 1 opaco |
| `cursor` | Ponteiro (`pointer` = clicável) |

### 7.6 Avatar e tabela (Aula 3)

```css
.avatar { width: 150px; border-radius: 50%; box-shadow: 2px 2px 10px rgba(0,0,0,0.5); }

table { width: 100%; border-collapse: collapse; }
th { background-color: #333; color: white; padding: 10px; }
td { border-bottom: 1px solid #ddd; padding: 10px; }

.cabecalho, .rodape { background-color: #2c3e50; color: white; text-align: center; padding: 20px; }
```

---

## §8. Posicionamento: `float` e `position`

*(Fonte: Slide_CSS p.24-29)*

### 8.1 Float

Tira o elemento do fluxo e faz o texto contornar. Valores: `left`, `right`, `none`, `inherit`.

```css
.imagem-flutuante { float: left; margin-right: 20px; width: 200px; }
.container { overflow: hidden; }          /* contém os flutuantes */
.clearfix:after { content: ""; display: table; clear: both; }
```

### 8.2 Position

| Valor | Comportamento | Código |
|---|---|---|
| `static` | **Padrão.** Fluxo normal; ignora `top/left/...` | `position: static;` |
| `relative` | Desloca **visualmente**, mantém o espaço original | `position: relative; top: 20px;` |
| `absolute` | Sai do fluxo; posiciona em relação ao **ancestral posicionado** mais próximo | pai `relative`, filho `absolute; top:0; left:0;` |
| `fixed` | Fixo na **janela** (não rola) | `position: fixed; top:0; left:0; width:100%; z-index:100;` |
| `sticky` | Híbrido: age como `relative` até o ponto, depois "cola" como `fixed` | `position: sticky; top: 0;` |

```css
.parent { position: relative; }
.child  { position: absolute; top: 0; left: 0; }
```

---

## §9. Flexbox (layout em 1 dimensão)

*(Fontes: Slide_CSS p.30-38, Layouts.pdf, Aula3, Aula 5)*

> **Regra de ouro:** o `display: flex` vai no **PAI** (container). Os filhos viram itens.

```css
.container { display: flex; gap: 30px; align-items: flex-start; }
```

- **Eixo principal (main axis):** definido por `flex-direction` (padrão `row` = horizontal).
- **Eixo cruzado (cross axis):** sempre perpendicular ao principal.
- Se `flex-direction: column`, os eixos **se invertem**.

### 9.1 Propriedades do container

| Propriedade | Valores | Observação |
|---|---|---|
| `flex-direction` | `row` (padrão), `column`, `row-reverse`, `column-reverse` | Define o eixo principal |
| `flex-wrap` | `nowrap` (padrão, transborda), `wrap` (quebra, recomendado), `wrap-reverse` | `wrap` para responsivo |
| `justify-content` | `flex-start`, `flex-end`, `center`, `space-between`, `space-around`, `space-evenly` | **Eixo principal** |
| `align-items` | `stretch` (padrão), `flex-start`, `flex-end`, `center`, `baseline` | **Eixo cruzado**, dentro de UMA linha |
| `align-content` | `flex-start`, `flex-end`, `center`, `space-between`, `space-around`, `stretch` | Alinha LINHAS inteiras; **só funciona com `flex-wrap: wrap`** |
| `gap` | `20px` | Espaço entre itens (acaba a dor de cabeça com margin) |

```css
/* Centralizar nos dois eixos */
.container { display: flex; justify-content: center; align-items: center; }

/* Espaçado horizontalmente e centralizado na vertical (cabeçalho) */
.header-novatech { display: flex; justify-content: space-between; align-items: center; }
.menu { display: flex; gap: 15px; }

/* Quebrar linha + espaçamento */
.servicos-container { display: flex; flex-wrap: wrap; gap: 20px; }
```

### 9.2 Propriedades do item flex

| Propriedade | Significado |
|---|---|
| `flex-basis` | Tamanho inicial ideal (ex.: `200px`) |
| `flex-grow` | Pode **crescer** se sobrar espaço? (`0` = não, `1` = sim, proporcional) |
| `flex-shrink` | Pode **encolher** se faltar espaço? |

### 9.3 Pegadinha: `justify-content` × `align-items`

`justify-content` = **eixo principal** (horizontal se `row`). `align-items` = **eixo cruzado** (vertical se `row`).

---

## §10. CSS Grid (layout em 2 dimensões)

*(Fontes: Slide_CSS p.39-45, Layouts.pdf, Formularios)*

Ativar: `display: grid;` **no pai**. Só ativar não faz muito: é preciso **desenhar colunas e linhas**.

### 10.1 Colunas e linhas

```css
.grid1 { grid-template-columns: 200px 1fr 1fr; }                  /* fixa + frações */
.grid2 { grid-template-columns: repeat(3, 1fr); }                 /* 3 colunas iguais */
.grid3 { grid-template-columns: repeat(auto-fit, minmax(250px, 1fr)); }   /* responsivo SEM media query */
.grid4 { grid-template-columns: 100px auto 200px; }

.c1 { grid-template-rows: 100px auto 200px; }
.c2 { grid-template-rows: repeat(3, 150px); }
.c4 { grid-template-rows: 1fr 2fr 1fr; }                          /* proporção 1:2:1 */
```

| Valor | Significado |
|---|---|
| `px` | Tamanho fixo |
| `%` | Porcentagem do container |
| `fr` | **Fração** do espaço livre |
| `auto` | Ajusta ao conteúdo |
| `repeat(n, tam)` | Repete n vezes |
| `minmax(mín, máx)` | Limites flexíveis |
| `auto-fit` | Colapsa colunas vazias |
| `auto-fill` | Preenche com colunas |

### 10.2 Gap

```css
.container { gap: 20px; }                  /* linhas e colunas */
.container { gap: 30px 15px; }             /* linha | coluna */
.container { row-gap: 25px; column-gap: 10px; }
```

O `gap` fica **entre** as células, não nas bordas externas.

### 10.3 Estrutura básica

```css
.container {
  display: grid;
  grid-template-columns: 1fr 1fr;
  grid-template-rows: auto;
  gap: 16px;
}
```

### 10.4 Áreas nomeadas

```css
.layout {
  display: grid;
  grid-template-areas:
    'header header header'
    'menu conteudo sidebar'
    'footer footer footer';
}
.cabecalho { grid-area: header; }
```

O CSS "desenha" o layout, sem HTML extra.

### 10.5 Ocupar a largura toda

```css
.campo-completo { grid-column: 1 / -1; }   /* da primeira linha da grade (1) até a última (-1) */
```

### 10.6 Alinhamento no Grid

| Propriedade | Alvo | Eixo |
|---|---|---|
| `justify-content` | O **grid inteiro** no container | Horizontal |
| `align-content` | O **grid inteiro** no container | Vertical |
| `justify-items` | O **conteúdo dos itens** nas células | Horizontal |
| `align-items` | O **conteúdo dos itens** nas células | Vertical |

Atalho: `place-items: center;` = `align-items` + `justify-items`.

```css
.container {
  display: grid;
  grid-template-columns: 1fr 1fr;
  justify-items: center;
  align-items: center;
}
```

---

## §11. Flexbox × Grid: quando usar qual

*(Fontes: Slide_CSS p.46-47, Layouts.pdf)*

| | Flexbox (fluxo) | Grid (matriz) |
|---|---|---|
| Dimensões | **1D** (linha **ou** coluna) | **2D** (linhas **e** colunas) |
| Lógica | Focado no **conteúdo** (itens empurram a caixa) | Focado no **layout** (desenha a caixa primeiro) |
| Uso ideal | Menus, botões, alinhar ícones, listas simples | Estrutura da página, galerias de cards |

> **Regra de ouro:** 1 dimensão → **Flexbox**. 2 dimensões → **Grid**.
> **Dica:** Grid para o **macro-layout**, Flexbox para **componentes micro**. Eles trabalham juntos (`header` com flex, `main` com grid).

---

## §12. Responsividade

*(Fontes: Aula_05_Responsividade_CSS, Formularios, Layouts)*

> Responsivo **não é diminuir**: é **reorganizar** (desktop → tablet com menos colunas → celular em ordem vertical).

### 12.1 Viewport (obrigatório no `<head>`)

```html
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

Sem essa linha, o celular pode simular uma tela de desktop e reduzir tudo.

### 12.2 Largura fixa × fluida

```css
/* FIXO (quebra no celular) */
.conteudo { width: 1100px; }

/* FLUIDO + LIMITE (correto) */
.conteudo { width: 90%; max-width: 1100px; margin: 0 auto; }
```

### 12.3 Unidades

| Unidade | Referência | Uso comum |
|---|---|---|
| `px` | Valor fixo | Bordas e detalhes |
| `%` | Elemento pai | Larguras fluidas |
| `vw` / `vh` | Janela visível | Seções e efeitos |
| `rem` | Fonte raiz | Textos e espaçamentos |
| `em` | Fonte do contexto | Componentes escaláveis |

Regra prática: `px` com moderação; prefira `%` e `rem` no que precisa crescer.

### 12.4 Container e imagens

```css
.container { width: 90%; max-width: 1200px; margin: 0 auto; }   /* margin: 0 auto centraliza */

img { max-width: 100%; height: auto; display: block; }          /* encolhe sem deformar */
```

Evite `width` e `height` fixos ao mesmo tempo na imagem.

### 12.5 Media Query e breakpoints

```css
@media (max-width: 768px) {     /* 1 condição: tela com até 768px */
  .menu { flex-direction: column; }   /* 2 alvo / 3 mudança */
}
```

- O **HTML não muda**; só entram novas regras.
- Breakpoint sugerido: celular até 600px; tablet 601–900px; desktop acima de 900px. **Não existe número mágico:** reduza a janela devagar e crie o breakpoint quando o conteúdo apertar.

### 12.6 Mobile First × Desktop First

```css
/* DESKTOP FIRST: reduz quando a tela diminui (max-width) */
.cards { grid-template-columns: repeat(3, 1fr); }
@media (max-width: 600px) { .cards { grid-template-columns: 1fr; } }

/* MOBILE FIRST: expande quando há espaço (min-width) */
.cards { grid-template-columns: 1fr; }
@media (min-width: 900px) { .cards { grid-template-columns: repeat(3, 1fr); } }
```

> No projeto, **escolha um padrão e mantenha**.

### 12.7 Flexbox e Grid adaptáveis

```css
.sobre { display: flex; gap: 32px; align-items: center; }
@media (max-width: 768px) { .sobre { flex-direction: column; } }

.cards { display: grid; grid-template-columns: repeat(3, 1fr); gap: 24px; }
@media (max-width: 900px) { .cards { grid-template-columns: repeat(2, 1fr); } }
@media (max-width: 600px) { .cards { grid-template-columns: 1fr; } }

/* Truque sem media query: */
.cards { grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); }
```

### 12.8 Testar no DevTools (3 etapas)

1. **Abrir** DevTools (`Ctrl/Cmd + Shift + I`).
2. **Simular** celular, tablet e largura livre.
3. **Observar** rolagem lateral, sobreposição e leitura. Teste 1200px, 768px e 390px.

### 12.9 4 erros que quebram o layout

1. Largura fixa (`width: 1000px`).
2. Imagem sem limite (passa do container).
3. Media Query invertida (`max-width` e `min-width` trocados).
4. Texto apertado (fonte e espaçamento não se adaptam).

> **Diagnóstico rápido:** apareceu rolagem horizontal? Algum filho é maior que o pai.

---

## §13. JavaScript

*(Fontes: JavaScript.pdf, Fundamentos_de_Desenvolvimento_Web_e_JavaScript.pdf)*

> **HTML constrói. CSS embeleza. JavaScript faz acontecer** (cálculos, validações, cliques, alteração de conteúdo).

### 13.1 Onde o JS vive

- Console do navegador (**F12**): `console.log('Olá mundo');`
- Arquivo externo (**recomendado**), ligado no HTML:

```html
<script src="js/script.js" defer></script>
```

> `defer` = o script só roda depois do HTML carregar. Separar arquivos mantém o HTML limpo, organiza a lógica e permite **reuso**.

### 13.2 Variáveis e tipos

```js
let nome = 'João';       // let: valor pode ser trocado
const idade = 20;        // const: "trancada" (não reatribuir)
const ativo = true;      // boolean
console.log(typeof idade);   // "number"  (typeof descobre o tipo)
```

Tipos: **String** (texto), **Number** (número), **Boolean** (`true`/`false`).

### 13.3 Operadores

```js
+  -  *  /  %                 // matemática (% = resto)
'Olá ' + nome                 // + também CONCATENA textos -> 'Olá João'
>  <  >=  <=                  // comparação
==   // compara só o valor
===  // compara VALOR e TIPO (use sempre este para evitar bugs)
```

### 13.4 Decisões: `if / else if / else`

```js
const idade = 20;
if (idade >= 18) {
  console.log('Maior de idade');
} else {
  console.log('Menor de idade');
}
// Pausa: e se a idade for exatamente 18? Entra no if (>= inclui o 18).

let situacao = '';
if (media >= 7) {
  situacao = 'Aprovado';
} else if (media >= 5) {
  situacao = 'Recuperação';
} else {
  situacao = 'Reprovado';
}
```

### 13.5 DOM: a ponte entre HTML e JS

O navegador transforma o HTML em **objetos** (a "árvore" do DOM).

```js
const titulo = document.querySelector('#titulo');   // # = busca por id (único)
const itens = document.querySelector('.classe');    // . = busca por classe
```

`querySelector()` é o padrão moderno para buscar elementos.

### 13.6 Ler e escrever na tela

```js
titulo.textContent = 'Título alterado';                    // ESCREVE na tela
const nome = document.querySelector('#nome').value;        // LÊ o que o usuário digitou
```

### 13.7 Eventos

```js
botao.addEventListener('click', function () {
  alert('Botão clicado!');
});
```

| Parte | Significado |
|---|---|
| `botao` | Quem vai ouvir (elemento alvo) |
| `addEventListener` | O "radar" que fica ligado aguardando uma ação |
| `'click'` | Qual ação (clique, digitação, envio de formulário...) |
| `function() {...}` | O que fazer quando acontecer |

### 13.8 Formulário, `submit` e `preventDefault()`

Formulários nasceram para **recarregar a página e enviar ao servidor**. `preventDefault()` bloqueia isso para o JS assumir o controle na mesma tela.

```js
const form = document.querySelector('#form');

form.addEventListener('submit', function (event) {
  event.preventDefault();   // O escudo! Bloqueia o recarregamento
  // a lógica do app continua aqui...
});
```

### 13.9 O erro clássico: `.value` devolve TEXTO

```js
const val = document.querySelector('#v1').value;           // '10' + '5' = '105'  (concatenação!)
const val = Number(document.querySelector('#v1').value);   // 10 + 5 = 15        (soma correta)
```

### 13.10 Cálculo e saída

```js
const resultado = valor1 + valor2;
document.querySelector('#resultado').textContent = 'Resultado: ' + resultado;

const media = (nota1 + nota2) / 2;    // parênteses OBRIGATÓRIOS (soma antes da divisão)
```

### 13.11 Validação: HTML × JavaScript

| | HTML | JavaScript |
|---|---|---|
| Como | `required`, `type="email"`, `min`/`max` | `if (...) { ... return; }` |
| Prós | Rápido, zero JS, proteção nativa | Mensagens personalizadas, lógica complexa (comparar campos) |
| Contras | Engessado, difícil personalizar | Exige escrever a verificação |

```js
if (nota1 < 0 || nota1 > 10) {
  alert('Nota inválida!');
  return;                       // interrompe o processamento
}
```

### 13.12 Ciclo de vida da interação (6 passos)

1. **Usuário** preenche e clica em Enviar.
2. **Navegador** dispara o evento `submit`.
3. **Escudo JS** intercepta com `preventDefault()`.
4. **Leitura (DOM In):** captura dados com `.value` (+ `Number()`).
5. **Lógica (cérebro):** calcula e decide com `if/else`.
6. **Escrita (DOM Out):** atualiza a tela com `.textContent`, sem piscar.

### 13.13 Exemplo completo (cadastro)

```html
<form id="form">
  <input type="text" id="nome" placeholder="Nome">
  <input type="number" id="idade" placeholder="Idade">
  <button type="submit">Enviar</button>
</form>
<p id="resultado"></p>
```

```js
const form = document.querySelector('#form');
const resultado = document.querySelector('#resultado');

form.addEventListener('submit', function (event) {
  event.preventDefault();

  const nome = document.querySelector('#nome').value;
  const idade = document.querySelector('#idade').value;

  if (idade >= 18) {
    resultado.textContent = nome + ', cadastro realizado!';
  } else {
    resultado.textContent = nome + ', você é menor de idade.';
  }
});
```

### 13.14 Exercícios dos slides

- **Calculadora de Média:** nome + 2 notas → média `(nota1 + nota2) / 2` → Aprovado (≥ 7), Recuperação (≥ 5 e < 7), Reprovado.
- **Calculadora de Desconto:** `desconto = preco * (percentual / 100);` e `valorFinal = preco - desconto;`.
- Outras ideias: IMC, conversor de temperatura, simulador de orçamento, calculadora de consumo.

> **Continua na §14:** funções, arrays, loops (`for`, `for...of`), `classList` e listas dinâmicas na tela.

---

## §14. JavaScript dinâmico: funções, arrays, loops e listas na tela

*(Fonte: JavaScript_Dinâmico.pdf, 13 slides. Os exemplos "completos" foram montados a partir dos trechos dos slides.)*

> **Ideia central do slide:** até a §13 líamos inputs, calculávamos e escrevíamos o resultado no HTML, tudo isolado. Agora entram **funções** (reuso), **arrays** (vários dados), **loops** (percorrer os dados) e **DOM** (mostrar na tela). Você deixa de escrever páginas estáticas e passa a **programar sistemas reais**.

### 14.1 Onde estamos: a base da interação

```js
let num1 = Number(document.querySelector('#n1').value);
let num2 = Number(document.querySelector('#n2').value);

let soma = num1 + num2;

if (soma > 10) {
  document.querySelector('#res').textContent = 'Alto!';
}
```

Fluxo: **ler** do input (`.value` + `Number()`) → **calcular** → **decidir** (`if`) → **escrever** na página (`.textContent`).

### 14.2 Funções: empacotando lógica reutilizável

| Parte | Papel | No código |
|---|---|---|
| **Parâmetros** | Entrada | `a`, `b` em `somar(a, b)` |
| Corpo | O que a função faz | `{ let total = a + b; }` |
| **Retorno** | Saída | `return total;` |

```js
function somar(a, b) {
  let total = a + b;
  return total;
}

function calcular() {
  let val = somar(5, 5);                                  // chama (executa) a função
  document.querySelector('#res').textContent = val;       // mostra 10
}
```

**Por que usar?** Em vez de copiar e colar o mesmo cálculo várias vezes, você cria uma "máquina" (a função) e a **chama (executa) apenas quando precisar**.

### 14.3 Eventos: o sistema nervoso da página

O JavaScript reage a gatilhos (cliques, digitação, envio).

| | Jeito antigo (bagunçado) | Jeito moderno (limpo) |
|---|---|---|
| Código | `<button onclick="calcular()">Calcular</button>` | `<button id="btn">Calcular</button>` + `addEventListener` no JS |
| Problema/vantagem | Mistura HTML com JavaScript e **dificulta a manutenção** | O HTML fica limpo; o JS apenas **escuta** o elemento aguardando a ação |

```html
<button id="btn">Calcular</button>
```

```js
let botao = document.querySelector("#btn");
botao.addEventListener("click", calcular);
```

**Outros eventos importantes:**
- `input`: ao digitar
- `change`: ao mudar o valor
- `submit`: ao enviar um formulário

> **Atenção (observação minha, não está no slide):** em `addEventListener("click", calcular)` a função vai **sem parênteses**. Com `calcular()` ela seria executada na hora, e não no clique.

### 14.4 Formulários e `submit`: assumindo o controle

1. **Usuário envia** (clica em Enviar).
2. **Recarregamento padrão** do navegador.
3. **Interceptação:** `event.preventDefault()`.
4. **Execução segura:** o cálculo roda e o resultado aparece (ex.: `Resultado: 42`).

```js
form.addEventListener('submit', function(event) {
  event.preventDefault();
});
```

> **Atenção:** sem o `preventDefault()`, a página pisca, recarrega e **todo o seu cálculo é perdido** instantaneamente.

### 14.5 Manipulação avançada: classes CSS via JavaScript

**JavaScript dita a regra. CSS cuida do visual.**

```js
let nota = 8;

if (nota >= 7) {
  res.classList.remove('reprovado');
  res.classList.add('aprovado');
}
```

```css
.aprovado {
  background-color: green;
  color: white;
}
```

Resultado: aparece o aviso verde "Aluno Aprovado!".

| Método | Faz o quê |
|---|---|
| `classList.add('x')` | Adiciona a classe |
| `classList.remove('x')` | Remove a classe |
| `classList.toggle('x')` | **Adiciona se não tiver, remove se já tiver** (ótimo para botões liga/desliga) |

> **Dica do slide:** `classList.toggle('dark-mode')`.

### 14.6 Arrays: guardando múltiplos valores

```js
let frutas = ["Maçã", "Banana", "Uva"];
```

| Código | Significado |
|---|---|
| `frutas[0]` | O primeiro item. **O primeiro índice é SEMPRE 0!** |
| `frutas[1]`, `frutas[2]` | Banana, Uva |
| `frutas.length` | Tamanho total (neste momento = **3**) |
| `frutas.push('Laranja')` | **Adiciona ao final** do array |

Analogia do slide: um **armário** com gavetas numeradas a partir do 0.

### 14.7 Estruturas de repetição: o loop `for` clássico

Automação em vez de repetição manual.

```js
for (let i = 0; i < frutas.length; i++) {
  console.log(frutas[i]);
}
```

| Parte | Nome | Função |
|---|---|---|
| `let i = 0` | **Início** | Onde começa |
| `i < frutas.length` | **Condição** | Até quando roda |
| `i++` | **Incremento** | O passo |

**Linha do tempo (3 frutas):**

| Volta | `i` | Executa |
|---|---|---|
| 1ª | 0 | `console.log(frutas[0])` |
| 2ª | 1 | `console.log(frutas[1])` |
| 3ª | 2 | `console.log(frutas[2])` |
| fim | 3 | **3 não é < 3**, então o loop termina |

### 14.8 O loop `for...of`: a forma elegante

```js
// FOR CLÁSSICO
for (let i = 0; i < frutas.length; i++) {
  console.log(frutas[i]);
}

// FOR...OF
for (let fruta of frutas) {
  console.log(fruta);
}
```

| | `for` clássico | `for...of` |
|---|---|---|
| Prós | **Controle total.** Excelente se você precisa saber a **posição exata** do item ou quer **pular itens** (ex.: de 2 em 2) | **Vai direto ao valor.** Muito mais fácil de ler e escrever; perfeito para **varrer todos os itens do início ao fim** |

### 14.9 Array + DOM: criando listas dinâmicas

Três passos: **1. dados na memória (JS)** → **2. o loop construtor** → **3. injeção na tela (DOM)**.

```js
let lista = ["Monitor", "Mouse"];     // 1. dados na memória

let html = '';                        // (começa vazio)
for (let item of lista) {             // 2. o loop construtor
  html = html + '<li>' + item + '</li>';
}

div.innerHTML = html;                 // 3. injeção na tela
```

Resultado na tela: uma lista com Monitor e Mouse.

> **A mágica:** o JavaScript transforma os dados da memória em **texto HTML** e injeta na tela. **A página é apenas um reflexo dos seus arrays!**

**Exemplo completo** (montado por mim a partir do slide):

```html
<ul id="lista"></ul>
```

```js
let lista = ["Monitor", "Mouse"];
let div = document.querySelector('#lista');   // aqui o "div" do slide é o <ul>

let html = '';
for (let item of lista) {
  html = html + '<li>' + item + '</li>';
}
div.innerHTML = html;
```

| | `.textContent` | `.innerHTML` |
|---|---|---|
| O que escreve | Só **texto** | Texto **interpretado como HTML** (tags viram elementos) |
| Quando usar | Mostrar um resultado simples | Montar listas/HTML a partir de dados |

> **Cuidado (observação minha, fora do slide):** se você injetar com `innerHTML` um texto digitado pelo usuário, ele pode conter HTML ou script (risco de **XSS**). Em sistema real, valide ou use `textContent`.

### 14.10 Exemplo integrador: o Sistema de Compras ("Projeto Mestre")

Três camadas, como no slide:

| Camada | O que faz | Trecho do slide |
|---|---|---|
| **Interface e entrada (HTML)** | Formulário: Nome do Produto, Preço, Qtd e botão Adicionar | `form.addEventListener('submit', adicionar);` + `event.preventDefault();` |
| **Lógica de negócio (JS)** | Calcula o total, guarda no array e **limpa os campos** do formulário | `let total = preco * qtd;` e `produtos.push(nome + ' - R$ ' + total);` |
| **Renderização (DOM)** | Percorre o array e atualiza a lista HTML | `for (let item of produtos) { // Atualiza lista HTML }` |

Resultado esperado na tela: `Notebook - R$ 3500`, `Mouse - R$ 150`, `Teclado - R$ 200`.

**Exemplo completo** (montado por mim a partir dos trechos do slide):

```html
<form id="form">
  <label for="nome">Nome do Produto</label>
  <input type="text" id="nome" required>

  <label for="preco">Preço</label>
  <input type="number" id="preco" min="0" step="0.01" required>

  <label for="qtd">Qtd</label>
  <input type="number" id="qtd" min="1" required>

  <button type="submit">Adicionar</button>
</form>

<ul id="lista"></ul>
```

```js
let produtos = [];                                    // FORA da função (senão zera a cada envio)
const form = document.querySelector('#form');
const lista = document.querySelector('#lista');

function adicionar(event) {
  event.preventDefault();                             // evita recarregar

  let nome = document.querySelector('#nome').value;
  let preco = Number(document.querySelector('#preco').value);
  let qtd = Number(document.querySelector('#qtd').value);

  let total = preco * qtd;                            // lógica
  produtos.push(nome + ' - R$ ' + total);             // guarda no array

  document.querySelector('#nome').value = '';         // limpa os campos
  document.querySelector('#preco').value = '';
  document.querySelector('#qtd').value = '';

  let html = '';                                      // renderiza a lista
  for (let item of produtos) {
    html = html + '<li>' + item + '</li>';
  }
  lista.innerHTML = html;
}

form.addEventListener('submit', adicionar);
```

> **Passo a passo:** formulário → `submit` → `preventDefault` → ler com `.value` (+ `Number`) → calcular → `push` no array → limpar campos → `for...of` monta o HTML → `innerHTML` mostra na tela.

### 14.11 Guia de sobrevivência: erros comuns (do slide)

| Sintoma (o que você vê) | Causa (diagnóstico) | Solução (remédio) |
|---|---|---|
| A soma de 5 + 5 deu **55** na tela | Esqueceu de converter texto para número | Envolva o input com `Number(input.value)` |
| O **primeiro item** da lista sumiu ou foi ignorado | Começou o contador do loop no 1 | No array, o primeiro índice é sempre `let i = 0` |
| Apareceu **'undefined'** na tela | Usou `<=` em vez de `<` no loop `for`, tentando ler uma gaveta que não existe | Use `i < array.length` (**sem o igual**) |
| A página **pisca** e o resultado desaparece num instante | O botão `submit` está recarregando a página (comportamento padrão) | Use `event.preventDefault()` **no início** da função |

### 14.12 Mapa mental do desenvolvedor web

| Linguagem | Metáfora | Papel |
|---|---|---|
| **HTML** | Os ossos | Estrutura e semântica |
| **CSS** | A pele | Aparência e design |
| **JavaScript** | O cérebro | Lógica e comportamento |

| Peça | Metáfora | Função |
|---|---|---|
| **Evento** | O gatilho | Dispara uma ação |
| **Função** | A máquina | Executa uma tarefa |
| **Array** | O armário | Guarda vários dados |
| **Repetição** | O braço | Percorre os dados |
| **DOM** | A ponte | Liga o JS ao HTML/CSS |

---

## §15. Processar dados: `find`, `filter`, `map`, `sort` (arrays de objetos)

*(Fonte: Processamento_de_Dados_em_JavaScript.pdf, 15 slides, aula de 11/11/2026. O exemplo integrado do 15.13 e a resolução do `reduce` (15.14) foram montados por mim a partir dos slides.)*

> **Ideia central do slide ("A linha de montagem"):** como localizar um aluno, listar só os aprovados e ordenar o boletim **na tela, sem perder a lista original**? Resposta: uma "linha de montagem" de métodos de array (`find`, `filter`, `map`, `sort`) que trabalham sobre uma **base intocada**.

### 15.1 A matéria-prima: array de objetos

Dados estruturados vivem em **objetos**; listas vivem em **arrays**; juntos, formam o "banco de dados em memória".

```js
const alunos = [
  { id: 1, nome: 'Ana',   media: 8.5, freq: 80, situacao: 'Aprovado' },
  { id: 2, nome: 'Bruno', media: 4.0, freq: 90, situacao: 'Reprovado por Nota' },
  { id: 3, nome: 'Carla', media: 6.0, freq: 60, situacao: 'Reprovado por Frequência' }
];
```

**Regras de negócio do slide** (nessa ordem):

| Ordem | Condição | Resultado |
|---|---|---|
| 1º | Frequência `< 75%` | Reprova (por frequência) |
| 2º | Média `< 5` | Reprova (por nota) |
| 3º | Média de `5` a `6.9` | Recuperação |
| 4º | Média `>= 7` | Aprova |

### 15.2 Callbacks e arrow functions

**Callback** = uma função **passada como parâmetro** para outra. Você entrega a "receita"; quem executa é o JavaScript, no momento certo.

- **Passar** a função (callback): `verificarAprovacao` (sem parênteses).
- **Executar** a função: `verificarAprovacao()` (com parênteses).

| Tradicional | Arrow function |
|---|---|
| `function verificarAprovacao(aluno) { return aluno.media >= 7; }` | `const verificarAprovacao = (aluno) => aluno.media >= 7;` |

```js
// Tradicional
function verificarAprovacao(aluno) {
  return aluno.media >= 7;
}

// Arrow function: o return é IMPLÍCITO quando não usamos chaves {}
const verificarAprovacao = (aluno) => aluno.media >= 7;
```

> **Cuidado (slide "Controle de qualidade"):** se você usar **chaves `{}`** na arrow function e esquecer o `return`, o resultado é `undefined`. Num `map`, você teria um array cheio de `undefined`.
>
> **Observação minha, fora do slide:** o slide mostra a linha `const verificarAprovacao =` repetida duas vezes (parece um defeito de diagramação). Escreva só uma vez.

### 15.3 O arsenal: qual método usar?

| Método | Propósito | O que retorna |
|---|---|---|
| `forEach` | Percorre a lista para **executar uma ação** (ex.: `console.log`) | `undefined` (nada) |
| `map` | **Transforma** cada item, gerando uma lista nova **com o mesmo tamanho** | Novo array (modificado) |
| `filter` | **Seleciona** os itens que passam num teste (condição verdadeira) | Novo array (menor ou igual) |
| `find` | Encontra o **primeiro** item que passa no teste e **para** a busca | Um único objeto (ou `undefined`) |
| `sort` | **Ordena** (com função comparadora) | O **próprio array**, alterado (ver 15.7) |

### 15.4 `find()`: a máquina de extração (um registro único)

Localiza **exatamente um registro**. Ideal para buscar por **identificadores exclusivos (ids)**.

```js
const alunoEncontrado = alunos.find(aluno => aluno.id === 2);
// retorna o objeto: { id: 2, nome: 'Bruno', ... }
```

> **E se o id for 99?** O JavaScript **não quebra**: `find` retorna `undefined`. **Sempre trate esse caso** antes de ler `alunoEncontrado.nome` na tela.

```js
// Observação minha (o slide só avisa; este exemplo é meu):
if (alunoEncontrado === undefined) {
  console.log('Aluno não encontrado');
} else {
  console.log(alunoEncontrado.nome);
}
```

### 15.5 `filter()`: a máquina de seleção (um subconjunto)

Cria um **subconjunto** de dados. **Não altera** os dados originais; entrega uma **lista nova** com as correspondências.

```js
const aprovados = alunos.filter(aluno => aluno.situacao === 'Aprovado');
// retorna um ARRAY: [ { id: 1, nome: 'Ana', ... } ]
```

> **E se ninguém estiver aprovado?** `filter` **não** retorna `undefined`: retorna um **array vazio `[]`**. Na interface, verifique `if (aprovados.length === 0)` para exibir "Nenhum resultado".

### 15.6 `find` × `filter`: teste de diagnóstico

Mesma condição nos dois: `aluno.media >= 6`.

| | `alunos.find(a => a.media >= 6)` | `alunos.filter(a => a.media >= 6)` |
|---|---|---|
| Retorna | **Um objeto** (o primeiro que passou) | **Um array** com todos que passaram |
| No exemplo do slide | O objeto `Ana` (é a primeira da lista) | `[ Ana, Carla ]` (as duas têm média `>= 6`) |
| Vazio? | `undefined` | `[]` |
| Use para | Detalhes de **UM** item (abrir perfil) | Listar **grupos** (relatório de aprovados) |

### 15.7 `sort()`: a máquina de organização

Sem parâmetros, o `sort()` **converte tudo em texto** (o número `10` viraria antes do `2`!). Por isso **sempre** passe uma **função comparadora** `(a, b) => ...`.

```js
// Numérico, crescente (para decrescente, inverta: b - a)
alunos.sort((a, b) => a.media - b.media);

// Texto: respeita acentuação e ordem alfabética local
alunos.sort((a, b) => a.nome.localeCompare(b.nome));
```

**Como funciona o comparador:** `(a, b)` são dois alunos "na balança". O slide diz: *se a conta der negativo, "a desce" na lista; positivo, "a sobe"; zero, ficam no mesmo lugar.*

| O comparador retorna | Efeito real no JavaScript (observação minha) |
|---|---|
| **Negativo** | `a` fica **antes** de `b` |
| **Positivo** | `a` fica **depois** de `b` |
| **Zero** | Mantém a ordem relativa |

> **Observação minha, fora do slide:** as palavras "desce/sobe" do slide são ambíguas e, lidas ao pé da letra, parecem o contrário do que o JavaScript faz. Não se prenda a elas: decore que **`a - b` = crescente** (menor primeiro) e **`b - a` = decrescente** (maior primeiro). O exemplo do próprio slide (`a.media - b.media`, crescente) está certo. Teste no Console se tiver dúvida.

### 15.8 A regra de ouro: `sort()` **altera** o array original

Ao contrário de `filter` e `map`, o `sort()` **muda fisicamente** o array. Se você ordenar a base principal diretamente, **perde a ordem de cadastro original para sempre**.

```js
// ERRO: sobrescreve a base!
alunos.sort((a, b) => a.media - b.media);

// CORRETO: faz uma cópia com slice() e ordena a cópia
const copia = alunos.slice().sort((a, b) => a.media - b.media);
```

> **Regra de ouro da arquitetura (slide):** **nunca** salve a lista filtrada ou ordenada **por cima** da variável da lista original de dados!

### 15.9 `map()`: a máquina de transformação

O `map` **extrai ou remodela** os dados originais. Use para criar **relatórios simplificados** (ex.: enviar a um gráfico ou gerar um CSV). **Não use `map` só para atualizar a tela**: para isso, use `forEach` ou `for...of`.

```js
const relatorioSimples = alunos.map(aluno => {
  return {
    nome: aluno.nome,
    media: aluno.media
  };
});
// gera uma nova lista de objetos "leves": [{ nome: 'Ana', media: 8.5 }, ...]
```

| Entrada (3 alunos) | Saída |
|---|---|
| `{ id: 123, nome: 'Ana', media: 8.5, freq: 90, situacao: 'Aprovado' }` e outros | `{ nome: 'Ana', media: 8.5 }` e outros (mesmo tamanho, menos campos) |

### 15.10 Busca por texto: "humanos × máquinas"

O computador diferencia **maiúsculas** e **espaços ocultos**. É preciso **higienizar** a entrada humana antes da busca.

```js
const termoBusca = '  ana '.trim().toLowerCase();

const resultados = alunos.filter(aluno =>
  aluno.nome.toLowerCase().includes(termoBusca)
);
```

| Método | O que faz |
|---|---|
| `.trim()` | Remove espaços no **início e no fim** |
| `.toLowerCase()` | Tudo minúsculo ("compara laranjas com laranjas") |
| `.includes(termo)` | Busca **trechos em qualquer parte** do nome |

### 15.11 Filtros combinados: texto + situação (`&&` e `||`)

Dá para encadear lógicas em um único `filter` com `&&`.

```js
const filtrados = alunos.filter(aluno => {
  const bateuNome = aluno.nome.toLowerCase().includes(termoBusca);
  const bateuSit  = (filtroSit === 'Todos') || (aluno.situacao === filtroSit);

  return bateuNome && bateuSit;
});
```

> **Curto-circuito lógico (`||`):** a opção `'Todos'` cria um curto-circuito. Se `filtroSit` for `'Todos'`, a segunda parte da condição **nem é testada**, e a situação do aluno passa livremente pelo filtro.

### 15.12 Conectando à interface: identidade × posição

> **Nunca use a posição da lista (`index`) para editar ou excluir.** Se você filtrar a lista, a Ana que estava na posição `[2]` pode virar a posição `[0]`. **Use sempre o `aluno.id`** (a "âncora fixa").
>
> **Identidade (id) é constante; posição (index) é volátil.**

**Eventos modernos na interface:**

| Evento | Quando dispara | Uso típico |
|---|---|---|
| `click` | (já conhecido) | Botões de ação (Excluir, Salvar) |
| `input` | **A cada letra digitada** | Barra de busca, resposta em tempo real |
| `change` | Quando o usuário **finaliza a escolha** | `<select>` de situações |

Sempre passe a lista resultante das operações para a sua função `renderizar(lista)`.

### 15.13 A arquitetura da linha (pipeline visual)

```text
[Base de dados] → [Filtrar] → [Copiar] → [Ordenar] → [Renderizar DOM]
 array original    .filter()   .slice()    .sort()     limpar <tbody> e
 intocável         (busca +                (no clone,  usar textContent
 (alunos)          select)                 conforme a  no resultado final
                                           escolha)
```

**Exemplo integrado (montado por mim a partir dos slides; os slides mostram só as peças):**

```js
const alunos = [ /* a base: nunca é ordenada nem sobrescrita */ ];

const inputBusca  = document.querySelector('#busca');
const selectSit   = document.querySelector('#filtro-situacao');
const selectOrdem = document.querySelector('#ordem');
const tbody       = document.querySelector('#tabela tbody');

function renderizar(lista) {
  tbody.innerHTML = '';                       // limpa antes de reconstruir (evita duplicação)

  if (lista.length === 0) {                   // lista vazia: avisa o usuário
    const tr = document.createElement('tr');
    const td = document.createElement('td');
    td.colSpan = 3;
    td.textContent = 'Nenhum resultado';
    tr.appendChild(td);
    tbody.appendChild(tr);
    return;
  }

  for (const aluno of lista) {
    const tr = document.createElement('tr');
    for (const valor of [aluno.nome, aluno.media, aluno.situacao]) {
      const td = document.createElement('td');
      td.textContent = valor;                 // textContent: seguro contra HTML injetado
      tr.appendChild(td);
    }
    tbody.appendChild(tr);
  }
}

function atualizarTela() {
  const termoBusca = inputBusca.value.trim().toLowerCase();
  const filtroSit  = selectSit.value;

  const filtrados = alunos.filter(aluno => {
    const bateuNome = aluno.nome.toLowerCase().includes(termoBusca);
    const bateuSit  = (filtroSit === 'Todos') || (aluno.situacao === filtroSit);
    return bateuNome && bateuSit;
  });

  const copia = filtrados.slice();            // clone seguro

  if (selectOrdem.value === 'media') {
    copia.sort((a, b) => b.media - a.media);  // decrescente
  } else {
    copia.sort((a, b) => a.nome.localeCompare(b.nome));
  }

  renderizar(copia);
}

inputBusca.addEventListener('input', atualizarTela);
selectSit.addEventListener('change', atualizarTela);
selectOrdem.addEventListener('change', atualizarTela);

atualizarTela();                              // primeira renderização
```

> **Observação minha, fora do slide:** `filter` já devolve um array novo, então o `slice()` ali é redundante. Ele é **obrigatório** quando você ordena a lista original diretamente (15.8). Mantive porque o pipeline do slide tem a etapa "Copiar", e ela é inofensiva.

### 15.14 Controle de qualidade e prática

- **Depuração:** `console.table(alunos)` mostra os objetos **alinhados em uma tabela** no Console.
- **Checklist da prática (slide, 21h às 22h):**
  - [ ] Barra de busca por nome (`trim` + `toLowerCase`).
  - [ ] Filtro `<select>` por **Situação**.
  - [ ] Ordenar por **Nome** ou **Média** (**sem destruir** os dados originais).
  - [ ] Botão **"Limpar Filtros"**.
  - [ ] Testar cenários: **lista vazia** e **recarregamento**.
- **Desafio opcional do slide:** usar `.reduce((acc, aluno) => acc + aluno.media, 0)` para calcular a **média geral da turma**, **protegendo contra divisão por zero**.

```js
// Resolução minha (o slide só dá a dica do reduce):
const soma = alunos.reduce((acc, aluno) => acc + aluno.media, 0);
const mediaGeral = alunos.length === 0 ? 0 : soma / alunos.length;   // evita dividir por zero
```

`reduce((acc, aluno) => ..., 0)`: `acc` é o **acumulador** (começa em `0`, o segundo argumento); a cada aluno você devolve o novo valor do acumulador.

---

## §16. Dominando JavaScript e JSON: fluxo, arrays, objetos e a ponte para o JSON

*(Fonte: Dominando_JavaScript_e_JSON.pdf, 15 slides, "O Blueprint dos Dados". Revisa o que já vimos (§13 e §14) e fecha com JSON. As respostas do desafio (16.13) marcadas como "minha" são minhas.)*

> **Roteiro do slide:** **1. Lógica e Repetição** → **2. Estruturação (arrays/objetos)** → **3. Comunicação (JSON)**.

### 16.1 Revisão rápida: o básico

```js
let x = 10;
const y = 'Olá';
Number('5');

if (x > 5) { /*...*/ } else { /*...*/ }

function somar(a, b) {
  return a + b;
}
```

### 16.2 Anatomia do `for`

```js
for (let i = 0; i < 5; i++) {
  console.log(i);          // 0, 1, 2, 3, 4
}
```

| Parte | Papel (nome no slide) |
|---|---|
| `let i = 0` | **Ponto de partida** |
| `i < 5` | **Condição de parada** |
| `i++` | **Engrenagem** (soma 1 a cada volta) |

Para pular de 2 em 2: `i += 2`.

### 16.3 Os "gêmeos falsos" e os relacionais

| Operador | Compara | `5 == '5'` / `5 === '5'` |
|---|---|---|
| `==` | **Apenas valor** | `true` |
| `===` | **Valor + tipo** | `false` |

> **Sempre prefira `===` e `!==`** para evitar bugs ocultos.

**Relacionais:** `>` maior, `<` menor, `>=` maior ou igual, `<=` menor ou igual.

### 16.4 Operadores lógicos no mundo real

| Operador | Exemplo do slide | Significado |
|---|---|---|
| `&&` (E) | `nota >= 7 && freq >= 75` | Só passa se **TUDO** for verdadeiro |
| `\|\|` (OU) | `falta < 10 \|\| atestado === true` | Basta **UM** ser verdadeiro |
| `!` (NÃO) | `!(nota < 7)` | **Inverte** a lógica (verdadeiro vira falso) |

### 16.5 Repetição manual: `while` e `do...while`

```js
let cont = 1;
while (cont <= 5) {
  console.log(cont);   // 1, 2, 3, 4, 5
  cont++;              // sem isso: LAÇO INFINITO (trava o navegador)
}

let i = 10;
do {
  console.log('Executou B!');
  i++;
} while (i < 5);
```

- **`while` verifica antes de fazer.**
- **`do...while` garante pelo menos UMA execução**, mesmo que a condição comece falsa (aqui `10` não é menor que `5`, mas imprime `Executou B!` uma vez).

### 16.6 `switch/case`, `break` e `continue`

```js
let opcao = '2';
switch (opcao) {
  case '1': cadastrar(); break;
  case '2': consultar(); break;
  case '3': sair(); break;
  default:  erro();
}
```

> O **`break`** impede que o código continue executando os casos abaixo por acidente.

| Comando | Exemplo | Efeito |
|---|---|---|
| `break` | `if (i === 5) break;` | **Interrompe TUDO** (o loop acaba; no slide, para no 4) |
| `continue` | `if (i === 3) continue;` | **Pula só esta iteração** (no slide, o 3 não aparece) |

### 16.7 Arrays: a rua de caixas de correio

```js
let frutas = ['Maçã', 'Uva', 'Kiwi'];    // frutas.length = 3
// índices:  [0]     [1]    [2]   -> o índice começa SEMPRE em zero
```

Percorrendo:

```js
for (let i = 0; i < frutas.length; i++) {
  console.log(frutas[i]);
}

for (let fruta of frutas) {
  console.log(fruta);
}
// Maçã, Uva, Kiwi
```

**Métodos de manipulação (a caixa de ferramentas):**

| Método | O que faz | Exemplo (começando com `['Maçã','Uva','Kiwi']`) |
|---|---|---|
| `push(x)` | Adiciona **no fim** | `frutas.push('Pera')` |
| `pop()` | Remove **do fim** | `frutas.pop()` |
| `unshift(x)` | Adiciona **no início** (os outros andam +1) | `frutas.unshift('Manga')` |
| `shift()` | Remove **do início** (os outros andam −1) | `frutas.shift()` |
| `splice(1, 1)` | Remove a partir do índice `1`, **1 item** | `frutas.splice(1, 1)` (tira `'Uva'`) |
| `includes(x)` | Pergunta se existe | `includes('Uva')` → `true` |
| `indexOf(x)` | Devolve a **POSIÇÃO**, não o valor | `indexOf('Kiwi')` → `2` |

### 16.8 `forEach`, `for` e `for...of`: quando cada um

```js
nomes.forEach(function(nome) {
  console.log(nome);
});
```

| Forma | Característica (slide) |
|---|---|
| `for` | **Manual**, engrenagens visíveis (`i++`) |
| `for...of` | **Prático** para ler valores rapidamente |
| `forEach` | **Elegante**, foca na ação (função *callback*) |

**Domando strings ("lavagem de dados"):** o usuário digitou `"   aNa Maria   "`.

```js
let texto = '   aNa Maria   ';
texto = texto.trim();          // 'aNa Maria'
texto = texto.toLowerCase();   // 'ana maria'
texto.includes('ana');         // true
```

> **Observação minha:** no slide aparece o texto `toLowerdizse()` (erro de digitação). O método correto é **`toLowerCase()`**.

### 16.9 Objetos: o fichário do aluno

```js
let aluno = {
  nome: 'Ana',
  idade: 20,
  nota: 8
};

aluno.nome;                    // acesso por PONTO
aluno['nota'];                 // acesso por COLCHETES
aluno.situacao = 'Aprovada';   // adicionando nova propriedade
```

| | Organização | Como acessa |
|---|---|---|
| **Array** | **Ordem** | Posição numérica: `[0]`, `[1]` |
| **Objeto** | **Características** | Chaves nomeadas: `.nome` |

**Array de objetos** (escalando os dados) e varredura:

```js
let alunos = [
  { nome: 'Ana',   nota: 9 },
  { nome: 'Bruno', nota: 6 }
];

for (let aluno of alunos) {
  if (aluno.nota >= 7) {
    console.log(aluno.nome + ': Aprovado');
  } else {
    console.log(aluno.nome + ': Reprovado');
  }
}
// Ana: Aprovado
// Bruno: Reprovado
```

### 16.10 JSON: a linguagem universal da web

**JavaScript Object Notation** **não é um objeto na memória**: é um **retrato em formato de texto**.

| | Objeto JS (memória) | Texto JSON (transferência) |
|---|---|---|
| Natureza | "Fichário 3D vivo" na memória | **Texto puro**, plano e universal |
| Chaves | **Sem aspas** | **Obrigatoriamente entre "aspas duplas"** |
| Funções | **Pode executar** funções | Não carrega funções |
| Sintaxe | Flexível | **Rigorosa** |

```js
// Objeto JS
{ nome: 'Ana', nota: 9 }

// Texto JSON
{
  "nome": "Ana",
  "nota": 9
}
```

Tipos aceitos no JSON: **strings, números, booleans, `null`, arrays e objetos**.

> **Aviso do slide:** JSON **não é banco de dados**! E usar **aspas simples** nas chaves **quebra o arquivo inteiro**.

### 16.11 O ciclo de tradução: `JSON.stringify()` e `JSON.parse()`

```text
Objeto JS vivo ──JSON.stringify()──▶ Texto simples (pronto para a rede)
Objeto JS vivo ◀──JSON.parse()───── Texto simples
        typeof: object  →  string
```

```js
const texto = JSON.stringify(alunos);   // objeto/array → string
const lista = JSON.parse(texto);        // string → objeto/array
```

**Erro típico:** `SyntaxError: JSON.parse: unexpected character at line 1`. Acontece quando você faz `parse` de um **texto malformado**: faltou uma vírgula? Esqueceu as aspas duplas? A tradução quebra e o sistema para.

### 16.12 Exemplo integrador (partes 1 e 2): cadastro de alunos

**Parte 1: captura e memória** (formulário com "Nome do Aluno" e "Nota Final" e botão "Adicionar"):

```js
form.addEventListener('submit', function(event) {
  // Impede a página de recarregar
  event.preventDefault();

  // Validação rápida
  if (inputNome.value === '' || inputNota.value < /* ...cortado no slide... */) {
    /* ... */
  }

  // Cria objeto e injeta no array de memória
  let novoAluno = {
    nome: inputNome.value,
    nota: Number(inputNota.value)
  };
  listaDeAlunos.push(novoAluno);
});
```

> **Observação minha:** no slide, a linha do `if` aparece **cortada** (`inputNota.value <`). Eu não inventei o resto; use a validação completa da §17 (`trim`, `isNaN` e limites).

**Parte 2: renderização e exportação:**

```js
function renderizarTabela() {
  tbody.innerHTML = '';
  for (let aluno of listaDeAlunos) {
    let situacao = aluno.nota >= 7 ? 'Aprovado' : 'Reprovado';
    tbody.innerHTML += '<tr><td>' + aluno.nome + '</td><td>' + situacao + '</td></tr>';
  }

  // Gera a String JSON para salvar
  let dadosExportacao = JSON.stringify(listaDeAlunos);
  console.log(dadosExportacao);
}
// Console: [{"nome":"Ana","nota":9},{"nome":"Bruno","nota":6}]
```

- O `? :` é o **operador ternário**: `condição ? valorSeVerdadeiro : valorSeFalso`.
- **Atenção (observação minha):** este exemplo do slide usa `innerHTML +=`, que a **§17.3** (Aula 12) mostra como **inseguro** (XSS). Em trabalho, prefira `createElement` + `textContent`. Em prova, veja o que o enunciado pede.

### 16.13 Referência rápida

| Matriz de decisão ("canivete suíço") | Use quando |
|---|---|
| `if/else` | Caminhos baseados em **condições lógicas** |
| `switch` | **Menu exato** / casos específicos |
| `for` | Sei **exatamente quantas vezes** vou repetir |
| `while` | **Não sei quando vai parar** (depende do usuário) |
| Array | Lista **ordenada**, baseada em **posição** |
| Objeto | **Agrupamento** de detalhes de **uma única coisa** |

**Hall da fama dos erros:**

1. Confundir `=` (atribuição) com `===` (comparação).
2. **Laço infinito** no `while` (esquecer o contador).
3. **Off-by-one:** usar `i <= length` em vez de `i < length`.
4. Usar **aspas simples** nas chaves de um arquivo JSON.

**Desafio rápido do slide (respostas: as 1 e 3 estão no conteúdo; a 2 é minha):**

1. O que acontece se eu der `.push()` num array **completamente vazio**? *Resposta (minha, coerente com 16.7):* o item é adicionado e passa a ser o índice `0`.
2. `indexOf('Batata')` num array de frutas devolve qual número? *Resposta (minha, o slide não traz):* **`-1`** (não encontrado).
3. É possível armazenar um **array inteiro** dentro de uma chave de um JSON? *Resposta:* **sim** (arrays e objetos são tipos válidos do JSON, ver 16.10).

---

## §17. Cadastro com validação e `localStorage` (Aula 12)

*(Fonte: Aula12.pdf, 15 slides, "JavaScript: a evolução do cadastro", 28/10/2026. Os trechos de código são dos slides; o código do 17.11 foi montado por mim.)*

> **Pergunta de abertura do slide:** *Onde ficam os dados quando a tela apaga?* Fluxo do problema: **1. Cadastro → 2. Recarregar (F5) → 3. Perda de dados.** E a frase: **"Copiar o projeto anterior não significa compreender o seu fluxo."**

### 17.1 Separação de responsabilidades: **Dados → Cálculo → Tela**

| Camada | Papel | Regra do slide |
|---|---|---|
| **Dados puros** | Nome, notas, frequência | (a base) |
| **A caixa preta (cálculo isolado)** | Recalcula a **média** e a **situação** em toda alteração ou recarregamento | Funções que **só calculam** |
| **O monitor (renderização, DOM)** | Constrói a tabela | A tela **apenas reflete** os dados; **nunca os altera**. A função de renderizar **nunca executa um `push`** no array |

### 17.2 A caixa preta: regras da instituição

```js
function calcularMedia(n1, n2) {
  return (n1 + n2) / 2;
}

function determinarSituacao(media, freq) {
  if (freq < 75)    return 'Reprovado';
  if (media >= 7)   return 'Aprovado';
  if (media >= 5)   return 'Recuperação';
  return 'Reprovado';
}
```

Fluxograma do slide: **Frequência `< 75`?** → reprova. Senão: **Média `>= 7`?** → aprova; senão **Média `>= 5`?** → recuperação; senão → reprova por nota.

> **Atenção (slide):** **sem arredondamentos para decidir.** A regra matemática é absoluta (ex.: `6.99` **não** vira `7`).
>
> **Observação minha:** a função do slide devolve só `'Reprovado'` nos dois casos de reprovação, mas a matriz de testes (17.5) mostra os rótulos "Reprova por Frequência" e "Reprova por Nota". Se o enunciado pedir esses rótulos, retorne `'Reprovado por Frequência'` e `'Reprovado por Nota'` nos dois `return`.

### 17.3 Proteção da fronteira da tela: `innerHTML` × `createElement`

| Injeção **insegura** (`innerHTML`) | Renderização **segura** (DOM) |
|---|---|
| `tabela.innerHTML += '<td>' + nome + '</td>';` | `let td = document.createElement('td');` |
| | `td.textContent = nome;` |
| | `linha.appendChild(td);` |
| Se o nome for `<b>Ana</b>`, aparece **Ana em negrito**: o navegador **interpretou o HTML** (vulnerabilidade **XSS**) | Aparece o **texto literal** `<b>Ana</b>` (protegido) |

> **Nota (slide):** **limpe o `tbody` antes de reconstruir** para evitar duplicação.

### 17.4 Falhas humanas e limites matemáticos

- **`Number('') === 0`:** um campo **vazio** vira `0`, que parece uma nota válida! **Valide campos vazios antes** da conversão.
- Limites do slide: **notas de 0 a 10**, **frequência de 0 a 100**.
- **O array de memória não deve ser alterado** se a validação matemática falhar.

```js
let nomeLimpo = nome.trim();
if (nomeLimpo === '' || isNaN(nota1)) {
  alert('Dados inválidos!');
  return;   // aborta a operação imediatamente
}
```

> **Observação minha:** o `return` só aborta se esse `if` estiver **dentro de uma função** (por exemplo, a função do `submit`). O `alert` aparece no slide; um texto na tela (`textContent`) costuma ser mais amigável.

### 17.5 Matriz de testes estruturais

| Cenário | Notas | Frequência | Esperado |
|---|---|---|---|
| Ana | 8.0 e 9.0 | 85% | `8.5` \| Aprovado |
| Bruno | 6.0 e 6.0 | 90% | `6.0` \| Recuperação |
| Carlos (prioridade) | 9.0 e 8.0 | 60% | `8.5` \| Reprova por Frequência |
| Dina | 4.0 e 4.0 | 80% | `4.0` \| Reprova por Nota |

**Limites críticos testados:** `7 / 7 / 75` → **Aprova**; `5 / 5 / 75` → **Recuperação**; `10 / 10 / 74.9` → **Reprova**.

> **Dica minha:** o Carlos mostra por que a **frequência vem primeiro** na função: média `8.5` não salva quem tem `60%`.

### 17.6 JSON: traduzindo objetos para texto

- `typeof array === 'object'`: para distinguir um array de outros objetos, use **`Array.isArray(dados)`**.
- **`JSON.stringify()`** produz **apenas um texto**. Ele **NÃO salva nada por si só**.
- **`JSON.parse()`** faz o caminho de volta (texto → array/objeto).
- JSON é um formato de **tráfego** de dados, **não é um banco de dados**.

```js
JSON.stringify([{ id: 1, name: 'Ana' }, { id: 2, name: 'Bruno' }]);
// '[{"id":1,"name":"Ana"},{"id":2,"name":"Bruno"}]'
```

### 17.7 `localStorage`: o cofre do navegador

**Regras do cofre (slide):**

| Regra | Detalhe |
|---|---|
| **Chave exclusiva do projeto** | Ex.: `'aula-web-alunos-v1'` |
| Aceita **SOMENTE texto** (String) | Por isso o `JSON.stringify` antes de guardar |
| **`setItem(chave, texto)`** | Guarda |
| **`getItem(chave)`** | Resgata. **Retorna `null`** se estiver vazio |

```js
localStorage.setItem('aula-web-alunos-v1', JSON.stringify(alunos));   // guardar
const dadosCofre = localStorage.getItem('aula-web-alunos-v1');        // resgatar (texto ou null)
```

> **Aviso do slide:** o armazenamento é **local ao navegador e à origem** (HTTP local). **Não é backup em nuvem e não é sincronizado!**
>
> **Atenção do laboratório:** use **apenas dados fictícios de teste**. **Nunca insira senhas, documentos ou dados reais** no Storage local.

### 17.8 O ciclo de vida da aplicação

1. **Iniciar (Load):** ler o cofre → **parse** → **validar** → **recalcular** → **renderizar**.
2. **Nova entrada:** o usuário preenche e submete o formulário.
3. **Atualizar:** inserir os dados puros no **array de memória**.
4. **Refletir:** renderizar a tela novamente **a partir do array**.
5. **Persistir:** transformar em JSON e **salvar** (`setItem`).

> **Importante (slide):** o carregamento (passo 1) ocorre **APENAS UMA VEZ**, quando a página inicia. **Não recadastre itens em duplicidade.**

### 17.9 A mecânica de inicialização

*Cofre (`localStorage`) → Processamento → Array JS.* **Sem a chave definida, o sistema inicia com um array vazio, pronto para uso.**

```js
let dadosCofre = localStorage.getItem('aula-web-alunos-v1');

if (dadosCofre !== null) {
  let alunosSalvos = JSON.parse(dadosCofre);

  for (let aluno of alunosSalvos) {
    // Validar integridade e recalcular derivados
    alunos.push(aluno);
  }
}

renderizarTabela();
```

> **Observação minha:** a **primeira linha** do trecho está parcialmente coberta por um balão no slide; a chave `'aula-web-alunos-v1'` é a que aparece nas "Regras do cofre". Repare que o `for...of` **recalcula os derivados** (média, situação) em vez de confiar cegamente no que estava salvo.

### 17.10 Proteção de fronteira: `try / catch`

```js
try {
  // Tentativa de conversão
  JSON.parse(textoCorrompido);
} catch (erro) {
  console.warn('Aviso: Dados salvos estão inválidos.');
  // O sistema aborta a leitura, mas mantém a aplicação viva
}
```

**Conceito:** o array original **não deve ser destruído** se o texto resgatado do armazenamento estiver **corrompido** ou **exceder cotas**.

### 17.11 Falhas controladas e resiliência

- Se o JSON for **inválido estruturalmente**, gere um **aviso**, mas **conserve o valor original** na memória.
- **Bloqueie a gravação** nessa chave específica até que haja recuperação explícita.
- **NUNCA sobrescrever o cofre com `[]`** em caso de falha de leitura.
- O `localStorage` **não é backup vitalício**.

```js
// Montagem minha, juntando as regras do slide (o slide dá as regras, não este código):
let cofreCorrompido = false;
const CHAVE = 'aula-web-alunos-v1';

function carregar() {
  const dadosCofre = localStorage.getItem(CHAVE);
  if (dadosCofre === null) return;               // primeira vez: começa vazio

  try {
    const salvos = JSON.parse(dadosCofre);
    if (!Array.isArray(salvos)) throw new Error('Formato inesperado');
    for (const aluno of salvos) {
      alunos.push(aluno);                        // aqui entram validação e recálculo
    }
  } catch (erro) {
    cofreCorrompido = true;                      // bloqueia a gravação
    console.warn('Aviso: Dados salvos estão inválidos.');
  }
}

function salvar() {
  if (cofreCorrompido) return;                   // nunca sobrescrever o cofre com []
  localStorage.setItem(CHAVE, JSON.stringify(alunos));
}
```

### 17.12 Laboratório e bilhete de saída

**Checklist do laboratório (programação em dupla):**

- [ ] **Refatorar** o código da Aula 12: separar **Dados, Cálculo e Tela**.
- [ ] **Substituir concatenação** por `createElement` / `textContent`.
- [ ] **Implementar validações** (limites numéricos, campos vazios, `isNaN`).
- [ ] **Integrar `localStorage`** (Load inicial único e Save após cada cadastro).
- [ ] **Executar e validar a matriz de 4 testes** (incluindo falhas).

**Bilhete de saída (3 perguntas para você responder):**

1. **Onde os dados realmente "vivem"** e são processados enquanto a aplicação está rodando? *(No array, na memória; a tela só reflete.)*
2. **Por que o JSON, rodando sozinho, não garante a persistência?** *(`stringify` só gera texto; quem guarda é o `setItem`.)*
3. **O que ocorre com o cadastro se o usuário limpar o cache e os dados do navegador?** *(O `localStorage` é apagado e os dados somem; não é backup.)*

*(As respostas entre parênteses são minhas, a partir do conteúdo dos slides.)*

---

## §18. Edição de cadastro e API ViaCEP (Aula 14)

*(Fonte: Aula14.pdf, 15 slides, "Edição de cadastros e consulta à API ViaCEP". Os trechos de código são dos slides; o código do 18.13 foi montado por mim.)*

> **O que vamos construir (slide):** **1. Evoluir o sistema atual:** editar alunos **sem duplicar registros** na memória. **2. Conectar ao mundo real:** consultar o **ViaCEP** para preenchimento automático. **3. Consolidar o fluxo:** sincronizar **Tela (DOM), Memória (Array) e Disco (`localStorage`)**.

### 18.1 Como os dados viajam

```text
Formulário HTML → Objeto JavaScript → Array de alunos → JSON.stringify() → localStorage
 (input)          (memória temporária) (lista na memória)  (o "tradutor")     (disco)
```

**Pergunta do slide:** por que precisamos do `JSON.stringify()` antes de salvar? **Dica:** o disco só entende **texto puro**, não estruturas vivas do JavaScript.

### 18.2 O bug do `push`: cadastrar × editar

| | **Cadastrar** | **Editar** |
|---|---|---|
| O que faz | **Cria um novo espaço** na memória | **Identifica um espaço existente e o sobrescreve** |
| Tamanho do array | **Cresce** (`push`) | **Idêntico** |
| Se usar a lógica errada | (correto aqui) | O sistema cria um **clone** na tabela (**duplicação**) |

> **Regra do slide:** se usarmos a lógica de **cadastro** para salvar uma **edição**, o sistema criará um **clone** na tabela.

### 18.3 Mapeando a lógica de edição (passo a passo)

1. **Identificar:** capturar o **índice exato ou o id** do aluno ao clicar em **Editar**.
2. **Carregar:** preencher os campos (DOM) com os dados atuais do objeto.
3. **Alterar:** o usuário edita os inputs livremente.
4. **Recalcular:** atualizar as regras de negócio (ex.: `novaMedia`, `novaSituacao`).
5. **Persistir:** **sobrescrever o array**, salvar no `localStorage` e **re-renderizar**.

```js
// O coração da edição:
alunos[indiceEncontrado] = alunoAtualizado;
```

> **Lembrete da §15.12:** prefira **achar o aluno pelo `id`** (`find` / `findIndex`) em vez de confiar na posição da linha na tela.
>
> **Observação minha, fora do slide:** `findIndex` (devolve a posição, ou `-1`) não aparece nos slides lidos. Se não puder usá-lo, `find` pelo `id` já devolve o objeto, e você pode alterar as propriedades dele direto.

### 18.4 Formulário inteligente: dois modos em uma só tela

| | **Modo Novo Cadastro** | **Modo Edição** |
|---|---|---|
| Variáveis de controle ("ocultas") | `modoEdicao = false;` | `modoEdicao = true;` e `indiceEdicao = 3;` |
| Campos | Vazios | Preenchidos com os dados do aluno (ex.: Ana Silva) |
| Botões | **[Cadastrar Aluno]** | **[Salvar Alterações]** e **[Cancelar]** |

> **Regra de UX (slide):** o botão **Cancelar** é essencial. Ele deve **limpar os campos** e **devolver a tela ao Modo Cadastro**, **sem alterar a memória**. Os dados originais devem permanecer **intocados** se o usuário desistir.

### 18.5 Atividade prática: fluxo de edição (checklist do slide)

- [ ] **Setup:** cadastrar dois alunos **fictícios** (Carlos e Bia).
- [ ] **Ação:** clicar em **Editar** na linha da Bia.
- [ ] **Modificação:** alterar a **nota 1** e a **frequência**.
- [ ] **Validação lógica:** salvar e verificar se **média e situação** foram recalculadas.
- [ ] **Validação de estado:** confirmar que **não houve duplicação** (a lista continua só com Carlos e Bia).
- [ ] **Validação de persistência:** pressionar **F5**; os novos dados da Bia devem **sobreviver ao reload**.

### 18.6 O problema do endereço e o conceito de API

Ninguém quer digitar um endereço completo. Uma **API** (Interface de Programação de Aplicações) permite **terceirizar** esse trabalho: pedir a informação estruturada para outro sistema (como o **ViaCEP**) e receber uma resposta pronta para uso.

| Analogia do slide | Papel |
|---|---|
| **Cliente** | Nosso JavaScript |
| **O garçom** | **Fetch API** |
| **A cozinha** | Servidor **ViaCEP** |
| **Objeto JSON** | O endereço completo (a resposta) |

### 18.7 Dissecando a consulta: a URL e o pacote JSON

```text
https://viacep.com.br/ws/  01001000  /json/
 └── domínio base          └ parâmetro └ formato
                             (CEP fictício)
```

Resposta (JSON) e para onde cada propriedade vai:

| Propriedade do JSON | Vai para o input |
|---|---|
| `logradouro` (ex.: `Praça da Sé`) | `id='rua'` |
| `localidade` (ex.: `São Paulo`) | `id='cidade'` |
| `uf` (ex.: `SP`) | `id='estado'` |

> **Regra do slide:** é preciso **mapear as propriedades do objeto JSON** devolvido pelo servidor **diretamente para os campos de input** do formulário HTML.
>
> **Observação minha:** o formulário do slide também tem **Bairro**. A propriedade correspondente na resposta do ViaCEP é `bairro` (o slide só desenha três setas no exemplo). Confirme olhando a resposta real no Console.

### 18.8 Assincronicidade: `async` e `await`

| | Ideia (slide) |
|---|---|
| **Síncrono** ("o carro esporte") | O código executa instantaneamente, **linha por linha** |
| **Assíncrono** ("o caminhão de entrega") | **Requisição de rede (`fetch`)**: o código precisa **pausar e esperar** a internet responder |
| **`async`** | **Etiqueta** avisando ao JavaScript: "esta função lidará com o tempo de espera da internet" |
| **`await`** | **O freio de mão**: "pare a execução desta linha específica e só avance quando a resposta chegar" |

**Fluxo:** **Solicitar → Aguardar → Conferir → Ler JSON → Usar dados.**

### 18.9 Escrevendo a consulta com a Fetch API

```js
async function buscarEndereco(cep) {
  const url = `https://viacep.com.br/ws/${cep}/json/`;

  // 1. Solicita e aguarda o servidor responder
  const response = await fetch(url);

  if (response.ok) {
    // 2. Aguarda a conversão do texto para Objeto JS
    const dados = await response.json();
    return dados;
  }
}
```

- A **crase** (`` ` ``) cria uma **template string**; `${cep}` insere a variável no texto.
- **`response.ok`** confere se o servidor respondeu com sucesso.
- **`response.json()`** converte o corpo da resposta em objeto JS (também precisa de `await`).

> **Aviso de tipagem (slide):** mantenha o **CEP como texto (String)**, ex.: `'01001000'`. Se usar **Número** (`01001000`), o JS **remove o zero à esquerda** e a API **recusará** a consulta!

### 18.10 Tratamento de erros e UX (o "semáforo")

| Nível | Situação | O que fazer |
|---|---|---|
| **Amarelo: regra de negócio** (formato inválido) | O usuário digitou `'ABC'` ou `'123'` | **Valide no JS antes de enviar à API**: o CEP deve ter **exatamente 8 dígitos** |
| **Vermelho: resposta da API** (CEP inexistente) | A rede funcionou, mas o CEP não existe: a API devolve um JSON válido contendo **`{ 'erro': true }`** | Testar essa propriedade na resposta |
| **Apagado: infraestrutura** (falha de rede) | Sem internet, ou o ViaCEP caiu: o **`fetch` falha** | Capturar com **`try { ... } catch (error) { ... }`** sem quebrar o sistema |

> **Regra de ouro de UX (slide):** **sempre mostre o texto "Consultando..."** na tela durante a espera e **remova-o ao terminar, independente do resultado**.

### 18.11 Preenchendo o DOM (e o `.focus()`)

```js
document.getElementById('rua').value    = dados.logradouro;
document.getElementById('cidade').value = dados.localidade;

// Direcionar o usuário para o próximo passo lógico:
document.getElementById('numero').focus();
```

> **Observação do slide:** a API preenche as ruas, mas o usuário deve **sempre poder alterar o texto manualmente** caso falte numeração ou complemento.

### 18.12 Cadastro expandido: da tela para o disco

- **A API preenche APENAS o HTML da tela.** Os dados **ainda não estão salvos!**
- Clicar em **Salvar** lê **todo o HTML preenchido**, atualiza o **array na memória** e **só então** salva no `localStorage`.
- **Alerta de compatibilidade (slide):** e os alunos cadastrados em aulas anteriores que **não têm endereço**? Ao renderizar a tabela, o código precisa **prever a ausência de dados** para não quebrar:

```js
const ruaExibicao = aluno.rua || 'Sem endereço cadastrado';
```

O `||` funciona como **valor padrão**: se `aluno.rua` for `undefined` (ou vazio), usa o texto da direita.

### 18.13 Missão de integração: API + formulário (em duplas)

| Frente | Tarefas do slide |
|---|---|
| **HTML** | Adicionar inputs de **CEP, Rua, Número, Complemento, Bairro, Cidade e UF**; criar o botão **"Buscar CEP"** |
| **Eventos** | Criar a escuta de evento no botão "Buscar CEP" (ou no evento **`blur`** ao sair do campo CEP) |
| **Consumo** | Implementar **`async/await` com `fetch`** e bloco **`try/catch`**; tratar CEPs com **erro** ou **não encontrados** |
| **Persistência** | Atualizar as funções de **Cadastrar e Editar** para incluírem as **novas chaves de endereço** no objeto do Aluno **antes** de enviar ao `localStorage` |

**Montagem minha (juntando as peças dos slides; o slide não traz este código completo):**

```js
async function buscarEndereco(cep) {
  const url = `https://viacep.com.br/ws/${cep}/json/`;
  const response = await fetch(url);
  if (!response.ok) return null;
  return await response.json();
}

btnCep.addEventListener('click', async function () {
  const cep = inputCep.value.trim().replace('-', '');     // mantém como TEXTO

  // Amarelo: regra de negócio
  if (cep.length !== 8 || isNaN(cep)) {
    msgCep.textContent = 'CEP inválido: digite 8 números.';
    return;
  }

  msgCep.textContent = 'Consultando...';

  try {
    const dados = await buscarEndereco(cep);

    if (dados === null || dados.erro) {                   // Vermelho: CEP inexistente
      msgCep.textContent = 'CEP não encontrado.';
      return;
    }

    document.getElementById('rua').value    = dados.logradouro;
    document.getElementById('bairro').value = dados.bairro;
    document.getElementById('cidade').value = dados.localidade;
    document.getElementById('estado').value = dados.uf;
    document.getElementById('numero').focus();
    msgCep.textContent = '';
  } catch (error) {                                       // Apagado: falha de rede
    msgCep.textContent = 'Não foi possível consultar. Verifique sua conexão.';
  }
});
```

> **Observações minhas, fora do slide:**
> - Para **remover o "Consultando..." em qualquer resultado**, o jeito mais direto é sobrescrever a mensagem em cada caminho (como acima). O bloco `finally` também serve, mas **não aparece nos slides**.
> - A validação `cep.length !== 8 || isNaN(cep)` é simples e **não é perfeita** (aceitaria `'1.234567'`). Uma validação mais rígida usaria expressão regular, que **não vimos nos slides**.

### 18.14 Homologação: "quebrando o próprio sistema" (checklist de qualidade)

- [ ] Editei a nota de um aluno e **salvou sem duplicar** na tabela?
- [ ] Cliquei em **Editar** e depois em **Cancelar**: os dados na tela e na memória **voltaram ao normal**?
- [ ] Busquei um **CEP real** (`01001-000`) e **rua/cidade preencheram sozinhos**?
- [ ] Busquei um **CEP inexistente** (`99999-999`) ou **inválido** (`'ABC'`): o sistema **avisou sem travar**?
- [ ] **Desliguei a internet** (Network offline) e testei: o **`try/catch` me protegeu**?
- [ ] **Salvei o aluno com endereço** e dei **F5**: tudo permaneceu na tela? **A exclusão continua funcionando?**

> **Frase final do slide:** **Teste como um usuário, corrija como um engenheiro.**

---

## §19. Projeto "Meu Perfil" (Aulas 2 e 3)

*(Fontes: Guia_aula_2, Aula3)*

### 19.1 Versão básica (Aula 2)

```html
<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <title>Meu Perfil</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <main class="perfil">
    <h1>Meu Perfil</h1>
    <p>Olá! Estou aprendendo Programação Web.</p>
    <h2>Meus hobbies</h2>
    <ul>
      <li>Ouvir música</li>
      <li>Assistir séries</li>
      <li>Aprender tecnologia</li>
    </ul>
    <a href="https://www.google.com" target="_blank">Visitar o Google</a>
  </main>
</body>
</html>
```

```css
body {
  font-family: Arial, sans-serif;
  background-color: #eaf2ff;
  color: #333;
  margin: 0;
  padding: 30px;
}
.perfil {
  max-width: 650px;
  margin: auto;
  background: white;
  padding: 30px;
  border-radius: 12px;
  box-shadow: 0 4px 12px rgba(0,0,0,.12);
}
h1 { color: #1e5aa8; }

/* Estilizando o link como botão */
a {
  display: inline-block;
  color: white;
  background-color: #1e5aa8;
  padding: 10px 16px;
  text-decoration: none;
  border-radius: 6px;
}
```

**Erros comuns (Aula 2):** não salvar os arquivos; errar o nome `style.css`; colocar o `link` do CSS **fora do `head`**.

### 19.2 Versão evoluída (Aula 3): layout com Flexbox

```html
<header class="cabecalho">...</header>

<main class="container">
  <aside class="perfil">
    <img src="imagens/foto-ana.jpg" alt="Foto de perfil de Ana sorrindo" class="avatar">
    <!-- nome, hobbies, links -->
  </aside>

  <section class="conteudo">
    <!-- tabela, vídeo (iframe), texto -->
  </section>
</main>

<footer class="rodape">...</footer>
```

```css
.container { display: flex; gap: 30px; align-items: flex-start; }
.cabecalho, .rodape { background-color: #2c3e50; color: white; text-align: center; padding: 20px; }
```

> **Layout = distribuir e organizar áreas na tela.** Sem layout, os blocos caem um embaixo do outro (fluxo padrão). `div`/`section` com `class` agrupam elementos; a **classe é o "crachá"** que o CSS usa para encontrar o alvo.

### 19.3 Erros comuns (Aula 3)

| Sintoma | Causa | Solução |
|---|---|---|
| Ícone de imagem quebrada | Caminho errado em `src` ou arquivo inexistente | Confira a pasta e a **ortografia exata** do nome |
| CSS não aplica | Nome de classe diferente no HTML e no CSS, ou faltou `{ }` / `;` | Confira a ortografia (`.perfil` × `class="perfil"`) e a sintaxe |
| Blocos não ficam lado a lado | Esqueceu `display: flex` no **elemento PAI** | Aplique o flex no contêiner que envolve as duas áreas |
| Escrevi o código e nada atualiza | Arquivo não foi salvo | `Ctrl+S` e atualize o navegador (`F5`) |

### 19.4 Missão (atividade)

Cabeçalho e rodapé estilizados, 2 áreas lado a lado com flex, avatar com `alt` e `border-radius`, `aside` com perfil e hobbies, tabela estruturada, **todo o CSS em arquivo externo**. Desafio extra: paleta de cores, seção "Minhas Redes" com links, 2ª imagem, vídeo do YouTube com `iframe`, tabela com linhas zebradas.

---

## §20. Projeto TecnoFix (simulado de Assistência Técnica)

*(Código que fizemos juntos. Estrutura exigida: `simulado/index.html`, `simulado/css/style.css`, `simulado/js/script.js`)*

### 20.1 Onde cada requisito está

| Requisito | Onde |
|---|---|
| Cabeçalho com logo + menu + 3 links | `<header>` + `<nav>` (flex) |
| Apresentação (título, descrição, botão) | `<section id="inicio" class="banner">` |
| Serviços (≥3, organizados) | `.servicos-grid` (**Grid** `auto-fit/minmax`) |
| Formulário (nome, e-mail, serviço, quantidade, valor, adicional, botão) | `<form id="form-orcamento" class="form-grid">` |
| `type`, `required`, `min`, `max`, `placeholder` | Campos do formulário |
| Cálculo + `if/else` + resultado na página | `js/script.js` |
| Responsividade | `width: 90%` + `max-width`, `@media`, grid adaptável |

### 20.2 `index.html` (completo)

```html
<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>TecnoFix | Assistência Técnica</title>
  <link rel="stylesheet" href="css/style.css">
</head>
<body>

  <!-- CABEÇALHO: logotipo + menu de navegação -->
  <header>
    <div class="container topo">
      <p class="logo">TecnoFix <span>Assistência Técnica</span></p>
      <nav>
        <a href="#inicio">Início</a>
        <a href="#servicos">Serviços</a>
        <a href="#orcamento">Orçamento</a>
        <a href="#contato">Contato</a>
      </nav>
    </div>
  </header>

  <main>

    <!-- ÁREA DE APRESENTAÇÃO -->
    <section id="inicio" class="banner">
      <div class="container">
        <h1>Seu notebook e seu celular de volta ao trabalho</h1>
        <p>
          A TecnoFix cuida de computadores, notebooks e celulares com
          diagnóstico claro, preço combinado antes do conserto e garantia
          em todos os serviços.
        </p>
        <a href="#orcamento" class="botao">Solicitar orçamento</a>
      </div>
    </section>

    <!-- ÁREA DE SERVIÇOS (organizada com CSS Grid) -->
    <section id="servicos" class="container">
      <h2>Nossos serviços</h2>
      <div class="servicos-grid">

        <article class="servico">
          <h3>Formatação com backup</h3>
          <p>Reinstalação do sistema, drivers e programas básicos, com cópia dos seus arquivos.</p>
          <p class="preco"><strong>R$ 120,00</strong> | prazo: 1 dia</p>
        </article>

        <article class="servico">
          <h3>Troca de tela</h3>
          <p>Substituição de telas de notebook e celular, com peça testada antes da entrega.</p>
          <p class="preco"><strong>R$ 450,00</strong> | peça inclusa</p>
        </article>

        <article class="servico">
          <h3>Limpeza preventiva</h3>
          <p>Limpeza interna, troca de pasta térmica e verificação de temperatura.</p>
          <p class="preco"><strong>R$ 80,00</strong> | prazo: 1 dia</p>
        </article>

        <article class="servico">
          <h3>Remoção de vírus</h3>
          <p>Varredura completa, remoção de ameaças e configuração de proteção.</p>
          <p class="preco"><strong>R$ 90,00</strong> | garantia de 30 dias</p>
        </article>

      </div>
    </section>

    <!-- FORMULÁRIO DE ORÇAMENTO -->
    <section id="orcamento" class="container">
      <h2>Calcule seu orçamento</h2>

      <form id="form-orcamento" class="form-grid">

        <div>
          <label for="nome">Nome do cliente</label>
          <input type="text" id="nome" name="nome" placeholder="ex: Maria Silva" minlength="3" required>
        </div>

        <div>
          <label for="email">E-mail</label>
          <input type="email" id="email" name="email" placeholder="ex: maria@email.com" required>
        </div>

        <div>
          <label for="servico">Serviço desejado</label>
          <select id="servico" name="servico" required>
            <option value="">Selecione...</option>
            <option value="Formatação com backup">Formatação com backup</option>
            <option value="Troca de tela">Troca de tela</option>
            <option value="Limpeza preventiva">Limpeza preventiva</option>
            <option value="Remoção de vírus">Remoção de vírus</option>
          </select>
        </div>

        <div>
          <label for="quantidade">Quantidade de aparelhos</label>
          <input type="number" id="quantidade" name="quantidade" placeholder="ex: 2" min="1" max="20" required>
        </div>

        <div>
          <label for="valor">Valor do serviço (R$)</label>
          <input type="number" id="valor" name="valor" placeholder="ex: 200" min="1" max="5000" step="0.01" required>
        </div>

        <div>
          <label for="adicional">Opção adicional</label>
          <select id="adicional" name="adicional" required>
            <option value="0">Nenhuma (R$ 0,00)</option>
            <option value="30">Busca e entrega (+ R$ 30,00)</option>
            <option value="50">Atendimento urgente (+ R$ 50,00)</option>
          </select>
        </div>

        <div class="campo-completo">
          <button type="submit">Calcular orçamento</button>
        </div>

      </form>

      <!-- RESULTADO: o JavaScript escreve nestes parágrafos -->
      <div class="resultado">
        <h3>Resultado</h3>
        <p id="res-cliente">Preencha o formulário e clique em calcular.</p>
        <p id="res-servico"></p>
        <p id="res-calculo"></p>
        <p id="res-adicional"></p>
        <p id="res-subtotal"></p>
        <p id="res-desconto"></p>
        <p id="res-total" class="total"></p>
        <p id="res-mensagem"></p>
      </div>
    </section>

  </main>

  <!-- RODAPÉ: também é a área "Contato" do menu -->
  <footer id="contato">
    <p>TecnoFix Assistência Técnica | Segunda a sexta, 9h às 18h</p>
    <p>WhatsApp: (54) 90000-0000 | contato@tecnofix.exemplo</p>
  </footer>

  <script src="js/script.js" defer></script>
</body>
</html>
```

### 20.3 `js/script.js` (completo, comentado)

```js
// 1. Busca o formulário no DOM
const form = document.querySelector('#form-orcamento');

// Pequena função auxiliar: 600 -> "R$ 600,00"
function formatar(numero) {
  return 'R$ ' + numero.toFixed(2).replace('.', ',');
}

// 2. Escuta o envio (clique no botão "Calcular orçamento")
form.addEventListener('submit', function (event) {
  event.preventDefault(); // evita recarregar a página

  // 3. Lê os valores do formulário (.value devolve texto)
  const nome = document.querySelector('#nome').value;
  const email = document.querySelector('#email').value;
  const servico = document.querySelector('#servico').value;

  // 4. Converte para número com Number()
  const quantidade = Number(document.querySelector('#quantidade').value);
  const valor = Number(document.querySelector('#valor').value);
  const adicional = Number(document.querySelector('#adicional').value);

  // 5. Cálculos
  const valorServicos = valor * quantidade;
  const subtotal = valorServicos + adicional;

  // 6. Regra com if/else: 10% de desconto a partir de R$ 500,00
  let desconto = 0;
  let mensagem = '';

  if (subtotal >= 500) {
    desconto = subtotal * (10 / 100);
    mensagem = 'Desconto de 10% aplicado: seu orçamento passou de R$ 500,00!';
  } else {
    mensagem = 'Faltam ' + formatar(500 - subtotal) + ' para ganhar 10% de desconto.';
  }

  const total = subtotal - desconto;

  // 7. Escreve o resultado na página com .textContent
  document.querySelector('#res-cliente').textContent = 'Cliente: ' + nome + ' (' + email + ')';
  document.querySelector('#res-servico').textContent = 'Serviço: ' + servico;
  document.querySelector('#res-calculo').textContent =
    'Cálculo: ' + formatar(valor) + ' × ' + quantidade + ' = ' + formatar(valorServicos);
  document.querySelector('#res-adicional').textContent = 'Adicional: ' + formatar(adicional);
  document.querySelector('#res-subtotal').textContent = 'Subtotal: ' + formatar(subtotal);
  document.querySelector('#res-desconto').textContent = 'Desconto: ' + formatar(desconto);
  document.querySelector('#res-total').textContent = 'Total: ' + formatar(total);
  document.querySelector('#res-mensagem').textContent = mensagem;
});
```

**Como funciona (resumo):**
1. `.value` devolve **texto**, então `Number()` converte antes de calcular.
2. `valorServicos = valor × quantidade`; `subtotal = valorServicos + adicional`.
3. `if (subtotal >= 500)` aplica 10% de desconto; senão o `else` mostra quanto falta.
4. `total = subtotal - desconto`; cada linha vai para a tela com `.textContent`.
5. O evento é `submit` (e não `click`) para o navegador validar `required`/`min`/`max` **antes**.

### 20.4 `css/style.css`: trechos-chave de layout (sem as cores)

```css
* { box-sizing: border-box; }

.container { width: 90%; max-width: 1100px; margin: 0 auto; }

/* Cabeçalho: Flexbox */
.topo { display: flex; justify-content: space-between; align-items: center; gap: 16px; }
nav { display: flex; flex-wrap: wrap; gap: 20px; }

/* Link com aparência de botão */
.botao { display: inline-block; padding: 14px 24px; border-radius: 6px; text-decoration: none; }

/* Serviços: Grid responsivo */
.servicos-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(220px, 1fr));
  gap: 24px;
}

/* Formulário: Grid de 2 colunas */
.form-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 20px; padding: 28px; border-radius: 8px; }
.campo-completo { grid-column: 1 / -1; }

input, select { width: 100%; padding: 10px; font-size: 16px; border-radius: 5px; }
input:focus, select:focus { outline: none; }
button { width: 100%; padding: 14px; font-weight: bold; border: none; border-radius: 6px; }
button:hover { cursor: pointer; }

/* Responsividade */
@media (max-width: 768px) {
  .topo { flex-direction: column; }
  .banner { padding: 48px 0; }
  .banner h1 { font-size: 2rem; }
}
@media (max-width: 600px) {
  .form-grid { grid-template-columns: 1fr; }
}
```

> O arquivo completo (com a paleta roxa e fundo preto) está em `simulado/css/style.css` do `simulado.zip`.

### 20.5 Extras que usei além dos slides (pode perguntar no professor)

- `step="0.01"` no `input type="number"` (aceitar centavos).
- `toFixed(2)` e `.replace('.', ',')` (formatar `R$ 600,00`).
- Uma função auxiliar `formatar()`.

---

## §21. Tabela de socorro: "por que não funciona?"

| Sintoma | Causa provável | Como corrigir |
|---|---|---|
| Imagem quebrada | Caminho/nome errado em `src` | Conferir pasta e ortografia (maiúsculas contam) |
| CSS não aplica | Classe com nome diferente; faltou `{ }` ou `;`; `link` fora do `head`; caminho errado | Conferir nomes e sintaxe; `href="css/style.css"` |
| Blocos não ficam lado a lado | Faltou `display: flex` **no pai** | Aplicar no container |
| Nada atualiza | Arquivo não salvo / cache | `Ctrl+S`, `F5` ou `Ctrl+F5` |
| `10 + 5 = 105` | `.value` é texto | `Number(...)` |
| Página recarrega ao enviar | Faltou `preventDefault()` | `event.preventDefault()` no `submit` |
| `Cannot read properties of null` | `id` do JS não bate com o HTML (ou script sem `defer`) | Conferir ids; usar `defer` |
| Rolagem horizontal no celular | Largura fixa ou imagem sem limite | `max-width: 100%`, `width: 90%` |
| Media query não "pega" | `max-width`/`min-width` invertidos; faltou o `viewport` | Conferir a direção |
| `align-content` sem efeito | Faltou `flex-wrap: wrap` | Adicionar `wrap` |
| Dado do formulário não viaja | Faltou `name` no `input` | Adicionar `name` |
| Primeiro item da lista sumiu | O loop `for` começou em `let i = 1` | Começar em `let i = 0` |
| Apareceu `undefined` na lista | Usou `<=` no loop (leu uma posição que não existe) | `i < array.length` (sem o igual) |
| A lista some ao adicionar o 2º item | O array foi declarado **dentro** da função (zera a cada envio) | Declarar `let produtos = [];` **fora** da função |
| A função roda sozinha ao carregar a página | `addEventListener("click", calcular())` com parênteses | Passar `calcular` **sem** parênteses |
| `map` devolveu array cheio de `undefined` | Arrow function com `{ }` e **sem `return`** | Colocar `return` ou tirar as chaves (§15.2) |
| `Cannot read properties of undefined` depois de um `find` | O `find` não achou e devolveu `undefined` | Testar `if (achado === undefined)` antes de usar (§15.4) |
| A lista original ficou ordenada/bagunçada | `sort()` aplicado direto na base | `alunos.slice().sort(...)` (§15.8) |
| Números ordenados como `10` antes de `2` | `sort()` sem função comparadora | `sort((a, b) => a - b)` (§15.7) |
| A busca não acha "Ana" digitando "ana " | Faltou higienizar a entrada | `.trim().toLowerCase()` nos dois lados (§15.10) |
| Excluir/editar mexe no aluno errado depois de filtrar | Usou a **posição** (`index`) e não o `id` | Localizar pelo `id` (§15.12) |
| Loop infinito trava o navegador | `while` sem atualizar o contador | `cont++` dentro do loop (§16.5) |
| Os casos do `switch` "vazam" | Faltou `break` | `break;` ao fim de cada `case` (§16.6) |
| `SyntaxError: JSON.parse ...` | Texto malformado (aspas simples, vírgula faltando) | Aspas duplas; `try/catch` no `parse` (§16.11, §17.10) |
| A nota vazia virou `0` e foi aceita | `Number('') === 0` | Validar campo vazio **antes** de converter (§17.4) |
| A tabela duplica linhas | Não limpou o `tbody`, ou carregou o cofre mais de uma vez | `tbody.innerHTML = ''`; Load **uma vez** (§17.3, §17.8) |
| Os dados somem ao dar F5 | Só estavam no array | `setItem` após cada alteração + Load ao iniciar (§17.7) |
| O `localStorage` guardou `[object Object]` | Faltou `JSON.stringify` | `setItem(chave, JSON.stringify(dados))` (§17.7) |
| O cofre foi apagado depois de um erro de leitura | Salvou `[]` por cima | Bloquear a gravação se a leitura falhou (§17.11) |
| Editar criou um aluno **clonado** | Usou `push` na edição | `alunos[indice] = atualizado` (§18.2, §18.3) |
| O ViaCEP recusa o CEP | CEP guardado como **número** (perdeu o zero à esquerda) | Manter como **String** (§18.9) |
| `Consultando...` fica na tela para sempre | A mensagem não foi trocada em todos os caminhos | Escrever uma mensagem em cada resultado (§18.10) |
| Alunos antigos mostram `undefined` no endereço | Não previu ausência de dados | `aluno.rua \|\| 'Sem endereço cadastrado'` (§18.12) |

---

## §22. Revisão final

### 22.1 Comparações que costumam cair

| Conceito A | Conceito B | Diferença |
|---|---|---|
| `<b>` | `<strong>` | Visual × com significado (importância) |
| `<i>` | `<em>` | Visual × ênfase no sentido |
| `div` | `section` | Neutra × com tema lógico (com título) |
| `section` | `article` | Agrupa por tema × conteúdo independente |
| `aside` | `footer` | Complementar × fecha o contexto |
| `class` (`.`) | `id` (`#`) | Reutilizável × único |
| `div p` | `div > p` | Qualquer nível × só filhos diretos |
| `h1 + p` | `h1 ~ p` | Só o primeiro irmão × todos os irmãos |
| `:hover` | `::before` | Estado (1 dois-pontos) × parte do elemento (2) |
| `padding` | `margin` | Espaço interno × externo |
| `content-box` | `border-box` | Width só do conteúdo × inclui padding e borda |
| `relative` | `absolute` | Mantém o espaço × sai do fluxo |
| `fixed` | `sticky` | Sempre fixo × cola ao atingir o ponto |
| `justify-content` | `align-items` | Eixo principal × eixo cruzado |
| `align-items` | `align-content` | Itens numa linha × linhas inteiras (precisa de `wrap`) |
| Flexbox | Grid | 1D × 2D |
| `auto-fit` | `auto-fill` | Colapsa colunas vazias × preenche |
| `max-width` (MQ) | `min-width` (MQ) | Desktop first × Mobile first |
| `let` | `const` | Reatribuível × fixa |
| `==` | `===` | Só valor × valor **e** tipo |
| `.value` | `.textContent` | Lê campo de formulário × lê/escreve texto na tela |
| Validação HTML | Validação JS | Nativa e rápida × personalizada e lógica |
| `type="submit"` | `type="button"` | Envia (dispara `submit`) × espera o JS |
| `onclick="..."` no HTML | `addEventListener` | Mistura HTML e JS (antigo) × HTML limpo e JS que escuta (moderno) |
| `for` clássico | `for...of` | Controle de posição e saltos × vai direto ao valor |
| `<` | `<=` no loop | Para no último item × lê uma gaveta que não existe (`undefined`) |
| `.textContent` | `.innerHTML` | Só texto × interpreta tags HTML |
| `classList.add` | `classList.toggle` | Sempre adiciona × alterna (liga/desliga) |
| `calcular` | `calcular()` | Passa a função (roda no evento) × executa na hora |
| `find` | `filter` | **Um** objeto (ou `undefined`) × **array** com todos (ou `[]`) |
| `map` | `forEach` | Cria **novo array** transformado × só executa uma ação (`undefined`) |
| `sort()` direto | `slice().sort()` | **Altera** a base × ordena uma **cópia** |
| `a - b` | `b - a` | Crescente × decrescente |
| `id` | `index` | Identidade **fixa** × posição **volátil** |
| `input` | `change` | A cada tecla digitada × ao finalizar a escolha |
| `while` | `do...while` | Verifica **antes** × executa **ao menos uma vez** |
| `break` | `continue` | Interrompe **todo** o loop × pula **só a iteração** |
| `push` / `pop` | `unshift` / `shift` | Mexem no **fim** × mexem no **início** |
| `includes` | `indexOf` | `true`/`false` × a **posição** (`-1` se não achar) |
| Objeto JS | Texto JSON | Chaves sem aspas, pode ter funções × **aspas duplas**, só texto |
| `JSON.stringify` | `JSON.parse` | Objeto → texto × texto → objeto |
| `JSON.stringify` | `localStorage.setItem` | Só **gera** o texto × **grava** no navegador |
| `innerHTML +=` | `createElement` + `textContent` | Interpreta HTML (risco de XSS) × texto literal e seguro |
| Cadastrar | Editar | `push` (cria espaço novo) × sobrescrever a posição existente |
| `response.ok` | `dados.erro` | Falha HTTP × CEP inexistente (JSON com `erro: true`) |
| Síncrono | Assíncrono (`await`) | Linha por linha × pausa e espera a rede responder |

### 22.2 Perguntas de revisão (cubra a resposta e tente)

1. Cite os 5 passos de uma requisição web.
2. Por que HTML não é linguagem de programação?
3. Quais atributos de `img` são essenciais e por quê?
4. Qual a diferença entre `<main>` e `<section>`? Quantos `<main>` pode haver?
5. Qual a diferença entre `id`, `name` e `for`?
6. Como o navegador valida um campo sem JavaScript?
7. Qual seletor vence: `p`, `.texto` ou `#destaque`? Qual a pontuação de `#destaque .texto p`?
8. O que `margin: 0 auto` faz? Com que outra propriedade costuma andar?
9. Como centralizar algo nos dois eixos com Flexbox? E com Grid?
10. Para que serve `repeat(auto-fit, minmax(200px, 1fr))`?
11. O que faz `grid-column: 1 / -1`?
12. Por que o `viewport` é necessário?
13. Qual a diferença entre Mobile First e Desktop First?
14. Por que `'10' + '5'` dá `'105'` e como corrigir?
15. O que o `preventDefault()` evita e por quê?
16. Escreva um `if/else if/else` de aprovado/recuperação/reprovado.
17. Escreva a regra de 10% de desconto a partir de R$ 500.
18. O que é uma função? Qual a diferença entre **parâmetro** e **retorno**?
19. Por que `onclick` no HTML é considerado o "jeito antigo"?
20. Cite 3 eventos importantes além de `click`.
21. O que fazem `classList.add`, `remove` e `toggle`?
22. Qual é o índice do primeiro item de um array? Como saber o tamanho? Como adicionar ao final?
23. Explique as 3 partes do `for` (início, condição, incremento). Por que o loop para em `i = 3` com 3 itens?
24. Quando usar `for` e quando usar `for...of`?
25. Como transformar um array em uma lista `<li>` na tela?
26. Por que a soma deu `55` e como corrigir? Por que o primeiro item sumiu?
27. O que é um *callback*? Qual a diferença entre passar `verificar` e executar `verificar()`?
28. Quando a arrow function tem `return` implícito? O que acontece se usar `{ }` e esquecer o `return` num `map`?
29. Qual a diferença entre `find` e `filter`? O que cada um devolve quando nada passa no teste?
30. Por que `sort()` sem comparador ordena `10` antes de `2`? Como ordenar números e como ordenar textos com acento?
31. Por que não se deve ordenar a base principal diretamente? Como fazer a cópia?
32. Escreva um `filter` que combine busca por nome e situação (com a opção "Todos").
33. Por que usar o `id` e não o `index` para editar ou excluir?
34. Quando usar `for`, `while`, `switch`? O que o `do...while` garante?
35. O que o `break` faz num `switch`? E o `continue` num loop?
36. Qual a diferença entre `push`, `pop`, `unshift`, `shift` e `splice`? O que `indexOf` devolve quando não acha?
37. Quais as diferenças entre um objeto JS e um texto JSON? O que quebra um JSON?
38. Por que `JSON.stringify` não "salva" nada? O que o `localStorage` aceita guardar?
39. O que `getItem` devolve quando a chave não existe? Por que o Load roda só uma vez?
40. Por que `Number('') === 0` é um perigo? Como validar com `trim` e `isNaN`?
41. Por que `innerHTML` com concatenação é inseguro? Qual a alternativa?
42. Para que serve o `try/catch` ao ler o `localStorage`? Por que nunca sobrescrever o cofre com `[]`?
43. Qual o "bug do `push`" na edição? Qual linha é o "coração da edição"?
44. Qual a função das variáveis `modoEdicao` e `indiceEdicao`? O que o botão Cancelar deve (e não deve) fazer?
45. O que fazem `async` e `await`? Por que o CEP deve ser String?
46. Quais os três tipos de falha na consulta ao ViaCEP (semáforo) e como tratar cada um?
47. Por que a API preencher os campos **não** significa que o dado foi salvo?

### 22.3 Mini-exercícios

1. Monte um menu com 3 links usando `nav` + `display: flex` + `gap: 20px`.
2. Faça 3 cards com Grid que viram 1 coluna abaixo de 600px.
3. Faça um formulário com nome (`required`), idade (`min="18"`) e um botão que mostre "maior de idade" ou "menor de idade" na tela.
4. Crie `function dobrar(n) { return n * 2; }` e mostre `dobrar(5)` na tela ao clicar num botão.
5. Monte um array com 3 nomes e mostre-os como `<li>` dentro de um `<ul>` usando `for...of` + `innerHTML`.
6. Faça um botão que alterna o tema escuro com `classList.toggle('dark-mode')`.
7. Refaça o Sistema de Compras: adicionar produto, listar na tela e limpar os campos.
8. Dado um array de alunos, use `filter` para listar só os com `media >= 7` e mostre "Nenhum resultado" se a lista vier vazia.
9. Ordene os alunos por média (decrescente) **sem alterar** o array original; confirme com `console.table`.
10. Faça uma barra de busca (evento `input`) que filtre por nome ignorando maiúsculas e espaços.
11. Calcule a média geral da turma com `reduce`, protegendo contra divisão por zero.
12. Salve o array de alunos no `localStorage` ao cadastrar e recarregue-o ao abrir a página; teste com F5 e com JSON corrompido (`try/catch`).
13. Crie o fluxo de edição (`modoEdicao`, `indiceEdicao`, Salvar/Cancelar) sem duplicar registros e confira após o F5.
14. Faça um botão "Buscar CEP" com `fetch`/`async`/`await` que preencha rua e cidade, trate CEP inválido e CEP inexistente e mostre "Consultando...".

---

*Fim do resumo. Bons estudos!*
