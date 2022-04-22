#include "ft_printf.h"

void put_string(t_fs *f_str)
{
    const char *str;
    unsigned long long len;

    str = va_arg(f_str->argcs, const char *);
    if (str == 0)
    {
        f_str->return_n += write(1, "(null)", 6);
        ++f_str->str;
        return ;
    }
    len = ft_strlen(str);
    if (f_str->precision < 0)
        f_str->precision = 0;
    if (f_str->is_precision && f_str->precision < len)
        len = f_str->precision;
    if (f_str->width > len && !(f_str->flags & MINUS))
    {
        if (f_str->flags & ZERO)
            f_str->return_n += print_zeroes(f_str->width - len);
        else
           f_str->return_n += print_spaces(f_str->width - len);
    }
    f_str->return_n += write(1, str, len);
    if (f_str->width > len && f_str->flags & MINUS)
        f_str->return_n += print_spaces(f_str->width - len);
    ++f_str->str;
    /* TODO: with null or ?zero? print null symbol*/
    /* Precision tells the number of chars*/
    /* Width is width */
    /* Minus flag is minus flag */
    return ;
}

void put_character(t_fs *f_str)
{
    unsigned char ch;

    if (f_str->width >= 1)
        f_str->width -= 1;
    if (!(f_str->flags & MINUS))
        f_str->return_n += print_spaces(f_str->width);
    ch = (unsigned char)va_arg(f_str->argcs, int); 
    if (ch == 0)
        f_str->return_n += write(1, "\0", 1);
    else
        f_str->return_n += write(1, &ch, 1);
    if (f_str->flags & MINUS)
        f_str->return_n += print_spaces(f_str->width);
    ++f_str->str;
}

void put_pointer_address(t_fs *f_str)
{
    unsigned long long address;

    address = *(int *)va_arg(f_str->argcs, void *);
    f_str->flags = f_str->flags | HASH;
    if (address == 0)
    {
        f_str->nb_len += write(1, "0x0", 3);
        ++f_str->str;
    }
    else
        itoxa(f_str, address);
}