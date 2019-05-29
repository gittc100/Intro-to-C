#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
    // printf("src intial: %s\n", src);
    // int x = src;
    int count = 0;
    int len = string_length(src);
    // printf("len: %d\n", len);
    int double_len = (len);
    // printf("double_len: %d\n", double_len);
    char *double_string = malloc(double_len);

    while (count < 1)
    {
        // printf("count: %d\n", count);
        if (*src == '\0')
        {
            src = src - len;
            // printf("*src if state: %c\n", *src);
            count++;
        }
        else
        {
            *double_string = *src;
            // printf("*double_string if state: %c\n", *double_string);
            src++;
            double_string++;
        }
    }

    *double_string = '\0';
    // printf("*double_string if state before end: %c\n", *double_string);
    double_string = double_string - (len);
    // printf("*double_string if state end: %c\n", *double_string);
    // printf("cmp: %d\n", check_strings(double_string, x));
    // printf("string: %s\n", double_string);
    return double_string;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. `n` is the amount of data that should be copied
    from `src` to `dest`. 
*/
void mem_copy(void *dest, const void *src, int n)
{
    // printf("n: %d\n", n);
    for (int i = 0; i < n; i++)
    {
        char *s = (char *)src;
        char *d = (char *)dest;
        *d = *s;
        s++;
        d++;
        src++;
        dest++;

        // int *p = (int*)src;
        // printf("p: %d\n", *p);
        // char *p = (char*)src;
        // int x = sizeof(src);
        // printf("*p: %c\n", *p);
        // printf("x: %d\n", x);
        // src = src + x;
        // printf("*dest: %c\n", (char*) dest);
        // char *dest = *p;
        // printf("*dest: %c\n", *dest);
    }
}

/*
    Given a pointer of `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 
    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?
    
    Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size)
{
    char *result = malloc(new_size + 1);
    for (int i = 0; i < new_size; i++)
    {
        char *p = (char *)ptr;
        *result = *p;
        p++;
        result++;
        ptr++;
    }
    *result = '\0';
    result = result - new_size;
    // printf("result: %s\n", result);
    return result;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));

    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);

    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0')
    {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif