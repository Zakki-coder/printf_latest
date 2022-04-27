NAME = libftprintf.a

INC =	-I./includes/		\
		-I./libft/	\
	
SRC =	./ft_printf.c	\
		./float_to_ascii.c	\
		./put_string.c	\
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
