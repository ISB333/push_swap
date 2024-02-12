# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adesille <adesille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 13:22:58 by adesille          #+#    #+#              #
#    Updated: 2024/02/12 11:38:55 by adesille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################## ARGUMENTS ########################

NAME = push_swap
CFLAGS += -Wall -Wextra -Werror -Ialgo -Iinit -Iprotect
CC = cc

######################## SOURCES ########################

SRCS = main.c
ALGO = ./algo/push_swap.c ./algo/push_swap_utils.c ./algo/three_sorter.c \
		./algo/sorter_stack_a_five.c ./algo/sorter_stack_b_five.c \
		./algo/push_swap_algo_extremes.c ./algo/push_swap_algo_inside_stacks.c
OPE = ./algo/ope/push.c ./algo/ope/reverse_rotate.c \
		./algo/ope/rotate.c ./algo/ope/swap.c

INIT = ./init/init_array.c ./init/init_list.c ./init/init_utils.c
		
PROT = ./protect/protect.c ./protect/protect_utils_1.c \
		./protect/protect_utils_2.c ./protect/protect_utils_3.c

OBJS = ${SRCS:.c=.o} ${INIT:.c=.o} ${ALGO:.c=.o} ${PROT:.c=.o} ${OPE:.c=.o}

######################## RULES ########################

all: ${NAME}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${NAME}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
