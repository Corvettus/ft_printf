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
		ft_toa.c \
		ft_convert_108.c \
		ft_start_double.c \
		ft_check.c \
		ft_ntlstn.c \
		ft_strjoin_char.c \
		ft_get_d.c \
		ft_get_f.c \
		ft_get_c.c \
		ft_get_u.c \
		ft_get_x.c \
		test.c \
		main.c \

FLS = -Wall -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(FLS) $(SRC) -I libft
	@cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all
