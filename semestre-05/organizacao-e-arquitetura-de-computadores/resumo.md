# Resumo — Arquitetura e Organização de Computadores

> Material de estudo baseado nos slides e nos três questionários de revisão.  
> **Prioridade:** CPU, memórias, barramentos, RISC/CISC, clock e placa-mãe.

---

## 1. Visão geral do computador

Um computador recebe dados, processa informações, armazena resultados e produz saídas.

```text
Entrada → Processamento → Saída
              ↕
           Memória
```

| Componente | Função | Exemplos |
|---|---|---|
| Entrada | Envia dados ao computador | Teclado, mouse, microfone |
| Processamento | Executa instruções e manipula dados | CPU |
| Memória | Guarda programas e dados em uso | RAM |
| Armazenamento | Guarda dados de forma persistente | SSD, HD |
| Saída | Apresenta resultados | Monitor, impressora |
| Barramentos | Conectam os componentes | CPU ↔ RAM ↔ E/S |

### Modelo de Von Neumann

O modelo de Von Neumann é a base dos computadores modernos:

- Dados e instruções ficam armazenados na memória.
- A CPU busca uma instrução, interpreta e executa a operação.
- O resultado pode voltar para a memória ou ser enviado para uma saída.
- Isso é o conceito de **programa armazenado**.

### Funções básicas do computador

1. **Processamento de dados:** cálculos e operações lógicas.
2. **Armazenamento de dados:** guardar dados temporária ou permanentemente.
3. **Movimentação de dados:** transferir informações entre CPU, memória e periféricos.
4. **Controle:** coordenar todas as atividades.

> **Pegadinha:** a classificação esperada é processamento, armazenamento, movimentação de dados e controle.

---

## 2. Arquitetura versus organização

| Arquitetura de computadores | Organização de computadores |
|---|---|
| Aspectos visíveis ao programador | Aspectos internos de implementação |
| ISA, registradores visíveis, bits, endereçamento | Sinais de controle, barramentos, caminho de dados, tecnologia de memória |
| Define o que a máquina oferece | Define como a máquina realiza isso |
| Relacionada à compatibilidade de software | Relacionada ao funcionamento interno |

### ISA

**ISA** (*Instruction Set Architecture*) é o conjunto de instruções que a CPU entende. É a interface entre software e hardware.

Exemplo: se existe uma instrução `ADD A, B`, a ISA define que a CPU deve interpretar aquilo como uma soma.

> **Como reconhecer na prova:** “visível ao programador” → arquitetura. “Sinais, circuitos, implementação interna” → organização.

---

## 3. CPU e ciclo de instrução

A **CPU** (*Central Processing Unit*) é responsável por interpretar e executar instruções.

| Componente | Função-chave |
|---|---|
| ULA/ALU | Executa operações aritméticas e lógicas |
| Unidade de Controle | Busca/decodifica instruções e gera sinais de controle |
| Registradores | Pequenas memórias internas muito rápidas |
| PC | Guarda o endereço da próxima instrução |
| IR/RI | Guarda a instrução atual |
| FPU | Executa operações de ponto flutuante |
| MMU | Traduz endereço virtual em endereço físico |
| Cache | Memória rápida próxima da CPU |

### ULA — Unidade Lógica e Aritmética

A ULA realiza:

- Soma, subtração e comparações.
- Operações lógicas: AND, OR, NOT.
- Manipulação de valores usados pelos programas.

> **Pegadinha:** a ULA calcula; ela não controla toda a execução e não armazena programas permanentemente.

### Unidade de Controle

A Unidade de Controle:

- Busca instruções na memória.
- Decodifica o significado das instruções.
- Gera sinais de controle.
- Coordena ULA, registradores, memória e E/S.
- Define a ordem das operações.

### Registradores

São pequenas áreas de armazenamento dentro da CPU:

- Muito rápidos.
- Baixa capacidade.
- Guardam valores temporários, instruções, resultados e endereços.

| Registrador | Função |
|---|---|
| PC — Program Counter | Endereço da próxima instrução |
| IR/RI — Instruction Register | Instrução que está sendo processada |
| MAR | Endereço de memória a acessar |
| MDR/MBR | Dado lido ou escrito na memória |
| Acumulador | Resultado temporário de operações |

### Ciclo de instrução

```text
Busca → Decodificação → Execução
```

1. **Busca:** CPU lê a instrução na memória.
2. **Decodificação:** Unidade de Controle interpreta a instrução.
3. **Execução:** ULA, registradores, memória ou E/S realizam a operação.

> **Pegadinha:** busca → execução → decodificação está errado. A CPU precisa decodificar antes de executar.

---

## 4. Memórias e hierarquia

A hierarquia de memória existe porque não há uma memória que seja simultaneamente enorme, extremamente rápida e barata.

```text
Registradores
     ↓
Cache
     ↓
RAM
     ↓
SSD / HD
```

| Nível | Velocidade | Capacidade | Custo por bit | Volátil? |
|---|---|---|---|---|
| Registradores | Muito alta | Muito baixa | Muito alto | Sim |
| Cache | Muito alta | Baixa | Alto | Sim |
| RAM | Alta | Média/alta | Médio | Sim |
| SSD/HD | Menor | Muito alta | Menor | Não |

### Regra da hierarquia

Quanto mais próxima da CPU estiver a memória:

- Maior velocidade.
- Menor capacidade.
- Maior custo por bit.
- Menor tempo de acesso.

```text
Mais perto da CPU = mais rápido + menor + mais caro por bit
Mais longe da CPU = mais lento + maior + mais barato por bit
```

### RAM

- É a memória principal.
- Guarda programas e dados em uso.
- É volátil: perde os dados sem energia.
- É mais rápida que SSD/HD.

### Cache

- Memória pequena e rápida próxima da CPU.
- Guarda temporariamente dados/instruções mais usados.
- Diminui a necessidade de acessar a RAM.

| Termo | Significado |
|---|---|
| Hit | O dado foi encontrado na cache |
| Miss | O dado não foi encontrado; deve ser buscado em nível inferior |
| Hit ratio | Proporção de acessos que encontraram o dado na cache |
| Tag | Identifica qual bloco da memória principal está em uma linha da cache |

### SRAM versus DRAM

| Característica | SRAM | DRAM |
|---|---|---|
| Velocidade | Mais rápida | Mais lenta |
| Custo por bit | Maior | Menor |
| Capacidade/densidade | Menor | Maior |
| Refresh | Não precisa | Precisa |
| Uso comum | Cache | RAM principal |

> **Pegadinha:** DRAM precisa de refresh; SRAM não precisa.

### ROM e memória não volátil

| Tipo | Característica |
|---|---|
| ROM | Conteúdo normalmente fixo |
| PROM | Programada uma vez |
| EPROM | Apagada por luz ultravioleta |
| EEPROM | Apagada e regravada eletricamente |
| Flash | Apagada e regravada eletricamente, geralmente em blocos |

A memória Flash é comum em SSDs, pendrives, cartões de memória e firmware.

### DDR4 e DDR5

| DDR4 | DDR5 |
|---|---|
| Geração anterior | Geração mais nova |
| Menor largura de banda | Maior largura de banda |
| Não encaixa em slot DDR5 | Não encaixa em slot DDR4 |

> **Pegadinha:** DDR4 e DDR5 não são intercambiáveis.

---

## 5. Barramentos

Barramentos são os caminhos de comunicação entre CPU, memória e periféricos.

| Barramento | Transporta | Direção típica | Pergunta para lembrar |
|---|---|---|---|
| Endereços | Localização de memória ou dispositivo | CPU → memória/E/S | Onde? |
| Dados | Valores, instruções e resultados | Bidirecional | O quê? |
| Controle | Sinais de leitura, escrita, clock e reset | Depende do sinal | Como/quando? |

### Barramento de endereços

Indica qual posição de memória ou qual dispositivo será acessado.

```text
CPU quer acessar a posição 1000
→ coloca 1000 no barramento de endereços
```

Em geral, é **unidirecional**, pois a CPU envia o endereço.

### Barramento de dados

Transporta dados, instruções e resultados.

É **bidirecional**:

- Na leitura, memória → CPU.
- Na escrita, CPU → memória.

### Barramento de controle

Carrega sinais que comandam as operações, como:

- Clock.
- Reset.
- Interrupção.
- Leitura de memória.
- Escrita de memória.

| Sinal | Significado |
|---|---|
| MEMR | *Memory Read*: leitura de memória |
| MEMW | *Memory Write*: escrita de memória |

### Mestre do barramento

No modelo básico, a CPU é o **mestre do barramento**:

- Inicia acessos.
- Coloca endereços.
- Ativa sinais de leitura/escrita.
- Coordena a transferência.

### Largura do barramento

A largura do barramento de dados define quantos bits são transferidos por ciclo.

| Largura | Transferência por ciclo |
|---|---|
| 8 bits | 1 byte |
| 16 bits | 2 bytes |
| 32 bits | 4 bytes |
| 64 bits | 8 bytes |
| 128 bits | 16 bytes |


a relação é:

\[
1\text{ byte} = 8\text{ bits}
\]

### Capacidade de endereçamento

Se há \(n\) linhas de endereço:

\[
\text{Quantidade de endereços} = 2^n
\]

Exemplo:

\[
2^{32} = 4.294.967.296\text{ endereços}
\]

### Leitura da memória

```text
1. CPU coloca o endereço no barramento de endereços.
2. CPU ativa o sinal de leitura: MEMR.
3. Memória localiza a posição indicada.
4. Memória coloca o dado no barramento de dados.
5. CPU recebe o dado.
```

### Escrita na memória

```text
1. CPU coloca o endereço no barramento de endereços.
2. CPU coloca o dado no barramento de dados.
3. CPU ativa o sinal de escrita: MEMW.
4. Memória grava o dado na posição indicada.
```

### Wait states

**Wait state** é um ciclo adicional de espera.

Ocorre quando a memória ou periférico é mais lento que a CPU e ainda não está pronto para concluir a transferência.

> **Pegadinha:** wait state não cancela a operação e não aumenta permanentemente o clock; apenas adiciona espera.

---

## 6. Clock e desempenho

O clock gera pulsos que sincronizam operações do sistema.

| Conceito | Significado |
|---|---|
| Frequência \(f\) | Quantidade de ciclos por segundo |
| Período \(T\) | Tempo de duração de um ciclo |

\[
f = \frac{1}{T}
\]

| Unidade | Equivalência |
|---|---|
| 1 MHz | \(10^6\) Hz |
| 1 GHz | \(10^9\) Hz |
| 1 µs | \(10^{-6}\) s |
| 1 ns | \(10^{-9}\) s |

Exemplo:

\[
T = 10\text{ ns}
\]

\[
f = \frac{1}{10 \times 10^{-9}} = 100\text{ MHz}
\]

### Tempo por instrução

\[
\text{Tempo por instrução} =
\frac{\text{ciclos por instrução}}{\text{frequência do clock}}
\]

Exemplo:

\[
\frac{100\text{ ciclos}}{50\text{ MHz}} = 2\text{ µs}
\]

> **Pegadinha:** clock maior não garante sozinho desempenho maior. Arquitetura, cache, IPC, núcleos, pipeline e memória também importam.

---

## 7. RISC, CISC e pipeline

| Característica | RISC | CISC |
|---|---|---|
| Instruções | Simples e regulares | Complexas e variadas |
| Execução | Mais previsível | Pode exigir mais ciclos |
| Pipeline | Mais favorecido | Mais complexo |
| Exemplos | ARM, MIPS, SPARC | x86 |
| Código | Pode precisar de mais instruções | Pode resolver mais com uma instrução |

### RISC

- *Reduced Instruction Set Computer*.
- Instruções simples e regulares.
- Boa eficiência energética.
- Favorece uso de pipeline.
- Comum em ARM, MIPS e SPARC.

### CISC

- *Complex Instruction Set Computer*.
- Mais instruções e instruções mais complexas.
- Uma instrução pode realizar várias operações.
- Exemplo clássico: x86.

### Pipeline

Pipeline sobrepõe etapas de várias instruções, como uma linha de montagem.

```text
Ciclo 1: Instrução 1 busca
Ciclo 2: Instrução 1 decodifica | Instrução 2 busca
Ciclo 3: Instrução 1 executa | Instrução 2 decodifica | Instrução 3 busca
```

> **Pegadinha:** RISC não significa código sempre menor; pode precisar de mais instruções simples.

---

## 8. Processadores e evolução

| Tema | Ideia principal |
|---|---|
| Válvulas → transistores | Computadores menores, mais confiáveis e mais econômicos |
| Circuitos integrados/VLSI | Muitos transistores integrados em um chip |
| Intel 4004 | Microprocessador comercial de 4 bits |
| Intel 8086 | Base histórica da família x86 |
| Intel 8088 | Usado no IBM PC original |
| AMD64 | Arquitetura de 64 bits compatível com x86 |
| Lei de Moore | Número de transistores historicamente dobrava em cerca de 18–24 meses |

### Processadores especializados

| Tecnologia | Uso |
|---|---|
| GPU | Gráficos e processamento paralelo |
| DSP | Processamento de sinais: áudio, vídeo e telecomunicações |
| FPGA | Hardware reconfigurável após a fabricação |
| NPU | Aceleração de inteligência artificial |
| FPU | Operações de ponto flutuante |
| MMU | Tradução de endereços virtuais e físicos |

### Arquitetura híbrida

Combina:

- Núcleos de alto desempenho para tarefas pesadas.
- Núcleos eficientes para tarefas leves e economia de energia.

---

## 9. Placa-mãe, chipset e firmware

A placa-mãe conecta CPU, RAM, armazenamento, placas de expansão e periféricos.

| Componente | Função |
|---|---|
| Socket | Interface física e elétrica onde a CPU é instalada |
| Northbridge | No modelo clássico, conecta CPU, RAM, cache e gráficos rápidos |
| Southbridge | No modelo clássico, lida com SATA, USB, áudio, rede e periféricos |
| VRM | Converte e regula energia fornecida à CPU |
| BIOS/UEFI | Firmware de inicialização do computador |
| Bateria CMOS | Mantém hora e configurações de BIOS/UEFI sem energia |

### BIOS e UEFI

Quando o computador é ligado, BIOS/UEFI:

1. Inicializa componentes.
2. Detecta hardware.
3. Verifica configurações.
4. Prepara o carregamento do sistema operacional.

> **Pegadinha:** BIOS/UEFI não é o sistema operacional.

### Formatos de placa-mãe

| Formato | Característica |
|---|---|
| ATX | Padrão, maior expansão |
| Micro-ATX | Menor que ATX |
| Mini-ITX | Compacto, comum em PCs pequenos |

---

## 10. Armazenamento: SATA, NVMe, M.2 e PCIe

| Termo | O que é | Ponto-chave |
|---|---|---|
| SATA | Interface de armazenamento | Usada por HDs e SSDs SATA; geralmente mais lenta que NVMe |
| NVMe | Protocolo para SSDs via PCIe | Alta velocidade e baixa latência |
| M.2 | Formato físico de módulo/conector | Pode usar SATA ou NVMe |
| PCIe | Interface de alta velocidade | Usada por NVMe e placas de expansão |

### PCI Express

PCIe utiliza **lanes**:

- PCIe x1, x4, x8 e x16.
- Mais lanes geralmente permitem maior largura de banda.

> **Pegadinha principal:** M.2 não significa obrigatoriamente NVMe. Existem SSDs M.2 SATA e SSDs M.2 NVMe.

---

## 11. Entrada e saída

| Tipo | Exemplos |
|---|---|
| Entrada | Teclado, mouse, scanner, microfone |
| Saída | Monitor, impressora, caixas de som |
| Entrada e saída | SSD/HD, pendrive, placa de rede, touchscreen |

### DMA

**DMA** (*Direct Memory Access*) permite transferência direta entre um dispositivo e a memória principal sem a CPU controlar cada byte.

Vantagem: libera a CPU para outras tarefas.

### Spooling

**Spooling** organiza tarefas de E/S em uma fila.

Exemplo:

```text
Vários documentos enviados para impressora
→ entram em uma fila
→ impressora executa um por vez
```

### Salvar um arquivo

```text
Programa solicita salvar
→ sistema operacional coordena a operação
→ driver/controlador atua
→ SSD ou HD grava os dados
```

---

## 12. Fórmulas e conversões

### Endereçamento

\[
\text{Quantidade de endereços} = 2^n
\]

### Bits e bytes

\[
1\text{ byte} = 8\text{ bits}
\]

### Frequência e período

\[
f = \frac{1}{T}
\]

\[
T = \frac{1}{f}
\]

### Tempo por instrução

\[
\text{Tempo por instrução} =
\frac{\text{ciclos por instrução}}{\text{frequência}}
\]

---

## 13. Pegadinhas principais

| Afirmação | Correção |
|---|---|
| RAM mantém dados sem energia | Errado: RAM é volátil |
| Cache é mais lenta que RAM | Errado: cache é mais rápida |
| DRAM não precisa de refresh | Errado: DRAM precisa de refresh |
| M.2 é sempre NVMe | Errado: M.2 é formato físico; pode ser SATA ou NVMe |
| Barramento de endereços é bidirecional | Errado: normalmente é unidirecional |
| Barramento de dados é bidirecional | Correto |
| Wait state cancela uma operação | Errado: apenas adiciona espera |
| ULA controla toda a execução | Errado: ULA calcula; Unidade de Controle coordena |
| Bateria CMOS mantém RAM ligada | Errado: mantém hora e configurações |
| Clock maior sempre significa CPU melhor | Errado: desempenho depende de vários fatores |
| RISC sempre gera código menor | Errado: pode exigir mais instruções simples |

---

## 14. Checklist final

- [ ] Diferenciar arquitetura de organização.
- [ ] Saber a função de ULA, Unidade de Controle, registradores, PC, IR, FPU e MMU.
- [ ] Memorizar a hierarquia: registradores → cache → RAM → SSD/HD.
- [ ] Comparar SRAM × DRAM e EPROM × Flash.
- [ ] Distinguir barramentos de endereços, dados e controle.
- [ ] Explicar leitura e escrita de memória com MEMR e MEMW.
- [ ] Resolver \(2^n\), conversão de bits/bytes, frequência/período e tempo por instrução.
- [ ] Comparar RISC × CISC e explicar pipeline.
- [ ] Reconhecer socket, chipset, VRM, BIOS/UEFI e bateria CMOS.
- [ ] Diferenciar M.2, SATA, NVMe e PCIe.
- [ ] Diferenciar DMA de spooling.
