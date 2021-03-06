# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/06 11:51:28 by mtrazzi           #+#    #+#              #
#    Updated: 2017/08/12 15:45:44 by mtrazzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in	

CC				=	clang

FLAGS			=	-Wall -Wextra -Werror

#--------------------------------------------------------------------------------
# PATHS
#--------------------------------------------------------------------------------

SRC_PATH		=	./src/

INC_PATH		=	./includes/

OBJ_PATH		=	./obj/

LIB_PATH		=	./libft/

#--------------------------------------------------------------------------------
# SRC
#--------------------------------------------------------------------------------

SRC_FILES		=	main.c				\
					ft_parse_stdin.c	\
					ft_lst_utils.c		\
					ft_error.c			\
					ft_parse.c			\
					ft_parse_utils.c	\
					ft_dfs_utils.c		\
					ft_find_path.c		\
					ft_process_paths.c	\
					ft_clean.c			

SRC				=	$(addprefix $(SRC_PATH), $(SRC_FILES))

#--------------------------------------------------------------------------------
# OBJ
#--------------------------------------------------------------------------------

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

#--------------------------------------------------------------------------------
# INC
#--------------------------------------------------------------------------------

INC				=	$(addprefix -I, $(INC_PATH))

HEADER_FILES	=	libft.h		\
					lem_in.h

HEADERS			=	$(addprefix $(INC_PATH), $(HEADERS_FILES))

#--------------------------------------------------------------------------------
# DEPENDENCIES
#--------------------------------------------------------------------------------

LIB_FILE		=	libft.a

LIB				=	$(addprefix $(LIB_PATH), $(LIB_FILE))

#--------------------------------------------------------------------------------
# RULES
#--------------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@echo "Building $(NAME)..."
	$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $@
	@echo "\033[3;94m!$(NAME) built!\033[0m"

$(LIB):
	@$(MAKE) -C $(LIB_PATH) $(LIB_FILE)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS) $(LIB)
	@mkdir -p obj
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LIB_PATH) fclean
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

linux: $(LIB)
	@echo "Building $(NAME)..."
	$(CC) $(CFLAGS) $(SRC) $(INC) $(LIB) -o $(NAME)
	@echo "\033[3;94m!$(NAME) built!\033[0m"

norme: fclean
	norminette $(SRC)
	norminette $(LIB_PATH)
	norminette $(INC_PATH)	

.PHONY: all, clean, fclean, re, norme
