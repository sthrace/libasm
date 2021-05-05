NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

TEST = main.c

OBJS = $(SRCS:.s=.o)

RM = rm -rf

%.o: %.s
	@nasm -f macho64 $<
	@echo "\033[0;35m\033[47m*********************\033[0m"
	@echo "\033[1;32mOBJECT FILE COMPILED\033[0m"

all: $(NAME)

$(NAME):	$(OBJS)
		@ar rc $(NAME) $(OBJS)
		@echo "\033[0;35m\033[47m*********************\033[0m"
		@echo "\033[1;34mLIBRARY CREATED\033[0m"
		@ranlib $(NAME)
		@echo "\033[0;35m\033[47m*********************\033[0m"
		@echo "\033[1;36mLIBRARY INDEXED\033[0m"

clean:		
		@$(RM) $(OBJS)
		@echo "\033[0;35m\033[47m*********************\033[0m"
		@echo "\033[1;31mOBJECT FILES REMOVED\033[0m"

fclean:		clean
		@$(RM) $(NAME) write_asm.txt write.txt test
		@echo "\033[0;35m\033[47m*********************\033[0m"
		@echo "\033[0;101mLIBRARY REMOVED\033[0m"

re:		fclean all

test: $(NAME) $(TEST)
		@gcc -g -Wall -Werror -Wextra main.c -L. -lasm -o test
		@echo "\033[0;35m\033[47m*********************\033[0m"
		@echo "\033[0;94mTEST FILE COMPILED\033[0m"
		@./test
		@echo "\033[0;93mTEST FILE COMPILED\033[0m"

.PHONY:		all clean fclean re
