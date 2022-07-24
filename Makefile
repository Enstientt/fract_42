# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 02:02:39 by zessadqu          #+#    #+#              #
#    Updated: 2022/07/24 19:17:10 by zessadqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

SRC = event_handlers.c \
	  fracts.c main.c \
	  iter_loop.c map_colors.c \
	  my_mlx_hook.c \
	  keys_handler.c

OBJS = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all