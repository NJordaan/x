# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njordaan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 08:22:22 by njordaan          #+#    #+#              #
#    Updated: 2018/08/07 11:47:39 by njordaan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a
FLAGS = -Wall -Wextra -Werror
SRC = color.c \
	  draw.c \
	  image.c \
	  math.c \
	  mesh.c \
	  object.c \
	  run.c \
	  scene.c \
	  vector.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC) $(FLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	-rm $(NAME)

re: fclean all
