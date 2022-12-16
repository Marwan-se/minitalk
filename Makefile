# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:57:02 by msekhsou          #+#    #+#              #
#    Updated: 2022/12/16 06:47:01 by msekhsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = server.c client.c Minitalk_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c Minitalk.h
		$(CC) $(CFLAGS) -o $@ -c $<
		
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean
