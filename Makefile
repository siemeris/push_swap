# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 11:51:03 by issierra          #+#    #+#              #
#    Updated: 2023/12/23 18:50:45 by issierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra
LIBFT=./libft/libft.a
H=push_swap.h

SRC=	push_swap.c check_inputs.c create_stack.c \
		moves.c sort.c sort_utils.c sort_updates.c \


OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	@make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -I $(H) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	@make clean -C ./libft
	@rm -f $(OBJ) 

fclean: clean
	@make clean -C ./libft
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re