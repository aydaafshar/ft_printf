/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayda <ayda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:59:40 by ayda              #+#    #+#             */
/*   Updated: 2025/11/12 11:53:19 by ayda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_hx(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static void	ft_prt_hex_put(unsigned int n, const char format)
{
	const char	*digits;

	if (format == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	if (n >= 16)
		ft_prt_hex_put(n / 16, format);
	write(1, &digits[n % 16], 1);
}

int	ft_prt_hex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	ft_prt_hex_put(n, format);
	return (ft_len_hx(n));
}
