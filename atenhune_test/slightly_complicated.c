/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slightly_complicated.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:42:07 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:56:20 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%%\n");
	printf("%i\n", 42);
	printf("%i\n", -42);
	printf("%i\n", 0);
	printf("%i\n", INT_MAX);
	printf("%i\n", INT_MIN);
	printf("%o\n", INT_MIN);
	printf("%o\n", INT_MAX);
	printf("%o\n", 0);
	printf("%o\n", 1);
	printf("%o\n", 8);
	printf("%o\n", 123213);
	printf("%o\n", 123212133);
	printf("%o\n", 123);
	printf("%o\n", 888888);
	printf("%u\n", INT_MIN);
	printf("%u\n", INT_MAX);
	printf("%u\n", 0);
	printf("%u\n", 1);
	printf("%u\n", 8);
	printf("%u\n", 123213);
	printf("%u\n", 123212133);
	printf("%u\n", 123);
	printf("%u\n", 888888);
	printf("%x\n", 8888881);
	printf("%x\n", 1);
	printf("%x\n", 88213888);
	printf("%x\n", 881);
	printf("%x\n", 8823881);
	printf("%x\n", 81);
	printf("%x\n", 16);
	printf("%x\n", 32);
	printf("%x\n", 132);
	printf("%x\n", 888822318);
	printf("%x\n", 0);
	printf("%x\n", 11);
	printf("%x\n", 15);
	printf("%x\n", 32);
	printf("%X\n", 8888881);
	printf("%X\n", 1);
	printf("%X\n", 88213888);
	printf("%X\n", 881);
	printf("%X\n", 8823881);
	printf("%X\n", 81);
	printf("%X\n", 16);
	printf("%X\n", 32);
	printf("%X\n", 132);
	printf("%X\n", 888822318);
	printf("%X\n", 0);
	printf("%X\n", 11);
	printf("%X\n", 15);
	printf("%X\n", 32);
	printf("%c\n", 32);
	printf("%c\n", 97);
	printf("%c\n", 98);
	printf("%c\n", 99);
	printf("%c\n", 100);
	printf("%c\n", 112);
	printf("%c\n", 70);
	printf("%c\n", 65);
	printf("%c\n", 111);
}

