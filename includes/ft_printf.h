/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jniemine <jniemine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:15:00 by jniemine          #+#    #+#             */
/*   Updated: 2022/05/18 11:57:29 by jniemine         ###   ########.fr       */
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

void format_fs(t_fs *f_str);
void put_percent(t_fs *f_str);
unsigned long long cast_to_modifier_u(t_fs *f_str, unsigned long long ll);
long long cast_to_modifier(t_fs *f_str, long long ll);
int is_signed(char c);
void integer(t_fs *f_str);
unsigned int octal_print(unsigned long long ull);
void right_adjusted_octal(t_fs *fs, unsigned long long ull, int len);
unsigned long long get_argument_u(t_fs *f_str);
long long get_argument(t_fs *f_str);
void octal(t_fs *f_str);
void hexa_print(t_fs *f_str, unsigned long long ull);
void right_adjusted_hexa(t_fs *fs, unsigned long long ull, int len);
void put_hexa_prefix(t_fs *fs);
void handle_width(t_fs *f_str, int len);
int str_reverse(char *s);
int zero_case(t_fs *f_str, unsigned long long ull);
unsigned long long convert_from_negativity(t_fs *f_str, long long ll);
void get_itoxa_argument(t_fs *f_str);
void right_adjusted_hexa(t_fs *fs, unsigned long long ull, int len);
int not_atoi(const char **s);
void print_float(t_fs *f_str, long double f);
int get_digit_before_decimal(long double f);
long double ten_raised_to_n(unsigned int n);
void parser(t_fs *f_str);
void get_flags(t_fs *f_str, char *fs);
void get_width(t_fs *f_str, const char *format);
void get_precision(t_fs *f_str, const char *format);
void get_precision(t_fs *f_str, const char *format);
void function_dispatcher(t_fs *f_str, char conversion);
void put_character(t_fs *f_str);
void hexa(t_fs *f_str, long long nb);
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
