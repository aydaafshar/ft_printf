/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayda <ayda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:04:44 by ayda              #+#    #+#             */
/*   Updated: 2025/11/13 12:50:46 by ayda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n_len(long n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits = 1;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*fill_str(char *str, unsigned long n, int len)
{
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (str);
}

static char	*ft_itoa(int nb)
{
	long			n;
	unsigned long	unb;
	int				len;
	char			*str;

	n = (long)nb;
	len = ft_n_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		unb = (unsigned long)(-n);
		str[0] = '-';
	}
	else
		unb = (unsigned long)(n);
	str = fill_str(str, unb, len);
	return (str);
}

int	ft_prt_number(int n)
{
	char	*number;
	int		count;

	count = 0;
	if (n == -2147483648)
		return ((write(1, "-2147483648", 11)));
	number = ft_itoa(n);
	count += ft_putstr(number);
	free(number);
	return (count);
}
