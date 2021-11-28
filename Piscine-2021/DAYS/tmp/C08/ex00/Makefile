CC=gcc
FLAGS=-Wall -Wextra -Werror
HEADER=-I includes
LIB=libft.a
SRC= $(addprefix srcs/, $(addsuffix .c, ft_putchar ft_putstr ft_strcmp ft_strlen ft_swap))
OBJ= $(notdir $(SRC:.c=.o))

all: $(LIB)

.PHONY: all clean fclean re

$(LIB): $(OBJ)
	ar rcs $@ $?

$(OBJ): $(SRC) 
	$(CC) $(FLAGS) $(HEADER) -c $?

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(LIB)
re: fclean all
