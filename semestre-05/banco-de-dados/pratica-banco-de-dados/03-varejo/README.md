# Exercício 3 — Varejo (`BdVarejo`)

Banco de uma rede de lojas: lojas, clientes, produtos, vendas e itens de cada venda.

- Script passo a passo (itens a–f): [bd_varejo.sql](bd_varejo.sql)
- Estado final do banco: [dump/dump_BdVarejo.sql](dump/dump_BdVarejo.sql)

**Legenda:** atributos em **negrito** são chaves primárias; atributos em *itálico* são chaves estrangeiras.

## Estrutura inicial (item b)

| Tabela | Atributo | Tipo | Restrição | Chave |
|---|---|---|---|---|
| Lojas | **codl** | INT | Chave primária | PK |
| Lojas | nome | VARCHAR(30) | Não nulo | — |
| Lojas | cidade | VARCHAR(30) | — | — |
| Lojas | uf | CHAR(2) | — | — |
| Clientes | **codc** | INT | Chave primária | PK |
| Clientes | nome | VARCHAR(40) | Não nulo | — |
| Clientes | CPF | NUMERIC(11) | — | — |
| Clientes | cidade | VARCHAR(30) | — | — |
| Produtos | **codp** | INT | Chave primária | PK |
| Produtos | descricao | VARCHAR(40) | Não nulo | — |
| Produtos | categoria | CHAR(20) | — | — |
| Produtos | preco | NUMERIC(8,2) | Não nulo | — |
| Vendas | **codv** | INT | Chave primária | PK |
| Vendas | *codc* | INT | Referencia Clientes(codc) | FK |
| Vendas | *codl* | INT | Referencia Lojas(codl) | FK |
| Vendas | data | DATE | Não nulo | — |
| Vendas | hora | TIME | Não nulo | — |
| ItensVenda | ***codv*** | INT | Referencia Vendas(codv); parte da chave primária composta (codv, codp) | PK e FK |
| ItensVenda | ***codp*** | INT | Referencia Produtos(codp); parte da chave primária composta (codv, codp) | PK e FK |
| ItensVenda | qtd | SMALLINT | Não nulo | — |
| ItensVenda | valor | NUMERIC(8,2) | Não nulo | — |

## Relacionamentos

| Tabela | Coluna | Referencia | Nome da restrição |
|---|---|---|---|
| Vendas | codc | Clientes(codc) | `fk_vendas_clientes` |
| Vendas | codl | Lojas(codl) | `fk_vendas_lojas` |
| ItensVenda | codv | Vendas(codv) | `fk_itensvenda_vendas` |
| ItensVenda | codp | Produtos(codp) | `fk_itensvenda_produtos` |

`ItensVenda` é uma tabela de ligação entre `Vendas` e `Produtos`: a mesma venda tem vários produtos, e o mesmo produto aparece em várias vendas.

## Alterações dos itens c a f

| Item | Operação | Detalhe |
|---|---|---|
| c) | Adicionar coluna | `ItensVenda.desconto` (NUMERIC(5,2)) |
| d) | Criar índice único | `uq_clientes_cpf` em `Clientes(CPF)` (no item b o CPF ainda não era único) |
| d) | Criar índice comum | `idx_produtos_categoria` em `Produtos(categoria)` |
| e) | Remover índice | `idx_produtos_categoria` (a coluna `categoria` continua existindo neste momento) |
| f) | Remover coluna | `Lojas.uf` |
| f) | Remover coluna | `Produtos.categoria` |

## Tabelas após o item f

- **Lojas:** codl, nome, cidade
- **Clientes:** codc, nome, CPF, cidade
- **Produtos:** codp, descricao, preco
- **Vendas:** codv, codc, codl, data, hora
- **ItensVenda:** codv, codp, qtd, valor, desconto

## Diagrama ER

Gerado pelo SGBD (engenharia reversa): `er_bd_varejo.png`
