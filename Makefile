CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = $(wildcard *.c)
OBJ = $(SRC:.c = .o)
TARGET = hsh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
