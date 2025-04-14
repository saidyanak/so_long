# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syanak <syanak@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:12:09 by syanak            #+#    #+#              #
#    Updated: 2024/11/06 17:49:57 by syanak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c		\
	ft_bzero.c		\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_memmove.c	\
	ft_memcpy.c		\
	ft_memset.c		\
	ft_strrchr.c	\
	ft_itoa.c		\
	ft_strchr.c		\
	ft_strlcpy.c	\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_strdup.c		\
	ft_calloc.c		\
	ft_putnbr_fd.c	\
	ft_strlen.c		\
	ft_strncmp.c	\
	ft_strtrim.c	\
	ft_strnstr.c	\
	ft_substr.c		\
	ft_strjoin.c 	\
	ft_split.c		\
	ft_tolower.c	\
	ft_toupper.c	\
	ft_strlcat.c	\
	ft_striteri.c	\
	ft_strmapi.c

BSOURCES = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BOBJECTS = $(BSOURCES:.c=.o)

OBJECTS = ${SRC:.c=.o}
ifneq ($(filter bonus,$(MAKECMDGOALS)),)
	SRC         +=   $(BSOURCES)
endif

all:	${NAME}

bonus: ${NAME}

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}


clean :
	rm -rf ${OBJECTS}
	rm -rf ${BOBJECTS}

fclean : clean
	rm -rf ${NAME}

re : fclean ${NAME}

.PHONY: all clean fclean re
