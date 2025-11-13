/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayda <ayda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:21:46 by ayda              #+#    #+#             */
/*   Updated: 2025/11/13 14:45:12 by ayda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	unsigned char	p;

	p = (unsigned char)c;
	write(1, &p, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	do_convesrion(va_list *bag, const char format)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(*bag, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*bag, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_prt_number(va_arg(*bag, int)));
	else if (format == 'u')
		return (ft_prt_unsigend(va_arg(*bag, unsigned int)));
	else if (format == 'p')
		return (ft_prt_pointer(va_arg(*bag, void *)));
	else if (format == 'x' || format == 'X')
		return (ft_prt_hex(va_arg(*bag, unsigned int), format));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	bag;

	i = 0;
	count = 0;
	va_start(bag, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				count += do_convesrion(&bag, format[i + 1]);
				i++;
			}
			else
				break ;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(bag);
	return (count);
}

// int	main(void)
// {
// 	int		i;
// 	int		c;
// 	char	ch;
// 	char	*p;
// 	char	*str;

// 	i = 1;
// 	c = 'a';
// 	ch = 'd';
// 	p = &ch;
// 	str = "ayda";
// 	ft_printf("p :%p\n", p);
// 	ft_printf("d : %d\n", i);
// 	ft_printf("c: %c\n", c);
// 	ft_printf("s: %s\n", str);
// 	return (0);
// }
