#!/bin/bash

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = -L./mlx -lmlx_Linux -lX11 -lXext -L./libft -lft

INC = -Imlx -Ilibft -Iinclude

RM = rm -f

NAME = so_long

SRCS_DIR = ./src

SRCS =  $(SRCS_DIR)/game_movement.c \
	$(SRCS_DIR)/game_error.c \
	$(SRCS_DIR)/game_free.c \
	$(SRCS_DIR)/game_setting.c \
	$(SRCS_DIR)/get_next_line.c \
	$(SRCS_DIR)/get_next_line_utils.c \
	$(SRCS_DIR)/map_check.c \
	$(SRCS_DIR)/map_check_path.c \
	$(SRCS_DIR)/map_check_utils.c \
	$(SRCS_DIR)/map_draw.c \
	$(SRCS_DIR)/map_load.c \
	$(SRCS_DIR)/main.c \

OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	  $(CC) $(CFLAGS) -o $@ $^ $(LIB)

.c.o:
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
