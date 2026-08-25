NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -Ilibft/includes

LIBFT_DIR   = Libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = src/main.c \
              src/parsing/parsing.c \
              src/parsing/check_errors.c \
              src/parsing/free_utils.c \
              src/operations/push.c \
              src/operations/swap.c \
              src/operations/rotate.c \
              src/operations/reverse_rotate.c \
              src/utils/stack_utils.c \
              src/utils/indexation.c \
              src/utils/disorder.c \
              src/algorithms/sort_small.c \
              src/algorithms/strategy_simple.c \
              src/algorithms/strategy_medium.c \
              src/algorithms/strategy_complex.c \
              src/algorithms/strategy_adaptive.c

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

# Compila libft llamando a su propio Makefile
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compila el ejecutable enlazando libft.a
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re