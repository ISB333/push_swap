# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 13:22:58 by adesille          #+#    #+#              #
#    Updated: 2024/03/03 12:11:56 by isb3             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################## ARGUMENTS ########################

NAME = push_swap
CFLAGS += -Wall -Wextra -Werror -Ialgo -Iinit -Iprotect -g3 -fsanitize=address 
CC = cc

######################## SOURCES ########################

SRCS = main.c

ALGO = ./algo/push_swap.c ./algo/three_sorter.c \
		./algo/five_sorter_a.c

UTILS = ./algo/utils/algo_utils.c ./algo/utils/algo_utils2.c \
		./algo/utils/extractor.c ./algo/utils/scrapper.c \
		./algo/utils/sorter_utils.c

OPE = ./algo/ope/push.c ./algo/ope/swap.c ./algo/ope/rotate.c \
       ./algo/ope/reverse_rotate.c

INIT = ./init/init_list.c ./init/init_utils.c 
		
PROT = ./protect/protect.c ./protect/protect_utils_1.c \
       ./protect/protect_utils_2.c 

OBJDIR = 0_obj

OBJS = $(OBJDIR)/main.o \
       $(ALGO:%.c=$(OBJDIR)/%.o) \
       $(UTILS:%.c=$(OBJDIR)/%.o) \
       $(OPE:%.c=$(OBJDIR)/%.o) \
       $(INIT:%.c=$(OBJDIR)/%.o) \
       $(PROT:%.c=$(OBJDIR)/%.o)

######################## RULES ########################

all: ${NAME}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJDIR}/%.o: %.c
		mkdir -p $(@D)
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -rf ${OBJDIR} ${NAME}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
