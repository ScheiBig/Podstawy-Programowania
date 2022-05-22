#include "big_number_utils.h"

#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "my_utils_v3.h"
#include "my_string_split.h"
#include "my_string.h"

int _comp_unsigned(c_cstring number1, c_cstring number2)
{
    size_t n1_l = strlen(number1);
    size_t n2_l = strlen(number2);

    if (n1_l < n2_l)
    {
        return -1;
    }
    if (n1_l > n2_l)
    {
        return 1;
    }
    for (size_t i = 0; i < n1_l; ++i)
    {
        if (*(number1 + i) < *(number2 + i))
        {
            return -1;
        }
        if (*(number1 + i) > *(number2 + i))
        {
            return 1;
        }
    }
    return 0;
}
// If result == null, calculates length of result to be needed, otherwise 
// performs subtraction of two positive numbers
int _mul(c_cstring number1, c_cstring number2, cstring result)
{
    c_cstring n1_p = number1 + strlen(number1) - 1;
    c_cstring n2_p;
    int carry = 0;
    int cur_num;
    size_t n1_i = 0;
    size_t n2_i = 0;
    for (; n1_p >= number1; --n1_p, ++n1_i)
    {
        for (n2_p = number2 + strlen(number2) - 1, n2_i = 0, carry = 0; n2_p >= number2; --n2_p, ++n2_i)
        {
            cur_num = ctoi(*n1_p) * ctoi(*n2_p) + carry + (is_digit(*(result + n1_i + n2_i)) ? ctoi(*(result + n1_i + n2_i)) : 0);
            carry = cur_num / 10;
            *(result + n1_i + n2_i) = dtoc(cur_num % 10);
        }
        if (carry >= 1)
        {
            *(result + n1_i + n2_i) = dtoc(carry);
        }
    }
    *(result + n1_i + n2_i) = str_term;

    string_reverse(result);
    return 0;
}

// If result == null, calculates length of result to be needed, otherwise 
// performs subtraction of two positive numbers (first is longer / larger)
int _sub(c_cstring number1, c_cstring number2, cstring result)
{
    c_cstring n1_p = number1 + strlen(number1) - 1;
    c_cstring n2_p = number2 + strlen(number2) - 1;
    int carry = 0;
    int cur_num;
    int cur_siz = 0;
    for (; n2_p >= number2; --n1_p, --n2_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) - ctoi(*n2_p) - carry;
        if (cur_num < 0)
        {
            cur_num += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    for (; n1_p >= number1; --n1_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) - carry;
        if (cur_num < 0)
        {
            cur_num += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    for (; *(result + cur_siz - 1) == '0'; --cur_siz)
    {
        *(result + cur_siz - 1) = str_term;
    }
    *(result + cur_siz) = str_term;

    string_reverse(result);
    return 0;

}

// If result == null, calculates length of result to be needed, otherwise 
// performs addition of two positive numbers (first is longer / larger)
int _add(c_cstring number1, c_cstring number2, cstring result)
{
    c_cstring n1_p = number1 + strlen(number1) - 1;
    c_cstring n2_p = number2 + strlen(number2) - 1;
    int carry = 0;
    int cur_num;
    int cur_siz = 0;
    for (; n2_p >= number2; --n1_p, --n2_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) + ctoi(*n2_p) + carry;
        carry = cur_num / 10;
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    for (; n1_p >= number1; --n1_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) + carry;
        carry = cur_num / 10;
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    if (carry == 1)
    {
        *(result + cur_siz) = '1';
        ++cur_siz;
    }
    *(result + cur_siz) = str_term;

    string_reverse(result);
    return 0;
}

int multiply(c_cstring number1, c_cstring number2, cstring* result)
{
    if (number1 == null || number2 == null || result == null)
    {
        return 1;
    }
    if (validate(number1) != 0 || validate(number2) != 0)
    {
        return 2;
    }
    if (*number1 == '0' || *number2 == '0')
    {
        size_t alloc_size = 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '0';
        return 0;
    }
    if (*number1 != '-' && *number2 != '-')
    {
        size_t alloc_size = strlen(number1) + strlen(number2) + 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        return _mul(number1, number2, *result);
    }
    else if (*number1 == '-' && *number2 == '-')
    {
        size_t alloc_size = strlen(number1 + 1) + strlen(number2 + 1) + 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        return _mul(number1 + 1, number2 + 1, *result);
    }
    else if (*number1 == '-')
    {
        size_t alloc_size = strlen(number1 + 1) + strlen(number2) + 3;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '-';
        return _mul(number1 + 1, number2, *result + 1);
    }
    else
    {
        size_t alloc_size = strlen(number1) + strlen(number2 + 1) + 3;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '-';
        return _mul(number1, number2 + 1, *result + 1);
    }
}

int subtract(c_cstring number1, c_cstring number2, cstring* result)
{
    if (number1 == null || number2 == null || result == null)
    {
        return 1;
    }
    if (validate(number1) != 0 || validate(number2) != 0)
    {
        return 2;
    }
    if (*number1 != '-' && *number2 != '-')
    {
        int res = _comp_unsigned(number1, number2);
        if (res > 0)
        {
            size_t alloc_size = max(strlen(number1), strlen(number2)) + 1;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            return _sub(number1, number2, *result);
        }
        else if (res < 0)
        {
            size_t alloc_size = max(strlen(number1), strlen(number2)) + 2;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            **result = '-';
            return _sub(number2, number1, *result + 1);
        }
        else
        {
            if ((*result = (cstring)calloc(2, sizeof(char))) == null)
            {
                return 3;
            }
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
            strcpy(*result, "0");
            return 0;
        }
    }
    else if (*number1 == '-' && *number2 == '-')
    {
        ++number1;
        ++number2;
        int res = _comp_unsigned(number1, number2);
        if (res > 0)
        {
            size_t alloc_size = max(strlen(number1), strlen(number2)) + 2;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            **result = '-';
            return _sub(number1, number2, *result + 1);
        }
        else if (res < 0)
        {
            size_t alloc_size = max(strlen(number1), strlen(number2)) + 1;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            return _sub(number2, number1, *result);
        }
        else
        {
            if ((*result = (cstring)calloc(2, sizeof(char))) == null)
            {
                return 3;
            }
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
            strcpy(*result, "0");
            return 0;
        }
    }
    else if (*number1 == '-')
    {
        size_t alloc_size = max(strlen(number1), strlen(number2)) + 3;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '-';
        if (_comp_unsigned(number1 + 1, number2) > 0)
        {
            return _add(number1 + 1, number2, *result + 1);
        }
        else
        {
            return _add(number2, number1 + 1, *result + 1);
        }
    }
    else
    {
        if (_comp_unsigned(number1, number2 + 1) > 0)
        {
            return add(number1, number2 + 1, result);
        }
        else
        {
            return add(number2 + 1, number1, result);
        }
    }
}

int add(c_cstring number1, c_cstring number2, cstring* result)
{
    if (number1 == null || number2 == null || result == null)
    {
        return 1;
    }
    if (validate(number1) != 0 || validate(number2) != 0)
    {
        return 2;
    }
    if (*number1 != '-' && *number2 != '-')
    {
        size_t alloc_size = max(strlen(number1), strlen(number2)) + 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        if (_comp_unsigned(number1, number2) > 0)
        {
            return _add(number1, number2, *result);
        }
        else
        {
            return _add(number2, number1, *result);
        }
    }
    else if (*number1 == '-' && *number2 == '-')
    {
        return subtract(number1, number2 + 1, result);
    }
    else if (*number1 == '-')
    {
        return subtract(number2, number1 + 1, result);
    }
    else
    {
        return subtract(number1, number2 + 1, result);
    }
}

int validate(c_cstring number)
{
    if (number == null)
    {
        return -1;
    }
    if (strlen(number) == 0)
    {
        return 2;
    }
    c_cstring temp = number;
    if (*number == '0' && strlen(number) != 1)
    {
        return 2;
    }
    if (*number == '-' && *(number + 1) == '0' && strlen(number) != 2)
    {
        return 2;
    }
    if (*temp == '-')
    {
        ++temp;
    }
    do
    {
        if (!is_digit(*temp))
        {
            return 2;
        }
    } while (*(++temp) != str_term);
    return 0;
}

int validate_token(token number)
{
    if (number.start_ptr == null)
    {
        return -1;
    }
    if (number.length == 0)
    {
        return 2;
    }
    c_cstring temp = number.start_ptr;
    c_cstring end = number.start_ptr + number.length;
    if (*number.start_ptr == '0' && number.length != 1)
    {
        return 2;
    }
    if (*number.start_ptr == '-' && *(number.start_ptr + 1) == '0' && number.length != 2)
    {
        return 2;
    }
    if (*temp == '-')
    {
        ++temp;
    }
    do
    {
        if (!is_digit(*temp))
        {
            return 2;
        }
    } while ((++temp) != end);
    return 0;
}

// NEXT TODO
int validate_expression(c_cstring expr)
{
    if (expr == null)
    {
        return 2;
    }
    if (strlen(expr) == 0)
    {
        return 1;
    }
    for (
        token tok = string_split_e(expr, "+-*");
        tok.start_ptr != null;
        tok = string_split_next_e(tok)
        )
    {
        if (tok.length == 0)
        {
            token prev = tok;
            tok = string_split_next_e(tok);
            tok.start_ptr = prev.start_ptr;
            ++tok.length;
        }
        if (validate_token(tok) != 0)
        {
            return 1;
        }
    }
    return 0;
}

int _comp_unsigned_token(token number1, token number2)
{
    size_t n1_l = number1.length;
    size_t n2_l = number2.length;

    if (n1_l < n2_l)
    {
        return -1;
    }
    if (n1_l > n2_l)
    {
        return 1;
    }
    for (size_t i = 0; i < n1_l; ++i)
    {
        if (*(number1.start_ptr + i) < *(number2.start_ptr + i))
        {
            return -1;
        }
        if (*(number1.start_ptr + i) > *(number2.start_ptr + i))
        {
            return 1;
        }
    }
    return 0;
}
// If result == null, calculates length of result to be needed, otherwise 
// performs subtraction of two positive numbers
int _mul_token(token number1, token number2, cstring result)
{
    c_cstring n1_p = number1.start_ptr + number1.length - 1;
    c_cstring n2_p;
    int carry = 0;
    int cur_num;
    size_t n1_i = 0;
    size_t n2_i = 0;
    for (; n1_p >= number1.start_ptr; --n1_p, ++n1_i)
    {
        for (n2_p = number2.start_ptr + number2.length - 1, n2_i = 0, carry = 0; n2_p >= number2.start_ptr; --n2_p, ++n2_i)
        {
            cur_num = ctoi(*n1_p) * ctoi(*n2_p) + carry + (is_digit(*(result + n1_i + n2_i)) ? ctoi(*(result + n1_i + n2_i)) : 0);
            carry = cur_num / 10;
            *(result + n1_i + n2_i) = dtoc(cur_num % 10);
        }
        if (carry >= 1)
        {
            *(result + n1_i + n2_i) = dtoc(carry);
        }
    }
    *(result + n1_i + n2_i) = str_term;

    string_reverse(result);
    return 0;
}

// If result == null, calculates length of result to be needed, otherwise 
// performs subtraction of two positive numbers (first is longer / larger)
int _sub_token(token number1, token number2, cstring result)
{
    c_cstring n1_p = number1.start_ptr + number1.length - 1;
    c_cstring n2_p = number2.start_ptr + number2.length - 1;
    int carry = 0;
    int cur_num;
    int cur_siz = 0;
    for (; n2_p >= number2.start_ptr; --n1_p, --n2_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) - ctoi(*n2_p) - carry;
        if (cur_num < 0)
        {
            cur_num += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    for (; n1_p >= number1.start_ptr; --n1_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) - carry;
        if (cur_num < 0)
        {
            cur_num += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    for (; *(result + cur_siz - 1) == '0'; --cur_siz)
    {
        *(result + cur_siz - 1) = str_term;
    }
    *(result + cur_siz) = str_term;

    string_reverse(result);
    return 0;

}

// If result == null, calculates length of result to be needed, otherwise 
// performs addition of two positive numbers (first is longer / larger)
int _add_token(token number1, token number2, cstring result)
{
    c_cstring n1_p = number1.start_ptr + number1.length - 1;
    c_cstring n2_p = number2.start_ptr + number2.length - 1;
    int carry = 0;
    int cur_num;
    int cur_siz = 0;
    for (; n2_p >= number2.start_ptr; --n1_p, --n2_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) + ctoi(*n2_p) + carry;
        carry = cur_num / 10;
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    for (; n1_p >= number1.start_ptr; --n1_p, ++cur_siz)
    {
        cur_num = ctoi(*n1_p) + carry;
        carry = cur_num / 10;
        *(result + cur_siz) = dtoc(cur_num % 10);
    }
    if (carry == 1)
    {
        *(result + cur_siz) = '1';
        ++cur_siz;
    }
    *(result + cur_siz) = str_term;

    string_reverse(result);
    return 0;
}

int multiply_token(token, token, cstring*);
int subtract_token(token, token, cstring*);
int add_token(token, token, cstring*);

int multiply_token(token number1, token number2, cstring* result)
{
    if (number1.start_ptr == null || number2.start_ptr == null || result == null)
    {
        return 1;
    }
    if (validate_token(number1) != 0 || validate_token(number2) != 0)
    {
        return 2;
    }
    if (*number1.start_ptr == '0' || *number2.start_ptr == '0')
    {
        size_t alloc_size = 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '0';
        return 0;
    }
    token num1m = (token){ .start_ptr = number1.start_ptr + 1, .length = number1.length - 1, .delimiters = number1.delimiters };
    token num2m = (token){ .start_ptr = number2.start_ptr + 1, .length = number2.length - 1, .delimiters = number2.delimiters };
    if (*number1.start_ptr != '-' && *number2.start_ptr != '-')
    {
        size_t alloc_size = number1.length + number2.length + 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        return _mul_token(number1, number2, *result);
    }
    else if (*number1.start_ptr == '-' && *number2.start_ptr == '-')
    {
        size_t alloc_size = (number1.length - 1) + (number2.length - 1) + 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        return _mul_token(num1m,num2m, * result);

    }
    else if (*number1.start_ptr == '-')
    {
        size_t alloc_size = (number1.length - 1) + number2.length + 3;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '-';
        return _mul_token(num1m, number2, * result + 1);
    }
    else
    {
        size_t alloc_size = number1.length + (number2.length - 1) + 3;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '-';
        return _mul_token(number1, num2m, * result + 1);
    }
}

int subtract_token(token number1, token number2, cstring* result)
{
    if (number1.start_ptr == null || number2.start_ptr == null || result == null)
    {
        return 1;
    }
    if (validate_token(number1) != 0 || validate_token(number2) != 0)
    {
        return 2;
    }
    token num1m = (token){ .start_ptr = number1.start_ptr + 1, .length = number1.length - 1, .delimiters = number1.delimiters };
    token num2m = (token){ .start_ptr = number2.start_ptr + 1, .length = number2.length - 1, .delimiters = number2.delimiters };
    if (*number1.start_ptr != '-' && *number2.start_ptr != '-')
    {
        int res = _comp_unsigned_token(number1, number2);
        if (res > 0)
        {
            size_t alloc_size = max(number1.length, number2.length) + 1;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            return _sub_token(number1, number2, *result);
        }
        else if (res < 0)
        {
            size_t alloc_size = max(number1.length, number2.length) + 2;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            **result = '-';
            return _sub_token(number2, number1, *result + 1);
        }
        else
        {
            if ((*result = (cstring)calloc(2, sizeof(char))) == null)
            {
                return 3;
            }
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
            strcpy(*result, "0");
            return 0;
        }
    }
    else if (*number1.start_ptr == '-' && *number2.start_ptr == '-')
    {
        int res = _comp_unsigned_token(num1m, num2m);
        if (res > 0)
        {
            size_t alloc_size = max(num1m.length, num2m.length) + 2;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            **result = '-';
            return _sub_token(num1m, num2m, *result + 1);
        }
        else if (res < 0)
        {
            size_t alloc_size = max(num1m.length, num2m.length) + 1;
            if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
            {
                return 3;
            }
            return _sub_token(num2m, num1m, *result);
        }
        else
        {
            if ((*result = (cstring)calloc(2, sizeof(char))) == null)
            {
                return 3;
            }
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
            strcpy(*result, "0");
            return 0;
        }
    }
    else if (*number1.start_ptr == '-')
    {
        size_t alloc_size = max(number1.length, number2.length) + 3;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        **result = '-';
        if (_comp_unsigned_token(num1m, num2m) > 0)
        {
            return _add_token(num1m, number2, *result + 1);
        }
        else
        {
            return _add_token(number2, num1m, *result + 1);
        }
    }
    else
    {
        if (_comp_unsigned_token(number1, num2m) > 0)
        {
            return add_token(number1, num2m, result);
        }
        else
        {
            return add_token(num2m, number1, result);
        }
    }
}

int add_token(token number1, token number2, cstring* result)
{
    if (number1.start_ptr == null || number2.start_ptr == null || result == null)
    {
        return 1;
    }
    if (validate_token(number1) != 0 || validate_token(number2) != 0)
    {
        return 2;
    }
    token num1m = (token){ .start_ptr = number1.start_ptr + 1, .length = number1.length - 1, .delimiters = number1.delimiters };
    token num2m = (token){ .start_ptr = number2.start_ptr + 1, .length = number2.length - 1, .delimiters = number2.delimiters };
    if (*number1.start_ptr != '-' && *number2.start_ptr != '-')
    {
        size_t alloc_size = max(number1.length, number2.length) + 2;
        if ((*result = (cstring)calloc(alloc_size, sizeof(char))) == null)
        {
            return 3;
        }
        if (_comp_unsigned_token(number1, number2) > 0)
        {
            return _add_token(number1, number2, *result);
        }
        else
        {
            return _add_token(number2, number1, *result);
        }
    }
    else if (*number1.start_ptr == '-' && *number2.start_ptr == '-')
    {
        return subtract_token(number1, num2m, result);
    }
    else if (*number1.start_ptr == '-')
    {
        return subtract_token(number2, num1m, result);
    }
    else
    {
        return subtract_token(number1, num2m, result);
    }
}

int calculate(c_cstring expr, cstring* result)
{
    if (expr == null || result == null)
    {
        return 1;
    }
    if (validate_expression(expr) != 0)
    {
        return 2;
    }
    token cur_tok = string_split_e(expr, "+-*");
    if (cur_tok.length == 0)
    {
        token prev = cur_tok;
        cur_tok = string_split_next_e(cur_tok);
        cur_tok.start_ptr = prev.start_ptr;
        ++cur_tok.length;
    }
    if (cur_tok.delimiters == null)
    {
        *result = (cstring)calloc(strlen(expr) + 1, sizeof(char));
        if (*result == null)
        {
            return 3;
        }
        strcpy(*result, expr);
        return 0;
    }
    token prev_tok = cur_tok;
    cstring prev_result = null;
    cstring cur_result = null;
    int ret;
    for (cur_tok = string_split_next_e(cur_tok);
        cur_tok.start_ptr != null;
        cur_tok = string_split_next_e(cur_tok)
        )
    {
        if (cur_tok.length == 0)
        {
            token prev = cur_tok;
            cur_tok = string_split_next_e(cur_tok);
            cur_tok.start_ptr = prev.start_ptr;
            ++cur_tok.length;
        }
        switch (*(cur_tok.start_ptr - 1))
        {
        case '+':
            ret = add_token(prev_tok, cur_tok, &cur_result);
            break;
        case '-':
            ret = subtract_token(prev_tok, cur_tok, &cur_result);
            break;
        case '*':
            ret = multiply_token(prev_tok, cur_tok, &cur_result);
            break;
        default:
            if (prev_result != null)
            {
                free(prev_result);
            }
            return 4;
        }
        if (prev_result != null)
        {
            free(prev_result);
        }
        if (ret != 0)
        {
            if (cur_result != null)
            {
                free(cur_result);
            }
            return ret;
        }
        prev_result = cur_result;
        prev_tok = (token){ .start_ptr = cur_result, .length = strlen(cur_result), .delimiters = null };
    }
    *result = cur_result;
    return 0;
}
