#include "includes/ft_printf.h"

int null_string(t_fs *f_str)
{
        if (f_str->flags & MINUS)
        {
            if (f_str->is_precision)
                f_str->print_len += ft_printf("%-*.*s", f_str->width, f_str->precision, "(null)");
            else
                f_str->print_len += ft_printf("%-*s", f_str->width, "(null)");
        }
        else
        {
            if (f_str->is_precision)
            {
                if (f_str->flags & ZERO)
                    f_str->print_len += ft_printf("%0*.*s", f_str->width, f_str->precision, "(null)");
                else
                    f_str->print_len += ft_printf("%*.*s", f_str->width, f_str->precision, "(null)");
            }
            else
            {
                if (f_str->flags & ZERO)
                    f_str->print_len += ft_printf("%0*s", f_str->width, "(null)");
                else
                    f_str->print_len += ft_printf("%*s", f_str->width, "(null)");
            }
        }
        ++f_str->str;
        return (1);
}

void put_string(t_fs *f_str)
{
    const char *str;
    unsigned long long len;

    str = va_arg(f_str->argcs, const char *);
    if (str == 0 && null_string(f_str))
        return ;
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

void itoxa_wrapper(t_fs *f_str, unsigned long long address)
{
    int precision;
    int width;
    int is_precision;
    
    precision = f_str->precision;
    width = f_str->width;
    is_precision = f_str->is_precision;
    f_str->is_precision = 0;
    f_str->width = 0;
    f_str->precision = 0;
    itoxa(f_str, address);
    f_str->is_precision = is_precision;
    f_str->width = width;
    f_str->precision = precision;
}

void put_pointer_address(t_fs *f_str)
{
    unsigned long long address;
    void *void_argument;
    int len;
    int precision_temp;

    void_argument = va_arg(f_str->argcs, void *);
    address = (unsigned long long)void_argument;
    len = hexa_len(f_str, address);
    precision_temp = f_str->precision;
    if (!(f_str->flags & MINUS)/* && !(f_str->flags & ZERO)*/)
    {
        if (f_str->flags & ZERO)
        {
            if (!f_str->is_precision)
                f_str->precision = f_str->width - 2; 
            f_str->print_len += print_spaces(f_str->width - f_str->precision - 2);
        }
        else 
        {
            if (!(f_str->is_precision))
                precision_temp = len;
            f_str->print_len += print_spaces(f_str->width - precision_temp - 2);
        }
    }
    f_str->print_len += write(1, "0x", 2);
    if (f_str->is_precision || f_str->flags & ZERO)
        f_str->print_len += print_zeroes(f_str->precision - len);
    if (address == 0 && (!(f_str->is_precision) || f_str->precision > 0))
            f_str->print_len += write(1, "0", 1);
    if (address != 0)
        itoxa_wrapper(f_str, address);
    else
        ++(f_str->str);
    if (f_str->flags & MINUS)
        f_str->print_len += print_spaces(f_str->width - len - 2);
}