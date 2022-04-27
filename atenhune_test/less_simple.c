/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:26:14 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 18:16:33 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%s %s\n", "moro", "mita kuuluu");
	printf("%s %s %s\n", "moro", "mita kuuluu", "?");
	printf("%s %s %s %s %s\n", "moro", "", "mita", "SInulle", "kuuluu");
	printf("%s %s %s %s %s %s %s %s %s %s %s %s %s\n", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13");
	printf("%s %s\n", "?", "!", NULL);
	printf("%d %d %d %d\n", 1, 2, 4, 5);
	printf("%d %d %d %d\n", -1, -2, -4, -5);
	printf("%d %d %d %d\n", 0, 0, 0, -0);
	printf("%d %d %d %d\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN);
	printf("%d %d %d %d\n", 1, 2, 2, 2);
	printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 2, 2, 4, 2, 222222, 4444, 4, 10, -123123123, 1);
	// printf("%p %p\n", p, pp);
	// printf("HELOO%p %pWORLD\n", p, pp);
	// printf("HI%p WHATS%pUP\n", p, pp);
}
	// int a;
	// int *p = &a;
	// int *pp;





