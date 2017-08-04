# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gphilips <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 19:19:11 by gphilips          #+#    #+#              #
#    Updated: 2017/08/03 19:54:53 by gphilips         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = init.c read_file.c map.c draw.c raycast.c move.c minimap.c textures.c \
	  events.c keypress.c create_win.c free.c main.c
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit
LIBDIR = libft/
LIB = libft.a
LIBPATH = $(addprefix $(LIBDIR), $(LIB))
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@gcc -o $(NAME) $(OBJ) $(LIBPATH) $(MLX)
	@echo "$@ created"

all: $(NAME)

clean:
	@make clean -C $(LIBDIR)
	@rm -f $(OBJ)
	@echo "Erasing .o files from wolf3d"

fclean:
	@make fclean -C $(LIBDIR)
	@rm -f $(OBJ)
	@echo "Erasing .o files from wolf3d"
	@rm -f $(NAME)
	@echo "Erasing $(NAME)"

re: fclean all
