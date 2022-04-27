#!/bin/bash
gcc simple.c ../libftprintf.a
./a.out > test_output
gcc ft_simple.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > simple_diff
gcc compare.c
./a.out simple_diff SIMPLE_TESTS

gcc less_simple.c ../libftprintf.a
./a.out > test_output
gcc ft_less_simple.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > less_simple_diff
gcc compare.c
./a.out less_simple_diff LESS_SIMPLE_TESTS

gcc slightly_complicated.c ../libftprintf.a
./a.out > test_output
gcc ft_slightly_complicated.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > slightly_complicated_diff
gcc compare.c
./a.out slightly_complicated_diff SLIGHTLY_COMPLICATED

gcc complicated.c ../libftprintf.a
./a.out > test_output
gcc ft_complicated.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > complicated_diff
gcc compare.c
./a.out complicated_diff COMPLICATED

gcc -w more_complicated.c ../libftprintf.a
./a.out > test_output
gcc -w ft_more_complicated.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > more_complicated_diff
gcc -w compare.c
./a.out more_complicated_diff MORE_COMPLICATED

gcc -w more_stuff.c ../libftprintf.a
./a.out > test_output
gcc -w ft_more_stuff.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > more_stuff_diff
gcc -w compare.c
./a.out more_stuff_diff MORE_STUFF

gcc -w dot.c ../libftprintf.a
./a.out > test_output
gcc -w ft_dot.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > dot_diff
gcc -w compare.c
./a.out dot_diff DOT

gcc -w undefined.c ../libftprintf.a
./a.out > test_output
gcc -w ft_undefined.c ../libftprintf.a
./a.out > ft_test_output
diff -y test_output ft_test_output > undefined_diff
gcc -w compare.c
./a.out undefined_diff UNDEFINED

# rm simple_diff less_simple_diff slightly_complicated_diff complicated_diff more_complicated_diff more_stuff_diff dot_diff undefined_diff test_output ft_test_output a.out
