# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 14:43:50 by bthomas           #+#    #+#              #
#    Updated: 2024/08/27 14:47:14 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= brain
SRC			= main.cpp
OBJS		= $(SRC:%.cpp=%.o)
CFLAGS		= -Wall -Werror -Wextra -std=c++98
COMPILER	= c++

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJS)

fclean: clean
	@echo "Removing program..."
	rm -rf $(NAME)

re: flcean all

.PHONY: all clean fclean re