# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 20:07:19 by minjungk          #+#    #+#              #
#    Updated: 2022/09/25 19:51:39 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC = cc
AR = ar
RM = rm -f

ARFLAGS = rsc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

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

NAME = libft.a

SRCS := \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_utoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c \
	ft_make_token.c \
	ft_parse_token.c \
	ft_printf.c \

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

all bonus: $(NAME)

$(NAME): $(OBJS)
	$Q$(AR) $(ARFLAGS) $@ $^

clean:
	$Q$(RM) $(OBJS) $(DEPS)

fclean: clean
	$Q$(RM) $(NAME)

re: fclean
	$Q$(MAKE)

.PHONY: all clean fclean re bonus
