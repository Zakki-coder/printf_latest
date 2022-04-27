/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:46:30 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 18:41:06 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d\n", -42);
	ft_printf("%d\n", 0);
	ft_printf("%d\n", INT_MAX);
	ft_printf("%d\n", INT_MIN);
	ft_printf("%s\n", "MORO");
	ft_printf("%s\n", "M");
	ft_printf("%s\n", "Moro mita kuuluu ?    ");
	ft_printf("%s\n", "");


	// ft_printf("%p\n", p);
	// ft_printf("%p\n", pp);
}

	// int a;
	// int *p = &a;
	// int *pp;