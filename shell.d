#include "shell"
/**
*int shell_cd: this fuction is a specifier needed for shell.
Return: return Null
*/

int shell_cd(char **args, char *shell_name, int line_num)
{
    (void)args;
    (void)shell_name;
    (void)line_num;

    /* Actual CD implementation goes here */
    char *dir = args[1] ? args[1] : getenv("HOME");
    if (chdir(dir) == -1) {
        fprintf(stderr, "%s: %d: cd: can't cd to %s\n",
               shell_name, line_num, dir);
        return (1);
    }
    return (0);
}
