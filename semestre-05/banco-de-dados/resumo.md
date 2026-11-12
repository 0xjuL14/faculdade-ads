---
titulo: "Banco de Dados: consulta rápida"
disciplina: Banco de Dados
atualizado: 2026-11-12
ambiente: Debian + MariaDB 10.11 + DBeaver
tags: [banco-de-dados, sql, mariadb, resumo]
---

# Banco de Dados: consulta rápida

> [!info] Como usar
> Versão em Markdown do `resumo-banco-de-dados.html` (mesmo conteúdo). Os callouts (`> [!note]`, `> [!tip]`...) são do **Obsidian**; em outros editores aparecem como citações comuns. Todo SQL foi testado no MariaDB 10.11.
>
> Legenda: **Nota** = definição/explicação · **Importante / Cai na prova** = ponto-chave · **Atenção** = armadilha/erro comum · **Dica** = boa prática.

## Sumário

1. [[#1. Preparando o ambiente: MariaDB + DBeaver no Debian|Preparando o ambiente: MariaDB + DBeaver no Debian]]
2. [[#2. Conceitos básicos: dado, informação, BD, SGBD, SBD|Conceitos básicos: dado, informação, BD, SGBD, SBD]]
3. [[#3. SGBD × sistema de arquivos e as 6 regras|SGBD × sistema de arquivos e as 6 regras]]
4. [[#4. Abstração, esquema × instância e independência|Abstração, esquema × instância e independência]]
5. [[#5. Modelos de dados, linguagens, papéis e estrutura do SGBD|Modelos de dados, linguagens, papéis e estrutura do SGBD]]
6. [[#6. Arquiteturas, BD na web, SGBDs e ODBC|Arquiteturas, BD na web, SGBDs e ODBC]]
7. [[#7. Redundância e projeto de BD|Redundância e projeto de BD]]
8. [[#8. Modelo Entidade-Relacionamento (MER/DER)|Modelo Entidade-Relacionamento (MER/DER)]]
9. [[#9. Cardinalidade|Cardinalidade]]
10. [[#10. Abordagem relacional e chaves|Abordagem relacional e chaves]]
11. [[#11. Do MER às tabelas (modelo lógico)|Do MER às tabelas (modelo lógico)]]
12. [[#12. Normalização (1FN, 2FN, 3FN)|Normalização (1FN, 2FN, 3FN)]]
13. [[#13. SQL: visão geral e DDL|SQL: visão geral e DDL]]
14. [[#14. DML: inserir, alterar e excluir|DML: inserir, alterar e excluir]]
15. [[#15. SELECT em uma tabela|SELECT em uma tabela]]
16. [[#16. Consultas com várias tabelas (junções)|Consultas com várias tabelas (junções)]]
17. [[#17. Subconsultas (consultas aninhadas)|Subconsultas (consultas aninhadas)]]
18. [[#18. Ordenação, grupos e atualização com consulta|Ordenação, grupos e atualização com consulta]]
19. [[#19. Conexão com aplicações: PHP, Java e C|Conexão com aplicações: PHP, Java e C]]
20. [[#20. Tabela de socorro: "por que não funciona?"|Tabela de socorro: "por que não funciona?"]]
21. [[#21. Pontos de atenção encontrados nos slides|Pontos de atenção encontrados nos slides]]
22. [[#22. Listas de exercícios (tente sozinha)|Listas de exercícios (tente sozinha)]]
23. [[#23. Revisão final|Revisão final]]

---

## 1. Preparando o ambiente: MariaDB + DBeaver no Debian

*(Fonte: configuração prática, não está nos slides. Testado com MariaDB 10.11, a versão do Debian 12)*

### 1.1 O que vamos montar

| Peça | O que é | Analogia |
|---|---|---|
| **MariaDB Server** | O **SGBD**: programa que guarda os dados e executa o SQL | A cozinha do restaurante |
| **Cliente `mariadb`** | Terminal para mandar SQL ao servidor | Falar direto com o cozinheiro |
| **DBeaver** | Interface gráfica (cliente) para escrever SQL e ver tabelas | O garçom com cardápio bonito |

> [!note] MariaDB × MySQL
> O MariaDB nasceu como um *fork* (cópia independente) do MySQL. Para o que vemos na disciplina, os comandos são praticamente iguais. Por isso os slides dizem "MySQL" e tudo funciona no MariaDB.

### 1.2 Instalar o MariaDB (precisa de `sudo`)

```bash
# Debian/Ubuntu e derivados (família apt)
sudo apt update
sudo apt install mariadb-server mariadb-client

# O serviço está rodando?
systemctl status mariadb          # procure "active (running)"; saia com q
mariadb --version
```

Se o serviço estiver parado:

```bash
sudo systemctl start mariadb      # liga agora
sudo systemctl enable mariadb     # liga sozinho ao iniciar o PC (opcional)
```

> [!tip] Dica
> Em máquina de estudo dá para **não** usar `enable` e ligar só quando for estudar (`sudo systemctl start mariadb`). Economiza memória e é um serviço a menos rodando.

### 1.3 Deixar a instalação segura

```bash
sudo mariadb-secure-installation   # em versões antigas: sudo mysql_secure_installation
```

Respostas recomendadas para estudo:

| Pergunta | Resposta | Por quê |
|---|---|---|
| Current password for root | *Enter* (vazio) | No Debian o root entra pelo login do sistema (*unix_socket*) |
| Switch to unix_socket authentication | `n` | Já está assim no Debian |
| Change the root password | `n` | O root continua acessível só via `sudo` (mais seguro) |
| Remove anonymous users | `Y` | Usuários sem nome são brecha |
| Disallow root login remotely | `Y` | Root só local |
| Remove test database | `Y` | Banco aberto a todos |
| Reload privilege tables | `Y` | Aplica as mudanças |

### 1.4 Criar o seu usuário de estudo

No Debian, o `root` do MariaDB **só entra com `sudo`**. O DBeaver não consegue usar esse tipo de login, então criamos um usuário próprio com senha.

```bash
sudo mariadb                       # abre o terminal do MariaDB como root
```

```sql
-- Troque 'juh' e a senha. Não reutilize senhas de outros serviços.
CREATE USER 'juh'@'localhost' IDENTIFIED BY 'TroqueEstaSenha!2026';

-- Permissão total só nos bancos cujo nome começa com "bd" (bdClinica, bdpratica...)
-- As crases (`) são obrigatórias por causa do curinga %
GRANT ALL PRIVILEGES ON `bd%`.* TO 'juh'@'localhost';

SHOW GRANTS FOR 'juh'@'localhost';  -- confere as permissões
EXIT;
```

> [!important] Princípio do menor privilégio
> Dar `ALL ON *.*` (tudo em todos os bancos) funciona, mas é mais permissão do que você precisa. Com o curinga `bd%` você pode criar e apagar seus bancos de exercício sem tocar nos bancos de sistema (`mysql`, `information_schema`).

Teste o login:

```bash
mariadb -u juh -p                  # -p pede a senha (não digite a senha no comando!)
```

```sql
CREATE DATABASE bdteste;
SHOW DATABASES;
DROP DATABASE bdteste;
```

> [!warning] Atenção
> Não use `mariadb -u juh -pMinhaSenha`: a senha fica salva no histórico do Bash (`~/.bash_history`) e aparece na lista de processos.

### 1.5 Instalar o DBeaver Community

Escolha **uma** das opções:

| Opção | Prós | Contras |
|---|---|---|
| **Pacote `.deb` oficial** | Integra ao sistema; já vem com Java embutido | Atualização manual (baixar de novo) |
| **Flatpak (Flathub)** | Atualiza com `flatpak update`; isolado do sistema | Ocupa mais espaço; primeira instalação baixa runtimes |

```bash
# Opção A: .deb (baixe "Linux Debian package" em https://dbeaver.io/download/)
cd ~/Downloads
sudo apt install ./dbeaver-ce_*_amd64.deb   # o ./ é obrigatório para instalar arquivo local

# Opção B: Flatpak
sudo apt install flatpak
flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
flatpak install flathub io.dbeaver.DBeaverCommunity
```

Para desinstalar: `sudo apt remove dbeaver-ce` (opção A) ou `flatpak uninstall io.dbeaver.DBeaverCommunity` (opção B).

### 1.6 Conectar o DBeaver ao MariaDB

1. **Database → New Database Connection** (ou ícone de tomada com "+").
2. Escolha **MariaDB** → *Next*.
3. Preencha: **Server Host** `localhost` · **Port** `3306` · **Database** em branco (ou `bdClinica`) · **Username** `juh` · **Password** sua senha.
4. Clique em **Test Connection**. Na primeira vez ele pede para **baixar o driver**: aceite (*Download*).
5. *Finish*. A conexão aparece no **Database Navigator** (painel esquerdo).

Atalhos úteis no editor SQL (**SQL Editor → New SQL script**, ou `Ctrl+]`):

| Atalho | Faz o quê |
|---|---|
| `Ctrl+Enter` | Executa **o comando onde está o cursor** |
| `Alt+X` | Executa **o script inteiro** (todos os comandos) |
| `Ctrl+Espaço` | Autocompletar nomes de tabelas/colunas |
| `F5` no navegador | Atualiza a lista de tabelas (depois de um `CREATE`) |

> [!note] Nota
> Comandos separados por `;` e por linha em branco. Se o `Ctrl+Enter` executar "pedaço errado", selecione o comando com o mouse antes.

### 1.7 Criar o `bdClinica` (base de quase todos os exercícios)

Cole este script no DBeaver e rode com `Alt+X` (ou salve como `bdclinica.sql` e rode `mariadb -u juh -p < bdclinica.sql`).

```sql
-- =========================================================
-- bdClinica: criação + população (base dos exercícios)
-- Fonte: SQL_Introducao01.pdf / SQL_INCLUSAO_POPULACAO.pdf
-- Testado no MariaDB (Debian)
-- =========================================================

DROP DATABASE IF EXISTS bdClinica;     -- CUIDADO: apaga o banco se já existir
CREATE DATABASE bdClinica
  CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
USE bdClinica;
SET NAMES utf8mb4;                     -- garante acentos corretos (ex.: São José)

-- 1) Tabelas "pai" primeiro (não dependem de ninguém)
CREATE TABLE Ambulatorios (
  nroa        INT,
  andar       NUMERIC(3)  NOT NULL,
  capacidade  SMALLINT,
  PRIMARY KEY (nroa)
);

CREATE TABLE Pacientes (
  codp    INT,
  nome    VARCHAR(40) NOT NULL,
  idade   SMALLINT    NOT NULL,
  cidade  CHAR(30),
  CPF     NUMERIC(11) UNIQUE,
  doenca  VARCHAR(40) NOT NULL,
  PRIMARY KEY (codp)
);

CREATE TABLE Funcionarios (
  codf     INT,
  nome     VARCHAR(40) NOT NULL,
  idade    SMALLINT,
  CPF      NUMERIC(11) UNIQUE,
  cidade   VARCHAR(30),
  salario  NUMERIC(10),
  cargo    VARCHAR(20),
  PRIMARY KEY (codf)
);

-- 2) Tabelas "filho" depois (têm chave estrangeira)
CREATE TABLE Medicos (
  codm           INT,
  nome           VARCHAR(40) NOT NULL,
  idade          SMALLINT    NOT NULL,
  especialidade  CHAR(20),
  CPF            NUMERIC(11) UNIQUE,
  cidade         VARCHAR(30),
  nroa           INT,
  PRIMARY KEY (codm),
  FOREIGN KEY (nroa) REFERENCES Ambulatorios (nroa)
);

CREATE TABLE Consultas (
  codm  INT,
  codp  INT,
  data  DATE,
  hora  TIME,
  PRIMARY KEY (codm, codp, data),          -- chave escolhida aqui: confirmar com a professora
  FOREIGN KEY (codm) REFERENCES Medicos (codm),
  FOREIGN KEY (codp) REFERENCES Pacientes (codp)
);

-- 3) População (na mesma ordem: pai -> filho)
INSERT INTO Ambulatorios VALUES
  (1, 1, 30), (2, 1, 50), (3, 2, 40), (4, 2, 25), (5, 2, 55);

INSERT INTO Medicos VALUES
  (1, 'Joao',   40, 'ortopedia',     37842156964, 'Florianopolis', 1),
  (2, 'Maria',  42, 'traumatologia', 24973816582, 'Blumenau',      2),
  (3, 'Pedro',  51, 'pediatria',     51684297346, 'São José',      2),
  (4, 'Carlos', 28, 'ortopedia',     83715924691, 'Joinville',     3),
  (5, 'Marcia', 33, 'neurologia',    69248375146, 'Biguacu',       3);

INSERT INTO Pacientes VALUES
  (1, 'Ana',    20, 'Florianopolis', 37492685173, 'gripe'),
  (2, 'Paulo',  24, 'Palhoca',       53827419646, 'fratura'),
  (3, 'Lucia',  30, 'Biguacu',       69148352764, 'tendinite'),
  (4, 'Carlos', 28, 'Joinville',     82573941655, 'sarampo');

INSERT INTO Funcionarios (codf, nome, idade, cidade, salario, CPF) VALUES
  (1, 'Rita',   32, 'Sao Jose',      1200, 26491738582),
  (2, 'Maria',  55, 'Palhoca',       1220, 39614872519),
  (3, 'Caio',   45, 'Florianopolis', 1100, 58273914682),
  (4, 'Carlos', 44, 'Florianopolis', 1200, 81469257319),
  (5, 'Paula',  33, 'Florianopolis', 2500, 63952841773);

INSERT INTO Consultas VALUES
  (1, 1, '2026-06-12', '14:00'),
  (1, 4, '2026-06-13', '10:00'),
  (2, 1, '2026-06-13', '09:00'),
  (2, 2, '2026-06-13', '11:00'),
  (2, 3, '2026-06-14', '14:00'),
  (2, 4, '2026-06-14', '17:00'),
  (3, 1, '2026-06-19', '18:00'),
  (3, 3, '2026-06-12', '10:00'),
  (3, 4, '2026-06-19', '13:00'),
  (4, 4, '2026-06-20', '13:00'),
  (4, 4, '2026-06-22', '19:30');

-- 4) Conferência rápida
SELECT 'Ambulatorios' AS tabela, COUNT(*) AS linhas FROM Ambulatorios
UNION ALL SELECT 'Medicos',      COUNT(*) FROM Medicos
UNION ALL SELECT 'Pacientes',    COUNT(*) FROM Pacientes
UNION ALL SELECT 'Funcionarios', COUNT(*) FROM Funcionarios
UNION ALL SELECT 'Consultas',    COUNT(*) FROM Consultas;
```

> [!warning] Atenção
> A primeira linha (`DROP DATABASE IF EXISTS`) **apaga** o `bdClinica` se ele já existir. É ótimo para "resetar" o banco depois de exercícios de `DELETE`, mas você perde o que tinha feito nele.

> [!important] Importante
> Os slides não deixam claro qual é a chave primária de `Consultas`. Usei `(codm, codp, data)` porque o médico 4 tem duas consultas com o paciente 4 em dias diferentes. **Confirmar com a professora.**

### 1.8 Como verificar

```sql
SHOW DATABASES;            -- bdClinica aparece?
USE bdClinica;
SHOW TABLES;               -- 5 tabelas
DESCRIBE Medicos;          -- colunas, tipos, chaves (PRI, UNI, MUL)
SHOW CREATE TABLE Consultas;   -- mostra o CREATE completo, com as FKs
```

Resultado esperado da conferência no fim do script: Ambulatorios 5 · Medicos 5 · Pacientes 4 · Funcionarios 5 · Consultas 11.

---

## 2. Conceitos básicos: dado, informação, BD, SGBD, SBD

*(Fonte: BD_AULA02_FundamentosI.pdf, BD_AULA02_CONCEITOS.pdf)*

### 2.1 Dado × informação

| | Dado | Informação |
|---|---|---|
| O que é | Matéria bruta; valor registrado | Dado com significado para alguém, num contexto |
| Exemplo | `37` | "A febre do paciente Paulo está em 37 °C" |

### 2.2 Definições principais

| Sigla | Definição (slides) | Exemplos |
|---|---|---|
| **BD** (Banco de Dados) | Coleção de dados **inter-relacionados**, representando informações sobre um **domínio específico** (minimundo / universo de discurso) | Lista telefônica, acervo de biblioteca |
| **SGBD** (Sistema Gerenciador de BD) | **Software** que permite criar, manter, manipular e compartilhar BDs | MySQL, MariaDB, Oracle, PostgreSQL, Access |
| **SBD** (Sistema de BD) | Sistema de registros por computador com **4 componentes: dados, hardware, software e usuários** | O sistema da clínica inteiro |

> [!note] BD não é qualquer amontoado de dados
> É uma coleção **lógica e coerente**, com significado, construída para uma **proposta específica**. Uma organização aleatória de dados não é um BD. Mudanças no mundo real devem ser refletidas no BD.

> [!important] Cai na prova
> "Agenda telefônica, lista de compras, dicionário e livro de romance são BDs?" Agenda, lista e dicionário têm dados organizados por um padrão e com propósito; o romance é texto corrido, sem estrutura de dados para consulta.

### 2.3 Por que sair das planilhas e arquivos?

Problemas do uso de planilhas/arquivos soltos:

- Falta de padronização
- Programas presos ao formato dos arquivos
- **Redundância** (mesmo dado em vários lugares) e **inconsistência** (cópias diferentes)
- Falta de integridade e de segurança
- Analista "dono" do sistema

Vantagens de um SBD:

- Rapidez no acesso; integração e compartilhamento
- Redução da redundância e da inconsistência
- Regras de integridade e segurança aplicadas automaticamente
- Transparência dos dados para as aplicações; desenvolvimento mais produtivo

### Revisão rápida

1. Qual a diferença entre BD, SGBD e SBD?
2. Quais os 4 componentes de um SBD?
3. Dê um exemplo de dado que vira informação.

---

## 3. SGBD × sistema de arquivos e as 6 regras

*(Fonte: BD_AULA02_CONCEITOS.pdf, BD_AULA02_FundamentosI.pdf)*

### 3.1 Quem acessa os dados?

| Sistema de arquivos | Sistema de Banco de Dados |
|---|---|
| Os **programas aplicativos** acessam e gerenciam os arquivos diretamente | O **SGBD** fica no meio, como interface entre os programas e os dados |

Problemas dos antigos arquivos de dados: inconsistência e redundância, dificuldade de acesso (programa novo até para consulta simples), integridade, **atomicidade** ("ou tudo dá certo ou aborta"), **acesso concorrente** (dois saques simultâneos) e segurança.

### 3.2 As 6 regras: SGBD × GA (Gerenciador de Arquivos)

Um SGBD precisa obedecer **todas** as seis. Se falhar em uma, é no máximo um "GA de alta qualidade".

| # | Regra | Ideia central | Se a aplicação precisa fazer, **não é SGBD** |
|---|---|---|---|
| 1 | **Autocontenção** | O SGBD guarda os dados **e** a descrição deles (estrutura, relacionamentos, acesso) | Programa declara a estrutura do registro (`struct` em C) |
| 2 | **Independência dos dados** | Aplicações imunes a mudanças no armazenamento ou na estratégia de acesso | Criar índice novo exige mexer no código |
| 3 | **Abstração dos dados** | Usuário vê só a representação conceitual (modelo de dados) | Usuário precisa conhecer o formato físico |
| 4 | **Visões** | Cada usuário pode ver os dados de forma diferente, sem cópias | Replicar a tabela para outro aplicativo |
| 5 | **Transações** | Gravar ou desfazer um conjunto de alterações com **uma** instrução; integridade referencial no SGBD | Desfazer "na mão" uma reserva cancelada |
| 6 | **Acesso automático** | O SGBD resolve bloqueios e evita **deadlock** | A aplicação tem que evitar o deadlock |

> [!note] Deadlock ("abraço mortal")
> O usuário A travou o registro X e espera o Y; o usuário B travou o Y e espera o X. Ninguém anda. No SGBD, quem resolve é ele próprio.

> [!tip] Dica
> Ponte com C: na regra 1, um programa em C que lê um arquivo binário de `struct` é o exemplo clássico de **GA**: a estrutura dos dados mora no código, não no "banco".

### 3.3 O que o SGBD garante

- **Controle de concorrência** (vários usuários ao mesmo tempo, sem estragar os dados)
- **Controle de transações**
- **Segurança** (quem pode ver/alterar)
- **Integridade** (regras: não nulo, único, chaves)
- **Backup/restore** facilitados

### 3.4 Utilitários de um SGBD

| Utilitário | Para quê |
|---|---|
| Carregamento (*loading*) | Importar arquivos/dados existentes; converter entre SGBDs |
| Backup | Copiar o BD (*dump*); também backup incremental |
| Reorganização de arquivos | Reorganizar o armazenamento para ganhar desempenho |
| Monitoramento de desempenho | Estatísticas para o DBA decidir melhorias |
| Espelhamento, replicação, clusterização | Cópias e distribuição para disponibilidade/desempenho |

Exemplo real de backup no MariaDB (no terminal, não no DBeaver):

```bash
mariadb-dump -u juh -p bdClinica > bdclinica_backup.sql   # cria o "dump"
mariadb -u juh -p bdClinica < bdclinica_backup.sql        # restaura (o banco precisa existir)
```

### Revisão rápida

1. Cite as 6 regras e dê um exemplo de violação de cada.
2. O que é deadlock? Qual regra trata dele?
3. Um programa em C que grava `struct` em arquivo binário é SGBD? Por quê?

---

## 4. Abstração, esquema × instância e independência

*(Fonte: BD_AULA02_FundamentosI.pdf, BD_AULA02_CONCEITOS.pdf)*

### 4.1 Os 3 níveis de abstração

| Nível | Outros nomes | Descreve | Quem usa |
|---|---|---|---|
| **Externo / de visões** | Nível mais alto | Só a **parte** do BD que cada usuário precisa | Usuários finais |
| **Lógico / conceitual** | Esquema conceitual | **Quais** dados existem e como se relacionam | DBA, projetista |
| **Físico / interno** | Nível mais baixo | **Como** os dados estão realmente armazenados | O SGBD |

```text
 Visão 1    Visão 2   ...   Visão n      ← nível externo (usuários)
      \        |          /
         Esquema conceitual              ← nível lógico
                |
         Esquema interno                 ← nível físico (disco)
```

Uma visão em SQL (exemplo do nível externo):

```sql
USE bdClinica;
-- A recepção só precisa ver nome e cidade dos pacientes, sem CPF e doença
CREATE VIEW vw_recepcao AS
  SELECT codp, nome, cidade FROM Pacientes;

SELECT * FROM vw_recepcao;
DROP VIEW vw_recepcao;   -- remove a visão (os dados de Pacientes continuam)
```

### 4.2 Esquema × instância

| Esquema | Instância |
|---|---|
| **Estrutura** do BD (muda pouco) | **Dados** num determinado instante (mudam o tempo todo) |
| Como a declaração de variáveis em um programa | Como o valor das variáveis num momento |
| `DESCRIBE Pacientes;` | `SELECT * FROM Pacientes;` |

### 4.3 Independência de dados

Capacidade de mudar o esquema de um nível **sem afetar o nível de cima**.

| Tipo | Muda o quê | Sem reescrever | Exemplo | Dificuldade |
|---|---|---|---|---|
| **Física** | Esquema físico/interno | Programas (nem esquema conceitual) | Criar índice, reorganizar arquivos para desempenho | Mais fácil |
| **Lógica** | Esquema lógico/conceitual | Programas e visões | Acrescentar uma coluna em Cliente; mudança do sistema monetário | **Mais difícil** |

> [!important] Por que a lógica é mais difícil?
> Porque os programas dependem muito mais da **estrutura lógica** (nomes de tabelas e colunas) do que da forma de armazenamento.

```sql
-- Independência FÍSICA na prática: criar um índice não muda nenhuma consulta
CREATE INDEX idx_pac_cidade ON Pacientes (cidade);
SELECT nome FROM Pacientes WHERE cidade = 'Joinville';  -- igual a antes, só mais rápido
DROP INDEX idx_pac_cidade ON Pacientes;
```

### Revisão rápida

1. Em qual nível fica uma visão? E um índice?
2. Esquema ou instância: "a tabela Pacientes tem 4 linhas hoje"?
3. Por que a independência lógica é mais difícil de alcançar?

---

## 5. Modelos de dados, linguagens, papéis e estrutura do SGBD

*(Fonte: BD_AULA02_CONCEITOS.pdf)*

### 5.1 Modelos lógicos de dados

**Modelo de dados** = conjunto de conceitos para descrever a estrutura de um BD (tipos, relacionamentos, restrições).

| Grupo | Ideia | Exemplos |
|---|---|---|
| Baseados em **objetos** | Código executável faz parte do modelo | Orientado a objetos |
| Baseados em **registros** | Registros de formato fixo + linguagem de consulta | Redes, Hierárquico, Relacional |

| Modelo | Quando | Como relaciona os dados |
|---|---|---|
| **Redes** (CODASYL / DBTG) | 1964 (relatório 1971) | Registros ligados por *sets* (ponteiros); problema de acesso aos "filhos" |
| **Hierárquico** | 1965-66 | Árvore: registros "pai" e "filho" explícitos |
| **Relacional** | Codd, **1970** (comercial nos anos 80) | **Tabelas**; relacionamentos por **valores** de dados |

> [!note] Nota
> Redes e Hierárquico são **fortemente influenciados pelo armazenamento físico**. A grande virada do Relacional é ligar tabelas por valores (ex.: `codm` na tabela Consultas), não por ponteiros. Desvantagem citada: representação pouco natural de objetos complexos.

### 5.2 Linguagens: DDL × DML

| | DDL | DML |
|---|---|---|
| Nome | *Data Definition Language* | *Data Manipulation Language* |
| Atua sobre | **Esquema** (estrutura) | **Dados** |
| Guarda em | Dicionário de dados | Tabelas |
| Comandos SQL | `CREATE`, `ALTER`, `DROP` | `SELECT`, `INSERT`, `UPDATE`, `DELETE` |

DML de alto nível (SQL): **não procedural, declarativa, orientada a conjuntos**: você diz **o que** quer, não **como** buscar. O SQL contempla DDL e DML (detalhes na seção 13).

Esquema na forma textual (usado nos slides):

```text
Medico   (Cod_med, Nome_med, Especialidade)
Paciente (Cod_pac, Nome_pac)
Consulta (Cod_med, Cod_pac, Dia, Hora)
```

### 5.3 Papéis humanos

| Papel | Atuação |
|---|---|
| Programador de aplicação | Desenvolve programas que usam o BD |
| Usuário sofisticado | Usa o BD direto com linguagem de consulta (SQL) |
| Usuário "ingênuo" | Usa só pelas telas dos aplicativos |
| Administrador de dados | Define e atualiza o esquema |
| **DBA** (Administrador do SGBD) | Armazenamento e acesso, permissões, integridade, backup, desempenho |

### 5.4 Como o SGBD atende uma solicitação

1. O usuário emite a solicitação.
2. O SGBD intercepta e analisa.
3. Inspeciona os esquemas externos, os mapeamentos entre os 3 níveis e a estrutura de armazenamento.
4. Executa a operação no BD.

Componentes da estrutura: processador de consultas, pré-compilador DML, compilador DDL, gerenciador do banco, gerenciador de arquivos, **dicionário de dados**.

### 5.5 Classificação de SGBDs

| Critério | Classificação |
|---|---|
| Modelo de dados | Rede · Hierárquico · Relacional |
| Nº de usuários | Monousuário · Multiusuário |
| Localização | Centralizado · Distribuído (SGBDD): homogêneo ou heterogêneo (BD federados) |

### Revisão rápida

1. Quem propôs o modelo relacional e quando?
2. `ALTER TABLE` é DDL ou DML? E `UPDATE`?
3. Qual a diferença entre usuário sofisticado e ingênuo?

---

## 6. Arquiteturas, BD na web, SGBDs e ODBC

*(Fonte: BD_AULA03_FundamentosII.pdf)*

### 6.1 Evolução das arquiteturas

| Arquitetura | Como funciona |
|---|---|
| **Centralizada** (mainframe) | Tudo (aplicação, interface, SGBD) roda no mainframe; usuários em terminais "burros" |
| **Cliente-servidor** | SGBD no servidor (**back-end**) executa consultas e transações; cliente (**front-end**) formula consultas e roda aplicativos |
| Ponto a ponto (P2P) | Máquinas são cliente e servidor ao mesmo tempo |
| Distribuída / remota | Vários servidores ligados por rede (VPN, links, satélite...) |

> [!tip] Dica
> O seu setup é cliente-servidor dentro do mesmo PC: o **MariaDB** é o servidor (porta 3306) e o **DBeaver** é o cliente.

### 6.2 Banco de dados na internet

1. O navegador faz a requisição ao **servidor web** (Apache, IIS).
2. O servidor web repassa a consulta SQL ao **servidor de BD**.
3. Recebe o resultado.
4. **Monta uma página HTML** com o resultado.
5. Devolve a página ao navegador.

É exatamente o papel do PHP na seção 19.

### 6.3 SGBDs e ferramentas citados

| Tipo | Exemplos |
|---|---|
| Desktop / antigos | dBASE, Paradox, DataFlex, FoxPro, Access |
| Corporativos | Oracle, MS-SQL Server, Sybase, DB2, Informix |
| Livres / gratuitos | **MySQL**, **PostgreSQL**, Firebird (de InterBase) |
| Ferramentas de desenvolvimento | Clipper, Joiner, Delphi, C++Builder, Visual Basic |

### 6.4 ODBC (*Open DataBase Connectivity*)

**Drivers** que dão uma **interface uniforme** entre aplicativos e diferentes SGBDs. O aplicativo fala com o gerenciador ODBC, que usa o driver certo para cada banco.

```text
Programa ─► Gerenciador ODBC ─┬─► Driver 1 ─► SGBD 1
                              ├─► Driver 2 ─► SGBD 2
                              └─► Driver N ─► SGBD N
```

> [!note] Nota
> O DBeaver faz algo parecido usando **JDBC** (o "ODBC" do Java): por isso ele pede para baixar o driver do MariaDB na primeira conexão.

### Revisão rápida

1. Na arquitetura cliente-servidor, onde as consultas são executadas?
2. Descreva os 5 passos de uma consulta a BD pela web.
3. Para que serve o ODBC?

---

## 7. Redundância e projeto de BD

*(Fonte: BD_AULA03_FundamentosII.pdf, TEC_BD_MER_e_Modelo_Logico.pdf)*

### 7.1 Redundância de dados

Exemplo da indústria: Vendas, Produção e Compras informatizadas **separadas**, cada uma com seu arquivo de produtos → o mesmo produto em três lugares.

| | Redundância **controlada** | Redundância **não controlada** |
|---|---|---|
| Quem sincroniza | O **software** | O **usuário** |
| Para quê | Confiabilidade/desempenho (ex.: sistema distribuído) | Ninguém quer; é efeito colateral |
| Risco | Baixo | **Inconsistência de dados** |

**Solução:** compartilhamento de dados: cada informação guardada **uma vez** e acessada por todos os sistemas → isso é um **banco de dados**, gerido por um **SGBD**.

### 7.2 Modelo de dados e níveis do projeto

- **Modelo de dados** = descrição formal da **estrutura** de um BD (diz que há "produtos com código, preço e descrição", não **quais** produtos).
- **Esquema** = a representação do modelo em uma linguagem de modelagem (textual ou gráfica).
- **Abordagem de modelagem** = conjunto de conceitos usados (ex.: Entidade-Relacionamento).

| Modelo | Depende do SGBD? | Para quem | Forma |
|---|---|---|---|
| **Conceitual** | Não | Cliente (validar requisitos) | DER (diagrama ER) |
| **Lógico** | Sim (tipo de SGBD, ex.: relacional) | Equipe técnica | Tabelas e colunas |
| **Físico** | Sim (SGBD específico) | DBA | Scripts SQL, índices, armazenamento (*tuning*) |

### 7.3 Passos de um projeto de BD

1. **Levantamento de requisitos**: entrevistas, documentação ("o que o sistema precisa guardar?").
2. **Modelo conceitual**: MER/DER (seção 8).
3. **Modelo lógico**: abordagem relacional (seções 10 e 11).
4. **Modelo físico**: criar no SGBD (seção 13).

Exemplo dos slides (indústria):

```text
Conceitual:  [Produto] (n) ──◇── (1) [Tipo de Produto]
Lógico:      TipoDeProduto (CodTipoProd, DescrTipoProd)
             Produto (CodProd, DescrProd, PrecoProd, CodTipoProd)
                 CodTipoProd referencia TipoDeProduto
```

```sql
-- Físico (MariaDB): banco separado para os exemplos de modelagem
CREATE DATABASE IF NOT EXISTS bdModelagem;
USE bdModelagem;

CREATE TABLE TipoDeProduto (
  CodTipoProd   INT PRIMARY KEY,
  DescrTipoProd VARCHAR(40) NOT NULL
);

CREATE TABLE Produto (
  CodProd     INT PRIMARY KEY,
  DescrProd   VARCHAR(60) NOT NULL,
  PrecoProd   DECIMAL(10,2),
  CodTipoProd INT NOT NULL,
  FOREIGN KEY (CodTipoProd) REFERENCES TipoDeProduto (CodTipoProd)
);

INSERT INTO TipoDeProduto VALUES (1, 'Computador'), (2, 'Impressora');
INSERT INTO Produto VALUES
  (1, 'PC desktop modelo X',          2500.00, 1),
  (2, 'PC notebook ABC',              3500.00, 1),
  (3, 'Impressora jato de tinta XXX',  500.00, 2),
  (4, 'Impressora laser XX',          1500.00, 2);
```

### Revisão rápida

1. Diferencie redundância controlada e não controlada.
2. Qual modelo é independente de SGBD?
3. Coloque em ordem: físico, requisitos, lógico, conceitual.

---

## 8. Modelo Entidade-Relacionamento (MER/DER)

*(Fonte: TEC_BD_MER_e_Modelo_Logico.pdf, BD_AULA03_FundamentosII.pdf)*

### 8.1 O que é o MER

- Modelo **conceitual**, de **alto nível**: **não tem ligação nenhuma com SGBD**.
- Mostra o que foi levantado nos requisitos; preocupa-se com os dados, não com tabelas.
- Precisa ser **fácil de entender**: o objetivo principal é **validar os requisitos com o cliente**.
- Representado graficamente pelo **DER** (Diagrama Entidade-Relacionamento).

### 8.2 Os 3 elementos principais

| Elemento | Símbolo no DER | Exemplo (clínica) |
|---|---|---|
| **Entidade** | Retângulo | MÉDICO, PACIENTE, CONSULTA, EXAME |
| **Atributo** | Bolinha ligada à entidade (preenchida = identificador) | CRM ●, NOME ○, ENDEREÇO ○ |
| **Relacionamento** | Losango ◇ | Médico ◇ Consulta ◇ Paciente |

Requisitos do exemplo CLÍNICA (slides):

- **Médico**: CRM (único), nome, endereço, telefone, especialidade
- **Paciente**: CPF (único), nome, endereço, telefone
- **Consulta**: código, data, observações; feita por **um** médico para **um** paciente
- **Exame** (passado na consulta): código, nome, resultado

### 8.3 Tipos de entidade, atributo e relacionamento

> [!note] Nota
> Os slides mostram estes tipos só em figuras. As definições abaixo são as usuais da literatura (Heuser, *Projeto de Banco de Dados*). **Conferir com a explicação da professora.**

| Tipo | Significado | Exemplo |
|---|---|---|
| Entidade **simples** (forte) | Existe por si só, tem identificador próprio | Médico |
| Entidade **fraca** | Só existe ligada a outra; identificador depende dela | Transação de uma Conta |
| Entidade **associativa** | Um relacionamento tratado como entidade (para se relacionar com outra) | Consulta, que se liga a Exame |
| Atributo **chave** (identificador) | Identifica cada ocorrência | CRM, CPF |
| Atributo **simples** | Valor único e indivisível | Nome |
| Atributo **composto** | Dividido em partes | Endereço = rua + número + cidade |
| Atributo **multivalorado** | Vários valores para a mesma ocorrência | Telefones |
| Relacionamento **binário** | Entre duas entidades | Departamento ◇ Empregado |
| **Autorrelacionamento** | Entidade com ela mesma | Funcionário *supervisiona* Funcionário |
| **Generalização / especialização** | Entidade "mãe" com subtipos | Pessoa → Física / Jurídica |

### Revisão rápida

1. Para quem o MER é feito, principalmente?
2. Qual a diferença entre entidade fraca e associativa?
3. Telefone (com vários números) é atributo de que tipo?

---

## 9. Cardinalidade

*(Fonte: TEC_BD_MER_e_Modelo_Logico.pdf + imagens de exercícios enviadas)*

### 9.1 Mínima e máxima

Cardinalidade = **quantas** ocorrências de uma entidade se associam a uma ocorrência da outra. Escrita como **(mínima, máxima)**:

| Notação | Leitura |
|---|---|
| `(0,1)` | Opcional, no máximo um |
| `(1,1)` | Obrigatório, exatamente um |
| `(0,n)` | Opcional, vários |
| `(1,n)` | Obrigatório, pelo menos um |

- **Mínima** 0 = participação **opcional**; 1 = **obrigatória**.
- **Máxima** define o **tipo**: 1:1, 1:N (ou N:1), N:N.

### 9.2 Como ler o diagrama

A cardinalidade fica **do lado da entidade que está sendo contada**. Leia "atravessando" o losango:

```text
[Equipe] (1,1) ──◇ compõe ◇── (1,n) [Jogadores]

→ Uma equipe é composta por (1,n) jogadores   (olhe o número do lado de Jogadores)
→ Um jogador compõe (1,1) equipe              (olhe o número do lado de Equipe)
→ Tipo: 1:N
```

### 9.3 Exercício das imagens (tente antes de abrir o gabarito)

Para cada um, diga: o tipo (1:1, 1:N, N:N) e uma frase de leitura em cada sentido.

1. Aluno (1,n) ◇ Realiza ◇ (1,n) Trabalho
2. Diretor (1,1) ◇ Dirige ◇ (1,1) Departamento
3. Autor (1,n) ◇ escreve ◇ (1,n) Livros
4. Equipe (1,1) ◇ compõe ◇ (1,n) Jogadores
5. Cliente (1,1) ◇ realiza ◇ (1,n) Encomenda

> [!success]- Ver gabarito
> | # | Tipo | Leitura |
> |---|---|---|
> | 1 | **N:N** | Um aluno realiza 1 ou mais trabalhos; um trabalho é feito por 1 ou mais alunos |
> | 2 | **1:1** | Um diretor dirige exatamente 1 departamento; um departamento tem exatamente 1 diretor |
> | 3 | **N:N** | Um autor escreve 1 ou mais livros; um livro tem 1 ou mais autores |
> | 4 | **1:N** | Uma equipe tem 1 ou mais jogadores; um jogador está em exatamente 1 equipe |
> | 5 | **1:N** | Um cliente faz 1 ou mais encomendas; uma encomenda é de exatamente 1 cliente |

> [!warning] Armadilha
> Ler o número "do lado errado". Em `Cliente (1,1) ... (1,n) Encomenda`, o `(1,1)` **não** quer dizer "um cliente faz uma encomenda". Quer dizer "**cada encomenda** tem **um** cliente".

---

## 10. Abordagem relacional e chaves

*(Fonte: TEC_BD_MER_e_Modelo_Logico.pdf)*

### 10.1 Vocabulário da tabela

Representa os dados como um **conjunto de tabelas**; a **tabela** é o conceito mais forte.

| Termo | Sinônimo | No exemplo |
|---|---|---|
| Tabela | Relação | `Funcionario` |
| Linha | **Tupla**, registro | `01, João, Rua 123, joao@teste.com` |
| Coluna | **Atributo**, campo | `NomeFunc` |
| Valor do campo | | `João` |

### 10.2 Chaves

Chaves especificam **restrições de integridade**.

| Chave | Definição (slides) | Exemplo | SQL |
|---|---|---|---|
| **Primária (PK)** | Atributo(s) que identificam **unicamente** uma tupla na tabela | `CodFunc` | `PRIMARY KEY` |
| **Estrangeira (FK)** | Atributo(s) que relacionam tabelas; seus valores **aparecem necessariamente na PK de outra tabela** | `CodDep` em Funcionário | `FOREIGN KEY ... REFERENCES` |
| **Alternativa / candidata** | Outro atributo que também identificaria a linha, mas não foi escolhido como PK | `CPFFunc` | `UNIQUE` |

```sql
CREATE DATABASE IF NOT EXISTS bdModelagem;
USE bdModelagem;

CREATE TABLE Departamento (
  CodDep    CHAR(2)     PRIMARY KEY,          -- chave primária
  Descricao VARCHAR(30) NOT NULL
);

CREATE TABLE Funcionario (
  CodFunc  INT         PRIMARY KEY,
  NomeFunc VARCHAR(40) NOT NULL,
  CPFFunc  CHAR(14)    UNIQUE,                -- chave alternativa/candidata
  CodDep   CHAR(2),
  FOREIGN KEY (CodDep) REFERENCES Departamento (CodDep)   -- chave estrangeira
);

INSERT INTO Departamento VALUES ('D1','Vendas'), ('D2','Compras'), ('D3','Manutenção');
INSERT INTO Funcionario VALUES
  (1, 'João',  '123.456.789-00', 'D1'),
  (2, 'Pedro', '123.456.789-01', 'D3');

-- Teste a integridade: as duas linhas abaixo DEVEM dar erro
INSERT INTO Funcionario VALUES (3, 'Maria', '123.456.789-02', 'D9');  -- D9 não existe (FK)
INSERT INTO Funcionario VALUES (4, 'José',  '123.456.789-00', 'D2');  -- CPF repetido (UNIQUE)
```

> [!note] Nota
> Erros esperados: `ERROR 1452 ... a foreign key constraint fails` (FK) e `ERROR 1062 Duplicate entry` (UNIQUE). Ver o erro acontecer é a melhor forma de entender a restrição.

### Revisão rápida

1. Tupla é linha ou coluna?
2. Uma FK pode ter um valor que não existe na PK da outra tabela?
3. Por que o CPF é chave candidata e não primária no exemplo?

---

## 11. Do MER às tabelas (modelo lógico)

*(Fonte: TEC_BD_MER_e_Modelo_Logico.pdf)*

### 11.1 Objetivos e passos da transformação

Objetivos: melhorar desempenho, **evitar junções**, diminuir o número de chaves, **evitar campos opcionais** (nulos), simplificar o software.

| Passo | O que faz |
|---|---|
| 1 | Traduzir **entidades** e atributos |
| 2 | Traduzir **relacionamentos** e seus atributos |
| 3 | Traduzir **generalização/especialização** *(só citado nos slides)* |

### 11.2 Passo 1: entidades

- Cada **entidade** vira uma **tabela**.
- Cada **atributo** vira uma **coluna**.
- O **identificador** vira a **chave primária**.

```text
PESSOA (Código, Nome, Endereço, Data de nascimento, Data de admissão)
→ Pessoa (CodPessoa, Nome, Endereço, DataNasc, DataAdm)
```

Dicas de nomenclatura: nomes **curtos**, **sem espaços**, e colunas que se repetem em outras tabelas ganham o nome da tabela como sufixo (`NomePessoa`, `CodPessoa`).

### 11.3 Passo 2: as 3 estratégias para relacionamentos

| Estratégia | O que faz | Exemplo |
|---|---|---|
| **Tabela própria** | O relacionamento vira uma tabela com as PKs das duas entidades | `Atuacao (CodEng, CodProj, Funcao)` |
| **Adição de coluna** | A PK de um lado vira FK (coluna) na tabela do outro lado | `Empregado (..., CodDept, DataLota)` |
| **Fusão de tabelas** | As duas entidades viram uma tabela só | `Conferencia (CodConf, Nome, DtInstOrg, EnderComOrg)` |

### 11.4 Qual estratégia usar? (tabela dos slides)

✓ = preferida · 2ª/3ª = alternativas · ✗ = não usar

| Relacionamento | Tabela própria | Adição de coluna | Fusão de tabelas |
|---|---|---|---|
| 1:1 `(0,1)` `(0,1)` | 2ª opção | **✓** | ✗ |
| 1:1 `(0,1)` `(1,1)` | 3ª opção | 2ª opção | **✓** |
| 1:1 `(1,1)` `(1,1)` | 3ª opção | 2ª opção | **✓** |
| 1:N `(0,1)` `(_,n)` | 2ª opção | **✓** | ✗ |
| 1:N `(1,1)` `(_,n)` | ✗ | **✓** | ✗ |
| N:N `(_,n)` `(_,n)` | **✓** | ✗ | ✗ |

> [!important] Regra de bolso
> **N:N → sempre tabela própria.** **1:N → adição de coluna** (a FK vai para o lado **N**). **1:1 → fusão** quando os dois lados são obrigatórios; **adição de coluna** quando são opcionais.

### 11.5 Exemplos em SQL

```sql
USE bdModelagem;

-- N:N  ENGENHEIRO (0,n) ATUAÇÃO (0,n) PROJETO  → tabela própria
CREATE TABLE Engenheiro (CodEng  INT PRIMARY KEY, Nome   VARCHAR(40));
CREATE TABLE Projeto    (CodProj INT PRIMARY KEY, Titulo VARCHAR(60));
CREATE TABLE Atuacao (
  CodEng  INT,
  CodProj INT,
  Funcao  VARCHAR(30),                     -- atributo do relacionamento
  PRIMARY KEY (CodEng, CodProj),           -- PK composta pelas duas FKs
  FOREIGN KEY (CodEng)  REFERENCES Engenheiro (CodEng),
  FOREIGN KEY (CodProj) REFERENCES Projeto (CodProj)
);

-- 1:N  DEPARTAMENTO (1,1) LOTAÇÃO (1,n) EMPREGADO  → adição de coluna no lado N
CREATE TABLE Departamento2 (CodDept INT PRIMARY KEY, Nome VARCHAR(40));
CREATE TABLE Empregado (
  CodEmp   INT PRIMARY KEY,
  Nome     VARCHAR(40),
  CodDept  INT NOT NULL,                   -- (1,1): todo empregado tem departamento
  DataLota DATE,                           -- atributo do relacionamento vem junto
  FOREIGN KEY (CodDept) REFERENCES Departamento2 (CodDept)
);

-- 1:1  CONFERÊNCIA (1,1) ORGANIZAÇÃO (1,1) COMISSÃO  → fusão de tabelas
CREATE TABLE Conferencia (
  CodConf        INT PRIMARY KEY,
  Nome           VARCHAR(60),
  DataInstComOrg DATE,                     -- dados da comissão "fundidos" aqui
  EnderComOrg    VARCHAR(80)
);

-- Entidade FRACA: Transação só existe dentro de uma Conta
CREATE TABLE Conta (NumConta INT PRIMARY KEY, Saldo DECIMAL(12,2));
CREATE TABLE Transacao (
  NumConta     INT,
  NumTransacao INT,
  data         DATE,
  quantia      DECIMAL(12,2),
  PRIMARY KEY (NumConta, NumTransacao),    -- PK inclui a PK da entidade "dona"
  FOREIGN KEY (NumConta) REFERENCES Conta (NumConta)
);
```

Mais exemplos dos slides (só no modelo lógico):

```text
1:1 (0,1)(0,1)  HOMEM — CASAMENTO — MULHER
  Adição de coluna: Homem (IdentH, Nome)
                    Mulher (IdentM, Nome, IdentH, Data, Regime)   IdentH referencia Homem
  Tabela própria:   Casamento (IdentM, IdentH, Data, Regime)

1:1 (1,1)(0,1)  CORRENTISTA — POSSUI — CARTÃO MAGNÉTICO
  Fusão:            Correntista (CodCorrent, Nome, CodCartão, DataExp)
  Adição de coluna: Cartão (CodCartão, DataExp, CodCorrent)       CodCorrent referencia Correntista

1:N (0,1)(_,n)  FINANCEIRA — FINANCIAM — VENDA
  Adição de coluna: Venda (IdVend, Data, CodFin, NoParc, TxJuros) CodFin referencia Financeira
  Tabela própria:   Financiam (IdVend, CodFin, NoParc, TxJuros)
```

### Revisão rápida

1. Num relacionamento 1:N, a FK vai para qual lado?
2. Por que N:N não pode ser resolvido com adição de coluna?
3. Onde ficam os atributos do relacionamento (ex.: `Funcao`, `DataLota`)?

---

## 12. Normalização (1FN, 2FN, 3FN)

*(Fonte: BD_AULA03B_NORMALIZACAO.pdf)*

### 12.1 O que é e por quê

- Técnica para **racionalizar** as estruturas de dados, **eliminando redundâncias** e problemas de manipulação e armazenamento.
- Decompõe tabelas "ruins" em tabelas **menores** que satisfazem as propriedades do modelo relacional.
- Na prática virou uma **ferramenta de verificação** do projeto.
- **Relação desnormalizada** = tabela que ainda não atende às formas normais.

Medidas de qualidade:

1. **Representação semântica correta** (cada dado com significado claro)
2. **Redução de valores redundantes**
3. **Redução de valores nulos**
4. **Não gerar tuplas espúrias** (linhas sem sentido criadas por uma decomposição errada)

Propriedades de uma boa decomposição: **junção sem perda** (juntar de volta não perde nem inventa dados) e **preservação de dependências**.

### 12.2 Dependência funcional (DF)

**X → Y** ("X determina Y"): se duas linhas têm o mesmo X, **obrigatoriamente** têm o mesmo Y.

```text
Matrícula → Nome, Endereço, Telefone, CodCurso
(sabendo a matrícula, sei o nome, o endereço...)
```

- É uma propriedade da **semântica** (do significado), definida por quem conhece o negócio.
- **Não dá para deduzir** uma DF só olhando o conteúdo da tabela; mas dá para provar que ela **não existe** (um contraexemplo basta).

| Tipo de DF | Definição | Exemplo |
|---|---|---|
| **Total / completa** | Y depende da chave **inteira** | `(Produto, Almox) → Qtd` |
| **Parcial** | Y depende de **parte** de uma chave composta | `Almox → End_Almox` |
| **Transitiva** | X → Z e Z → Y, com Z não chave | `Código → Gênero → País_Origem` |

### 12.3 As três formas normais

| FN | Teste | Solução |
|---|---|---|
| **1FN** | Todos os atributos **atômicos e monovalorados** (sem compostos, multivalorados ou grupos repetidos) | Separar em colunas atômicas; criar nova tabela para o grupo repetido |
| **2FN** | Está na 1FN **e** nenhum atributo não chave depende de **parte** da PK composta | Nova tabela para cada parte da chave com os atributos que dependem dela |
| **3FN** | Está na 2FN **e** nenhum atributo não chave depende de outro atributo **não chave** (sem DF transitiva) | Nova tabela com o atributo determinante e os que ele determina |

> [!important] Atalho de prova
> 2FN só pode ser violada quando a **PK é composta**. Se a PK tem uma coluna só e a tabela está na 1FN, ela já está na 2FN.

### 12.4 Exemplos dos slides

**1FN: atributo composto**

```text
ESTUDANTES = {Matrícula, Nome, Endereço(Rua, Número, Bairro, Cidade, UF), CodCurso}
→ ESTUDANTES = {Matrícula, Nome, Rua, Número, Bairro, Cidade, UF, CodCurso}
```

**1FN: grupo repetido**

```text
FUNCIONÁRIOS = {CodFunc, Nome, Cargo, {Projeto, DataIni, DataFim}}
→ FUNCIONÁRIOS = {CodFunc, Nome, Cargo}
→ FUNC_PROJ    = {CodFunc, Projeto, DataIni, DataFim}
```

**2FN: dependência parcial** (PK = Produto + Almox)

```text
ESTOQUE = {Produto, Almox, End_Almox, Unid_Est, Qtd, Preco}
  Almox   → End_Almox   (parcial)
  Produto → Unid_Est    (parcial)
```

```text
Decomposição (nomes como faz sentido pelas DFs):
  Produto      = {Produto, Unid_Est}
  Almoxarifado = {Almox, End_Almox}
  Estoque      = {Produto, Almox, Qtd, Preco}
```

> [!warning] Atenção
> No slide, os nomes estão trocados (`Estoque = {PRODUTO + UNID_EST}` e `Produto = {PRODUTO + ALMOX + QTD + PRECO}`). A **estrutura** está certa; só o nome das tabelas parece invertido. **Confirmar com a professora.**

**3FN: dependência transitiva**

```text
MÚSICA = {Código, Título, Gênero, País_Origem}   (o país é do GÊNERO, não da música)
  Código → Gênero → País_Origem
→ MÚS_1 = {Código, Título, Gênero}
→ MÚS_2 = {Gênero, País_Origem}
```

Também é 3FN eliminar **campos calculáveis**: com `Cli_Nascimento` não precisa de `Cli_Idade`.

### 12.5 Passo a passo no exemplo Funcionário / Recados / Escritório

| Etapa | Problema | Correção |
|---|---|---|
| Original | Colunas `Recado1`, `Recado2`... (e o terceiro recado?) | |
| **1FN** | Grupo repetido | Uma linha por recado, chave por registro; mas agora nome e endereço do escritório se repetem |
| **2FN** | Recados e escritório não dependem só do funcionário | Tabela `Recados` (FK `Fun_ID`) e tabela `Escritorios` (FK `Fun_Esc_ID`): o escritório existe mesmo sem funcionário |
| **3FN** | Atributos transitivos / calculáveis | Remover (ex.: idade derivada do nascimento) |

```sql
USE bdModelagem;

CREATE TABLE Escritorios (
  Esc_ID       INT PRIMARY KEY,
  Esc_Endereco VARCHAR(80) NOT NULL
);

CREATE TABLE Funcionarios (
  Fun_ID     INT PRIMARY KEY,
  Fun_Nome   VARCHAR(40) NOT NULL,
  Fun_Esc_ID INT,
  FOREIGN KEY (Fun_Esc_ID) REFERENCES Escritorios (Esc_ID)
);

CREATE TABLE Recados (
  Rec_ID     INT AUTO_INCREMENT PRIMARY KEY,   -- AUTO_INCREMENT: o MariaDB gera o número
  Rec_Fun_ID INT NOT NULL,
  Rec_Texto  VARCHAR(200) NOT NULL,
  FOREIGN KEY (Rec_Fun_ID) REFERENCES Funcionarios (Fun_ID)
);

INSERT INTO Escritorios  VALUES (1, 'Rua Manga, 10');
INSERT INTO Funcionarios VALUES (1, 'Ana', 1), (2, 'Beto', 1);
INSERT INTO Recados (Rec_Fun_ID, Rec_Texto) VALUES
  (1, 'Ligar para o fornecedor'), (1, 'Reunião às 14h'), (1, 'Enviar relatório');

-- Juntando de volta (junção sem perda): quantos recados quiser, sem colunas novas
SELECT f.Fun_Nome, e.Esc_Endereco, r.Rec_Texto
FROM Funcionarios f
JOIN Escritorios e ON e.Esc_ID = f.Fun_Esc_ID
JOIN Recados r     ON r.Rec_Fun_ID = f.Fun_ID;
```

> [!tip] Dica
> Para limpar os exemplos de modelagem: `DROP DATABASE bdModelagem;`

### Revisão rápida (questionário dos slides)

1. O que é uma dependência funcional?
2. Quem especifica as DFs válidas entre os atributos de um esquema?
3. A que se refere a expressão "relação desnormalizada"?
4. Defina 1FN, 2FN e 3FN considerando só chaves primárias.
5. **Exercício prático:** normalize a locadora (enunciado na seção 22).

---

## 13. SQL: visão geral e DDL

*(Fonte: SQL_Introducao01.pdf, SQL_INCLUSAO_POPULACAO.pdf, SQL_DDL_DML.pdf, SQL2026.pptx)*

### 13.1 O que é SQL

- *Structured Query Language*: linguagem comercial para BD **relacional**.
- Padrão ISO desde os anos 80: **SQL-1 (86), SQL-2 (92), SQL-3 (99)**.
- Base formal: **álgebra relacional** e **cálculo relacional**.
- **Não é só consulta**: define dados, visões, permissões, restrições de integridade, transações e pode ser embutida em linguagens de programação.

### 13.2 As quatro sublinguagens

| Sigla | Nome | Para quê | Comandos |
|---|---|---|---|
| **DDL** | *Data Definition Language* | Criar/alterar a **estrutura** | `CREATE`, `ALTER`, `DROP` |
| **DML** | *Data Manipulation Language* | Consultar e mudar os **dados** | `SELECT`, `INSERT`, `UPDATE`, `DELETE` |
| **DCL** | *Data Control Language* | **Permissões** | `GRANT`, `REVOKE` |
| **TCL** | *Transaction Control Language* | **Transações** | `COMMIT`, `ROLLBACK` |

Ambiente SQL: **catálogo** = conjunto de esquemas; **esquema** = objetos de um usuário (tabelas, visões, restrições). No MariaDB, "esquema" e "banco" (*database*) são a mesma coisa.

### 13.3 Banco de dados

O SQL **padrão** não tem comando para criar banco; MySQL/MariaDB, SQL Server e DB2 têm.

```sql
CREATE DATABASE bdDDL;          -- cria
SHOW DATABASES;                 -- lista
USE bdDDL;                      -- passa a usar
-- DROP DATABASE bdDDL;         -- apaga TUDO (deixei comentado de propósito)
```

### 13.4 `CREATE TABLE`

```text
CREATE TABLE nome_tabela (
  nome_atributo_1 tipo_1 [[NOT] NULL] [UNIQUE]
  [{, nome_atributo_n tipo_n}]
  [, PRIMARY KEY (nome(s)_atributo(s))]
  [{, FOREIGN KEY (nome_atributo) REFERENCES nome_tabela (atributo)}]
)
```

> [!note] Nota
> Como ler a sintaxe: `[ ]` = opcional · `{ }` = pode repetir · `|` = escolha uma opção.

Tipos de dados citados (e equivalentes no MariaDB):

| Tipo | Guarda | Exemplo | Observação |
|---|---|---|---|
| `INTEGER` / `INT` | Inteiro | `codm INT` | São sinônimos |
| `SMALLINT` | Inteiro pequeno (−32768 a 32767) | `idade SMALLINT` | |
| `NUMERIC(t, d)` | Número exato: `t` dígitos, `d` decimais | `NUMERIC(10,2)` → 99999999.99 | Sinônimo de `DECIMAL`; use para dinheiro |
| `CHAR(n)` | Texto de tamanho **fixo** | `CHAR(2)` para UF | Completa com espaços |
| `VARCHAR(n)` | Texto de tamanho **variável** até `n` | `VARCHAR(40)` | Mais comum |
| `DATE` | Data | `'2026-06-12'` | Formato **'AAAA-MM-DD'** |
| `TIME` | Hora | `'14:00'` | |
| `DATETIME` | Data e hora | `'2026-06-12 14:00:00'` | |

Restrições na coluna:

| Restrição | Significa |
|---|---|
| `NOT NULL` | Obrigatório preencher |
| `UNIQUE` | Não pode repetir (chave candidata) |
| `PRIMARY KEY` | Identifica a linha: única **e** não nula |
| `FOREIGN KEY ... REFERENCES` | O valor tem que existir na outra tabela |

```sql
USE bdDDL;

CREATE TABLE Ambulatorios (
  nroa        INTEGER,
  andar       NUMERIC(3) NOT NULL,
  capacidade  SMALLINT,
  PRIMARY KEY (nroa)
);

CREATE TABLE Medicos (
  codm           INTEGER,
  nome           VARCHAR(40) NOT NULL,
  idade          SMALLINT    NOT NULL,
  especialidade  CHAR(20),
  CPF            NUMERIC(11) UNIQUE,
  cidade         VARCHAR(30),
  nroa           INTEGER,
  PRIMARY KEY (codm),
  FOREIGN KEY (nroa) REFERENCES Ambulatorios (nroa)
);
```

### 13.5 `ALTER TABLE`

```text
ALTER TABLE nome_tabela
    ADD [COLUMN] atributo tipo [RIs]
  | MODIFY [COLUMN] atributo tipo [RIs]
  | DROP COLUMN atributo
  | ADD CONSTRAINT nome_RI definição
  | DROP CONSTRAINT nome_RI
  | [ADD | DROP] [PRIMARY KEY ... | FOREIGN KEY ...]
```

(RI = restrição de integridade; "I / E / A" nos slides = Incluir / Excluir / Alterar.)

```sql
USE bdDDL;

ALTER TABLE Ambulatorios ADD nome VARCHAR(30);            -- incluir coluna
ALTER TABLE Ambulatorios MODIFY nome VARCHAR(50);         -- alterar tipo/tamanho
ALTER TABLE Ambulatorios DROP COLUMN nome;                -- excluir coluna

CREATE TABLE Funcionarios (codf INT PRIMARY KEY, nome VARCHAR(40), nroa INT);

-- FK com nome escolhido (facilita remover depois)
ALTER TABLE Funcionarios
  ADD CONSTRAINT fk_nroa FOREIGN KEY (nroa) REFERENCES Ambulatorios (nroa);

ALTER TABLE Funcionarios DROP FOREIGN KEY fk_nroa;        -- jeito MariaDB/MySQL
ALTER TABLE Funcionarios DROP COLUMN nroa;

SHOW CREATE TABLE Funcionarios;                           -- confere o resultado
```

> [!warning] `DROP PRIMARY KEY` em tabela referenciada falha
> `ALTER TABLE Ambulatorios DROP PRIMARY KEY` dá erro enquanto `Medicos` tiver FK apontando para ela: primeiro remova a FK.

> [!tip] Dica
> Se você não der nome à FK, o MariaDB cria um automático (`Medicos_ibfk_1`). Descubra com `SHOW CREATE TABLE Medicos;`.

### 13.6 Índices

- Estruturas que **aceleram consultas** (como o índice remissivo de um livro).
- São criados **automaticamente** para PK (e para `UNIQUE` e FK no MariaDB).
- Custo: ocupam espaço e deixam `INSERT`/`UPDATE` um pouco mais lentos.

```sql
USE bdDDL;
CREATE UNIQUE INDEX indMed_CPF ON Medicos (CPF);   -- índice único
CREATE INDEX indMed_esp ON Medicos (especialidade); -- índice comum
SHOW INDEX FROM Medicos;
DROP INDEX indMed_esp ON Medicos;
```

### 13.7 `DELETE` × `TRUNCATE` × `DROP`

| Comando | Tipo | Apaga | Estrutura fica? | `WHERE`? | Desfaz com `ROLLBACK`? |
|---|---|---|---|---|---|
| `DELETE FROM t` | DML | Linhas (todas ou filtradas) | Sim | **Sim** | Sim (dentro de transação) |
| `TRUNCATE TABLE t` | DDL | **Todas** as linhas | Sim | Não | **Não** |
| `DROP TABLE t` | DDL | Linhas **e** a tabela | **Não** | Não | **Não** |

### 13.8 DCL e TCL na prática

```sql
-- DCL (rodar como root: sudo mariadb). Exemplo de usuário só-leitura:
-- CREATE USER 'leitor'@'localhost' IDENTIFIED BY 'outraSenha!';
-- GRANT SELECT ON bdClinica.* TO 'leitor'@'localhost';
-- REVOKE SELECT ON bdClinica.* FROM 'leitor'@'localhost';

-- TCL: a rede de segurança para treinar UPDATE/DELETE
USE bdClinica;
START TRANSACTION;                 -- começa a transação
DELETE FROM Consultas;             -- "ops", apaguei tudo
SELECT COUNT(*) FROM Consultas;    -- 0
ROLLBACK;                          -- desfaz
SELECT COUNT(*) FROM Consultas;    -- 11 de novo
```

> [!important] Transações e as regras do SGBD
> Isso é a **regra 5 (Transações)** da seção 3: desfazer várias alterações com uma instrução. `COMMIT` confirma; `ROLLBACK` desfaz. Comandos DDL (`CREATE`, `DROP`, `TRUNCATE`) **confirmam automaticamente** e não voltam.

> [!warning] Atenção
> No DBeaver, o padrão é **auto-commit** ligado: cada comando já é confirmado. Para treinar com `ROLLBACK`, escreva o `START TRANSACTION;` antes, ou mude para modo manual no botão de transação da barra de ferramentas.

```sql
DROP DATABASE bdDDL;   -- limpeza do banco de testes desta seção
```

### Revisão rápida

1. `TRUNCATE` é DDL ou DML? Dá para usar `WHERE`?
2. Por que usar `ADD CONSTRAINT fk_nome` em vez de deixar o nome automático?
3. Diferença entre `CHAR(20)` e `VARCHAR(20)`?

---

## 14. DML: inserir, alterar e excluir

*(Fonte: SQL_Introducao01.pdf, SQL_INCLUSAO_POPULACAO.pdf, SQL_DDL_DML.pdf)*

### 14.1 `INSERT`

```text
INSERT INTO nome_tabela [(lista_atributos)]
VALUES (lista_valores) [, (lista_valores)]
```

```sql
USE bdClinica;
START TRANSACTION;   -- para treinar sem estragar o banco

-- a) Todas as colunas, na ordem do CREATE (frágil: depende da ordem)
INSERT INTO Ambulatorios VALUES (6, 3, 20);

-- b) Colunas escolhidas (recomendado): as não citadas ficam NULL
INSERT INTO Medicos (codm, nome, idade, especialidade, CPF, cidade)
VALUES (6, 'Joana', 37, 'traumatologia', 11122233344, 'Florianopolis');

-- c) Várias linhas de uma vez
INSERT INTO Pacientes VALUES
  (5, 'Bruno', 9,  'Ilhota',  12312312312, 'gripe'),
  (6, 'Clara', 61, 'Palhoca', 32132132132, 'fratura');

SELECT * FROM Medicos WHERE codm = 6;   -- nroa aparece NULL
ROLLBACK;
```

```sql
-- d) INSERT ... SELECT: copia resultado de uma consulta para outra tabela
USE bdClinica;
CREATE TABLE MedNovos (codigo INT, nome VARCHAR(40), especialidade CHAR(20));

INSERT INTO MedNovos
  SELECT codm, nome, especialidade
  FROM Medicos
  WHERE idade < 35;              -- slides usam idade < 21 (não retornaria ninguém aqui)

SELECT * FROM MedNovos;          -- Carlos e Marcia
DROP TABLE MedNovos;
```

### 14.2 "Popular" as tabelas: a ordem importa

"Popular" é jargão de mercado: **preencher a tabela com registros**.

> [!warning] A chave estrangeira obriga uma ordem
> Não dá para cadastrar o médico do ambulatório 1 antes do ambulatório 1 existir: o SGBD recusa com **erro de integridade referencial** (`ERROR 1452`). Ordem no `bdClinica`: **Ambulatorios → Pacientes/Funcionarios → Medicos → Consultas**. Para apagar, a ordem é a **inversa**.

Também respeite tipos e `NOT NULL`, e use datas no formato `'AAAA-MM-DD'`.

### 14.3 `UPDATE`

```text
UPDATE nome_tabela
SET atributo_1 = valor [, atributo_n = valor]
[WHERE condição]
```

```sql
USE bdClinica;
START TRANSACTION;

UPDATE Ambulatorios
SET capacidade = capacidade + 5, andar = 3     -- pode usar o valor antigo na conta
WHERE nroa = 2;

SELECT * FROM Ambulatorios WHERE nroa = 2;     -- capacidade 55, andar 3

-- Somar tempo a uma hora: ADDTIME (função do MariaDB)
UPDATE Consultas SET hora = ADDTIME(hora, '00:30:00')
WHERE codm = 1 AND codp = 1;
SELECT * FROM Consultas WHERE codm = 1 AND codp = 1;   -- 14:30:00

ROLLBACK;
```

### 14.4 `DELETE`

```text
DELETE FROM nome_tabela [WHERE condição]
```

```sql
USE bdClinica;
START TRANSACTION;

DELETE FROM Consultas WHERE hora > '19:00';    -- apaga só as consultas após 19h
SELECT COUNT(*) FROM Consultas;                -- 10

ROLLBACK;
```

> [!warning] `UPDATE` e `DELETE` sem `WHERE` afetam TODAS as linhas
> `UPDATE Medicos SET cidade = 'Florianopolis'` (exemplo dos slides) muda a cidade de todos os médicos.

> [!tip] Hábito seguro em 3 passos
> 
> 1. Rode um `SELECT` com o mesmo `WHERE` e confira quais linhas aparecem.
> 2. Troque o `SELECT *` por `UPDATE ... SET` ou `DELETE`, mantendo o `WHERE`.
> 3. Confira com `SELECT` de novo. Em dúvida, use `START TRANSACTION` / `ROLLBACK`.

> [!note] Apagar "pai" com filhos
> `DELETE FROM Medicos WHERE codm = 2` falha (`ERROR 1451`) porque há consultas do médico 2. Apague (ou mova) os filhos antes. Opção avançada, fora dos slides: `FOREIGN KEY ... ON DELETE CASCADE`.

### Revisão rápida

1. Por que é melhor listar as colunas no `INSERT`?
2. O que acontece com `DELETE FROM Ambulatorios;` sem `WHERE` no `bdClinica`? (Dica: FK.)
3. Em que ordem se populam tabelas com FK? E em que ordem se apagam?

---

## 15. SELECT em uma tabela

*(Fonte: SQL2026_SELECT.pdf, SQL2026.pptx, SQL_DDL_DML.pdf)*

### 15.1 Estrutura e ordem das cláusulas

```text
SELECT   colunas / expressões        -- o que mostrar
FROM     tabela(s)                   -- de onde
WHERE    condição nas linhas         -- filtra linhas
GROUP BY colunas                     -- agrupa
HAVING   condição nos grupos         -- filtra grupos
ORDER BY colunas [DESC]              -- ordena
LIMIT    n                           -- quantas linhas
```

> [!important] Ordem em que o SGBD processa
> (diferente da ordem em que você escreve): `FROM → WHERE → GROUP BY → HAVING → SELECT → ORDER BY → LIMIT`. Por isso um alias criado no `SELECT` **não** pode ser usado no `WHERE`, mas pode no `ORDER BY`.

### 15.2 Mapeamento para a álgebra relacional

| Álgebra | Nome | SQL |
|---|---|---|
| **π** a1, a2 (T) | Projeção (escolhe colunas) | `SELECT a1, a2 FROM T` |
| **σ** c (T) | Seleção (escolhe linhas) | `SELECT * FROM T WHERE c` |
| T1 **×** T2 | Produto cartesiano | `FROM T1, T2` |
| T1 **⋈** T2 | Junção | `FROM T1 JOIN T2 ON ...` |
| T1 **∪** T2 | União | `... UNION ...` |

```sql
USE bdClinica;
SELECT * FROM Pacientes;                              -- (Pacientes)
SELECT * FROM Pacientes WHERE idade > 18;             -- σ idade>18 (Pacientes)
SELECT CPF, nome FROM Pacientes;                      -- π CPF,nome (Pacientes)
SELECT CPF, nome FROM Pacientes WHERE idade > 18;     -- π CPF,nome (σ idade>18 (Pacientes))
```

### 15.3 Projeção: `DISTINCT`, alias e cálculos

O `SELECT` **não elimina duplicatas** por padrão (tabela = coleção). Para eliminar, `DISTINCT`.

```sql
USE bdClinica;
SELECT especialidade FROM Medicos;            -- ortopedia aparece 2 vezes
SELECT DISTINCT especialidade FROM Medicos;   -- 4 linhas, sem repetição

-- Valores calculados + alias (AS)
SELECT nroa, capacidade / 5 AS grupos5 FROM Ambulatorios;
SELECT CPF, salario - (salario * 0.1) AS liquido FROM Funcionarios;
```

### 15.4 Funções de agregação

Resumem várias linhas em **um** valor.

| Função | Retorna | Nulos |
|---|---|---|
| `COUNT(*)` | Nº de **linhas** | Conta |
| `COUNT(coluna)` | Nº de valores **não nulos** | **Não conta** |
| `SUM(col)` | Soma | Ignora |
| `AVG(col)` | Média | Ignora |
| `MIN(col)` / `MAX(col)` | Menor / maior | Ignora |

```sql
USE bdClinica;
SELECT COUNT(*) AS TotalOrtopedistas FROM Medicos WHERE especialidade = 'ortopedia';  -- 2
SELECT COUNT(nroa) AS Total FROM Medicos;                  -- médicos com ambulatório
SELECT SUM(capacidade) AS TotalAndar1 FROM Ambulatorios WHERE andar = 1;          -- 80
SELECT AVG(idade) AS MediaPacFpolis FROM Pacientes WHERE cidade = 'Florianopolis';-- 20
SELECT MIN(salario) AS minimo, MAX(salario) AS maximo FROM Funcionarios;          -- 1100 / 2500
SELECT COUNT(DISTINCT especialidade) FROM Medicos;         -- 4 (duplicatas não contam)
```

> [!warning] Agregação + coluna comum sem `GROUP BY`
> `SELECT andar, COUNT(andar) FROM Ambulatorios;` é **errado** pelos slides. No MariaDB ele **roda sem erro**, mas o `andar` mostrado é um valor qualquer, sem significado. Para contar por andar, use `GROUP BY andar` (seção 18).

> [!note] Nota
> `FIRST()` e `LAST()` aparecem em `SQL_DDL_DML.pdf`, mas **não existem** no MySQL/MariaDB (são do MS Access). Use `ORDER BY ... LIMIT 1`.

### 15.5 Filtros no `WHERE`

Operadores de comparação: `=`, `>`, `>=`, `<`, `<=`, `<>` ou `!=` (diferente). Lógicos: `AND`, `OR`, `NOT`.

| Recurso | Sintaxe | Exemplo |
|---|---|---|
| Padrão de texto | `[NOT] LIKE 'padrão'` | `nome LIKE 'M%'` |
| Nulo | `IS [NOT] NULL` | `nroa IS NULL` |
| Intervalo (inclusivo) | `[NOT] BETWEEN v1 AND v2` | `hora BETWEEN '14:00' AND '18:00'` |
| Pertence a lista | `[NOT] IN (v1, v2, ...)` | `especialidade IN ('ortopedia','pediatria')` |

Curingas do `LIKE`:

| Curinga | Casa com | Exemplo | Resultado |
|---|---|---|---|
| `%` | Zero ou mais caracteres | `'M%'` | Maria, Marcia |
| `_` | **Exatamente um** caractere | `'_a%'` | 2ª letra "a": Maria, Marcia, Paulo, Carlos... |
| `[a-f]` | Faixa | só **SQL Server** | No MariaDB use `REGEXP '^[a-f]'` |

```sql
USE bdClinica;
SELECT CPF, nome FROM Medicos WHERE nome LIKE 'M%';                -- inicial M
SELECT nome FROM Pacientes WHERE CPF LIKE '%73' OR CPF LIKE '%55'; -- termina com...
SELECT CPF, nome FROM Medicos WHERE nroa IS NULL;                  -- sem ambulatório
SELECT * FROM Consultas WHERE hora BETWEEN '14:00' AND '18:00';    -- período da tarde
SELECT * FROM Medicos
WHERE cidade = 'Florianopolis'
  AND especialidade IN ('ortopedia', 'traumatologia', 'cardiologia');
SELECT nome FROM Medicos WHERE nome REGEXP '^[a-f]';               -- alternativa ao [a-f]
```

> [!warning] `= NULL` nunca funciona
> `WHERE nroa = NULL` não retorna nada; o certo é `IS NULL`. Nulo significa "desconhecido", e comparar com desconhecido dá desconhecido.

> [!warning] Precedência
> `AND` é avaliado antes de `OR`. `WHERE a OR b AND c` = `a OR (b AND c)`. Na dúvida, use parênteses: `WHERE (nome LIKE '%Desk' OR nome LIKE '%Table') AND preco > 300`.

> [!note] Nota
> Com os dados de 2026 todos os médicos têm ambulatório, então `nroa IS NULL` volta vazio. Na versão 2006 dos slides, o Carlos não tinha `nroa`.

### 15.6 `UNION`

Junta resultados de duas consultas **compatíveis** (mesmo nº de colunas, tipos compatíveis, na mesma ordem).

```sql
USE bdClinica;
SELECT CPF, nome FROM Medicos
UNION                                   -- sem repetições
SELECT CPF, nome FROM Pacientes;

SELECT cidade FROM Medicos
UNION ALL                               -- mantém repetições (mais rápido)
SELECT cidade FROM Pacientes;
```

### 15.7 Funções úteis do MariaDB (para os exercícios)

Não estão nos slides, mas alguns exercícios precisam delas (ex.: "idade em meses").

```sql
USE bdClinica;
SELECT nome, idade * 12 AS idade_meses FROM Pacientes;            -- cálculo simples
SELECT UPPER(nome), LENGTH(nome), CONCAT(nome, ' - ', cidade) FROM Medicos;
SELECT CURDATE(), NOW();                                           -- data/hora atuais
SELECT data, DATE_FORMAT(data, '%d/%m/%Y') AS data_br FROM Consultas;
SELECT DATEDIFF('2026-06-22', '2026-06-12');                       -- 10 dias
```

### Revisão rápida

1. Por que `COUNT(*)` e `COUNT(nroa)` podem dar resultados diferentes?
2. Qual curinga representa exatamente um caractere?
3. `BETWEEN 14:00 AND 18:00` inclui as 18:00?

---

## 16. Consultas com várias tabelas (junções)

*(Fonte: SQL2026_SELECT.pdf, SQL2026.pptx)*

### 16.1 Produto cartesiano

`FROM t1, t2` combina **cada** linha de `t1` com **cada** linha de `t2` (4 pacientes × 11 consultas = 44 linhas). Sozinho não faz sentido; precisa da **condição de junção** no `WHERE`.

```sql
USE bdClinica;
SELECT COUNT(*) FROM Pacientes, Consultas;            -- 44: tudo com tudo

SELECT Pacientes.CPF, Pacientes.nome, Consultas.data
FROM Pacientes, Consultas
WHERE Consultas.hora > '12:00'
  AND Pacientes.codp = Consultas.codp;                -- condição de junção
```

### 16.2 `[INNER] JOIN ... ON`

Mesmo resultado, mas a condição de junção fica separada do filtro: mais legível.

```text
SELECT lista FROM tabela1 [INNER] JOIN tabela2 ON condição_junção
[JOIN tabela3 ON ...] [WHERE condição]
```

```sql
USE bdClinica;
SELECT m.nome
FROM Medicos m                        -- "m" e "c" são aliases de tabela
JOIN Consultas c ON m.codm = c.codm
WHERE c.data = '2026-06-13';          -- Joao, Maria, Maria (Maria tem 2 consultas)

-- Três tabelas: médico, paciente e data
SELECT m.nome AS medico, p.nome AS paciente, c.data, c.hora
FROM Consultas c
JOIN Medicos   m ON m.codm = c.codm
JOIN Pacientes p ON p.codp = c.codp
ORDER BY c.data, c.hora;
```

> [!warning] `ERROR 1052 Column 'nome' in SELECT is ambiguous`
> As duas tabelas têm `nome`. Diga de qual: `m.nome` ou `p.nome`.

### 16.3 `NATURAL JOIN`

Junta automaticamente por **todas as colunas com o mesmo nome** nas duas tabelas.

```sql
USE bdClinica;
SELECT nome FROM Medicos NATURAL JOIN Consultas
WHERE data = '2026-06-13';            -- junta por codm (única coluna em comum)
```

> [!warning] Armadilha do `NATURAL JOIN`
> `Medicos NATURAL JOIN Pacientes` junta por `nome`, `idade`, `cidade` **e** `CPF` ao mesmo tempo, e retorna vazio. Use só quando tiver certeza de quais colunas são iguais.

### 16.4 Autojunção (tabela com ela mesma)

Precisa de **dois aliases** para a mesma tabela.

```sql
USE bdClinica;
-- Médicos com a mesma especialidade do João
SELECT m2.nome
FROM Medicos m1, Medicos m2
WHERE m1.nome = 'Joao'
  AND m1.especialidade = m2.especialidade;   -- Joao e Carlos
```

### 16.5 Junções externas: `LEFT` / `RIGHT [OUTER] JOIN`

O `INNER JOIN` só mostra quem **tem par**. A junção externa mostra **todos** de um lado, com `NULL` onde não há par.

| Junção | Mantém todas as linhas de |
|---|---|
| `INNER JOIN` | Só as que combinam |
| `LEFT JOIN` | Tabela da **esquerda** |
| `RIGHT JOIN` | Tabela da **direita** |
| `FULL JOIN` | As duas (**não existe no MySQL/MariaDB**) |

```sql
USE bdClinica;
-- Todos os ambulatórios; se tiver médico, mostra
SELECT a.nroa, a.andar, m.codm, m.nome
FROM Ambulatorios a
LEFT JOIN Medicos m ON a.nroa = m.nroa;      -- 4 e 5 aparecem com NULL

-- Ambulatórios SEM médico (padrão "LEFT JOIN + IS NULL")
SELECT a.nroa
FROM Ambulatorios a
LEFT JOIN Medicos m ON a.nroa = m.nroa
WHERE m.codm IS NULL;                        -- 4 e 5

-- Simulando FULL JOIN no MariaDB: LEFT UNION RIGHT
SELECT a.nroa, m.nome FROM Ambulatorios a LEFT  JOIN Medicos m ON a.nroa = m.nroa
UNION
SELECT a.nroa, m.nome FROM Ambulatorios a RIGHT JOIN Medicos m ON a.nroa = m.nroa;
```

### Revisão rápida

1. Quantas linhas tem o produto cartesiano de uma tabela de 5 linhas com outra de 11?
2. Quando usar `LEFT JOIN` em vez de `JOIN`?
3. Por que `NATURAL JOIN` pode retornar vazio?

---

## 17. Subconsultas (consultas aninhadas)

*(Fonte: SQL2026_SELECT.pdf, SQL2026.pptx)*

Uma consulta **dentro** de outra. Alternativa às junções para relacionar tabelas; a subconsulta pode filtrar antes (otimização).

### 17.1 `IN` / `NOT IN`

Testa se o valor **pertence** ao conjunto que a subconsulta devolve.

```sql
USE bdClinica;
-- Médicos com consulta no dia 19/06
SELECT nome FROM Medicos
WHERE codm IN (SELECT codm FROM Consultas WHERE data = '2026-06-19');   -- Pedro

-- Funcionários que NÃO são pacientes (diferença: Funcionarios − Pacientes)
SELECT CPF FROM Funcionarios
WHERE CPF NOT IN (SELECT CPF FROM Pacientes);
```

> [!warning] `NOT IN` com nulos
> Se a subconsulta devolver algum `NULL`, o `NOT IN` retorna **vazio**. Se a coluna pode ter nulos, filtre (`WHERE CPF IS NOT NULL`) ou use `NOT EXISTS`.

### 17.2 `ANY` e `ALL`

| Cláusula | Verdadeiro quando a comparação vale para... | Equivale a |
|---|---|---|
| `> ANY (...)` | **Pelo menos um** valor | `> MIN(...)` |
| `> ALL (...)` | **Todos** os valores | `> MAX(...)` |
| `= ANY (...)` | Algum valor | `IN (...)` |
| `<> ALL (...)` | Nenhum valor igual | `NOT IN (...)` |

```sql
USE bdClinica;
-- Funcionários mais novos que ALGUM outro (todos, menos o mais velho)
SELECT nome, idade FROM Funcionarios
WHERE idade < ANY (SELECT idade FROM Funcionarios);

-- Funcionários que ganham mais que TODOS os de Florianópolis
SELECT nome, salario FROM Funcionarios
WHERE salario > ALL (SELECT salario FROM Funcionarios WHERE cidade = 'Florianopolis');
-- vazio: o maior salário de Fpolis (2500) é da própria Paula
```

> [!note] Nota
> Slides: `ALL` **não tem mapeamento** direto para a álgebra relacional e **não equivale à divisão**.

### 17.3 Comparação elemento-elemento (subconsulta de um valor)

Quando a subconsulta devolve **exatamente um** valor, compara-se direto, sem `IN`/`ANY`/`ALL`.

```sql
USE bdClinica;
-- Quem ganha mais que a Rita
SELECT nome FROM Funcionarios
WHERE salario > (SELECT salario FROM Funcionarios WHERE nome = 'Rita');

-- Outros médicos com a mesma especialidade do CPF 37842156964 (João)
SELECT nome, CPF FROM Medicos
WHERE CPF <> 37842156964
  AND especialidade = (SELECT especialidade FROM Medicos WHERE CPF = 37842156964);
```

> [!warning] Atenção
> Se a subconsulta devolver mais de uma linha: `ERROR 1242 Subquery returns more than 1 row`. Troque `=` por `IN`.

### 17.4 `EXISTS` / `NOT EXISTS`

- Testa se a subconsulta **retorna alguma linha** (verdadeiro/falso).
- É **correlacionada**: usa um campo da consulta de fora (`m.codm`) e roda **para cada linha** externa.
- Vem do **quantificador existencial (∃)** do cálculo relacional.

```sql
USE bdClinica;
-- Médicos que têm consulta em 13/06
SELECT nome FROM Medicos m
WHERE EXISTS (SELECT * FROM Consultas
              WHERE data = '2026-06-13' AND codm = m.codm);

-- Funcionários de Florianópolis que NÃO são pacientes
SELECT f.nome FROM Funcionarios f
WHERE f.cidade = 'Florianopolis'
  AND NOT EXISTS (SELECT * FROM Pacientes WHERE CPF = f.CPF);
```

**"Para todos" com `NOT EXISTS` duplo** (divisão relacional). Exemplo dos slides: pacientes que consultaram com **todos** os médicos.

```sql
USE bdClinica;
SELECT p.nome FROM Pacientes p
WHERE NOT EXISTS (                        -- não existe médico...
  SELECT * FROM Medicos m
  WHERE NOT EXISTS (                      -- ...com quem o paciente não tenha consulta
    SELECT * FROM Consultas c
    WHERE c.codm = m.codm AND c.codp = p.codp));
-- vazio: ninguém consultou com os 5 médicos (Marcia não tem consultas)
```

> [!tip] Dica
> Leia o `NOT EXISTS` duplo como "**não existe** médico que o paciente **não** tenha consultado" = "consultou **todos**".

### 17.5 Subconsulta no `FROM` (tabela derivada)

A subconsulta gera uma tabela temporária usada pela consulta externa. **O alias é obrigatório.**

```sql
USE bdClinica;
SELECT m.*, c.hora
FROM Medicos m
JOIN (SELECT codm, hora FROM Consultas WHERE data = '2026-06-13') AS c
  ON m.codm = c.codm;

SELECT Amb.*
FROM (SELECT nroa, andar FROM Ambulatorios) AS Amb
JOIN (SELECT nroa FROM Medicos WHERE cidade = 'Florianopolis') AS MFlo
  ON Amb.nroa = MFlo.nroa;
```

> [!warning] Sem alias dá erro
> No MariaDB 10.11 aparece como erro de sintaxe (`ERROR 1064 ... near ''`), que não explica nada; no MySQL a mensagem é `ERROR 1248 Every derived table must have its own alias`.

### Revisão rápida

1. Qual a diferença entre `IN` e `EXISTS`?
2. `salario > ANY (...)` é equivalente a comparar com `MIN` ou `MAX`?
3. Como ler um `NOT EXISTS` duplo?

---

## 18. Ordenação, grupos e atualização com consulta

*(Fonte: SQL2026_SELECT.pdf, SQL2026.pptx, SQL_DDL_DML.pdf)*

### 18.1 `ORDER BY` e `LIMIT`

Ordem **crescente** (`ASC`) é o padrão; `DESC` = decrescente. Vários critérios: desempata pelo próximo.

```sql
USE bdClinica;
SELECT * FROM Pacientes ORDER BY nome;
SELECT salario, nome FROM Funcionarios ORDER BY salario DESC, nome;

SELECT * FROM Pacientes ORDER BY nome LIMIT 2;            -- as 2 primeiras
SELECT salario, nome FROM Funcionarios
ORDER BY salario DESC, nome
LIMIT 1, 3;                                               -- pula 1, traz 3 (linhas 2 a 4)
-- mesmo que: LIMIT 3 OFFSET 1
```

> [!important] `LIMIT a, b`
> `a` = quantas pular, `b` = quantas trazer. O exemplo do slide `LIMIT 5,10` traz as **linhas 6 a 15**.

### 18.2 `GROUP BY`

Forma **grupos** com as linhas que têm o mesmo valor; geralmente vem com função de agregação. Só colunas do agrupamento (ou agregações) devem aparecer no `SELECT`.

```sql
USE bdClinica;
SELECT especialidade, COUNT(*) AS total
FROM Medicos
GROUP BY especialidade;      -- neurologia 1, ortopedia 2, pediatria 1, traumatologia 1

SELECT andar, AVG(capacidade) AS media_cap
FROM Ambulatorios
GROUP BY andar;              -- andar 1: 40 / andar 2: 40
```

### 18.3 `HAVING`

Condição para os **grupos** (o `WHERE` filtra **linhas** antes de agrupar). Só existe junto com `GROUP BY` e usa colunas do agrupamento ou agregações.

```sql
USE bdClinica;
SELECT especialidade, COUNT(*)
FROM Medicos
GROUP BY especialidade
HAVING COUNT(*) > 1;         -- só ortopedia

-- WHERE e HAVING juntos: conta consultas da tarde por médico, só quem tem 2+
SELECT codm, COUNT(*) AS consultas_tarde
FROM Consultas
WHERE hora >= '12:00'        -- filtra LINHAS
GROUP BY codm
HAVING COUNT(*) >= 2;        -- filtra GRUPOS
```

| | `WHERE` | `HAVING` |
|---|---|---|
| Filtra | Linhas | Grupos |
| Quando | Antes do `GROUP BY` | Depois do `GROUP BY` |
| Aceita agregação (`COUNT`...)? | **Não** | Sim |

> [!warning] Atenção
> `WHERE COUNT(*) > 1` dá `ERROR 1111 Invalid use of group function`. Condição com agregação vai no `HAVING`.

### 18.4 Atualização com consulta

`INSERT`, `UPDATE` e `DELETE` podem usar subconsultas, necessário quando a alteração depende de **outra tabela**.

```sql
USE bdClinica;
START TRANSACTION;

-- 1) Apagar consultas após 17h da médica Maria
DELETE FROM Consultas
WHERE hora > '17:00:00'
  AND codm IN (SELECT codm FROM Medicos WHERE nome = 'Maria');

-- 2) Tirar o ambulatório de quem atende sozinho nele
UPDATE Medicos
SET nroa = NULL
WHERE NOT EXISTS (SELECT * FROM Medicos m
                  WHERE m.codm <> Medicos.codm
                    AND m.nroa = Medicos.nroa);     -- só Joao (sozinho no ambulatório 1)

-- 3) Somar à capacidade do ambulatório 2 a capacidade do 4
UPDATE Ambulatorios
SET capacidade = capacidade + (SELECT capacidade FROM Ambulatorios WHERE nroa = 4)
WHERE nroa = 2;

SELECT * FROM Medicos;  SELECT * FROM Ambulatorios;
ROLLBACK;
```

> [!note] Nota
> Testado no MariaDB 10.11: os exemplos 2 e 3 (subconsulta na **mesma** tabela que está sendo alterada) funcionam. No **MySQL** eles dão `ERROR 1093`; se acontecer, envolva a subconsulta em uma tabela derivada: `(SELECT capacidade FROM (SELECT * FROM Ambulatorios) AS a WHERE nroa = 4)`.

### Revisão rápida

1. Diferença entre `WHERE` e `HAVING`?
2. O que retorna `LIMIT 5, 10`?
3. Quando um `UPDATE` precisa de subconsulta?

---

## 19. Conexão com aplicações: PHP, Java e C

*(Fonte: BANCO_DE_DADOS_e_PHP.pdf; 19.5 a 19.7 são complementos testados, fora dos slides)*

### 19.1 Preparar o PHP no Debian (precisa de `sudo`)

```bash
sudo apt install php-cli php-mysql     # php-mysql traz as extensões mysqli e PDO MySQL
php -m | grep -i -E 'mysqli|pdo_mysql' # as duas devem aparecer
```

> [!note] Nota
> Os slides usam o nome "MySQL", mas o mesmo código PHP conecta no MariaDB.

### 19.2 Conexão com `mysqli`

São necessárias 4 informações: `$servername`, `$database`, `$username`, `$password`.

| Função | Faz o quê |
|---|---|
| `mysqli_connect()` | Abre a conexão com o servidor |
| `mysqli_connect_error()` | Mensagem do erro, se falhar |
| `die()` | Encerra o script mostrando a mensagem |
| `mysqli_close()` | Fecha a conexão (se omitida, fecha sozinha no fim do script) |

```php
<?php
// conexao_mysqli.php (código dos slides, adaptado ao seu usuário)
$servername = "localhost";
$database   = "bdClinica";
$username   = "juh";          // nos slides: root com senha vazia (não funciona no Debian)
$password   = "TroqueEstaSenha!2026";

// Cria a conexão
$conn = mysqli_connect($servername, $username, $password, $database);

// Verifica a conexão
if (!$conn) {
    die("Falha de Conexão: " . mysqli_connect_error());
}
echo "Conexão com Sucesso!!!\n";

// Bônus: executar uma consulta e mostrar o resultado
$resultado = mysqli_query($conn, "SELECT nome, especialidade FROM Medicos");
while ($linha = mysqli_fetch_assoc($resultado)) {
    echo $linha["nome"] . " - " . $linha["especialidade"] . "\n";
}

mysqli_close($conn);
?>
```

Rodar no terminal: `php conexao_mysqli.php`.

> [!warning] Atenção
> **Por que o `root` com senha vazia dos slides falha no Debian?** Porque lá o root do MariaDB usa autenticação por *unix_socket* (só entra com `sudo`). Use o usuário criado na seção 1.4.

### 19.3 Conexão com PDO

PDO (*PHP Data Objects*) é uma interface orientada a objetos que funciona com vários SGBDs. Nos slides, a configuração fica em um arquivo e a conexão em outro.

```php
<?php
// pdoconfig.php
$host     = 'localhost';
$dbname   = 'bdClinica';
$username = 'juh';
$password = 'TroqueEstaSenha!2026';
?>
```

```php
<?php
// databaseconnect.php
require_once 'pdoconfig.php';     // inclui as variáveis do outro arquivo (uma única vez)

try {
    // DSN (Data Source Name): tipo do banco + host + nome do banco
    $conn = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8mb4", $username, $password);
    echo "Conectado a $dbname em $host com sucesso.\n";
} catch (PDOException $pe) {
    die("Não foi possível se conectar ao banco de dados $dbname: " . $pe->getMessage());
}
?>
```

| Parte | Significado |
|---|---|
| `require_once` | Puxa o arquivo de configuração (se mudar o nome do arquivo, mude aqui) |
| DSN | "Endereço" do banco: `mysql:host=...;dbname=...` |
| `try { }` | Tenta conectar |
| `catch (PDOException $pe)` | Se der erro, executa este bloco (mensagem e `die`) |

> [!note] Nota
> Os slides chamam o DSN de "DNS" em um ponto e citam `dbconfig.php` em vez de `pdoconfig.php`: são erros de digitação. O correto é **DSN** e o nome do arquivo que você usou no `require_once`.

### 19.4 Além dos slides: consulta segura com parâmetros

Nunca monte SQL juntando texto vindo do usuário (`"... WHERE nome = '" . $_GET['nome'] . "'"`): isso abre brecha para **SQL Injection**. Use *prepared statements*:

```php
<?php
require_once 'pdoconfig.php';
$conn = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8mb4", $username, $password);
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$cidade = "Florianopolis";                        // imagine que veio de um formulário
$stmt = $conn->prepare("SELECT nome FROM Pacientes WHERE cidade = ?");
$stmt->execute([$cidade]);                        // o valor vai separado do SQL
foreach ($stmt as $linha) {
    echo $linha["nome"] . "\n";
}
?>
```

> [!tip] Dica
> Não deixe senha de banco em repositório público no GitHub. Em projeto real, a configuração fica fora da pasta pública e do controle de versão (`.gitignore`).

### 19.5 Java (JDBC), passo a passo

> [!note] Além dos slides
> Os slides só mostram PHP. Esta seção usa a mesma lógica: configuração separada → conexão → `try/catch` → consulta. Testado com OpenJDK + MariaDB Connector/J 2.7 (pacote do Debian) + MariaDB 10.11.

**O que é JDBC?** *Java Database Connectivity*: a API padrão do Java para bancos de dados. É o "ODBC do Java" (seção 6.4). O seu programa usa sempre as mesmas classes (`Connection`, `PreparedStatement`, `ResultSet`), e um **driver** (um arquivo `.jar`) traduz isso para o MariaDB. O DBeaver funciona exatamente assim.

```text
App.java ─► API JDBC (java.sql) ─► driver mariadb-java-client.jar ─► MariaDB (porta 3306)
```

**Passo 1: instalar o JDK e o driver** (Debian; precisa de `sudo`)

```bash
sudo apt install default-jdk libmariadb-java
javac -version                                   # confere o compilador Java
ls /usr/share/java/mariadb-java-client.jar       # confere o driver
```

> [!tip] Dica
> Em projeto com Maven ou Gradle, o driver entra como dependência `org.mariadb.jdbc:mariadb-java-client` em vez do pacote do sistema.

**Passo 2: entender a URL de conexão**

```text
jdbc:mariadb://localhost:3306/bdClinica
│    │         │         │    └─ banco
│    │         │         └─ porta
│    │         └─ servidor (host)
│    └─ qual driver usar
└─ protocolo JDBC
```

É o equivalente ao **DSN** do PDO: `mysql:host=localhost;dbname=bdClinica`.

**Passo 3: criar os arquivos** (numa pasta, ex.: `~/bd-java/`)

`Conexao.java` faz o papel do `pdoconfig.php` + `databaseconnect.php`:

```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

// Conexao.java: guarda a configuração e abre a conexão
// (papel do pdoconfig.php + databaseconnect.php dos slides)
public class Conexao {
    private static final String URL     = "jdbc:mariadb://localhost:3306/bdClinica";
    private static final String USUARIO = "juh";

    public static Connection abrir() throws SQLException {
        String senha = System.getenv("DB_PASS");   // senha vem do ambiente, não do código
        if (senha == null) {
            throw new SQLException("Variável DB_PASS não definida (veja o passo 4).");
        }
        return DriverManager.getConnection(URL, USUARIO, senha);
    }
}
```

`App.java` testa a conexão, faz uma consulta com parâmetro e um `UPDATE` com `rollback`:

```java
import java.sql.*;

// App.java: testa a conexão, faz uma consulta e uma atualização segura
public class App {
    public static void main(String[] args) {
        // try-with-resources: fecha a conexão sozinho no final (como o mysqli_close)
        try (Connection conn = Conexao.abrir()) {
            System.out.println("Conexão com sucesso!");

            // 1) Consulta com parâmetro (?)
            String sql = "SELECT nome, idade FROM Medicos WHERE especialidade = ?";
            try (PreparedStatement st = conn.prepareStatement(sql)) {
                st.setString(1, "ortopedia");              // 1 = primeiro "?"
                try (ResultSet rs = st.executeQuery()) {
                    while (rs.next()) {                    // anda linha por linha
                        System.out.println(rs.getString("nome") + " (" + rs.getInt("idade") + " anos)");
                    }
                }
            }

            // 2) Atualização dentro de transação (TCL: commit/rollback)
            conn.setAutoCommit(false);                     // = START TRANSACTION
            try (PreparedStatement up = conn.prepareStatement(
                    "UPDATE Pacientes SET cidade = ? WHERE codp = ?")) {
                up.setString(1, "Ilhota");
                up.setInt(2, 2);                           // Paulo
                int linhas = up.executeUpdate();           // retorna quantas linhas mudaram
                System.out.println("Linhas alteradas: " + linhas);
            }
            conn.rollback();                               // desfaz (troque por conn.commit() para gravar)
            System.out.println("Alteração desfeita com rollback.");

        } catch (SQLException e) {
            System.out.println("Erro no banco: " + e.getMessage());
        }
    }
}
```

| Classe/método | Papel | Equivalente no PHP |
|---|---|---|
| `DriverManager.getConnection(url, user, senha)` | Abre a conexão | `mysqli_connect()` / `new PDO(...)` |
| `PreparedStatement` + `?` | SQL com parâmetros (protege de SQL Injection) | `$conn->prepare(...)` |
| `setString(1, ...)`, `setInt(2, ...)` | Preenche o 1º, 2º `?` (contagem começa em **1**) | `execute([...])` |
| `executeQuery()` → `ResultSet` | Executa `SELECT` | `mysqli_query()` |
| `rs.next()` / `rs.getString("nome")` | Anda nas linhas / lê a coluna | `mysqli_fetch_assoc()` |
| `executeUpdate()` | Executa `INSERT`/`UPDATE`/`DELETE` e retorna nº de linhas | |
| `setAutoCommit(false)`, `commit()`, `rollback()` | Transação (TCL) | `START TRANSACTION` / `COMMIT` / `ROLLBACK` |
| `try (...)` | Fecha tudo sozinho no final | `mysqli_close()` |
| `catch (SQLException e)` | Trata o erro | `catch (PDOException $pe)` |

**Passo 4: definir a senha fora do código**

```bash
read -s -p "Senha do banco: " DB_PASS && export DB_PASS && echo
# read -s não mostra o que você digita e não salva a senha no histórico do Bash
```

A variável vale só para **aquele terminal**. Fechou, sumiu (é o objetivo).

**Passo 5: compilar e executar**

```bash
cd ~/bd-java
javac -cp /usr/share/java/mariadb-java-client.jar -d out Conexao.java App.java
java  -cp out:/usr/share/java/mariadb-java-client.jar App
```

- `-cp` (*classpath*): onde o Java procura classes. Precisa ter **o seu código (`out`) e o driver (`.jar`)**.
- No Linux os caminhos do classpath são separados por `:` (no Windows, por `;`).
- `-d out`: coloca os `.class` compilados na pasta `out`.

**Passo 6: verificar**

Saída esperada:

```text
Conexão com sucesso!
Joao (40 anos)
Carlos (28 anos)
Linhas alteradas: 1
Alteração desfeita com rollback.
```

Confirme no DBeaver que o Paulo continua em Palhoca (`SELECT cidade FROM Pacientes WHERE codp = 2;`), porque o `rollback()` desfez a alteração.

**Erros comuns (Java)**

| Mensagem | Causa | Solução |
|---|---|---|
| `No suitable driver found for jdbc:mariadb://...` | O `.jar` do driver não está no `-cp` | Inclua o caminho do `.jar` no `java -cp` |
| `Variável DB_PASS não definida` | Esqueceu o passo 4 (ou abriu outro terminal) | Rode o `read -s ...` de novo |
| `Access denied for user 'juh'@'localhost'` | Senha errada | Confira a senha |
| `Could not connect ... Connection refused` | MariaDB parado | `sudo systemctl start mariadb` |
| `error: cannot find symbol` ao compilar | Faltou compilar `Conexao.java` junto | Compile os dois arquivos |
| `Unknown database 'bdclinica'` | Maiúsculas/minúsculas | Use `bdClinica` (igual ao `CREATE`) |

> [!important] Diferença importante em relação a C
> Em Java a memória é liberada pelo *garbage collector* e o `try (...)` fecha a conexão. Você **não** chama nada como `free()`. Mas fechar conexões continua importante: o MariaDB tem limite de conexões abertas.

### 19.6 C (MariaDB Connector/C), passo a passo

> [!note] Além dos slides
> Testado com `gcc -Wall -Wextra -std=c11` (sem avisos), MariaDB Connector/C (`libmariadb-dev`) e MariaDB 10.11. Sem vazamento de memória segundo o Valgrind.

**O que muda em C?** Não existe camada tipo JDBC: você chama direto as **funções da biblioteca** do MariaDB e cuida da **memória** e dos **erros** manualmente (cada função retorna um código que precisa ser verificado).

**Passo 1: instalar o compilador e a biblioteca** (Debian; precisa de `sudo`)

```bash
sudo apt install build-essential libmariadb-dev
mariadb_config --cflags --libs    # mostra as opções de compilação
# saída típica: -I/usr/include/mariadb -I/usr/include/mariadb/mysql
#               -L/usr/lib/x86_64-linux-gnu/ -lmariadb
```

- `-I...`: onde estão os cabeçalhos (`mysql.h`).
- `-lmariadb`: liga (*link*) o programa à biblioteca do MariaDB.

**Passo 2: entender o fluxo da API**

```text
mysql_init()           cria a "alça" (handle) da conexão: MYSQL *
mysql_real_connect()   conecta (host, usuário, senha, banco, porta)
mysql_query()          envia o SQL (retorna 0 = sucesso)
mysql_store_result()   traz o resultado: MYSQL_RES *
mysql_fetch_row()      pega a próxima linha: MYSQL_ROW (vetor de char *)
mysql_free_result()    libera o resultado            ← obrigatório
mysql_close()          fecha a conexão               ← obrigatório
```

> [!important] Tudo chega como string
> `row[0]`, `row[1]`... são `char *`. A idade `40` vem como `"40"`. Para fazer conta, converta (`atoi`, `strtol`). E um valor `NULL` no banco vira ponteiro **`NULL`** em C: testar antes de usar evita *segmentation fault*.

**Passo 3: programa de consulta** (`consulta.c`)

```c
/* consulta.c: conecta no bdClinica e lista os médicos */
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>                       /* API do MariaDB Connector/C */

int main(void) {
    const char *senha = getenv("DB_PASS");          /* senha vem do ambiente */
    if (senha == NULL) {
        fprintf(stderr, "Defina a variável DB_PASS (veja o passo 4).\n");
        return EXIT_FAILURE;
    }

    /* 1) Cria a "alça" (handle) da conexão */
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init falhou (sem memória?)\n");
        return EXIT_FAILURE;
    }

    /* 2) Conecta: host, usuário, senha, banco, porta, socket, flags */
    if (mysql_real_connect(conn, "localhost", "juh", senha,
                           "bdClinica", 3306, NULL, 0) == NULL) {
        fprintf(stderr, "Falha de conexão: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    mysql_set_character_set(conn, "utf8mb4");       /* acentos corretos */
    printf("Conexão com sucesso!\n");

    /* 3) Executa o SQL (retorna 0 quando dá certo) */
    if (mysql_query(conn, "SELECT codm, nome, especialidade FROM Medicos")) {
        fprintf(stderr, "Erro na consulta: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    /* 4) Traz o resultado para a memória do programa */
    MYSQL_RES *res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "Erro ao ler resultado: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    /* 5) Percorre as linhas: cada linha é um vetor de strings (char *) */
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)) != NULL) {
        /* row[i] pode ser NULL se o valor no banco for NULL */
        printf("%s - %s (%s)\n", row[0], row[1], row[2] ? row[2] : "sem especialidade");
    }
    printf("Total: %llu médicos\n", (unsigned long long) mysql_num_rows(res));

    /* 6) Libera memória e fecha */
    mysql_free_result(res);
    mysql_close(conn);
    return EXIT_SUCCESS;
}
```

**Passo 4: senha fora do código** (igual ao Java)

```bash
read -s -p "Senha do banco: " DB_PASS && export DB_PASS && echo
```

O programa lê com `getenv("DB_PASS")`. Se a variável não existir, `getenv` retorna `NULL`, e o código trata isso antes de usar.

**Passo 5: compilar e executar**

```bash
gcc -Wall -Wextra -std=c11 consulta.c -o consulta $(mariadb_config --cflags --libs)
./consulta
```

- `$(mariadb_config --cflags --libs)`: o Bash executa o comando e cola a saída dele ali (as opções do passo 1).
- `-Wall -Wextra`: liga os avisos do compilador. Corrija todos.

Saída esperada:

```text
Conexão com sucesso!
1 - Joao (ortopedia)
2 - Maria (traumatologia)
3 - Pedro (pediatria)
4 - Carlos (ortopedia)
5 - Marcia (neurologia)
Total: 5 médicos
```

**Passo 6: alterar dados com segurança** (`atualiza.c`)

Em C, montar o SQL com `sprintf` e um valor digitado pelo usuário abre brecha para **SQL Injection** (e para estouro de buffer). O caminho seguro é o *prepared statement* (`MYSQL_STMT`): mais verboso, mas o valor vai separado do SQL.

```c
/* atualiza.c: UPDATE seguro com prepared statement + transação */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

int main(void) {
    const char *senha = getenv("DB_PASS");
    if (senha == NULL) { fprintf(stderr, "Defina DB_PASS.\n"); return EXIT_FAILURE; }

    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL ||
        mysql_real_connect(conn, "localhost", "juh", senha, "bdClinica", 3306, NULL, 0) == NULL) {
        fprintf(stderr, "Falha de conexão: %s\n", conn ? mysql_error(conn) : "mysql_init");
        if (conn) mysql_close(conn);
        return EXIT_FAILURE;
    }
    mysql_set_character_set(conn, "utf8mb4");

    /* 1) Prepara o SQL com "?" no lugar dos valores */
    const char *sql = "UPDATE Pacientes SET cidade = ? WHERE codp = ?";
    MYSQL_STMT *stmt = mysql_stmt_init(conn);
    if (stmt == NULL || mysql_stmt_prepare(stmt, sql, strlen(sql))) {
        fprintf(stderr, "Erro no prepare: %s\n", stmt ? mysql_stmt_error(stmt) : "stmt_init");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    /* 2) Valores e "bind": diz ao driver o tipo e o endereço de cada parâmetro */
    char cidade[] = "Ilhota";
    unsigned long tam_cidade = strlen(cidade);
    int codp = 2;                                       /* Paulo */

    MYSQL_BIND param[2];
    memset(param, 0, sizeof(param));                    /* zera tudo: evita lixo de memória */

    param[0].buffer_type   = MYSQL_TYPE_STRING;         /* 1º ?  → texto */
    param[0].buffer        = cidade;
    param[0].buffer_length = tam_cidade;
    param[0].length        = &tam_cidade;

    param[1].buffer_type   = MYSQL_TYPE_LONG;           /* 2º ?  → int */
    param[1].buffer        = &codp;

    /* 3) Transação manual: nada é gravado até o commit */
    mysql_autocommit(conn, 0);

    if (mysql_stmt_bind_param(stmt, param) || mysql_stmt_execute(stmt)) {
        fprintf(stderr, "Erro ao executar: %s\n", mysql_stmt_error(stmt));
        mysql_rollback(conn);
    } else {
        printf("Linhas alteradas: %llu\n",
               (unsigned long long) mysql_stmt_affected_rows(stmt));
        mysql_rollback(conn);                           /* troque por mysql_commit(conn) para gravar */
        printf("Alteração desfeita com rollback.\n");
    }

    mysql_stmt_close(stmt);
    mysql_close(conn);
    return EXIT_SUCCESS;
}
```

```bash
gcc -Wall -Wextra -std=c11 atualiza.c -o atualiza $(mariadb_config --cflags --libs)
./atualiza
# Linhas alteradas: 1
# Alteração desfeita com rollback.
```

| Parte | Explicação |
|---|---|
| `mysql_stmt_prepare` | Envia o SQL com `?` para o servidor "compilar" |
| `MYSQL_BIND param[2]` | Um "envelope" por `?`, na ordem em que aparecem |
| `memset(param, 0, ...)` | Zera a struct: campos não usados ficam com lixo se você esquecer |
| `buffer_type` | Tipo do valor (`MYSQL_TYPE_STRING`, `MYSQL_TYPE_LONG` = `int`) |
| `buffer` | **Endereço** do valor (por isso `&codp`; `cidade` já é ponteiro) |
| `mysql_autocommit(conn, 0)` | Desliga o auto-commit = `START TRANSACTION` |
| `mysql_rollback` / `mysql_commit` | Desfaz / grava |

**Passo 7 (opcional): conferir vazamento de memória**

```bash
sudo apt install valgrind
valgrind --leak-check=full ./consulta
# procure: "definitely lost: 0 bytes" e "ERROR SUMMARY: 0 errors"
```

Apague a linha `mysql_free_result(res);`, compile de novo e rode o Valgrind: ele vai apontar o vazamento. É um ótimo exercício de ponteiros e memória.

> [!note] Nota
> O Valgrind pode mostrar alguns bytes "*still reachable*": é memória interna da biblioteca, liberada quando o programa termina. O que importa é `definitely lost: 0`.

**Erros comuns (C)**

| Mensagem | Causa | Solução |
|---|---|---|
| `fatal error: mysql.h: No such file or directory` | Falta `libmariadb-dev` ou o `$(mariadb_config --cflags)` | Instale o pacote / use o comando completo do passo 5 |
| `undefined reference to 'mysql_init'` | Faltou ligar a biblioteca (`-lmariadb`) | Use `$(mariadb_config --libs)` **no fim** do comando |
| `Segmentation fault` ao imprimir | Usou `row[i]` que era `NULL` (ou usou `row` depois do `mysql_free_result`: comportamento indefinido) | Teste `row[i] ? row[i] : "..."`; libere só no final |
| `Commands out of sync` | Fez outra `mysql_query` sem ler o resultado da anterior | Chame `mysql_store_result` (e depois `mysql_free_result`) antes da próxima consulta |
| `Access denied ...` / `Can't connect ...` | Senha errada / serviço parado | Igual ao Java |
| Acentos estranhos (`SÃ£o`) | Conexão em latin1 | `mysql_set_character_set(conn, "utf8mb4")` |

### 19.7 PHP × Java × C: comparação

| | PHP (slides) | Java | C |
|---|---|---|---|
| Biblioteca | `mysqli` / PDO | JDBC + `mariadb-java-client.jar` | `libmariadb` (Connector/C) |
| "Endereço" do banco | DSN `mysql:host=...;dbname=...` | URL `jdbc:mariadb://host:3306/banco` | Parâmetros separados em `mysql_real_connect` |
| Tratamento de erro | `die()` / `try-catch` | `try-catch (SQLException)` | Testar o retorno de cada função + `mysql_error()` |
| Fechar / liberar | Automático no fim do script | `try (...)` | **Manual**: `mysql_free_result`, `mysql_close` |
| Tipos dos valores lidos | Strings/arrays | Métodos tipados (`getInt`, `getString`) | Sempre `char *` |
| Parâmetros seguros | `prepare` + `?` | `PreparedStatement` + `?` | `MYSQL_STMT` + `MYSQL_BIND` |
| Esforço para começar | Baixo | Médio | Alto |

### Revisão rápida (19.5 a 19.7)

1. O que o arquivo `.jar` do driver faz numa aplicação JDBC?
2. Por que o `java` dá `No suitable driver found` mesmo com o código correto?
3. Em C, por que é preciso testar `row[i]` antes de imprimir?
4. Qual é a função de `$(mariadb_config --cflags --libs)` no comando do `gcc`?
5. Por que o *prepared statement* é mais seguro do que montar o SQL com `sprintf`?

---

## 20. Tabela de socorro: "por que não funciona?"

*(Fonte: erros reproduzidos no MariaDB 10.11 + armadilhas dos slides)*

| Sintoma / erro | Causa provável | Como corrigir |
|---|---|---|
| `ERROR 1064 ... syntax ... near '´Ana´'` | Aspas copiadas do slide (`´` ou `‘ ’`) | Use aspas simples retas: `'Ana'` |
| `ERROR 1146 Table 'bdClinica.medicos' doesn't exist` | **No Linux, nome de tabela diferencia maiúsculas**: a tabela é `Medicos` | Escreva igual ao `CREATE` (`SHOW TABLES;` para conferir) |
| `ERROR 1046 No database selected` | Esqueceu o `USE` | `USE bdClinica;` ou escolha o banco no DBeaver |
| `ERROR 1452 ... foreign key constraint fails` (INSERT) | O "pai" ainda não existe | Insira antes o registro referenciado |
| `ERROR 1451 Cannot delete or update a parent row` | Tentou apagar "pai" que tem "filhos" | Apague/mova os filhos antes |
| `ERROR 1062 Duplicate entry` | Valor repetido em PK ou `UNIQUE` | Use outro valor ou corrija o dado |
| `ERROR 1048 Column 'nome' cannot be null` | Coluna `NOT NULL` sem valor | Informe o valor |
| `ERROR 1052 Column 'nome' ... is ambiguous` | Coluna existe nas duas tabelas do JOIN | Prefixe: `m.nome` |
| `ERROR 1111 Invalid use of group function` | Agregação no `WHERE` | Mova para o `HAVING` |
| `ERROR 1242 Subquery returns more than 1 row` | `=` com subconsulta de várias linhas | Use `IN` (ou `ANY`/`ALL`) |
| `ERROR 1064 ... near ''` em subconsulta no FROM | Tabela derivada sem alias | `(...) AS nome` |
| `ERROR 1044 Access denied ... to database` | Usuário sem permissão naquele banco | Use nome começando com `bd` ou ajuste o `GRANT` |
| `ERROR 1045 Access denied for user 'root'@'localhost'` (DBeaver/PHP) | Root do Debian só entra via `sudo` | Use o usuário da seção 1.4 |
| `ERROR 2002 Can't connect ... socket` | Serviço parado | `sudo systemctl start mariadb` |
| Acentos viram `SÃ£o JosÃ©` | Cliente do terminal em latin1 | `SET NAMES utf8mb4;` no início do script ou `mariadb --default-character-set=utf8mb4` |
| `WHERE x = NULL` não retorna nada | `NULL` não se compara com `=` | `IS NULL` / `IS NOT NULL` |
| `NOT IN` retorna vazio "sem motivo" | Subconsulta devolveu algum `NULL` | Filtre os nulos ou use `NOT EXISTS` |
| Consulta com `OR` traz linhas demais | `AND` avaliado antes do `OR` | Use parênteses |
| Data não encontra nada | Formato `'12/06/2026'` ou `'DD-MM-YYYY'` | Use `'2026-06-12'` |
| CPF começando com 0 perde o zero | `NUMERIC` não guarda zeros à esquerda | Em projeto real use `CHAR(11)` (no exercício, siga o enunciado) |
| `UPDATE`/`DELETE` mudou tudo | Faltou `WHERE` | Restaure: rode de novo o script da seção 1.7 |

---

## 21. Pontos de atenção encontrados nos slides

*(Fonte: comparação entre os arquivos e testes no MariaDB)*

> [!warning] Atenção
> Estes itens são **diferenças ou erros no material**. Vale confirmar com a professora antes da prova.

| # | Onde | O que está no material | O que funciona / o correto |
|---|---|---|---|
| 1 | SQL_Introducao01 / pptx | Formato de data `"DD-MM-YYYY"` | MariaDB usa `'AAAA-MM-DD'` (o próprio slide "Popular" confirma) |
| 2 | SQL_DDL_DML | Funções `FIRST()` e `LAST()` | Não existem no MySQL/MariaDB |
| 3 | SQL_DDL_DML / SELECT | Curingas `[charlist]`, `[a-f]` | Só SQL Server; no MariaDB use `REGEXP` |
| 4 | SQL_DDL_DML | `DELETE - to modify existing data` | `DELETE` **remove** linhas |
| 5 | Exercícios | Datas 2006 em umas versões, 2026 em outras | Use as datas da base que você populou |
| 6 | Consultas, ex. 1 | Enunciado diz "**ou**", resposta usa `AND` | Deveria ser `OR` |
| 7 | Consultas, ex. 4 | "antes de 14/06 **e** depois de 20/06" resolvido com `data > 14 AND data < 20` | Isso é "entre"; o pedido é `data < ... OR data > ...` |
| 8 | Junções, ex. 8 | Resposta faz `Medicos LEFT JOIN Consultas` | Não usa `Pacientes`, então não traz nome/CPF dos pacientes |
| 9 | Exemplo do `IN` | Lista repete `'cardiologia'` | Pelo enunciado, deveria incluir `'ortopedia'` |
| 10 | Agregação | "Não podem ser combinadas a outros atributos" | Correto como regra, mas o MariaDB **executa** e mostra valor arbitrário |
| 11 | Normalização (2FN) | Nomes `Estoque` e `Produto` trocados | Ver seção 12.4 |
| 12 | Exercícios SQL | Chave de `Consultas` não definida no texto | Usei `(codm, codp, data)`; confirmar |
| 13 | Ex. de atualização 4 | "médico Pedro (**codf** = 3)" | Médico usa `codm` |
| 14 | Infográfico "Aprenda SQL" | `INTERSECT`, `EXCEPT`, funções de data... e erros (`DELEFE`, `STSDATE`, `IEATEADD`) | Material extra, fora dos slides; corretos: `DELETE`, `SYSDATE`, `DATEADD` |
| 15 | PHP | "DNS", `dbconfig.php` | DSN, `pdoconfig.php` |

---

## 22. Listas de exercícios (tente sozinha)

*(Fonte: SQL_Introducao01.pdf, SQL_INCLUSAO_POPULACAO.pdf, SQL2026_SELECT.pdf, SQL2026.pptx, BD_AULA03B_NORMALIZACAO.pdf)*

> [!tip] Como treinar
> Rode o script da seção 1.7, resolva no DBeaver, confira o resultado e, para `UPDATE`/`DELETE`, use `START TRANSACTION` + `ROLLBACK` ou recrie o banco. Depois traga suas respostas para corrigirmos juntas.

### 22.1 DDL

1. ~~Criar o BD `BdClinica`~~ e 2. ~~criar as tabelas~~ (feitos pelo script da seção 1.7: compare com o seu).
3. Criar a coluna `nroa` (int) na tabela `Funcionarios`.
4. Criar os índices: `Medicos`: CPF (único); `Pacientes`: doenca.
5. Remover o índice `doenca` em `Pacientes`.
6. Remover as colunas `cargo` e `nroa` de `Funcionarios`.

### 22.2 Atualizações

1. O paciente Paulo mudou-se para Ilhota.
2. A consulta do médico 1 com o paciente 4 passou para 12:00 do dia 4 de julho de 2026.
3. A paciente Ana fez aniversário e sua doença agora é câncer.
4. A consulta do médico Pedro (codm = 3) com o paciente Carlos (codp = 4) passou para uma hora e meia depois.
5. O funcionário Carlos (codf = 4) deixou a clínica.
6. As consultas marcadas após as 19 horas foram canceladas.
7. Os pacientes com câncer ou idade inferior a 10 anos deixaram a clínica.
8. Os médicos que residem em Biguacu e Palhoca deixaram a clínica.

### 22.3 Consultas simples

1. Nome e CPF dos médicos com menos de 40 anos **ou** com especialidade diferente de traumatologia.
2. Todos os dados das consultas no período da tarde após 19/06/2026.
3. Nome e idade dos pacientes que não residem em Florianópolis.
4. Hora das consultas marcadas antes de 14/06/2026 e depois de 20/06/2026.
5. Nome e idade (em meses) dos pacientes.
6. Em quais cidades residem os funcionários?
7. Menor e maior salário dos funcionários de Florianópolis.
8. *(numeração dos slides pula para 10)* Horário da última consulta marcada para 13/06/2026.
9. Média de idade dos médicos e total de ambulatórios atendidos por eles.
10. Código, nome e salário líquido dos funcionários (salário − 20%).
11. Nome dos funcionários que terminam com a letra "a".
12. Nome e CPF dos funcionários que não possuem a sequência "00000" no CPF.
13. Nome e especialidade dos médicos cuja segunda e última letra do nome seja "o".
14. Códigos e nomes dos pacientes com mais de 25 anos com tendinite, fratura, gripe e sarampo.

### 22.4 Produto, JOIN, NATURAL JOIN e junção externa

Resolva cada uma com produto, com junção (e junção natural, quando possível):

1. Nome e CPF dos médicos que também são pacientes do hospital.
2. Pares (código, nome) de funcionários e médicos que residem na mesma cidade.
3. Código e nome dos pacientes com consulta após as 14 horas.
4. Número e andar dos ambulatórios utilizados por médicos ortopedistas.
5. Nome e CPF dos pacientes com consultas entre 14 e 16 de junho de 2026.
6. Nome e idade dos médicos que têm consulta com a paciente Ana.
7. Código e nome dos médicos que atendem no mesmo ambulatório do médico Pedro e têm consulta em 14/06/2026.
8. Nome, CPF e idade dos pacientes com consultas com ortopedistas antes do dia 16.
9. Nome e salário dos funcionários que moram na mesma cidade do funcionário Carlos e ganham mais que ele.
10. Dados de todos os ambulatórios e, onde houver médicos, seus códigos e nomes.
11. CPF e nome de todos os médicos e, para os que têm consultas, CPF e nome dos pacientes e as datas.

### 22.5 Subconsultas

**Com `IN`:**

1. Nome e CPF dos médicos que também são pacientes.
2. Código e nome dos pacientes com consulta após as 14 horas.
3. Nome e idade dos médicos que têm consulta com a paciente Ana.
4. Número e andar dos ambulatórios onde nenhum médico dá atendimento.
5. Nome, CPF e idade dos pacientes com consultas **sempre** antes do dia 16.

**Com `ANY` e/ou `ALL`:**

1. Números e andares de todos os ambulatórios, exceto o de menor capacidade.
2. Nome e idade dos médicos que têm consulta com a paciente Ana.
3. Nome e idade do médico mais jovem (sem `MIN`!).
4. Nome e CPF dos pacientes com consultas em horários anteriores a todos os horários do dia 12/06/2026.
5. Nome e CPF dos médicos que não atendem em ambulatórios com capacidade superior à dos ambulatórios do segundo andar.

**Com `EXISTS`:**

1. Nome e CPF dos médicos que também são pacientes.
2. Nome e idade dos médicos que têm consulta com a paciente Ana.
3. Número do ambulatório com a maior capacidade (sem `MAX`!).
4. Nome e CPF dos médicos que têm consultas com **todos** os pacientes.
5. Nome e CPF dos ortopedistas com consultas com todos os pacientes de Florianópolis.

**Subconsulta no `FROM`:**

1. Todos os dados das consultas da médica Maria.
2. Código e nome dos pacientes com consulta após as 14 horas.
3. Nome e cidade dos pacientes com consultas com ortopedistas.
4. Nome e CPF dos pacientes de Florianópolis sem consultas com o médico João.

### 22.6 ORDER BY e GROUP BY

1. Dados dos funcionários ordenados por salário (decrescente) e idade (crescente); só os três primeiros.
2. Nome dos médicos e número e andar do ambulatório, ordenado pelo número do ambulatório.
3. Nome do médico e dos pacientes com consulta, ordenado por data e hora.
4. Idades dos médicos e total de médicos com a mesma idade.
5. Datas e total de consultas em cada data, para horários após 12h.
6. Andares com ambulatórios e a média de capacidade por andar.
7. Andares cuja média de capacidade seja >= 40.
8. Nome dos médicos com mais de uma consulta marcada.

### 22.7 Atualizações com consulta

1. Passar para 19h todas as consultas da paciente Ana.
2. Excluir os pacientes que não têm consultas.
3. Passar para 21/06/2026 as consultas do médico Pedro marcadas antes do meio-dia.
4. O ambulatório 4 foi para o mesmo andar do ambulatório 1 e sua capacidade agora é o dobro da do ambulatório de maior capacidade.
5. O funcionário Caio (codf = 3) tornou-se médico: mesma especialidade e ambulatório da médica Maria (codm = 2). Inserir Caio em `Medicos`.

### 22.8 Normalização: locadora de automóveis

1. A locadora aluga carros de uma marca apenas para clientes pessoa jurídica (empresas).
2. Os clientes credenciam motoristas para usar os veículos.
3. Preço diário e potência dependem do **modelo** do carro.

```text
REGISTRO_ALUGUEL = { NumCNH, NomeMotorista, DataNasc, CGCCliente, NomeCliente, EndCliente,
                     { PlacaCarro, Modelo, Cor, Potência, QTDDiárias, PreçoDiária } }
```

Faça a normalização até a 3FN, indicando as DFs de cada passo.

---

## 23. Revisão final

*(Fonte: todos os arquivos)*

### 23.1 Checklist de prova

- [ ] Diferenciar dado, informação, BD, SGBD e SBD
- [ ] Citar as 6 regras SGBD × GA com exemplo
- [ ] Explicar os 3 níveis de abstração e as independências física e lógica
- [ ] Comparar modelos Redes, Hierárquico e Relacional
- [ ] Diferenciar modelo conceitual, lógico e físico
- [ ] Ler e desenhar cardinalidades (1,1), (0,n), (1,n)
- [ ] Escolher entre tabela própria, adição de coluna e fusão
- [ ] Identificar DF parcial e transitiva; normalizar até a 3FN
- [ ] Escrever `CREATE TABLE` com PK, FK, `NOT NULL`, `UNIQUE`
- [ ] `INSERT`/`UPDATE`/`DELETE` sempre com `WHERE` conferido
- [ ] `SELECT` com `LIKE`, `BETWEEN`, `IN`, `IS NULL`, agregações
- [ ] `JOIN`, `LEFT JOIN`, autojunção
- [ ] Subconsultas `IN`, `ANY`, `ALL`, `EXISTS`, no `FROM`
- [ ] `GROUP BY` + `HAVING`, `ORDER BY` + `LIMIT`
- [ ] Conectar com PHP (mysqli e PDO)

### 23.2 Conceitos parecidos (não confunda)

| Par | Diferença |
|---|---|
| SGBD × SBD | Software × sistema completo (dados + hardware + software + usuários) |
| Esquema × instância | Estrutura × dados num momento |
| Independência física × lógica | Muda armazenamento × muda estrutura lógica |
| Redundância controlada × não controlada | Software sincroniza × usuário sincroniza |
| Entidade fraca × associativa | Depende de outra para existir × relacionamento tratado como entidade |
| Chave primária × candidata | Escolhida para identificar × poderia identificar |
| DF parcial × transitiva | Depende de parte da chave (2FN) × depende de não chave (3FN) |
| `DELETE` × `TRUNCATE` × `DROP` | Linhas (com WHERE) × todas as linhas × tabela inteira |
| `WHERE` × `HAVING` | Linhas × grupos |
| `COUNT(*)` × `COUNT(col)` | Conta linhas × conta não nulos |
| `UNION` × `UNION ALL` | Sem repetições × com repetições |
| `JOIN` × `LEFT JOIN` | Só pares × todos da esquerda |
| `IN` × `EXISTS` | Valor no conjunto × subconsulta retorna algo |
| `ANY` × `ALL` | Algum valor × todos os valores |

### 23.3 Perguntas de revisão

1. Por que uma organização aleatória de dados não é um BD?
2. Qual regra do SGBD é violada quando a aplicação precisa evitar deadlock?
3. Criar um índice é exemplo de qual independência de dados?
4. O que é uma visão e em que nível de abstração ela está?
5. O que caracteriza o modelo relacional, segundo Codd?
6. Para quem é feito o modelo conceitual e por quê?
7. Em `Equipe (1,1) — (1,n) Jogadores`, onde vai a chave estrangeira?
8. Como transformar um relacionamento N:N com atributo próprio?
9. Uma tabela com PK simples pode violar a 2FN?
10. Por que `Cli_Idade` viola a 3FN se existe `Cli_Nascimento`?
11. Qual a ordem para popular `Ambulatorios`, `Medicos` e `Consultas`?
12. Qual a diferença entre `LIKE 'a%'` e `LIKE '_a%'`?
13. Por que `SELECT andar, COUNT(*) FROM Ambulatorios;` é um erro conceitual?
14. Escreva uma consulta que liste os ambulatórios sem médicos de duas formas diferentes.
15. No PHP, para que serve o bloco `catch`?
