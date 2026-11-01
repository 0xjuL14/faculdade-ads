# Exercício 2 — Indústria (`BdIndustria`)

Banco de uma fábrica: linhas de produção, operadores, máquinas e ordens de produção.

- Script passo a passo (itens a–f): [bd_industria.sql](bd_industria.sql)
- Estado final do banco: [dump/dump_BdIndustria.sql](dump/dump_BdIndustria.sql)

**Legenda:** atributos em **negrito** são chaves primárias; atributos em *itálico* são chaves estrangeiras.

## Estrutura inicial (item b)

| Tabela | Atributo | Tipo | Restrição | Chave |
|---|---|---|---|---|
| Linhas | **codl** | INT | Chave primária | PK |
| Linhas | nome | VARCHAR(30) | Não nulo | — |
| Linhas | capacidade | NUMERIC(6,2) | — | — |
| Operadores | **matricula** | INT | Chave primária | PK |
| Operadores | nome | VARCHAR(40) | Não nulo | — |
| Operadores | turno | CHAR(1) | Não nulo | — |
| Operadores | *codl* | INT | Referencia Linhas(codl) | FK |
| Maquinas | **codm** | INT | Chave primária | PK |
| Maquinas | modelo | VARCHAR(30) | Não nulo | — |
| Maquinas | ano | SMALLINT | — | — |
| Maquinas | *codl* | INT | Referencia Linhas(codl) | FK |
| OrdensProducao | **nro** | INT | Chave primária | PK |
| OrdensProducao | *codl* | INT | Referencia Linhas(codl) | FK |
| OrdensProducao | *matricula* | INT | Referencia Operadores(matricula) | FK |
| OrdensProducao | *codm* | INT | Referencia Maquinas(codm) | FK |
| OrdensProducao | qtd | NUMERIC(10,2) | Não nulo | — |
| OrdensProducao | dt_inicio | DATE | Não nulo | — |
| OrdensProducao | dt_fim | DATE | — | — |

## Relacionamentos

| Tabela | Coluna | Referencia | Nome da restrição |
|---|---|---|---|
| Operadores | codl | Linhas(codl) | `fk_operadores_linhas` |
| Maquinas | codl | Linhas(codl) | `fk_maquinas_linhas` |
| OrdensProducao | codl | Linhas(codl) | `fk_ordensproducao_linhas` |
| OrdensProducao | matricula | Operadores(matricula) | `fk_ordensproducao_operadores` |
| OrdensProducao | codm | Maquinas(codm) | `fk_ordensproducao_maquinas` |

## Alterações dos itens c a f

| Item | Operação | Detalhe |
|---|---|---|
| c) | Adicionar coluna | `OrdensProducao.status` (CHAR(12)) |
| d) | Criar índice único composto | `uq_maquinas_modelo_ano` em `Maquinas(modelo, ano)`: **um** índice sobre a combinação das duas colunas |
| d) | Criar índice comum | `idx_ordensproducao_dt_inicio` em `OrdensProducao(dt_inicio)` |
| e) | Remover índice | `idx_ordensproducao_dt_inicio` (a coluna `dt_inicio` continua existindo) |
| f) | Remover coluna | `OrdensProducao.dt_fim` |
| f) | Remover coluna | `Linhas.capacidade` |

## Tabelas após o item f

- **Linhas:** codl, nome
- **Operadores:** matricula, nome, turno, codl
- **Maquinas:** codm, modelo, ano, codl
- **OrdensProducao:** nro, codl, matricula, codm, qtd, dt_inicio, status

## Diagrama ER

Gerado pelo SGBD (engenharia reversa): `er_bd_industria.png`
