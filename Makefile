NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		= main.c stack.c \
             check_input.c check_input_utils.c \
             stack_utils.c algorithm_utils.c \
             swap_action.c push_action.c rotate_action.c rotate_reverse_action.c \
             small_sort.c radix_sort.c \
             error.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re