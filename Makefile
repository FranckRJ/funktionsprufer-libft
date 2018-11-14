# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/11/13 14:30:24 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test-libft
CFLAGS = -Wall -Wextra --std=c++14
SRCS = $(wildcard *.cpp)
TPPS = $(wildcard *.tpp)
INCLUDES = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SRCS) $(TPPS) $(INCLUDES)
	g++ $(CFLAGS) $(SRCS) -L. -lft -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
