CC=cc
CFLAGS=-Wall -Wextra -Werror 
HEADER=so_long.h
NAME=so_long
SRCS=./main.c ./map_funcs.c ./map_funcs2.c ./utils.c ./player_utils.c ./player_utils2.c ./error_checking/check_errors.c \
	./error_checking/check_errors_utils.c ./error_checking/check_errors_utils2.c ./error_checking/ft_split.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -lXext -lX11 -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -O3

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re