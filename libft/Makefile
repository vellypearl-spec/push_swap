# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/22 11:23:51 by vkuzmina          #+#    #+#              #
#    Updated: 2026/07/28 12:34:15 by vkuzmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

#Main functions
SRC =  ft_atoi.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_strncmp.c \
ft_tolower.c \
ft_toupper.c \
ft_memcmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strchr.c \
ft_strdup.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_bzero.c \
ft_calloc.c \
ft_memchr.c \
ft_strlcat.c \
ft_strlcpy.c \

#Additional functions
ADD = ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

#List functions
LST = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c\
ft_lstmap.c

#Ft_printf functions

PTF = ft_printf.c \
ft_checker.c \
ft_printc.c \
ft_printd_i.c \
ft_prints.c \
ft_printu.c \
ft_printp.c \
ft_printx_X.c 

#GNL functions
GNL = get_next_line.c \
get_next_line_utils.c

OBJ = $(SRC:.c=.o) $(ADD:.c=.o) $(LST:.c=.o) $(PTF:.c=.o) $(GNL:.c=.o)
EXT =	$(IDIR)$(NAME:.a=.h)

#compile files
COMPILE = cc $(CFLAGS) -c
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
all: $(NAME) 

#object files
.o .c:
	$(CC) $(CFLAGS) -c $< $^
	
#clean
clean: 
	rm -rf $(NAME) $(OBJ)
fclean: clean 
	rm -rf $(NAME)
re: clean all 

