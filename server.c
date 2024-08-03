/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:35:04 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/03 17:40:12 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <stdlib.h>

static void	handler(int sig)
{
	static int	byte = 0;
	static int	i = 7;

	byte += (sig & 1) << i;
	i--;
	if (i == -1)
	{
		ft_printf("%c", byte);
		if (byte == '\0')
			ft_printf("%c", '\n');
		byte = 0;
		i = 7;
	}
}

int	main(void)
{
	ft_printf("Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler);
		pause();
	}
	return (0);
}