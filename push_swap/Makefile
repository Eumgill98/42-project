CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft

INC = -I./include -Ilibft

RM = rm -f

NAME = push_swap

STACK_SRCS_DIR = ./src/stack

SRCS_DIR = ./src

SRCS = $(SRCS_DIR)/ft_atoil.c \
	$(SRCS_DIR)/ps_encoding.c \
	$(SRCS_DIR)/ps_exit.c \
	$(SRCS_DIR)/ps_free.c \
	$(SRCS_DIR)/ps_functions.c \
	$(SRCS_DIR)/ps_init_stacks.c \
	$(SRCS_DIR)/ps_input.c \
	$(SRCS_DIR)/ps_input_utils.c \
	$(SRCS_DIR)/ps_make_idx.c \
	$(SRCS_DIR)/ps_printstr.c \
	$(SRCS_DIR)/ps_sort.c \
	$(SRCS_DIR)/ps_sort_big.c \
	$(SRCS_DIR)/ps_sort_check.c \
	$(SRCS_DIR)/ps_sort_small.c \
	$(SRCS_DIR)/ps_sort_utils.c \
	$(SRCS_DIR)/push_swap.c \
	$(STACK_SRCS_DIR)/ft_dlstadd_back.c \
	$(STACK_SRCS_DIR)/ft_dlstadd_front.c \
	$(STACK_SRCS_DIR)/ft_dlstdel_one.c \
	$(STACK_SRCS_DIR)/ft_dlstnew.c \
	$(STACK_SRCS_DIR)/ft_dlstpop_all.c \
	$(STACK_SRCS_DIR)/ft_dlstpop_back.c \
	$(STACK_SRCS_DIR)/ft_dlstpop_front.c \
	$(STACK_SRCS_DIR)/ft_dlstswap.c \
	$(STACK_SRCS_DIR)/ft_find_idx.c \
	$(STACK_SRCS_DIR)/ft_push.c \
	$(STACK_SRCS_DIR)/ft_rotate.c \
	$(STACK_SRCS_DIR)/ft_rrotate.c \
	$(STACK_SRCS_DIR)/ft_stackappend.c \
	$(STACK_SRCS_DIR)/ft_stackcopy.c \
	$(STACK_SRCS_DIR)/ft_stackfree.c \
	$(STACK_SRCS_DIR)/ft_stackinit.c \
	$(STACK_SRCS_DIR)/ft_stacklen.c \
	$(STACK_SRCS_DIR)/ft_stackmax.c \
	$(STACK_SRCS_DIR)/ft_stackmin.c \
	$(STACK_SRCS_DIR)/ft_swap.c \

LIB_NAME = libft.a

LIB_DIR = ./libft

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
