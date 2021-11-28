CC = gcc
SRC = *.c
OBJ = *.o

bin: $(OBJ)
	$(CC) $^ -o $@
	rm $^
$(OBJ): $(SRC)
	$(CC) -c $^
