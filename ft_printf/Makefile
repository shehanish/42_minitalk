# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarunat <skarunat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:34:03 by skarunat          #+#    #+#              #
#    Updated: 2023/02/22 11:32:07 by skarunat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= ft_printf.c\
							 ft_convins.c\
							  ft_convins2.c\

OBJS		= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
						cc $(CFLAGS) -c $(SRCS)
						ar rcs $(NAME) $(OBJS)

clean:
						$(RM) $(OBJS)

fclean:			clean
						$(RM) $(NAME)

re:						fclean all

.PHONY:			all clean fclean re