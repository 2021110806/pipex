CC = cc
CFLAGS = -g
NAME = pipex
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)

.PHONY : clean fclean re all bonus

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c -o $@ $?