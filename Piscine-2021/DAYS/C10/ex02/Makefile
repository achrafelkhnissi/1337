CC=gcc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I includes
SRCS=$(wildcard srcs/*)
OBJS=$(notdir $(SRCS:.c=.o))
BIN=ft_tail

.PHONY: all clean fclean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(INCLUDES) $(FLAGS) -g $? -o $@

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -g -c $(SRCS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(BIN)
