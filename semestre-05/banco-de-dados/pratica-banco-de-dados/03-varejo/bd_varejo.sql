-- ============================================================
-- Banco de Dados | Exercício 3 — Varejo (BdVarejo)
-- SGBD: MariaDB 11.8 (Debian) | Cliente: DBeaver / terminal
--
-- Como executar (terminal):
--   sudo mariadb < bd_varejo.sql
-- No DBeaver: abrir o arquivo e executar como script (Alt+X).
--
-- Atenção: o script segue os itens a) a f) do enunciado, em ordem.
-- O estado FINAL do banco é o do item f). Para ver o banco pronto,
-- use o arquivo da pasta dump/.
--
-- Pré-requisito: o usuário que executa precisa ter permissão para
-- criar/usar o banco BdVarejo (configuração do ambiente, feita
-- à parte, como administrador — não faz parte dos itens).
--
-- Para poder rodar o script mais de uma vez, descomente a linha
-- abaixo. CUIDADO: ela APAGA o banco BdVarejo inteiro.
-- DROP DATABASE IF EXISTS BdVarejo;
-- ============================================================


-- ------------------------------------------------------------
-- a) Criar o banco de dados BdVarejo
-- ------------------------------------------------------------
CREATE DATABASE BdVarejo
CHARACTER SET utf8mb4
COLLATE utf8mb4_general_ci;

-- Selecionar o banco de dados
USE BdVarejo;

-- Conferir qual banco está selecionado
SELECT DATABASE();

-- Saída esperada:
-- BdVarejo


-- ------------------------------------------------------------
-- b) Criar as tabelas e definir as chaves e restrições
-- ------------------------------------------------------------
-- Cinco tabelas: Lojas, Clientes, Produtos, Vendas e ItensVenda.
-- Criadas nessa ordem para que as tabelas referenciadas já existam
-- ao definir os relacionamentos.

-- Tabela Lojas
CREATE TABLE BdVarejo.Lojas (
    codl INT NOT NULL,
    nome VARCHAR(30) NOT NULL,
    cidade VARCHAR(30),
    uf CHAR(2),
    PRIMARY KEY (codl)
);

-- Tabela Clientes
-- codc é chave primária.
-- O CPF ainda NÃO recebe UNIQUE no item b: o índice único
-- será criado no item d, conforme solicitado.
CREATE TABLE BdVarejo.Clientes (
    codc INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    CPF NUMERIC(11),
    cidade VARCHAR(30),
    PRIMARY KEY (codc)
);

-- Tabela Produtos
-- codp é chave primária
CREATE TABLE BdVarejo.Produtos (
    codp INT NOT NULL,
    descricao VARCHAR(40) NOT NULL,
    categoria CHAR(20),
    preco NUMERIC(8,2) NOT NULL,
    PRIMARY KEY (codp)
);

-- Tabela Vendas
-- codv é chave primária
-- e há chaves estrangeiras para Clientes e Lojas
CREATE TABLE BdVarejo.Vendas (
    codv INT NOT NULL,
    codc INT,
    codl INT,
    data DATE NOT NULL,
    hora TIME NOT NULL,
    PRIMARY KEY (codv),
    CONSTRAINT fk_vendas_clientes FOREIGN KEY (codc)
        REFERENCES BdVarejo.Clientes (codc),
    CONSTRAINT fk_vendas_lojas FOREIGN KEY (codl)
        REFERENCES BdVarejo.Lojas (codl)
);

-- Tabela ItensVenda
-- Chave primária composta por (codv, codp)
-- e chaves estrangeiras para Vendas e Produtos.
-- codv e codp participam da PK e também são FKs (PK e FK).
-- (a coluna desconto entra somente no item c)
CREATE TABLE BdVarejo.ItensVenda (
    codv INT NOT NULL,
    codp INT NOT NULL,
    qtd SMALLINT NOT NULL,
    valor NUMERIC(8,2) NOT NULL,
    PRIMARY KEY (codv, codp),
    CONSTRAINT fk_itensvenda_vendas FOREIGN KEY (codv)
        REFERENCES BdVarejo.Vendas (codv),
    CONSTRAINT fk_itensvenda_produtos FOREIGN KEY (codp)
        REFERENCES BdVarejo.Produtos (codp)
);

-- Conferência das tabelas
-- Listar as tabelas criadas
SHOW TABLES FROM BdVarejo;

-- Saída esperada, independentemente da ordem de exibição:
-- Clientes
-- ItensVenda
-- Lojas
-- Produtos
-- Vendas

-- Conferir a estrutura de cada tabela
DESCRIBE BdVarejo.Lojas;

DESCRIBE BdVarejo.Clientes;

DESCRIBE BdVarejo.Produtos;

DESCRIBE BdVarejo.Vendas;

DESCRIBE BdVarejo.ItensVenda;

-- Conferir a definição completa de ItensVenda
SHOW CREATE TABLE BdVarejo.ItensVenda;

-- Na definição retornada, verificar:
-- PRIMARY KEY (codv, codp)
-- fk_itensvenda_vendas: codv referencia Vendas.codv
-- fk_itensvenda_produtos: codp referencia Produtos.codp

-- Para conferir todos os relacionamentos em uma grade:
SELECT
    TABLE_NAME AS tabela,
    COLUMN_NAME AS coluna,
    REFERENCED_TABLE_NAME AS tabela_referenciada,
    REFERENCED_COLUMN_NAME AS coluna_referenciada
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_SCHEMA = 'BdVarejo'
  AND REFERENCED_TABLE_NAME IS NOT NULL
ORDER BY TABLE_NAME, COLUMN_NAME;

-- Relações esperadas:
-- ItensVenda.codp -> Produtos.codp
-- ItensVenda.codv -> Vendas.codv
-- Vendas.codc     -> Clientes.codc
-- Vendas.codl     -> Lojas.codl


-- ------------------------------------------------------------
-- c) Adicionar desconto à tabela ItensVenda
-- ------------------------------------------------------------

-- Adicionar a coluna desconto do tipo NUMERIC(5,2)
ALTER TABLE BdVarejo.ItensVenda
ADD COLUMN desconto NUMERIC(5,2);

-- Conferir a estrutura após a alteração
DESCRIBE BdVarejo.ItensVenda;

-- Colunas esperadas na saída:
-- codv
-- codp
-- qtd
-- valor
-- desconto


-- ------------------------------------------------------------
-- d) Criar os índices
-- ------------------------------------------------------------
-- Índice único sobre CPF em Clientes
-- e índice comum sobre categoria em Produtos.

-- Índice único sobre CPF em Clientes
CREATE UNIQUE INDEX uq_clientes_cpf
ON BdVarejo.Clientes (CPF);

-- Índice comum sobre categoria em Produtos
CREATE INDEX idx_produtos_categoria
ON BdVarejo.Produtos (categoria);

-- Conferência dos índices
-- Conferir os índices de Clientes
SHOW INDEX FROM BdVarejo.Clientes;

-- Entre os resultados, verificar:
-- Key_name: uq_clientes_cpf
-- Column_name: CPF
-- Non_unique: 0

-- Conferir os índices de Produtos
SHOW INDEX FROM BdVarejo.Produtos;

-- Entre os resultados, verificar:
-- Key_name: idx_produtos_categoria
-- Column_name: categoria
-- Non_unique: 1

-- Non_unique = 0: índice único
-- Non_unique = 1: índice que permite valores repetidos


-- ------------------------------------------------------------
-- e) Remover o índice sobre categoria de Produtos
-- ------------------------------------------------------------

-- Remover o índice criado sobre categoria em Produtos
DROP INDEX idx_produtos_categoria
ON BdVarejo.Produtos;

-- Conferir os índices restantes
SHOW INDEX FROM BdVarejo.Produtos;

-- Resultado esperado:
-- O índice idx_produtos_categoria não deve mais aparecer.
-- A chave primária permanece.
-- A coluna categoria continua existindo neste momento.


-- ------------------------------------------------------------
-- f) Remover uf de Lojas e categoria de Produtos
-- ------------------------------------------------------------

-- Remover a coluna uf de Lojas
ALTER TABLE BdVarejo.Lojas
DROP COLUMN uf;

-- Remover a coluna categoria de Produtos
ALTER TABLE BdVarejo.Produtos
DROP COLUMN categoria;

-- Conferir as colunas restantes em Lojas
DESCRIBE BdVarejo.Lojas;

-- Colunas esperadas na saída:
-- codl
-- nome
-- cidade

-- Conferir as colunas restantes em Produtos
DESCRIBE BdVarejo.Produtos;

-- Colunas esperadas na saída:
-- codp
-- descricao
-- preco
