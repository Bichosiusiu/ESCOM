section .data
    prompt_cadena1 db "Ingrese Cadena 1 :", 0
    prompt_cadena2 db "Ingrese Cadena 2 :", 0
    prompt_cadena3 db "Ingrese Cadena 3 :", 0
    prompt_cadena4 db "Ingrese Cadena 4 :", 0
    prompt_cadena5 db "Ingrese Cadena 5 :", 0
    prompt_cadena6 db "Concatenada: ", 0
    len_cadena1 dd 0
    len_cadena2 dd 0
    len_cadena3 dd 0
    len_cadena4 dd 0
    len_cadena5 dd 0
    len_total dd 0
    nl db 0xa
section .bss
    input1 resb 50
    input2 resb 50
    input3 resb 50
    input4 resb 50
    input5 resb 50
    output_concat resb 150
section .text
global _start
_start:
    mov edx, 18
    mov ecx, prompt_cadena1
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, input1
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edx, 18
    mov ecx, prompt_cadena2
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, input2
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edx, 18
    mov ecx, prompt_cadena3
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, input3
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edx, 18
    mov ecx, prompt_cadena4
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, input4
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edx, 18
    mov ecx, prompt_cadena5
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 50
    mov ecx, input5
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edi, input1
    call strlen
    mov [len_cadena1], eax
    mov [len_total], eax
    mov edi, input2
    call strlen
    mov [len_cadena2], eax
    add [len_total], eax
    mov edi, input3
    call strlen
    mov [len_cadena3], eax
    add [len_total], eax
    mov edi, input4
    call strlen
    mov [len_cadena4], eax
    add [len_total], eax
    mov edi, input5
    call strlen
    mov [len_cadena5], eax
    add [len_total], eax
    mov eax, 0
    xor edi, edi
    mov edi, output_concat
    jmp copy1
copy1:
    cmp eax, [len_cadena1]
    jge copy2
    mov esi, input1
    add esi, eax
    mov ecx, 1
    rep movsb
copy2:
    cmp eax, [len_cadena2]
    jge copy3
    mov esi, input2
    add esi, eax
    mov ecx, 1
    rep movsb
copy3:
    cmp eax, [len_cadena3]
    jge copy4
    mov esi, input3
    add esi, eax
    mov ecx, 1
    rep movsb
copy4:
    cmp eax, [len_cadena4]
    jge copy5
    mov esi, input4
    add esi, eax
    mov ecx, 1
    rep movsb
copy5:
    cmp eax, [len_cadena5]
    jge end_copy
    mov esi, input5
    add esi, eax
    mov ecx, 1
    rep movsb
end_copy:
    add eax, 1
    cmp eax, [len_total]
    jle copy1
    mov edx, 28
    mov ecx, prompt_cadena6
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, [len_total]
    mov ecx, output_concat
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 1
    mov ecx, nl
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov eax, 1
    int 0x80
strlen:
    mov ebx, edi
    xor al, al
    mov ecx, 0xffffffff
    repne scasb
    sub edi, ebx
    sub edi, 2
    mov eax, edi
    ret
