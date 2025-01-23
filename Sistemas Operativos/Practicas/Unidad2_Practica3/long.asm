section .data
    mensaje_entrada db "Ingrese la cadena :", 0
    mensaje_resultado db "Longitud:", 0
section .bss
    buffer_cadena resb 100
    buffer_digitos resb 10
    puntero_digitos resb 8
section .text
global _start
_start:
    mov edx, 20
    mov ecx, mensaje_entrada
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov edx, 100
    mov ecx, buffer_cadena
    mov ebx, 0
    mov eax, 3
    int 0x80
    mov edx, 23
    mov ecx, mensaje_resultado
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov rdi, buffer_cadena
    call calcular_longitud
    sub rax, 1 
    call mostrar_digitos
    mov rax, 60
    mov rdi, 0
    syscall
mostrar_digitos:
    mov rcx, buffer_digitos
    mov rbx,10
    mov [rcx], rbx  
    inc rcx
    mov [puntero_digitos], rcx      
convertir_a_ascii:
    mov rdx,0
    mov rbx,10     
    div rbx             
    push rax           
    add rdx, 48       
    mov rcx,[puntero_digitos]
    mov [rcx]  ,dl
    inc rcx     
    mov [puntero_digitos]  , rcx
    pop rax
    cmp rax,0
    jne convertir_a_ascii    
imprimir_digitos:
    mov rcx,[puntero_digitos]          
    mov rax,1
    mov rdi,1           
    mov rsi,rcx
    mov rdx,1
    syscall
    mov rcx,[puntero_digitos]
    dec rcx
    mov [puntero_digitos], rcx
    cmp rcx, buffer_digitos
    jge imprimir_digitos 
    ret
calcular_longitud:
    xor rcx, rcx      
calcular_siguiente:
    cmp [rdi], byte 0  
    jz fin_calculo
    inc rcx            
    inc rdi            
    jmp calcular_siguiente
fin_calculo:
    mov rax, rcx      
    ret

