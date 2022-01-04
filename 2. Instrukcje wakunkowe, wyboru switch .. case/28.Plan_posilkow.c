#include <stdio.h>

typedef unsigned char uchar;

int main()
{
    uchar choice, plan_content[3][32] = {
        "Breakfast, Lunch and Dinner",
        "Lunch and Dinner",
        "Dinner"
    };
    int success, plan;
    printf("Enter your choice: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf(" %c", &choice);
    choice *= success == 1;
    choice *= choice >= 'A' && choice <= 'C';

    switch (choice)
    {
    case (uchar)0:
        printf("Incorrect input\n");
        return 1;
    default:
        plan = choice - 'A';
    }

    printf("You chose %s as your meal plan.\n", plan_content[plan]);
    return 0;
}
