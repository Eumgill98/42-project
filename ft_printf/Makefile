CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar

ARFLAGS = crs

NAME = libftprintf.a

SRCS_DIR = .

SRCS =  ${SRCS_DIR}/ft_printf.c \
	${SRCS_DIR}/ft_printf_hex.c \
	${SRCS_DIR}/ft_printf_num.c \
	${SRCS_DIR}/ft_printf_str.c \
	${SRCS_DIR}/ft_printf_utils.c

OBJS  = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJECT)
	$(AR) $(ARFLAGS) $@ $^

%.o: %c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
