/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complicated.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:52:53 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:54:51 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%c %s %d\n", 97, "hei", 0);
	printf("%c %s %d\n", 97, "hei", -2);
	printf("%c %s %d %s\n", 97, "hei", INT_MAX, NULL);
	printf("%c %s %d %i\n", 97, "hei", INT_MAX, INT_MIN);
	printf("%c %s %d %s %s %d\n", 97, "hei", INT_MAX, "1", "2", 0);
	printf("%c %s %d %x\n", 97, "hei", INT_MAX, 123332);
	printf("%c %s %d %x %X\n", 97, "hei", INT_MAX, 123332, 0);
	printf("%c %s %d %x %X %s \n", 97, "hei", INT_MAX, 123332, 12, "MOI");
	printf("%c %s %d %x %d %i %X\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321);
	printf("%c %s %d %x %d %i %X %s\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321 ,":)");
	printf("%c %s %d %x %d %i %X %c\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, 99);
	printf("%c %s %d %x %d %i %X %i\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, -123);
	printf("%c %s %d %x %d %i %X %i\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, 213);
	printf("%c %s %d %x %d %i %X %u\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, 123);
	printf("%c %s %d %x %d %i %X %i %c\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, -0, 97);
}