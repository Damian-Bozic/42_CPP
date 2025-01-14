# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:10:01 by dbozic            #+#    #+#              #
#    Updated: 2025/01/06 15:10:03 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
MAIN = Main.cpp
SOURCES = Contact.cpp PhoneBook.cpp HelperFunctions.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
NAME = PhoneBook.a
PROGRAM = PhoneBook

all: $(PROGRAM)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(PROGRAM): $(NAME)
	$(CC) $(FLAGS) $(MAIN) $(NAME) -o $(PROGRAM)

%.o: %.c
	$(CC) $(FLAGS) -I. -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(PROGRAM) $(BPROGRAM)

cc:
	$(CC) $(FLAGS) $(MAIN) $(NAME) $(LIBFT) $(MINILIBX) -lXext -lX11 -o $(PROGRAM)

re: fclean all

full: all clean
	clear