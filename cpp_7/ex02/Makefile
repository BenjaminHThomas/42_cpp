# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 19:45:57 by bthomas           #+#    #+#              #
#    Updated: 2024/09/28 19:46:07 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02
SRC			= main.cpp \
				Array.tpp
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