# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2024/06/17 02:46:12 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

CFLAGS		+= -Wall -Wextra -Werror -O2
CPPFLAGS	+= -MMD -MP

ifdef DEBUG
CFLAGS		+= -g -fsanitize=address,undefined
LDFLAGS		+= -fsanitize=address,undefined
endif

Q = @
ifdef VERBOSE
	Q =
endif

# **************************************************************************** #
# dependency
# **************************************************************************** #

LIBS = external/libexternal.a

CPPFLAGS	+= $(foreach dir, $(dir $(LIBS)), -I$(dir))
LDFLAGS 	+= $(foreach dir, $(dir $(LIBS)), -L$(dir))
LDLIBS  	+= $(foreach lib, $(notdir $(LIBS)), -l$(patsubst lib%.a,%,$(lib)))

$(LIBS):
	$Q$(MAKE) -C $(@D)

# **************************************************************************** #
# push_swap
# **************************************************************************** #

PUSHSWAP = push_swap

PUSHSWAP_SRCS = \
		deque.c \
		ps_init.c \
		ps_parse.c \
		ps_atob.c \
		ps_btoa.c \
		ps_solve.c \
		push_swap.c \

PUSHSWAP_OBJS = $(PUSHSWAP_SRCS:.c=.o)
PUSHSWAP_DEPS = $(PUSHSWAP_SRCS:.c=.d)
-include $(PUSHSWAP_DEPS)

$(PUSHSWAP): $(PUSHSWAP_OBJS)
$(PUSHSWAP_OBJS): $(LIBS)

# **************************************************************************** #
# checker
# **************************************************************************** #

CHECKER = checker

CHECKER_SRCS = \
		deque.c \
		ps_init.c \
		ps_parse.c \
		checker.c \

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CHECKER_DEPS = $(CHECKER_SRCS:.c=.d)
-include $(CHECKER_DEPS)

$(CHECKER): $(CHECKER_OBJS)
$(CHECKER_OBJS): $(LIBS)

# **************************************************************************** #
# main
# **************************************************************************** #

all:
	$(MAKE) $(PUSHSWAP)

bonus:
	$(MAKE) $(CHECKER)

clean:
	$Q$(foreach dir, $(dir $(LIBS)), $(MAKE) -C $(dir) clean)
	$Q$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$Q$(foreach dir, $(dir $(LIBS)), $(MAKE) -C $(dir) fclean)
	$Q$(RM) $(PUSHSWAP) $(CHECKER)

re: fclean
	$Q$(MAKE)

.PHONY: all clean fclean re bonus
