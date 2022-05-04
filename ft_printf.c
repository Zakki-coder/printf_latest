/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jniemine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:51:33 by jniemine          #+#    #+#             */
/*   Updated: 2022/04/07 17:10:10 by jniemine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int has_prefix(t_fs *f_str);

unsigned long long print_spaces(int len)
{
	unsigned long long ret;

	ret = 0;
	while (len > 0)
	{
		ft_putchar(' ');
		--len;
		++ret;
	}
	return (ret);
}

void putchar_and_count(char c, t_fs *f_str)
{
	f_str->return_n += write (1, &c, 1);
}

void putchar_n(char c, unsigned long long n, t_fs *f_str)
{
	int i;

	i = 0;
	while (i < n)
	{
		f_str->return_n += write(1, &c, 1);
		++i;
	}
}

void multi_percent_handler(const char **str, t_fs *f_str)
{
	int n;

	n = 0;
	while (**str == '%' && **str != '\0')
	{
		++(*str);
		++n;
	}
	putchar_n('%', n / 2, f_str);
	if (n % 2 != 0)
		--(*str);
}
		
/* Print util % is ecountered */
int print_chars(t_fs *f_str)
{
	const char **str;
	int n;

	n = f_str->return_n;
	str = &f_str->str;
	while(**str != '\0')
	{
		//Just make if for %% and call percent handler
		if (**str == '%' && *(*str + 1) == '%')
		{
			multi_percent_handler(str, f_str);
			continue ;
		}
		if (**str == '%' && *(*str + 1) != '%')
			return (1);
		putchar_and_count(**str, f_str);
		++(*str);
	}
	if (**str == '\0')
		return (-1);
	return (1);
}

void get_flags(t_fs *f_str)
{
	int *flags;
	const char **s;

	s = &f_str->str;
	flags = &f_str->flags;
	//Traverse in a loop until no flag is ecountered, return int where flag have been encoded as bits	
	while(**s == '#' || **s == '-' || **s == '0' || **s == '+' || **s == ' ')
	{
		if (**s == '#')	
			*flags |= HASH;
		if (**s == '-')
			*flags |= MINUS;
		if (**s == '0')
			*flags |= ZERO;
		if (**s == '+')
			*flags |= PLUS;
		if (**s == ' ')
			*flags |= SPACE;
		++(*s);
	}
}

int is_conversion(char c)
{
	return (c == 'f' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X');
}

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
	
void get_width(t_fs *f_str)
{
	int n;
	const char **s;
	
	s = &f_str->str;
	n = 0;
	if (ft_isdigit(**s))
	{
		n = not_atoi(s);
		if(n > f_str->width && n <= MAX_INT) //At least on linux this is the limit
			f_str->width = n;
	}
}

/* precision has been initialized to -1 and changes to at least to zero if . is found *precision */
void get_precision(t_fs *f_str)
{
	int n;
	const char **s;

	n = 0;
	s = &f_str->str;
	if(**s == '.')
	{
		f_str->is_precision = 1;
		while (**s == '.')
			++(*s);
		if(ft_isdigit(**s))
		{
			n = not_atoi(s);
			if(n > f_str->precision && n <= MAX_INT)
				f_str->precision = n;
		}
	}
}

/* ll or hh doesnt need to be checked because l and h will catch those */
int is_modifier(char c)
{
	return (c == 'L' || c == 'l' || c == 'h');
}

void get_modifiers(t_fs *f_str)
{
	const char **s;

	s = &f_str->str;
	//loop until largest modifier is found, or conversion char or null is found
	//No need to worry about over or underflow because str is limited with % and \0
	//What should happen in case like hhh?
	//h is more significant is my assumption. So if hhh then at least h.
	while (is_modifier(**s))
	{
		if (**s == 'L')
			f_str->modifier |= LDBL;
		if (**s == 'l' && *(*s + 1) == 'l')
			f_str->modifier |= LLONG;
		if (**s == 'l' && *(*s - 1) != 'l' && *(*s + 1) != 'l')
			f_str->modifier |= LONG;
		if (**s == 'h' && *(*s + 1) == 'h'
			&& *(*s - 1) != 'h' && *(*s + 2) != 'h' && (*s)++)
			f_str->modifier |= CHAR;
		else if(**s == 'h')
			f_str->modifier |= SHORT;
		++(*s);
	}
}

long long get_argument(t_fs *f_str)
{
	int m;
	long long arg;

	m = f_str->modifier;
	if (m & LLONG)
		arg = va_arg(f_str->argcs, long long);
	else if (m & LONG)
		arg = va_arg(f_str->argcs, long);
	else
		arg = va_arg(f_str->argcs, int);
	return (arg);
}
/* Handle width is used multiple places */

void handle_width(t_fs *f_str, int len)
{
	int f;
	char *ret;

	f = f_str->flags;
	if (len > f_str->width)
		f_str->width = len;
	if (f_str->precision > f_str->width)
		f_str->width = f_str->precision; //Behaves differently with float
	if (len == f_str->width && has_prefix(f_str))
		if ((*f_str->str == 'd' || *f_str->str == 'i')
		&& f_str->width < MAX_INT) //At least on linux this is the limit.
			++f_str->width;
	if ((!(f & MINUS)) && has_prefix(f_str) && f_str->precision == f_str->width)
		++f_str->width;
}
/* itodiutoa starts */
static int	nb_length(unsigned long long nb)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		++n;
		nb /= 10;
	}
	return (n);
}

int is_signed(char c)
{
	return (c == 'd' || c == 'i' || c == 'f');
}

int has_prefix(t_fs *f_str)
{
	int f;

	f = f_str->flags;
	if (is_signed(*f_str->str))
		return (f_str->neg || f & SPACE || f & PLUS);
	else
		return (0);
}

void set_prefix(t_fs *f_str, char *out, unsigned int nb_len)
{
	int f;
	char prefix;

	f = f_str->flags;
	if (f_str->neg)
		prefix = '-';
	else if (f & PLUS)
		prefix = '+';
	else if (f & SPACE)
		prefix = ' ';
	else
		return ;
	if ((f & MINUS) || (f & ZERO))
		*out = prefix;	
	else
		*(out + f_str->width - f_str->precision - 1/*nb_len - 1*/) = prefix; // nb_len - 1 changed to - precision
}

char *not_itoa(char *out, unsigned long long nb, int len, int diff)
{
	unsigned long long	ll;

	ll = 0;
	while (len > 0)
	{
		ll = nb - ((nb / 10) * 10);
		nb /= 10;
		*(out + diff + --len) = ll + '0';
	}	
	return (out);
}

unsigned long long convert_from_negativity(t_fs *f_str, long long ll)
{
	unsigned long long ull;

	ull = 0;
	if (*f_str->str != 'u' && ll < 0)
	{
		f_str->neg = 1;
		if (ll == -9223372036854775807 - 1)
			ull = (unsigned long long)9223372036854775807 + 1;
		else
			ull = ll * -1;
		return (ull);
	}
	ull = ll;
	return (ull);
}

/* Return 1 if the number is 0 and precision is 0 */
int zero_case(t_fs *f_str, unsigned long long ull)
{
	if (ull == 0 && f_str->is_precision && f_str->precision == 0)
	{
		f_str->return_n += print_spaces(f_str->width);	
		++f_str->str;
		return (1);
	}
	return (0);
}

//Precision guarantees the number of digits, so if there is precision and prefix, then +1 width
void itodiutoa(t_fs *f_str, long long ll)
{
	char	*out; //Remember to free
	int		len;
	int		diff;
	unsigned long long ull;
	/* Zero case hasnt been tested */	
	if (zero_case(f_str, ll))
		return ;
	ull = convert_from_negativity(f_str, ll);
	len = nb_length(ull);
	handle_width(f_str, len); //Remember to free
	if (f_str->precision < len)
		f_str->precision = len;
	diff = f_str->width - len;
	out = (char *)ft_memalloc(sizeof(*out) * f_str->width);
	if (out == NULL)
		exit (-1);
	ft_memset(out, ' ', f_str->width);
	if (f_str->flags & MINUS)
	{
		if  (ll < 0 || f_str->flags & PLUS || f_str->flags & SPACE)
			diff = 1;
		else
			diff = 0;
		if (f_str->precision - len > 0 && !(f_str->flags & MINUS))
		{
			ft_memset(out + diff, '0', f_str->precision - len);
			diff += f_str->precision - len;
		}
	}
	if (!(f_str->flags & MINUS) && f_str->is_precision) //ON linux we generate zeroes with formula precision - nb len, even if no zero flag. On mac not?
		ft_memset(out + (f_str->width - f_str->precision), '0', f_str->precision);
	else if (!(f_str->flags & MINUS) && f_str->flags & ZERO)
		ft_memset(out, '0', f_str->width);
	out = not_itoa(out, ull, len, diff); //Make a function to decide which type of number is parsed, d , o or x, malloc protection is in handle_width
	set_prefix(f_str, out, len);
	f_str->return_n += write(1, out, f_str->width);
	++f_str->str;
	free(out);
}
/* itodiutoa ends */

/* At the moment only used with octal */
unsigned long long  print_zeroes(int len)
{
	unsigned long long ret;

	ret = 0;
	while (len > 0)
	{
		ft_putnbr(0);
		--len;
		++ret;
	}
	return (ret);
}


/* Octa Starts */
/*Argument type is uint because that was the one which gave correct results on my linux*/
unsigned int octal_len(t_fs *f_str, unsigned long long ull)
{
	char s[100];
	int i;
	int add;

	add = 0;
	i = 0;
	ft_bzero(s, 100);
	if (ull == 0)
		return (1);
	while(ull > 0)
	{
		s[i] = (ull % 8) + '0';
		ull /= 8;
		++i;
	}
	if (f_str->flags & HASH)
		add = 1;
	return (ft_strlen(s) + add);
}

int str_reverse(char *s)
{
	int len;
	int i;
	char temp[100];

	bzero(temp, 100);
	len = ft_strlen(s) - 1;
	i = 0;
	while (len >= 0)
	{
		temp[i] = s[len];
		++i;
		--len;
	}
	ft_putstr(temp);
	return (ft_strlen(temp));
}

unsigned int octal_print(unsigned long long ull)
{
	char s[100];
	int i;

	if (ull == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	i = 0;
	ft_bzero(s, 100);
	while(ull > 0)
	{
		s[i] = (ull % 8) + '0';
		ull /= 8;
		++i;
	}
	return (str_reverse(s));
}

void right_adjusted_octal(t_fs *fs, unsigned long long ull, int len)
{
	if (fs->precision > 0)
	{
		fs->return_n += print_spaces(fs->width - fs->precision - len);
		if (ull == 0)
			fs->return_n += print_zeroes(fs->precision);
		else
			fs->return_n += print_zeroes(fs->precision - len);
	}
	else if (!fs->is_precision)
	{			
		if (!(fs->flags & ZERO))
			fs->return_n += print_spaces(fs->width - fs->precision - len);
		if (fs->flags & HASH)
			fs->return_n += print_zeroes(1);
		if (fs->flags & ZERO)
			fs->return_n += print_zeroes(fs->width - len);
	}
	else if (fs->is_precision)
	{		
		fs->return_n += print_spaces(fs->width - fs->precision - len);
		if (fs->flags & HASH && ++len)
			fs->return_n +=	print_zeroes(1);
	}
	if (ull > 0 || (ull == 0 && !fs->is_precision && !(fs->flags & HASH)))
		fs->return_n += octal_print(ull);
}
/* Number of zeroes = precision - number length. If number is nonzero.
 * If precision is not given and zero flag is on. Number of zeroes = width - number length
 */
void itootoa(t_fs *f_str, unsigned long long ull)
{
	int len;
	int width;
	int precision;

	if (zero_case(f_str, ull))
	{
		if (f_str->flags & HASH)
			f_str->return_n += print_zeroes(1);
		return ;
	}
	width = f_str->width;
	precision = f_str->precision;
	//Always print zero except when precision is 0 and there is no hash.
	/* Create number, calculate width > precision > number length, choose largest */
	len = octal_len(f_str, ull);
	handle_width(f_str, len);
	if (!(f_str->flags & MINUS))
		right_adjusted_octal(f_str, ull, len);
	else
	{
		/* With # prefix with zero, test with zero and 0 precision. */
		if (f_str->flags & HASH)
			f_str->return_n += print_zeroes(1);
		if (len > f_str->precision)
			f_str->precision = len;
		if (ull > 0)
			f_str->return_n += print_zeroes(f_str->precision - len);
		else if (ull == 0 && f_str->precision > 0)
			f_str->return_n += print_zeroes(f_str->precision - len);
		if (ull > 0)
			f_str->return_n += octal_print(ull);
		f_str->return_n += print_spaces(f_str->width - f_str->precision);
	}
	++f_str->str;
}
/* Octal ends here */
/* Every conversion has a width for the whole, length for just the digits and offset for where to print it the field */

/* itoxa starts */

unsigned int hexa_len(unsigned long long ull)
{
	char s[100];
	int i;

	i = 0;
	ft_bzero(s, 100);
	if (ull == 0)
		return (1);
	while(ull > 0)
	{
		if (ull % 16 > 9)
			s[i] = (ull % 16) - 9 + '@';
		else
			s[i] = ull % 16 + '0';
		ull /= 16;
		++i;
	}
	return (ft_strlen(s));
}

void put_hexa_prefix(t_fs *fs)
{
	char l_case;

	l_case = *fs->str;
//	if (l_case == 'X' || l_case == 'x')
//	{
		if (l_case == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
//		if (l_case == 'x')
//			ft_putstr("0x");
		fs->return_n += 2;
//	}
}

/* TODO: Check hexa and octa for overflow with huge width */
void hexa_print(t_fs *f_str, unsigned long long ull)
{
	char s[100];
	int i;
	int casing;

	i = 0;
	ft_bzero(s, 100);
	if (ull == 0)
	{
		putchar_and_count('0', f_str);
		return ;
	}
	if (*f_str->str == 'X')
		casing = '@';
	else
		casing = '`';
	while(ull > 0)
	{
		if (ull % 16 > 9)
			s[i] = (ull % 16) - 9 + casing;
		else
			s[i] = ull % 16 + '0';
		ull /= 16;
		++i;
	}
	f_str->return_n += str_reverse(s);
}
/* Dont print prefix if ull == 0 and precision is given*/
/* Prints too much spaces when hash is given 2 too much to be precise */
void right_adjusted_hexa(t_fs *fs, unsigned long long ull, int len)
{
	if (fs->is_precision && fs->precision > 0)
	{
		fs->return_n += print_spaces(fs->width - len);
		if (fs->flags & HASH && ull > 0)
		{
			put_hexa_prefix(fs);	
			len += 2;
		}
		fs->return_n += print_zeroes(fs->precision - len);
	}
	else if (!fs->is_precision)
	{			
		if (!(fs->flags & ZERO))
		{
			if (fs->flags & HASH)
				len += 2;
			fs->return_n += print_spaces(fs->width - len);
		}
		if (fs->flags & HASH && ull != 0)
		{
			len += 2;
			put_hexa_prefix(fs);
		}
		if (fs->flags & ZERO)
			fs->return_n += print_zeroes(fs->width - len);
	}
	else if (fs->is_precision)
	{		
		fs->return_n += print_spaces(fs->width - fs->precision - len);
		if (fs->flags & HASH && ull > 0)
			put_hexa_prefix(fs);
	}
	if (ull > 0 || ((ull == 0 && fs->precision > 0)))
		hexa_print(fs, ull);
}

void update_precision(t_fs *f_str, int len)
{
	int precision;

	precision = f_str->precision;
	/* Default precision to 1 */
	if (!f_str->is_precision)
		f_str->precision = 1;	
//	if (len > precision && !(f_str->is_precision && precision == 0))
//		f_str->precision = len;
}

void itoxa(t_fs *f_str, unsigned long long ull)
{
	/* For x produce output with lowercase, for X with UPPERCASE */
	/* precision is the minimum numbers of digits to appear, test with zero padd */
	/* # flag prefixes with 0x or 0X, for NONZERO!!!! */
	/* 0 flag padds with zeroes on the left */
	/* - flag left adjustes and overrides 0 flag */
	/* NO SPACE OR + FLAG */
	int len;
	int width;
	int precision;

	if (zero_case(f_str, ull))
		return ;
	width = f_str->width;
	//When precision is explicitly zero, this doesnt work FIX IT
	//Always print zero except when precision is 0 and there is no hash.
	/* Create number, calculate width > precision > number length, choose largest */
	len = hexa_len(ull);
	update_precision(f_str, len);
	precision = f_str->precision;
	handle_width(f_str, len);
	if (!(f_str->flags & MINUS))
		right_adjusted_hexa(f_str, ull, len);
	else
	{
		/* With # prefix with zero, test with zero and 0 precision. */
		/* If precision is larger than len, then add zeroes to front, test all functions */
		if (f_str->flags & HASH && ull != 0)
		{
			put_hexa_prefix(f_str);
			len += 2;
		}
		hexa_print(f_str, ull);
		f_str->return_n += print_spaces(f_str->width - len);
	}
	++f_str->str;
}

void function_dispatcher(t_fs *f_str, long long ll)
{
			//call either absolute_itoa, otoa, or xtoa, or the unsigned one
	if(*f_str->str == 'd' || *f_str->str == 'i' || *f_str->str == 'u')	
		itodiutoa(f_str, ll);
	if (*f_str->str == 'o')
		itootoa(f_str, ll);
	if (*f_str->str == 'x' || *f_str->str == 'X')
		itoxa(f_str, ll);
}

unsigned long long cast_to_modifier_u(t_fs *f_str, unsigned long long ll)
{
	int m;

	m = f_str->modifier;
	if (m & LLONG)
		return((unsigned long long)ll);//print_di(f_str, (long long)ll);
	else if (m & LONG)
		return((unsigned long)ll);//print_di(f_str, (long)ll);
	else if (m & SHORT)
		return((unsigned short)ll);//print_di(f_str, (short)ll);
	else if (m & CHAR)
		return((unsigned char)ll);//print_di(f_str, (char)ll);
	return((unsigned int)ll);//print_di(f_str, (int)ll);
}

long long cast_to_modifier(t_fs *f_str, long long ll)
{
	int m;

	m = f_str->modifier;
	//Add calls for the rest of diouxX, modify print_di to take care of things
	//Modifier decides casting, diouxX is just the format
	if (m & LLONG)
		return((long long)ll);//print_di(f_str, (long long)ll);
	else if (m & LONG)
		return((long)ll);//print_di(f_str, (long)ll);
	else if (m & SHORT)
		return((short)ll);//print_di(f_str, (short)ll);
	else if (m & CHAR)
		return((char)ll);//print_di(f_str, (char)ll);
	return((int)ll);//print_di(f_str, (int)ll);
}
	
/* Never format string or argcs or return_n */
void format_fs(t_fs *f_str)
{
	f_str->flags = 0;
	f_str->width = 0;
	f_str->precision = 0;
	f_str->is_precision = 0;
	f_str->modifier = 0;
	f_str->conversion = 0;
	f_str->neg = 0;
	f_str->percent_flag = 0;
	f_str->nb_len = 0;
}

unsigned long long get_argument_u(t_fs *f_str)
{
	int m;
	unsigned long long arg;

	m = f_str->modifier;
	if (m & LDBL)
		arg = va_arg(f_str->argcs, long double);//call get_ldbl, which gets the value How the original does it, is there SEGFAULT here?
	else if (m & LLONG)
		arg = va_arg(f_str->argcs, long long);
	else if (m & LONG)
		arg = va_arg(f_str->argcs, long);
	else
		arg = va_arg(f_str->argcs, int);
	return (arg);
}

void left_adjusted_percent(t_fs *f_str)
{
	putchar_and_count('%', f_str);	
	f_str->return_n += print_spaces(f_str->width - 1);
}
	
void right_adjusted_percent(t_fs *f_str)
{
	if (f_str->flags & ZERO)
		f_str->return_n += print_zeroes(f_str->width - 1);
	else
		f_str->return_n += print_spaces(f_str->width - 1);
	putchar_and_count('%', f_str);	
}

void put_percent(t_fs *f_str)
{
	if (f_str->flags & MINUS)
		left_adjusted_percent(f_str);
	else
		right_adjusted_percent(f_str);
	++f_str->str;
}

void parse_conversion(t_fs *f_str)
{
	long double			ld;
	long long int		ll;
	unsigned long long	ull;
	//str should be pointing to conversion
	//make a function which gets the argument from stack
	//Conver the value to octal-, hexa-, integer- or float string
	//One function to return long long and one to return long double
	/* TODO get rid of get_argument and function dispatcher 
		You can still use cast_to_modifier */
	if (*f_str->str != 'f' && *f_str->str != '%' && *f_str->str != 's' && *f_str->str != 'c' && *f_str->str != 'p')
	{
		if (*f_str->str != 'd' && *f_str->str != 'i')
		{
			ull = get_argument_u(f_str);
			ull = cast_to_modifier_u(f_str, ull);
			function_dispatcher(f_str, ull);
		}
		else
		{
			ll = get_argument(f_str);
			ll = cast_to_modifier(f_str, ll);
			function_dispatcher(f_str, ll);
		}

	}
	else if (*f_str->str == '%')
		put_percent(f_str);
	else if (*f_str->str == 's')
		put_string(f_str);
	else if (*f_str->str == 'c')
		put_character(f_str);
	else if (*f_str->str == 'p')
		put_pointer_address(f_str);
	else
		float_to_ascii(f_str);
	format_fs(f_str);
}

int is_flag(char c)
{
	return (c == '#' || c == '-' || c == '0' || c == '+' || c == ' ');
}

int is_correct_format_str(char c)
{
	return (ft_isdigit(c) /*|| is_conversion(c)*/ || is_modifier(c) || is_flag(c)
			|| c == '%');
}

void no_conversion(t_fs *f_str)
{
	if (f_str->width >= 1)
		f_str->width -= 1;
	if (f_str->flags & ZERO)
		print_zeroes(f_str->width);
	else
		print_spaces(f_str->width);
}

int search_conversion(t_fs *f_str)
{
	char *conversions = "diouxXfcsp";
	int i;

	i = 0;
	while (conversions[i] != '\0')
	{
		if (ft_strchr(f_str->str, conversions[i]))
			return (1);
		++i;
	}
	return (0);
}

void parser(t_fs *f_str)
{
	const char **str;

	str = &f_str->str;
	while (**str != '\0')
	{
	//Traverse and print fs until %, with print_chars then send to get_flags
	if(print_chars(f_str) == -1)
		return ;
	if (search_conversion(f_str))
		while((!is_conversion(**str) || **str == '%') && **str != '\0')
		{
			++(*str);
			get_flags(f_str);
	//Loop for width(number), precision(.number), length mod(letter) until conversion or \0 is encountered
			get_width(f_str);
			get_precision(f_str);
			get_modifiers(f_str);
			if (**str == '%')
				break;
		}
		//Print the first conversion out and reset struct
		if (is_conversion(**str) || **str == '%')
			parse_conversion(f_str);
		else
			no_conversion(f_str);
	}
	//If we find \0 before conversion, nothing gets printed int the '%'-'\0' range, is it correcto?
}

int	ft_printf(const char *str, ...)
{
	//TEST that implicit formatting works
	t_fs	f_str;

	format_fs(&f_str);
	f_str.return_n = 0;
	f_str.str = str;
	va_start(f_str.argcs, str);
	parser(&f_str);
	va_end(f_str.argcs);
	return(f_str.return_n);
}
