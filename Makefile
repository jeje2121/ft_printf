# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awora <awora@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 11:40:04 by awora             #+#    #+#              #
#    Updated: 2022/04/15 15:31:58 by awora            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putstr.c \
ft_usignnbr.c ft_adressp.c

OBJ = $(SRC:.c=.o )

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a ./libftprintf.a
	ar rcs $(NAME) $(OBJ) 

clean:
	make clean -C libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)
	
re: fclean all