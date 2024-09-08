# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 15:18:17 by bthomas           #+#    #+#              #
#    Updated: 2024/09/08 14:02:24 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02
SRC			= main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
OBJS		= $(SRC:%.cpp=%.o)
CFLAGS		= -g3 -Wall -Werror -Wextra -std=c++98
COMPILER	= c++

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) -I. $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@echo "Removing object files..."
	rm -rf $(OBJS)

fclean: clean
	@echo "Removing program..."
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re