# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 02:22:44 by minjungk          #+#    #+#              #
#    Updated: 2024/06/17 02:46:59 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

.ONESHELL:

# **************************************************************************** #
# object
# **************************************************************************** #

GET_NEXT_LINE	= get_next_line/get_next_line.o

FT_PRINTF		= ft_printf/libftprintf.a

$(FT_PRINTF):
	@if [ ! -z $(shell find ./ft_printf -empty) ]; then
		git submodule update --init --recursive
	fi
	$(MAKE) -C $(@D)

# **************************************************************************** #
# libexternal.a
# **************************************************************************** #

NAME = libexternal.a

$(NAME): $(FT_PRINTF) $(GET_NEXT_LINE)
	cp $(FT_PRINTF) $@
	ar rsc $@ $(GET_NEXT_LINE)

# **************************************************************************** #
# main
# **************************************************************************** #

all: $(NAME)

clean:
	$(MAKE) -C $(dir $(FT_PRINTF)) $@
	$(RM) $(GET_NEXT_LINE)

fclean: clean
	$(MAKE) -C $(dir $(FT_PRINTF)) $@
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
