# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 02:02:39 by zessadqu          #+#    #+#              #
#    Updated: 2022/07/31 17:09:25 by zessadqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = @gcc

BONUS = fractol_bon

Header = fractol.h

Header_bonus = fractol_b/fractol_bonus.h

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

OBJS = $(SRC:.c=.o)

B_OBJS = $(SRC_bonus:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo "run only the executable to see usage"

clean :
	@rm -f $(OBJS) $(B_OBJS)

fclean : clean
	@rm -f $(NAME) $(BONUS)

re : fclean all

bonus : $(BONUS)

$(BONUS) : $(B_OBJS)
	@gcc $(FLAGS) $(B_OBJS) $(MLX) -o $(BONUS)
	@echo "run only the executable to see usage"

$(OBJS) : $(Header)

$(B_OBJS) : $(Header_bonus)