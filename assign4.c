#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Infix to Postfix

struct node
{
    char data;
    struct node *next;
} *top = NULL;

void push(char x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));

    if (t == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct node *t;
    char x = -1;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

char stackTop()
{
    if (top)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

int isEmpty()
{
    return top ? 0 : 1;
}

int inPrec(char input)
{
    switch (input)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '%':
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;
    }
}

int outPrec(char input)
{
    switch (input)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '%':
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 100;
    }
}

int isOperator(char input) 
{ 
    switch (input) { 
    case '+': 
        return 1; 
    case '-': 
        return 1; 
    case '*': 
        return 1; 
    case '%': 
        return 1; 
    case '/': 
        return 1;
    case '^':
        return 1; 
    case '(': 
        return 1; 
    } 
    return 0; 
} 
 

int isOperand(char input)
{
    if (input >= 65 && input <= 90 || input >= 97 && input <= 122)
        return 1;
    return 0;
}


char *inToPost(char *input)
{
    char *postfix;
    int i = 0, j = 0;
    int len = strlen(input);
    postfix = (char *)malloc((len + 2)*sizeof(char));

    while (input[i] != '\0')
    {
        if (isOperand(input[i]))
        {
            printf("%c", input[i]);
        }
        else if (isOperator(input[i]))
        {
            if (isEmpty() || outPrec(input[i]) > inPrec(stackTop()))
                push(input[i]);
            else
            {
                while (!isEmpty() && outPrec(input[i]) < inPrec(stackTop()))
                {
                    printf("%c", pop());
                }
                push(input[i]);
            }
        }
        else if (input[i] == ')')
        {
            while (stackTop() != '(')
            {
                printf("%c", stackTop());
                pop();
                if (isEmpty())
                {
                    printf("Wrong input\n");
                    exit(1);
                }
            }
            pop();
        }
        i++;
    }

    while (!isEmpty())
    {
        if (stackTop() == '(')
        {
            printf("\n Wrong input\n");
            exit(1);
        }
        printf("%c", pop());
    }
    printf("\n");
}

int main()
{
    char *infix = "((a + b)*c) - d^e^f ";
    push('#');

    char *postfix = inToPost(infix);
}
