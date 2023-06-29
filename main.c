#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define welcome_message "Welcome! Please input an math expression："

typedef struct 
{
    float number1;
    char operater;
    float number2;
} Expression;

Expression extractExpression(char* expression) {
    Expression result = {.number1 = 0, .number2 = 0, .operater = '\0'};

    int len = strlen(expression);
    int status = 0;
    int i = 0;

    while (i < len) {
        if (isdigit(expression[i])) {
            int j = i;
            while (j < len && isdigit(expression[j])) {
                j++;
            }
            if (status == 0) {
                sscanf(&expression[i], "%f", &result.number1);
                status = 1;
            } else {
                sscanf(&expression[i], "%f", &result.number2);
            }
            i = j;
        } else if (isspace(expression[i])) {
            i++;
        } else {
            result.operater = expression[i];
            i++;
        }
    }
    return result;
}

float power(float root, float n) {
    float result = 1;
    if (n == (int)n) {
        if (n > 0) {
            for (; n > 0; n--) {
                result *= root;
            }
        } else if (n < 0) {
            for (int i = -n; i > 0; i--) {
                result *= root;
            }
            result = 1/result;
        } else {
            result = 0;
        }
    } else {
        exit(1);
    }
    return result;
}

float caculate(Expression expression) {
    float result = 0;
    switch (expression.operater)
    {
    case '/':
        result = expression.number1 / expression.number2;
        break;
    case '*':
        result = expression.number1 * expression.number2;
        break;
    case '+':
        result = expression.number1 + expression.number2;
        break;
    case '-':
        result = expression.number1 - expression.number2;
        break;
    case '^':
        result = power(expression.number1, expression.number2);
        break;
    default:
        exit(1);
        break;
    }
    return result;
}

int main() {
    float answer;
    char expression_string[101];
    printf(welcome_message);
    scanf("%s", expression_string);
    Expression expression = extractExpression(expression_string);
    printf("The answer is %f", caculate(expression));
    return 0;
}
