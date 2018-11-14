# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/11/14 17:28:34 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test-libft
CFLAGS = -Wall -Wextra --std=c++14
SRCS = $(wildcard *.cpp)
TPPS = $(wildcard *.tpp)
INCLUDES = $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)

%.o: %.cpp $(INCLUDES) $(TPPS)
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
