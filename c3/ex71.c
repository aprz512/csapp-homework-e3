/*
Write a function good_echo that reads a line from standard input and writes it to
standard output. Your implementation should work for an input line of arbitrary
length. You may use the library function fgets, but you must make sure your
function works correctly even when the input line requires more space than you
have allocated for your buffer. Your code should also check for error conditions
and return when one is encountered. Refer to the definitions of the standard I/O
functions for documentation [45, 61].
*/

#include <stdio.h>

#define BUFFER_SIZE 6

int good_echo()
{

    char buffer[BUFFER_SIZE];

    while (1)
    {
        char *input = fgets(buffer, BUFFER_SIZE, stdin);
        if (input == NULL)
        {
            return -1;
        }
        else
        {
            fputs(buffer, stdout);
            // printf("buffer = %s", buffer);
        }
    }

    return 0;
}

int main()
{
    good_echo();
    return 0;
}