# include <string.h>
# include <stdio.h>
//# include <stdlib.h>
# include <unistd.h>
//# include <stddef.h>
# include <stdarg.h>



int	ft_putchar_pf(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	{
		while (*format)
		{
			if(*format == '%' && *(format + 1) == 'c')
			{
				char	c;
				c = va_arg(args, int);
				ft_putchar_pf(c);
				i++;
				format++;
			}
			else
			{
				ft_putchar_pf(*format);
				i++;
			}
		format++;
		}	
    }
	va_end(args);
	return (i);
}
int	main()
{
	int	i;

	i = 0;
	char c = 'A';
 	i = printf("Le caractère est : %c\n", c);
   	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le caractère est : %c\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	return (0);
}
	