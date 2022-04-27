/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slightly_complicated.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:42:07 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:55:28 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("%%\n");
	ft_printf("%i\n", 42);
	ft_printf("%i\n", -42);
	ft_printf("%i\n", 0);
	ft_printf("%i\n", INT_MAX);
	ft_printf("%i\n", INT_MIN);

	ft_printf("%o\n", INT_MIN);
	ft_printf("%o\n", INT_MAX);
	ft_printf("%o\n", 0);
	ft_printf("%o\n", 1);
	ft_printf("%o\n", 8);
	ft_printf("%o\n", 123213);
	ft_printf("%o\n", 123212133);
	ft_printf("%o\n", 123);
	ft_printf("%o\n", 888888);

	ft_printf("%u\n", INT_MIN);
	ft_printf("%u\n", INT_MAX);
	ft_printf("%u\n", 0);
	ft_printf("%u\n", 1);
	ft_printf("%u\n", 8);
	ft_printf("%u\n", 123213);
	ft_printf("%u\n", 123212133);
	ft_printf("%u\n", 123);
	ft_printf("%u\n", 888888);

	ft_printf("%x\n", 8888881);
	ft_printf("%x\n", 1);
	ft_printf("%x\n", 88213888);
	ft_printf("%x\n", 881);
	ft_printf("%x\n", 8823881);
	ft_printf("%x\n", 81);
	ft_printf("%x\n", 16);
	ft_printf("%x\n", 32);
	ft_printf("%x\n", 132);
	ft_printf("%x\n", 888822318);
	ft_printf("%x\n", 0);
	ft_printf("%x\n", 11);
	ft_printf("%x\n", 15);
	ft_printf("%x\n", 32);

	ft_printf("%X\n", 8888881);
	ft_printf("%X\n", 1);
	ft_printf("%X\n", 88213888);
	ft_printf("%X\n", 881);
	ft_printf("%X\n", 8823881);
	ft_printf("%X\n", 81);
	ft_printf("%X\n", 16);
	ft_printf("%X\n", 32);
	ft_printf("%X\n", 132);
	ft_printf("%X\n", 888822318);
	ft_printf("%X\n", 0);
	ft_printf("%X\n", 11);
	ft_printf("%X\n", 15);
	ft_printf("%X\n", 32);
	
	ft_printf("%c\n", 32);
	ft_printf("%c\n", 97);
	ft_printf("%c\n", 98);
	ft_printf("%c\n", 99);
	ft_printf("%c\n", 100);
	ft_printf("%c\n", 112);
	ft_printf("%c\n", 70);
	ft_printf("%c\n", 65);
	ft_printf("%c\n", 111);
}

