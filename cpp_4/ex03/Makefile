# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 15:18:17 by bthomas           #+#    #+#              #
#    Updated: 2024/09/19 11:36:53 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex03
SRC			= main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
OBJS		= $(SRC:.cpp=.o)
CPP_FLAGS		= -Wall -Werror -Wextra -std=c++98 -g3
CPP	= c++

%.o : %.cpp
	$(CPP) $(CPP_FLAGS) -I. -c $< -o $@ 

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) -I. $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@echo "Removing object files..."
	rm -rf $(OBJS)

fclean: clean
	@echo "Removing program..."
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
