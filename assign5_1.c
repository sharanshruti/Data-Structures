#include <stdio.h>
#include <stdlib.h>
//Correctly Paranthesized or not

struct node
{
    char data;
    struct node *next;
} *top = NULL;

void push(char a)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));

    if (t == NULL)
    {
        printf("Stack overflow\n");
    }
    else
    {
        t->data = a;
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
        printf("Stack underflow\n");
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

int match(char a, char b)
{
    if (a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isBalanced(char *exp)
{
    char popped_up;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == NULL)
            {
                return 0;
            }
            else
            {
                popped_up = pop();
                if (!match(popped_up, exp[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "{([a+b] * [c - d])/e}";
    if(isBalanced(exp)==1)
        printf("expression correctly paranthesized.\n");
    else
        printf("expression incorecctly paranthesized.\n");

    return 0;
}
