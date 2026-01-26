# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 17:19:36 by dbozic            #+#    #+#              #
#    Updated: 2026/01/07 17:19:37 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = srcs/
OBJ_DIR = objs/
SOURCES = main.cpp Span.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)%.o)
OBJECTS_DIRS = $(addprefix())
PROGRAM = span

all: $(PROGRAM)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

${PROGRAM}: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(PROGRAM)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

full: re
	make clean
	clear

.PHONY: all clean fclean re full
