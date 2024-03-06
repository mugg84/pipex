# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 09:23:31 by mmughedd          #+#    #+#              #
#    Updated: 2024/03/05 10:59:50 by mmughedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

SRC_PATH = src/

UTILS = utils.c child_proc.c

UTILS_PATH = utils/

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS = $(addprefix $(SRC_PATH), $(SRC)) $(addprefix $(UTILS_PATH), $(UTILS))

INCS = -I./include

OBJS = $(SRCS:.c=.o)

NAME = pipex

CC = cc

RM = rm -f

FLAGS = -Wextra -Werror -Wall

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

all: $(NAME)

makelibft:
	make -sC $(LIBFT_PATH)

$(NAME): makelibft $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCS)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.phony: all clean fclean re makelibft