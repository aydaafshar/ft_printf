/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayda <ayda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:42:54 by ayda              #+#    #+#             */
/*   Updated: 2025/11/12 12:00:06 by ayda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_ptr(uintptr_t ptr)
{
	int	digits;

	if (ptr == 0)
		return (1);
	digits = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		digits++;
	}
	return (digits);
}

static void	ft_prt_ptr(uintptr_t ptr)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (ptr >= 16)
		ft_prt_ptr(ptr / 16);
	else
	{
		write(1, &hex_digits[ptr % 16], 1);
	}
}

int	ft_prt_pointer(uintptr_t ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
	{
		ft_prt_ptr(ptr);
		count += ft_len_ptr(ptr);
	}
	return (count);
}
