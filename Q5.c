#include <stdio.h>
#include <ctype.h>

int main()
{
    char sentences[3][100];

    // Input 3 semicolon-separated sentences
    for (int i = 0; i < 3; i++)
    {
        printf("Enter sentence %d: ", i + 1);

        scanf("%[^;]%*c", sentences[i]);
    }

    // Count vowels using nested loops
    for (int i = 0; i < 3; i++)
    {
        int vowels = 0;

        for (int j = 0; sentences[i][j] != '\0'; j++)
        {
            char ch = tolower(sentences[i][j]);

            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
            {
                vowels++;
            }
        }

        printf("Sentence %d has %d vowels.\n", i + 1, vowels);
    }

    return 0;
}