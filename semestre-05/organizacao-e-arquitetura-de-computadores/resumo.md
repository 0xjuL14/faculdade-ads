# Organização e Arquitetura de Computadores: resumo de consulta rápida

> Resumo dos slides da disciplina (23 PDFs). Versão em Markdown para Obsidian/Notesnook. A versão em HTML tem calculadora, busca e os desenhos dos circuitos.

## Sumário

- 1. Fundamentos e modelo de Von Neumann
- 2. Níveis de abstração, linguagens e tradução
- 3. Tipos de computadores, Lei de Moore e hardware × software
- 4. Processadores: componentes, tipos e linha do tempo
- 5. CISC × RISC
- 6. Sistemas digitais e portas lógicas
- 7. Conjunto de instruções (parte 1A): formato, bits e endereços
- 8. Tipos de dados e classes de operação (parte 1B)
- 9. Operações lógicas, deslocamento, controle e E/S (parte 2)
- 10. Modos de endereçamento, registradores e formato da instrução (partes 2 e 3)
- 11. Memória: características, hierarquia, RAM, ROM e cache
- 12. Barramentos: memória, clock, sincronia, pontes e PCIe
- 13. Placa-mãe: componentes, expansão, armazenamento e compatibilidade
- 14. Entrada/Saída e armazenamento
- 15. Pipeline e arquiteturas superescalares (partes 1 e 2)
- 16. Revisão final: comparações, perguntas e exercícios
- 17. Tabela de conversão: decimal, binário, hexadecimal e DCB (BCD)

---

## 1. Fundamentos e modelo de Von Neumann
*(Fonte: Aula_1_Arquitetura_de_Computadores_INTRODUCAO.pdf e Aula03_1_Computadores.pdf)*

### 1.1 O que é um computador e o que ele faz

Um computador é um dispositivo capaz de **calcular e tomar decisões lógicas** milhões ou bilhões de vezes mais rápido que uma pessoa. A finalidade dele é **receber, manipular e armazenar dados** (processamento de dados): dados iniciais → manipulação → resultado.

| Função | O que significa |
|---|---|
| Processamento de dados | Executar cálculos e decisões lógicas |
| Armazenamento de dados | Guardar dados e programas (essencial) |
| Movimentação (transferência) de dados | Levar dados entre componentes e para o mundo externo |
| Controle | Mecanismo que coordena as **três** funções anteriores |

> 🏆 **Regra de ouro**: **Regra de ouro:** são **4 funções**: 3 operacionais (processar, armazenar, transferir) + 1 de controle que gerencia as outras 3.

### 1.2 Arquitetura × Organização

| | Arquitetura | Organização |
|---|---|---|
| Visível ao programador? | **Sim** | **Não** |
| O que estuda | Atributos que afetam a lógica de construção e execução dos programas | Unidades operacionais e interconexões que **implementam** a arquitetura |
| Exemplos | Conjunto de instruções; número de bits do processador; mecanismos de E/S; técnicas de endereçamento de memória | Sinais de controle; interface computador/periféricos; tecnologia de memória usada |

**Por que a separação importa?** Um fabricante pode vender uma **família** de modelos com a **mesma arquitetura** e **organizações diferentes** (desempenho e preço diferentes). O cliente migra de modelo sem trocar o software: preserva o investimento e mantém a compatibilidade de código.

- **IBM 360:** uma arquitetura, vários modelos. Dava para comprar um modelo inferior e subir depois.
- **PCs:** compatibilidade entre gerações porque todos adotam a arquitetura **Intel x86**. Programas antigos ainda rodam.

> ⚠️ **Atenção**: **Pegadinha:** "o PC tem 32 bits" é **arquitetura** (o programador enxerga). "Qual tecnologia de memória o chip usa" é **organização** (o programador não enxerga).

Por que estudar isso? Desempenho é fator de qualidade do software. Para escrever programas eficientes é preciso saber quais são os componentes, como interagem entre si e como o software interage com eles.

### 1.3 Modelo de Von Neumann

É o modelo de todos os computadores de **propósito geral**. Ideia central: **programa armazenado**, ou seja, **instruções e dados ficam na mesma memória**, e o computador busca e executa as instruções automaticamente.

| Elemento | Função |
|---|---|
| **Memória** (principal) | Armazena dados **e** instruções |
| **Unidade de Controle (UC)** | Determina a sequência de instruções, decodifica e gera sinais de controle para as outras unidades |
| **ULA** (Unidade Lógica e Aritmética) | Executa operações aritméticas (soma, subtração...) e lógicas (comparações) |
| **Entrada/Saída (E/S)** | Comunica o computador com o ambiente externo |

```
   Entrada/Saída  <-->  Memória principal
         ^                   ^
         |                   |
         +---- Unidade de Controle <--> ULA
```

> 📝 **Nota**: Pense na UC como quem organiza **"qual passo acontece agora"**, e na ULA como quem **faz a conta**.

### 1.4 Componentes de um computador

| Componente | Papel |
|---|---|
| **CPU** | Controla as operações do computador e realiza o processamento (cérebro). Pode ter um ou vários processadores (multicore) |
| **Memórias** | Todos os meios de armazenamento para programas e dados |
| **Dispositivos de E/S** | Transferência de dados (teclado, mouse, monitor...) |
| **Rede de interconexão** | Comunicação entre CPU, memória e E/S (o **barramento**) |

Dentro da CPU:

- **Unidade de controle:** decodifica as instruções do programa e emite sinais de controle.
- **ULA:** executa as operações aritméticas e lógicas.
- **Registradores:** armazenamento interno da CPU, memória de acesso **ultrarrápido**.
- **Rede de interconexão da CPU:** liga UC, ULA e registradores.

Memórias: **principal** (RAM, guarda dados e instruções em uso) e **secundária** (armazenamento de longa duração).

### 1.5 Ciclo de instrução: busca → decodificação → execução

| Etapa | O que acontece |
|---|---|
| 1. Busca (Fetch) | A instrução é lida da memória |
| 2. Decodificação (Decode) | A UC identifica o que deve ser feito |
| 3. Execução (Execute) | A ULA realiza a operação |
| 4. Resultado | Encaminhado para armazenamento ou saída (quando necessário) |

**Exemplo do slide, executando 8 + 4:**

```
A1 (endereço)  -> guarda a instrução "ADD 8, 4"
1) A instrução vai para o Registrador de Instrução (dentro da CPU)
2) O decodificador entende: é uma soma
3) A ULA recebe os operandos 8 e 4 e calcula 8 + 4 = 12
```

> 💡 **Dica**: **A1 é o "onde", a instrução é o "o quê", e a ULA é quem faz.** Os números 8 e 4 são **operandos** que fazem parte da instrução armazenada.

**Fluxo de uma calculadora (5 × 3):**

| Etapa | Componente | O que faz |
|---|---|---|
| Entrada | Teclado | Captura 5, ×, 3 |
| Armazenamento | Memória | Guarda dados e instruções |
| Coordenação | UC | Busca, decodifica e direciona |
| Processamento | ULA | Calcula 5 × 3 = 15 |
| Saída | Display | Mostra 15 |

O mesmo raciocínio vale para um editor de texto (digitar é entrada, a frase na tela é saída) e para tocar um vídeo (clicar em *play* é entrada; imagem e som são saída).

### 1.6 Evolução histórica (resumo)

| Marco | Ideia |
|---|---|
| Pascal e Leibniz | Máquinas de calcular mecânicas |
| **Babbage** | Máquina Analítica: programável, já com memória, unidade de computação, entrada e saída |
| 1ª geração | **Válvulas** (ex.: ENIAC) |
| 2ª geração | **Transistores** no lugar das válvulas |
| Circuitos integrados | Maior compactação e desempenho |
| 4ª geração | **VLSI**: grande quantidade de transistores em um único chip |
| Consequência | Computadores menores, mais rápidos e mais acessíveis (miniaturização reduz tamanho, custo e consumo e aumenta o desempenho) |

O slide cita ainda o processamento paralelo como visão de evolução.

> 📝 **Nota**: **Pergunta do slide:** "O que muda quando o programa passa a ser armazenado na memória?" O slide só deixa a pergunta. **Observação minha, não está no slide:** a resposta é que trocar de tarefa passa a ser só carregar outro programa na memória, sem refazer a ligação física da máquina.


---

## 2. Níveis de abstração, linguagens e tradução
*(Fonte: aula03_2_-_Arquitetura_e_Hardware.pdf)*

### 2.1 Conceitos básicos

- **Computador digital:** máquina que resolve problemas executando uma série de instruções (máquina programável).
- **Programa:** sequência de instruções que descreve como realizar uma tarefa.
- **Linguagem de máquina:** conjunto de instruções básicas que os circuitos de um computador reconhecem e executam **diretamente**. É binária, primitiva e complicada para humanos (ex.: somar 2 números, comparar com zero, copiar dados de um lugar da memória para outro).
- **Organização estruturada:** projetar o computador em **níveis de abstração**. Cada nível é construído sobre o nível imediatamente abaixo.

### 2.2 Tradução × Interpretação

Linguagens de alto nível (C, C++, Pascal, Fortran, Java...) precisam virar linguagem de máquina para executar. Há dois métodos:

| | Tradução (compilação) | Interpretação | Híbrido |
|---|---|---|---|
| Como funciona | O programa **inteiro** é convertido para linguagem de máquina e **depois** executado | Cada instrução é examinada, decodificada e **executada na hora** | Mistura os dois |
| Quem faz | Compilador | Interpretador | |
| Exemplos do slide | C, Pascal | Haskell | Java |

### 2.3 Máquina virtual e máquinas de vários níveis

- **Máquina virtual (M1):** abstração capaz de reconhecer e executar diretamente as instruções de uma linguagem L1. Na prática, M1 é um **programa escrito em L0** sendo interpretado por M0.
- Programas em L1 são **traduzidos ou interpretados** por M1.
- Para tradução/interpretação serem práticas, L0 e L1 não devem ser muito diferentes.
- "Uma máquina define uma linguagem. Uma linguagem define uma máquina." Um computador com **n níveis** pode ser visto como **n máquinas virtuais**.
- **Vantagem:** quem programa no nível k **não precisa conhecer** os níveis inferiores. A estrutura em níveis dá flexibilidade e independência.
- A maioria dos computadores modernos tem 2 ou mais níveis (seis ou mais é cada vez mais comum).

### 2.4 Os níveis (de baixo para cima)

| Nível | Nome | O que é |
|---|---|---|
| −1 | Dispositivos | Microeletrônica, transistores, tecnologia de fabricação de circuitos integrados |
| **0** | **Lógica digital** | Hardware. **Portas lógicas** (AND, OR, NOT) combinadas formam funções aritméticas, memórias (registradores) e processadores |
| **1** | **Microarquitetura** | Registradores (8 a 32) + ULA formam o **caminho de dados** (*data path*). Pode haver um **microprograma** que interpreta as instruções do nível 2 |
| **2** | **ISA** (Instruction Set Architecture) | Conjunto de instruções do processador = **linguagem de máquina**. É a verdadeira **interface entre software e hardware**. Discute tipos de dados, modelos de memória e endereçamento, formato das instruções |
| **3** | **Sistema operacional** | Gerência de memória, escalonamento de processos, E/S, interface com o usuário. Roda vários programas ao mesmo tempo |
| **4** | **Linguagem de montagem** (assembly) | Mnemônicos para as instruções. O **montador** traduz |
| **5** | **Linguagens de alto nível** | C, C++, Java... traduzidas por **compiladores** (às vezes interpretadas, como Java) |
| 6+ | Máquinas virtuais voltadas a aplicações | Administração, educação, projeto, realidade virtual etc. |

> 🏆 **Regra de ouro**: **Regra de ouro:** níveis **abaixo** do SO são para programadores **de sistema** (predomina **interpretação**, linguagem numérica boa para a máquina). Níveis **acima** são para programadores **de aplicação** (predomina **tradução**, linguagem com palavras).

> ⚠️ **Atenção**: **Pegadinha:** "Nível ISA" não é o nível 1. ISA = **nível 2**. Microarquitetura = nível 1. Lógica digital = nível 0.

### 2.5 Microprograma × controle por hardware

| | Controle por **software** (microprogramado) | Controle por **hardware** |
|---|---|---|
| O que controla o caminho de dados | Um **microprograma** (interpretador residente em ROM) | Circuitos, sem programa armazenado |
| Típico de | **CISC** | **RISC** |
| Vantagens | Facilita projetar os circuitos; parte da lógica fica no *firmware*; permite instruções mais potentes | Execução direta, mais simples |

Poucas máquinas têm mais de 20 instruções no nível de microarquitetura (a maioria move dados ou faz testes simples).

**Exemplo (instrução ADD):** buscar a instrução na memória → localizar operandos e trazê-los aos registradores → somar na ULA → enviar o resultado ao lugar certo. Com microprograma, um programa guiado controla esses passos. Em hardware, os mesmos passos acontecem sem esse programa.

### 2.6 Hardware, software e firmware

| Termo | Definição |
|---|---|
| **Hardware** | Objetos tangíveis: circuitos integrados, placas, cabos, fontes, memórias, impressoras |
| **Software** | Instruções, algoritmos e suas representações computacionais: os programas |
| **Firmware** | Software **embarcado** no dispositivo na fabricação, que controla o hardware diretamente (ex.: **BIOS**). Em muitos computadores o microprograma está em firmware |

> 📝 **Nota**: **Hardware e software são logicamente equivalentes:** qualquer operação do software pode ser feita em hardware, e qualquer instrução de hardware pode ser simulada por software.

### 2.7 Da linguagem fonte até a execução

```
Programa em alto nível --Compilador--> Assembly --Montador--> Objeto (módulo em ling. de máquina)
                                                                    |
Objeto das bibliotecas (rotinas em ling. de máquina) ----+          |
                                                         v          v
                                                         Ligador (linker)
                                                              |
                                                       Executável
                                                              |
                                                       Carregador (loader) --> Memória --> CPU
```

| Programa | O que faz |
|---|---|
| **Compilador** | Recebe arquivos de texto em alto nível e gera assembly (ou direto arquivos objeto) |
| **Montador** (assembler) | Gera o arquivo objeto a partir do assembly. Em geral **não executa direto**, pois referencia sub-rotinas e dados de outros arquivos (bibliotecas) |
| **Ligador** (linker) | Junta um ou mais objetos e gera o **executável** |
| **Carregador** (loader) | Coloca o programa na memória para executar. Em geral faz parte do SO |
| **Interpretador** | Recebe assembly, alto nível ou binário e **executa diretamente**, comando a comando |

Compilador e montador são **tradutores**. **Processadores são interpretadores implementados em hardware.**

> ⚠️ **Atenção**: **Pegadinha:** o montador **não** gera o executável final. Quem junta tudo e resolve as referências entre arquivos é o **ligador**.


---

## 3. Tipos de computadores, Lei de Moore e hardware × software
*(Fonte: Aula03_3_-_Tipos_de_computadores.pdf e Material_Complementar_Capítulo01_1_DispositivosEquipamentos.pdf)*

### 3.1 Lei de Moore e o círculo virtuoso

- Processadores são circuitos digitais em pastilhas de silício (chips). Reduzir a distância entre os pontos aumenta a velocidade da corrente, então **chips menores = mais rápidos**.
- **Gordon Moore** (ex-presidente do conselho da Intel), anos 60: o progresso na fabricação de chips deveria permitir **dobrar o número de transistores em um chip mais ou menos a cada dois anos**.
- O mesmo slide também diz que o número de transistores **dobra a cada 18 meses**, o que equivaleria a **66,7% ao ano**.

> ⚠️ **Atenção**: **Atenção (divergência no slide):** o texto fala em "dois anos" e depois em "18 meses". Para a prova, repita o que o professor falou. **Observação minha, não está no slide:** os 66,7% ao ano vêm de uma conta linear (100% ÷ 1,5 ano). Em crescimento exponencial, dobrar a cada 18 meses dá cerca de 58,7% ao ano (2 elevado a 12/18).

**Círculo virtuoso** (termo dos economistas): progresso tecnológico → produtos melhores e preços menores → novas aplicações → novos mercados e empresas → concorrência → demanda por tecnologia ainda melhor (o círculo dá a volta completa).

### 3.2 Os 7 tipos de computadores

| # | Tipo | Características do slide |
|---|---|---|
| 1 | **Descartáveis** | Chip **RFID** (identificação por radiofrequência): radiotransponder minúsculo + número de 128 bits. Produtos, animais, veículos, bagagens, pedágio eletrônico |
| 2 | **Microcontroladores** | Computadores **embutidos** em dispositivos que não são vendidos como computadores. Têm processador, memória e E/S, com software em **ROM** gravada na fabricação. Versões de 4, 8, 16 e 32 bits. Carro: ~50; jato: 200 ou mais |
| 3 | **Computadores de jogos** | Computadores normais com recursos gráficos e de som especiais, **software limitado e pouca extensão** (PlayStation 2, Xbox, GameCube) |
| 4 | **Computadores pessoais** | Desktops e notebooks. Coração = placa de circuito impresso (CPU, memória, E/S, interfaces, *slots*) |
| 5 | **Servidores** | Atendem vários usuários ou programas. Arquitetura robusta e **tolerante a falhas**. GBs de memória, centenas de GB de disco, rede rápida, milhares de transações por segundo |
| 6 | **Conjunto de estações de trabalho (clusters)** | PCs ou estações ligados por rede de gigabytes/s, com software especial para trabalharem juntos num problema (*server farm*) |
| 7 | **Mainframes** | Grande porte, vários processadores. Todo o processamento na CPU, com "terminais burros". Novo nicho: comércio eletrônico, grandes bases de dados |

Detalhes do slide:

- **PlayStation 2:** CPU proprietária de 295 MHz com palavras de 128 bits; 32 MB de RAM; chip gráfico de 160 MHz; chip de áudio de 48 canais; leitor de DVD.
- **Tipos de servidor:** banco de dados (armazenamento e processamento), aplicação (execução de programas) e web (sites e aplicações web).
- **Clusters servem para:** servidor web com milhares de requisições por minuto (distribuídas entre os servidores, em paralelo), simulação de colisão de galáxias, síntese de medicamentos, modelagem do fluxo de ar na asa de um avião.
- Servidor com um só processador não é muito diferente de um PC e roda os mesmos SOs (Unix ou Windows).

> ⚠️ **Atenção**: **Pegadinha:** microcontrolador **não é** "um processador sozinho". É um computador **completo e pequeno** (processador + memória + E/S).

### 3.3 Hardware, software, dados e informação (material complementar)

- **Hardware:** componentes físicos (mecânicos, magnéticos, eletrônicos). Quatro categorias: **processador, placa-mãe, memória e dispositivos de E/S**.
- **Processador (UCP/CPU):** principal componente eletrônico, fica na placa-mãe e executa todas as operações com auxílio da memória e da E/S ("cérebro").
- **Memória principal:** acessada **diretamente** pelo processador, alta velocidade e baixa capacidade. É a **RAM** (informações usadas no trabalho do processador) e a **ROM** (instruções de inicialização).
- **Memória secundária:** armazena os dados de forma permanente.
- **Placa-mãe:** interconecta todos os dispositivos. Se o processador é o cérebro, ela é o **"sistema nervoso"**.
- **Software:** parte lógica (dados e instruções passadas ao hardware).

| Software | O que é |
|---|---|
| **Básico** | Essencial ao funcionamento: sistema operacional, BIOS e programas do fabricante |
| **Aplicativo** | Desenvolvido para uma aplicação específica (editor de texto, navegador, reprodutor) |

- **Sistema operacional:** gerencia a comunicação entre componentes, entre aplicativos e entre estes e o usuário.
- **BIOS:** primeiro programa executado ao ligar. Reconhece o hardware, verifica se tudo funciona e passa o comando ao SO, informando sobre o hardware.

| Conceito | Definição |
|---|---|
| **Dado** | Elemento básico da informação, um registro (ex.: nome do funcionário, horas trabalhadas, peças em estoque) |
| **Informação** | Resultado do processamento dos dados |
| **Processamento** | O computador transforma dados em informação pelo hardware + software |

> 📝 **Nota**: **Dados** são a matéria-prima. **Informação** é o resultado depois de processar.


---

## 4. Processadores: componentes, tipos e linha do tempo
*(Fonte: Oque_é_Processador.pdf e Aula_-_Processadores_E_Tendência.pdf)*

### 4.1 O que é e o que faz

O **microprocessador** (processador, **CPU** ou **UCP**) é um microchip especializado, um circuito integrado que realiza **cálculo e tomada de decisão**. Funções:

- Realiza operações aritméticas e comparações lógicas.
- A **unidade de controle** interpreta e gerencia a execução de cada instrução.
- Administra, na memória principal, o programa e os dados transferidos entre os elementos da máquina.
- Recebe dados e comandos do usuário, processa conforme as instruções armazenadas e fornece resultados.
- Opera com números e símbolos em **binário** e passa informações à placa-mãe, que as leva a monitor, impressora etc. (a placa-mãe é a "ponte" entre o processador e o resto).

Fabricação (resumo do slide): camada de silício de extrema pureza, laminada, mascarada por processo fotográfico e dopada em fornos com misturas gasosas. O processo se repete até formar a microarquitetura.

### 4.2 Características e componentes internos

| Item | O que é |
|---|---|
| **Frequência (clock)** | Medida em hertz. Define a capacidade de processar informações |
| **Cores (núcleos)** | Processador *core* (um núcleo) ou *multicore* (vários na mesma peça) |
| **Cache** | Memória auxiliar que reduz o tempo de transmissão entre o processador e outros componentes |
| **Potência** | Medida em watts: energia consumida por segundo. **1 W = 1 J/s** |
| **ULA** | Realiza as operações matemáticas pedidas pelo programa |
| **Unidade de Controle** | O mais próximo de um "cérebro" dentro do processador: define o regime de funcionamento e a ordem das tarefas |
| **Registradores** | Pequenas memórias velozes. Os mais importantes: **PC** (Contador de Programa: aponta a próxima instrução) e **IR** (Registrador de Instrução: registra a instrução em execução) |
| **Unidade de Ponto Flutuante** | Calcula com números enormes (64, 128 bits, por exemplo) |
| **MMU** (Memory Management Unit) | Hardware que transforma **endereços virtuais em físicos** e administra a memória principal |

> ⚠️ **Atenção**: **Pegadinha:** PC aqui é **Program Counter** (contador de programa), não "computador pessoal".

### 4.3 Tipos de processadores

| Tipo | Características | Exemplos | Aplicações |
|---|---|---|---|
| **CISC** | Conjunto de instruções complexo e amplo; várias operações em uma instrução; mais ciclos de clock por instrução; uso eficiente de memória, mas pode gastar mais energia | Intel x86, AMD Athlon | Computadores de uso geral, servidores |
| **RISC** | Conjunto reduzido e simples; cada instrução faz uma operação simples; menos ciclos por instrução; melhor desempenho em alta velocidade | ARM, IBM PowerPC | Dispositivos móveis, sistemas embarcados |
| **ARM** | RISC com **alta eficiência energética**; múltiplos núcleos | Apple M1, Qualcomm Snapdragon | Smartphones, tablets, IoT |
| **x86** | Arquitetura CISC; instruções complexas e várias operações simultâneas | Intel Core i7, AMD Ryzen | Desktops, laptops, servidores |
| **Multicore** | Vários núcleos no mesmo chip; paralelismo; melhor em multitarefa | Intel Core i9, Ryzen Threadripper | Alta performance, servidores, desktops |
| **FPGA** | Programável **após a fabricação** pelo usuário; alta flexibilidade | Xilinx Virtex, Intel Stratix | Aplicações industriais, comunicação, criptografia |
| **Propósito específico** | Projetados para funções específicas: GPU, DSP | NVIDIA GeForce (GPU), TI TMS320 (DSP) | Jogos, imagem, áudio |

### 4.4 Linha do tempo dos processadores

| Ano | Processador | Destaques do slide |
|---|---|---|
| 1971 | **Intel 4004** | **Primeiro microprocessador**, para calculadoras. 4 bits, 2.300 transistores, clock máx. 740 kHz, 92 mil instruções/s (~11 µs por instrução) |
| 1973 | Intel 8008 | CPU de 8 bits, ~3.500 transistores. O nome veio de marketing (dobro do 4004) |
| 1974 | **Intel 8080** | **Primeiro voltado a computadores pessoais** (usado no Altair 8800). 8 bits, 290 mil operações/s, ~10× o 8008 |
| 1978 | **Intel 8086** | **Primeira CPU de 16 bits**, 29.000 transistores, 10× o 8080. Base da arquitetura **x86** |
| 1979 | Intel 8088 | Versão do 8086 com **barramento externo de 8 bits**. Escolhido para o primeiro PC da IBM |
| 1982 | Intel 80286 (286) | 16 bits, 134.000 transistores, até 12 MHz, compatível com o software anterior, multitarefa e proteção de dados |
| 1985 | **Intel 386** | **32 bits**, 275.000 transistores, 33 MHz, 5 MIPS |
| 1988 | 386SX ("386 Lite") | Mais barato, 2,5 a 3 MIPS, roda software de 32 bits |
| 1989 | **Intel 486** | 1,2 milhão de transistores, 50 MHz. **Primeiro com coprocessador matemático integrado e cache L1** |
| 1993 | **Pentium** | ~3,1 milhões de transistores (CMOS 0,8 µm), 66 MHz até 233 MHz, ~112 MIPS, duas caches de 8 KB e unidade de ponto flutuante integrada. **Introduziu o conceito superescalar** |
| 1995 | Pentium Pro | Voltado a servidores, 5,5 milhões de transistores, 200 MHz, **cache L2**, tecnologia de 0,35 µm |
| 1997 | Pentium II | 7,5 milhões de transistores (0,25 µm), tecnologia **MMX** (SIMD) e cache de alta velocidade |
| 1998 | Pentium II Xeon | Servidores e estações de trabalho: 4, 8 ou mais processadores |
| 1999 | Pentium III | 70 novas instruções (gráficos 3D, áudio, vídeo), 9,7 milhões de transistores, até 500 MHz |
| 2000 | Pentium 4 | 42 milhões de transistores, 1,5 GHz nas primeiras versões |
| 2001–2006 | **64 bits** | **AMD64 (x86-64)** venceu; Itanium (Intel, do zero) não. Athlon 64 foi o primeiro de 64 bits. Intel licenciou o x86-64 |
| 2005 | Pentium D, Athlon 64 X2 | Primeiros **multicore**: dois núcleos no mesmo chip. A AMD usava **HyperTransport** (ponto a ponto, baixa latência) |
| 2005–2006 | Core 2 Duo, Core 2 Quad, Phenom X4 | Intel abandona a marca Pentium. Chips com 4 núcleos (45 nm) |
| 2007 | **Core i3** | Controlador de memória interno. 2 núcleos físicos + 2 virtuais (**Hyper-Threading**), 32 nm, gráfico integrado |
| 2007 | **Core i5** | Microarquitetura **Nehalem**, soquete LGA 1156, controlador de memória embutido, **sem SMT** (segundo o slide) |
| 2008 | **Core i7** | Primeiro com Nehalem. 8 MB de cache, memória até 1066 MHz em **Triple Channel** |

**AMD:** K5 (1995, primeira arquitetura independente, soquete compatível com x86); K6 e K6-2 (SIMD, Super Socket 7, barramento externo de 100 MHz); **Athlon (1999)**, o primeiro acima de **1 GHz**; Am286/386/486 como concorrentes diretos.

> ⚠️ **Atenção**: **Atenção (os slides se contradizem):** o 8080 aparece com **4.800 transistores** (slide "O que é Processador") e com **6.000 transistores e 2 MHz** (slide "Tendências"). O 8086 aparece com 8 MHz e com 5 a 10 MHz. O Pentium aparece com 66 MHz (primeiras versões) e com 60 MHz de clock inicial. Os anos de i3/i5 (2007) também vêm do slide. Na dúvida, siga o número que o professor passou em aula.

### 4.5 Fabricantes

| Empresa | Fundadores | Sede | Observação do slide |
|---|---|---|---|
| **Intel** | Gordon Moore e Robert Noyce | Santa Clara, Califórnia | Principalmente microprocessadores. Slogan "Leap ahead" |
| **AMD** | W. Jerry Sanders III e Edwin J. Turney | Sunnyvale, Califórnia | Concorre diretamente com a Intel. Slogan "The future is fusion" |
| **IBM** | Herman Hollerith (procedência não exata) | Armonk, Nova York | Hardware e software |

### 4.6 Evolução e tendências (slide "Tipos de Processadores")

| Fase | Ideia |
|---|---|
| Anos 1970 | 4004 (4 bits, 740 kHz) e 8080 (8 bits) |
| 1978 | 8086, 16 bits, base do x86 |
| Anos 1980 | Conceito **RISC** (ARM, MIPS): simplicidade e eficiência |
| 1993 | Pentium: **superescalar**, várias instruções por ciclo |
| Anos 2000 | **Multicore**: Core Duo (2006), AMD Ryzen (2017) |
| 2000 em diante | **ARM** domina os dispositivos móveis (Apple A-series, Snapdragon) |
| 2010–2020 | Processadores com **NPU** (unidade de processamento neural) para IA: Apple M1/M2, TPU do Google |
| Tendência | **Arquiteturas híbridas** (núcleos de alta performance + de alta eficiência; Intel Alder Lake, 2021) e **computação quântica** (qubits; desafios de escala e correção de erros) |


---

## 5. CISC × RISC
*(Fonte: Arquiteturas_RISC-CISC.pdf (com apoio de aula03_2 e Aula_-_Processadores_E_Tendência.pdf))*

### 5.1 Definições

| | **CISC** | **RISC** |
|---|---|---|
| Significa | Complex Instruction Set Computing | Reduced Instruction Set Computing |
| Ideia | Muitas instruções com diferentes níveis de complexidade | Poucas instruções, **simples e rápidas** |
| Instruções | Uma instrução pode fazer várias tarefas | Cada instrução faz uma operação simples |
| Endereçamento | **Mais** modos de endereçamento | Menos modos |
| Latência / ciclos | Maior latência, mais ciclos por instrução | Poucos ciclos (às vezes **um** só) por instrução |
| Tamanho do código | **Menor** (menos linhas de baixo nível) | **Maior** (mais instruções para a mesma tarefa) |
| Pipeline | Mais difícil (instruções de tamanho/duração variáveis) | **Aproveita melhor** (uniformidade e simplicidade) |
| Controle (aula03_2) | Em geral **microprogramado** | Em geral **por hardware** |
| Exemplos | x86 (Intel e AMD): 8086, 80186, 80286, 386, 486 | ARM, MIPS, PowerPC, SPARC |
| Onde é comum | PCs, servidores | Celulares, embarcados, roteadores, consoles |

> 🏆 **Regra de ouro**: **Regra de ouro:** CISC = hardware faz **mais**, código **menor**. RISC = hardware faz **menos por instrução**, código **maior**, mas cada instrução é rápida e combina melhor com **pipeline**.

> ⚠️ **Atenção**: **Pegadinha (ponto de atenção do slide):** não existe "RISC sempre ganha". O slide diz que a comparação **depende da aplicação**: RISC rende bem em muito volume de instruções simples, CISC pode ter vantagem em instruções complexas e diversificadas. Conta também a **implementação**, as otimizações de hardware e o software.

### 5.2 Exemplo prático: multiplicar dois números

O slide usa pseudocódigo (uma instrução × várias). **Observação minha, não está no slide:** o exemplo clássico, para visualizar a diferença, é este:

```
CISC (1 instrução, a própria instrução acessa a memória):
    MULT  A, B          ; A <- A * B

RISC (várias instruções simples, só LOAD/STORE acessam a memória):
    LOAD  R1, A         ; R1 <- memória[A]
    LOAD  R2, B         ; R2 <- memória[B]
    MUL   R1, R2        ; R1 <- R1 * R2
    STORE A, R1         ; memória[A] <- R1
```

CISC: código curto, instrução demorada. RISC: código mais longo, cada passo simples e fácil de encadear no pipeline.

### 5.3 x86 e x86-64

- **x86** (ou 80x86) é o nome genérico da família baseada no **Intel 8086**. O nome vem de que os primeiros processadores terminavam em "86": 8086, 80186, 80286, 80386, 80486.
- O slide diz que a Intel usa x86 e a AMD usa **x86-64**, uma versão **ampliada** do x86 que acessa **mais memória** e executa mais tarefas. Hoje os processadores de 64 bits rodam sobre o padrão **x86-64 da AMD** (licenciado à Intel).

### 5.4 Famílias RISC citadas

| Arquitetura | O que o slide diz |
|---|---|
| **ARM** (Advanced RISC Machines) | Muito difundida e versátil: smartphones, tablets, embarcados. **Eficiência energética** e arquitetura **modular** |
| **MIPS** (Microprocessor without Interlocked Pipeline Stages) | Projeto simples e eficiente: roteadores, consoles, embarcados. Usa **32 registradores** (alguns reservados à própria máquina). RISC clássico + pipeline |
| **PowerPC** | Aliança **IBM, Motorola e Apple**. Série RS/6000 (fev. 1990). Linha Macintosh de **1994 a 2006**. Baseado no 801. Inclui unidade de ponto flutuante e **pipeline**. Desde 2006 evolui como **Power ISA**, com versões de 32 e 64 bits |
| **SPARC** (Scalable Processor ARChitecture) | Arquitetura **aberta** da **Sun** (~1987), hoje Oracle. UltraSPARC; licenciada para outros (ex.: Fujitsu). Servidores de alto desempenho e embarcados críticos |

### 5.5 Aplicações e tendências do RISC

- **Móveis:** ARM em smartphones, tablets e embarcados (eficiência energética = bateria maior).
- **Supercomputadores:** execução eficiente de instruções e pipeline ajudam no processamento paralelo (pesquisa científica, simulação climática, modelagem molecular).
- **Servidores e data centers:** eficiência energética, escalabilidade e flexibilidade.
- **Tendências:** transistores menores e novos materiais, litografia **EUV** (Extreme Ultraviolet), melhor design de pipeline, novas técnicas de **predição de desvios**, melhor gestão de cache e **IA integrada** aos processadores.


---

## 6. Sistemas digitais e portas lógicas
*(Fonte: AULA14__SISTEMAS_DIGITAIS.pdf e Aula14_PORTAS_LOGICAS.pdf (Prof. Edgar Zuim))*

### 6.1 Sistema digital e níveis lógicos

Um **sistema digital** é binário: cada dígito tem só **2 valores**, chamados **níveis lógicos**, **0** ou **1** (no decimal, cada dígito tem 10). No circuito eles viram sinais elétricos:

| Nível lógico 0 | Nível lógico 1 |
|---|---|
| FALSO | VERDADEIRO |
| Desligado / nível baixo | Ligado / nível alto |
| Zero / **Terra (GND)**, ausência de tensão | **VCC**, tensão aplicada (normalmente **5 V** em CIs da família TTL) |

Todas as operações lógicas vêm de **3 operações primárias**: **inversão (NOT)**, **soma lógica (OR)** e **produto lógico (AND)**.

- **Porta lógica:** circuito com **uma só saída** e **duas ou mais entradas**. Só aparece sinal na saída para certa combinação de entradas ("ajuda a tomar uma decisão lógica").
- **Tabela-verdade:** técnica para mostrar como a saída depende dos níveis nas entradas. Com **n entradas** há **2ⁿ linhas** (2 entradas = 4 linhas; 3 entradas = 8 linhas).

### 6.2 As portas

| Porta | Símbolo/expressão | Regra | Analogia |
|---|---|---|---|
| **AND** (E) | X = A · B (ou AB) | Saída **1 só se todas** as entradas forem 1. Saída 0 se **ao menos uma** for 0 | Interruptores em **série**: a lâmpada acende se os dois estiverem ligados |
| **OR** (OU) | X = A + B | Saída **1 se pelo menos uma** entrada for 1. Saída 0 só se **todas** forem 0 | Interruptores em **paralelo**: acende se um estiver ligado |
| **NOT** (NÃO) | X = A com barra (complemento) | **Inverte** a entrada (0 vira 1, 1 vira 0). Só tem **1 entrada** | Inversor |
| **NAND** | AND + inversão | Saída **0 só se todas** as entradas forem 1 | |
| **NOR** | OR + inversão | Saída **1 só se todas** as entradas forem 0 | |
| **XOR** (OU exclusivo) | soma lógica com círculo | Saída **1 se as entradas forem diferentes**. 0 se iguais | |
| **XNOR** | XOR + inversão | Saída **1 se as entradas forem iguais**. É o inverso do XOR | |

**Símbolos das portas (como nos slides):**

> 🖼️ *Figura (no HTML):* símbolos das 7 portas com tabelas-verdade. Em texto: AND `A·B` · OR `A+B` · NOT `Ā` · NAND `(A·B)̅` · NOR `(A+B)̅` · XOR `A⊕B` · XNOR `(A⊕B)̅`. A bolinha na saída do símbolo indica inversão.

**Tabela-verdade conjunta (2 entradas):**

| A | B | AND | OR | NAND | NOR | XOR | XNOR |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 | 0 | 1 | 0 |
| 1 | 0 | 0 | 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 | 1 |

> 💡 **Dica**: **Como reconhecer na prova:** AND = "tudo ou nada" (só a linha 11 dá 1). OR = só a linha 00 dá 0. XOR = 1 quando as entradas **diferem**. NAND e NOR são o AND e o OR **invertidos** (a coluna fica ao contrário).

> ⚠️ **Atenção**: **Pegadinha:** a porta **OR** tem nome de "soma" (+), mas **1 + 1 = 1** em lógica (não é 2). A porta AND é o "produto" (·).

**NAND e NOR são “AND/OR + NOT”:**

> 🖼️ *Figura (no HTML):* **NAND = AND seguida de NOT** e **NOR = OR seguida de NOT**.

**Analogia dos interruptores e da lâmpada (slides de AND e OR):**

> 🖼️ *Figura (no HTML):* **AND = dois interruptores em série** (a lâmpada acende só se A e B estiverem fechados). **OR = em paralelo** (acende se A ou B estiver fechado).

### 6.3 Portas com mais de 2 entradas

- **AND com 3 entradas:** X = A · B · C. A saída só é 1 na linha 111 (das 8 linhas, só 1 dá 1).
- **OR com 3 entradas:** X = A + B + C. A saída só é 0 na linha 000.
- Uma OR de 3 entradas pode ser feita com **duas OR de 2 entradas**: X = (A + B) + C = A + B + C.
- Regra do OR: "saída FALSA se, e somente se, **todas** as entradas forem FALSAS".

> 🖼️ *Figura (no HTML):* portas AND e OR de 3 entradas. AND dá 1 só em 111; OR dá 0 só em 000.

> 🖼️ *Figura (no HTML):* OR de 3 entradas feita com duas ORs de 2 entradas: `X = (A + B) + C`.

### 6.4 Associação de portas e análise de circuitos

Combinando portas, obtemos circuitos mais complexos e escrevemos a **expressão booleana** da saída diretamente.

- **Exemplo do slide (OR):** três portas OR, P1 e P2 recebem (A,B) e (C,D), P3 recebe as saídas S1 e S2. X = (A + B) + (C + D). O circuito se comporta como **uma OR de 4 entradas**.
- **Exemplo (AND/OR misto):** P1 = OR, P2 = AND, P3 = AND. A saída X depende da **última porta (P3)**, mas só depois de calcular S1 e S2.

```
Como analisar um circuito:
1) Calcule a saída de cada porta da 1ª camada (S1, S2...).
2) Use essas saídas como entradas da próxima porta.
3) A saída da última porta é X.

Ex.: A=0, B=0, C=0, D=1 em X = (A+B) + (C+D)
     S1 = 0+0 = 0     S2 = 0+1 = 1     X = 0+1 = 1
```

**Circuitos dos slides (P1, P2, P3):**

> 🖼️ *Figuras (no HTML):* à esquerda `X = (A+B)+(C+D)` com P1, P2 e P3 sendo ORs; à direita o circuito misto com P1 = OR, P2 = AND e P3 = AND, `X = (A+B)·(C·D)`.

Tabela do circuito misto (8 linhas do slide): `S1 = A+B`, `S2 = C·D`, `X = S1·S2`.

| A | B | C | D | S1 | S2 | X |
|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 | 1 | 1 |
| 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 1 | 0 | 0 |

> 🖼️ *Figura (no HTML):* NAND (entradas A e B) → saída C → OR junto com D → saída E. Logo `E = C + D = (A·B)̅ + D`.

### 6.5 Teorema de De Morgan

| Afirmação do slide | Em símbolos (barra = inversão) |
|---|---|
| **NAND** = **OR** com todas as entradas **invertidas** | não(A · B) = (não A) + (não B) |
| **NOR** = **AND** com todas as entradas **invertidas** | não(A + B) = (não A) · (não B) |

Serve para **simplificar expressões lógicas** de circuitos digitais.

> 🖼️ *Figura (no HTML):* **NAND = OR com entradas invertidas** (`(A·B)̅ = Ā + B̄`) e **NOR = AND com entradas invertidas** (`(A+B)̅ = Ā · B̄`).

### 6.6 Portas em Verilog (linguagem de descrição de hardware)

```
module exemplo_AND ( A, B, C );   // AND:  assign C = A & B;
  input wire A, B;
  output wire C;
  assign C = A & B;
endmodule
```

| Porta | Operador Verilog |
|---|---|
| AND | `&` |
| OR | `|` |
| NAND | `~&` |
| NOR | `~|` |
| XOR | `^` |
| XNOR | `~^` |

> 📝 **Nota**: Os operadores `&`, `|` e `^` são os mesmos que você usa em **C** para operações **bit a bit**. Isso conecta com as **máscaras AND** e os **deslocamentos** da seção sobre operações lógicas.

### 6.7 Circuitos integrados comerciais e tarefa

- **CI MM74HC08:** reúne várias portas **AND** de 2 entradas.
- **CI MM74HC04:** reúne várias portas **NOT** (6 inversores).
- **CI MM74HC32:** o CI genérico do slide "Exemplos" reúne 4 portas **OR** (observação minha: o número HC32 aparece só na foto do chip).
- **Tarefa do slide:** pesquisar simuladores de portas lógicas, testar as entradas, identificar AND, OR, NOT e XOR e mostrar exemplos práticos.
- Referência de nível no modelo de camadas: portas lógicas são o **nível 0 (lógica digital)** da seção 2. Combinadas, formam funções aritméticas, registradores e processadores.

**Pinagem dos CIs (desenho dos slides redesenhado):**

> 🖼️ *Figuras (no HTML):* pinagem dos CIs de 14 pinos (esquema simplificado).

| Pino | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| **MM74HC08** (AND) / **MM74HC32** (OR) | A1 | B1 | Y1 | A2 | B2 | Y2 | GND | Y3 | A3 | B3 | Y4 | A4 | B4 | VCC |
| **MM74HC04** (NOT) | A1 | Y1 | A2 | Y2 | A3 | Y3 | GND | Y4 | A4 | Y5 | A5 | Y6 | A6 | VCC |


---

## 7. Conjunto de instruções (parte 1A): formato, bits e endereços
*(Fonte: 12_AULA_conjunto-de-instrucao-parte-1a.pdf (slides só em imagem, lidos por OCR e conferidos visualmente))*

### 7.1 O que é o conjunto de instruções

- É a **coleção completa de instruções que a CPU executa**. Em linguagem de máquina, cada instrução é uma **sequência de bits**.
- É a **fronteira de projeto**: a interface entre quem **projeta a CPU** e quem **programa**. Um bom conjunto facilita a implementação.

| | Assembly | Alto nível |
|---|---|---|
| Exemplo | `ADD A, B` | `A = B + C` (uma linha) |
| Tradução | O **montador** traduz **1 para 1** | O **compilador** traduz **1 para N** (uma linha vira várias instruções) |

> ⚠️ **Atenção**: **Pegadinha:** assembly é **1 instrução simbólica ↔ 1 instrução de máquina**. Alto nível é **1 linha ↔ várias instruções de máquina**.

### 7.2 Elementos de uma instrução

Quatro campos (o slide chama de "cartão"):

| Campo | Função |
|---|---|
| **Opcode** | Define a **operação** |
| **Operando fonte** | De onde vem o dado (pode ser 1 ou mais) |
| **Operando destino** | Onde vai o resultado |
| **Referência à próxima instrução** | De onde buscar a seguinte (em geral **implícita**: é a instrução seguinte na memória) |

Uma instrução é um **padrão de bits**. O padrão é o código (`10110010`) e o símbolo (`ADD R1, R2`) só ajuda a leitura. No formato, o tamanho dos campos de operando pode variar (**opcode + campos de operando**).

### 7.3 Ciclo de instrução (5 etapas)

```
1 Busca  ->  2 Decodificação  ->  3 Busca de operandos  ->  4 Execução  ->  5 Armazenamento
   ^                                                                              |
   +------------------------------ retorno à busca -------------------------------+
```

**Onde ficam os operandos?** Em um destes três lugares: **memória**, **registrador** ou **dispositivo de E/S**.

> 📝 **Nota**: Compare com o ciclo da seção 1 (busca, decodificação, execução, resultado). Aqui o slide detalha a **busca de operandos** como etapa própria.

### 7.4 Bit, byte, palavra e quantos valores cabem

| Unidade | Tamanho |
|---|---|
| 1 bit | 0 ou 1 |
| 1 byte | **8 bits** (n bytes = 8n bits) |
| Palavra | **16 bits** (neste material) |
| Dupla | 32 bits |
| Quádrupla | 64 bits |

- **n bits → 2ⁿ padrões** diferentes. Sem sinal: de **0 a 2ⁿ − 1**.
- 8 bits: **256** valores. 16 bits: **65.536** valores.
- **Complemento de 2** (com sinal): faixa de **−2ⁿ⁻¹ a 2ⁿ⁻¹ − 1**. Em 16 bits: **−32.768 a 32.767** (um negativo a mais que positivos).

> 🏆 **Regra de ouro**: **Regra de ouro:** cada bit a mais **dobra** a quantidade de valores. Sem sinal em 8 bits: 0 a 255. Com sinal (complemento de 2) em 8 bits: −128 a 127.

### 7.5 Exemplo do slide: o número 374 de três jeitos

**Em binário (divisões sucessivas por 2, lendo os restos de baixo para cima):**

```
374 / 2 = 187  resto 0
187 / 2 =  93  resto 1
 93 / 2 =  46  resto 1
 46 / 2 =  23  resto 0
 23 / 2 =  11  resto 1
 11 / 2 =   5  resto 1
  5 / 2 =   2  resto 1
  2 / 2 =   1  resto 0
  1 / 2 =   0  resto 1      -> lendo de baixo p/ cima: 101110110  (9 bits)

Em 16 bits: 0000 0001 0111 0110   =  0x0176
```

**BCD** (decimal codificado em binário), cada dígito decimal vira seu código:

| Forma | Tamanho | 374 fica |
|---|---|---|
| BCD **desempacotado** (1 dígito por byte) | 3 bytes | `00000011  00000111  00000100` |
| BCD **empacotado** (2 dígitos por byte) | 2 bytes | `00000011  01110100` (3 no primeiro byte; 7 e 4 no segundo) |

**O mesmo 374 em três tamanhos:** número puro = **9 bits**, BCD = **16 bits**, texto ASCII = **24 bits** (3 caracteres × 8 bits).

> ⚠️ **Atenção**: **Pegadinha:** o **caractere '6'** não é o **número 6**:
> número 6 = `00000110`; **ASCII** '6' = `00110110`; **EBCDIC** '6' = `11110110`.
> Para extrair o valor do dígito use **AND com `00001111`**: dá `00000110` nos dois casos.

### 7.6 Máscara AND: separar dígitos de uma palavra

Palavra de 16 bits com dois caracteres ASCII ('3' e '7'): `00110011 00110111`.

```
Primeiro caractere:   palavra  00110011 00110111
                      máscara  11111111 00000000   (AND)
                      resultado 00110011 00000000
                      deslocar 8 posições à direita -> 00000000 00110011

Segundo caractere:    palavra  00110011 00110111
                      máscara  00000000 11111111   (AND)
                      resultado 00000000 00110111  (já está na posição certa)
```

Cada caractere vai então para a E/S. A conta de custo está na seção 10.

### 7.7 Quantos endereços tem uma instrução?

| Formato | Significado | Característica do slide |
|---|---|---|
| **4 endereços** | O1, O2 (entradas), O3 (saída), O4 (próxima instrução) | O endereço da próxima costuma ser **implícito** |
| **3 endereços** | `ADD A, B, C` significa **A = B + C** | Raro em CISC. **Padrão em ARM, MIPS e RISC-V** |
| **2 endereços** | `ADD A, B` significa **A = A + B** | Instrução menor, **mais instruções** no programa |
| **1 endereço** | `ADD B` significa **ACC = ACC + B** | Usa o **acumulador**. Comum no IAS |
| **0 endereços** | Operandos **implícitos** | Operações na **pilha** (modelo de pilha) |

**A mesma conta, três codificações: Y = (A − B) ÷ (C + D × E)**

```
3 endereços (4 instruções)    2 endereços (7 instruções)    1 endereço (10 instruções)
SUB T, A, B                   MOV T, A                      LOAD  A
MUL U, D, E                   SUB T, B                      SUB   B
ADD U, C, U                   MOV U, D                      STORE T
DIV Y, T, U                   MUL U, E                      LOAD  D
                              ADD U, C                      MUL   E
                              DIV T, U                      ADD   C
                              MOV Y, T                      STORE U
                                                            LOAD  T
                                                            DIV   U
                                                            STORE Y
```

| Mais endereços | Menos endereços |
|---|---|
| Instruções **maiores** | Instruções **primitivas** |
| Programas **menores** | Ciclo **rápido** |

Arquiteturas modernas usam **2 ou 3** endereços.

> 🏆 **Regra de ouro**: **Regra de ouro:** mais endereços por instrução = **instrução mais longa e programa mais curto**. Menos endereços = **instrução curta e programa mais longo**.


---

## 8. Tipos de dados e classes de operação (parte 1B)
*(Fonte: 12_AULA_tipos-de-dados-e-operacoes-parte-1b.pdf (slides só em imagem, lidos por OCR e conferidos visualmente))*

### 8.1 Representação: um padrão, vários significados

Os **bits não determinam sozinhos a interpretação**. O mesmo padrão `00000110` pode ser o **número 6** ou um **código** (caractere). Quem decide é a **instrução/operação** que o usa: o **tipo é definido pelas operações de manipulação**, não só pelo tamanho. O mesmo conteúdo pode servir à operação A ou à operação B.

### 8.2 Endianness: a ordem dos bytes na memória

É a ordem em que os **bytes de um valor** ocupam **endereços consecutivos**. Exemplo do slide: o valor **12345678h** (4 bytes) guardado a partir do endereço 184.

| Endereço | 184 | 185 | 186 | 187 |
|---|---|---|---|---|
| **Big-endian** (byte mais significativo no menor endereço) | 12 | 34 | 56 | 78 |
| **Little-endian** (byte menos significativo no menor endereço) | 78 | 56 | 34 | 12 |

- **Endereço = base + índice.**
- **Bi-endian:** a máquina aceita os dois formatos.
- Sem consenso. Big-endian: **acelera a comparação de sequências de caracteres**. Little-endian: **facilita a aritmética de alta precisão**.

| Little-endian | Big-endian |
|---|---|
| Pentium, 80x86, VAX | IBM 370, Motorola 680x0, boa parte das RISC |

> 💡 **Dica**: **Macete:** **Big** = o "grande" (mais significativo) vem **primeiro**, como lemos o número. **Little** = o "pequeno" vem primeiro (os bytes aparecem de trás para a frente).

> ⚠️ **Atenção**: **Pegadinha:** a ordem inverte os **bytes**, não os **bits** dentro de cada byte. `78 56 34 12` mantém cada byte intacto.

### 8.3 Convenções do Pentium

| Tamanho | Nome no slide |
|---|---|
| 8 bits | Byte |
| 16 bits | Palavra |
| 32 bits | Palavra dupla |
| 64 bits | Palavra quádrupla |

Convenções: endereçamento **por byte**, disposição **little-endian**, **sem exigência de alinhamento** em múltiplos de 4.

### 8.4 Tipos de dados

| Tipo | Como se interpreta |
|---|---|
| **Geral** | Conteúdo binário arbitrário |
| **Inteiro** | Complemento de 2 (com sinal) |
| **Ordinal** | Sem sinal |
| **BCD** | Dígitos decimais codificados: **desempacotado** (1 dígito por byte) ou **empacotado** (2 por byte) |
| **Ponteiro** (near) | **32 bits** |
| **Campo de bits** | Cada posição é independente |
| **Sequência** | Bytes, palavras ou duplas |

### 8.5 Ponto flutuante (IEEE 754)

Uma "etiqueta" de bits dividida em **três campos**: **sinal | expoente | significando** (mantissa).

| Formato | Sinal | Expoente | Significando | Viés do expoente |
|---|---|---|---|---|
| **Simples** (32 bits) | 1 | 8 | 23 | **127** |
| **Dupla** (64 bits) | 1 | 11 | 52 | **1023** |
| **Estendida** | | | | Faixa até **10⁴⁹³²** |

```
valor = (-1)^S  x  1,M  x  2^(E - viés)        (viés = 127 na precisão simples)
```

O expoente **desloca a vírgula binária**. Dupla e estendida dão **mais precisão e faixa**.

**Exemplo (observação minha, não está no slide):** simples com S = 0, E = 10000010 (130), M = 0100...0:
valor = +1 × 1,01₂ × 2^(130 − 127) = 1,25 × 2³ = **10**.

| Representação | O que define o formato |
|---|---|
| Inteiro | Complemento de 2 |
| BCD | Dígitos decimais codificados |
| Ponto flutuante | Sinal, expoente e significando (simples, dupla, estendida) |

### 8.6 As 7 classes de operação (3 grupos)

| Grupo | Classes |
|---|---|
| **1. Mover** | **Transferência de dados**; **Entrada e saída** |
| **2. Transformar** | **Aritméticas**; **Lógicas**; **Conversão** |
| **3. Direcionar** | **Controle de sistema**; **Transferência de controle** |

- Os **opcodes mudam entre máquinas**, mas as **classes permanecem**. As opções variam (máquinas A, B e C).
- Aritméticas e lógicas operam sobre **registradores**.

### 8.7 Transferência de dados

Uma instrução de transferência especifica **quatro aspectos**: **origem**, **destino**, **tamanho** e **modo de endereçamento**.

Quando envolve **memória**, o processador precisa: (1) **determinar o endereço**, (2) **converter virtual em real**, (3) **verificar a cache**.

Comparação do slide: no **IBM 370** há **instruções distintas** para cada movimento (o tipo fica no opcode); no **VAX** há **uma só instrução**, e a especificação fica no operando.

### 8.8 Operações aritméticas

Fluxo (slide "fluxo aritmético"):

1. **Transferência** antes ou depois (dados vão ao/vêm do registrador).
2. **Execução na ULA.**
3. **Atualização dos códigos de condição** (flags).

Operações mais comuns: **soma, subtração, multiplicação, divisão**; **INC** (incremento), **DEC** (decremento), **negação** (−x) e **valor absoluto** (|x|).


---

## 9. Operações lógicas, deslocamento, controle e E/S (parte 2)
*(Fonte: 13_AULA_arquitetura-e-organizacao-de-computadores-parte-2.pdf (slides só em imagem, lidos por OCR e conferidos visualmente))*

### 9.1 Operações lógicas e para que servem

As quatro operações (NOT, AND, OR, XOR) agem **bit a bit** e usam as mesmas tabelas das portas da seção 6. No conjunto de instruções elas servem para três coisas:

| Uso | O que faz |
|---|---|
| **Mascarar** | Zerar bits que não interessam |
| **Isolar** | Deixar passar **só os bits selecionados** (a máscara é uma "peneira") |
| **Testar** | Verificar se certos bits valem 0 ou 1 |

> 📝 **Nota**: Máscara AND passo a passo: seção 7.6. Exercício completo com custo: seção 10.5.

### 9.2 Deslocamento e rotação

| Operação | O que faz | Exemplo (8 bits) |
|---|---|---|
| **Deslocamento lógico** | Um bit sai e **um zero entra** | `00110110` desloca à esquerda → `01101100` |
| **Deslocamento aritmético** | Preserva o **bit de sinal** (a posição mais significativa fica protegida) e desloca os demais | |
| **Rotação** | O bit que sai de uma ponta **volta pela outra**; **nenhum bit é perdido**. Útil para testar bits | |

> ⚠️ **Atenção**: **Pegadinha:** deslocamento **lógico** descarta o bit que sai e entra zero. **Rotação** não perde nada. **Aritmético** protege o **sinal**.

**Observação minha, não está no slide:** deslocar 1 posição à esquerda equivale a multiplicar por 2 (e à direita, a dividir por 2). No aritmético à direita, o bit de sinal é repetido para o número negativo continuar negativo.

### 9.3 Conversão e E/S (duas classes de operação)

| | Conversão | E/S |
|---|---|---|
| Ideia | **Muda o formato** do dado (ex.: decimal → binário) | **Transfere dados** com dispositivos |
| Analogia do slide | Um tradutor que transforma | Uma tomada que conecta |

Duas formas de organizar a E/S:

| | **E/S mapeada em memória** | **E/S independente** (isolada) |
|---|---|---|
| Como funciona | Dispositivos têm **endereços como se fossem memória** | Dispositivos **não** usam endereços da memória (observação minha) |
| Instruções | Usa as **mesmas instruções de movimentação** da memória | Poucos **comandos especiais** de E/S |
| Extra | | Pode usar **DMA** |
| Analogia | Endereço postal comum | Campainha dedicada |

### 9.4 Controle de sistema

Instruções de **acesso restrito**, **privilegiadas**, usadas pelo **sistema operacional** em **modo de núcleo** (modo kernel). Um programa comum não pode executá-las.

### 9.5 Transferência de controle: desvios e saltos

Altera o fluxo normal (sequencial) do programa. O slide compara com trilhos: o fluxo segue em linha ou toma um **desvio**. Serve também para **modularização**.

| Tipo | Como decide | Exemplo |
|---|---|---|
| **Desvio condicional** | Decide **com base em uma condição** | `BRZ X` (desvia para X se o resultado for zero). Uma direção pergunta, a outra segue |
| **Desvio incondicional** | **Desvia sempre**, sem testar nada | `JUMP X` (exemplo meu, não está no slide) |
| **Instrução de salto** | O **campo de endereço aponta outra função** | O slide usa a analogia de uma catraca que conta e muda de estado ao atingir o limite |

### 9.6 Sub-rotinas (chamada e retorno)

Uma sub-rotina é uma tarefa **chamada** e **devolvida ao fluxo**: **chamada → subprograma executa → retorno** (vai, executa, volta). Dá **economia** (código escrito uma vez) e **modularidade**.

**Aninhamento:** uma chamada pode abrir outra (Principal chama Proc1, que chama Proc2). **Cada chamada precisa guardar o próprio endereço de retorno.**

| Onde guardar o endereço de retorno | Resultado |
|---|---|
| **Registrador** | Falha com **aninhamento** (o segundo retorno sobrescreve o primeiro) |
| **Início do procedimento** | Falha com **recursão** |
| **Pilha** | **Resolve** os dois |

**Pilha:** estrutura **LIFO** (último a entrar, primeiro a sair). Suporta aninhamento e recursão. O slide compara: registrador = post-it, início do procedimento = caderno fixo, pilha = bandeja de documentos.

**Passagem de parâmetros** pode usar:

| Rota | Como |
|---|---|
| **Registrador** | Rota direta (envelope) |
| **Memória** | Rota compartilhada (gaveta) |
| **Pilha** | Bandeja |

```
Pilha na prática:  ADD
  1) retira os dois valores do topo (ex.: 7 e 5)
  2) soma na ULA (7 + 5 = 12)
  3) coloca o resultado de volta no topo
  Dois elementos saem, um resultado volta. Zero endereços explícitos.
```

> 🏆 **Regra de ouro**: **Regra de ouro:** para **recursão** e **chamadas aninhadas** o endereço de retorno tem que ir para a **pilha**. Registrador único e "início do procedimento" não bastam.

### 9.7 Painel de operações típicas

O slide mostra, como um painel de oficina, as operações básicas de um conjunto de instruções: **MOVE, LOAD, STORE, ADD, AND, JUMP condicional**. Cada "tecla" aciona uma operação.


---

## 10. Modos de endereçamento, registradores e formato da instrução (partes 2 e 3)
*(Fonte: 13_AULA_arquitetura-e-organizacao-de-computadores-parte-2.pdf e ..-parte-3.pdf (slides só em imagem, lidos por OCR e conferidos visualmente))*

### 10.1 Por que existem vários modos de endereçamento

Um **campo de endereço curto** precisa alcançar **muita memória**. A solução é uma referência curta que aponta para um destino maior (como o CEP aponta para um endereço completo). Uma máquina costuma ter **mais de um modo**.

- **Como a UC sabe o modo?** O **opcode** define o modo, **ou** a instrução traz um **campo de modo**.
- **Critérios para comparar modos:** **alcance**, **flexibilidade** e **complexidade**.
- **EA** (*effective address*) = endereço efetivo, o endereço real onde está o operando.

### 10.2 Os modos, um por um

| Modo | Fórmula | Acessos à memória (do operando) | Característica |
|---|---|---|---|
| **Imediato** | operando = valor no campo (`ADD 5`) | **0** | Constante sem acessar memória. Limitado pelo tamanho do campo |
| **Direto** | EA = A | **1** | O campo é o endereço do operando. Limitação de espaço de endereçamento |
| **Indireto** | EA = (A) | **2** | O campo aponta para um ponteiro que guarda o endereço do operando. **Espaço grande** |
| **Registrador** | operando = R | **0** | Operando está no registrador. Espaço limitado (poucos registradores) |
| **Indireto por registrador** | EA = (R) | **1** | O registrador guarda o endereço. **Um acesso a menos que o indireto** |
| **Deslocamento** | EA = A + (R) | **1** | Combina direto e indireto por registrador. Flexibilidade com custo de cálculo |
| **Relativo** | EA = A + PC | **1** | O registrador usado é o **PC**: deslocamento em relação à instrução atual |
| **Base + deslocamento** | EA = (R) + A | **1** | R guarda o endereço-base; A é o deslocamento. É assim que se implementa **segmentação** |
| **Indexado** | EA = A + (R) | **1** | Eficiente para **vetores** |
| **Pilha** | SP aponta o topo | depende | Operando **implícito**: não aparece na instrução |

Notação: **(X)** significa "conteúdo de X". Acessos contados **sem** a busca da própria instrução.

**Pré-indexação × pós-indexação** (a ordem muda o resultado):

```
Pré-indexação:   EA = ( A + R )      soma primeiro, depois acessa a memória
Pós-indexação:   EA = ( A ) + R      acessa a memória primeiro, depois soma
```

> 🏆 **Regra de ouro**: **Regra de ouro:** quanto mais indireção, mais **alcance** e mais **acessos à memória** (mais lento). **Registrador** é o mais rápido. **Indireto** tem o maior alcance, mas o acesso custa tempo.

**Exemplo numérico (observação minha, não está no slide).** Dados: campo da instrução A = 100; M[100] = 500; M[500] = 7; M[120] = 9; R1 = 20; R2 = 100.

| Modo | Conta | Operando obtido | Acessos |
|---|---|---|---|
| Imediato | o próprio valor | **100** | 0 |
| Direto | M[100] | **500** | 1 |
| Indireto | M[M[100]] = M[500] | **7** | 2 |
| Registrador (R2) | R2 | **100** | 0 |
| Indireto por registrador (R2) | M[R2] = M[100] | **500** | 1 |
| Indexado/deslocamento (A + R1) | M[100 + 20] = M[120] | **9** | 1 |

> ⚠️ **Atenção**: **Pegadinha:** **imediato** e **registrador** têm **0 acessos** à memória para o operando, mas por motivos diferentes: o primeiro tem o valor **dentro da instrução**, o segundo tem o valor **dentro da CPU**.

### 10.3 Organização de registradores

| Processador | Registradores |
|---|---|
| **Motorola 68000** | **Dados:** D0 a D7. **Endereços:** A0 a A7 (separados por função) |
| **Intel 8086** | **AX** acumulador, **BX** base, **CX** contador, **DX** dados, mais registradores de **ponteiro e índice** |
| **80386 ao Pentium** | **EAX, EBX, ECX, EDX, ESP, EBP, ESI, EDI**, flags e ponteiro de instrução. 32 bits, com nomes herdados dos de 16 bits |

### 10.4 Formato da instrução

- A instrução se divide em **campos**: **opcode**, **modo**, **operando**, **operando**. O formato define **onde encontrar cada parte** (campos separados facilitam a decodificação). Um conjunto pode ter **mais de um formato**.
- **Tamanho da instrução** é decisão de projeto: **curta, média ou longa**. Afeta a **memória** (ocupa mais ou menos), o **barramento** (quantos acessos para buscar) e a **CPU**. Conflito entre **repertório rico** e **economia de espaço**.
- O tamanho deve ser **múltiplo inteiro** da **unidade de transferência** (e também múltiplo do tamanho do caractere e do inteiro).
- **Como dividir a palavra:** bits do **opcode** (quantos opcodes existem) × bits de **endereço** (o endereço define o **alcance**).

**O que consome bits da instrução (5 decisões que disputam espaço):**

1. **Modos de endereçamento**
2. **Número de operandos**
3. **Registrador ou memória**
4. **Tamanho do banco de registradores**
5. **Granularidade** (endereçar por byte, palavra...)

**Observação minha, não está no slide:** pela regra n bits → 2ⁿ, um opcode de 6 bits distingue até 64 operações e um campo de endereço de 10 bits alcança 1.024 posições. Mais bits para um lado = menos para o outro.

### 10.5 Exercício resolvido: duas letras numa palavra de 16 bits

**Enunciado do slide:** palavra de 16 bits com 2 caracteres. Transmitir **um caractere por vez** para a E/S.

```
1) Carregar a palavra em R1 e em R2 (duas cópias)
2) AND de R1 com 1111111100000000      (a máscara bloqueia a metade direita)
3) Deslocar R1 8 posições à direita:   0011001100000000 -> 0000000000110011
4) E/S do primeiro caractere (R1)
5) AND de R2 com 0000000011111111      (a abertura troca de lado)
6) E/S do segundo caractere (R2)
```

**Custo:** 2 máscaras (AND) + 1 deslocamento de 8 posições + 2 envios à E/S. **Dois caracteres custam 1 palavra e 2 acessos** (à E/S).

### 10.6 Recapitulação do slide

| Ideia | Resumo |
|---|---|
| Bits e bytes | 8 bits por byte; 8n bits em n bytes; **2ⁿ** valores representáveis |
| Registrador | É o mais **rápido** |
| Indireto | Tem o maior **alcance** |
| Acesso à memória | **Custa tempo** |

> 📝 **Nota**: O slide final aponta a próxima etapa (Parte 4), com o capítulo de conjuntos de instrução do Stallings. Essa parte **não foi enviada**, então não está neste resumo.


---

## 11. Memória: características, hierarquia, RAM, ROM e cache
*(Fonte: AULA_0708_-_MEMORIAS.pdf e Material_Complementar_Capítulo01_1_DispositivosEquipamentos.pdf)*

### 11.1 Características de um sistema de memória

Memória é todo dispositivo que permite **guardar dados**. O sistema de memória se entende pelas suas **características**:

| Característica | Opções / ideia do slide |
|---|---|
| **Localização** | No processador (registradores), **interna** (principal), **externa** (armazenamento) |
| **Capacidade** | Tamanho da palavra × número de palavras. Interna: em bytes ou palavras. Externa: em bytes |
| **Unidade de transferência** | Interna: nº de bits lidos/escritos de cada vez (**palavra**). Externa: **blocos** |
| **Método de acesso** | **Sequencial**, **direto**, **aleatório**, **associativo** |
| **Desempenho** | **Tempo de acesso**, **tempo de ciclo**, **taxa de transferência** |
| **Tecnologia** | Semicondutores, magnética, óptica, magneto-óptica |
| **Características físicas** | Volátil × não volátil; apagável × não apagável |
| **Organização** | Arranjo físico dos bits para formar palavras (fundamental em memórias de acesso aleatório) |

### 11.2 Hierarquia de memórias

Hierarquia: **CPU → registradores → cache → memória principal → memória secundária**. As restrições de projeto resumem-se a **capacidade, velocidade e custo**.

Relações entre tecnologias:

- **Tempo de acesso mais rápido** → **custo por bit maior**.
- **Capacidade maior** → **custo por bit menor**.
- **Capacidade maior** → **tempo de acesso maior**.

**Descendo na hierarquia** (do registrador para o disco):

| O que acontece | |
|---|---|
| Custo por bit | **diminui** |
| Capacidade | **aumenta** |
| Tempo de acesso | **aumenta** |
| Frequência de acesso pelo processador | **diminui** |

**Hit e miss:**

- **Hit:** o dado está no nível superior (mais perto da CPU). **Hit ratio = hits ÷ acessos.**
- **Miss:** o dado está ausente. O bloco é copiado do nível inferior. O tempo extra é a **miss penalty**.
- **Miss ratio = misses ÷ acessos = 1 − hit ratio.**

> ⚠️ **Atenção**: **Pegadinha:** hit ratio + miss ratio = **1** (ou 100%). Se o hit ratio é 0,95, o miss ratio é **0,05**.

### 11.3 Memória principal, secundária, RAM e ROM

- **Memória principal (primária):** conjunto de chips que guardam as informações **enquanto estão sendo processadas**, só enquanto o computador está ligado. A RAM é vendida em placas chamadas **pentes**.
- **Memória secundária (auxiliar):** grava os dados de forma **física e permanente**: não se perdem ao desligar.
- **RAM** (Random Access Memory): permite **ler e escrever rápido e facilmente**; **volátil**.
- **ROM** (Read Only Memory): guarda informações básicas do hardware, gravadas pelo fabricante. Padrão **permanente**, só leitura.

| | **DRAM** (dinâmica) | **SRAM** (estática) |
|---|---|---|
| Formada por | **Capacitores** | **Flip-flops** |
| Integração | **Alta** (baixo custo por bit) | Menor (alto custo por bit) |
| Refresh | **Precisa** de refresh constante (perde a informação em algum tempo) | **Não precisa** |
| Tempo de acesso | Maior | **Pequeno** |
| Uso típico | Memória principal | Cache |

> ⚠️ **Atenção**: **Pegadinha:** a "D" de DRAM é de **dinâmica** (capacitores que descarregam e precisam de **refresh**). SRAM não precisa de refresh, é mais rápida e mais cara.

**Comparação do slide (valores de referência):**

| Tipo | Tempo de acesso | Custo por GB |
|---|---|---|
| SRAM | 0,5 a 2,5 ns | US$ 2.000 a 5.000 |
| DRAM | 50 a 70 ns | US$ 20 a 75 |
| HD | 5 a 20 ms | US$ 0,20 a 2,00 |

**Famílias de memória:**

| Tipo | Categoria | Apagamento | Escrita | Volátil? |
|---|---|---|---|---|
| **RAM** | Leitura/escrita | Elétrico (byte a byte) | Elétrica | **Volátil** |
| **ROM** | Apenas leitura | Impossível | Por máscara (fábrica) | Não volátil |
| **PROM** | Apenas leitura | Impossível | Elétrica (o cliente grava) | Não volátil |
| **EPROM** | Principalmente leitura | **Ultravioleta** (apaga tudo) | Elétrica | Não volátil |
| **EEPROM** | Principalmente leitura | **Elétrico, byte a byte** | Elétrica | Não volátil |
| **Flash** (Flash EPROM) | Principalmente leitura | **Elétrico, por bloco** | Elétrica | Não volátil |

- Variantes de RAM no slide: **SRAM**, **DRAM**, **VRAM** (Video RAM).
- **ROM:** vantagem = programas ficam permanentemente armazenados. Problemas: o custo fixo de gravação é alto e **não podem ocorrer erros** (um bit errado inutiliza o lote).
- **PROM:** alternativa mais barata, **gravação feita pelo cliente**, vantajosa em larga escala.
- **Flash:** introduzida em meados dos anos 80; **apaga e lê rápido**.

> 💡 **Dica**: **Macete para apagamento:** EPROM = **U**ltravioleta (**tudo** de uma vez). EEPROM = **E**létrico, **byte a byte**. Flash = elétrico, **por bloco**.

> 📝 **Nota**: O slide traz a citação atribuída a Bill Gates em 1981, "640K ought to be enough for anybody" (640 KB bastariam), para mostrar como a necessidade de memória cresceu.

### 11.4 Memória cache

- Objetivo: obter **velocidade de acesso**. É o **nível de memória mais próximo da CPU**.
- A cache tem **linhas de palavras**, e o número de linhas é **muito menor** que o número de blocos da memória principal.
- Ao ler um bloco, ele é copiado para **uma linha**. Como uma linha não guarda o mesmo bloco para sempre, cada linha tem um **rótulo (tag)** que identifica qual bloco está ali. O rótulo costuma ser **parte do endereço de memória**.
- Nas caches modernas, as linhas de dados e de endereços ligam-se a áreas de armazenamento temporário (buffers) e ao **barramento do sistema**, por onde se acessa a memória principal.


---

## 12. Barramentos: memória, clock, sincronia, pontes e PCIe
*(Fonte: AULA_08_BARRAMENTO.pdf, AULA_08_BARRAMENTO_EXEMPLOS.pdf e barramentos-complementos-da-aula.pdf)*

### 12.1 Como a memória funciona (pinos)

Uma memória de **8 bits de dado e 3 bits de endereço** tem os pinos: **A0 a A2** (endereço), **D0 a D7** (dado), **MREQ** (liga a memória), **R** (leitura) e **W** (escrita).

| Grupo | Pinos | Função |
|---|---|---|
| **Endereço** | A0–An | Seleciona **a posição** (onde) |
| **Dado** | D0–Dn | A **informação transferida** (o quê) |
| **Controle** | MREQ, R, W (R/W), IORQ, clock | Define a operação e **quando** acontece |

> 🏆 **Regra de ouro**: **Regra de ouro:** **Endereço = onde. Dados = o quê. Controle = quando/como.**

**Escrita: gravar 53 no endereço 5**

```
53 = 00110101b          endereço 5 = 101b
1) CPU coloca o endereço no barramento de endereços:  A0=1  A1=0  A2=1
2) CPU coloca o dado no barramento de dados:          D0=1 D1=0 D2=1 D3=0 D4=1 D5=1 D6=0 D7=0
3) CPU ativa W e MREQ
4) A memória armazena 53 na posição 5   ->   M[5] <- 00110101b
```

**Leitura: ler o endereço 5**

```
1) CPU coloca o endereço:  A0=1  A1=0  A2=1
2) CPU ativa R e MREQ
3) A memória coloca o conteúdo da posição 5 (00110101b) no barramento de dados
4) A CPU lê o dado: 00110101b = 53
```

> ⚠️ **Atenção**: **Pegadinha:** na **escrita** a CPU envia **endereço + dado + comando W**. Na **leitura** a CPU envia **endereço + comando R** e **recebe** o dado. Em ambos, **MREQ** liga a memória.

> 📝 **Nota**: Os bits D0 a D7 aparecem na ordem do pino (D0 = bit menos significativo). Por isso 53 = `00110101b` aparece como D0=1, D1=0, D2=1, D3=0, D4=1, D5=1, D6=0, D7=0.

### 12.2 Barramentos de sistema

Um computador tem **3 componentes** (CPU, memória, dispositivos) ligados por **3 barramentos**, cada um um conjunto de fios com função própria:

| Barramento | Função | Sentido |
|---|---|---|
| **Endereços** | Seleciona o endereço de memória ou do dispositivo | Unidirecional (CPU → memória/dispositivo) |
| **Dados** | Informação a ser transferida | **Bidirecional** |
| **Controle** | Configura **quais dispositivos se comunicarão** | |

- A **CPU** é, em geral, a **"dona" do barramento** (**mestre**). Memória e dispositivos são **escravos**: respondem.
- **MREQ** liga a memória. **IORQ** liga dispositivos de E/S.
- **A0 a An**: endereço do dado. **D0 a Dn**: dado transferido.
- A **largura do barramento de dados** = quantos bits viajam por vez. A **largura do de endereços** define **quanta memória** dá para endereçar.

### 12.3 Clock e sincronia

- O **clock** (relógio) é gerado por um **cristal de quartzo** que emite pulsos em intervalos constantes. Nível lógico 1 = +5 V, nível lógico 0 = 0 V.
- O **clock orienta o mestre**. O mestre dá uma ordem e **espera n ciclos** pela resposta.
- **Frequência = 1 ÷ período.**

**Exemplo do slide:** período de 10 ns.

```
10 ns = 1 ciclo
1 s   = x ciclos
x = 1 s / (10 x 10^-9 s) = 10^8 ciclos por segundo = 100 MHz
```

> 💡 **Dica**: **Atalho:** 10 ns → 100 MHz. 100 ns → 10 MHz. 1 ns → 1 GHz. (1 MHz = 10⁶ Hz, 1 GHz = 10⁹ Hz.)

### 12.4 Barramentos síncronos: leitura de memória em 3 ciclos

Cada dispositivo tem a **sua própria velocidade**, então a CPU usa **tabelas de temporização** e os dispositivos são **projetados para obedecê-las**.

| Ciclo | O que acontece |
|---|---|
| **T1** | A CPU coloca o endereço no **MAR** e aciona **MREQ** e **RD** (leitura) |
| **T2** | A CPU **espera** a resposta da memória |
| **T3** | A CPU **lê o dado** no barramento de dados e **desativa** MAR, MREQ e RD |

Esquema simplificado (observação minha, para visualizar; o slide mostra o gráfico de sinais):

```
sinal       T1          T2          T3
endereço    [ endereço válido ................. ]
MREQ, RD    [ ativos .......................... ]   desativam no fim de T3
dado                    (memória procurando)  [ dado válido ]  <- CPU lê em T3
```

- **Por que existe T2, se "nada acontece"?** Porque a **memória é mais lenta que a CPU** e precisa de **tempo para localizar o dado**.
- **E se o dado não estiver no barramento no fim?** A CPU insere **ciclos de espera (wait states)**. O barramento síncrono **estende o tempo** quando o escravo é lento.

### 12.5 Barramentos em ponte e chipset

Dispositivos com **clocks diferentes** (ex.: placa PCI a **33 MHz** × CPU Intel de **~3 GHz**) precisam ser compatibilizados:

- **WAIT** é um pino da CPU que a **paralisa** ("espera aí, dona CPU!").
- Quem controla isso é, em geral, uma **ponte**: CPU pede acesso → a ponte detecta o dispositivo lento → ativa WAIT e paralisa a CPU → o dispositivo termina → a ponte libera a CPU.

| Ponte | Papel | Velocidades do slide |
|---|---|---|
| **Ponte Norte** | Liga **CPU, cache, memória RAM e vídeo** (AGP/PCIe) | Faixa de **400 a 800 MHz** (CPU em ~3 GHz) |
| **Ponte Sul** | Liga os periféricos **lentos**: Ethernet, SATA, USB, mouse, teclado (via ponte PCI-ISA) | PCI 33 MHz; ISA 8,33 MHz |

Exemplo citado: chipset **Intel 440GX** (AGP 2x, PCI 33 MHz, ISA). **Quanto mais perto da CPU, mais rápido.** Um barramento único seria **gargalo**; pontes e chipsets **distribuem o tráfego** e **isolam velocidades**.

### 12.6 PCIe: barramento serial, ponto a ponto

- **Serial** e **ponto a ponto**, organizado em **lanes** (x1, x4, x8, x16), **bidirecional** e **retrocompatível**.
- **GT/s** = transferências por segundo.

| Geração | GT/s por lane | Banda x16 (do slide) |
|---|---|---|
| Gen1 | 2,5 | 4 GB/s |
| Gen2 | 5 | 8 GB/s |
| Gen3 | 8 | 16 GB/s |
| Gen4 | 16 | 32 GB/s |
| Gen5 | 32 | 64 GB/s |
| Gen6 | 64 | 128 GB/s |
| Gen7 | 128 | 256 GB/s |

**Como calcular a banda de uma GPU (PCIe 4.0 x16, 16 GT/s por lane):**

```
1) 16 lanes x 16 GT/s = 256 GT/s
2) 256 / 8 = 32 GB/s por direção        (divide por 8 para passar de bits para bytes)
3) PCIe 3.0 x16 = 16 GB/s
4) A geração nova dobra a banda.   Um slot Gen3 reduz a banda disponível para a GPU.
```

> ⚠️ **Atenção**: **Atenção (os slides se contradizem):** pela tabela e pela fórmula acima, **PCIe 5.0 x16 = 32 GT/s × 16 ÷ 8 = 64 GB/s por direção**. Mas o slide de fechamento do barramento e o slide de E/S falam em **128 GB/s** para o Gen5 x16. **Observação minha, não está no slide:** 128 GB/s só faz sentido se somar **as duas direções** (bidirecional). Na dúvida, mostre a conta e diga se é por direção ou total.

### 12.7 Banda na prática (referência do slide)

| Conexão | Banda aproximada | Tempo de referência |
|---|---|---|
| NVMe Gen4 x4 | ≈ 7.000 MB/s | 100 GB em ≈ 15 s |
| SATA 3.0 | ≈ 550 MB/s | 100 GB em ≈ 3 min |
| DDR5-5600 dual channel | ≈ 89,6 GB/s | (5600 × 64 ÷ 8 × 2) |
| DDR4-3200 dual channel | ≈ 51,2 GB/s | comparação |
| USB 3.2 Gen1 / Gen2 | 5 / 10 Gb/s | 1 TB em ≈ 33 / 16 min |
| USB4 | 40 Gb/s | 1 TB em ≈ 4 min |

```
Banda da memória DDR:   transferências/s (MT/s) x 64 bits / 8 x nº de canais
DDR5-5600 dual:   5600 x 64 / 8 x 2 = 89.600 MB/s = 89,6 GB/s
DDR4-3200 dual:   3200 x 64 / 8 x 2 = 51.200 MB/s = 51,2 GB/s
```

> 📝 **Nota**: "**A interface define o caminho; a velocidade define o tempo.**" Em **dual channel** a banda **dobra** porque dois canais de 64 bits trabalham em paralelo.

> ⚠️ **Atenção**: **Atenção:** o slide de E/S fala em SATA III de **6 Gb/s (~600 MB/s)** e o slide de barramentos usa **≈ 550 MB/s**. Os dois são aproximações do mesmo SATA 3.0 (550 MB/s é o valor prático após o overhead).

### 12.8 Documentação (datasheet) e pinagem: quantos bits de dados e de endereço?

O **datasheet** mostra sinais, temporização, capacidade e tempos de acesso. O projetista usa isso para saber quantos ciclos a CPU deve esperar.

| Sinal | Tipo | Função |
|---|---|---|
| A0–A2 | Entrada | Endereço |
| D0–D7 | Entrada/saída | Dados |
| MREQ | Controle | Request de memória |
| R/W | Controle | Leitura / escrita |

**Receita (4 passos do slide):** (1) identifique **D0–Dn** → bits de dados; (2) identifique **A0–An** → bits de endereço; (3) calcule **2^(bits de endereço)** = posições; (4) conclua os **bytes por ciclo**.

| CPU | Dados | Endereço | Memória endereçável |
|---|---|---|---|
| **8086** | 16 bits | 20 bits | 1 MB |
| **8088** | **8** bits | 20 bits | 1 MB |
| **80286** | 16 bits | **24** bits | 16 MB |

```
dados     = largura do barramento (bytes transferidos por ciclo = bits / 8)
endereços = log2(memória)         memória = 2^(bits de endereço)

Exemplo do slide: 8 bits de dados, 20 bits de endereço
  1 byte por ciclo;  2^20 = 1.048.576 posições = 1 MB endereçável
```

### 12.9 Exercício: tempo por instrução

**Enunciado:** programa com 10.000 instruções sequenciais gasta 100.000 ciclos de clock. Clock de 5 MHz. Qual o tempo médio por instrução, em µs?

```
5 MHz = 5.000.000 ciclos por segundo
1 ciclo = 1 / 5.000.000 s = 2 x 10^-7 s = 0,2 µs
100.000 ciclos / 10.000 instruções = 10 ciclos por instrução (CPI = 10)
tempo por instrução = 10 x 2 x 10^-7 s = 2 x 10^-6 s = 2 µs
```

> 🏆 **Regra de ouro**: **Regra de ouro:** **tempo por instrução = CPI × período do clock** (período = 1 ÷ frequência). Cuidado com as unidades: MHz → 10⁶, ns → 10⁻⁹, µs → 10⁻⁶.


---

## 13. Placa-mãe: componentes, expansão, armazenamento e compatibilidade
*(Fonte: placa-mae-historia-evolucao-e-arquitetura.pdf (partes 1 e 2))*

### 13.1 Definição e arquitetura

A **placa-mãe** é a principal placa de circuito do computador: **conecta os componentes e permite que se comuniquem** (CPU → RAM → armazenamento → GPU → rede/USB/áudio → fonte). Para o slide é o "sistema nervoso central" e "a infraestrutura que conecta o computador".

```
PROCESSADOR
     |
CHIPSET / CONTROLADORES
     |
MEMÓRIA   ARMAZENAMENTO   EXPANSÃO   PERIFÉRICOS
```

> 📝 **Nota**: Hoje **nem todos os controladores ficam em um único chipset**: parte deles foi integrada ao próprio processador.

### 13.2 Evolução

**Linha do tempo:** anos 1970 (microprocessadores) → **1981 IBM PC** → PC/XT e PC/AT → **ATX, Micro-ATX, Mini-ITX** → **PCI Express, M.2, UEFI** → plataformas modernas. Contexto: grandes computadores → minicomputadores → microcomputadores → IBM PC → PCs compatíveis → placas modernas.

| | Placa **antiga** | Placa **atual** |
|---|---|---|
| Integração | Componentes **separados** | **Alta integração** |
| Barramentos | Simples | PCI Express, M.2, USB |
| Rede, áudio e firmware | Em placas ou chips à parte | Integrados (rede, áudio, UEFI) |

### 13.3 Os três componentes principais: Socket, Chipset e VRM

"Socket, VRM e chipset trabalham juntos para o processador se **conectar fisicamente**, **receber a energia correta** e **conversar com o resto das peças**."

| Componente | O que é | Detalhes do slide |
|---|---|---|
| **Socket** | **Encaixe da CPU**: interface física e elétrica entre processador e placa-mãe ("a tomada física") | Socket 7, 478, AM2, AM4, AM5 (AMD); LGA 775, LGA 1200, LGA 1700 (Intel) |
| **Chipset** | Coordena a comunicação e o gerenciamento de recursos da placa | **Northbridge + Southbridge** nas arquiteturas antigas; hoje **PCH** e controladores integrados no processador |
| **VRM** (Voltage Regulator Module) | **Converte e regula a energia** que chega à CPU | Bobinas, capacitores e circuitos de controle |

### 13.4 Firmware, CMOS e bateria

- **BIOS e UEFI** são **firmwares** de **inicialização e configuração**: inicialização → detecção de hardware → configuração → **boot**.
- A **memória CMOS** e a **pequena bateria** preservam as **configurações**, o **relógio do sistema** e o firmware.

### 13.5 Memória e expansão

- Os **slots DIMM** recebem os módulos de RAM. Evolução: **DDR → DDR2 → DDR3 → DDR4 → DDR5**.
- **DDR4 e DDR5 são gerações diferentes** (desempenho, largura de banda, energia) e **não são intercambiáveis**: cada uma tem seu encaixe.
- **Padrões de expansão** ao longo do tempo: **ISA → PCI → AGP → PCI Express**.
- **Lanes (PCIe):** caminhos de dados **x1, x4, x8, x16**. O slot **x16** é muito usado por placas de vídeo (banda por geração na seção 12.6).

### 13.6 Lanes no processamento vetorial (SIMD)

O slide reaproveita a palavra *lane* num segundo sentido: **unidade funcional paralela** dentro de um vetor/pipeline que executa **a mesma operação em elementos diferentes** ao mesmo tempo (**SIMD**: Single Instruction, Multiple Data). Analogia: rodovia de 4 pistas, passam 4 carros lado a lado.

```
Somar A = [10, 20, 30, 40] e B = [1, 2, 3, 4]

Escalar (1 caminho):   4 ciclos   10+1=11 | 20+2=22 | 30+3=33 | 40+4=44
Vetorial (4 lanes):    1 ciclo, com uma única instrução VADD
   Lane 0: 10+1=11   Lane 1: 20+2=22   Lane 2: 30+3=33   Lane 3: 40+4=44
```

Cada lane tem a **sua própria ULA** e registros locais. Síntese: **uma instrução, múltiplos dados, um único ciclo**.

> ⚠️ **Atenção**: **Pegadinha:** *lane* de **PCIe** = fio/caminho de comunicação (x1, x4, x16). *Lane* de **SIMD** = unidade de execução paralela. Mesmo nome, contextos diferentes.

### 13.7 Armazenamento: cabos, formatos e protocolos

| | Descrição |
|---|---|
| **IDE/PATA** | Cabo **largo**, conector volumoso |
| **SATA** | Cabo **fino**, instalação mais organizada |
| **M.2** | **Formato físico** (o "encaixe" na placa) |
| **NVMe** | **Protocolo** de alta velocidade que roda sobre o **PCI Express** |

> 🏆 **Regra de ouro**: **Regra de ouro:** **M.2 é formato. NVMe é protocolo.** Um drive M.2 pode ser **SATA** (mais lento, AHCI) **ou NVMe** (mais rápido). O SSD SATA de 2,5" usa interface SATA e geralmente precisa de cabos. O M.2 NVMe usa a interface PCIe e normalmente dispensa cabos.

### 13.8 Form factor e gabinete

**Form factor** combina **tamanho, posição dos componentes, pontos de fixação e compatibilidade**. Padrões: **AT, ATX, Micro-ATX, Mini-ITX**.

| | **ATX** | **Micro-ATX** | **Mini-ITX** |
|---|---|---|---|
| Tamanho | Maior | Intermediário | Compacto |
| Slots e expansão | Mais slots PCIe e maior conectividade | Equilibra tamanho reduzido com boa quantidade de slots | Poucos slots (geralmente **um** PCIe) |
| Uso | | | Builds pequenos |

**Tipos de gabinete:** Full Tower (alta expansão), Mid Tower (uso geral), Mini Tower (menor volume), SFF (formato compacto), Desktop (uso horizontal) e HTPC (central multimídia).

| Formato da placa | Gabinetes compatíveis |
|---|---|
| ATX | Mid Tower / Full Tower |
| Micro-ATX | Mid Tower ou gabinete compatível |
| Mini-ITX | Gabinetes compactos ou compatíveis |

> ⚠️ **Atenção**: **Pegadinha:** um gabinete ATX comporta uma placa Micro-ATX, mas o **inverso nem sempre** é possível. Formato é o **primeiro filtro**: depois confirme as especificações do fabricante.

### 13.9 Conectores internos e externos

| Onde | Conectores |
|---|---|
| **Energia** | ATX de 24 pinos; EPS da CPU |
| **Armazenamento** | SATA; M.2 |
| **Gabinete** | USB interno; áudio frontal; painel frontal; conectores de ventoinhas (fluxo de ar) |
| **Painel traseiro** | USB, USB-C, Ethernet, HDMI, DisplayPort, áudio; Wi-Fi/Bluetooth quando disponível (depende do modelo) |

### 13.10 Checklist antes de comprar

Confira: **socket da CPU**, **processador compatível**, **tipo de RAM** (DDR4 × DDR5), **quantidade de slots**, **PCI Express**, **M.2 e SATA**, **USB**, **formato** da placa, **fonte** (potência e conectores), **refrigeração** (inclusive altura do cooler e suporte a radiadores de water cooler) e **espaço para a GPU** (comprimento máximo).

**Configuração de exemplo do slide:** processador AM5 ou LGA 1700 · placa ATX · memória DDR5 · SSD M.2 NVMe · GPU PCIe x16 · fonte ATX · gabinete Mid Tower. Conferência: socket e CPU conferem; DDR5 nos slots compatíveis; SSD no slot M.2; GPU no PCIe x16; ATX cabe no Mid Tower; fonte com conectores e refrigeração adequados. **Ainda assim, confira o manual da placa.**

> 💡 **Dica**: "Não basta caber. A peça precisa **conectar**, receber **energia** e ter **espaço** para funcionar." Conhecer hardware é entender **como as peças se conectam, se comunicam e trabalham juntas**.


---

## 14. Entrada/Saída e armazenamento
*(Fonte: 5_AULA_SISTEMA_ENTRADA_SAIDA.pdf e SistemaEntradaSaida.pdf)*

### 14.1 O que é E/S (I/O)

**E/S** (Input/Output) é o conjunto de **hardware e software** que faz a comunicação entre o computador e o **mundo exterior**. Sem ela, o processador ficaria isolado.

| | Função |
|---|---|
| **Entrada** | Receber dados do usuário/ambiente e **converter em sinais digitais** |
| **Saída** | Apresentar os resultados em formato compreensível (imagem, som, texto impresso) |
| **Interfaces de E/S** | Circuitos e protocolos que **padronizam** a comunicação entre processador e periféricos |

### 14.2 Dispositivos de entrada e de saída

| Dispositivo | Tipos / detalhes do slide |
|---|---|
| **Teclado** (entrada) | **Mecânico** (switch individual, durável, preferido por programadores e gamers), **membrana** (borracha sob as teclas, silencioso, econômico, comum em escritórios), **ergonômico**. Cada tecla gera um sinal convertido em código pelo **controlador do teclado** |
| **Mouse** (entrada) | **Óptico** (LED + sensor de imagem), **laser** (mais preciso, funciona em vidro e tecido), **trackball**. Traduz o movimento em coordenadas **X, Y** |
| **Scanner** (entrada) | Digitaliza documentos e imagens (analógico → digital). Sensores **CCD**. Tipos: plana e ADF (alimentador automático) |
| **Microfone** (entrada) | Converte ondas sonoras em sinais elétricos, digitalizados pelo **conversor A/D** da placa de som. Tipos: dinâmico e condensador |
| **Monitor** (saída) | **LCD** (cristais líquidos + retroiluminação fluorescente), **LED** (retroiluminação por LEDs: mais brilho, menos consumo), **OLED** (cada pixel emite luz própria: pretos perfeitos, alto contraste). Qualidade: resolução, taxa de atualização, profundidade de cor, tipo de painel |
| **Impressora** (saída) | **Jato de tinta** (fotos e cores), **laser** (toner, rápida, menor custo por página em volume), **térmica** (calor em papel especial: PDV, etiquetas, cupons) |
| **Alto-falantes** (saída) | **Estéreo** (2 canais), **surround** (5.1, 7.1), **Bluetooth** (2,4 GHz, alcance ~10 m, codecs aptX e AAC) |

### 14.3 Interfaces de E/S

| Interface | Detalhes |
|---|---|
| **USB** (Universal Serial Bus) | Interface universal. Versões 2.0, 3.0 e USB-C: de **480 Mbps a 40 Gbps**. Suporta alimentação elétrica (USB Power Delivery) |
| **HDMI** | **Vídeo e áudio digitais** de alta definição (até 8K) |
| **VGA** | Padrão **analógico** antigo (equipamentos legados). O HDMI o substituiu progressivamente |
| **Ethernet (RJ-45)** | Rede local, de **100 Mbps a 10 Gbps** |
| **Áudio P2 (3,5 mm)** | Microfones, fones e caixas de som, de forma analógica |

### 14.4 Armazenamento: primário, secundário e terciário

| Nível | O que é | Exemplos |
|---|---|---|
| **Primária** | Acesso **direto** pelo processador. **Rápida e volátil** | RAM, cache L1/L2/L3, registradores |
| **Secundária** | **Não volátil**, maior capacidade, mais lenta | HD, SSD, pendrive, CD/DVD |
| **Terciária** | Longo prazo e grande volume, geralmente **offline ou remota** | Fitas magnéticas (LTO), backup em nuvem, DVDs de arquivo |

- **RAM:** volátil, acesso aleatório (qualquer posição em tempo constante), latência em nanossegundos. DDR4 e DDR5 são os padrões atuais. **Mais RAM** evita recorrer à **memória virtual (swap no disco)**, que é muito mais lenta.
- **HD:** **pratos magnéticos** girando (5.400 a 7.200 RPM) com **cabeça de leitura/escrita** mecânica. Mais capacidade e **menor custo por GB**.
- **SSD:** memória **flash NAND**, **sem partes móveis**, mais rápido e confiável que o HD (principalmente os **NVMe via PCIe**).
- **CD/DVD:** mídias **ópticas** com laser. **CD até 700 MB**; **DVD até 8,5 GB** (dupla camada).
- **Nuvem:** armazenamento remoto escalável (AWS S3, Google Cloud Storage). **Fitas LTO:** backup de longo prazo.

| Característica | RAM | HD | SSD | CD/DVD | Nuvem |
|---|---|---|---|---|---|
| Volatilidade | **Volátil** | Não volátil | Não volátil | Não volátil | Não volátil |
| Velocidade | Muito alta | Baixa | Alta | Muito baixa | Depende da internet |
| Capacidade típica | 8–64 GB | 500 GB–20 TB | 250 GB–4 TB | 700 MB–8,5 GB | Escalável |
| Custo por GB | Alto | Muito baixo | Médio | Baixo | Variável |
| Uso principal | Execução de programas | Armazenamento em massa | Sistema operacional e apps | Mídia e distribuição | Backup e colaboração |

### 14.5 Arquitetura de E/S: barramentos, controladores e drivers

- **Barramentos** (canais compartilhados entre processador, memória e E/S): **PCIe** (serial, alta velocidade: GPUs, SSDs NVMe, placas de rede; lanes x1, x4, x8, x16) e **SATA** (HDs e SSDs SATA; **SATA III = 6 Gb/s, ~600 MB/s**).
- **Controlador de E/S** (**hardware**): circuito dedicado que gerencia a comunicação entre processador e dispositivo. **Libera a CPU** de gerenciar cada operação e **sinaliza quando conclui**. Ex.: controlador de disco, USB, placa de rede.
- **Driver** (**software**): traduz as chamadas do **sistema operacional** em comandos específicos do hardware. Tipos: **driver de dispositivo** (um hardware específico, ex.: placa de vídeo NVIDIA) e **driver de sistema** (recursos compartilhados como interrupções e DMA).

> 🏆 **Regra de ouro**: **Regra de ouro:** **controlador = hardware**, **driver = software**. Essa separação é princípio da arquitetura modular dos SOs modernos.

### 14.6 Protocolos de E/S: polling, interrupção e DMA

| | **Polling** (busy-waiting) | **Interrupção** (interrupt-driven) | **DMA** (Direct Memory Access) |
|---|---|---|---|
| Quem toma a iniciativa | **CPU** consulta o status do dispositivo **periodicamente** | O **dispositivo** avisa a CPU (via **IRQ**) | **Controlador DMA** move os dados |
| CPU enquanto espera | Em **loop** de consulta, gastando ciclos | **Livre** para outras tarefas | **Livre** durante a transferência |
| Quando usar | Dispositivos **muito rápidos** (espera curta) | Dispositivos **lentos** | **Grandes volumes** (disco, rede, áudio/vídeo) |
| Vantagem | Simples, sem hardware de interrupção | Não desperdiça ciclos | O mais eficiente para blocos grandes |
| Desvantagem | **Desperdício de ciclos** | Custo de salvar contexto | Precisa de controlador DMA |
| Analogia do slide | Olhar a caixa de correio várias vezes ao dia | O carteiro toca a campainha | O carteiro deixa a carta direto no escritório |

**Interrupção em 4 etapas:**

1. O dispositivo conclui a operação e envia o **sinal de interrupção (IRQ)**.
2. A CPU **salva o estado atual** nos registradores (contexto).
3. A CPU executa a **ISR** (*Interrupt Service Routine*, rotina de tratamento).
4. A CPU **retorna à tarefa original**.

**DMA em 4 etapas:**

1. A CPU **configura** o controlador DMA (endereço e tamanho).
2. O controlador DMA **gerencia a transferência** sozinho (dispositivo ↔ RAM).
3. A CPU fica **livre**.
4. Ao concluir, o DMA emite uma **interrupção** para avisar a CPU.

> ⚠️ **Atenção**: **Pegadinha:** o DMA **também usa interrupção**, mas só **no final**, para avisar que acabou. Na interrupção "pura" a CPU participa **da transferência** dos dados. No DMA ela só **configura** e é **avisada**.

### 14.7 Exemplos práticos do slide

- **Digitar uma letra:** o teclado gera um sinal elétrico (**scan code**) → o controlador converte em dados → o **driver** converte em **ASCII/Unicode** → o SO processa → o subsistema gráfico mostra na tela.
- **Salvar um documento:** o software faz uma **chamada de sistema (system call)** → o SO gerencia o **sistema de arquivos** (FAT32, NTFS, ext4) e **enfileira** a escrita → o **controlador do HD/SSD** grava os blocos nos setores. No SSD envolve **apagar e reescrever células flash**, gerenciado pelo firmware do controlador.

### 14.8 Técnicas de otimização de E/S

| Técnica | O que faz | Exemplo |
|---|---|---|
| **Caching** | Guarda **cópias dos dados mais acessados** em memória mais rápida (cache ou RAM). Reduz o tempo nas leituras repetidas | *Page cache* em RAM para dados de disco |
| **Buffering** | Usa **áreas temporárias (buffers)** para absorver a diferença entre as taxas de **produção e consumo**. Produtor e consumidor operam de forma assíncrona | Dados chegando mais rápido do que são processados |
| **Spooling** (Simultaneous Peripheral Operations On-Line) | Guarda trabalhos **em fila no disco** para processamento sequencial pelo dispositivo | **Fila de impressão** |

**Recapitulação do slide:** E/S conecta o computador ao mundo externo · entrada captura, saída apresenta · USB, HDMI e Ethernet padronizam conexões · armazenamento é hierárquico (RAM → SSD/HD → nuvem/fita) · PCIe e SATA ligam os componentes · controladores e drivers gerenciam a comunicação hardware–software · polling, interrupção e DMA são os protocolos fundamentais · caching, buffering e spooling otimizam o desempenho.

> 📝 **Nota**: O slide termina propondo um tutorial prático: **como desmontar** e depois **como montar** um computador.


---

## 15. Pipeline e arquiteturas superescalares (partes 1 e 2)
*(Fonte: Aula15_10_Arquiteturas-superescalares-e-pipeline-Parte_1.pdf e ...-parte-2.pdf (slides só em imagem, lidos por OCR e conferidos visualmente))*

### 15.1 Por que pipeline: desempenho = frequência × IPC

A Lei de Moore descreve o crescimento da integração. Aumentar a **frequência** foi uma estratégia importante, mas o desempenho também depende de **quantas instruções avançam por ciclo**:

```
Desempenho = frequência x IPC
```

### 15.2 O pipeline clássico de 5 estágios

**Princípio:** uma **linha de montagem de instruções**. Cada instrução percorre as mesmas etapas, e **várias instruções ocupam etapas diferentes ao mesmo tempo**.

| Estágio | Nome | O que faz |
|---|---|---|
| **IF** | Instruction Fetch (busca) | Busca a instrução e atualiza o **PC** |
| **ID** | Instruction Decode | Decodifica e **lê os registradores** |
| **EX** | Execute | Executa a operação ou **calcula o endereço** |
| **MEM** | Memory access | Acessa a memória de dados (quando necessário) |
| **WB** | Write Back | **Grava o resultado** no registrador |

Diagrama espaço-tempo (cada linha é uma instrução, cada coluna um ciclo):

```
        C1   C2   C3   C4   C5   C6   C7
I1      IF   ID   EX   MEM  WB
I2           IF   ID   EX   MEM  WB
I3                IF   ID   EX   MEM  WB
```

### 15.3 Latência, throughput e speedup

| Conceito | Definição |
|---|---|
| **Latência** | **Tempo para concluir uma instrução** |
| **Throughput** | **Instruções concluídas por unidade de tempo** |
| **Speedup (ideal)** | tempo sequencial ÷ tempo com pipeline |

> ⚠️ **Atenção**: **Pegadinha (slide):** "mais fluxo não necessariamente significa menor latência". O pipeline melhora o **throughput**, mas uma instrução isolada **não termina mais cedo**.

Com **k estágios** e **n instruções**, sem stalls:

```
Ciclos com pipeline = k + n - 1
Ciclos sem pipeline = k x n
Speedup = (k x n) / (k + n - 1)       -> tende a k quando n é grande
```

**Exercício 1 do slide: sem stalls, quanto ganhamos?** k = 5 estágios, n = 100 instruções.

```
1) ciclos com pipeline = k + n - 1 = 5 + 100 - 1 = 104
2) speedup = k x n / ciclos = 5 x 100 / 104 = 500 / 104 ≈ 4,8
```

### 15.4 Hazards (conflitos)

| Tipo | Causa |
|---|---|
| **Estrutural** | Duas operações disputam o **mesmo recurso** |
| **De dados** | Uma instrução depende do **resultado** de outra |
| **De controle** | O fluxo depende do **resultado de um desvio** |

**Estrutural:** com **memória única**, se a busca (IF) e o acesso a dados (MEM) caem no **mesmo ciclo**, só um dos pedidos usa a memória.

**De dados** (exemplos do slide):

| | Exemplo | O que acontece | Natureza |
|---|---|---|---|
| **RAW** (Read After Write) | `ADD R1,R2,R3` seguido de `SUB R4,R1,R5` | A SUB **lê R1 antes** da escrita anterior terminar | **Dependência verdadeira** |
| **WAR** (Write After Read) | `SUB R4,R1,R5` seguido de `ADD R1,R2,R3` | A escrita **ameaça uma leitura anterior** | **Falsa** (de nome) |
| **WAW** (Write After Write) | `ADD R1,R2,R3` seguido de `MUL R1,R4,R5` | **Duas escritas** no mesmo registrador: importa a ordem | **Falsa** (de nome) |

> 🏆 **Regra de ouro**: **Regra de ouro:** **RAW é verdadeira** (o dado realmente precisa ser produzido antes). **WAR e WAW são falsas** (só disputam o **nome** do registrador) e a **renomeação** resolve.

**De controle:** num `BEQ` o próximo PC ainda não está decidido. Se o desvio for **tomado**, as instruções buscadas no caminho errado são **descartadas (flush)**, e o flush **custa ciclos**.

### 15.5 Soluções: forwarding, stalls e bolhas

- **Forwarding (bypassing):** **encaminha o valor** do resultado da ALU **diretamente** para a entrada da próxima operação, **sem esperar o write-back**. Reduz a espera quando o produtor já calculou o dado mas ainda não o gravou.
- **Stall (bolha):** no **load-use imediato** o valor chega **tarde demais** para a operação dependente. O controle **congela o avanço e insere um ciclo vazio** (equivalente a um **NOP**).

```
LW  R1, 0(R2)       ; o dado só existe depois do estágio MEM
ADD R3, R1, R4      ; precisa de R1 logo em seguida -> 1 stall (mesmo com forwarding)
```

> ⚠️ **Atenção**: **Pegadinha:** **forwarding resolve RAW entre operações da ALU**, mas **não elimina** o stall do **load-use**, porque o dado do `LW` ainda não saiu da memória.

### 15.6 Predição de desvios

| Tipo | Como decide |
|---|---|
| **Estática** | Sempre **tomado** ou sempre **não tomado** |
| **Dinâmica** | Usa o **histórico recente** do desvio |

- **Contador saturante de 2 bits:** 4 estados (não tomado forte, não tomado fraco, tomado fraco, tomado forte). **Um erro muda o estado gradualmente**, então uma exceção isolada não inverte a previsão.
- **BTB** (Branch Target Buffer): **cache de alvos de desvio**. Associa o **PC do desvio** ao **alvo previsto**, permitindo buscar no destino previsto **sem esperar o cálculo do endereço**.
- **Mais contexto, melhor escolha (parte 2):** **dois níveis** (preditor correlacionado, usa **histórico de padrões**), **torneio/híbrido** (combina preditores para escolher a predição) e **TAGE** (presente em CPUs modernas).

### 15.7 Execução dinâmica, Tomasulo e renomeação

- **Execução fora de ordem (OoO):** avança o que está pronto. Ex.: `I1` load espera o dado; `I2` (soma independente) executa; `I3` (usa o load) espera `I1`. A dependência **RAW** ainda limita o IPC: **não dá para adiantar** uma operação que precisa de um resultado indisponível.
- **Tomasulo (escalonamento dinâmico):** as **estações de reserva** guardam a **operação e os operandos**. Se falta um operando, a instrução **espera**, enquanto outras prontas avançam. Usa **tags** para acompanhar resultados pendentes. Fluxo: instruções → emissão → estações de reserva → execução → resultado.
- **Renomeação de registradores:** um nome arquitetural, **vários destinos físicos**. Ex.: `ADD R1,R2,R3` e `MUL R1,R4,R5`: o primeiro R1 vira P7, o segundo vira P12. **Elimina WAR e WAW**. **RAW continua** sendo dependência real.

### 15.8 Superescalar, superpipeline e in-order × out-of-order

- **Superescalar:** busca, emite e executa **mais de uma instrução por ciclo**, sujeito a dependências e recursos. **Largura de emissão** = máximo de instruções iniciadas em um ciclo.

| | **Superescalar** | **Superpipeline** |
|---|---|---|
| Ideia | **Largura**: várias instruções iniciam **no mesmo ciclo** | **Profundidade**: estágios **mais curtos** |
| Efeito | Aumenta a largura de emissão | Aumenta a **frequência potencial**, **sem** emissão múltipla |

| | **In-order** | **Out-of-order** |
|---|---|---|
| Emissão | Na **ordem do programa**. Uma instrução bloqueada **segura as seguintes** | Busca e acompanha uma **janela** de instruções e emite **as prontas**, respeitando dependências e recursos |

- **Recursos:** ALUs, unidades de ponto flutuante e unidades load/store podem operar **ao mesmo tempo**, desde que haja instruções **independentes** e **operandos prontos**.
- **Exemplos históricos:** **Pentium** (emissão de 2 vias), **Pentium Pro** (execução fora de ordem), **ARM Cortex-A** (famílias com 8 ou mais vias). A **largura nominal não garante IPC igual à largura**: dependências e stalls limitam.

### 15.9 Métricas: CPI e IPC

```
Tempo de CPU = instruções x CPI x tempo de ciclo
IPC = instruções concluídas por ciclo        CPI = ciclos por instrução      IPC = 1 / CPI
```

**Exercício 3 do slide: conte os ciclos antes de dividir.** 10 instruções, com 1 stall de load-use e 1 desvio mal predito (3 ciclos de flush):

```
ciclos totais = 10 + 1 + 3 = 14
IPC = instruções / ciclos = 10 / 14 ≈ 0,71          CPI = 14 / 10 = 1,4
```

> 📝 **Nota**: O slide conta 1 ciclo por instrução mais as penalidades. **Observação minha, não está no slide:** ele não soma os ciclos de preenchimento do pipeline (k − 1).

**Exercício 2 do slide: identifique a dependência e escolha a solução.**

```
ADD R1, R2, R3
SUB R4, R1, R5      ; RAW com a ADD (lê R1)   -> forwarding entrega o valor sem esperar o write-back
MUL R1, R6, R7      ; WAW com a ADD (escreve R1) -> renomeação separa os destinos arquitetuais
LW  R8, 0(R9)
ADD R10, R8, R1     ; load-use (usa R8 logo após o load) -> 1 stall para o dado ficar disponível
```

### 15.10 Caminho da instrução num pipeline superescalar fora de ordem

Oito etapas: **Fetch múltiplo → Decode → Renomeação → Dispatch → Issue → Execute → Writeback → Commit**. Emissão e execução podem avançar em **paralelo**, enquanto o **estado arquitetural se confirma em ordem**.

**ROB (Reorder Buffer):** guarda as instruções **na ordem do programa** (da mais antiga: resultado gravado; resultado pronto: aguarda commit; execução pendente: aguarda resultado).

| Papel do ROB | Explicação |
|---|---|
| **Precisão** | O **commit em ordem** sustenta **exceções precisas** |
| **Recuperação** | Predição errada: **descartar o caminho incorreto** e retomar |

**Execução fora de ordem, commit em ordem.**

### 15.11 Limites, especulação e mais paralelismo

- **Limites:** **power wall** (limite de potência) e **memory wall** (memória lenta). Pela **lei de Amdahl**, a parte **sequencial** limita o speedup do **ILP** (paralelismo em nível de instrução).
- **Especulação:** executa **antes da confirmação**. O ROB permite **commit em ordem** e exceções precisas. Erro exige **recuperação**.
- **SMT** (Hyper-Threading na Intel): explora **TLP** (paralelismo em nível de thread) quando falta ILP.
- A **estagnação da frequência por volta de 2005** impulsionou a transição para **multicore**.

**Síntese do slide:** pipeline sobrepõe etapas → forwarding e predição reduzem esperas → emissão múltipla, OoO, renomeação e especulação extraem ILP, **sem eliminar limites**.

### 15.12 Quiz do slide e gabarito comentado

| # | Pergunta | Resposta em uma linha |
|---|---|---|
| 1 | Qual a diferença entre RAW e WAW? | RAW **lê antes de uma escrita**. WAW **disputa a ordem de escritas** |
| 2 | Por que load-use exige stall? | O load **ainda não entregou** o dado que a instrução seguinte precisa |
| 3 | O que a renomeação elimina? | **Dependências falsas de nome**, como WAW (e WAR), ao separar destinos |
| 4 | Qual o papel do BTB? | **Guarda alvos de desvios** para apoiar a busca |
| 5 | Por que o commit é in-order? | **Mantém o estado preciso** e a ordem arquitetural do programa |


---

## 16. Revisão final: comparações, perguntas e exercícios
*(Fonte: síntese de todos os arquivos acima (as perguntas de revisão e a seção 16.3 são minhas, no estilo dos slides))*

### 16.1 Tabelas de comparação que costumam cair

| | **CISC** | **RISC** |
|---|---|---|
| Instruções | Muitas, complexas, tamanho variável | Poucas, simples, tamanho fixo |
| Controle | **Microprograma** | **Hardwired** (cabeado) |
| Exemplos | x86 | ARM, MIPS, PowerPC, SPARC |

| | **Big-endian** | **Little-endian** |
|---|---|---|
| Ordem dos bytes | Byte mais significativo no **menor endereço** | Byte menos significativo no **menor endereço** |

| | **DRAM** | **SRAM** |
|---|---|---|
| Uso típico | Memória principal | Cache |
| Velocidade/custo | Mais lenta e barata | Mais rápida e cara |

| | Lógico | Aritmético | Rotação |
|---|---|---|---|
| Bit que sai | Descartado, entra zero | Preserva o sinal | Volta pela outra ponta |

| | **Polling** | **Interrupção** | **DMA** |
|---|---|---|---|
| Quem age | CPU consulta | Dispositivo avisa | Controlador DMA transfere |

| | Compilador | Montador | Ligador | Carregador |
|---|---|---|---|---|
| Faz | Alto nível → assembly/objeto | Assembly → código de máquina | Junta módulos objeto | Põe o programa na memória |

| | RAW | WAR | WAW |
|---|---|---|---|
| Tipo | Verdadeira | Falsa (nome) | Falsa (nome) |
| Solução | Forwarding / stall | Renomeação | Renomeação |

| | Superescalar | Superpipeline |
|---|---|---|
| Ideia | Largura (várias por ciclo) | Profundidade (estágios curtos) |

| | M.2 | NVMe |
|---|---|---|
| O que é | Formato físico | Protocolo sobre PCIe |

### 16.2 Perguntas de revisão (cubra a resposta e tente)

1. Quais são os 4 elementos do modelo de Von Neumann? **Memória, UC, ULA e entrada/saída.**
2. Qual a ideia do programa armazenado? **Instruções e dados ficam na mesma memória.**
3. Quais as etapas do ciclo de instrução? **Busca, decodificação, execução.**
4. Qual a função da ULA? **Fazer as operações aritméticas e lógicas.**
5. Quem faz o quê? **A memória guarda; B UC controla; C ULA calcula; D entrada recebe; E saída apresenta.**
6. Qual a diferença entre arquitetura e organização? **Arquitetura = o que o programador enxerga (ISA); organização = como é implementado.**
7. Em um barramento, o que define quanta memória se endereça? **A largura do barramento de endereços (2^n).**
8. Por que existe o ciclo T2? **A memória é mais lenta e precisa de tempo.**
9. Por que o load-use exige stall? **O dado ainda não saiu da memória.**
10. O que a renomeação elimina? **WAR e WAW.**

### 16.3 Mini-exercícios com resolução

| Exercício | Resolução |
|---|---|
| 374 em binário | 374 = 256+64+32+16+4+2 = `101110110` |
| Período de 10 ns, frequência? | 1 / 10 ns = **100 MHz** |
| 10.000 instr., 100.000 ciclos, 5 MHz | CPI 10 × 0,2 µs = **2 µs** por instrução |
| PCIe 4.0 x16 | 16 × 16 GT/s ÷ 8 = **32 GB/s por direção** |
| PCIe 5.0 x16 | 16 × 32 ÷ 8 = **64 GB/s por direção** (128 se somar as duas direções) |
| DDR5-5600 dual channel | 5600 × 64 ÷ 8 × 2 = **89.600 MB/s = 89,6 GB/s** |
| 1 GB a 550 MB/s | 1000 ÷ 550 ≈ **1,8 s** |
| Speedup, 5 estágios, 100 instr. | 500 ÷ 104 ≈ **4,8** |
| IPC com 14 ciclos para 10 instr. | 10 ÷ 14 ≈ **0,71** |
| 20 bits de endereço | 2^20 = **1 MB** |
| 24 bits de endereço | 2^24 = **16 MB** |

### 16.4 Pontos em que os slides se contradizem ou faltam

- **Lei de Moore:** um slide fala em 18 meses, outro em 2 anos.
- **Transistores do 8080:** números diferentes entre arquivos de processadores.
- **PCIe Gen5 x16:** 64 GB/s (tabela) × 128 GB/s (fechamento/E/S).
- **SATA 3:** 550 MB/s (barramentos) × ~600 MB/s (E/S).
- A **Parte 4** (Stallings) citada nas aulas **não foi enviada**.

> 💡 **Dica**: Na prova, mostre a conta e diga a unidade (por direção ou total, MB/s ou Gb/s). Assim a resposta fica defensável mesmo se o slide divergir.


---

## 17. Tabela de conversão: decimal, binário, hexadecimal e DCB (BCD)
*(Fonte: seções 7 e 8 (BCD, binário, hexa) + tabela gerada por mim para consulta rápida (observação minha, não está nos slides))*

### 17.1 Os 16 símbolos básicos (nibble = 4 bits)

Um **nibble** (4 bits) vale de 0 a 15 e corresponde a **1 dígito hexadecimal**. É a base de toda conversão binário ↔ hexa.

| Decimal | Binário (4 bits) | Hexadecimal | DCB/BCD (8421) |
|---|---|---|---|
| 0 | `0000` | `0` | `0000` |
| 1 | `0001` | `1` | `0001` |
| 2 | `0010` | `2` | `0010` |
| 3 | `0011` | `3` | `0011` |
| 4 | `0100` | `4` | `0100` |
| 5 | `0101` | `5` | `0101` |
| 6 | `0110` | `6` | `0110` |
| 7 | `0111` | `7` | `0111` |
| 8 | `1000` | `8` | `1000` |
| 9 | `1001` | `9` | `1001` |
| 10 | `1010` | `A` | **inválido** (só 0000 a 1001 são dígitos BCD) |
| 11 | `1011` | `B` | **inválido** (só 0000 a 1001 são dígitos BCD) |
| 12 | `1100` | `C` | **inválido** (só 0000 a 1001 são dígitos BCD) |
| 13 | `1101` | `D` | **inválido** (só 0000 a 1001 são dígitos BCD) |
| 14 | `1110` | `E` | **inválido** (só 0000 a 1001 são dígitos BCD) |
| 15 | `1111` | `F` | **inválido** (só 0000 a 1001 são dígitos BCD) |

> ⚠️ **Atenção**: **Pegadinha:** DCB/BCD codifica **cada dígito decimal** em 4 bits. Os códigos `1010` a `1111` **não existem** em BCD.

### 17.2 Tabela de 0 a 32 (consulta rápida)

| Decimal | Binário (8 bits) | Hexadecimal | DCB/BCD |
|---|---|---|---|
| 0 | `00000000` | `00` | `0000` |
| 1 | `00000001` | `01` | `0001` |
| 2 | `00000010` | `02` | `0010` |
| 3 | `00000011` | `03` | `0011` |
| 4 | `00000100` | `04` | `0100` |
| 5 | `00000101` | `05` | `0101` |
| 6 | `00000110` | `06` | `0110` |
| 7 | `00000111` | `07` | `0111` |
| 8 | `00001000` | `08` | `1000` |
| 9 | `00001001` | `09` | `1001` |
| 10 | `00001010` | `0A` | `0001 0000` |
| 11 | `00001011` | `0B` | `0001 0001` |
| 12 | `00001100` | `0C` | `0001 0010` |
| 13 | `00001101` | `0D` | `0001 0011` |
| 14 | `00001110` | `0E` | `0001 0100` |
| 15 | `00001111` | `0F` | `0001 0101` |
| 16 | `00010000` | `10` | `0001 0110` |
| 17 | `00010001` | `11` | `0001 0111` |
| 18 | `00010010` | `12` | `0001 1000` |
| 19 | `00010011` | `13` | `0001 1001` |
| 20 | `00010100` | `14` | `0010 0000` |
| 21 | `00010101` | `15` | `0010 0001` |
| 22 | `00010110` | `16` | `0010 0010` |
| 23 | `00010111` | `17` | `0010 0011` |
| 24 | `00011000` | `18` | `0010 0100` |
| 25 | `00011001` | `19` | `0010 0101` |
| 26 | `00011010` | `1A` | `0010 0110` |
| 27 | `00011011` | `1B` | `0010 0111` |
| 28 | `00011100` | `1C` | `0010 1000` |
| 29 | `00011101` | `1D` | `0010 1001` |
| 30 | `00011110` | `1E` | `0011 0000` |
| 31 | `00011111` | `1F` | `0011 0001` |
| 32 | `00100000` | `20` | `0011 0010` |

### 17.3 Valores que aparecem muito

| Decimal | Binário | Hexadecimal | DCB/BCD | Por que importa |
|---|---|---|---|---|
| 48 | `110000` | `30` | `0100 1000` | Código ASCII de '0' |
| 64 | `1000000` | `40` | `0110 0100` | 2⁶ |
| 65 | `1000001` | `41` | `0110 0101` | ASCII de 'A' |
| 97 | `1100001` | `61` | `1001 0111` | ASCII de 'a' |
| 99 | `1100011` | `63` | `1001 1001` | BCD ≠ binário |
| 100 | `1100100` | `64` | `0001 0000 0000` | BCD: 3 dígitos |
| 127 | `1111111` | `7F` | `0001 0010 0111` | Maior inteiro de 8 bits com sinal |
| 128 | `10000000` | `80` | `0001 0010 1000` | 2⁷ (bit de sinal) |
| 255 | `11111111` | `FF` | `0010 0101 0101` | Maior valor de 8 bits sem sinal (1 byte) |
| 256 | `100000000` | `100` | `0010 0101 0110` | 2⁸ (precisa de 9 bits) |
| 374 | `101110110` | `176` | `0011 0111 0100` | Exemplo do slide (seção 7.5) |
| 1000 | `1111101000` | `3E8` | `0001 0000 0000 0000` | 10³ |
| 1023 | `1111111111` | `3FF` | `0001 0000 0010 0011` | 2¹⁰ − 1 |
| 1024 | `10000000000` | `400` | `0001 0000 0010 0100` | 2¹⁰ (1 KiB) |
| 4095 | `111111111111` | `FFF` | `0100 0000 1001 0101` | 2¹² − 1 (FFF) |
| 65535 | `1111111111111111` | `FFFF` | `0110 0101 0101 0011 0101` | Maior valor de 16 bits sem sinal |

> 💡 **Dica**: Conferência com a seção 7.5: **374 = `101110110` = `176` hexa = BCD `0011 0111 0100`**. Repare como o BCD tem 12 bits e o binário puro, 9.

### 17.4 Como converter (passo a passo)

**Decimal → binário (divisões sucessivas por 2, lendo os restos de baixo para cima):**

```
Exemplo: 45
45 / 2 = 22  resto 1   (menos significativo)
22 / 2 = 11  resto 0
11 / 2 =  5  resto 1
 5 / 2 =  2  resto 1
 2 / 2 =  1  resto 0
 1 / 2 =  0  resto 1   (mais significativo)
Lendo de baixo para cima: 101101   -> 45 = 101101b
Prova: 32 + 8 + 4 + 1 = 45
```

**Binário → decimal (soma das potências de 2 onde há bit 1):**

```
Pesos:  128  64  32  16   8   4   2   1
Bits:     0   0   1   0   1   1   0   1     -> 32 + 8 + 4 + 1 = 45
```

**Binário ↔ hexadecimal (agrupe de 4 em 4, a partir da direita):**

```
0010 1101  ->  2 D  ->  2Dh        (45 em decimal)
1011 1111  ->  B F  ->  BFh        (191)
Hexa -> binário: cada dígito vira 4 bits:  A5h -> 1010 0101
```

**Decimal → hexadecimal (divisões por 16):**

```
Exemplo: 255
255 / 16 = 15 resto 15 (F)
 15 / 16 =  0 resto 15 (F)     -> FFh
Ou: converta para binário (11111111) e agrupe: 1111 1111 -> FF
```

**Hexadecimal → decimal (pesos 16⁰, 16¹, 16²...):**

```
2Dh = 2 x 16 + 13 = 45          1A3h = 1 x 256 + 10 x 16 + 3 = 419
```

**Decimal → DCB/BCD (cada dígito separado, 4 bits cada):**

```
Exemplo: 259  ->  2     5     9
                 0010  0101  1001      -> 0010 0101 1001 (BCD)
BCD -> decimal: leia grupos de 4 bits e escreva o dígito de cada um.
```

### 17.5 Binário puro × BCD (a comparação que confunde)

| | **Binário puro** | **BCD (DCB)** |
|---|---|---|
| Como codifica | O número inteiro em base 2 | **Cada dígito decimal** em 4 bits |
| 25 vira | `11001` (5 bits) | `0010 0101` (8 bits) |
| 99 vira | `1100011` | `1001 1001` |
| Uso | Cálculo interno da ULA | Relógios, calculadoras, displays de 7 segmentos |
| Desperdício | Nenhum | Usa 4 bits para valores 0 a 9 (6 combinações sobram) |

> 🏆 **Regra de ouro**: **Regra de ouro:** BCD **não é** o número em binário. É o **dígito decimal em binário**. Para 25: binário = `11001`; BCD = `0010 0101`.

**Potências de 2 para decorar:** 2⁰=1, 2¹=2, 2²=4, 2³=8, 2⁴=16, 2⁵=32, 2⁶=64, 2⁷=128, 2⁸=256, 2⁹=512, 2¹⁰=1024.

> 💡 **Dica**: A calculadora no início da página converte de verdade: digite um número em **Dec**, troque para **Bin** ou **Hex** e confira. Para BCD, converta cada dígito decimal à mão para 4 bits.
