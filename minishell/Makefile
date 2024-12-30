CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB_DIR = ./libft

LIB = -L$(LIB_DIR) -lft -lreadline

INCLUDE_DIR = include

SRCS_DIR = src

MN_ENVIRONMENT = mn_environment

MN_ERROR = mn_error

MN_TOKENIZER = mn_tokenizer

MN_UTILS = mn_utils

MN_BUILT_IN = mn_built_in

MN_EXEC = mn_exec

INC = -I$(INCLUDE_DIR) -I$(LIB_DIR)

NAME = minishell

SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_env_utils.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_insert_envs.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_insert_exports.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_insert_utils.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_update_envs.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_update_exports.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_make_env_lst.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_make_environment.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_new_env.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_destroy_env.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_destroy_env_lst.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_destroy_environment.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_print_env_lst.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_check_in_env.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_change_env_value.c \
		$(SRCS_DIR)/$(MN_ENVIRONMENT)/mn_check_plus.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_print_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_malloc_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_parser_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_qutoe_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_assignment_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_many_arg_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_exit_numeric_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_pipes_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_forks_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_not_command_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_is_directory_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_print_re_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_open_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_cant_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_out_error.c \
		$(SRCS_DIR)/$(MN_ERROR)/mn_dup2_error.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_append_token.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_arglen.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_change_env.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_change_env_utils.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_check_quote_closed.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_check_token_s_type.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_check_token_type.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_check_token_valid.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_check_built_in_type.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_del_arg.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_del_redirect.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_del_process.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_destroy_args.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_destroy_redirects.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_destroy_token_lst.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_destroy_process.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_destroy_pipes.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_init_process.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_init_pipes.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_new_arg.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_new_token.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_new_redirect.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_new_process.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_new_pipes.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_pre_env_token.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_pre_sq_token.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_pre_str_token.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_split_token.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_tokenizer.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_processer.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_processlen.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_setting_env.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_setting_create.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_setting_init.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_setting_free.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_setting_token_init.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_setting_exit.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_set_child_signal.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_set_child_heredoc_signal.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_free_heredoc_child.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_allocate_g_status.c \
		$(SRCS_DIR)/$(MN_TOKENIZER)/mn_heredoc.c \
		$(SRCS_DIR)/$(MN_UTILS)/mn_signal.c \
		$(SRCS_DIR)/$(MN_UTILS)/mn_parsing.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_built_in_utils.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_cd.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_echo.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_env.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_exit.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_export.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_pwd.c \
		$(SRCS_DIR)/$(MN_BUILT_IN)/mn_unset.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_do_built_in.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_exec.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_execve.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_execve_utils.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_multiple_process.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_one_process.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_redirect_append.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_redirect_heredoc.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_redirect_in.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_redirect_out.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_redirect.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_redirect_error_code.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_pipe_utils.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_set_ignore_parent_signal.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_free_split_path.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_close_origin_fd.c \
		$(SRCS_DIR)/$(MN_EXEC)/mn_wait_all_child.c

LIB_NAME = libft.a

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
