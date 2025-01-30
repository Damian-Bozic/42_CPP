# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:28:27 by dbozic            #+#    #+#              #
#    Updated: 2025/01/21 15:28:28 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
PROGRAM = Sed_is_for_losers

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