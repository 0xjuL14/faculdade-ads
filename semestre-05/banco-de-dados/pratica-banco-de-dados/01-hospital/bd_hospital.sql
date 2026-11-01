-- ============================================================
-- Banco de Dados | Exercício 1 — Saúde (BdHospital)
-- SGBD: MariaDB 11.8 (Debian) | Cliente: DBeaver / terminal
--
-- Como executar (terminal):
--   sudo mariadb < bd_hospital.sql
-- No DBeaver: abrir o arquivo e executar como script (Alt+X).
--
-- Atenção: o script segue os itens a) a f) do enunciado, em ordem.
-- O estado FINAL do banco é o do item f). Para ver o banco pronto,
-- use o arquivo da pasta dump/.
--
-- Para poder rodar o script mais de uma vez, descomente a linha
-- abaixo. CUIDADO: ela APAGA o banco BdHospital inteiro.
-- DROP DATABASE IF EXISTS BdHospital;
-- ============================================================


-- ------------------------------------------------------------
-- a) Criar o banco de dados BdHospital
-- ------------------------------------------------------------
CREATE DATABASE BdHospital
CHARACTER SET utf8mb4
COLLATE utf8mb4_general_ci;

-- Selecionar o banco de dados
USE BdHospital;


-- ------------------------------------------------------------
-- b) Criar as tabelas e definir as chaves e restrições
-- ------------------------------------------------------------

-- Tabela Setores
CREATE TABLE BdHospital.Setores (
    nros INT NOT NULL,
    nome VARCHAR(30) NOT NULL,
    andar NUMERIC(3) NOT NULL,
    PRIMARY KEY (nros)
);

-- Tabela Medicos
-- crm é chave primária, CPF é único
-- e nros é chave estrangeira referenciando Setores
CREATE TABLE BdHospital.Medicos (
    crm INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    idade SMALLINT NOT NULL,
    especialidade CHAR(20),
    CPF NUMERIC(11),
    nros INT,
    PRIMARY KEY (crm),
    CONSTRAINT uq_medicos_cpf UNIQUE (CPF),
    CONSTRAINT fk_medicos_setores FOREIGN KEY (nros)
        REFERENCES BdHospital.Setores (nros)
);

-- Tabela Pacientes
-- codp é chave primária e CPF é único
CREATE TABLE BdHospital.Pacientes (
    codp INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    idade SMALLINT NOT NULL,
    cidade CHAR(30),
    CPF NUMERIC(11),
    doenca VARCHAR(40) NOT NULL,
    PRIMARY KEY (codp),
    CONSTRAINT uq_pacientes_cpf UNIQUE (CPF)
);

-- Tabela Internacoes
-- Chave primária composta por (codp, data_ent)
-- e chaves estrangeiras para Pacientes e Medicos
CREATE TABLE BdHospital.Internacoes (
    codp INT NOT NULL,
    crm INT,
    data_ent DATE NOT NULL,
    data_sai DATE,
    PRIMARY KEY (codp, data_ent),
    CONSTRAINT fk_internacoes_pacientes FOREIGN KEY (codp)
        REFERENCES BdHospital.Pacientes (codp),
    CONSTRAINT fk_internacoes_medicos FOREIGN KEY (crm)
        REFERENCES BdHospital.Medicos (crm)
);

-- Conferência das tabelas
-- Listar as tabelas criadas
SHOW TABLES FROM BdHospital;

-- Saída esperada, independentemente da ordem de exibição:
-- Internacoes
-- Medicos
-- Pacientes
-- Setores

-- Conferir a definição de Internacoes,
-- incluindo a chave primária composta e as chaves estrangeiras
SHOW CREATE TABLE BdHospital.Internacoes;

-- Na definição retornada, verificar:
-- PRIMARY KEY (codp, data_ent)
-- fk_internacoes_pacientes: codp referencia Pacientes.codp
-- fk_internacoes_medicos: crm referencia Medicos.crm


-- ------------------------------------------------------------
-- c) Adicionar nros a Pacientes e definir a chave estrangeira
-- ------------------------------------------------------------

-- Adicionar a coluna nros à tabela Pacientes
ALTER TABLE BdHospital.Pacientes
ADD COLUMN nros INT;

-- Criar a relação entre Pacientes e Setores
ALTER TABLE BdHospital.Pacientes
ADD CONSTRAINT fk_pacientes_setores
FOREIGN KEY (nros)
REFERENCES BdHospital.Setores (nros);

-- Conferir a definição completa da tabela Pacientes
SHOW CREATE TABLE BdHospital.Pacientes;

-- Na definição retornada, verificar:
-- A existência da coluna nros do tipo INT
-- A existência da chave estrangeira fk_pacientes_setores
-- A referência a Setores.nros

-- Como o resultado de SHOW CREATE TABLE aparece em uma única célula
-- (no DBeaver), esta consulta mostra o relacionamento de forma mais clara:
SELECT
    COLUMN_NAME AS coluna,
    REFERENCED_TABLE_NAME AS tabela_referenciada,
    REFERENCED_COLUMN_NAME AS coluna_referenciada
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_SCHEMA = 'BdHospital'
  AND TABLE_NAME = 'Pacientes'
  AND COLUMN_NAME = 'nros'
  AND REFERENCED_TABLE_NAME IS NOT NULL;

-- Saída esperada:
-- coluna | tabela_referenciada | coluna_referenciada
-- nros   | Setores             | nros


-- ------------------------------------------------------------
-- d) Criar os índices: Medicos.CPF (único) e Pacientes.doenca
-- ------------------------------------------------------------

-- No item b, a restrição UNIQUE (CPF) já havia criado o índice único
-- em Medicos. Por isso usamos OR REPLACE com o mesmo nome, para não
-- deixar dois índices equivalentes.
-- Obs.: "CREATE OR REPLACE INDEX" existe no MariaDB, mas NÃO no MySQL.

-- Recriar o índice único sobre CPF em Medicos,
-- mantendo o nome usado pela restrição do item b
CREATE OR REPLACE UNIQUE INDEX uq_medicos_cpf
ON BdHospital.Medicos (CPF);

-- Criar um índice comum sobre doenca em Pacientes
CREATE INDEX idx_pacientes_doenca
ON BdHospital.Pacientes (doenca);

-- Conferência dos índices
-- Conferir os índices de Medicos
SHOW INDEX FROM BdHospital.Medicos;

-- Entre os resultados, verificar:
-- Key_name: uq_medicos_cpf
-- Column_name: CPF
-- Non_unique: 0

-- Conferir os índices de Pacientes
SHOW INDEX FROM BdHospital.Pacientes;

-- Entre os resultados, verificar:
-- Key_name: idx_pacientes_doenca
-- Column_name: doenca
-- Non_unique: 1

-- Non_unique = 0: índice único
-- Non_unique = 1: índice que permite valores repetidos


-- ------------------------------------------------------------
-- e) Remover o índice sobre doenca de Pacientes
-- ------------------------------------------------------------

-- Remover o índice criado sobre a coluna doenca
DROP INDEX idx_pacientes_doenca
ON BdHospital.Pacientes;

-- Conferir os índices restantes
SHOW INDEX FROM BdHospital.Pacientes;

-- Resultado esperado:
-- O índice idx_pacientes_doenca não deve mais aparecer.
-- Os demais índices permanecem.
-- A coluna doenca continua existindo na tabela.


-- ------------------------------------------------------------
-- f) Remover andar de Setores e nros de Pacientes
-- ------------------------------------------------------------

-- Remover a coluna andar de Setores
ALTER TABLE BdHospital.Setores
DROP COLUMN andar;

-- Remover a relação entre Pacientes e Setores
-- ANTES de excluir a coluna usada pela chave estrangeira
-- (senão o MariaDB/MySQL recusa o DROP COLUMN)
ALTER TABLE BdHospital.Pacientes
DROP FOREIGN KEY fk_pacientes_setores;

-- Remover a coluna nros de Pacientes
ALTER TABLE BdHospital.Pacientes
DROP COLUMN nros;

-- Conferir as colunas restantes em Setores
DESCRIBE BdHospital.Setores;

-- Colunas esperadas na saída:
-- nros
-- nome

-- Conferir as colunas restantes em Pacientes
DESCRIBE BdHospital.Pacientes;

-- Colunas esperadas na saída:
-- codp
-- nome
-- idade
-- cidade
-- CPF
-- doenca
