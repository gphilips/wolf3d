NAME = wolf3d

SRC = create_win.c main.c
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit
LIBDIR = libft/
LIB = libft.a
LIBPATH = $(addprefix $(LIBDIR), $(LIB))
OBJ = $(SRC:.c=.o)

all: $(NAME)

.PHONY: all clean fclean re

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $@ $(OBJ) $(LIBPATH) $(MLX)
	@echo "$@ created"

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
