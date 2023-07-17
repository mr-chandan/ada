#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char text[10], pattern[10];
    int textlen, patternlen, i, j;

    printf("enter the text ");
    gets(text);

    printf("enter the pattern to be found ");
    gets(pattern);

    textlen = strlen(text);
    patternlen = strlen(pattern);

    for (i = 0; i <= textlen; i++)
    {
        for (j = 0; j < patternlen; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == patternlen)
        {
            printf("pattern found at %d ", i);
        }
    }
}