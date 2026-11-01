-- ============================================================
-- Banco de Dados | Exercício 5 — Cinema (BdCinema)
-- SGBD: MariaDB 11.8 (Debian) | Cliente: DBeaver / terminal
--
-- Como executar (terminal):
--   sudo mariadb < bd_cinema.sql
-- No DBeaver: abrir o arquivo e executar como script (Alt+X).
--
-- Atenção: o script segue os itens a) a f) do enunciado, em ordem.
-- O estado FINAL do banco é o do item f). Para ver o banco pronto,
-- use o arquivo da pasta dump/.
--
-- Pré-requisito: o usuário que executa precisa ter permissão para
-- criar/usar o banco BdCinema (configuração do ambiente, feita
-- à parte, como administrador — não faz parte dos itens).
--
-- Para poder rodar o script mais de uma vez, descomente a linha
-- abaixo. CUIDADO: ela APAGA o banco BdCinema inteiro.
-- DROP DATABASE IF EXISTS BdCinema;
-- ============================================================


-- ------------------------------------------------------------
-- a) Criar o banco de dados BdCinema
-- ------------------------------------------------------------
CREATE DATABASE BdCinema
CHARACTER SET utf8mb4
COLLATE utf8mb4_general_ci;

-- Selecionar o banco de dados
USE BdCinema;

-- Conferir qual banco está selecionado
SELECT DATABASE();

-- Saída esperada:
-- BdCinema


-- ------------------------------------------------------------
-- b) Criar as tabelas e definir as chaves e restrições
-- ------------------------------------------------------------
-- Cinco tabelas: Salas, Filmes, Sessoes, Ingressos e Funcionarios.
-- Criadas nessa ordem para que as tabelas referenciadas já existam
-- quando os relacionamentos forem definidos.

-- Tabela Salas
CREATE TABLE BdCinema.Salas (
    nros INT NOT NULL,
    capacidade SMALLINT NOT NULL,
    tipo CHAR(15),
    PRIMARY KEY (nros)
);

-- Tabela Filmes
-- codf é chave primária.
-- O índice único sobre titulo só é criado no item d.
CREATE TABLE BdCinema.Filmes (
    codf INT NOT NULL,
    titulo VARCHAR(50) NOT NULL,
    duracao SMALLINT,
    genero CHAR(20),
    classificacao CHAR(3),
    PRIMARY KEY (codf)
);

-- Tabela Sessoes
-- cods é chave primária
-- e há chaves estrangeiras para Filmes e Salas
CREATE TABLE BdCinema.Sessoes (
    cods INT NOT NULL,
    codf INT,
    nros INT,
    data DATE NOT NULL,
    hora TIME NOT NULL,
    preco NUMERIC(6,2) NOT NULL,
    PRIMARY KEY (cods),
    CONSTRAINT fk_sessoes_filmes FOREIGN KEY (codf)
        REFERENCES BdCinema.Filmes (codf),
    CONSTRAINT fk_sessoes_salas FOREIGN KEY (nros)
        REFERENCES BdCinema.Salas (nros)
);

-- Tabela Ingressos
-- coding é chave primária (nome mantido como no enunciado)
-- e cods é chave estrangeira referenciando Sessoes.
-- (a coluna poltrona entra somente no item c)
CREATE TABLE BdCinema.Ingressos (
    coding INT NOT NULL,
    cods INT,
    CPF NUMERIC(11),
    tipo CHAR(10),
    valor NUMERIC(6,2),
    PRIMARY KEY (coding),
    CONSTRAINT fk_ingressos_sessoes FOREIGN KEY (cods)
        REFERENCES BdCinema.Sessoes (cods)
);

-- Tabela Funcionarios
-- codfu é chave primária
-- e nros é chave estrangeira referenciando Salas
CREATE TABLE BdCinema.Funcionarios (
    codfu INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    cargo VARCHAR(20),
    nros INT,
    PRIMARY KEY (codfu),
    CONSTRAINT fk_funcionarios_salas FOREIGN KEY (nros)
        REFERENCES BdCinema.Salas (nros)
);

-- Conferência das tabelas
-- Listar as tabelas criadas
SHOW TABLES FROM BdCinema;

-- Saída esperada, independentemente da ordem de exibição:
-- Filmes
-- Funcionarios
-- Ingressos
-- Salas
-- Sessoes

-- Conferir a estrutura de cada tabela
DESCRIBE BdCinema.Salas;

DESCRIBE BdCinema.Filmes;

DESCRIBE BdCinema.Sessoes;

DESCRIBE BdCinema.Ingressos;

DESCRIBE BdCinema.Funcionarios;

-- Conferir a definição completa de Sessoes
SHOW CREATE TABLE BdCinema.Sessoes;

-- Na definição retornada, verificar:
-- PRIMARY KEY (cods)
-- fk_sessoes_filmes: codf referencia Filmes.codf
-- fk_sessoes_salas: nros referencia Salas.nros

-- Conferir a definição completa de Ingressos
SHOW CREATE TABLE BdCinema.Ingressos;

-- Na definição retornada, verificar:
-- PRIMARY KEY (coding)
-- fk_ingressos_sessoes: cods referencia Sessoes.cods

-- Para conferir todos os relacionamentos em uma grade:
SELECT
    TABLE_NAME AS tabela,
    COLUMN_NAME AS coluna,
    REFERENCED_TABLE_NAME AS tabela_referenciada,
    REFERENCED_COLUMN_NAME AS coluna_referenciada
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_SCHEMA = 'BdCinema'
  AND REFERENCED_TABLE_NAME IS NOT NULL
ORDER BY TABLE_NAME, COLUMN_NAME;

-- Relações esperadas:
-- Funcionarios.nros -> Salas.nros
-- Ingressos.cods    -> Sessoes.cods
-- Sessoes.codf      -> Filmes.codf
-- Sessoes.nros      -> Salas.nros


-- ------------------------------------------------------------
-- c) Adicionar poltrona à tabela Ingressos
-- ------------------------------------------------------------

-- Adicionar a coluna poltrona do tipo VARCHAR(4)
ALTER TABLE BdCinema.Ingressos
ADD COLUMN poltrona VARCHAR(4);

-- Conferir a estrutura após a alteração
DESCRIBE BdCinema.Ingressos;

-- Colunas esperadas na saída:
-- coding
-- cods
-- CPF
-- tipo
-- valor
-- poltrona


-- ------------------------------------------------------------
-- d) Criar os índices
-- ------------------------------------------------------------
-- Índice único sobre titulo em Filmes
-- e índice comum sobre data em Sessoes.

-- Índice único sobre titulo em Filmes
CREATE UNIQUE INDEX uq_filmes_titulo
ON BdCinema.Filmes (titulo);

-- Índice comum sobre data em Sessoes
CREATE INDEX idx_sessoes_data
ON BdCinema.Sessoes (data);

-- Conferência dos índices
-- Conferir os índices de Filmes
SHOW INDEX FROM BdCinema.Filmes;

-- Entre os resultados, verificar:
-- Key_name: uq_filmes_titulo
-- Column_name: titulo
-- Non_unique: 0

-- Conferir os índices de Sessoes
SHOW INDEX FROM BdCinema.Sessoes;

-- Entre os resultados, verificar:
-- Key_name: idx_sessoes_data
-- Column_name: data
-- Non_unique: 1

-- Non_unique = 0: índice único
-- Non_unique = 1: índice que permite valores repetidos


-- ------------------------------------------------------------
-- e) Remover o índice sobre data de Sessoes
-- ------------------------------------------------------------

-- Remover o índice criado sobre data em Sessoes
DROP INDEX idx_sessoes_data
ON BdCinema.Sessoes;

-- Conferir os índices restantes
SHOW INDEX FROM BdCinema.Sessoes;

-- Resultado esperado:
-- O índice idx_sessoes_data não deve mais aparecer.
-- Os demais índices permanecem.
-- A coluna data continua existindo na tabela.


-- ------------------------------------------------------------
-- f) Remover classificacao de Filmes e tipo de Salas
-- ------------------------------------------------------------

-- Remover a coluna classificacao de Filmes
ALTER TABLE BdCinema.Filmes
DROP COLUMN classificacao;

-- Remover a coluna tipo de Salas
ALTER TABLE BdCinema.Salas
DROP COLUMN tipo;

-- Conferir as colunas restantes em Filmes
DESCRIBE BdCinema.Filmes;

-- Colunas esperadas na saída:
-- codf
-- titulo
-- duracao
-- genero

-- Conferir as colunas restantes em Salas
DESCRIBE BdCinema.Salas;

-- Colunas esperadas na saída:
-- nros
-- capacidade
