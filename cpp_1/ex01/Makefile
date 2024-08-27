# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 17:30:06 by bthomas           #+#    #+#              #
#    Updated: 2024/08/27 13:56:18 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= zombieHorde

SRC				= Zombie.cpp main.cpp zombieHorde.cpp

OBJDIR		= objs
OBJS			= $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

CFLAGS		= -Wall -Werror -Wextra -std=c++98
DEP_FLAG	= -MMD
DEP				= $(OBJS:%.o=%.d)
COMPILER	= c++

all: $(OBJDIR) $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(COMPILER) $(CFLAGS) $(DEP_FLAG) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) -I. $(OBJS) -o $(NAME)

clean:
	@echo "Cleaning objects..."
	rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing program..."
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
