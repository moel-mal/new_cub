# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 16:46:47 by moel-mal          #+#    #+#              #
#    Updated: 2020/12/24 17:17:30 by moel-mal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = src/*/*.c

LIBFT = ./libft/libft.a

INCLUDE = -I ./libft/libft.h -I ./include/cub3d.h -I /usr/local/include

GCC = gcc -Wall -Werror -Wextra  -g3 -fsanitize=address
	
GNL = get_next_line/get_next_line.c\

FRAMEWORK = -framework OpenGL -framework AppKit -Wreturn-type\

MLX = -lmlx\

FLAGS = -Wall -Wextra -Werror\

RED=\033[0;31m\
GREEN=\033[0;32m\
NC=\033[0m\

all: $(NAME)

$(NAME):
	@echo  "\033[0;32m > compilation success \033[0m"
	gcc   $(SRC) -o $(NAME) $(GNL) $(LIBFT) $(MLX) $(FRAMEWORK)
	
clean:
	@echo  "\033[0;31m > CLEAN OBJECTS \033[0m" 
	rm -f $(OBJECT)
	
fclean: clean
	@echo  "\033[0;31m > CLEAN ALL \0033[0m"
	rm -f $(NAME)
	rm -f cub3D
	
re: fclean all