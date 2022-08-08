# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 02:02:39 by zessadqu          #+#    #+#              #
#    Updated: 2022/08/04 11:14:38 by zessadqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

BONUS = fractol_bon

Headers = fractol.h fractol_b/fractol_bonus.h

SRC = event_handlers.c \
	  fracts.c main.c \
	  iter_loop.c map_colors.c \
	  my_mlx_hook.c \
	  keys_handler.c \
	  switcher.c \
	  ft_putstr_fd.c\

SRC_bonus = fractol_b/event_handlers_bonus.c \
	  fractol_b/fracts_bonus.c \
	  fractol_b/main_bonus.c \
	  fractol_b/iter_loop_bonus.c \
	  fractol_b/map_colors_bonus.c \
	  fractol_b/my_mlx_hook_bonus.c \
	  fractol_b/keys_handler_bonus.c \
	  fractol_b/switcher_bonus.c \
	  fractol_b/ft_putstr_fd.c\

OBJS = $(SRC:.c=.o)

OBJS_bonus = $(SRC_bonus:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo "run only the executable to see usage"

clean :
	@rm -f $(OBJS) $(OBJS_bonus)

fclean : clean
	@rm -f $(NAME) $(BONUS)

re : fclean all

bonus : $(BONUS)

$(BONUS) : $(OBJS_bonus)
	$(CC) $(CFLAGS) $(OBJS_bonus) $(MLX) -o $(BONUS)
	@echo "run only the executable to see usage"

%.o: %.c $(Headers)
	$(CC) $(CFLAGS) -c $< -o $@