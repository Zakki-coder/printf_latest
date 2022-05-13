#include "ft_printf.h"

long double ten_raised_to_n(unsigned int n)
{
	long double res;

	res = 1;
	while (n > 0)
	{
		res *= 10;
		--n;
	}
	return (res);
}


int get_digit_before_decimal(long double f)
{
	unsigned long long nb;

	nb = f;
	if (nb > 10)
	{
		nb /= 10;
		nb *= 10;
		nb = (unsigned long long)f - nb;
		return((int)nb);
	}
	return ((int)f);
}



unsigned int whole_part_len(long double f)
{
   unsigned int res;

   res = 0;
   if (f < 1)
		return (1);
   while (f >= 1) 
   {
	   f /= 10;
	   ++res;
   }
   return (res);
}

void whole_part(t_fs *f_str, long double *f, char *nb, int *i)
{
	int				exp;
	unsigned int		first_digit;
	long double		 whole_part;

	exp = 0;
	whole_part = *f;
	while (whole_part >= 10)
	{
		whole_part /= 10;
		++exp;
	}
	while (exp >= 0)
	{
		first_digit = *f / ten_raised_to_n(exp);
		nb[(*i)++] = first_digit + '0';
		*f -= first_digit * ten_raised_to_n(exp);
		--exp;
	}
}

void fractional_part(t_fs *f_str, long double *f, char *nb, int *i)
{
	int precision;
	long long digit;
	long double flt;

	flt = *f;
	precision = f_str->precision;
	while (precision > 0)
	{
		digit = (long long)flt;
		nb[(*i)++] = digit + '0';
		flt -= digit;
		flt *= 10;
		--precision;
	}
}

void create_output(t_fs *f_str, char *nb, unsigned int nb_len)
{
	char			*out;

	out = ft_memalloc(sizeof(char) * f_str->width);
	if (out == NULL)
		exit(-1);
	ft_bzero(out, f_str->width);
	ft_memset(out, ' ', f_str->width);
	if (!(f_str->flags & MINUS))
	{
		if (f_str->flags & ZERO)
			ft_memset(out + has_prefix(f_str), '0', f_str->width);
		ft_memcpy(out + (f_str->width - nb_len) + has_prefix(f_str), nb, nb_len);
	}
	else
		ft_memcpy(out + has_prefix(f_str), nb, nb_len - has_prefix(f_str));
	if (!(f_str->flags & ZERO))
		set_prefix(f_str, out, nb_len - 1); 
	else
		set_prefix(f_str, out, f_str->width); 
	f_str->ret += write(1, out, f_str->width);
}

void print_float(t_fs *f_str, long double f)
{
	int i;
	char *nb;

	nb = ft_memalloc(whole_part_len(f) + f_str->precision + has_prefix(f_str) + 2); //Size of array is len of whole part and precision, +2 is for sign and dot
	if (nb == NULL)
		exit (-1);
	ft_bzero(nb, whole_part_len(f) + f_str->precision + has_prefix(f_str) + 2);
	f_str->nb_len = whole_part_len(f) + f_str->precision; //One for dot
	i = 0;
	whole_part(f_str, &f, nb, &i); //f should be the fractionw now
	if (f_str->precision != 0 || f_str->flags & HASH)
	{
		f_str->nb_len += 1;
		if (f >= 1)
			nb[i++] = (int)f + '0';
		nb[i++] = '.';
		f *= 10;
	}
	fractional_part(f_str, &f, nb, &i);
	if (has_prefix(f_str))
		f_str->nb_len += 1;
	if (f_str->width < f_str->nb_len)
		f_str->width = f_str->nb_len;
	create_output(f_str, nb, f_str->nb_len);
}

