# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/11/15 15:22:31 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test-libft
CFLAGS = -Wall -Wextra --std=c++14
SRCS = $(wildcard *.cpp)
TPPS = $(wildcard *.tpp)
INCLUDES = $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)
DEPFILE = .Makefile.dep

$(shell rm -f $(DEPFILE))
$(shell for file in *.cpp; do (gcc --std=c++14 -M "$${file}"; echo "\tg++ \$$(CFLAGS) -c \$$< -o \$$@\n") >> $(DEPFILE); done)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

include $(DEPFILE)

re: fclean all
