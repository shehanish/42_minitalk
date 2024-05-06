/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convins2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarunat <skarunat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:33:45 by skarunat          #+#    #+#             */
/*   Updated: 2023/02/22 14:37:17 by skarunat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	else if (number < 0)
	{
		ft_putchar_len('-', length);
		ft_number(-number, length);
	}
	else if (number >= 10)
	{
		ft_number(number / 10, length);
		ft_putchar_len(number % 10 + '0', length);
	}
	else
		ft_putchar_len(number + '0', length);
}

//unsigned int %u

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putchar_len(u % 10 + '0', length);
}

static int	ft_trim(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' && str[i + 1] <= '9' && str[i + 1] >= '0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = ft_trim(str);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - 48);
		}
		else
			result = result + (str[i] - 48);
		i++;
	}
	return (sign * result);
}
