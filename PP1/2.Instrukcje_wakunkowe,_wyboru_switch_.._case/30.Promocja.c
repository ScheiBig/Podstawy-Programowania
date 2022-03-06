#include <stdio.h>

int main()
{
    int grade;
    printf("Enter your grade: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d", &grade);
    switch (grade)
    {
    case 1:
        printf("brak promocji do nastepnej klasy\n");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        printf("promocja do nastepnej klasy\n");
        break;
    case 6:
        printf("promocja z ocena celujaca\n");
    default:
        printf("Wprowadzona ocena jest niepoprawna.\n");
    }
    return 0;
}
