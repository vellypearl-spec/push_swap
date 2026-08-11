# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 20:45:33 by vkuzmina          #+#    #+#              #
#    Updated: 2026/08/11 20:47:26 by vkuzmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTNAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft

#Main 
SRC =  

#
ADD = 

OBJ = $(SRC:.c=.o) $(ADD:.c=.o) 
EXT =	$(IDIR)$(NAME:.a=.h)
all: $(NAME) 

#compile files
COMPILE = cc $(CFLAGS) -c
makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)
$(NAME): makelibft $(OBJ)
	@ar -r $(NAME) $(OBJ)


#object files
#.o .c:
#	$(CC) $(CFLAGS) -c $< $^
	
#clean
clean: 
	rm -rf $(NAME) $(OBJ)
	cd $(LIBFTDIR) && make clean
fclean: clean 
	rm -rf $(NAME)
	cd $(LIBFTDIR) && make fclean
re: clean all 