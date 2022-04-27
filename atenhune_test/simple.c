/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:46:30 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:56:00 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a;
	int *p = &a;
	int *pp;
	printf("%%\n");
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 0);
	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MIN);
	printf("%s\n", "MORO");
	printf("%s\n", "M");
	printf("%s\n", "Moro mita kuuluu ?    ");
	printf("%s\n", "");
	printf("%p\n", p);
	printf("%p\n", pp);
}