section .data
    txt_soma   db "Soma (ADD):          "
    txt_sub    db "Subtracao (SUB):     "
    txt_mul    db "Multiplicacao (MUL): "
    txt_div    db "Divisao (DIV):       "
    txt_resto  db "Resto (DIV):         "
    tam_txt    equ 21 ; todos os textos tem 21 chars

    numero     db "000", 10  ; 3 dig. + quebra de linha

section .text
    global _start

_start:
    mov eax, 20 ; primeiro número
    mov ebx, 5 ; segundo número
    add eax, ebx ; eax = 20 + 5 = 25
    mov ecx, txt_soma
    call mostrar

    mov eax, 20
    mov ebx, 5
    sub eax, ebx ; eax = 20 - 5 = 15
    mov ecx, txt_sub
    call mostrar

    mov eax, 20
    mov ebx, 5
    mul ebx   ; eax = 20 * 5 = 100
    mov ecx, txt_mul
    call mostrar

    mov eax, 20
    mov ebx, 5
    mov edx, 0  ; zera edx antes da divisão
    div ebx  ; eax = 20/5 = 4 e edx = resto, que é 0
    mov edi, edx  ; guarda o resto em edi (mostrar usa edx)
    mov ecx, txt_div
    call mostrar

    mov eax, edi ; mostra o resto
    mov ecx, txt_resto
    call mostrar

    mov eax, 1 ; exit
    mov ebx, 0 ; codigo 0 = terminou sem erro
    int 80h

mostrar: ; imprime o txt apontado por ecx e dps o nº que está em eax
    mov esi, eax ; guarda o numero em esi, write usa eax

    mov eax, 4 ; write
    mov ebx, 1 ; 1 = tela
    mov edx, tam_txt ; tamanho do texto, ecx ja aponta para ele
    int 80h

    ; separa os 3 digitos: centena, dezena e unidade
    mov eax, esi
    mov edx, 0
    mov ebx, 100
    div ebx ; eax = centena, edx = resto
    add al, '0' ; número -> char ASCII
    mov [numero], al

    mov eax, edx
    mov edx, 0
    mov ebx, 10
    div ebx  ; eax = dezena, edx = unidade
    add al, '0'
    mov [numero + 1], al
    add dl, '0'
    mov [numero + 2], dl

    mov eax, 4  ; write
    mov ebx, 1
    mov ecx, numero
    mov edx, 4  ; 3 dig. + quebra linha
    int 80h
    ret
