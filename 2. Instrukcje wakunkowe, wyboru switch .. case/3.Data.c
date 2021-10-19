#include <stdio.h>

int main()
{
    unsigned int day, month, year;
    int success;
    printf("Input date (dd-mm-yyyy): \n");
    success = scanf("%2u-%2u-%4u", &day, &month, &year);
    if (success != 3) 
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (month == 1 ||
        month == 3 ||
        month == 5 ||
        month == 7 ||
        month == 8 ||
        month == 10 ||
        month == 12)
    {
        if (day > 0 && day <= 31)
        {
            printf("Correct\n");
        }
        else
        {
            printf("Incorrect\n");
        }
    }
    else if (month == 4 ||
        month == 6 ||
        month == 9 ||
        month == 11)
    {
        if (day > 0 && day <= 30)
        {
            printf("Correct\n");
        }
        else
        {
            printf("Incorrect\n");
        }
    } 
    else if (month == 2)
    {
        if (year % 4 == 0 &&
            year % 400 != 100 &&
            year % 400 != 200 &&
            year % 400 != 300)
        {
            if (day > 0 && day <= 29)
            {
                printf("Correct\n");
            }
            else
            {
                printf("Incorrect\n");
            }   
        }
        else
        {
            if (day > 0 && day <= 28)
            {
                printf("Correct\n");
            }
            else
            {
                printf("Incorrect\n");
            }   
            
        }
    }
    else
    {
        printf("Incorrect\n");
    }

    return 0;
}
