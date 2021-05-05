                global  _ft_strcpy
                section .text

_ft_strcpy:  
                cmp     rsi, 0
                je      end
                cmp     rdi, 0
                je      end
                mov     rdi, rsi
                ret

end:  
                mov     rdi, 0
                ret