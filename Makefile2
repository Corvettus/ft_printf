NAME = libftprintf.a

SRCS =  ft_printf.c \
        ft_print_c.c \
        ft_print_s.c \
        ft_print_p.c \
        ft_print_d.c \
        ft_print_o.c \
        ft_print_u.c \
        ft_print_X.c \
        ft_print_f.c \
        main.c
OBJ = $(SRCS:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): %.o : %.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all