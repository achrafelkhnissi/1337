#include <unistd.h>
#include <stdarg.h>

void    ft_putchar(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

void    ft_putstr(char *str, int *count)
{
    if (!str)
        ft_putstr("(null)", count);
    else
        while(*str)
           ft_putchar(*(str++), count);
}

void    ft_putnbr(int n, int *count)
{
    unsigned int    num;

    num = n;
    if (n < 0)
    {
       num = -n;
       ft_putchar('-', count);
    }
    if (num < 10)
       ft_putchar(num + '0', count);
    else
    {
       ft_putnbr(num / 10, count);
       ft_putnbr(num % 10, count);
    }
}

void    ft_puthex(unsigned int n, const char* base, int *count)
{
    if (n < 16)
       ft_putchar(base[n % 16], count);
    else
    {
       ft_puthex(n / 16, base, count);
       ft_puthex(n % 16, base, count);
    }
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(args, char *), &count);
            else if (*format == 'd')
                ft_putnbr(va_arg(args, int), &count);
            else if (*format == 'x')
                ft_puthex(va_arg(args, int), "0123456789abcdef", &count);
        }
        else
            ft_putchar(*format, &count);
        format++;
    }
    va_end(args);
    return (count);
}
