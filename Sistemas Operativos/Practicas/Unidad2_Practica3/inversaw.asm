segment .data
    instruccion db 'Digite 5 cadenas:',0
    mensaje db 'Cadena :',0
    concat db 'Cadena concatenada :',0
    inver db 'Cadena inversa :',0
    voca db 'Cantidad vocales :',0
    salto db 0xD, 0xA
    i db 0
    longitud dd 0
    vocales dd 0
segment .bss
    handleConsola resd 1
    caractEscritos resd 1
    longitudCadena resd 1
    ultimoArgumento resd 1
    cadena resb 101
    resultado resb 1000
    reversa resb 1000
    longitudStr resb 4
    vocalesStr resb 4
segment .text
global _main
    extern _GetStdHandle@4
    extern _WriteConsoleA@20
    extern _ReadConsoleA@20
    extern _ExitProcess@4
_main:
    mov edi, resultado
    mov byte[i], 0
    mov dword[longitud], 0
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 18
    push dword instruccion
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 2
    push dword salto
    push dword [handleConsola]
    call _WriteConsoleA@20
pedirCadenas:
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 9
    push dword mensaje
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,2
    mov[longitudCadena],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 101
    push dword cadena
    push dword [handleConsola]
    call _ReadConsoleA@20
    mov esi, cadena
    call copiarCadena
    inc byte[i]
    cmp byte[i], 5
    je imprimirResultado
    jne pedirCadenas
copiarCadena:
    mov dl, byte[esi]
    mov byte[edi], dl
    inc edi
    inc esi
    inc dword[longitud]
    call esVocal
    cmp byte[esi], 0xD
    jne copiarCadena
    ret
esVocal:
    cmp dl, 'a'
    je incrementarVocales
    cmp dl, 'e'
    je incrementarVocales
    cmp dl, 'i'
    je incrementarVocales
    cmp dl, 'o'
    je incrementarVocales
    cmp dl, 'u'
    je incrementarVocales
    cmp dl, 'A'
    je incrementarVocales
    cmp dl, 'E'
    je incrementarVocales
    cmp dl, 'I'
    je incrementarVocales
    cmp dl, 'O'
    je incrementarVocales
    cmp dl, 'U'
    je incrementarVocales
    ret
incrementarVocales:
    inc dword[vocales]
    ret
imprimirResultado:
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 21
    push dword concat
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword [longitud]
    push dword resultado
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 2
    push dword salto
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov esi, reversa
    dec edi
invertir:
    mov dl, byte[edi]
    mov byte[esi], dl
    dec edi
    inc esi
    cmp edi, resultado
    jl imprimirReversa
    jge invertir
    ret
imprimirReversa:          
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 17
    push dword inver
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword [longitud]
    push dword reversa
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 2
    push dword salto
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov ax, word[vocales]
    mov bx, 10
    mov cx, 0
    mov dx, 0
    mov edi, vocalesStr
enteroACadena:              
    mov bx, 10
    div bx
    add dx, '0'
    push dx
    inc cx
    mov dx, 0
    cmp ax, 0
    jne enteroACadena
guardarDigitos:
    pop dx
    mov [edi], dx
    inc edi
    dec cx
    cmp cx, 0
    jne guardarDigitos
imprimirVocales:
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 19
    push dword voca
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 4
    push dword vocalesStr
    push dword [handleConsola]
    call _WriteConsoleA@20
salida:
    push dword 0
    call _ExitProcess@4