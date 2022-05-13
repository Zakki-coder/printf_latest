/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jniemine <jniemine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:15:00 by jniemine          #+#    #+#             */
/*   Updated: 2022/05/13 17:11:15 by jniemine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h" //REmove filepath
# include <stdarg.h>
# include "unistd.h"
# include <stdlib.h>

#include <stdio.h> //DELT

# define HASH	256
# define MINUS	64
# define ZERO	16
# define PLUS	4	
# define SPACE	1
# define LDBL	512
# define LLONG 	128
# define LONG	32
# define SHORT	8
# define CHAR	2	
# define MAX_INT 2147483647

typedef struct s_format_string
{
	const char	*str;
	va_list		argcs;
	unsigned long long ret;
	unsigned int		nb_len;
	int			flags;
	int			width;
	int			precision;
	int			is_precision;
	int			modifier;
	int			conversion;
	int			neg;
	int			percent_flag;
}				t_fs;

void print_float(t_fs *f_str, long double f);
int get_digit_before_decimal(long double f);

int is_flag(char c);
void put_character(t_fs *f_str);
void itoxa(t_fs *f_str, long long nb);
void put_pointer_address(t_fs *f_str);
unsigned long long print_spaces(int len);
unsigned long long  print_zeroes(int len);
void put_string(t_fs *f_str);
void float_to_ascii(t_fs *f_str);
int has_prefix(t_fs *f_str);
void set_prefix(t_fs *f_str, char *out, unsigned int nb_len);
unsigned long long cast_to_modifier_u(t_fs *f_str, unsigned long long ll);
long double divide_one_with_ten_n(int precision); //DEBUGGIN
void	print_octal(t_fs *f_str, unsigned long long ull);
unsigned int hexa_len(t_fs *f_str, unsigned long long ull); //FOR DEBUG
void	abs_putnbr(unsigned long long n);		//FOR DEBUG
unsigned long long	convert_to_octal(unsigned long long ull); //FOR DEBUG
char	*absolute_itoa(long long ll, int *n); //FOR DEBUG
void	get_modifiers(t_fs *f_str, const char *fs);	//FOR DEBUG
void	get_precision(t_fs *f_str, const char *fs); //FOR DEBUG
void	get_width(t_fs *f_str, const char *fs);	//FOR DEBUG
void	get_flags(t_fs *f_str, char *fs);
const char	*search_conversion(const char *fs);
int		is_conversion(char c);	//FOR DEBUG
int		ft_printf(const char *str, ...);

#endif
