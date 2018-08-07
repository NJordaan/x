# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njordaan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/13 11:16:28 by njordaan          #+#    #+#              #
#    Updated: 2018/08/06 14:11:54 by njordaan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= program.njordaan
FRAME= -framework OpenGL -framework Appkit -lmlx
FLAGS= -Wall -Wextra -Werror
SRC= ./src/src.a
LIB= ./lib/lib.a

compile:
	make -C ./lib/
	make -C ./src/
	gcc $(FLAGS) $(FRAME) -o $(NAME) main.c $(LIB) $(SRC)
	clear

run: compile
	./$(NAME)

clean:
	make -C ./lib/ clean
	make -C ./src/ clean

leaks:
	leaks $(NAME) | grep "Process"

all: run
