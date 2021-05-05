                global  _ft_strlen
                section .text

_ft_strlen:  
                mov     rcx, 0
                cmp     rdi, 0
                je      end
                jmp     loop

loop:   
                cmp     byte [rdi + rcx], 0
                je      end
                inc     rcx
                jmp     loop

end:  
                mov     rax, rcx
                ret