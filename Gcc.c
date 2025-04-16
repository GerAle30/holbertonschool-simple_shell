CC = gcc
CFLAGS = -Wall - Wextra - pedantic - Werror

SRC = main.c parser.c execute.c builtins.c path.c
OBJ = $(SRC : .c = .o)
EXEC = hsh

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $ ^ -o $@

clean :
	rm - f $(OBJ) $(EXEC)

re : clean all
