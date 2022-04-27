/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:29:44 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:55:19 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("%ld\n", LONG_MAX);
	ft_printf("%ld\n", LONG_MIN);
	ft_printf("%ld\n", 0);
	ft_printf("%lld\n", LLONG_MAX);
	ft_printf("%lld\n", LLONG_MIN);
	ft_printf("%lld\n", 0);
	ft_printf("%hd\n", 0);
	ft_printf("%hd\n", 123);
	ft_printf("%hhd\n", 0);
	ft_printf("%hhd\n", 123);

	ft_printf("%li\n", LONG_MAX);
	ft_printf("%li\n", LONG_MIN);
	ft_printf("%li\n", 0);
	ft_printf("%lli\n", LLONG_MAX);
	ft_printf("%lli\n", LLONG_MIN);
	ft_printf("%lli\n", 0);
	ft_printf("%hi\n", 0);
	ft_printf("%hi\n", 123);
	ft_printf("%hhi\n", 0);
	ft_printf("%hhi\n", 123);

	ft_printf("%lu\n", 0);
	ft_printf("%lu\n", ULONG_MAX);
	ft_printf("%lu\n", 123);
	ft_printf("%lu\n", -1);
	ft_printf("%llu\n", 0);
	ft_printf("%llu\n", ULLONG_MAX);
	ft_printf("%llu\n", 123);
	ft_printf("%llu\n", -2);
	ft_printf("%hu\n", 0);
	ft_printf("%hu\n", 12);
	ft_printf("%hu\n", 123);
	ft_printf("%hhu\n", 0);
	ft_printf("%hhu\n", 12);
	ft_printf("%hhu\n", 123);

	ft_printf("%lx\n", 0);
	ft_printf("%lx\n", ULONG_MAX);
	ft_printf("%lx\n", 123);
	ft_printf("%lx\n", -1);
	ft_printf("%llx\n", 0);
	ft_printf("%llx\n", ULLONG_MAX);
	ft_printf("%llx\n", 123);
	ft_printf("%llx\n", -2);
	ft_printf("%hx\n", 0);
	ft_printf("%hx\n", 12);
	ft_printf("%hx\n", 123);
	ft_printf("%hhx\n", 0);
	ft_printf("%hhx\n", 12);
	ft_printf("%hhx\n", 123);

	ft_printf("%lX\n", 0);
	ft_printf("%lX\n", ULONG_MAX);
	ft_printf("%lX\n", 123);
	ft_printf("%lX\n", -1);
	ft_printf("%llX\n", 0);
	ft_printf("%llX\n", ULLONG_MAX);
	ft_printf("%llX\n", 123);
	ft_printf("%llX\n", -2);
	ft_printf("%hX\n", 0);
	ft_printf("%hX\n", 12);
	ft_printf("%hX\n", 123);
	ft_printf("%hhX\n", 0);
	ft_printf("%hhX\n", 12);
	ft_printf("%hhX\n", 123);

	ft_printf("%lo\n", 0);
	ft_printf("%lo\n", ULONG_MAX);
	ft_printf("%lo\n", 123);
	ft_printf("%lo\n", -1);
	ft_printf("%llo\n", 0);
	ft_printf("%llo\n", ULLONG_MAX);
	ft_printf("%llo\n", 123);
	ft_printf("%llo\n", -2);
	ft_printf("%ho\n", 0);
	ft_printf("%ho\n", 12);
	ft_printf("%ho\n", 123);
	ft_printf("%hho\n", 0);
	ft_printf("%hho\n", 12);
	ft_printf("%hho\n", 123);

}