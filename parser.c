#include "shell.h"

/**
 * parse_input - Splits a command string into parts
 * @line: Input string (e.g., "ls -l")
 * Return: Array of strings (e.g., ["ls", "-l", NULL])
 */
char **parse_input(char *line)
{
    int buffer_size = MAX_ARGS;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;
    int i = 0;

    if (!tokens) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Split by spaces/tabs/newlines
    token = strtok(line, TOKEN_DELIM);
    while (token) {
        tokens[i++] = token;
        
        // Resize if needed
        if (i >= buffer_size) {
            buffer_size += MAX_ARGS;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
        }
        
        token = strtok(NULL, TOKEN_DELIM);
    }
    
    tokens[i] = NULL; // Mark end
    return tokens;
}
