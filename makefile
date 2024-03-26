# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 12:02:53 by dpaluszk          #+#    #+#              #
#    Updated: 2024/03/25 19:00:35 by dpaluszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

all: ${NAME}

SRC = ft_printf.c

OBJECTS = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = cc
