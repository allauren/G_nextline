# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 00:46:43 by allauren          #+#    #+#              #
#    Updated: 2017/11/12 02:37:33 by allauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = get_next_line 
FLAGS = -Wall -Wextra -Werror  -g3 #-fsanitize=address
LIB = libft/libft.a

SRC =get_next_line.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(LIB) $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
