#!/bin/bash
#compile withe simple_test
mkdir -p test_results
gcc simple_test.c ft_printf.c float_to_ascii.c put_string.c ./libft/*.c -I./includes -I./libft/
./a.out
