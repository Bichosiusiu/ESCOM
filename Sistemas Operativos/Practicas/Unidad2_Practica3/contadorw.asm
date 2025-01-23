segment .data
    valor db 0               
    nueva_linea db 13, 10      
    mensaje db 'Numero: ', 0   
    hStdOut dd 0               
segment .bss
segment .text
global _main
    extern _GetStdHandle@4
    extern _WriteConsoleA@20
    extern _ExitProcess@4
_main:
    push -11                  
    call _GetStdHandle@4
    mov [hStdOut], eax         
    mov ecx, 1                 
cuenta_bucle:
    mov eax, [hStdOut]
    push 0                     
    push 7                    
    push mensaje               
    push eax                   
    call _WriteConsoleA@20
    mov al, [valor]           
    add al, '0'               
    mov [valor], al            
    mov eax, [hStdOut]
    push 0                   
    push 1                    
    push valor                 
    push eax                   
    call _WriteConsoleA@20
    mov eax, [hStdOut]
    push 0                     
    push 2                     
    push nueva_linea          
    push eax                   
    call _WriteConsoleA@20
    mov al, [valor]
    sub al, '0'               
    inc al                   
    mov [valor], al
    cmp al, 10
    jne cuenta_bucle          
fin_programa:
    push 0                     
    call _ExitProcess@4

