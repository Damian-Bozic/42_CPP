# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 16:06:37 by dbozic            #+#    #+#              #
#    Updated: 2025/12/22 16:06:39 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = srcs/
OBJ_DIR = objs/
SOURCES = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)%.o)
OBJECTS_DIRS = $(addprefix())
PROGRAM = DynamicCastTest

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
