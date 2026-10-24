# Resumo de consulta: Programação Web (HTML, CSS, JS)

> **Como achar rápido:** cada seção tem um código `§N`. Use `Ctrl+F` e digite, por exemplo, `§9` para ir direto ao Flexbox.
> Cada bloco indica a **fonte** (qual PDF) entre parênteses.

---

## 0. Índice rápido: "Preciso de..."

| Preciso de... | Vá para | Busque por |
|---|---|---|
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
| Meu Perfil (projeto das aulas 2 e 3) | §14 | `perfil` |
| Site TecnoFix (código completo) | §15 | `TecnoFix` |
| "Por que não funciona?" | §16 | `sintoma` |
| Revisão final | §17 | `revisão` |

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

---

## §14. Projeto "Meu Perfil" (Aulas 2 e 3)

*(Fontes: Guia_aula_2, Aula3)*

### 14.1 Versão básica (Aula 2)

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

### 14.2 Versão evoluída (Aula 3): layout com Flexbox

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

### 14.3 Erros comuns (Aula 3)

| Sintoma | Causa | Solução |
|---|---|---|
| Ícone de imagem quebrada | Caminho errado em `src` ou arquivo inexistente | Confira a pasta e a **ortografia exata** do nome |
| CSS não aplica | Nome de classe diferente no HTML e no CSS, ou faltou `{ }` / `;` | Confira a ortografia (`.perfil` × `class="perfil"`) e a sintaxe |
| Blocos não ficam lado a lado | Esqueceu `display: flex` no **elemento PAI** | Aplique o flex no contêiner que envolve as duas áreas |
| Escrevi o código e nada atualiza | Arquivo não foi salvo | `Ctrl+S` e atualize o navegador (`F5`) |

### 14.4 Missão (atividade)

Cabeçalho e rodapé estilizados, 2 áreas lado a lado com flex, avatar com `alt` e `border-radius`, `aside` com perfil e hobbies, tabela estruturada, **todo o CSS em arquivo externo**. Desafio extra: paleta de cores, seção "Minhas Redes" com links, 2ª imagem, vídeo do YouTube com `iframe`, tabela com linhas zebradas.

---

## §15. Projeto TecnoFix (simulado de Assistência Técnica)

*(Código que fizemos juntos. Estrutura exigida: `simulado/index.html`, `simulado/css/style.css`, `simulado/js/script.js`)*

### 15.1 Onde cada requisito está

| Requisito | Onde |
|---|---|
| Cabeçalho com logo + menu + 3 links | `<header>` + `<nav>` (flex) |
| Apresentação (título, descrição, botão) | `<section id="inicio" class="banner">` |
| Serviços (≥3, organizados) | `.servicos-grid` (**Grid** `auto-fit/minmax`) |
| Formulário (nome, e-mail, serviço, quantidade, valor, adicional, botão) | `<form id="form-orcamento" class="form-grid">` |
| `type`, `required`, `min`, `max`, `placeholder` | Campos do formulário |
| Cálculo + `if/else` + resultado na página | `js/script.js` |
| Responsividade | `width: 90%` + `max-width`, `@media`, grid adaptável |

### 15.2 `index.html` (completo)

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

### 15.3 `js/script.js` (completo, comentado)

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

### 15.4 `css/style.css`: trechos-chave de layout (sem as cores)

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

### 15.5 Extras que usei além dos slides (pode perguntar no professor)

- `step="0.01"` no `input type="number"` (aceitar centavos).
- `toFixed(2)` e `.replace('.', ',')` (formatar `R$ 600,00`).
- Uma função auxiliar `formatar()`.

---

## §16. Tabela de socorro: "por que não funciona?"

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

---

## §17. Revisão final

### 17.1 Comparações que costumam cair

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

### 17.2 Perguntas de revisão (cubra a resposta e tente)

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

### 17.3 Mini-exercícios

1. Monte um menu com 3 links usando `nav` + `display: flex` + `gap: 20px`.
2. Faça 3 cards com Grid que viram 1 coluna abaixo de 600px.
3. Faça um formulário com nome (`required`), idade (`min="18"`) e um botão que mostre "maior de idade" ou "menor de idade" na tela.

---

*Fim do resumo. Bons estudos!*
