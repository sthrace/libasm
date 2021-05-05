                global  _ft_strdup
                section .text
                extern ___error
                extern _malloc

_ft_strdup:  
                cmp     rdi, 0
                je      error
                mov     rcx, 0
                jmp     loop

loop:
                inc     rcx
                cmp     byte [rdi + rcx], 0
                je      allocate
                jmp     loop

allocate:
                push    rdi
                mov     rdi, rcx
                inc     rdi
                call    _malloc
                cmp     rax, 0
                je      error
                pop     rdi
                jmp     end

error:
                call	___error
			    mov		rax, 0
			    ret

end:
                mov     rax, rdi
                ret

