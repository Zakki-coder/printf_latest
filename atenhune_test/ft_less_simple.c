/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:26:14 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:55:08 by atenhune         ###   ########.fr       */
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

	ft_printf("%s %s\n", "moro", "mita kuuluu");
	ft_printf("%s %s %s\n", "moro", "mita kuuluu", "?");
	ft_printf("%s %s %s %s %s\n", "moro", "", "mita", "SInulle", "kuuluu");
	ft_printf("%s %s %s %s %s %s %s %s %s %s %s %s %s\n", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13");
	ft_printf("%s %s\n", "?", "!", NULL);

	ft_printf("%d %d %d %d\n", 1, 2, 4, 5);
	ft_printf("%d %d %d %d\n", -1, -2, -4, -5);
	ft_printf("%d %d %d %d\n", 0, 0, 0, -0);
	ft_printf("%d %d %d %d\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN);
	ft_printf("%d %d %d %d\n", 1, 2, 2, 2);
	ft_printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 2, 2, 4, 2, 222222, 4444, 4, 10, -123123123, 1);

	ft_printf("%p %p\n", p, pp);
	ft_printf("HELOO%p %pWORLD\n", p, pp);
	ft_printf("HI%p WHATS%pUP\n", p, pp);
}