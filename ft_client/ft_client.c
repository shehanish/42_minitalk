/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarunat <skarunat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:20:52 by skarunat          #+#    #+#             */
/*   Updated: 2023/03/07 14:59:06 by skarunat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include	<signal.h>
 #include	<unistd.h>
 #include <sys/types.h>
// #include	<stdlib.h>
// #include	<stdlib.h>

#include "../include/minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(pid, argv[2][i]);
			i++;
		}
		send_char(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
