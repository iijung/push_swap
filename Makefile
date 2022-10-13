# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2022/10/13 12:53:31 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC = $Qcc
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

# **************************************************************************** #
# dependency
# **************************************************************************** #

LIBFT = libft/libft.a

$(LIBFT):
	$Q$(MAKE) -C $(@D)

# **************************************************************************** #
# push_swap
# **************************************************************************** #

PUSHSWAP = push_swap

PUSHSWAP_SRCS = \
		deque.c \
		push_swap.c \
		ps_init.c \
		ps_parse.c \
		ps_atob.c \
		ps_btoa.c \
		ps_solve.c \
		ps_debug.c \

PUSHSWAP_OBJS = $(PUSHSWAP_SRCS:.c=.o)
PUSHSWAP_DEPS = $(PUSHSWAP_SRCS:.c=.d)
-include $(PUSHSWAP_DEPS)

$(PUSHSWAP): $(PUSHSWAP_OBJS)
$(PUSHSWAP_OBJS): $(LIBFT)

# **************************************************************************** #
# checker
# **************************************************************************** #

CHECKER = checker

CHECKER_SRCS = \

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CHECKER_DEPS = $(CHECKER_SRCS:.c=.d)
-include $(CHECKER_DEPS)

# **************************************************************************** #
# main
# **************************************************************************** #

NAME = $(PUSHSWAP)

all bonus:
	$(MAKE) -C $(dir $(LIBFT))
	$(MAKE) $(NAME)

clean:
	$Q$(MAKE) -C $(dir $(LIBFT)) clean
	$Q$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$Q$(RM) $(LIBFT) $(NAME)

re: fclean
	$Q$(MAKE)

.PHONY: all clean fclean re bonus $(dir $(LIBFT))

seq = $(shell seq 100 | sort -R)
test: $(NAME)
	./$(NAME) $(seq)

seq5 := $(shell seq 5 | sort -R)
seq100 := $(shell seq 100 | sort -R)
seq500 := $(shell seq 500 | sort -R)
test2: $(NAME)
	@echo "########################################################################"
	@echo "Error"
	@echo "########################################################################"
	./$(NAME) 3 two 1 | cat -e
	./$(NAME) 3 2 2 1 | cat -e
	./$(NAME) 2147483648 0 | cat -e
	./$(NAME) 0 -2147483649 | cat -e
	./$(NAME) | cat -e
	@echo "########################################################################"
	@echo "already sort 0 "
	@echo "########################################################################"
	./$(NAME) 42 | wc -l
	./$(NAME) 0 1 2 3 | wc -l
	./$(NAME) 0 1 2 3 4 5 6 7 8 9 | wc -l
	@echo "########################################################################"
	@echo "simple (2 or 3)"
	@echo "########################################################################"
	./$(NAME) 0 2 1
	./$(NAME) 1 0 2
	./$(NAME) 1 2 0
	./$(NAME) 2 0 1
	./$(NAME) 2 1 0
	@echo "########################################################################"
	@echo "simple (good : < 8 | bad : > 12)"
	@echo "########################################################################"
	./$(NAME) 1 5 2 4 3 | cut -f 1 | ./checker_linux 1 5 2 4 3
	@./$(NAME) 1 5 2 4 3 | wc -l
	./$(NAME) $(seq5) | cut -f 1 | ./checker_linux $(seq5)
	@./$(NAME) $(seq5) | wc -l
	@echo "########################################################################"
	@echo "middle (5 : < 700, 4 : < 900, 3 : <1100, 2 : < 1300, 1 : 1500)"
	@echo "########################################################################"
	./$(NAME) $(seq100) | cut -f 1 | ./checker_linux $(seq100)
	@./$(NAME) $(seq100) | wc -l
	@echo "########################################################################"
	@echo "advance (5 : < 5500, 4 : < 7000, 3 : <8500, 2 : < 10000, 1 : 11500)"
	@echo "########################################################################"
	@echo "# adcande start... (tail -f seq500.txt)"
#./$(NAME) $(seq500) | nl > seq500.txt
#	tail -1 seq500.txt
	

