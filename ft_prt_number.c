/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayda <ayda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:04:44 by ayda              #+#    #+#             */
/*   Updated: 2025/11/09 21:38:02 by ayda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n_len(int n)
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

static char	*fill_str(char *str, unsigned int n, int len)
{
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (str);
}

static char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	len = ft_n_len(n);
	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '\0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str = fill_str(str, n, len);
	return (str);
}

int	ft_prt_number(int n)
{
	char	*number;
	int		count;

	number = ft_itoa(n);
	count = ft_putstr(number);
	free(number);
	return (count);
}
