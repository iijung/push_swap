# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2024/06/17 07:41:22 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

CPPFLAGS	+= -MMD -MP
CFLAGS		+= -Wall -Wextra -Werror -O2

ifdef DEBUG
CPPFLAGS	+= -DDEBUG=1
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

LIBS = \
	lib/push_swap/libpushswap.a \
	external/libexternal.a \

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
		ps_atob.c \
		ps_btoa.c \
		ps_sort.c \
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
	for d in $(dir $(LIBS)); do $(MAKE) -C $$d clean; done
	$Q$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	for d in $(dir $(LIBS)); do $(MAKE) -C $$d fclean; done
	$Q$(RM) $(PUSHSWAP) $(CHECKER)

re: fclean
	$Q$(MAKE)

.PHONY: all clean fclean re bonus

# **************************************************************************** #
# for test
# **************************************************************************** #

seq = $(shell seq 100 | sort -R)

test: $(PUSHSWAP)
	./$(PUSHSWAP) $(seq)

seq5	:= $(shell seq 5 | sort -R)
seq100	:= $(shell seq 100 | sort -R)
seq500	:= $(shell seq 500 | sort -R)

test2: $(PUSHSWAP) $(CHECKER)
	@echo "########################################################################"
	@echo "Error"
	@echo "########################################################################"
	./$(PUSHSWAP) | cat -e
	./$(PUSHSWAP) 3 two 1 | cat -e
	./$(PUSHSWAP) 3 2 2 1 | cat -e
	./$(PUSHSWAP) 2147483648 0 | cat -e
	./$(PUSHSWAP) 0 -2147483649 | cat -e
	@echo "########################################################################"
	@echo "already sort 0 "
	@echo "########################################################################"
	./$(PUSHSWAP) 42 | wc -l
	./$(PUSHSWAP) 0 1 2 3 | wc -l
	./$(PUSHSWAP) 0 1 2 3 4 5 6 7 8 9 | wc -l
	@echo "########################################################################"
	@echo "simple (2 or 3)"
	@echo "########################################################################"
	./$(PUSHSWAP) 0 2 1
	./$(PUSHSWAP) 1 0 2
	./$(PUSHSWAP) 1 2 0
	./$(PUSHSWAP) 2 0 1
	./$(PUSHSWAP) 2 1 0
	@echo "########################################################################"
	@echo "simple (good : < 8 | bad : > 12)"
	@echo "########################################################################"
	./$(PUSHSWAP) 1 5 2 4 3 | cut -f 1 | ./$(CHECKER) 1 5 2 4 3
	@./$(PUSHSWAP) 1 5 2 4 3 | wc -l
	./$(PUSHSWAP) $(seq5) | cut -f 1 | ./$(CHECKER) $(seq5)
	@./$(PUSHSWAP) $(seq5) | wc -l
	@echo "########################################################################"
	@echo "middle (5 : < 700, 4 : < 900, 3 : <1100, 2 : < 1300, 1 : 1500)"
	@echo "########################################################################"
	./$(PUSHSWAP) $(seq100) | cut -f 1 | ./$(CHECKER) $(seq100)
	@./$(PUSHSWAP) $(seq100) | wc -l
	@echo "########################################################################"
	@echo "advance (5 : < 5500, 4 : < 7000, 3 : <8500, 2 : < 10000, 1 : 11500)"
	@echo "########################################################################"
	@echo "# adcande start... (tail -f seq500.txt)"
	./$(PUSHSWAP) $(seq500) | nl > seq500.txt
	@tail -1 seq500.txt

.PHONY: test
