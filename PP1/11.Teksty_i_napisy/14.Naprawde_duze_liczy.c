#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "my_utils_v2.h"
__include__discard_stdin()
__include__string_reverse()

int add(const char* number1, const char* number2, char* result, int size);
int validate(const char* number);

int main()
{
    char num1[201];
    char num2[201];
    print_ln("Enter first number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%200s", num1);
    discard_stdin();
    print_ln("Enter second number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%200s", num2);
    char res[202];
    if (add(num1, num2, res, 202) != 0)
    {
        __m_exit(eINPUT_invalid);
    }
    printf("%s", res);
    return 0;
}

int add(const char* number1, const char* number2, char* result, int size)
{
    if (number1 == null || number2 == null || result == null || size <= 0 ||
        validate(number1) != 1 || validate(number2) != 1)
    {
        return 1;
    }
    int n1_l = (int)strlen(number1);
    int n2_l = (int)strlen(number2);
    const char* n1_p = number1 + n1_l - 1;
    const char* n2_p = number2 + n2_l - 1;
    int carry = 0;
    int cur_num;
    int cur_siz = 0;
    while (true)
    {
        cur_num = ctoi(*n1_p) + ctoi(*n2_p) + carry;
        carry = cur_num / 10;
        *(result + cur_siz) = dtoc(cur_num % 10);
        --n1_p;
        --n2_p;
        ++cur_siz;
        if (cur_siz == size)
        {
            return 2;
        }
        if (n1_p < number1 && n2_p < number2)
        {
            break;
        }
        else if (n1_p < number1)
        {
            while (true)
            {
                cur_num = ctoi(*n2_p) + carry;
                carry = cur_num / 10;
                *(result + cur_siz) = dtoc(cur_num % 10);
                --n2_p;
                ++cur_siz;
                if (cur_siz == size)
                {
                    return 2;
                }
                if (n2_p < number2)
                {
                    break;
                }
            }
            break;
        }
        else if (n2_p < number2)
        {
            while (true)
            {
                cur_num = ctoi(*n1_p) + carry;
                carry = cur_num / 10;
                *(result + cur_siz) = dtoc(cur_num % 10);
                --n1_p;
                ++cur_siz;
                if (cur_siz == size)
                {
                    return 2;
                }
                if (n1_p < number1)
                {
                    break;
                }
            }
            break;
        }
    }
    if (carry == 1)
    {
        if (cur_siz < size)
        {
            *(result + cur_siz) = '1';
            ++cur_siz;
        }
        else
        {
            return 2;
        }
    }
    if (cur_siz < size)
    {
        *(result + cur_siz) = str_term;
    }
    else
    {
        return 2;
    }
    string_reverse(result);
    return 0;
}

int validate(const char* number)
{
    if (number == null)
    {
        return -1;
    }
    if (strlen(number) == 0)
    {
        return 1;
    }
    const char* temp = number;
    if (*number == '0' && strlen(number) != 1)
    {
        return 0;
    }
    do
    {
        if (!is_digit(*temp))
        {
            return 0;
        }
    } while (*(++temp) != str_term);
    return 1;
}
