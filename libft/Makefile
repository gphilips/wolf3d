# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gphilips <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 15:43:34 by gphilips          #+#    #+#              #
#    Updated: 2016/11/18 21:09:51 by gphilips         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		ft_strncat.c ft_strcat.c ft_strlcat.c \
		ft_memalloc.c ft_memdel.c ft_putchar.c ft_putstr.c ft_putendl.c \
		ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strmap.c ft_strequ.c ft_strnequ.c ft_strmapi.c \
		ft_itoa.c ft_strjoin.c ft_strsub.c ft_strtrim.c ft_lstnew.c \
		ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_strsplit.c ft_lst_push_back.c ft_isupper.c ft_islower.c ft_max.c \
		ft_swap.c ft_strdup_to_c.c ft_strlen_to_c.c ft_count_word.c \
		get_next_line.c

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(FILES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libft created"

.PHONY: clean fclean re

clean :
	@rm -f $(OBJ)
	@echo "Erasing .o files from libft"

fclean : clean
	@rm -f $(NAME)
	@echo "Erasing $(NAME)"

re : fclean all
