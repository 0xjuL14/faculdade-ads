-- ============================================================
-- Banco de Dados | Exercício 2 — Indústria (BdIndustria)
-- SGBD: MariaDB 11.8 (Debian) | Cliente: DBeaver / terminal
--
-- Como executar (terminal):
--   sudo mariadb < bd_industria.sql
-- No DBeaver: abrir o arquivo e executar como script (Alt+X).
--
-- Atenção: o script segue os itens a) a f) do enunciado, em ordem.
-- O estado FINAL do banco é o do item f). Para ver o banco pronto,
-- use o arquivo da pasta dump/.
--
-- Pré-requisito: o usuário que executa precisa ter permissão para
-- criar/usar o banco BdIndustria (configuração do ambiente, feita
-- à parte, como administrador — não faz parte dos itens).
--
-- Para poder rodar o script mais de uma vez, descomente a linha
-- abaixo. CUIDADO: ela APAGA o banco BdIndustria inteiro.
-- DROP DATABASE IF EXISTS BdIndustria;
-- ============================================================


-- ------------------------------------------------------------
-- a) Criar o banco de dados BdIndustria
-- ------------------------------------------------------------
CREATE DATABASE BdIndustria
CHARACTER SET utf8mb4
COLLATE utf8mb4_general_ci;

-- Selecionar o banco de dados
USE BdIndustria;

-- Conferir qual banco está selecionado
SELECT DATABASE();

-- Saída esperada:
-- BdIndustria


-- ------------------------------------------------------------
-- b) Criar as tabelas e definir as chaves e restrições
-- ------------------------------------------------------------
-- Ordem: primeiro Linhas, depois Operadores e Maquinas, e por último
-- OrdensProducao. Assim, as tabelas referenciadas já existem quando
-- as chaves estrangeiras são criadas.

-- Tabela Linhas
CREATE TABLE BdIndustria.Linhas (
    codl INT NOT NULL,
    nome VARCHAR(30) NOT NULL,
    capacidade NUMERIC(6,2),
    PRIMARY KEY (codl)
);

-- Tabela Operadores
-- matricula é chave primária
-- e codl é chave estrangeira referenciando Linhas
CREATE TABLE BdIndustria.Operadores (
    matricula INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    turno CHAR(1) NOT NULL,
    codl INT,
    PRIMARY KEY (matricula),
    CONSTRAINT fk_operadores_linhas FOREIGN KEY (codl)
        REFERENCES BdIndustria.Linhas (codl)
);

-- Tabela Maquinas
-- codm é chave primária
-- e codl é chave estrangeira referenciando Linhas
CREATE TABLE BdIndustria.Maquinas (
    codm INT NOT NULL,
    modelo VARCHAR(30) NOT NULL,
    ano SMALLINT,
    codl INT,
    PRIMARY KEY (codm),
    CONSTRAINT fk_maquinas_linhas FOREIGN KEY (codl)
        REFERENCES BdIndustria.Linhas (codl)
);

-- Tabela OrdensProducao
-- nro é chave primária
-- e há chaves estrangeiras para Linhas, Operadores e Maquinas
-- (a coluna status e os índices entram nos itens seguintes)
CREATE TABLE BdIndustria.OrdensProducao (
    nro INT NOT NULL,
    codl INT,
    matricula INT,
    codm INT,
    qtd NUMERIC(10,2) NOT NULL,
    dt_inicio DATE NOT NULL,
    dt_fim DATE,
    PRIMARY KEY (nro),
    CONSTRAINT fk_ordensproducao_linhas FOREIGN KEY (codl)
        REFERENCES BdIndustria.Linhas (codl),
    CONSTRAINT fk_ordensproducao_operadores FOREIGN KEY (matricula)
        REFERENCES BdIndustria.Operadores (matricula),
    CONSTRAINT fk_ordensproducao_maquinas FOREIGN KEY (codm)
        REFERENCES BdIndustria.Maquinas (codm)
);

-- Conferência das tabelas
-- Listar as tabelas criadas
SHOW TABLES FROM BdIndustria;

-- Saída esperada, independentemente da ordem de exibição:
-- Linhas
-- Maquinas
-- Operadores
-- OrdensProducao

-- Conferir a estrutura de cada tabela
DESCRIBE BdIndustria.Linhas;

DESCRIBE BdIndustria.Operadores;

DESCRIBE BdIndustria.Maquinas;

DESCRIBE BdIndustria.OrdensProducao;

-- Conferir a definição completa de OrdensProducao
SHOW CREATE TABLE BdIndustria.OrdensProducao;

-- Na definição retornada, verificar:
-- PRIMARY KEY (nro)
-- fk_ordensproducao_linhas: codl referencia Linhas.codl
-- fk_ordensproducao_operadores:
--     matricula referencia Operadores.matricula
-- fk_ordensproducao_maquinas: codm referencia Maquinas.codm

-- Para visualizar todas as chaves estrangeiras do banco em uma grade:
SELECT
    TABLE_NAME AS tabela,
    COLUMN_NAME AS coluna,
    REFERENCED_TABLE_NAME AS tabela_referenciada,
    REFERENCED_COLUMN_NAME AS coluna_referenciada
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_SCHEMA = 'BdIndustria'
  AND REFERENCED_TABLE_NAME IS NOT NULL
ORDER BY TABLE_NAME, COLUMN_NAME;

-- Relações esperadas:
-- Maquinas.codl            -> Linhas.codl
-- Operadores.codl          -> Linhas.codl
-- OrdensProducao.codl      -> Linhas.codl
-- OrdensProducao.codm      -> Maquinas.codm
-- OrdensProducao.matricula -> Operadores.matricula


-- ------------------------------------------------------------
-- c) Adicionar status à tabela OrdensProducao
-- ------------------------------------------------------------

-- Adicionar a coluna status do tipo CHAR(12)
ALTER TABLE BdIndustria.OrdensProducao
ADD COLUMN status CHAR(12);

-- Conferir a estrutura após a alteração
DESCRIBE BdIndustria.OrdensProducao;

-- Colunas esperadas na saída:
-- nro
-- codl
-- matricula
-- codm
-- qtd
-- dt_inicio
-- dt_fim
-- status


-- ------------------------------------------------------------
-- d) Criar os índices
-- ------------------------------------------------------------
-- O enunciado pede um índice único sobre a combinação de modelo e ano
-- em Maquinas, e um índice comum sobre dt_inicio em OrdensProducao.

-- Índice único composto por modelo e ano em Maquinas
CREATE UNIQUE INDEX uq_maquinas_modelo_ano
ON BdIndustria.Maquinas (modelo, ano);

-- Índice comum sobre dt_inicio em OrdensProducao
CREATE INDEX idx_ordensproducao_dt_inicio
ON BdIndustria.OrdensProducao (dt_inicio);

-- O primeiro é UM único índice composto pelas duas colunas (não dois
-- índices separados). Ele impede repetir a combinação de modelo e ano
-- quando ambos os valores são não nulos.

-- Conferência dos índices
-- Conferir os índices de Maquinas
SHOW INDEX FROM BdIndustria.Maquinas;

-- Entre os resultados, verificar:
-- Key_name: uq_maquinas_modelo_ano
-- Non_unique: 0
-- Seq_in_index: 1 | Column_name: modelo
-- Seq_in_index: 2 | Column_name: ano
-- As duas linhas representam o mesmo índice composto.

-- Conferir os índices de OrdensProducao
SHOW INDEX FROM BdIndustria.OrdensProducao;

-- Entre os resultados, verificar:
-- Key_name: idx_ordensproducao_dt_inicio
-- Column_name: dt_inicio
-- Non_unique: 1


-- ------------------------------------------------------------
-- e) Remover o índice sobre dt_inicio
-- ------------------------------------------------------------

-- Remover o índice sobre dt_inicio de OrdensProducao
DROP INDEX idx_ordensproducao_dt_inicio
ON BdIndustria.OrdensProducao;

-- Conferir os índices restantes
SHOW INDEX FROM BdIndustria.OrdensProducao;

-- Resultado esperado:
-- O índice idx_ordensproducao_dt_inicio não deve mais aparecer.
-- Os demais índices permanecem.
-- A coluna dt_inicio continua existindo na tabela.
-- (O comando remove somente o índice, sem excluir a coluna ou seus dados.)


-- ------------------------------------------------------------
-- f) Remover dt_fim de OrdensProducao e capacidade de Linhas
-- ------------------------------------------------------------

-- Remover a coluna dt_fim de OrdensProducao
ALTER TABLE BdIndustria.OrdensProducao
DROP COLUMN dt_fim;

-- Remover a coluna capacidade de Linhas
ALTER TABLE BdIndustria.Linhas
DROP COLUMN capacidade;

-- Conferir as colunas restantes em OrdensProducao
DESCRIBE BdIndustria.OrdensProducao;

-- Colunas esperadas na saída:
-- nro
-- codl
-- matricula
-- codm
-- qtd
-- dt_inicio
-- status

-- Conferir as colunas restantes em Linhas
DESCRIBE BdIndustria.Linhas;

-- Colunas esperadas na saída:
-- codl
-- nome
