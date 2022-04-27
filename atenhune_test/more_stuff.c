/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:29:44 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:55:57 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%ld\n", LONG_MAX);
	printf("%ld\n", LONG_MIN);
	printf("%ld\n", 0);
	printf("%lld\n", LLONG_MAX);
	printf("%lld\n", LLONG_MIN);
	printf("%lld\n", 0);
	printf("%hd\n", 0);
	printf("%hd\n", 123);
	printf("%hhd\n", 0);
	printf("%hhd\n", 123);
	printf("%li\n", LONG_MAX);
	printf("%li\n", LONG_MIN);
	printf("%li\n", 0);
	printf("%lli\n", LLONG_MAX);
	printf("%lli\n", LLONG_MIN);
	printf("%lli\n", 0);
	printf("%hi\n", 0);
	printf("%hi\n", 123);
	printf("%hhi\n", 0);
	printf("%hhi\n", 123);
	printf("%lu\n", 0);
	printf("%lu\n", ULONG_MAX);
	printf("%lu\n", 123);
	printf("%lu\n", -1);
	printf("%llu\n", 0);
	printf("%llu\n", ULLONG_MAX);
	printf("%llu\n", 123);
	printf("%llu\n", -2);
	printf("%hu\n", 0);
	printf("%hu\n", 12);
	printf("%hu\n", 123);
	printf("%hhu\n", 0);
	printf("%hhu\n", 12);
	printf("%hhu\n", 123);
	printf("%lx\n", 0);
	printf("%lx\n", ULONG_MAX);
	printf("%lx\n", 123);
	printf("%lx\n", -1);
	printf("%llx\n", 0);
	printf("%llx\n", ULLONG_MAX);
	printf("%llx\n", 123);
	printf("%llx\n", -2);
	printf("%hx\n", 0);
	printf("%hx\n", 12);
	printf("%hx\n", 123);
	printf("%hhx\n", 0);
	printf("%hhx\n", 12);
	printf("%hhx\n", 123);
	printf("%lX\n", 0);
	printf("%lX\n", ULONG_MAX);
	printf("%lX\n", 123);
	printf("%lX\n", -1);
	printf("%llX\n", 0);
	printf("%llX\n", ULLONG_MAX);
	printf("%llX\n", 123);
	printf("%llX\n", -2);
	printf("%hX\n", 0);
	printf("%hX\n", 12);
	printf("%hX\n", 123);
	printf("%hhX\n", 0);
	printf("%hhX\n", 12);
	printf("%hhX\n", 123);
	printf("%lo\n", 0);
	printf("%lo\n", ULONG_MAX);
	printf("%lo\n", 123);
	printf("%lo\n", -1);
	printf("%llo\n", 0);
	printf("%llo\n", ULLONG_MAX);
	printf("%llo\n", 123);
	printf("%llo\n", -2);
	printf("%ho\n", 0);
	printf("%ho\n", 12);
	printf("%ho\n", 123);
	printf("%hho\n", 0);
	printf("%hho\n", 12);
	printf("%hho\n", 123);

	



}