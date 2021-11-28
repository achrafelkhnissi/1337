CC=gcc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I includes
SRCS=$(wildcard srcs/*)
OBJS=$(notdir $(SRCS:.c=.o))
BIN=ft_last

.PHONY: all clean fclean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(INCLUDES) $(FLAGS) $? -o $@

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(BIN)
