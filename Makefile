# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2022/09/14 11:17:14 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC = cc
AR = ar
RM = rm -f 

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CPPFLAGS = -I./libft
LDFLAGS = -L./libft -lft

ifdef DEBUG
	CFLAGS += -O0 -g -fsanitize=address,undefined
endif

Q = @
ifdef VERBOSE
	Q =
endif

%.o : %.c
	$(Q)$(COMPILE.c) $(OUTPUT_OPTION) $<

# **************************************************************************** #
# main
# **************************************************************************** #
NAME = push_swap

src_m = \
		push_swap.c

src_b = \
		push_swap.c

SRCS = $(if $(filter bonus, $(MAKECMDGOALS)), $(src_b), $(src_m))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
LIBS = libft/libft.a

all bonus:
	$(Q)$(MAKE) -C $(dir $(LIBS)) $(notdir $(LIBS))
	$(Q)$(MAKE) $(NAME)

$(NAME): $(LIBS) $(OBJS)

clean:
	$(Q)$(MAKE) -C $(dir $(LIBS)) clean
	$(Q)$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(Q)$(RM) $(LIBS) $(NAME)

re: fclean
	$(Q)$(MAKE)

.PHONY: all clean fclean re bonus $(LIBS)

-include $(DEPS)
