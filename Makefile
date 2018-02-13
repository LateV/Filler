# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vibondar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 13:42:50 by vibondar          #+#    #+#              #
#    Updated: 2018/01/26 13:42:53 by vibondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vibondar.filler

LIBFTDIR = libft/

SRC =	main.c 				\
		ft_rmap.c 			\
		ft_pars.c 			\
		ft_game.c 			\
		ft_putcoord.c 		\
		ft_son.c 			\

OBJ = $(SRC:.c=.o)

HEADER = filler.h
HEADERLIBFT = libft/libft.h
CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o players/$(NAME) -L./$(LIBFTDIR) -lft

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFTDIR)libft.a: libft/Makefile
	make -C $(LIBFTDIR)

clean:
		rm -f $(OBJ)
		make clean -C $(LIBFTDIR)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFTDIR)libft.a

re: fclean all
