# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 11:45:45 by bthomas           #+#    #+#              #
#    Updated: 2024/08/28 13:23:20 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= sed42
SRC			= main.cpp sed.cpp
OBJS		= $(SRC:%.cpp=%.o)

FLAGS		= -Wall -Werror -Wextra -std=c++98 -g3
COMPILER	= c++

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) -I. $(OBJS) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJS)

fclean: clean
	@echo "Removing program"
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

