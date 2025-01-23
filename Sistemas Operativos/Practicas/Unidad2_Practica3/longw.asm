segment .data
    mensaje_entrada db 'Ingrese una cadena: ', 0
    mensaje_longitud db 'La longitud de la cadena es: ', 0
segment .bss
    espDig   resd 100
    handleConsola   resd 1
    caracteresEscritos  resd 1
    tamanoCadena    resd 1
    argumentoFinal  resd 1
    bufferCadena    resb 100
    punteroDigito   resd 1
segment .text
global _main
    extern _GetStdHandle@4
    extern _ReadConsoleA@20
    extern _WriteConsoleA@20
    extern _ExitProcess@4
_main:
    push dword -11
    call _GetStdHandle@4
    mov [handleConsola], eax
    xor eax, eax
    mov eax, 0d
    mov [argumentoFinal], eax
    push dword [argumentoFinal]
    push dword caracteresEscritos
    push dword 20
    push dword mensaje_entrada
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleConsola], eax
    xor eax, eax
    mov eax, 100d
    mov [tamanoCadena], eax
    xor eax, eax
    mov eax, 0d
    mov [argumentoFinal], eax
    push dword [argumentoFinal]
    push dword caracteresEscritos
    push dword [tamanoCadena]
    push dword bufferCadena
    push dword [handleConsola]
    call _ReadConsoleA@20
    push dword -11
    call _GetStdHandle@4
    mov [handleConsola], eax
    xor eax, eax
    mov eax, 0d
    mov [argumentoFinal], eax
    push dword [argumentoFinal]
    push dword caracteresEscritos
    push dword 28
    push dword mensaje_longitud
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov edi, bufferCadena
    call calcular_longitud
    sub eax, 2               
    call imprimir_resultado
    xor eax, eax
    mov eax, 0d
    mov [argumentoFinal], eax
    push dword [argumentoFinal]
    call _ExitProcess@4
imprimir_resultado:
    mov ecx, espDig
    mov ebx, 10        
    mov [ecx], ebx
    inc ecx
    mov [punteroDigito], ecx
convertir_a_ascii:
    mov edx, 0
    mov ebx, 10
    div ebx                
    add edx, 48              
    mov ecx, [punteroDigito]
    mov [ecx], dl
    inc ecx
    mov [punteroDigito], ecx
    cmp eax, 0
    jne convertir_a_ascii
imprimir_digitos:
    mov ecx, [punteroDigito]             
    push dword -11
    xor eax, eax
    call _GetStdHandle@4
    mov [handleConsola], eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 1
    push dword ecx
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov ecx, [punteroDigito]
    dec ecx
    mov [punteroDigito], ecx
    cmp ecx, espDig
    jge imprimir_digitos
    ret
calcular_longitud:
    xor ecx, ecx
contar_caracteres:
    cmp [edi], byte0
    je fin
    inc ecx
    inc esi
    jmp contar_caracteres
fin:
    mov eax, ecx
    ret
