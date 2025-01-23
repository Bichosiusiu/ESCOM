section .data
    msg_instruccion db 'Ingrese 5 cadenas:', 0
    msg_solicitar db 'Ingrese la cadena :', 0
    msg_concatenada db 'Cadena unida :', 0
    msg_inversa db 'Cadena invertida :', 0
    msg_vocales db 'Total vocales :', 0
    salto_linea db 0xa
    buffer_concatenado times 100 db ' '
section .bss
    temp_char resb 1
    longitud resb 1
    cadena_actual resb 50
    buffer_inverso resb 500
    contador_vocales resd 1
    num_cadenas resb 8
    digitos_vocales resb 100
section .text
global _start
_start:
    mov edx, 18
    mov ecx, msg_instruccion
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 1
    mov ecx, salto_linea
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 19
    mov ecx, msg_solicitar
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edi, buffer_concatenado
    mov edx, 50
    mov ecx, cadena_actual
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov esi, cadena_actual
    call encontrar_final
    times 4 call pedir_cadena
    mov rdi, buffer_concatenado
    call calcular_longitud
    mov [longitud], rax
    mov [temp_char], rax
    push temp_char
    mov edx, 15
    mov ecx, msg_concatenada
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, [temp_char]
    mov ecx, buffer_concatenado
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 1
    mov ecx, salto_linea
    mov ebx, 1
    mov eax, 4
    int 0x80
    call invertir_cadena
    mov edx, 18
    mov ecx, msg_inversa
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, [temp_char]
    mov ecx, buffer_inverso
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 17
    mov ecx, msg_vocales
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov eax, [contador_vocales]
    mov [digitos_vocales], eax
    call imprimir_numero
    mov eax, 1
    int 0x80
pedir_cadena:
    mov edx, 19
    mov ecx, msg_solicitar
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, cadena_actual
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov esi, cadena_actual
    inc edi
encontrar_final:
    cmp [esi], byte 0xa
    jz fin_lectura
    mov al, [esi]
    cmp al, 'a'
    je contar_vocal
    cmp al, 'e'
    je contar_vocal
    cmp al, 'i'
    je contar_vocal
    cmp al, 'o'
    je contar_vocal
    cmp al, 'u'
    je contar_vocal
    jmp siguiente_char
contar_vocal:
    add dword [contador_vocales], 1
siguiente_char:
    mov ecx, 1
    rep movsb
    jmp encontrar_final
calcular_longitud:
    xor rcx, rcx
recorrer:
    cmp [rdi], byte ' '
    jz finalizar
    inc rcx
    inc rdi
    jmp recorrer
finalizar:
    mov rax, rcx
    ret
imprimir_numero:
    mov rcx, digitos_vocales
    mov rbx, 10
    mov [rcx], rbx
    inc rcx
    mov [num_cadenas], rcx
imprimir_bucle:
    mov rdx, 0
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48
    mov rcx, [num_cadenas]
    mov [rcx], dl
    inc rcx
    mov [num_cadenas], rcx
    pop rax
    cmp rax, 0
    jne imprimir_bucle
imprimir_final:
    mov rcx, [num_cadenas]
    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 1
    syscall
    mov rcx, [num_cadenas]
    dec rcx
    mov [num_cadenas], rcx
    cmp rcx, digitos_vocales
    jge imprimir_final
    ret
invertir_cadena:    
    mov esi, buffer_concatenado
    sub esi, 1
invertir_bucle:
    cmp [esi], byte 0
    jz fin_inversion
    mov edi, buffer_inverso
    add edi, [temp_char]
    mov ecx, 1
    rep movsb
    sub byte [temp_char], 1
    jmp invertir_bucle
fin_inversion:
    ret
fin_lectura:
    sub edi,1
    ret