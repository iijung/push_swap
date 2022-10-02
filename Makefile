# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2022/10/02 18:11:38 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC = cc
AR = ar
RM = rm -f 

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CPPFLAGS = -I./libft
LDFLAGS = -L./libft
LDLIBS = -lft

ifdef DEBUG
	CFLAGS += -O0 -g -fsanitize=address,undefined
	LDFLAGS += -fsanitize=address,undefined
endif

Q = @
ifdef VERBOSE
	Q =
endif

%.o : %.c
	$Q$(COMPILE.c) $(OUTPUT_OPTION) $<

% : %.o
	$Q$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION)

# **************************************************************************** #
# main
# **************************************************************************** #

NAME = push_swap

src_m = \
		deque.c \
		push_swap.c \
		ps_init.c \
		ps_parse.c \
		ps_atob.c \
		ps_debug.c \

src_b = \
		push_swap.c

SRCS = $(if $(filter bonus, $(MAKECMDGOALS)), $(src_b), $(src_m))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

LIBS = libft/libft.a
DIRS = libft 

all bonus:
	$Q$(MAKE) -C $(DIRS)
	$Q$(MAKE) $(NAME)

$(NAME): $(OBJS)
$(OBJS): $(LIBS)
$(LIBS):
	$Q$(MAKE) -C $(@D) $(@F)

clean:
	$Q$(MAKE) -C $(dir $(LIBS)) clean
	$Q$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$Q$(RM) $(LIBS) $(NAME)

re: fclean
	$Q$(MAKE)

.PHONY: all clean fclean re bonus $(DIRS)

seq = $(shell seq 20 | sort -uR)
test: $(NAME)
	./$(NAME) $(seq)
