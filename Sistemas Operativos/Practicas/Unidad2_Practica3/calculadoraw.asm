segment .data
    opc1 db '1.- Operacion Suma',0xa
    opc2 db '2.- Operacion Resta',0xa
    opc3 db '3.- Operacion Division',0xa
    opc4 db '4.- Operacion Multiplicacion',0xa
    opc db 'Opcion :',0
    soln1 db 'Numero 1 :',0
    soln2 db 'Numero 2 :',0
    nega db '-'
    notneg equ ($-nega)
    suma db 'Suma',10
    notsum equ ($-suma)
    resu db 'Resultado :',0
segment .bss
    longitud   resd 1
    handleConsola resd 1
    caractEscritos resd 1
    ultimoArgumento resd 1
    opcion resb 3
    num1 resb 50
    num2 resb 50
    esperadoDigito resb 100
    puntero resb 8
segment .text
global _main
    extern _GetStdHandle@4
    extern _ReadConsoleA@20
    extern _WriteConsoleA@20
    extern _ExitProcess@4
_main:
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
    push dword opc1
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
    push dword 20
    push dword opc2
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
    push dword 23
    push dword opc3
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
    push dword 29
    push dword opc4
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
    push dword 9
    push dword opc
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,2
    mov[longitud],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 3
    push dword opcion
    push dword [handleConsola]
    call _ReadConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 11
    push dword soln1
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,50
    mov[longitud],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 50
    push dword num1
    push dword [handleConsola]
    call _ReadConsoleA@20
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 11
    push dword soln2
    push dword [handleConsola]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,50
    mov[longitud],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 50
    push dword num2
    push dword [handleConsola]
    call _ReadConsoleA@20
    sub byte [opcion],'0'
    cmp byte [opcion],byte 1
    je operacionSuma
    cmp byte [opcion],byte 2
    je operacionResta
    cmp byte [opcion],byte 3
    je operacionDivision
    cmp byte [opcion],byte 4
    je operacionMultiplicacion
operacionSuma:
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 11
    push dword resu
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov eax, num1
    call atoi
    push eax
    mov eax, num2
    call atoi
    pop edx
    add eax,edx
    call imprimir
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    call _ExitProcess@4
operacionResta:
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 11
    push dword resu
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov eax, num1
    call atoi
    push eax
    mov eax, num2
    call atoi
    pop edx
    cmp eax,edx
    jg signo
    sub edx,eax
    mov eax, edx
    call imprimir
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    call _ExitProcess@4
signo:
    push eax
    push edx
    push dword-11
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword notneg
    push dword nega
    push dword [handleConsola]
    call _WriteConsoleA@20
    pop edx
    pop eax
    sub eax,edx
    call imprimir
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    call _ExitProcess@4
operacionDivision:
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 11
    push dword resu
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov eax, num1
    call atoi
    push eax
    mov eax, num2
    call atoi
    mov ebx,eax
    pop eax
    div ebx
    call imprimir
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    call _ExitProcess@4
operacionMultiplicacion:
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 11
    push dword resu
    push dword [handleConsola]
    call _WriteConsoleA@20
    mov eax, num1
    call atoi
    push eax
    mov eax, num2
    call atoi
    mov ebx,eax
    pop eax
    mul ebx
    call imprimir
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    call _ExitProcess@4
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
    mov ecx, esperadoDigito
    mov ebx, 10
    mov [ecx], ebx
    inc ecx
    mov [puntero], ecx
bucle1:
    mov edx, 0
    mov ebx, 10
    div ebx
    add edx, 48
    mov ecx, [puntero]
    mov [ecx], dl
    inc ecx
    mov [puntero], ecx
    cmp eax, 0
    jne bucle1
bucle2:
    mov ecx, [puntero]
    push dword-11
    xor eax,eax
    call _GetStdHandle@4
    mov [handleConsola],eax
    xor eax,eax
    mov eax,0d
    mov [ultimoArgumento],eax
    push dword [ultimoArgumento]
    push dword caractEscritos
    push dword 1
    push dword ecx
    push dword [handleConsola]
    call _WriteConsoleA@20;
    mov ecx, [puntero]
    dec ecx
    mov [puntero], ecx
    cmp ecx, esperadoDigito
    jge bucle2
    ret