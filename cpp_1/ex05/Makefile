# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 14:15:16 by bthomas           #+#    #+#              #
#    Updated: 2024/08/28 14:18:08 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harl
SRC			= main.cpp Harl.cpp
OBJS		= $(SRC:%.cpp=%.o)
CFLAGS		= -Wall -Werror -Wextra -std=c++98
COMPILER	= c++

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) -I. $(OBJS) -o $(NAME)

clean:
	@echo "Removing objects..."
	rm -rf $(OBJS)

fclean: clean
	@echo "Removing program..."
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re