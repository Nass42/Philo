# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 22:31:29 by namohamm          #+#    #+#              #
#    Updated: 2022/05/24 08:06:26 by namohamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC      = gcc
CFLAGS   = -Wall -Wextra -Werror -g

OK_COLOR = \x1b[32;01m

SOURCES  =	ft_action1.c\
			ft_action2.c\
			ft_action3.c\
			ft_atoi1.c\
			ft_atoi2.c\
			ft_list1.c\
			ft_list2.c\
			ft_list3.c\
			ft_split.c\
			ft_strlen.c\
			ft_init_one.c\
			main.c\
			medium_size.c\
			push_chunk.c\
			small_size1.c\
			small_size2.c\
			small_size3.c\
			sort_chunks.c\
			king_size.c\
			ft_error1.c\
			ft_error2.c\
			ft_handler1.c\
			ft_handler2.c\
			ft_error1_1.c\
			ft_error2_2.c\

HEADER = push.h\

OBJECTS  = $(SOURCES:%.c=%.o)
rm = rm -f

all: $(NAME)

macbook:
	make all

$(OBJECTS): %.o : %.c $(HEADER)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJECTS)
	@$(CC) -o $@ $^ $(CFLAGS)
	@echo "$(OK_COLOR)$(NAME) Created successfully !"

fclean: clean
	@rm -f $(NAME)
	@echo "$(OK_COLOR) full clean"

clean:
	@rm -f $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re
