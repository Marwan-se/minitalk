# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 03:07:55 by msekhsou          #+#    #+#              #
#    Updated: 2022/12/17 14:23:59 by msekhsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = Minitalk.h
SRC = Minitalk_utils.c
OBJ = $(SRC:.c=.o)

all:$(NAME1) $(NAME2)

$(NAME1) : server.c $(INC)
	 		$(CC) $(CFLAGS) server.c $(SRC) -o server
$(NAME2) : client.c $(INC)
			$(CC) $(CFLAGS) client.c $(SRC) -o client

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean
