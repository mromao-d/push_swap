# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 20:31:57 by mromao-s          #+#    #+#              #
#    Updated: 2026/03/16 20:40:45 by mromao-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS = lst_operations.c \
		movements.c \
		push_swap.c \
		sorts.c \
		split.c \
		utils.c \
		sorts_utils.c \
		frees.c


OBJS=$(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

run:
	@$(NAME)
	@./$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
