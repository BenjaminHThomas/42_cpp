# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 11:04:17 by bthomas           #+#    #+#              #
#    Updated: 2024/10/14 11:04:32 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RPN
SRC			= main.cpp RPN.cpp
OBJS		= $(SRC:%.cpp=%.o)
CFLAGS		= -Wall -Werror -Wextra -std=c++98
COMPILER	= c++

%.o : %.cpp
	$(COMPILER) $(CFLAGS) -I. -c $< -o $@ 

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