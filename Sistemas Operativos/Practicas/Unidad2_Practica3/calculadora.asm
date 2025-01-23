section .data 
    opc1 db '1.- Operacion Suma',0xa
    opc2 db '2.- Operacion Resta',0xa
    opc3 db '3.- Operacion Division',0xa
    opc4 db '4.- Operacion Multiplicacion',0xa
    opc db 'Opcion ',0
    opcl equ ($-opc)
    soln1 db 'Numero 1 :',0
    soln2 db 'Numero 2 :',0
    nega db '-'
    notneg equ ($-nega)
    suma db 'Suma',10
    sumal equ ($-suma)
    resu db 'Resultado :',0
section .bss
    opcion resb 2
    num1 resb 50
    num2 resb 50
    espDigito resb 100
    posDigito resb 8
section .text
global _start
_start:
    mov edx, 19
    mov ecx, opc1
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 20
    mov ecx, opc2
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 23
    mov ecx, opc3
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 29
    mov ecx, opc4
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 9
    mov ecx, opc
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 2
    mov ecx, opcion
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edx, 11
    mov ecx, soln1
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, num1
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edx, 11
    mov ecx, soln2
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, num2
    mov ebx, 0
    mov eax, 3
    int 0x80
    sub byte [opcion], '0'
    cmp byte [opcion], byte 1
    je sum
    cmp byte [opcion], byte 2
    je res
    cmp byte [opcion], byte 3
    je divi
    cmp byte [opcion], byte 4
    je multi
sum:
    mov edx, 13
    mov ecx, resu
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov rax, num1
    call atoi
    push rax
    mov rax, num2
    call atoi
    pop rdx
    add rax, rdx
    call imprimir
    mov eax, 1
    int 0x80
res:
    mov edx, 13
    mov ecx, resu
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov rax, num1
    call atoi
    push rax
    mov rax, num2
    call atoi
    pop rdx
    cmp rax, rdx
    jg cambio
    sub rdx, rax
    mov rax, rdx
    call imprimir
    mov eax, 1
    int 0x80
cambio:
    push rax
    push rdx
    mov edx, notneg
    mov ecx, nega
    mov ebx, 1
    mov eax, 4
    int 0x80
    pop rdx
    pop rax
    sub rax, rdx
    call imprimir
    mov eax, 1
    int 0x80
divi:
    mov edx, 13
    mov ecx, resu
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov rax, num1
    call atoi
    push rax
    mov rax, num2
    call atoi
    mov rbx, rax
    pop rax
    div rbx
    call imprimir
    mov eax, 1
    int 0x80
multi:
    mov edx, 13
    mov ecx, resu
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov rax, num1
    call atoi
    push rax
    mov rax, num2
    call atoi
    mov rbx, rax
    pop rax
    mul rbx
    call imprimir
    mov eax, 1
    int 0x80
atoi:
    mov esi, eax
    mov eax, 0
    mov ecx, 0
.potencia10:
    xor ebx, ebx
    mov bl, [esi+ecx]
    cmp bl, 48
    jl .finatoi
    cmp bl, 57
    jg .finatoi
    cmp bl, 10
    je .finatoi
    cmp bl, 0
    jz .finatoi
    sub bl, 48
    add eax, ebx
    mov ebx, 10
    mul ebx
    inc ecx
    jmp .potencia10
.finatoi:
    mov ebx, 10
    div ebx
    ret
imprimir:
    mov rcx, espDigito
    mov rbx, 10
    mov [rcx], rbx
    inc rcx
    mov [posDigito], rcx
bucle:
    mov rdx, 0
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48
    mov rcx, [posDigito]
    mov [rcx], dl
    inc rcx
    mov [posDigito], rcx
    pop rax
    cmp rax, 0
    jne bucle
bucle2:
    mov rcx, [posDigito]
    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 1
    syscall
    mov rcx, [posDigito]
    dec rcx
    mov [posDigito], rcx
    cmp rcx, espDigito
    jge bucle2
    ret