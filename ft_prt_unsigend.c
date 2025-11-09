/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_unsigend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayda <ayda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:39:19 by ayda              #+#    #+#             */
/*   Updated: 2025/11/09 22:24:18 by ayda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_number(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits = 1;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*ft_itoa_uns(unsigned int n)
{
	int		len;
	char	*str;

	len = len_number(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

int	t_prt_unsigend(unsigned int number)
{
	int		count;
	char	*num;

	count = 0;
	num = ft_itoa_uns(number);
	count += ft_putstr(num);
	free(num);
	return (num);
}
