/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:04:51 by aarustam          #+#    #+#             */
/*   Updated: 2024/08/03 17:28:01 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "printf/ft_printf.h"

static void	char_to_bit(int pid, char *str)
{
	int		i;
	char	c;
	int		j;

	j = 0;
	while (ft_strlen(str) >= j)
	{
		i = 8;
		c = str[j];
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	char_to_bit(ft_atoi(argv[1]), argv[2]);
	return (0);
}
