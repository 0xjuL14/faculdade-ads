section .data ; definições de dados
; inicializações, const

	mensagem db 'Hello, Wold!' ; 13 bits de tamanho

; mensagem funcionará como um ponteiro na memória

section .text ; inicio do programa

	global _start

_start:
	mov rax, 1 ; identificador da chamada sys_write
	mov rdi, 1 ; saída padrão
	mov rsi, mensagem ; ponteiro
	mov rdx, 13 ; nº de bites
	syscall

	mov rax, 60 ; identificador da chamada sys_exit
	mov rdi, 0 ; se o programa executa com sucesso retorna 0
	syscall
