/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:01:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 14:13:47 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%llllllllld\n", LLONG_MAX);
	printf("%llllllllld\n", 0ll);
	printf("%llllllhhhhllld\n", 0ll);
	printf("%++++++00000llllllllld\n", 0ll);
	printf("%++++++00000llllllllld\n", 0ll);
	printf("%++++++00000llllllllld\n", 0ll);
	printf("%++++++00000llllllllld\n", 0ll);
	printf("%++++++00000llllllllld\n", 0ll);
	printf("%++++++00000llllllllld\n", 123);
	printf("%++++++#+ 00000lllllllllu\n", 123u);
	printf("%++++++#+ 00000lllllllll\n", 123u);
	printf("%0-12s\n", "MORO");
	printf("%0#-12s\n", "MORO");
	printf("%0-12s\n", NULL);
	printf("%0-12\n", "moi");
	printf("%0-12\n", "moi");
	printf("%0-12%\n", "moi");
	printf("%%%\n", "moi");
	printf("%# +u\n", 123);
	printf("%# +x\n", 123);
	printf("%# +X\n", 123);
	printf("%# +    u\n", 123);
	printf("%# +    o\n", 123);
	printf("%# +  z  o\n", 123);
	printf("%# +  z  x\n", 123);
	printf("%# +  z  X\n", 123);
	printf("%# +  zj  o\n", 123);
	printf("%# +12  z-j12  o\n", 123);
	printf("%*d\n", -5, 123);
	printf("%.*d\n", -5, 123);
	printf("%*.*d\n", -5, -10, 123);
	printf("%*.*hhhhhhhhhhhllhlhlhlhd\n", -5, -10, 123l);
	printf("%*.*hhhhhhhhhzzjjjlhlhlhd\n", -5, -10, 123l);

}