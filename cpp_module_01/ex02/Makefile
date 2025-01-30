# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 17:48:54 by dbozic            #+#    #+#              #
#    Updated: 2025/01/17 17:48:56 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
PROGRAM = HI_THIS_IS_BRAIN

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