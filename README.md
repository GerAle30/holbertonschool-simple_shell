# Simple Shell

## Description
A basic UNIX command-line interpreter (shell) that executes commands from the standard input or from a file. This shell supports essential functionality including command execution, environment variable display, and basic built-in commands.

## Features
- Interactive and non-interactive modes
- Command execution using PATH resolution
- Built-in commands:
  - `exit`: Exit the shell with a status code
  - `env`: Print the current environment variables
- Error handling for commands not found

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage
### Interactive Mode
```
$ ./hsh
($) /bin/ls
file1 file2 file3
($) pwd
/home/user/shell
($) exit
$
```

### Non-Interactive Mode
```
$ echo "/bin/ls" | ./hsh
file1 file2 file3
$
```

## Files
- **main.c**: Entry point for the shell program
- **builtins.c**: Contains built-in command implementations (env, exit)
- **execute_command.c**: Command execution and PATH resolution
- **parse_line.c**: Line parsing and token handling
- **_prompts.c**: Shell prompt display
- **shell.h**: Header file with function prototypes

## Built-in Commands
- `exit`: Exit the shell with optional status code
- `env`: Print the current environment variables

## Memory Management
The shell properly handles memory allocation and deallocation to prevent memory leaks.

## Function Descriptions

### main.c
- `main()`: The entry point that initializes the shell and starts the command loop

### builtins.c
- `print_environment()`: Prints the current environment variables
- `handle_command()`: Processes built-in commands or passes to executor

### execute_command.c
- `get_path_env()`: Retrieves the PATH environment variable
- `search_in_path()`: Searches for commands in PATH directories
- `resolve_path()`: Resolves a command to its full path
- `resolve_and_execute()`: Resolves path and executes command
- `execute_command()`: Main command execution function

### parse_line.c
- `read_line()`: Reads one line from standard input
- `trim_newline()`: Removes trailing newline character
- `is_blank()`: Checks if a string is empty or only whitespace
- `split_line()`: Splits a line into tokens
- `free_args()`: Frees the argument array

### _prompts.c
- `print_prompt()`: Displays the shell prompt in interactive mode

## Return Values
- Commands return their exit status
- Command not found returns 127
- Shell built-in commands return 0 on success
