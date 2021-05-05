                global  _ft_strcmp
                section .text

_ft_strcmp:  
                mov     rcx, -1 
                jmp     loop

loop:
                inc     rcx
                mov     dl, byte[rdi + rcx]
                cmp     byte[rsi + rcx], dl
                je      loop
                jmp     end

end:  
                movzx   rax, byte[rdi + rcx]
                movzx   rdx, byte[rsi + rcx]
                sub     rax, rdx
                ret