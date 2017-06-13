# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/22 11:26:06 by ksaetern          #+#    #+#              #
#    Updated: 2017/01/24 18:47:42 by ksaetern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

INC =	libft.h
SRC_PATH = ./src/
INC_PATH = ./include/

FLAGS =	gcc -c -Wall -Wextra -Werror

SRCS =	ft_strcmp.c ft_atoi.c ft_isdigit.c ft_isalpha.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_putchar.c ft_putstr.c ft_putendl.c \
		ft_putendl.c ft_putnbr.c ft_bzero.c ft_strclr.c ft_memdel.c \
		ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_strdel.c ft_striter.c ft_striteri.c ft_toupper.c ft_tolower.c \
		ft_strncmp.c ft_memcmp.c ft_strequ.c ft_strnequ.c ft_strcpy.c \
		ft_strncpy.c ft_strstr.c ft_itoa.c ft_strcat.c ft_strdup.c ft_strchr.c \
		ft_strrchr.c ft_strncat.c ft_strnew.c ft_strnstr.c ft_strtrim.c \
		ft_strjoin.c ft_strsub.c ft_strmap.c ft_strmapi.c ft_strsplit.c \
		ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		ft_memalloc.c ft_strlcat.c ft_strlen.c ft_int_len.c ft_wspace_check.c \
		ft_until.c ft_wordsplit.c ft_strrev.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_get_next_line.c \

OBJS =	ft_strcmp.o ft_atoi.o ft_isdigit.o ft_isalpha.o ft_isalnum.o \
		ft_isascii.o ft_isprint.o ft_putchar.o ft_putstr.o ft_putendl.o \
		ft_putendl.o ft_putnbr.o ft_bzero.o ft_strclr.o ft_memdel.o \
		ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_putendl_fd.o \
		ft_strdel.o ft_striter.o ft_striteri.o ft_toupper.o ft_tolower.o \
		ft_strncmp.o ft_memcmp.o ft_strequ.o ft_strnequ.o ft_strcpy.o \
		ft_strncpy.o ft_strstr.o ft_itoa.o ft_strcat.o ft_strdup.o ft_strchr.o \
		ft_strrchr.o ft_strncat.o ft_strnew.o ft_strnstr.o ft_strtrim.o \
		ft_strjoin.o ft_strsub.o ft_strmap.o ft_strmapi.o ft_strsplit.o \
		ft_memset.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o \
		ft_memalloc.o ft_strlcat.o ft_strlen.o ft_int_len.o ft_wspace_check.o \
		ft_until.o ft_wordsplit.o ft_strrev.o ft_lstnew.o ft_lstdelone.o \
		ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_get_next_line.o \

SRC = $(addprefix $(SRC_PATH), $(SRCS))
INC = $(addprefix -I,$(INC_PATH))

all:	$(NAME)

$(NAME):
		@$(FLAGS) $(SRC) $(INC)
		@ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean flcean re
