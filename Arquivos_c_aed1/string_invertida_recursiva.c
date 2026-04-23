#include <stdio.h>
#include <string.h>

void inverterString(char *string)
{
    if (*string == '\0')
    {
        return;
    }
    inverterString(string + 1);
    printf("%c ", *string);
}

int main()
{
    char string[10] = "abcdefghij";

    inverterString(string);
}