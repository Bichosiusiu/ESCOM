segment .data
    mensaje1 db 'Cadena 1 :', 0
    mensaje2 db 'Cadena 2 :', 0
    mensaje3 db 'Cadena 3 :', 0
    mensaje4 db 'Cadena 4 :', 0
    mensaje5 db 'Cadena 5 :', 0
    resultado db 'Resultado (intercalado)>', 0
    saltoLinea db 0xA
    longitudA dd 1
    longitudB dd 1
    longitudC dd 1
    longitudD dd 1
    longitudE dd 1
    longitudFinal dd 1
segment .bss
    handleCon resd 1
    charsEscritos resd 1
    tamanoCadena resd 1
    parametroFinal resd 1
    cadenaA resb 50
    cadenaB resb 50
    cadenaC resb 50
    cadenaD resb 50
    cadenaE resb 50
    cadenaFinal resb 150
segment .text
global _main
    extern _GetStdHandle@4
    extern _ReadConsoleA@20
    extern _WriteConsoleA@20
    extern _ExitProcess@4
_main:
    push dword -11
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 0
    mov [parametroFinal], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword 11
    push dword mensaje1
    push dword [handleCon]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 50
    mov [tamanoCadena], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword [tamanoCadena]
    push dword cadenaA
    push dword [handleCon]
    call _ReadConsoleA@20
    push dword -11
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 0
    mov [parametroFinal], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword 11
    push dword mensaje2
    push dword [handleCon]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 50
    mov [tamanoCadena], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword [tamanoCadena]
    push dword cadenaB
    push dword [handleCon]
    call _ReadConsoleA@20
    push dword -11
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 0
    mov [parametroFinal], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword 11
    push dword mensaje3
    push dword [handleCon]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 50
    mov [tamanoCadena], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword [tamanoCadena]
    push dword cadenaC
    push dword [handleCon]
    call _ReadConsoleA@20
    push dword -11
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 0
    mov [parametroFinal], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword 11
    push dword mensaje4
    push dword [handleCon]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 50
    mov [tamanoCadena], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword [tamanoCadena]
    push dword cadenaD
    push dword [handleCon]
    call _ReadConsoleA@20
    push dword -11
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 0
    mov [parametroFinal], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword 11
    push dword mensaje5
    push dword [handleCon]
    call _WriteConsoleA@20
    push dword -10
    call _GetStdHandle@4
    mov [handleCon], eax
    mov eax, 50
    mov [tamanoCadena], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword [tamanoCadena]
    push dword cadenaE
    push dword [handleCon]
    call _ReadConsoleA@20
    mov edi, cadenaA
    call _calcLength
    mov [longitudA], eax
    mov [longitudFinal], eax
    mov edi, cadenaB
    call _calcLength
    mov [longitudB], eax
    add [longitudFinal], eax
    mov edi, cadenaC
    call _calcLength
    mov [longitudC], eax
    add [longitudFinal], eax
    mov edi, cadenaD
    call _calcLength
    mov [longitudD], eax
    add [longitudFinal], eax
    mov edi, cadenaE
    call _calcLength
    mov [longitudE], eax
    add [longitudFinal], eax
    xor eax, eax
    mov edi, cadenaFinal
    jmp unirA
unirA:
    cmp eax, [longitudA]
    jge unirB
    mov esi, cadenaA
    add esi, eax
    mov ecx, 1
    rep movsb
unirB:
    cmp eax, [longitudB]
    jge unirC
    mov esi, cadenaB
    add esi, eax
    mov ecx, 1
    rep movsb
unirC:
    cmp eax, [longitudC]
    jge unirD
    mov esi, cadenaC
    add esi, eax
    mov ecx, 1
    rep movsb
unirD:
    cmp eax, [longitudD]
    jge unirE
    mov esi, cadenaD
    add esi, eax
    mov ecx, 1
    rep movsb
unirE:
    cmp eax, [longitudE]
    jge finConcatenacion
    mov esi, cadenaE
    add esi, eax
    mov ecx, 1
    rep movsb
    jmp finConcatenacion
finConcatenacion:
    add eax, 1
    cmp eax, [longitudFinal]
    jle unirA
    jmp fin
fin:
    push dword -11
    call _GetStdHandle@4
    mov [handleCon], eax
    xor eax, eax
    mov eax, 0
    mov [parametroFinal], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword 25
    push dword resultado
    push dword [handleCon]
    call _WriteConsoleA@20
    push dword -11
    call _GetStdHandle@4
    mov [handleCon], eax
    push dword [parametroFinal]
    push dword charsEscritos
    push dword [longitudFinal]
    push dword cadenaFinal
    push dword [handleCon]
    call _WriteConsoleA@20
    xor eax, eax
    push dword [parametroFinal]
    call _ExitProcess@4
_calcLength:
    mov ebx, edi
    xor al, al
    mov ecx, 0xffffffff
    repne scasb
    sub edi, ebx
    sub edi, 1
    mov eax, edi
    ret
