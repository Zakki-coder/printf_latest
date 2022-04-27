/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_complicated.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:08:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:55:15 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("%012d\n", 42);
	ft_printf("% 012d\n", 42);
	ft_printf("% 0-12d\n", 42);
	ft_printf("%012d\n", -42);
	ft_printf("% 012d\n", -42);
	ft_printf("%012d\n", 0);
	ft_printf("%+012d\n", 0);
	ft_printf("%-01d\n", 0);
	ft_printf("%+02d\n", 0);
	ft_printf("%012d\n", INT_MAX);
	ft_printf("%+012d\n", INT_MAX);
	ft_printf("%+-012d\n", INT_MAX);
	ft_printf("%+012d\n", INT_MIN);
	ft_printf("%-01d\n", INT_MIN);
	ft_printf("%-+012d\n", INT_MIN);

	ft_printf("%012i\n", 42);
	ft_printf("% 012i\n", 42);
	ft_printf("%012i\n", -42);
	ft_printf("%0 12i\n", -42);
	ft_printf("%012i\n", 0);
	ft_printf("%+012i\n", 0);
	ft_printf("%-01i\n", 0);
	ft_printf("%+02i\n", 0);
	ft_printf("%012i\n", INT_MAX);
	ft_printf("%+012i\n", INT_MAX);
	ft_printf("%+-012i\n", INT_MAX);
	ft_printf("%+012i\n", INT_MIN);
	ft_printf("%-01i\n", INT_MIN);
	ft_printf("%-+012i\n", INT_MIN);

	ft_printf("%u\n", 0);
	ft_printf("%12u\n", 0);
	ft_printf("%012u\n", 0);
	ft_printf("%02u\n", 0);
	ft_printf("%01u\n", 0);
	ft_printf("%030u\n", 0);
	ft_printf("%-30u\n", 0);
	ft_printf("%-030u\n", 0);
	ft_printf("%u\n", 123);
	ft_printf("%12u\n", 12345);
	ft_printf("%012u\n", 11);
	ft_printf("%02u\n", 65463456);
	ft_printf("%01u\n", 3456);
	ft_printf("%030u\n", 11324);
	ft_printf("%-30u\n", 1234);
	ft_printf("%-030u\n", 99912);

	ft_printf("%-030x\n", 0);
	ft_printf("%#x\n", 0);
	ft_printf("%-30x\n", 0);
	ft_printf("%-#30x\n", 0);
	ft_printf("%030x\n", 0);
	ft_printf("%0#30x\n", 0);
	ft_printf("%-030x\n", 123);
	ft_printf("%030x\n", 432134);
	ft_printf("%03x\n", 12312);
	ft_printf("%0#x\n", 12312);

	ft_printf("%-030X\n", 0);
	ft_printf("%-30X\n", 0);
	ft_printf("%-#30X\n", 0);
	ft_printf("%030X\n", 0);
	ft_printf("%-030X\n", 123);
	ft_printf("%-0#30X\n", 123);
	ft_printf("%030X\n", 432134);
	ft_printf("%03X\n", 12312);

	ft_printf("%03o\n", 12312);
	ft_printf("%03o\n", 0);
	ft_printf("%#o\n", 0);
	ft_printf("%#03o\n", 0);
	ft_printf("%#03o\n", 0);
	ft_printf("%0#3o\n", 0);
	ft_printf("%-033o\n", 0);
	ft_printf("%033o\n", 0);
	ft_printf("%03o\n", INT_MAX);
	ft_printf("%0o\n", UINT_MAX);
	ft_printf("%-030o\n", UINT_MAX);
	ft_printf("%-12o\n", UINT_MAX);

}