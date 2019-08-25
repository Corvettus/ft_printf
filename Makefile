NAME = libftprintf.a

SRC = ft_printf.c \
		ft_print_c.c \
		ft_print_s.c \
		ft_print_p.c \
		ft_print_d.c \
		ft_print_o.c \
		ft_print_u.c \
		ft_print_X.c \
		ft_print_f.c \
		ft_print_pc.c \
		main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc -g $(SRC) -I libft -L libft/ -lft -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all