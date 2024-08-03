/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:16:09 by aarustam          #+#    #+#             */
/*   Updated: 2024/04/08 17:27:19 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parz(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(args, int));
	if (c == 'd' || c == 'i')
		len += print_decim(va_arg(args, int));
	if (c == 's')
		len += print_str(va_arg(args, char *));
	if (c == 'u')
		len += print_unsigned(va_arg(args, unsigned int));
	if (c == 'p')
		len += print_ptr(va_arg(args, unsigned long long));
	if (c == 'x')
		len += print_lower_hex(va_arg(args, unsigned int));
	if (c == 'X')
		len += print_upper_hex(va_arg(args, unsigned int));
	if (c == '%')
	{
		len += 1;
		ft_putchar('%');
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len += parz(str[i + 1], args);
			i++;
		}
		else
		{
			print_char(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main()
{
	unsigned int c = 6976176;
	ft_printf("\n%uab%c %ddula&c %c", c, 'd',8,9);
	return(0);
}*/
