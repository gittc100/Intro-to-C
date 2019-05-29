#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int len = strlen(y) - 1;
    while (*y != '\0')
    {
        *x = *y;
        x++;
        y++;
    }
    *x = '\0';
    x = x - len - 1;
    printf("%s", x);
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    char x = c;
    printf("c: %d\n", c);
    printf("x: %c\n", x);
    while (*str != '\0')
    {
        printf("*str: %c\n", *str);
        if (*str == x)
        {
            return str;
        }
        else
        {
            str++;
        }
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int count = 0;
    int len = strlen(needle);
    while (*haystack != '\0')
    {
        if (*haystack == *needle && count == len - 1)
        {
            haystack = haystack - count;
            return haystack;
        }
        else if (*haystack == *needle)
        {
            haystack++;
            count++;
            needle++;
        }
        else
        {
            haystack++;
            count = 0;
            needle = needle - count;
        }
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
