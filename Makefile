NAME = libftprintf.a

INC =	-I./includes/			\
		-I./libft/				\
	
SRC =	./ft_printf.c				\
		./put_string.c				\
		./put_pointer_address.c 	\
		./float_part_1.c			\
		./float_part_2.c			\
		./float_part_3.c			\
		./get_format_utilities.c	\
		./parser_part_1.c			\
		./hexa.c					\
		./hexa_part_2.c				\
		./octal.c					\
		./octal_part_2.c			\
		./integer.c					\
		./libft/*.c					\

OBJ =	./*.o

${NAME}:
	@gcc -c ${SRC} ${INC}
	@ar -rc ${NAME} ${OBJ}

all: ${NAME}

clean:
	@rm -f *.o
	@rm -f ./libft/*.o

fclean: clean
	@rm -f ${NAME}
	@rm -f ./libft/libft.a 

re: fclean all
