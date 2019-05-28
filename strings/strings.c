#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        // printf("s*: %c\n", *s);
        // printf("s: %d\n", s);
        s++;
        count++;
    }
    return count;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    int x = strlen(s);
    printf("s: %d\n", x);
    // printf("original rv: %i\n", rv);
    int len = strlen(s) - 1;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        printf("s+i:%c\n", *(s+i));
     
        // printf("rv:%i\n", rv);
        // printf("rv:%c\n", *rv);
        if (*(s+i) == ' ')
        {
            *rv = ' ';
        }else
        {
            *rv = *(s+i);
        }
        // printf("rv:%c\n", *rv);
        rv++;
        // printf("rv:%i\n", rv);
    }
    *rv = '\0';
    rv = rv - len -1;
    while (*rv != '\0')
    {
        printf("while *rv: %c\n", *rv);
        rv++;
    }
    rv = rv - len -1;
    // printf("final rv: %i\n", rv);
    printf("final *rv: %c\n", *rv);
    return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
