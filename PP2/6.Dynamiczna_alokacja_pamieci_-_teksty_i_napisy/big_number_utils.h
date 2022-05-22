#pragma once

int multiply(const char* number1, const char* number2, char** result);
int subtract(const char* number1, const char* number2, char** result);
int add(const char* number1, const char* number2, char** result);

int validate(const char* number);
int validate_expression(const char* expr);
int calculate(const char* expr, char** result);