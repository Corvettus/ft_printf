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
		ft_controller.c \
<<<<<<< HEAD
		ft_toa.c \
=======
		ft_convert_108.c \
>>>>>>> d69bc320921e1797cd9b8ff457388dc7fc99f539
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