# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adesille <adesille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 13:22:58 by adesille          #+#    #+#              #
#    Updated: 2024/03/05 13:25:24 by adesille         ###   ########.fr        #
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

BONUS = ./0_checker/checker.c

OBJDIR = 0_obj

BONUS_OBJS = $(BONUS:%.c=$(OBJDIR)/%.o)
COMMON_OBJS = $(ALGO:%.c=$(OBJDIR)/%.o) \
			  $(UTILS:%.c=$(OBJDIR)/%.o) \
			  $(OPE:%.c=$(OBJDIR)/%.o) \
			  $(INIT:%.c=$(OBJDIR)/%.o) \
			  $(PROT:%.c=$(OBJDIR)/%.o)

######################## RULES ########################

all: ${NAME}

${NAME}: ${OBJDIR}/main.o ${COMMON_OBJS}
		${CC} ${CFLAGS} ${OBJDIR}/main.o ${COMMON_OBJS} -o ${NAME}

bonus: ${BONUS_OBJS} ${COMMON_OBJS}
		${CC} ${CFLAGS} ${BONUS_OBJS} ${COMMON_OBJS} -o checker

${OBJDIR}/%.o: %.c
		mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -rf ${OBJDIR} ${NAME} checker

fclean: clean
		rm -f ${NAME} checker

re: fclean all

.PHONY: all clean fclean re


# ######################## ARGUMENTS ########################

# NAME = push_swap
# CFLAGS += -Wall -Wextra -Werror -Ialgo -Iinit -Iprotect -g3 -fsanitize=address 
# CC = cc

# ######################## SOURCES ########################

# SRCS = main.c

# ALGO = ./algo/push_swap.c ./algo/three_sorter.c \
# 		./algo/five_sorter_a.c

# UTILS = ./algo/utils/algo_utils.c ./algo/utils/algo_utils2.c \
# 		./algo/utils/extractor.c ./algo/utils/scrapper.c \
# 		./algo/utils/sorter_utils.c

# OPE = ./algo/ope/push.c ./algo/ope/swap.c ./algo/ope/rotate.c \
#        ./algo/ope/reverse_rotate.c

# INIT = ./init/init_list.c ./init/init_utils.c 
		
# PROT = ./protect/protect.c ./protect/protect_utils_1.c \
#        ./protect/protect_utils_2.c 

# OBJDIR = 0_obj

# BONUS = ./0_checker/checker.c

# OBJS = $(OBJDIR)/main.o \
#        $(ALGO:%.c=$(OBJDIR)/%.o) \
#        $(UTILS:%.c=$(OBJDIR)/%.o) \
#        $(OPE:%.c=$(OBJDIR)/%.o) \
#        $(INIT:%.c=$(OBJDIR)/%.o) \
#        $(PROT:%.c=$(OBJDIR)/%.o)

# OBJS_BONUS = $(BONUS:%.c=$(OBJDIR)/%.0)

# ######################## RULES ########################

# all: ${NAME}

# ${NAME}: ${OBJS}
# 		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

# bonus: ${OBJS_BONUS}
# 		${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME}_bonus

# ${OBJDIR}/%.o: %.c
# 		mkdir -p $(@D)
# 		${CC} ${CFLAGS} -c $< -o $@

# clean:
# 		rm -rf ${OBJDIR} ${NAME} ${NAME}_bonus

# fclean: clean
# 		rm -f ${NAME} ${NAME}_bonus

# re: fclean all

# .PHONY: all clean fclean re bonus
