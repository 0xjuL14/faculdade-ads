# Banco de Dados — Exercícios Práticos (SQL)

Lista de exercícios práticos da disciplina de Banco de Dados (Análise e Desenvolvimento de Sistemas).
Cada exercício cria um banco de dados de uma área diferente e segue a mesma sequência de comandos DDL:

| Item | O que faz |
|------|-----------|
| a) | Criar o banco de dados |
| b) | Criar as tabelas, com chaves primárias, estrangeiras e restrições |
| c) | Adicionar uma coluna (`ALTER TABLE ... ADD COLUMN`) |
| d) | Criar índices (`CREATE INDEX` / `CREATE UNIQUE INDEX`) |
| e) | Remover um índice (`DROP INDEX`) |
| f) | Remover colunas (`ALTER TABLE ... DROP COLUMN`), incluindo uma coluna que é chave estrangeira |

## Exercícios

| # | Área | Banco | Script (passo a passo a–f) | Dump (estado final) |
|---|------|-------|----------------------------|---------------------|
| 1 | Saúde | `BdHospital` | [bd_hospital.sql](01-hospital/bd_hospital.sql) | [dump_BdHospital.sql](01-hospital/dump/dump_BdHospital.sql) |
| 2 | Indústria | `BdIndustria` | [bd_industria.sql](02-industria/bd_industria.sql) | [dump_BdIndustria.sql](02-industria/dump/dump_BdIndustria.sql) |
| 3 | Varejo | `BdVarejo` | [bd_varejo.sql](03-varejo/bd_varejo.sql) | [dump_BdVarejo.sql](03-varejo/dump/dump_BdVarejo.sql) |
| 4 | Educação | `BdEscola` | [bd_escola.sql](04-escola/bd_escola.sql) | [dump_BdEscola.sql](04-escola/dump/dump_BdEscola.sql) |
| 5 | Cinema | `BdCinema` | [bd_cinema.sql](05-cinema/bd_cinema.sql) | [dump_BdCinema.sql](05-cinema/dump/dump_BdCinema.sql) |

Cada pasta tem um `README.md` com a estrutura das tabelas (tipos, chaves e restrições), o que cada item de c a f altera e como as tabelas ficam no final.

O diagrama entidade-relacionamento (ER) gerado pelo SGBD por engenharia reversa de cada banco fica na pasta do exercício (`er_bd_*.png`).

## Script x dump: qual usar?

- **Script (`bd_*.sql`)**: conta a história do exercício, item por item, com comentários e as conferências (`SHOW`, `DESCRIBE`) de cada etapa. Serve para estudar.
- **Dump (`dump/dump_*.sql`)**: foto do estado final do banco depois do item f), gerada com `mariadb-dump`. Contém só a estrutura (sem dados). Serve para recriar o banco pronto rapidamente.

## Como executar

Ambiente usado: MariaDB 11.8 no Debian, com DBeaver como cliente. Os comandos são compatíveis com MySQL, com uma exceção: o `CREATE OR REPLACE UNIQUE INDEX` do exercício 1 (item d) existe só no MariaDB.

### Rodar o passo a passo

```bash
sudo mariadb < 01-hospital/bd_hospital.sql
```

Ou, no DBeaver, abra o arquivo e execute como script (`Alt+X`).

> Os scripts criam o banco com `CREATE DATABASE`. Se o banco já existir, vai dar erro. Para rodar de novo, apague o banco antes (isso **apaga todos os dados dele**):
> `DROP DATABASE BdHospital;`

### Restaurar o dump (estado final)

O dump não contém o `CREATE DATABASE`, então crie o banco antes:

```bash
sudo mariadb -e "CREATE DATABASE BdHospital;"
sudo mariadb BdHospital < 01-hospital/dump/dump_BdHospital.sql
```

### Conferir

```sql
USE BdHospital;
SHOW TABLES;
DESCRIBE Pacientes;
SHOW INDEX FROM Pacientes;
```

## Conceitos praticados

- Chave primária simples e composta (`Internacoes`, `ItensVenda`, `Matriculas`)
- Chave estrangeira e ordem de criação das tabelas
- Colunas que são ao mesmo tempo PK e FK
- Restrições `NOT NULL` e `UNIQUE`
- Índice comum x índice único x índice composto (`modelo` + `ano` em `Maquinas`)
- Remover uma coluna que é FK: é preciso remover a restrição (`DROP FOREIGN KEY`) antes de `DROP COLUMN`
- Engenharia reversa: gerar o diagrama ER a partir do banco pronto
