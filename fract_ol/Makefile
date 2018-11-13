# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 13:09:11 by grdalmas          #+#    #+#              #
#    Updated: 2018/07/14 20:53:39 by grdalmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol	

CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework Appkit

OBJ_PATH = ./obj/
LIBFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./srcS/

SRC_NAME =	fractol_main.c \
			fractol_init.c \
			fractol_put_img.c \
			fractol_key_hooks.c \
			fractals.c \
			fractol_key_hooks.c \
			fractol_menu.c \
			fractol_mouse_params.c \
			fractol_print_menu.c \
			fractol_print_menu_2.c
			
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fractol.h

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LIBFT_PATH)
			$(CC) -o $(NAME) $(FRAM) -L $(LIBFT_PATH) -lft $^ -o $@
			@echo "It's done, fract'ol is ready"
			
$(OBJ_PATH)%.o :$(SRC_PATH)%.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
		@make -C $(LIBFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "Objects removed"

fclean: clean
		@make -C $(LIBFT_PATH) fclean
		@rm -rf $(NAME)
		@echo "All clean"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
