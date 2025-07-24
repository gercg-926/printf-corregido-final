# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 15:00:28 by marvin            #+#    #+#              #
#    Updated: 2025/06/16 15:00:28 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c parsing/process_conversion.c parsing/process_format_specifier.c ft_printf_utils/handle_c.c ft_printf_utils/handle_s.c ft_printf_utils/handle_d.c ft_printf_utils/handle_u.c ft_printf_utils/handle_x.c ft_printf_utils/handle_X.c ft_printf_utils/handle_p.c ft_printf_utils/handle_percent.c ft_printf_utils/ft_utoa.c ft_printf_utils/ft_xtoa.c ft_printf_utils/ft_xtoa_ulong.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
