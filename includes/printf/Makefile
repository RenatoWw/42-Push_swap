NAME = libftprintf.a
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = ft_printf.c \
	ft_print_ch.c \
	ft_print_hex.c \
	ft_print_nbr.c \
	ft_print_str.c \
	ft_print_unbr.c \
	ft_print_ptr.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	cc -c -Wall -Werror -Wextra -I. $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) all
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re