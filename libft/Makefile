NAME = libft.a

SRC =	array.c conv.c ft_printf_fd.c ft_printf.c get_next_line.c lst.c \
		lst2.c mem.c mem2.c put_fd.c put.c strings.c strings2.c strings3.c \
		strings4.c xtra.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra -g $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "minilibft compiled"

clean:
	@/bin/rm -f $(OBJ)
	@echo "objs ded"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f minilibft.h.gch
	@echo "lib ded"

re: fclean all
