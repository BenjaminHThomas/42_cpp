# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 15:18:17 by bthomas           #+#    #+#              #
#    Updated: 2024/09/16 17:24:41 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex00
SRC			= main.cpp Bureaucrat.cpp
OBJS		= $(SRC:%.cpp=%.o)
CFLAGS		= -Wall -Werror -Wextra -std=c++98
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

re: fclean 
	make all

.PHONY: all clean fclean re