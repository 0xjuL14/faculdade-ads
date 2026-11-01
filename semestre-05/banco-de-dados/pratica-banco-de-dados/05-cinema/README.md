# Exercício 5 — Cinema (`BdCinema`)

Banco de um cinema: salas, filmes, sessões, ingressos e funcionários.

- Script passo a passo (itens a–f): [bd_cinema.sql](bd_cinema.sql)
- Estado final do banco: [dump/dump_BdCinema.sql](dump/dump_BdCinema.sql)

**Legenda:** atributos em **negrito** são chaves primárias; atributos em *itálico* são chaves estrangeiras.

## Estrutura inicial (item b)

| Tabela | Atributo | Tipo | Restrição | Chave |
|---|---|---|---|---|
| Salas | **nros** | INT | Chave primária | PK |
| Salas | capacidade | SMALLINT | Não nulo | — |
| Salas | tipo | CHAR(15) | — | — |
| Filmes | **codf** | INT | Chave primária | PK |
| Filmes | titulo | VARCHAR(50) | Não nulo | — |
| Filmes | duracao | SMALLINT | — | — |
| Filmes | genero | CHAR(20) | — | — |
| Filmes | classificacao | CHAR(3) | — | — |
| Sessoes | **cods** | INT | Chave primária | PK |
| Sessoes | *codf* | INT | Referencia Filmes(codf) | FK |
| Sessoes | *nros* | INT | Referencia Salas(nros) | FK |
| Sessoes | data | DATE | Não nulo | — |
| Sessoes | hora | TIME | Não nulo | — |
| Sessoes | preco | NUMERIC(6,2) | Não nulo | — |
| Ingressos | **coding** | INT | Chave primária | PK |
| Ingressos | *cods* | INT | Referencia Sessoes(cods) | FK |
| Ingressos | CPF | NUMERIC(11) | — | — |
| Ingressos | tipo | CHAR(10) | — | — |
| Ingressos | valor | NUMERIC(6,2) | — | — |
| Funcionarios | **codfu** | INT | Chave primária | PK |
| Funcionarios | nome | VARCHAR(40) | Não nulo | — |
| Funcionarios | cargo | VARCHAR(20) | — | — |
| Funcionarios | *nros* | INT | Referencia Salas(nros) | FK |

## Relacionamentos

| Tabela | Coluna | Referencia | Nome da restrição |
|---|---|---|---|
| Sessoes | codf | Filmes(codf) | `fk_sessoes_filmes` |
| Sessoes | nros | Salas(nros) | `fk_sessoes_salas` |
| Ingressos | cods | Sessoes(cods) | `fk_ingressos_sessoes` |
| Funcionarios | nros | Salas(nros) | `fk_funcionarios_salas` |

`Sessoes` junta um filme e uma sala em uma data e hora; cada ingresso vendido pertence a uma sessão.

## Alterações dos itens c a f

| Item | Operação | Detalhe |
|---|---|---|
| c) | Adicionar coluna | `Ingressos.poltrona` (VARCHAR(4)) |
| d) | Criar índice único | `uq_filmes_titulo` em `Filmes(titulo)` |
| d) | Criar índice comum | `idx_sessoes_data` em `Sessoes(data)` |
| e) | Remover índice | `idx_sessoes_data` (a coluna `data` continua existindo) |
| f) | Remover coluna | `Filmes.classificacao` |
| f) | Remover coluna | `Salas.tipo` |

## Tabelas após o item f

- **Salas:** nros, capacidade
- **Filmes:** codf, titulo, duracao, genero
- **Sessoes:** cods, codf, nros, data, hora, preco
- **Ingressos:** coding, cods, CPF, tipo, valor, poltrona
- **Funcionarios:** codfu, nome, cargo, nros

## Diagrama ER

Gerado pelo SGBD (engenharia reversa): `er_bd_cinema.png`
