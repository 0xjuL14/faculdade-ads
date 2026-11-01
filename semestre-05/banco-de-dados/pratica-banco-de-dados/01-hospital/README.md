# Exercício 1 — Saúde (`BdHospital`)

Banco de um hospital: setores, médicos, pacientes e internações.

- Script passo a passo (itens a–f): [bd_hospital.sql](bd_hospital.sql)
- Estado final do banco: [dump/dump_BdHospital.sql](dump/dump_BdHospital.sql)

**Legenda:** atributos em **negrito** são chaves primárias; atributos em *itálico* são chaves estrangeiras.

## Estrutura inicial (item b)

| Tabela | Atributo | Tipo | Restrição | Chave |
|---|---|---|---|---|
| Setores | **nros** | INT | Chave primária | PK |
| Setores | nome | VARCHAR(30) | Não nulo | — |
| Setores | andar | NUMERIC(3) | Não nulo | — |
| Medicos | **crm** | INT | Chave primária | PK |
| Medicos | nome | VARCHAR(40) | Não nulo | — |
| Medicos | idade | SMALLINT | Não nulo | — |
| Medicos | especialidade | CHAR(20) | — | — |
| Medicos | CPF | NUMERIC(11) | Único | — |
| Medicos | *nros* | INT | Referencia Setores(nros) | FK |
| Pacientes | **codp** | INT | Chave primária | PK |
| Pacientes | nome | VARCHAR(40) | Não nulo | — |
| Pacientes | idade | SMALLINT | Não nulo | — |
| Pacientes | cidade | CHAR(30) | — | — |
| Pacientes | CPF | NUMERIC(11) | Único | — |
| Pacientes | doenca | VARCHAR(40) | Não nulo | — |
| Internacoes | ***codp*** | INT | Referencia Pacientes(codp); parte da chave primária composta (codp, data_ent) | PK e FK |
| Internacoes | *crm* | INT | Referencia Medicos(crm) | FK |
| Internacoes | **data_ent** | DATE | Parte da chave primária composta (codp, data_ent) | PK |
| Internacoes | data_sai | DATE | — | — |

## Relacionamentos

| Tabela | Coluna | Referencia | Nome da restrição |
|---|---|---|---|
| Medicos | nros | Setores(nros) | `fk_medicos_setores` |
| Internacoes | codp | Pacientes(codp) | `fk_internacoes_pacientes` |
| Internacoes | crm | Medicos(crm) | `fk_internacoes_medicos` |

## Alterações dos itens c a f

| Item | Operação | Detalhe |
|---|---|---|
| c) | Adicionar coluna | `Pacientes.nros` (INT) |
| c) | Adicionar chave estrangeira | `fk_pacientes_setores`: `Pacientes.nros` → `Setores(nros)` |
| d) | Criar índice único | `uq_medicos_cpf` em `Medicos(CPF)` (recriado com `OR REPLACE`: o `UNIQUE` do item b já tinha criado esse índice) |
| d) | Criar índice comum | `idx_pacientes_doenca` em `Pacientes(doenca)` |
| e) | Remover índice | `idx_pacientes_doenca` |
| f) | Remover coluna | `Setores.andar` |
| f) | Remover chave estrangeira e coluna | `fk_pacientes_setores`, depois `Pacientes.nros` (a FK precisa sair antes da coluna) |

## Tabelas após o item f

- **Setores:** nros, nome
- **Medicos:** crm, nome, idade, especialidade, CPF, nros
- **Pacientes:** codp, nome, idade, cidade, CPF, doenca
- **Internacoes:** codp, crm, data_ent, data_sai

## Diagrama ER

Gerado pelo SGBD (engenharia reversa): `er_bd_hospital.png`
