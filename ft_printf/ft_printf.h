/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarunat <skarunat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:33:55 by skarunat          #+#    #+#             */
/*   Updated: 2023/02/22 11:32:17 by skarunat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putchar_len(char c, int *length);

void	ft_print_str(char *str, int *length);

void	ft_put_pointer(size_t ptr, int *len);

void	ft_hexadecimal(unsigned int x, int *length, char x_or_X);

void	ft_unsigned_int(unsigned int u, int *length);

void	ft_number(int number, int *length);

int		ft_printf(const char *string, ...);

int		ft_atoi(const char *str);

#endif
