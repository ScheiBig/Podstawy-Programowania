#include <stdio.h>

typedef unsigned char uchar;

int main()
{
    uchar letter = (char)0;

    printf("Input your letter: ");
    scanf(" %c", &letter);
    letter *= letter >= 'A' || letter >= 'a';
    letter *= letter <= 'Z' || letter <= 'z';
    switch (letter)
    {
    case (uchar)0:
        printf("Incorrect input\n");
        return 1;
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
        printf("vowel\n");
        break;
    default:
        printf("consonant\n");
        break;
    }
    return 0;
}
