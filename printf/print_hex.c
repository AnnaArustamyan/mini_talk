/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:18:56 by aarustam          #+#    #+#             */
/*   Updated: 2024/04/05 21:19:03 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lower_hex(unsigned int p)
{
	int	len;

	len = 0;
	print_ptr_hex(p, "0123456789abcdef");
	if (p == 0)
		return (1);
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	print_upper_hex(unsigned int p)
{
	int	len;

	len = 0;
	print_ptr_hex(p, "0123456789ABCDEF");
	if (p == 0)
		return (1);
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}
