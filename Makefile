NAME = so_long

SRC= get_next_line.c get_next_line_utils.c  main.c \
		render1.c render2.c map_check1.c map_check2.c key_handling.c \
		map_read.c ft_atoi.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_printf.c \
		ft_strcmp.c 


CC = cc -g3 #-fsanitize=address

CFLAGS = -Wall -Wextra -Werror

LIBXFLAGS =  -lmlx -lXext -lX11
OBJS = $(SRC:.c=.o)
all : $(NAME)

$(NAME) : $(SRC)
	# make -C ft_printf
	$(CC) $(SRC) $(CFLAGS) $(LIBXFLAGS) -o $(NAME)
clean :
	# make -C fclean
	rm -f $(OBJS)

fclean : clean
	# make -C  fclean
	rm -f $(NAME)

re : fclean all