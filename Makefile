# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 00:09:09 by ksaetern          #+#    #+#              #
#    Updated: 2017/04/30 22:46:34 by ksaetern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

INC_PATH	= ./libft/include/
LIB_PATH	= ./libft/
MLX_PATH	= ./minilibx_macos/

CC 			= gcc
AR 			= AR

CCFLAGS 	= -Wall -Wextra -Werror
INC 		= ./fdf.h

LIBFT 		= ./libft
LIBFT_A 	= libft.a
LIBFT_ALL 	= $(LIBFT)/$(LIBFT_A) 

MLX_CAP 	= ./minilibx_macos/
MLX_A 		= libmlx.a
MLX_MAC 	= $(MLX_CAP)/$(MLX_A)
MLX_C_ALL 	= $(MLX_MAC) -framework OpenGL -framework Appkit

LIB_M_ALL 	= $(LIBFT_ALL) $(MLX_C_ALL)
SRCS	=			main.c \
	   			store.c \
				enviroment.c \
				drawlogic.c \
				slopedraw.c \
				rotate.c \
				color.c \
				parse.c \
				translate.c \

INCLUDE 	=  -I fdf.h -L $(LIB_PATH) -lft -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
OBJ		=	${SRCS:.c=.o}

all: $(NAME)

#recompiling the libraries is turned off now for speed
$(NAME): $(OBJ)
		#@make -C libft
		@echo "\033[32mCompiled libft\033[0m"
		#@make -C $(MLX_CAP)
		@echo "\033[32mCompiled mlx_macros\033[0m"
		@$(CC) $(CCFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

		@echo "\033[36;1m                           \033[0m";
		@echo "\033[36;1m        ,--,               \033[0m";
		@echo "\033[36;1m      ,--.'|      ,----,   \033[0m";
		@echo "\033[36;1m   ,--,  | :    .'   .' \  \033[0m";
		@echo "\033[36;1m,---.'|  : '  ,----,'    | \033[0m";
		@echo "\033[36;1m;   : |  | ;  |    :  .  ; \033[0m";
		@echo "\033[36;1m|   | :  : |  ;    |.'  /  \033[0m";
		@echo "\033[36;1m:   : |.'  |  \`----'/  ;   \033[0m";
		@echo "\033[36;1m|   ' '  ; :    /  ;  /    \033[0m";
		@echo "\033[36;1m\   \  .'. |   ;  /  /-,   \033[0m";
		@echo "\033[36;1m \`---\`:  : |  .  /  /  ;   \033[0m";
		@echo "\033[36;1m      '  ; | /__;  '   :   \033[0m";
		@echo "\033[36;1m      |  : ;|   :    .'    \033[0m";
		@echo "\033[36;1m      '  ,/ ;   | .'       \033[0m";
		@echo "\033[36;1m      '--'  \`---'         \033[0m";
		@echo "\033[36;1m                           \033[0m";

		@echo "\033[34;1mFDF created\n\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	#@make -C libft clean
	#@make -C $(MLX_CAP) clean
	@echo "\033[31;1m libs cleaned\033[0m"

fclean: clean
	#@make -C libft fclean
	#@make -C $(MLX_CAP) clean
	@rm -f $(NAME)
	@echo "\033[31;1m$(NAME) and libs fcleaned\033[0m"

re: fclean all

.PHONY: clean