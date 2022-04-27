/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undefined.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:01:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 14:09:17 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("%llllllllld\n", LLONG_MAX);
	ft_printf("%llllllllld\n", 0ll);
	ft_printf("%llllllhhhhllld\n", 0ll);
	ft_printf("%++++++00000llllllllld\n", 0ll);
	ft_printf("%++++++00000llllllllld\n", 0ll);
	ft_printf("%++++++00000llllllllld\n", 0ll);
	ft_printf("%++++++00000llllllllld\n", 0ll);
	ft_printf("%++++++00000llllllllld\n", 0ll);
	ft_printf("%++++++00000llllllllld\n", 123);
	ft_printf("%++++++#+ 00000lllllllllu\n", 123u);
	ft_printf("%++++++#+ 00000lllllllll\n", 123u);
	ft_printf("%0-12s\n", "MORO");
	ft_printf("%0#-12s\n", "MORO");
	ft_printf("%0-12s\n", NULL);
	ft_printf("%0-12\n", "moi");
	ft_printf("%0-12\n", "moi");
	ft_printf("%0-12%\n", "moi");
	ft_printf("%%%\n", "moi");
	ft_printf("%# +u\n", 123);
	ft_printf("%# +x\n", 123);
	ft_printf("%# +X\n", 123);
	ft_printf("%# +    u\n", 123);
	ft_printf("%# +    o\n", 123);
	ft_printf("%# +  z  o\n", 123);
	ft_printf("%# +  z  x\n", 123);
	ft_printf("%# +  z  X\n", 123);
	ft_printf("%# +  zj  o\n", 123);
	ft_printf("%# +12  z-j12  o\n", 123);
	ft_printf("%*d\n", -5, 123);
	ft_printf("%.*d\n", -5, 123);
	ft_printf("%*.*d\n", -5, -10, 123);
	ft_printf("%*.*hhhhhhhhhhhllhlhlhlhd\n", -5, -10, 123l);
	ft_printf("%*.*hhhhhhhhhzzjjjlhlhlhd\n", -5, -10, 123l);

}