# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 19:43:05 by dbozic            #+#    #+#              #
#    Updated: 2025/02/07 19:43:06 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
PROGRAM = My_first_OCF_class

all: $(PROGRAM)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

${PROGRAM}: $(OBJECTS)
		$(CC) $(FLAGS) $(OBJECTS) -o $(PROGRAM)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re