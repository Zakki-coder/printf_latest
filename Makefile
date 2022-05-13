NAME = libftprintf.a

INC =	-I./includes/			\
		-I./libft/				\
	
SRC =	./ft_printf.c			\
		./float_to_ascii.c		\
		./put_string.c			\
		./put_pointer_address.c \
		./float_part_1.c		\
		./libft/*.c				\

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
