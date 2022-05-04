#include <stdio.h>

#define BUF_LEN 1001

int main()
{
    char buffer[BUF_LEN] = { (char)0 };
    size_t length = 0;

    printf("Enter your string: ");
    fgets(buffer, BUF_LEN, stdin);
    buffer[BUF_LEN - 1] = (char)0;

    for (; length < 1000 && buffer[length] != (char)0 && buffer[length] != '\n'; ++length);

    printf("%zu\n", length);
    
    return 0;
}
