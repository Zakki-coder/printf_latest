#include "includes/ft_printf.h"

void put_string(t_fs *f_str)
{
    const char *str;
    unsigned long long len;

    str = va_arg(f_str->argcs, const char *);
    if (str == 0)
    {
        f_str->print_len += write(1, "(null)", 6);
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
            f_str->print_len += print_zeroes(f_str->width - len);
        else
           f_str->print_len += print_spaces(f_str->width - len);
    }
    f_str->print_len += write(1, str, len);
    if (f_str->width > len && f_str->flags & MINUS)
        f_str->print_len += print_spaces(f_str->width - len);
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
    {
        if (f_str->flags & ZERO)
            f_str->print_len += print_zeroes(f_str->width);
        else
            f_str->print_len += print_spaces(f_str->width);
    }
    ch = (unsigned char)va_arg(f_str->argcs, int); 
    if (ch == 0)
        f_str->print_len += write(1, "\0", 1);
    else
        f_str->print_len += write(1, &ch, 1);
    if (f_str->flags & MINUS)
        f_str->print_len += print_spaces(f_str->width);
    ++f_str->str;
}

void put_pointer_address(t_fs *f_str)
{
    unsigned long long address;
    void *void_argument;
    int len;

    void_argument = va_arg(f_str->argcs, void *);
    address = (unsigned long long)void_argument;
    len = hexa_len(f_str, address);
    if (address == 0)
        len = 0;
    f_str->print_len += print_spaces(f_str->width - len - 2);
    f_str->print_len += write(1, "0x", 2);
    if (f_str->is_precision)
        f_str->print_len += print_zeroes(f_str->precision - len);
    if (address == 0)
    {
        ++(f_str->str);
        return ;
    }
    f_str->is_precision = 0;
    f_str->width = 0;
    f_str->precision = 0;
    itoxa(f_str, address);
}