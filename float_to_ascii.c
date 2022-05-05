#include "includes/ft_printf.h"

/* TODO: What should I do when LDBL is not enough? */
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

unsigned int len_to_first_digit(long double f)
{
    unsigned int len;

    len = 0;
    while (f >= 10)
    {
        f/= 10;
        ++len;
    }
    return (len);
}

void normalizer(int *precision, long double *f)
{
    unsigned int decimal_place;

    decimal_place = len_to_first_digit(*f);
    *f /= ten_raised_to_n(decimal_place);
    *precision += decimal_place;
}

void set_precision_for_rounding_dir(t_fs *f_str, int *precision)
{
    if (f_str->is_precision)
        *precision = f_str->precision;
    else
    {
        f_str->is_precision = 1;
        f_str->precision = 6;
        *precision += f_str->precision;
    }
}

int rounding_direction(t_fs *f_str, long double f, int *for_bankers)
{
    int precision;
    long double exp;
    
    set_precision_for_rounding_dir(f_str, &precision);
    normalizer(&precision, &f);
    exp = ten_raised_to_n(f_str->precision); 
    while (precision) 
    {
        f -= (int)f;
        f *= 10;
        if (precision == 1)
            *for_bankers = (int)f;
        --precision;
    }
    f -= (int)f;
    if (f < 0.5)
        return (-1);
    else if (f == 0.5)
        return (0);
    return (1);
}

long double divide_one_with_ten_n(int precision)
{
    long double ret;

    ret = 1;
    while (precision)
    {
        ret /= 10;
        --precision;
    }
    return (ret);
}

long double round_up_float(int precision, long double f)
{
    long double add;

    add = divide_one_with_ten_n(precision); //Was originally precision + 1
    f += add;
    f -= add / 10;
    return (f);
}

/* Could i just use divide_one_with_ten_n and multiply with 5?? Would the result differ? */
/* Maybe do divide any number with ten function? */
long double divide_five_with_ten_n(int precision)
{
    long double ret;

    ret = 5 / ten_raised_to_n(precision);
    return (ret);
}

long double round_bankers(int precision, long double f, int next_to_last)
{
    if (next_to_last % 2 == 0)
        ;/* Just cut after precision when even? */
    else
        f += divide_one_with_ten_n(precision);
    return(f);
}

/* Just cut after precision when rounding down :D */
long double round_down_float(int precision, long double f)
{
    return (f);
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
    int                 exp;
    unsigned int        first_digit;
    long double         whole_part;

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
    unsigned long long digit;

    precision = f_str->precision;
    while (precision > 0)
    {
        digit = *f;
        nb[(*i)++] = digit + '0';
        *f -= digit;
        *f *= 10;
        --precision;
    }
}
/* With # flag, should contain decimal point, even if no fraction
 * With 0 flag, pad on the left with zeroes
 * With - flag, adjust on the left, override 0
 * With ' ' Empty space before conversion
 * With + place a sign before number, override ' '
 */
//Caller needs to take care that width is at least nb_len
void create_output(t_fs *f_str, char *nb, unsigned int nb_len)
{
    char            *out;
    unsigned int    starts_with_zero;

    starts_with_zero = 0;
    if (*nb == '0')
        starts_with_zero = 1;
    out = ft_memalloc(sizeof(char) * f_str->width);
    if (out == NULL)
        exit(-1);
    ft_bzero(out, f_str->width);
    ft_memset(out, ' ', f_str->width);
    if (!(f_str->flags & MINUS))
    {
        if (f_str->flags & ZERO)
            ft_memset(out + has_prefix(f_str), '0', f_str->width + has_prefix(f_str));
        ft_memcpy(out + (f_str->width - nb_len + has_prefix(f_str)), nb, nb_len);
    }
    else
        ft_memcpy(out, nb, nb_len);
    set_prefix(f_str, out, nb_len); 
    write(1, out, f_str->width);
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
/*    else if (f == 0 && f_str->flags & HASH)
    {
        f_str->nb_len += 1;
        nb[i++] = '.';
    }
*/
    fractional_part(f_str, &f, nb, &i);
    if (has_prefix(f_str))
        f_str->nb_len += 1;
    if (f_str->width < f_str->nb_len)
        f_str->width = f_str->nb_len;
    create_output(f_str, nb, f_str->nb_len);
}

long double rounder(t_fs *f_str, long double f)
{
    int direction;
    int for_bankers;

    direction = rounding_direction(f_str, f, &for_bankers);
    if (direction == 1)
        return(round_up_float(f_str->precision, f));
    else if (direction == 0)
        return(round_bankers(f_str->precision, f, for_bankers));
    return(round_down_float(f_str->precision, f)); //At this moment does nothing because no need?
}

void float_to_ascii(t_fs *f_str)
{
    long double f;

    if (f_str->modifier & LDBL)
        f = (long double)va_arg(f_str->argcs, long double);
    else 
        f = va_arg(f_str->argcs, double);
    /*Check negativity */
    if (1 / f < 0)
    {
        f *= -1;
        f_str->neg = 1;
    }
    /*check for precision */
    print_float(f_str, rounder(f_str, f));
    ++f_str->str;
}