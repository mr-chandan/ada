#include <stdio.h>
#include <string.h>

int bruteForceStringMatch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }

    return -1; 
}

int main()
{
    char text[] = "Hello, World!";
    char pattern[] = "World";

    int result = bruteForceStringMatch(text, pattern);

    if (result != -1)
    {
        printf("Pattern found at index %d\n", result);
    }
    else
    {
        printf("Pattern not found in the text\n");
    }

    return 0;
}
