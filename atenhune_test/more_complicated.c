/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_complicated.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:08:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:55:53 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%012d\n", 42);
	printf("% 012d\n", 42);
	printf("% 0-12d\n", 42);
	printf("%012d\n", -42);
	printf("% 012d\n", -42);
	printf("%012d\n", 0);
	printf("%+012d\n", 0);
	printf("%-01d\n", 0);
	printf("%+02d\n", 0);
	printf("%012d\n", INT_MAX);
	printf("%+012d\n", INT_MAX);
	printf("%+-012d\n", INT_MAX);
	printf("%+012d\n", INT_MIN);
	printf("%-01d\n", INT_MIN);
	printf("%-+012d\n", INT_MIN);
	printf("%012i\n", 42);
	printf("% 012i\n", 42);
	printf("%012i\n", -42);
	printf("%0 12i\n", -42);
	printf("%012i\n", 0);
	printf("%+012i\n", 0);
	printf("%-01i\n", 0);
	printf("%+02i\n", 0);
	printf("%012i\n", INT_MAX);
	printf("%+012i\n", INT_MAX);
	printf("%+-012i\n", INT_MAX);
	printf("%+012i\n", INT_MIN);
	printf("%-01i\n", INT_MIN);
	printf("%-+012i\n", INT_MIN);
	printf("%u\n", 0);
	printf("%12u\n", 0);
	printf("%012u\n", 0);
	printf("%02u\n", 0);
	printf("%01u\n", 0);
	printf("%030u\n", 0);
	printf("%-30u\n", 0);
	printf("%-030u\n", 0);
	printf("%u\n", 123);
	printf("%12u\n", 12345);
	printf("%012u\n", 11);
	printf("%02u\n", 65463456);
	printf("%01u\n", 3456);
	printf("%030u\n", 11324);
	printf("%-30u\n", 1234);
	printf("%-030u\n", 99912);
	printf("%-030x\n", 0);
	printf("%#x\n", 0);
	printf("%-30x\n", 0);
	printf("%-#30x\n", 0);
	printf("%030x\n", 0);
	printf("%0#30x\n", 0);
	printf("%-030x\n", 123);
	printf("%030x\n", 432134);
	printf("%03x\n", 12312);
	printf("%0#x\n", 12312);
	printf("%-030X\n", 0);
	printf("%-30X\n", 0);
	printf("%-#30X\n", 0);
	printf("%030X\n", 0);
	printf("%-030X\n", 123);
	printf("%-0#30X\n", 123);
	printf("%030X\n", 432134);
	printf("%03X\n", 12312);
	printf("%03o\n", 12312);
	printf("%03o\n", 0);
	printf("%#o\n", 0);
	printf("%#03o\n", 0);
	printf("%#03o\n", 0);
	printf("%0#3o\n", 0);
	printf("%-033o\n", 0);
	printf("%033o\n", 0);
	printf("%03o\n", INT_MAX);
	printf("%0o\n", UINT_MAX);
	printf("%-030o\n", UINT_MAX);
	printf("%-12o\n", UINT_MAX);

}