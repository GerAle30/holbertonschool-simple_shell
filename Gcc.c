CC := gcc
CFLAGS := -Wall -Wextra -pedantic -Werror -std=gnu89
SRC := $(wildcard *.c)
OBJ := $(SRC:.c = .o)
TARGET := hsh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
