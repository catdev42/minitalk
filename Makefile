# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/03/28 18:35:47 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME	:= pipex
# NAME_BONUS := pipexbonus

NAME_SERVER := server
NAME_CLIENT	:= client

LIBNAME = libft.a
LIBDIR = ./libft
LIBFT = ./libft/libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= .
SRC_SERVER  	:= server.c
OBJS_SERVER    	= $(SRC_SERVER:.c=.o)

SRC_CLIENT  	:= client.c
OBJS_CLIENT   	= $(SRC_CLIENT:.c=.o)

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror -g

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make -C $(LIBDIR)

$(NAME_SERVER): $(LIBFT) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

clean:
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	cd $(LIBDIR) && make fclean

re: fclean all
