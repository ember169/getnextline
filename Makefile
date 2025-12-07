# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgervet <42@leogervet.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 16:50:13 by lgervet           #+#    #+#              #
#    Updated: 2025/12/06 16:56:16 by lgervet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        := get_next_line.a

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs
RM          := rm -f

# ******************************** MANDATORY ******************************** #

SRCS        := get_next_line.c \
               get_next_line_utils.c

OBJS        := $(SRCS:.c=.o)

# ********************************* BONUS *********************************** #

SRCS_BONUS  := get_next_line_bonus.c \
               get_next_line_utils_bonus.c

OBJS_BONUS  := $(SRCS_BONUS:.c=.o)

BONUS_DONE  := .bonus_done

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_DONE)

$(BONUS_DONE): $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@touch $(BONUS_DONE)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(BONUS_DONE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

