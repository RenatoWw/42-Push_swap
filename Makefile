NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
LIBFT = includes/libft/
LIBFT_A = includes/libft/libft.a
PRINTF = includes/printf/
PRINTF_A = includes/printf/libftprintf.a

SRCS = push_swap.c \
		list_functions/linked_list_utils.c \
		list_functions/linked_list_delete.c \
		list_functions/linked_list_insert.c \
		parser.c \
		fill_stack.c \
		free.c \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/reverse_rotate.c \
		algorithm/three_elem_sort.c \

OBJ_DIR = objs/

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -s -C $(LIBFT)

$(PRINTF_A):
	$(MAKE) -s -C $(PRINTF)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	rm -rf $(OBJ_dir)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re