# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 13:34:33 by Vsavilov          #+#    #+#              #
#    Updated: 2022/01/19 12:14:37 by Vsavilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################
###   Program/s name/s   ###
############################

NAME = Pipex

LIBFT_NAME = libft.a

##############################
###   Compiler and flags   ###
##############################

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT)/inc

CFLAGS += -O3

CFLAGS += -fsanitize=address -g3

#################
###   Paths   ###
#################

SRC_PATH = src

OBJ_PATH = obj

INC_PATH = inc

LIBFT_PATH = libft

########################
###   Source items   ###
########################

SRCS_NAME = main.c \
	    parse.c \
	    utils.c \
	    error_msg.c \
	    env_compare.c \
	    child_process.c \
	    init_structs.c

#####################
###   Make rule   ###
#####################

MAKE = make

##########################
###   Create objects   ###
##########################

OBJS_NAME = $(SRCS_NAME:%.c=%.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

#######################
###   Create libs   ###
#######################

LIBFT =	$(LIBFT_PATH)

#################################
###   Rules can be executed   ###
#################################

all: $(NAME)

#######################
###   Objects dir   ###
#######################

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(LIBS_DIR):
	mkdir -p $(LIBS-DIR) 2> /dev/null

#########################
###   Compile libs   ###
#########################

$(LIBFT_NAME):
	$(MAKE) all -sC $(LIBFT)
	cp -r $(addprefix $(LIBFT)/, $(LIBFT_NAME)) $(LIBFT_NAME)

#####################
###   Compile.o   ###
#####################

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_NAME)

#######################
###   Other rules   ###
#######################

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT)
	rm -rf $(NAME)
	rm $(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
