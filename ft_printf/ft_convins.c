/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarunat <skarunat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:12:18 by skarunat          #+#    #+#             */
/*   Updated: 2023/01/11 17:33:39 by skarunat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <unistd.h>
//#include <stdio.h>

//print a character %c

void	ft_putchar_len(char c, int *length)
{
	write(1, &c, 1);
	*length += 1;
}

//print a string %s

void	ft_print_str(char *str, int *length)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar_len(str[i], length);
		i++;
	}
}

//pointer %p

void	ft_put_pointer(size_t ptr, int *len)
{
	char	string[25];
	char	*base_value;
	int		i;

	base_value = "0123456789abcdef";
	i = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*len += 5;
		return ;
	}
	if (ptr == 0)
		ft_putchar_len('0', len);
	write(1, "0x", 2);
	*len += 2;
	while (ptr != 0)
	{
		string[i] = base_value[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(string[i], len);
}
//hexadecimal - x or X

void	ft_hexadecimal(unsigned int x, int *length, char x_or_X)
{
	char	str[25];
	char	*base_character;
	int		i;

	if (x_or_X == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', length);
		return ;
	}
	while (x != 0)
	{
		str[i] = base_character[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_len(str[i], length);
	}
}
