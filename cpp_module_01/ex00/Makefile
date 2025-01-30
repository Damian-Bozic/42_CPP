# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 13:24:23 by dbozic            #+#    #+#              #
#    Updated: 2025/01/15 13:24:25 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
PROGRAM = BraiiiiiiinnnzzzZ

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
