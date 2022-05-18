/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_part_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jniemine <jniemine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:53:10 by jniemine          #+#    #+#             */
/*   Updated: 2022/05/18 12:11:37 by jniemine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	function_dispatcher(t_fs *f_str, char conversion)
{
	long double			ld;
	long long int		ll;
	unsigned long long	ull;

	if (conversion == 'u' || conversion == 'U'
		|| conversion == 'd' || conversion == 'i')
		integer(f_str);
	else if (conversion == 'o')
		octal(f_str);
	else if (conversion == 'X' || conversion == 'x')
		hexa(f_str, 0);
	else if (conversion == '%')
		put_percent(f_str);
	else if (conversion == 's')
		put_string(f_str);
	else if (conversion == 'c')
		put_character(f_str);
	else if (conversion == 'p')
		put_pointer_address(f_str);
	else
		float_to_ascii(f_str);
	format_fs(f_str);
}
