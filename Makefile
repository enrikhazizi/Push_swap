CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -Ilibft

NAME = push_swap

SRC = \
	algorithmic.c benchmark.c chunk_sort_utils.c chunk_sort.c greedy_chunk_sort.c \
	greedy_chunk_strategy.c greedy_chunk_utils.c ops_a.c ops_b.c ops_mix.c parser_utils.c \
	push_swap_utils_2.c push_swap_utils_3.c push_swap_utils.c push_swap.c

LIBFT_DIR = libft
LIBFT_SRC = \
	$(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_bzero.c $(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_isalnum.c $(LIBFT_DIR)/ft_isalpha.c $(LIBFT_DIR)/ft_isascii.c \
	$(LIBFT_DIR)/ft_isdigit.c $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_itoa.c \
	$(LIBFT_DIR)/ft_memchr.c $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_memcpy.c \
	$(LIBFT_DIR)/ft_memmove.c $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_putchar_fd.c \
	$(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr_fd.c $(LIBFT_DIR)/ft_putstr_fd.c \
	$(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_striteri.c $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strlcat.c \
	$(LIBFT_DIR)/ft_strlcpy.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strmapi.c \
	$(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_strnstr.c $(LIBFT_DIR)/ft_strrchr.c \
	$(LIBFT_DIR)/ft_strtrim.c $(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/ft_tolower.c \
	$(LIBFT_DIR)/ft_toupper.c $(LIBFT_DIR)/ft_lstadd_back.c $(LIBFT_DIR)/ft_lstadd_front.c \
	$(LIBFT_DIR)/ft_lstclear.c $(LIBFT_DIR)/ft_lstdelone.c $(LIBFT_DIR)/ft_lstiter.c \
	$(LIBFT_DIR)/ft_lstlast.c $(LIBFT_DIR)/ft_lstmap.c $(LIBFT_DIR)/ft_lstnew.c \
	$(LIBFT_DIR)/ft_lstsize.c $(LIBFT_DIR)/ft_printf.c $(LIBFT_DIR)/ft_printf_utils.c \
	$(LIBFT_DIR)/ft_putchar_pf.c $(LIBFT_DIR)/ft_putnbr_pf.c $(LIBFT_DIR)/ft_putstr_pf.c

OBJ = $(SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
