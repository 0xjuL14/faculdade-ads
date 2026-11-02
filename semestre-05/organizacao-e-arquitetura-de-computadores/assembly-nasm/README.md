# Assembly NASM

Estudos de Assembly x86-64 no Linux usando NASM.

## Hello, World

Programa que imprime `Hello, World!` usando as syscalls `write` e `exit`.

### Como foi feito

1. Criei e editei o arquivo com o **nano**:
   ```bash
   nano hello.asm
   ```
2. Montei com o NASM (gera `hello.o`):
   ```bash
   nasm -f elf64 -o hello.o hello.asm
   ```
3. Linkei com o `ld` (gera o executável `hello`):
   ```bash
   ld hello.o -o hello
   ```
4. Executei:
   ```bash
   ./hello
   ```

### Código

```nasm
section .data
    mensagem db "Hello, World!"

section .text
    global _start

_start:
    mov rax, 1          ; syscall write
    mov rdi, 1          ; stdout
    mov rsi, mensagem   ; endereço da string
    mov rdx, 13         ; tamanho em bytes
    syscall

    mov rax, 60         ; syscall exit
    mov rdi, 0          ; código 0 = sucesso
    syscall
```

---

## Tabelas de consulta

### Estrutura do programa

| Elemento | Função | Observação |
|---|---|---|
| `section .data` | Guarda dados e constantes | Ex.: a string da mensagem |
| `section .text` | Guarda o código | Instruções ficam aqui |
| `global _start` | Torna o `_start` visível ao linker | Obrigatório |
| `_start:` | Ponto de entrada do programa | Equivale ao "início" do `main` |
| `db` | Define bytes | 1 caractere = 1 byte |

### Syscall (chamada de sistema)

Syscall é um pedido que o programa faz ao sistema operacional (imprimir, ler, abrir arquivo, encerrar). O número da syscall vai em `RAX` e a instrução `syscall` dispara a chamada.

| Syscall | RAX (número) | RDI (1º param.) | RSI (2º param.) | RDX (3º param.) |
|---|---|---|---|---|
| `write` | 1 | Onde escrever (fd) | Endereço da mensagem | Tamanho em bytes |
| `exit` | 60 | Código de saída | não usa | não usa |

### Descritores de arquivo (valor do RDI no write)

| Valor | Nome | Significado |
|---|---|---|
| 0 | stdin | Entrada padrão (teclado) |
| 1 | stdout | Saída padrão (tela) |
| 2 | stderr | Saída de erro |

### Código de saída (exit)

| Valor | Significado |
|---|---|
| 0 | Sucesso (como `return 0` em C) |
| Diferente de 0 | Erro |

### Registradores para parâmetros de syscall (Linux x86-64)

O número da syscall vai em `RAX`. Os argumentos seguem a ordem abaixo, e depois se executa `syscall`.

| Ordem | Registrador | Uso geral | No `write` | No `exit` |
|---|---|---|---|---|
| Número da syscall | RAX | Qual syscall chamar | 1 | 60 |
| 1º parâmetro | RDI | Primeiro argumento | fd (1 = tela) | código de saída |
| 2º parâmetro | RSI | Segundo argumento | endereço da mensagem | não usa |
| 3º parâmetro | RDX | Terceiro argumento | tamanho em bytes | não usa |
| 4º parâmetro | R10 | Quarto argumento | não usa | não usa |
| 5º parâmetro | R8 | Quinto argumento | não usa | não usa |
| 6º parâmetro | R9 | Sexto argumento | não usa | não usa |

> **Atenção:** em funções em C (convenção System V) o 4º parâmetro é o `RCX`.
> Em syscalls é o `R10`, porque a instrução `syscall` usa o `RCX` internamente
> para guardar o endereço de retorno.

| Contexto | 4º parâmetro |
|---|---|
| Função em C (System V) | RCX |
| Syscall Linux | R10 |

Referência: `man 2 syscall`, seção "Architecture calling conventions".

### Registrador e bits (família do RAX)

Registrador é a memória mais rápida da CPU. Cada nível é a metade do anterior.

| Nome | Tamanho | Bytes |
|---|---|---|
| RAX | 64 bits | 8 |
| EAX | 32 bits | 4 |
| AX | 16 bits | 2 |
| AH / AL | 8 bits | 1 |

O mesmo padrão vale para RBX/EBX/BX, RCX/ECX/CX e RDX/EDX/DX.

### Tamanho dos dados

| Unidade | Bits |
|---|---|
| 1 byte | 8 |
| 1 caractere ASCII | 1 byte |
| `"Hello, World!"` | 13 bytes |

### Montar vs. linkar

| Etapa | Ferramenta | Entrada | Saída | Executável? |
|---|---|---|---|---|
| Montar (assemble) | `nasm -f elf64` | `hello.asm` | `hello.o` | Não |
| Linkar | `ld` | `hello.o` | `hello` | Sim |

---

## Requisitos

- Linux 64 bits (x86_64). Confira com `uname -a`.
- NASM: `sudo apt install nasm`
- binutils (fornece o `ld`): `sudo apt install binutils`
