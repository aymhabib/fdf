# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 04:58:22 by aymhabib          #+#    #+#              #
#    Updated: 2019/07/07 04:58:23 by aymhabib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all: $(NAME)

SRCS = src/*.c

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

$(NAME):
	make -C libft
	gcc -I /usr/local/Include $(SRCS) $(LIBFT) -o $(NAME) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit	

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
