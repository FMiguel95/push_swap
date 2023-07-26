NAME = push_swap
NAME_BONUS = checker

SRC_LIST = push_swap.c parsing.c basic_operations.c swap.c push.c rotate.c \
		   reverse_rotate.c push_swap_utils.c sorting.c list_utils.c \
		   sort_utils1.c sort_utils2.c sort_utils3.c
SRC_LIST_BONUS = checker_bonus.c parsing_bonus.c list_utils_bonus.c \
				 basic_operations_bonus.c checker_utils_bonus.c

SRC_DIR = src/
SRC_DIR_BONUS = src_bonus/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(SRC_LIST_BONUS))

BIN_DIR = bin/
BIN_DIR_BONUS = bin_bonus/
BIN = $(addprefix $(BIN_DIR), $(SRC_LIST:.c=.o))
BIN_BONUS = $(addprefix $(BIN_DIR_BONUS), $(SRC_LIST_BONUS:.c=.o))

LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(BIN) $(LIBFT)
	$(CC) $(CFLAGS) $(BIN) -L$(LIBFT_DIR) -lft -o $(NAME)

$(BIN_DIR)%.o: $(SRC_DIR)%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir $(BIN_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BIN_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(BIN_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

$(BIN_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(BIN_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR_BONUS):
	mkdir $(BIN_DIR_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(BIN_DIR)
	$(RM) $(BIN_DIR_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

norm:
	@norminette $(SRC)
	@norminette $(SRC_BONUS)
	@norminette -R CheckForbiddenSourceHeader include/*.h
