# Calculadora em Assembly x86 (NASM)

Calculadora simples escrita em **Assembly x86 (32 bits)** com **NASM**. Ela faz as quatro operações básicas usando os registradores do processador e mostra os resultados na tela.

Projeto integrador (Q8) da atividade prática de **Organização e Arquitetura de Computadores**.

![Assembly](https://img.shields.io/badge/Assembly-x86-6F2EA8)
![NASM](https://img.shields.io/badge/montador-NASM-blue)
![Linux](https://img.shields.io/badge/Linux-int%2080h-yellow)

---

## Sumário

- [Requisitos do exercício](#requisitos-do-exercício)
- [Saída do programa](#saída-do-programa)
- [Como compilar e executar](#como-compilar-e-executar)
- [Como o programa funciona](#como-o-programa-funciona)
- [Explicação de cada operação](#explicação-de-cada-operação)
- [Como o número aparece na tela](#como-o-número-aparece-na-tela)
- [Registradores utilizados](#registradores-utilizados)
- [Limitações](#limitações)
- [Conceitos praticados](#conceitos-praticados)

---

## Requisitos do exercício

| # | Requisito | Onde aparece no código |
|---|---|---|
| 1 | Armazenar dois números em EAX e EBX | `mov eax, 20` e `mov ebx, 5` |
| 2 | Soma com `ADD` | `add eax, ebx` |
| 3 | Subtração com `SUB` | `sub eax, ebx` |
| 4 | Multiplicação com `MUL` | `mul ebx` |
| 5 | Divisão com `DIV` | `div ebx` |
| 6 | Registradores para armazenar e analisar os resultados | EAX (resultados), EDX/EDI (resto), ESI (cópia temporária) |
| 7 | Explicação do funcionamento | Este README |

---

## Saída do programa

```
Soma (ADD):          025
Subtracao (SUB):     015
Multiplicacao (MUL): 100
Divisao (DIV):       004
Resto (DIV):         000
```

> Os resultados sempre aparecem com **3 dígitos** (por isso o `025`). Veja em [Limitações](#limitações).

---

## Como compilar e executar

Testado no **Debian x86-64**. O código usa registradores de 32 bits e chamadas de sistema com `int 80h`, então ele é montado como **ELF de 32 bits**.

### 1. Instalar as ferramentas

```bash
sudo apt update
sudo apt install nasm binutils
```

- **nasm:** o montador, que transforma o `.asm` em código de máquina.
- **binutils:** traz o `ld`, o ligador, que gera o executável.

### 2. Montar, ligar e executar

```bash
nasm -f elf32 calculadora.asm -o calculadora.o   # montador: gera o objeto de 32 bits
ld -m elf_i386 calculadora.o -o calculadora      # ligador: gera o executável de 32 bits
./calculadora                                    # executa
```

### 3. Conferir

```bash
./calculadora; echo "código de saída: $?"   # deve terminar com "código de saída: 0"
file calculadora                            # deve mostrar "ELF 32-bit LSB executable, Intel 80386"
```

> **Por que 32 bits num Debian de 64 bits?** O Linux x86-64 consegue executar programas de 32 bits, graças à compatibilidade IA-32, que vem ativada por padrão no kernel do Debian. O `-f elf32` e o `-m elf_i386` dizem ao montador e ao ligador para gerar esse formato.

---

## Como o programa funciona

O programa usa dois números, **20 em EAX** e **5 em EBX**, e faz as quatro operações em sequência.

Antes de cada operação, os dois valores são **carregados de novo**. Isso é necessário porque cada operação guarda o resultado em EAX e apaga o valor anterior.

Depois de cada cálculo, o programa chama o procedimento `mostrar` com `CALL`. Ele imprime o nome da operação e o resultado, e depois volta com `RET` para a linha seguinte ao `CALL`. No final, a chamada de sistema `exit` encerra o programa com código 0.

```
_start
  ├── soma          → call mostrar
  ├── subtração     → call mostrar
  ├── multiplicação → call mostrar
  ├── divisão       → call mostrar (quociente)
  │                 → call mostrar (resto)
  └── exit(0)

mostrar
  ├── write: imprime o texto da operação
  ├── separa o número em centena, dezena e unidade (DIV)
  ├── write: imprime os 3 dígitos + quebra de linha
  └── ret
```

O código fica dividido em duas seções:

| Seção | O que guarda |
|---|---|
| `section .data` | Os textos de cada operação, o tamanho deles (`tam_txt equ 21`) e o espaço `numero` onde os dígitos são montados |
| `section .text` | O código: o ponto de entrada `_start` e o procedimento `mostrar` |

---

## Explicação de cada operação

| Operação | Instrução | Como funciona | Resultado |
|---|---|---|---|
| **Soma** | `add eax, ebx` | Soma EBX ao EAX e guarda o resultado no EAX, que é o primeiro operando | EAX = **25** |
| **Subtração** | `sub eax, ebx` | Subtrai EBX do EAX; o resultado fica no EAX | EAX = **15** |
| **Multiplicação** | `mul ebx` | O `MUL` recebe só um operando: multiplica o EAX pelo valor indicado. O EAX participa sem aparecer na instrução. O resultado fica no EAX, e a parte alta iria para o EDX (aqui ela é 0) | EAX = **100** |
| **Divisão** | `mov edx, 0` + `div ebx` | O `DIV` divide o valor formado por **EDX:EAX** pelo EBX. Por isso o EDX é zerado antes: se tivesse lixo, a divisão daria errado. O quociente fica no EAX e o resto no EDX | EAX = **4**, EDX = **0** |

### Detalhe da divisão

```asm
mov eax, 20
mov ebx, 5
mov edx, 0      ; parte alta do dividendo = 0  ->  dividendo = 20
div ebx         ; EAX = 20 / 5 = 4   e   EDX = resto = 0
mov edi, edx    ; guarda o resto em EDI, porque o procedimento mostrar usa o EDX
```

---

## Como o número aparece na tela

A chamada de sistema `write` só imprime **caracteres**, não números. Se o programa mandasse o valor 25 direto, a tela não mostraria "25". Por isso o procedimento `mostrar` separa o número em três dígitos usando o próprio `DIV`:

1. **Divide por 100:** o quociente é a **centena**, e o resto segue para o próximo passo.
2. **Divide esse resto por 10:** o quociente é a **dezena** e o resto é a **unidade**.
3. **Soma `'0'`** (código ASCII 48) a cada dígito. Assim o número 2 vira o caractere `'2'` (código 50).

Exemplo com **25**:

```
25 ÷ 100 = 0  resto 25   → centena = 0  → '0'
25 ÷ 10  = 2  resto 5    → dezena  = 2  → '2'
                         → unidade = 5  → '5'
Na tela: 025
```

Os três caracteres são gravados em `numero` (`[numero]`, `[numero + 1]` e `[numero + 2]`). O quarto byte já guarda o `10`, que é a quebra de linha (`\n`).

### Chamadas de sistema usadas (Linux 32 bits)

| Chamada | EAX | EBX | ECX | EDX |
|---|---|---|---|---|
| `write` | 4 | 1 (tela) | endereço do texto | quantidade de bytes |
| `exit` | 1 | código de saída (0 = sem erro) | – | – |

---

## Registradores utilizados

| Registrador | Função no programa |
|---|---|
| **EAX** | Primeiro número e resultado de todas as operações. No `write` e no `exit`, guarda o número da chamada de sistema |
| **EBX** | Segundo número (5). Dentro de `mostrar`, é o divisor (100 e 10) e o descritor da tela (1) |
| **ECX** | Endereço do texto que será impresso |
| **EDX** | Parte alta do dividendo e **resto** da divisão. No `write`, indica quantos bytes imprimir |
| **EDI** | Guarda o resto da divisão principal, porque `mostrar` reutiliza o EDX |
| **ESI** | Guarda o resultado enquanto o texto é impresso, porque o `write` usa o EAX |
| **EIP** e **ESP** | Usados implicitamente pelo `CALL` e pelo `RET`: o `CALL` empilha o endereço de retorno (topo apontado pelo ESP) e salta; o `RET` desempilha esse endereço de volta para o EIP |

---

## Limitações

- **Só mostra resultados de 0 a 999.** O procedimento `mostrar` separa apenas centena, dezena e unidade. Com 1000 ou mais, o dígito da centena sai errado.
- **Sem números negativos.** `MUL` e `DIV` trabalham com valores sem sinal. Se a subtração der negativa (por exemplo, 5 - 20), o resultado aparece errado.
- **Os números ficam fixos no código.** Para testar outros valores, é preciso editar os `mov eax, 20` e `mov ebx, 5` e montar de novo.
- **Divisão por zero.** Se EBX for 0, o `DIV` gera uma exceção e o programa é encerrado pelo sistema (erro de ponto flutuante, `SIGFPE`).

### Testando com outros números

Trocando para `mov eax, 50` e `mov ebx, 7` nos quatro blocos, a saída esperada é:

```
Soma (ADD):          057
Subtracao (SUB):     043
Multiplicacao (MUL): 350
Divisao (DIV):       007
Resto (DIV):         001
```

---

## Conceitos praticados

- Registradores de propósito geral do x86 (EAX, EBX, ECX, EDX, ESI, EDI)
- Instruções aritméticas: `ADD`, `SUB`, `MUL`, `DIV`
- Operandos implícitos (`MUL` e `DIV` usam EAX e EDX sem que eles apareçam na instrução)
- Procedimentos com `CALL` e `RET`, e o papel da pilha no endereço de retorno
- Seções `.data` e `.text`, constantes com `equ`
- Chamadas de sistema do Linux com `int 80h`
- Conversão de número para caractere ASCII
