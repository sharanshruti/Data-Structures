#include <stdio.h>
#include <stdlib.h>
//Functionality of queue using stack

struct node
{
    int data;
    struct node *next;
} *top1 = NULL, *top2 = NULL;

void push1(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));

    if (t == NULL)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        t->data = x;
        t->next = top1;
        top1 = t;
    }
}

void push2(int x)
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
        t->next = top2;
        top2 = t;
    }
}

int pop1()
{
    struct node *t;
    int x = -1;

    if (top1 == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        t = top1;
        top1 = top1->next;
        x = t->data;
        free(t);
    }
    return x;
}

int pop2()
{
    struct node *t;
    int x = -1;

    t = top2;
    top2 = top2->next;
    x = t->data;
    free(t);

    return x;
}

int isEmpty1()
{
    return top1 ? 0 : 1;
}

int isEmpty2()
{
    return top2 ? 0 : 1;
}

void enqueue(int x)
{
    push1(x);
}

int dequeue()
{
    int x = -1;
    if (top1 == NULL && top2 == NULL)
    {
        printf("empty\n");
        getchar();
        exit(0);
    }

    if (top2 == NULL)
    {
        while (top1 != NULL)
        {
            push2(pop1());
        }
    }

    return pop2();
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());

    enqueue(293);
    enqueue(2975);
    enqueue(679);
    enqueue(49);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());

    return 0;
}
