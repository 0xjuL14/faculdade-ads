# Exercício 4 — Educação (`BdEscola`)

Banco de uma escola: cursos, professores, turmas, alunos e matrículas.

- Script passo a passo (itens a–f): [bd_escola.sql](bd_escola.sql)
- Estado final do banco: [dump/dump_BdEscola.sql](dump/dump_BdEscola.sql)

**Legenda:** atributos em **negrito** são chaves primárias; atributos em *itálico* são chaves estrangeiras.

## Estrutura inicial (item b)

| Tabela | Atributo | Tipo | Restrição | Chave |
|---|---|---|---|---|
| Cursos | **codc** | INT | Chave primária | PK |
| Cursos | nome | VARCHAR(40) | Não nulo | — |
| Cursos | carga_horaria | SMALLINT | — | — |
| Professores | **codpr** | INT | Chave primária | PK |
| Professores | nome | VARCHAR(40) | Não nulo | — |
| Professores | titulacao | CHAR(15) | — | — |
| Professores | CPF | NUMERIC(11) | — | — |
| Turmas | **codt** | INT | Chave primária | PK |
| Turmas | *codc* | INT | Referencia Cursos(codc) | FK |
| Turmas | *codpr* | INT | Referencia Professores(codpr) | FK |
| Turmas | semestre | CHAR(6) | Não nulo | — |
| Turmas | sala | VARCHAR(10) | — | — |
| Alunos | **ra** | INT | Chave primária | PK |
| Alunos | nome | VARCHAR(40) | Não nulo | — |
| Alunos | idade | SMALLINT | Não nulo | — |
| Alunos | cidade | VARCHAR(30) | — | — |
| Alunos | CPF | NUMERIC(11) | Único | — |
| Alunos | *codc* | INT | Referencia Cursos(codc) | FK |
| Matriculas | ***ra*** | INT | Referencia Alunos(ra); parte da chave primária composta (ra, codt) | PK e FK |
| Matriculas | ***codt*** | INT | Referencia Turmas(codt); parte da chave primária composta (ra, codt) | PK e FK |
| Matriculas | nota | NUMERIC(4,2) | — | — |
| Matriculas | faltas | SMALLINT | — | — |

## Relacionamentos

| Tabela | Coluna | Referencia | Nome da restrição |
|---|---|---|---|
| Turmas | codc | Cursos(codc) | `fk_turmas_cursos` |
| Turmas | codpr | Professores(codpr) | `fk_turmas_professores` |
| Alunos | codc | Cursos(codc) | `fk_alunos_cursos` |
| Matriculas | ra | Alunos(ra) | `fk_matriculas_alunos` |
| Matriculas | codt | Turmas(codt) | `fk_matriculas_turmas` |

`Matriculas` liga `Alunos` a `Turmas`: um aluno cursa várias turmas, e uma turma tem vários alunos.

## Alterações dos itens c a f

| Item | Operação | Detalhe |
|---|---|---|
| c) | Adicionar coluna | `Matriculas.status` (CHAR(10)) |
| d) | Criar índice único | `uq_professores_cpf` em `Professores(CPF)` (o CPF de `Alunos` já era único desde o item b, pela restrição `uq_alunos_cpf`) |
| d) | Criar índice comum | `idx_alunos_nome` em `Alunos(nome)` |
| e) | Remover índice | `idx_alunos_nome` (a coluna `nome` continua existindo) |
| f) | Remover coluna | `Turmas.sala` |
| f) | Remover coluna | `Alunos.cidade` |

## Tabelas após o item f

- **Cursos:** codc, nome, carga_horaria
- **Professores:** codpr, nome, titulacao, CPF
- **Turmas:** codt, codc, codpr, semestre
- **Alunos:** ra, nome, idade, CPF, codc
- **Matriculas:** ra, codt, nota, faltas, status

## Diagrama ER

Gerado pelo SGBD (engenharia reversa): `er_bd_escola.png`
