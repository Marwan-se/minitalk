# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 03:07:55 by msekhsou          #+#    #+#              #
#    Updated: 2022/12/20 20:30:54 by msekhsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client
NAME3 = server_bonus
NAME4 = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = Minitalk.h
SRC = Minitalk_utils.c
BSRC = Minitalk_utils_bonus.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all:$(NAME1) $(NAME2)

$(NAME1) : server.c $(INC)
	 		$(CC) $(CFLAGS) server.c $(SRC) -o server
$(NAME2) : client.c $(INC)
			$(CC) $(CFLAGS) client.c $(SRC) -o client

bonus: $(NAME3) $(NAME4)

$(NAME3) : server_bonus.c $(INC)
	 		$(CC) $(CFLAGS) server_bonus.c $(BSRC) -o server_bonus
$(NAME4) : client_bonus.c $(INC)
			$(CC) $(CFLAGS) client_bonus.c $(BSRC) -o client_bonus

clean:
		$(RM) $(OBJ) $(BOBJ)
fclean: clean
		$(RM) $(NAME) $(BOBJ)

re: fclean all

.PHONY: all clean fclean
