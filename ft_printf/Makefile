# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:14:34 by mmughedd          #+#    #+#              #
#    Updated: 2024/02/25 10:54:07 by mmughedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printchar.c ft_printstr.c ft_print_nbr.c ft_print_uint.c ft_print_hex.c ft_print_ptr.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

LIBFT = ../libft

LIBFT_NAME = libft.a

INCS = -I./include

CC = cc

FLAGS = -Wextra -Werror -Wall

AR = ar -rcs

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

makelibft: #TODO:find alternative
	make -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_NAME) .
	mv $(LIBFT_NAME) $(NAME)

$(NAME): makelibft $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	${RM} ${NAME}

re: fclean all

.phony: all clean fclean re makelibft
