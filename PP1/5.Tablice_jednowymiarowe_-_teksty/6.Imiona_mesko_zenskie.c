#include <stdio.h>
#include <string.h>

#define BUF_LEN 11

int main()
{
    char buffer[BUF_LEN] = { (char)0 };

    printf("Enter your name: ");
    fgets(buffer, BUF_LEN, stdin);
    buffer[BUF_LEN - 1] = (char)0;
    if (buffer[strlen(buffer) - 1] <= ' ') buffer[strlen(buffer) - 1] = (char)0;

    if (buffer[strlen(buffer) - 1] == 'a')
        printf("Imie zenskie\n");
    else
        printf("Imie meskie");

    return 0;
}
