NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
LIBFT = includes/libft/
LIBFT_A = includes/libft/libft.a
PRINTF = includes/printf/
PRINTF_A = includes/printf/libftprintf.a

SRCS_SHARED = list_functions/linked_list_utils.c \
			list_functions/linked_list_insert.c \
			parser.c \
			error.c \
			fill_stack.c \
			free.c \
			operations/swap.c \
			operations/push.c \
			operations/rotate.c \
			operations/reverse_rotate.c \
			algorithm/three_elem_sort.c \
			algorithm/four_elem_sort.c \
			algorithm/five_elem_sort.c \
			algorithm/turk.c \
			algorithm/turk_utils.c \
			algorithm/sort.c \
			algorithm/cheapest_move.c \
			algorithm/find_target.c \
			algorithm/rotation_cost.c \
			lis_alg/create_idx_arr.c \
			lis_alg/create_lis_arr.c \
			lis_alg/assign_lis.c \

SRCS = push_swap.c $(SRCS_SHARED)


SRCS_BONUS = bonus/checker.c \
			bonus/get_next_line_utils.c \
			bonus/get_next_line.c \
			$(SRCS_SHARED)

OBJ_DIR = objs/

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(SRCS_BONUS:.c=.o))

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_A) $(PRINTF_A) -o $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -s -C $(LIBFT)

$(PRINTF_A):
	$(MAKE) -s -C $(PRINTF)

norm:
	norminette push_swap.h $(SRCS)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re