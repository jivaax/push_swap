NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

SRCS = $(addsuffix .c, \
	push_swap parsing parsing_utils stack_utils rotations swaps \
	pushes rev_rot sort_small sort_four_five sort_algorithm)
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re