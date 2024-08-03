CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft

INC = -I./include -I./libft

RM = rm -f

NAME = pipex

SRCS_DIR = ./src

SRCS = $(SRCS_DIR)/pipex.c \
	$(SRCS_DIR)/pi_child.c \
	$(SRCS_DIR)/pi_command.c \
	$(SRCS_DIR)/pi_env_utils.c \
	$(SRCS_DIR)/pi_execute.c \
	$(SRCS_DIR)/pi_exit_utils.c \
	$(SRCS_DIR)/pi_free_utils.c \
	$(SRCS_DIR)/pi_init_utils.c

LIB_NAME = libft.a

LIB_DIR  = ./libft

OBJS = ${SRCS:.c=.o}

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):
	make -C $(LIB_DIR)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

.c.o:
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
