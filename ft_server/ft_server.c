/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarunat <skarunat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:20:55 by skarunat          #+#    #+#             */
/*   Updated: 2023/02/23 13:52:36 by skarunat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include	<signal.h>
// #include	<stdio.h>

#include "../include/minitalk.h"

void	sig_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./server \n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message... \n");
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause ();
	}
	return (0);
}
