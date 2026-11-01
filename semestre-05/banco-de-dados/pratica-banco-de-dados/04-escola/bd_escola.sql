-- ============================================================
-- Banco de Dados | Exercício 4 — Educação (BdEscola)
-- SGBD: MariaDB 11.8 (Debian) | Cliente: DBeaver / terminal
--
-- Como executar (terminal):
--   sudo mariadb < bd_escola.sql
-- No DBeaver: abrir o arquivo e executar como script (Alt+X).
--
-- Atenção: o script segue os itens a) a f) do enunciado, em ordem.
-- O estado FINAL do banco é o do item f). Para ver o banco pronto,
-- use o arquivo da pasta dump/.
--
-- Pré-requisito: o usuário que executa precisa ter permissão para
-- criar/usar o banco BdEscola (configuração do ambiente, feita
-- à parte, como administrador — não faz parte dos itens).
--
-- Para poder rodar o script mais de uma vez, descomente a linha
-- abaixo. CUIDADO: ela APAGA o banco BdEscola inteiro.
-- DROP DATABASE IF EXISTS BdEscola;
-- ============================================================


-- ------------------------------------------------------------
-- a) Criar o banco de dados BdEscola
-- ------------------------------------------------------------
CREATE DATABASE BdEscola
CHARACTER SET utf8mb4
COLLATE utf8mb4_general_ci;

-- Selecionar o banco de dados
USE BdEscola;

-- Conferir qual banco está selecionado
SELECT DATABASE();

-- Saída esperada:
-- BdEscola


-- ------------------------------------------------------------
-- b) Criar as tabelas e definir as chaves e restrições
-- ------------------------------------------------------------
-- Cinco tabelas: Cursos, Professores, Turmas, Alunos e Matriculas.
-- Criadas nessa ordem para que as tabelas referenciadas já existam
-- quando os relacionamentos forem definidos.

-- Tabela Cursos
CREATE TABLE BdEscola.Cursos (
    codc INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    carga_horaria SMALLINT,
    PRIMARY KEY (codc)
);

-- Tabela Professores
-- codpr é chave primária.
-- O índice único sobre o CPF de Professores só é criado no item d
-- (já o CPF de Alunos precisa ser único desde o item b).
CREATE TABLE BdEscola.Professores (
    codpr INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    titulacao CHAR(15),
    CPF NUMERIC(11),
    PRIMARY KEY (codpr)
);

-- Tabela Turmas
-- codt é chave primária
-- e há chaves estrangeiras para Cursos e Professores
CREATE TABLE BdEscola.Turmas (
    codt INT NOT NULL,
    codc INT,
    codpr INT,
    semestre CHAR(6) NOT NULL,
    sala VARCHAR(10),
    PRIMARY KEY (codt),
    CONSTRAINT fk_turmas_cursos FOREIGN KEY (codc)
        REFERENCES BdEscola.Cursos (codc),
    CONSTRAINT fk_turmas_professores FOREIGN KEY (codpr)
        REFERENCES BdEscola.Professores (codpr)
);

-- Tabela Alunos
-- ra é chave primária, CPF é único
-- e codc é chave estrangeira referenciando Cursos
CREATE TABLE BdEscola.Alunos (
    ra INT NOT NULL,
    nome VARCHAR(40) NOT NULL,
    idade SMALLINT NOT NULL,
    cidade VARCHAR(30),
    CPF NUMERIC(11),
    codc INT,
    PRIMARY KEY (ra),
    CONSTRAINT uq_alunos_cpf UNIQUE (CPF),
    CONSTRAINT fk_alunos_cursos FOREIGN KEY (codc)
        REFERENCES BdEscola.Cursos (codc)
);

-- Tabela Matriculas
-- Chave primária composta por (ra, codt)
-- e chaves estrangeiras para Alunos e Turmas.
-- ra e codt formam juntos a PK e também são FKs (PK e FK).
-- (a coluna status entra somente no item c)
CREATE TABLE BdEscola.Matriculas (
    ra INT NOT NULL,
    codt INT NOT NULL,
    nota NUMERIC(4,2),
    faltas SMALLINT,
    PRIMARY KEY (ra, codt),
    CONSTRAINT fk_matriculas_alunos FOREIGN KEY (ra)
        REFERENCES BdEscola.Alunos (ra),
    CONSTRAINT fk_matriculas_turmas FOREIGN KEY (codt)
        REFERENCES BdEscola.Turmas (codt)
);

-- Conferência das tabelas
-- Listar as tabelas criadas
SHOW TABLES FROM BdEscola;

-- Saída esperada, independentemente da ordem de exibição:
-- Alunos
-- Cursos
-- Matriculas
-- Professores
-- Turmas

-- Conferir a estrutura de cada tabela
DESCRIBE BdEscola.Cursos;

DESCRIBE BdEscola.Professores;

DESCRIBE BdEscola.Turmas;

DESCRIBE BdEscola.Alunos;

DESCRIBE BdEscola.Matriculas;

-- Conferir a definição completa de Matriculas
SHOW CREATE TABLE BdEscola.Matriculas;

-- Na definição retornada, verificar:
-- PRIMARY KEY (ra, codt)
-- fk_matriculas_alunos: ra referencia Alunos.ra
-- fk_matriculas_turmas: codt referencia Turmas.codt

-- Para conferir todos os relacionamentos em uma grade:
SELECT
    TABLE_NAME AS tabela,
    COLUMN_NAME AS coluna,
    REFERENCED_TABLE_NAME AS tabela_referenciada,
    REFERENCED_COLUMN_NAME AS coluna_referenciada
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_SCHEMA = 'BdEscola'
  AND REFERENCED_TABLE_NAME IS NOT NULL
ORDER BY TABLE_NAME, COLUMN_NAME;

-- Relações esperadas:
-- Alunos.codc     -> Cursos.codc
-- Matriculas.codt -> Turmas.codt
-- Matriculas.ra   -> Alunos.ra
-- Turmas.codc     -> Cursos.codc
-- Turmas.codpr    -> Professores.codpr


-- ------------------------------------------------------------
-- c) Adicionar status à tabela Matriculas
-- ------------------------------------------------------------

-- Adicionar a coluna status do tipo CHAR(10)
ALTER TABLE BdEscola.Matriculas
ADD COLUMN status CHAR(10);

-- Conferir a estrutura após a alteração
DESCRIBE BdEscola.Matriculas;

-- Colunas esperadas na saída:
-- ra
-- codt
-- nota
-- faltas
-- status


-- ------------------------------------------------------------
-- d) Criar os índices
-- ------------------------------------------------------------
-- Índice único sobre CPF em Professores
-- e índice comum sobre nome em Alunos.

-- Índice único sobre CPF em Professores
CREATE UNIQUE INDEX uq_professores_cpf
ON BdEscola.Professores (CPF);

-- Índice comum sobre nome em Alunos
CREATE INDEX idx_alunos_nome
ON BdEscola.Alunos (nome);

-- Conferência dos índices
-- Conferir os índices de Professores
SHOW INDEX FROM BdEscola.Professores;

-- Entre os resultados, verificar:
-- Key_name: uq_professores_cpf
-- Column_name: CPF
-- Non_unique: 0

-- Conferir os índices de Alunos
SHOW INDEX FROM BdEscola.Alunos;

-- Entre os resultados, verificar:
-- Key_name: idx_alunos_nome
-- Column_name: nome
-- Non_unique: 1

-- O índice uq_alunos_cpf, criado no item b,
-- também deve continuar aparecendo.

-- Non_unique = 0: índice único
-- Non_unique = 1: índice que permite valores repetidos


-- ------------------------------------------------------------
-- e) Remover o índice sobre nome de Alunos
-- ------------------------------------------------------------

-- Remover o índice criado sobre nome em Alunos
DROP INDEX idx_alunos_nome
ON BdEscola.Alunos;

-- Conferir os índices restantes
SHOW INDEX FROM BdEscola.Alunos;

-- Resultado esperado:
-- O índice idx_alunos_nome não deve mais aparecer.
-- Os demais índices permanecem.
-- A coluna nome continua existindo na tabela.


-- ------------------------------------------------------------
-- f) Remover sala de Turmas e cidade de Alunos
-- ------------------------------------------------------------

-- Remover a coluna sala de Turmas
ALTER TABLE BdEscola.Turmas
DROP COLUMN sala;

-- Remover a coluna cidade de Alunos
ALTER TABLE BdEscola.Alunos
DROP COLUMN cidade;

-- Conferir as colunas restantes em Turmas
DESCRIBE BdEscola.Turmas;

-- Colunas esperadas na saída:
-- codt
-- codc
-- codpr
-- semestre

-- Conferir as colunas restantes em Alunos
DESCRIBE BdEscola.Alunos;

-- Colunas esperadas na saída:
-- ra
-- nome
-- idade
-- CPF
-- codc
