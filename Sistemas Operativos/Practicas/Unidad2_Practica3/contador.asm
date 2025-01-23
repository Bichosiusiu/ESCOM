section .data
    valor db 0            
    nueva_linea db 10     
section .text
global _start
_start:
    mov ebx, 1          
cuenta_bucle:
    mov al, [valor]     
    add al, '0'          
    mov [valor], al      
    mov eax, 4          
    mov ecx, valor      
    mov edx, 1          
    int 0x80             
    mov eax, 4           
    mov ecx, nueva_linea 
    mov edx, 1           
    int 0x80             
    mov al, [valor]      
    sub al, '0'          
    inc al               
    mov [valor], al     
    cmp al, 10
    jne cuenta_bucle    
fin_programa:
    mov eax, 1          
    xor ebx, ebx      
    int 0x80            

    
        
           
