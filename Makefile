NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
LIBFT = includes/libft/
LIBFT_A = includes/libft/libft.a

SRCS = push_swap.c \
		linked_list_utils.c \
		linked_list_delete.c \
		linked_list_insert.c \
		parse_numbers.c \
		fill_stack.c \
		free.c

OBJ_DIR = objs/

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -s -C $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -rf $(OBJ_dir)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re