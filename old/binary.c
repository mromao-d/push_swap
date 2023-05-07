#include <stdio.h>
#include <stdlib.h>

char    *ft_binary(int   nmbr)
{
    int     i;
    char    *output;

    output = malloc(sizeof(char) * 33);
    i = 31;
    while (i >= 0)
    {
        output[31 - i] = ((nmbr >> i) & 1 ) == 1 ? '1' : '0';
        i--;
    }
    output[32] = '\0';
    return (output);
}

int main (void)
{
    printf("%s", ft_binary(42));
    return (0);
}

/* int main (void)
{
    printf("%d", (42>>3) & 1);
    return (0);
} */