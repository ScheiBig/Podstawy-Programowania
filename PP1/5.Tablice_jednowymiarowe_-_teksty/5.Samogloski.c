#include <stdio.h>
#include <stdbool.h>

#define BUF_LEN 1001

int main()
{
    char buffer[BUF_LEN] = { (char)0 };
    bool vovels[12] = { false };

    size_t count = 0;

    printf("Enter your string: ");
    fgets(buffer, BUF_LEN, stdin);
    buffer[BUF_LEN - 1] = (char)0;

    for (size_t i = 0; i < 1000 && buffer[i] >= ' '; ++i)
    {
        switch (buffer[i])
        {
        case 'a':
            vovels[0] = true;
            break;
        case 'A':
            vovels[1] = true;
            break;
        case 'e':
            vovels[2] = true;
            break;
        case 'E':
            vovels[3] = true;
            break;
        case 'i':
            vovels[4] = true;
            break;
        case 'I':
            vovels[5] = true;
            break;
        case 'o':
            vovels[6] = true;
            break;
        case 'O':
            vovels[7] = true;
            break;
        case 'u':
            vovels[8] = true;
            break;
        case 'U':
            vovels[9] = true;
            break;
        case 'y':
            vovels[10] = true;
            break;
        case 'Y':
            vovels[11] = true;
            break;
        default:
            break;
        }
    }

    for (size_t i = 0; i < 12; ++i)
    {
        if (vovels[i]) ++count;
    }

    printf("%zu\n", count);

    return 0;
}
