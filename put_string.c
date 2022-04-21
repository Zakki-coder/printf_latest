#include "ft_printf.h"

void put_string(t_fs *f_str)
{
    const char *str;
    unsigned long long len;

    str = va_arg(f_str->argcs, const char *);
    len = ft_strlen(str);
    if (f_str->precision < 0)
        f_str->precision = 0;
    if (f_str->is_precision && f_str->precision < len)
        len = f_str->precision;
    if (f_str->width > len && !(f_str->flags & MINUS))
       f_str->return_n += print_spaces(f_str->width - len);
    f_str->return_n += write(1, str, len);
    if (f_str->width > len && f_str->flags & MINUS)
        f_str->return_n += print_spaces(f_str->width - len);
    ++f_str->str;
    /* Precision tells the number of chars to be printed */
    /* Width is width */
    /* Minus flag is minus flag */
}