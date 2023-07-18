#include <stdio.h>
#include <string.h>
void main()
{
    char text[20], pat[20];
    int textlen, patternlen,j;
    printf("Enter the string : ");
    gets(text);
    printf("Enter the pattern to find : ");
    gets(pat);

    textlen = strlen(text);
    patternlen = strlen(pat);

    for (int i = 0; i <= textlen - patternlen; i++)
    {

        for (j = 0; j < patternlen; j++)
        {
            if (text[i + j] != pat[j])
            {
                break;
            }
        }

        if (j == patternlen)
            printf("Pattern found at position %d \n", i + 1);
    }
}
