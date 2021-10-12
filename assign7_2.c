#include <stdio.h>

#define SIZE 10

//Stack Oerations Using Queue
int queue[SIZE], back = 0, front = -1;

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return (front == SIZE-1);
}

void enqueue(int data)
{
    if (isFull())
        printf("\nError: The queue is full.\n");
    else
    {
        front++;
        queue[front] = data;
    }
}

int dequeue()
{
    int data = 0;
    if (!isEmpty())
    {
        data = queue[back];
        back++;
    }
    else printf("\nError: The queue is empty!\n");
    return data;
}

void main(void)
{
    int data;
    char menu = -1;
    while (menu != '0')
    {
        printf("\n1. Push\n2. Pop\n3. Check if Empty\n4. Check if full\n0. Exit\nEnter a menu number: ");
        scanf(" %c", &menu);
        if (menu == '1')
        {
            printf("Enter data to be pushed: ");
            scanf("%d", &data);
            enqueue(data);
        }
        else if (menu == '2')
        {
            for (int i = 0; i < front; i++)
            {
                queue[i] = dequeue();
            }
            data = dequeue();
            back = 0;
            
            if (data)
            {
                front--;
                printf("\n%d has been popped.\n", data);
            }
        }
        else if (menu == '3')
        {
            if (isEmpty())
                printf("\nThe queue is empty.\n");
            else printf("\nThe queue is not empty.\n");
        }
        else if (menu == '4')
        {
            if (isFull())
                printf("\nThe queue is full.\n");
            else printf("\nThe queue is not full.\n");
        }
        else if (menu == '0');
        else printf("\nWrong meny index entered!\n\n");
    }
}