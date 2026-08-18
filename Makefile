# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 20:45:33 by vkuzmina          #+#    #+#              #
#    Updated: 2026/08/18 11:17:15 by vkuzmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include

LIBFTDIR = ./include/libft

SRC = src/main/push_swap.c \
      src/utils/stack_utils.c \
      src/utils/misc.c \
      src/parsing/parse.c \
	  src/operations/push.c \
	  src/operations/swap.c \
	  src/operations/rotate.c \
	  src/operations/reverse_rotate.c \
	  src/sorting/small_sort.c \
	  src/utils/helper.c \
	  src/utils/operation_cost.c \
	  src/sorting/simple_strategy.c \
	  src/metric/disorder_metric.c \
	  src/sorting/medium_sort.c \
	  src/sorting/complex_sort.c \
	  src/utils/rank_distance.c \
	  src/utils/sorting_utility.c
	  
OBJ = $(SRC:.c=.o)

BENCH_SRC =	src/parsing/parse.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/operations/swap.c \
			src/sorting/small_sort.c \
			src/sorting/simple_strategy.c \
			src/metric/disorder_metric.c \
			src/utils/stack_utils.c \
			src/utils/misc.c \
			src/utils/helper.c \
			src/utils/operation_cost.c \
			src/sorting/medium_sort.c \
			src/sorting/complex_sort.c \
			src/sorting/custom_strategy.c \
			src/utils/rank_distance.c \
			src/utils/sorting_utility.c
BENCH_OBJ = $(BENCH_SRC:.c=.o)

BENCH_MAIN = tests/simple_benchmark.o

benchmark: $(BENCH_OBJ) $(BENCH_MAIN)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(BENCH_OBJ) $(BENCH_MAIN) $(LIBFTDIR)/libft.a -o benchmark
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BENCH_OBJ) $(BENCH_MAIN)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) benchmark
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
