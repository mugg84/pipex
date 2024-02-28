# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 07:55:02 by mmughedd          #+#    #+#              #
#    Updated: 2024/02/25 10:37:30 by mmughedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

SRC_PATH = src/

UTILS = utils.c

UTILS_PATH = utils/

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

FT_PRINTF_PATH = ft_printf/

FT_PRINTF_NAME = libftprintf.a

FT_PRINTF = $(FT_PRINTF_PATH)$(FT_PRINTF_NAME)

SRCS = $(addprefix $(SRC_PATH), $(SRC)) $(addprefix $(UTILS_PATH), $(UTILS))

INCS = -I./include

OBJS = $(SRCS:.c=.o)

NAME = pipex

CC = cc

RM = rm -f

FLAGS = -g#-Wextra -Werror -Wall

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

all: $(NAME)

makelibft:
	make -sC $(LIBFT_PATH)

makeprintf:
	make -sC $(FT_PRINTF_PATH)

$(NAME): makelibft makeprintf $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) $(INCS)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)

re: fclean all

.phony: all clean fclean re makelibft