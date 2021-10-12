#include <stdio.h>
//Valid Expression or not(Operators, Operands, Paranthesis)

int isAlphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int isOp(char symbol)
{
    if (symbol == '^' || symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*')
        return 1;
    return 0;
}

char pairBracket(char x)
{
    if (x == ')')
        return '(';
    if (x == '}')
        return '{';
    if (x == ']')
        return '[';
}

int valid(char *exp)
{
    char brackets[50];
    brackets[0] = '\0';
    int top = 0, i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            if (i > 0 && isAlphanumeric(exp[i - 1]))
                return 0;
            top++;
            brackets[top] = exp[i];
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isAlphanumeric(exp[i + 1]))
                return 0;
            if (brackets[top] == pairBracket(exp[i]))
                top--;
            else
                return 0;
        }
        else if (isAlphanumeric(exp[i]) && isAlphanumeric(exp[i + 1]))
            return 0;
        else if (isOp(exp[i]))
        {
            if (i == 0 || exp[i + 1] == '\0')
                return 0;
            if (isOp(exp[i - 1]) || exp[i - 1] == '(' || exp[i - 1] == '{' || exp[i - 1] == '[')
                return 0;
            if (isOp(exp[i + 1]) || exp[i + 1] == ')' || exp[i + 1] == '}' || exp[i + 1] == ']')
                return 0;
        }
        i++;
    }
    if (top > 0)
        return 0;
    return 1;
}

void rmvSpace(char *expression)
{
    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == ' ')
            continue;
        expression[j] = expression[i];
        j++;
    }
    expression[j] = '\0';
}

void main(void)
{
    char expression[100] = "[a+{b*c/(d+e)-f}+g]+h";

    rmvSpace(expression);

    if (valid(expression))
        printf("Valid\n");
    else
        printf("Invalid\n");
}
