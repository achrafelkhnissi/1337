CC=gcc
AR=ar crs
RM=rm -rf
FLAG=-Wall -Wextra -Werror
HEADER=-I includes
SRC=$(addprefix srcs/, $(addsuffix .c, ft_putchar ft_swap ft_putstr ft_strlen ft_strcmp))
OBJ=$(notdir $(SRC:.c=.o))
LIB=libft.a

.PHONY: all clean fclean re

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) $@ $?
	$(RM) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(HEADER) $(FLAG) -c $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

re: fclean all
