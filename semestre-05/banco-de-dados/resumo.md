# Banco de Dados — Resumo para Prova

> **Prioridade de estudo:**
> 1. Normalização: 1FN, 2FN, 3FN e dependências funcionais.
> 2. MER/DER e transformação para o modelo lógico.
> 3. Chaves: primária, estrangeira e candidata.
> 4. Fundamentos: SGBD, abstração e independência de dados.

## 1. Conceitos básicos

### Dado × informação

- **Dado:** valor bruto registrado no sistema, que sozinho pode não ter significado completo. Ex.: `2026-10-03`, `150`, `Maria`.
- **Informação:** dado interpretado em um contexto, com significado. Ex.: “Maria realizou uma compra de R$ 150 em 03/10/2026”.

### Banco de Dados (BD)

Um **Banco de Dados** é uma coleção organizada de dados relacionados, criada para representar informações de um domínio específico, como uma clínica, biblioteca, loja ou escola.

Um BD representa aspectos do mundo real, possui dados relacionados e tem uma finalidade definida; não é uma coleção aleatória de arquivos.

### BD × SGBD × SBD

| Termo | O que é | Exemplo |
|---|---|---|
| BD | Dados organizados | Dados de médicos, pacientes e consultas |
| SGBD | Software que gerencia o BD | MySQL, PostgreSQL, Oracle |
| SBD | Sistema completo | Dados + hardware + software + usuários |

**SGBD** é o software que cria, armazena, consulta, altera, protege e controla os dados.

## 2. Sistema de arquivos × SGBD

```text
Sistema de arquivos:
Aplicação → Arquivos

Sistema de banco de dados:
Aplicação → SGBD → Banco de Dados
```

### Problemas de sistemas de arquivos

- Redundância e inconsistência de dados
- Falta de padronização
- Dificuldade de consultas
- Falhas de segurança e integridade
- Dependência entre programas e arquivos
- Problemas com acesso simultâneo por vários usuários

### Vantagens do SGBD

- Compartilhamento de dados
- Redução de redundância desnecessária
- Integridade e segurança
- Backup e recuperação
- Controle de concorrência e transações
- Maior independência entre aplicações e dados

### Redundância

| Tipo | Significado |
|---|---|
| Controlada | O software conhece as cópias e mantém sua sincronização |
| Não controlada | As cópias não são sincronizadas automaticamente e podem divergir |

## 3. Operações e linguagens

| Operação | SQL | Finalidade |
|---|---|---|
| Inserção | `INSERT` | Adiciona registros |
| Consulta | `SELECT` | Recupera dados |
| Alteração | `UPDATE` | Modifica dados |
| Exclusão | `DELETE` | Remove dados |

| Linguagem | Nome | Função |
|---|---|---|
| DDL | Data Definition Language | Define estrutura: tabelas, colunas, chaves e regras |
| DML | Data Manipulation Language | Manipula dados: inserir, consultar, alterar e excluir |

## 4. Abstração e independência de dados

### Três níveis de abstração

| Nível | Também chamado de | Descreve |
|---|---|---|
| Físico | Interno | Como os dados são armazenados: arquivos, índices e estruturas internas |
| Lógico/conceitual | Esquema conceitual | Quais dados existem, relacionamentos e restrições |
| Externo | Visões | Apenas a parte necessária para cada usuário |

### Independência de dados

- **Independência física:** alterar armazenamento, arquivos ou índices sem mudar o esquema lógico ou os programas. Ex.: criar um índice para melhorar desempenho.
- **Independência lógica:** alterar o esquema lógico sem precisar reescrever os programas. Ex.: adicionar um atributo `Email` em Cliente.

### Esquema × instância

| Conceito | Significado |
|---|---|
| Esquema | Estrutura do banco/tabela |
| Instância | Dados existentes em um momento específico |

```text
Esquema: CLIENTE(CodCliente, Nome, CPF)
Instância: (1, 'Ana', '123.456.789-00')
```

## 5. Papéis no SBD

### Administrador de Dados

- Define e atualiza o esquema do BD
- Decide quais dados são relevantes à organização

### DBA — Administrador do SGBD

- Define armazenamento e estratégias de acesso
- Gerencia usuários e permissões
- Define controles de integridade
- Planeja backup e recuperação
- Monitora desempenho

### Tipos de usuário

| Tipo | Atuação |
|---|---|
| Programador de aplicação | Desenvolve programas que acessam o BD |
| Usuário sofisticado | Pode executar consultas diretamente |
| Usuário ingênuo | Usa interfaces prontas do sistema |

## 6. Projeto de Banco de Dados

```text
Levantamento de requisitos
        ↓
Modelagem conceitual
        ↓
Projeto lógico
        ↓
Projeto físico
```

| Etapa | Resultado |
|---|---|
| Levantamento de requisitos | Identificação de dados, regras e necessidades do sistema |
| Modelagem conceitual | MER/DER independente de SGBD |
| Projeto lógico | Tabelas, colunas, PKs, FKs e relacionamentos |
| Projeto físico | Scripts, tipos, índices, armazenamento, segurança e tuning |

- **MER/DER** é de alto nível, fácil de validar com o cliente e independente de um SGBD específico.
- **Tuning** é o ajuste do banco, principalmente físico, para melhorar desempenho.

## 7. MER e DER

```text
MER = Entidades + Atributos + Relacionamentos
```

| Elemento | Significado | Representação comum |
|---|---|---|
| Entidade | Objeto/conceito sobre o qual armazenamos dados | Retângulo |
| Atributo | Característica de entidade ou relacionamento | Elipse/círculo |
| Relacionamento | Associação entre entidades | Losango |

Exemplo:

```text
MÉDICO — realiza — CONSULTA — atende — PACIENTE
```

### Tipos de entidade

| Tipo | Característica | Exemplo |
|---|---|---|
| Forte/simples | Possui existência independente e identificador próprio | CLIENTE, PRODUTO, CONTA |
| Fraca | Sua existência depende de outra entidade | TRANSAÇÃO ligada a CONTA |
| Associativa | Surge de relacionamento relevante com atributos/identificação próprios | MATRÍCULA entre ALUNO e DISCIPLINA |

> **Entidade fraca:** se o enunciado diz que algo só existe se estiver ligado a outra entidade, trate como fraca.

### Tipos de atributo

| Tipo | Exemplo |
|---|---|
| Simples | Nome, Preço, Cor |
| Composto | Endereço = Rua + Número + Bairro + Cidade + UF |
| Multivalorado | Cliente com vários telefones |
| Chave | CPF, CRM, Matrícula, Código |

## 8. Cardinalidades

| Notação | Significado |
|---|---|
| `(0,1)` | Opcional; no máximo uma ocorrência |
| `(1,1)` | Obrigatória; exatamente uma ocorrência |
| `(0,n)` | Opcional; pode ter várias ocorrências |
| `(1,n)` | Obrigatória; uma ou várias ocorrências |

| Cardinalidade | Significado |
|---|---|
| 1:1 | Um para um |
| 1:N | Um para muitos |
| N:1 | Muitos para um |
| N:N | Muitos para muitos |

Exemplo: se cada consulta é feita por exatamente um médico e cada médico pode realizar várias consultas, o relacionamento entre MÉDICO e CONSULTA é **1:N**.

## 9. Modelo relacional e chaves

| Conceito relacional | Nome comum |
|---|---|
| Relação | Tabela |
| Tupla | Linha/registro |
| Atributo | Coluna |

### Tipos de chave

| Chave | Definição |
|---|---|
| Primária (PK) | Identifica unicamente cada tupla; não deve repetir nem ser nula |
| Composta | PK formada por mais de um atributo |
| Candidata | Atributo/conjunto que poderia identificar unicamente a tupla |
| Alternativa | Chave candidata não escolhida como PK |
| Estrangeira (FK) | Referencia a PK de outra tabela |

Exemplo:

```text
DEPARTAMENTO(CodDept, Descricao)
FUNCIONARIO(CodFunc, Nome, CodDept)

FUNCIONARIO.CodDept → DEPARTAMENTO.CodDept
```

A FK ajuda a garantir **integridade referencial**: não deve existir um funcionário ligado a um departamento inexistente.

## 10. MER → modelo lógico

### Regras básicas

- Cada entidade vira uma tabela.
- Cada atributo vira uma coluna.
- O atributo identificador vira chave primária.

### Relacionamento 1:N

A PK do lado **1** vai como FK no lado **N**.

```text
DEPARTAMENTO(CodDept, Nome)
EMPREGADO(CodEmp, Nome, CodDept)
```

> **Macete:** no relacionamento 1:N, a FK fica no lado dos “muitos”.

Se o relacionamento tiver atributo próprio, ele costuma ir junto da FK no lado N:

```text
EMPREGADO(CodEmp, Nome, CodDept, DataLotacao)
```

### Relacionamento N:N

Cria-se uma tabela própria para o relacionamento.

```text
ENGENHEIRO(CodEng, Nome)
PROJETO(CodProj, Titulo)
ATUACAO(CodEng, CodProj, Funcao)
```

Normalmente:

```text
PK de ATUACAO = (CodEng, CodProj)
```

### Relacionamento 1:1

Pode usar tabela própria, adição de coluna ou fusão de tabelas. No material, para 1:1 obrigatório dos dois lados, a estratégia indicada é a **fusão**.

```text
CONFERENCIA(CodConf, Nome, DataInstComOrg, EnderComOrg)
```

### Entidade fraca

A tabela da entidade fraca contém a PK da entidade forte.

```text
CONTA(NumConta, Saldo)
TRANSACAO(NumConta, NumTransacao, Data, Quantia)
```

Uma chave possível para `TRANSACAO`:

```text
PK = (NumConta, NumTransacao)
```

## 11. Normalização

A normalização organiza as relações para:

- Reduzir redundância desnecessária
- Evitar inconsistências
- Evitar anomalias de inserção, atualização e exclusão
- Reduzir valores nulos desnecessários
- Evitar tuplas espúrias em junções
- Preservar dependências funcionais

### Anomalias

| Tipo | Exemplo |
|---|---|
| Atualização | Alterar endereço do cliente repetido em vários pedidos e esquecer uma linha |
| Inserção | Não conseguir cadastrar um departamento porque não possui funcionário |
| Exclusão | Apagar o último funcionário e perder também os dados do departamento |

## 12. Dependências funcionais

Notação:

\[
X \rightarrow Y
\]

Leitura: `X determina Y`, ou `Y depende funcionalmente de X`.

Exemplo:

\[
\text{Matrícula} \rightarrow \text{Nome, Endereço, Telefone, CodCurso}
\]

Uma DF depende das **regras de negócio**, não apenas dos dados presentes na tabela em um momento. Ver nomes únicos hoje não prova que `Nome → Matrícula`; duas pessoas podem ter o mesmo nome.

## 13. Primeira Forma Normal — 1FN

Uma relação está na **1FN** se todos os atributos forem atômicos e monovalorados, sem grupos repetitivos.

### Violações comuns

- Atributo composto: `Endereço = Rua + Número + Bairro + Cidade + UF`.
- Campos repetidos: `Telefone1`, `Telefone2`, `Telefone3`.
- Grupos repetitivos: `Recado1`, `Recado2`, `Recado3`.
- Coluna com lista de valores: vários projetos em um único campo.

Exemplo de decomposição:

```text
FUNCIONARIO(CodFunc, Nome, Cargo)
FUNC_PROJ(CodFunc, Projeto, DataIni, DataFim)
```

### Checklist 1FN

```text
Há lista de valores em uma coluna?
Há atributos compostos?
Há campos como Telefone1, Telefone2 ou Recado1, Recado2?
```

Se sim, investigue violação de 1FN.

## 14. Segunda Forma Normal — 2FN

Uma relação está na **2FN** quando:

1. Está na 1FN.
2. Todo atributo não-chave depende da chave primária completa.
3. Não há dependência parcial.

### Dependência parcial

Acontece principalmente com chave composta, quando um atributo depende de apenas parte da chave.

```text
ESTOQUE(Produto, Almoxarifado, EndAlmox, UnidEst, Qtd, Preco)
PK = (Produto, Almoxarifado)
```

Se:

\[
\text{Almoxarifado} \rightarrow \text{EndAlmox}
\]

\[
\text{Produto} \rightarrow \text{UnidEst}
\]

então há dependência parcial e a relação não está na 2FN.

Possível decomposição:

```text
ALMOXARIFADO(Almoxarifado, EndAlmox)
PRODUTO(Produto, UnidEst)
ESTOQUE(Produto, Almoxarifado, Qtd, Preco)
```

### Checklist 2FN

```text
A chave é composta?
Algum atributo não-chave depende apenas de parte da chave?
```

Se sim, não está na 2FN.

## 15. Terceira Forma Normal — 3FN

Uma relação está na **3FN** quando:

1. Está na 2FN.
2. Não possui dependências transitivas.
3. Atributo não-chave não depende de outro atributo não-chave.

### Dependência transitiva

\[
\text{Chave} \rightarrow A
\]

\[
A \rightarrow B
\]

Exemplo:

```text
MUSICA(Codigo, Titulo, Genero, PaisOrigem)
```

Se:

\[
\text{Codigo} \rightarrow \text{Genero}
\]

\[
\text{Genero} \rightarrow \text{PaisOrigem}
\]

há dependência transitiva. A decomposição é:

```text
MUSICA(Codigo, Titulo, Genero)
GENERO(Genero, PaisOrigem)
```

### Atributo derivável

Evite armazenar um dado que pode ser calculado por outro quando isso causa inconsistência.

```text
CLIENTE(CodCliente, Nome, DataNascimento, Idade)
```

`Idade` pode ser calculada com base em `DataNascimento` e na data atual. Guardar as duas pode deixar a idade desatualizada.

### Checklist 3FN

```text
Um atributo não-chave determina outro atributo não-chave?
Há uma relação Chave → A → B?
Algum dado pode ser obtido de outro dado armazenado?
```

## 16. Comparação das formas normais

| Forma normal | Exige | Elimina principalmente |
|---|---|---|
| 1FN | Valores atômicos e sem grupos repetitivos | Listas, atributos compostos e valores múltiplos |
| 2FN | Estar na 1FN e não ter dependência parcial | Dependência de parte de uma chave composta |
| 3FN | Estar na 2FN e não ter dependência transitiva | Dependência entre atributos não-chave |

```text
1FN → valores atômicos
2FN → depende da chave inteira
3FN → depende somente da chave, não de outro atributo não-chave
```

## 17. Propriedades da decomposição

| Propriedade | Significado |
|---|---|
| Junção sem perda | Juntar as relações decompostas recupera os dados corretos sem perdas nem linhas falsas |
| Preservação de dependências | As DFs relevantes continuam verificáveis nas novas relações |
| Sem tuplas espúrias | A junção não cria combinações sem sentido |

## 18. Pegadinhas frequentes

- Em 1:N, a FK vai no lado N.
- Em N:N, crie tabela própria com as duas FKs.
- Em 1:1 obrigatório-obrigatório, os slides indicam fusão de tabelas.
- Entidade fraca não é igual a entidade associativa.
- A 2FN é especialmente relevante com chave composta.
- Chave simples não garante automaticamente 3FN.
- Uma DF é determinada pela regra de negócio, não só pelo conteúdo atual da tabela.

## 19. Resumo de bolso

```text
BD = dados organizados.
SGBD = software que gerencia os dados.
SBD = dados + hardware + software + usuários.

Projeto:
Requisitos → Conceitual → Lógico → Físico.

MER:
Entidades + atributos + relacionamentos.

Chaves:
PK identifica.
FK referencia outra tabela.
Candidata pode ser PK.
Alternativa é candidata não escolhida.

Transformação:
1:N → FK no lado N.
N:N → tabela própria.
1:1 obrigatório-obrigatório → fusão de tabelas.

Normalização:
1FN → sem grupos repetitivos/valores múltiplos.
2FN → sem dependência parcial.
3FN → sem dependência transitiva.
```

## 20. Perguntas de revisão

1. Qual é a diferença entre BD, SGBD e SBD?
2. Quais são os três níveis de abstração de dados?
3. Qual a diferença entre independência física e lógica?
4. Qual é a ordem do projeto de banco de dados?
5. Quais são os três elementos do MER?
6. O que diferencia entidade fraca de entidade associativa?
7. Qual a diferença entre atributo composto e multivalorado?
8. Onde fica a FK em um relacionamento 1:N?
9. Como se transforma um relacionamento N:N?
10. Qual a diferença entre PK, FK, chave candidata e alternativa?
11. O que é dependência funcional?
12. Como identificar violação da 1FN?
13. Quando ocorre dependência parcial?
14. Quando ocorre dependência transitiva?
15. O que significa junção sem perda?
