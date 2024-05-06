/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarunat <skarunat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:51:50 by skarunat          #+#    #+#             */
/*   Updated: 2023/01/12 14:05:15 by skarunat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_print_checker(char s, va_list *args, int *length, int *i)
{
	if (s == 's')
		ft_print_str(va_arg(*args, char *), length);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), length);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), length);
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), length, 'X');
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), length, 'x');
	else if (s == 'p')
		ft_put_pointer(va_arg(*args, size_t), length);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), length);
	else if (s == '%')
		ft_putchar_len('%', length);
	else
		*i -= 1;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		length;
	int		i;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_print_checker(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}

// int   main()
// {
//  ft_printf("char: %c\n", 'g');
//  ft_printf("string: %s\n", "hbjhuir");
//  ft_printf("int: %i\n", -16434);
//  ft_printf("decimal: %d\n", 16434);
//  ft_printf("hex lower: %x\n", 17);
//  ft_printf("hex upper: %X\n", 17);
//  ft_printf("hex pointer: %p\n", 13);
//  ft_printf("unsigned in: %u\n", 67243);
//  ft_printf("percent: %%\n", "  %");
//  return 0;
// }

// #include "ft_printf.h"
// #include <stdio.h>

// int main()
// {
// 	ft_printf("\nOur c: %c\n", 'a');
// 	printf("\nYOur c: %c\n", 'a');
// }
