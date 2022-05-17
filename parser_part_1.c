/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_part_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakken <jakken@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:55:59 by jniemine          #+#    #+#             */
/*   Updated: 2022/05/16 20:04:53 by jakken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int not_atoi(const char **s)
{
	int n;

	n = 0;
	while (ft_isdigit(**s))
	{
		n *= 10;
		n += **s - '0';	
		++(*s);
	}
	--(*s);
	return(n);
}

static int no_conversion(t_fs *f_str)
{
	if (f_str->width >= 1)
		f_str->width -= 1;
	if (f_str->flags & ZERO)
		print_zeroes(f_str->width);
	else
		print_spaces(f_str->width);
	return (1);
}

const char *search_conversion(const char *fs)
{
	char *conversions = "diouUxXfcsp%";
	int i;
	int k;
	char *ret_conversion;

	i = 0;
	k = 0;
	if (!fs)
		return (NULL);
	while (fs[i] != '\0')
	{
		while (conversions[k] != '\0')
		{
			if (conversions[k] == fs[i])
				return (&fs[i]);
			++k;
		}
		k = 0;
		++i;
	}
	return (NULL);
}

static void get_format(t_fs *f_str, const char *conversion, const char *percent)
{
	char *format;

	f_str->ret += write(1, f_str->str, percent - f_str->str);
	format = (char *)ft_memalloc(sizeof(*format) * (conversion - percent) + 1);
	if (format == NULL) //FREE
		exit(-1);
	ft_memcpy(format, percent, conversion - percent);
	format[conversion - percent + 1] = '\0';
	get_flags(f_str, format);
	get_width(f_str, format);
	get_precision(f_str, format);
	get_modifiers(f_str, format);
	f_str->str = conversion;
	function_dispatcher(f_str, *conversion);
	free (format);
}

void parser(t_fs *f_str)
{
	const char **str;
	const char *conversion;
	const char *percent;

	conversion = NULL;
	while (*f_str->str != '\0')
	{
		if (conversion)
			f_str->str = conversion + 1;
		percent = ft_strchr(f_str->str, '%');
		if (percent)
			conversion = search_conversion(percent + 1);
		if (!percent)
		{
			f_str->ret += write(1, f_str->str, ft_strlen(f_str->str));
			return ;
		}
		else if (!conversion && no_conversion(f_str))
		{
			f_str->ret += write(1, percent + 1, ft_strlen(percent + 1));
			return ;
		}
		else
			get_format(f_str, conversion, percent);
	}
}