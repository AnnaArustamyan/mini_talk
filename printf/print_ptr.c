/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:19:21 by aarustam          #+#    #+#             */
/*   Updated: 2024/04/05 21:19:28 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr_hex(unsigned long long p, char *base)
{
	if (p >= 16)
	{
		print_ptr_hex(p / 16, base);
		ft_putchar(base[p % 16]);
	}
	else
	{
		ft_putchar(base[p]);
	}
}

int	print_ptr(unsigned long long p)
{
	int	len;

	len = 2;
	write (1, "0x", 2);
	print_ptr_hex(p, "0123456789abcdef");
	if (p == 0)
		return (3);
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}
