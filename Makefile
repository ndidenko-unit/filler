#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndidenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 13:09:53 by ndidenko          #+#    #+#              #
#    Updated: 2018/06/12 13:09:54 by ndidenko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ndidenko.filler

FILE_C =  main.c manhattan.c printcoord.c free_maps.c

FILE_O = $(FILE_C:.c=.o)

GCC = gcc

FLAG = -Wall -Wextra -Werror

LIB_INC = -I libft/

LIBNAME = ./libft/libft.a

all: $(NAME)

$(LIBNAME): ./libft/libft.h
	make -C ./libft

$(NAME): $(LIBNAME) $(FILE_O)
	$(GCC) $(FILE_O) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(GCC) $(FLAG) -c $< $(LIB_INC)

clean:
	make -C ./libft clean
	rm -f $(FILE_O)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
	make -C ./libft fclean