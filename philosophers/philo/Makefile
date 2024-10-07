#!/bin/bash

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

NAME = philo

SRCS_DIR = .

SRCS = $(SRCS_DIR)/ph_init.c \
		$(SRCS_DIR)/ph_new_sleep.c \
		$(SRCS_DIR)/ph_print.c \
		$(SRCS_DIR)/ph_monitoring.c \
		$(SRCS_DIR)/ph_parsing.c \
		$(SRCS_DIR)/ph_routine.c \
		$(SRCS_DIR)/ph_free.c \
		$(SRCS_DIR)/ph_mutex.c \
		$(SRCS_DIR)/ph_philo.c \
		$(SRCS_DIR)/ph_time.c \
		$(SRCS_DIR)/main.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %c
		$(CC) $(CFLAGS) -c $^ -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all 

.PHONY: all clean fclean re
