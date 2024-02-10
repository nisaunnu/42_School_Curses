#include <unistd.h>
#include <stdarg.h>

void ft_putstr(char *str, int *len)
{
	if(!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void ft_int(long long int nb, int *len, int base)
{
	if(nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if(nb >= base)
		ft_int((nb / base), base, len);
	*len += write(1, &"0123456789abcdef"[nb % base], 1);
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list arg;

	va_start(arg, format);
	while (*format)
	{
		if(*format == '%' && *(format + 1))
		{
			format++;
			if(*format == 's')
				ft_putstr(va_arg(arg, char *), &len);
			if(*format == 'd')
				ft_int((long long int)va_arg(arg, int), &len, 10);
			if(*format == 'x')
				ft_int((long long int)va_arg(arg, unsigned int), &len, 16);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return(len);
}
