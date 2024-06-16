# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 02:34:32 by minjungk          #+#    #+#              #
#    Updated: 2024/06/17 04:40:53 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

LIBPUSHSWAP = libpushswap.a

CPPFLAGS	+= -MMD -MP
CFLAGS		+= -Wall -Wextra -Werror -O2
ARFLAGS		= rsc

ifdef DEBUG
CPPFLAGS	+= -DDEBUG=1
CFLAGS		+= -g -fsanitize=address,undefined
LDFLAGS		+= -fsanitize=address,undefined
endif

# **************************************************************************** #
# dependency
# **************************************************************************** #

LIBS = ../../external/libexternal.a

CPPFLAGS	+= $(foreach dir, $(dir $(LIBS)), -I$(dir))
LDFLAGS 	+= $(foreach dir, $(dir $(LIBS)), -L$(dir))
LDLIBS  	+= $(foreach lib, $(notdir $(LIBS)), -l$(patsubst lib%.a,%,$(lib)))

$(LIBS):
	$Q$(MAKE) -C $(@D)

# **************************************************************************** #
# push_swap
# **************************************************************************** #

SRCS = \
	ps_assert.c \
	deque.c \
	ps_init.c \
	ps_parse.c \

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

all bonus: $(LIBPUSHSWAP)

$(LIBPUSHSWAP): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$(RM) $(LIBPUSHSWAP)

re: fclean
	$(MAKE) $(LIBPUSHSWAP)

.PHONY: all clean fclean re bonus
