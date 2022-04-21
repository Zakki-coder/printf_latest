NAME = libftprintf.a

INC =	-I./		\
		-I./libft/	\
	
SRC =	./ft_printf.c	\
		./libft/*.c	\

OBJ =	./*.o

${NAME}:
	@gcc -c ${SRC} ${INC}
	@ar -rc ${NAME} ${OBJ}

all: ${NAME}

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}

re: fclean all
