NAME = ft_advanced_do-op
SRC = ft_opp.c main.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) $(SRC)

clean:
	/bin/rm -f ft_opp.o main.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
