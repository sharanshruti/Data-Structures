#include <stdio.h>
#include <stdlib.h>
//Operations on polynomials stored in Linked Lists

typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} node;

node *insert(node *head, int coeff, int exp)
{
    node *temp;
    node *p = (node *)malloc(sizeof(node));
    p->coeff = coeff;
    p->exp = exp;
    p->next = NULL;

    if (head == NULL || exp > head->exp)
    {
        p->next = head;
        head = p;
    }

    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exp > exp)
        {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
    return head;
}

node *create(node *head)
{
    int x, coeff, exp;

    do
    {
        printf("Enter the value of coeff : ");
        scanf("%d", &coeff);

        printf("Enter the value of exp : ");
        scanf("%d", &exp);

        head = insert(head, coeff, exp);

        printf("Want to insert more terms(1/0) : ");
        scanf("%d", &x);

    } while (x == 1);

    return head;
}

void print(node *head)
{
    if (head == NULL)
    {
        printf("Not a polynomia\n");
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            printf("(%dx^%d)", temp->coeff, temp->exp);
            temp = temp->next;
            if (temp != NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void polyAdd(node *head1, node *head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *head3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            head3 = insert(head3, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            head3 = insert(head3, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            head3 = insert(head3, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        head3 = insert(head3, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        head3 = insert(head3, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    printf("Added polynomial is :");
    print(head3);
}

void polySub1(node *head1, node *head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *head3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            head3 = insert(head3, p1->coeff - p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            head3 = insert(head3, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            head3 = insert(head3, -1 * (p2->coeff), p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        head3 = insert(head3, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        head3 = insert(head3, -1 * (p2->coeff), p2->exp);
        p2 = p2->next;
    }
    printf("Subtracted polynomial is :");
    print(head3);
}

void polySub2(node *head1, node *head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *head3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            head3 = insert(head3, p2->coeff - p1->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            head3 = insert(head3, -1 * (p1->coeff), p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            head3 = insert(head3, (p2->coeff), p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        head3 = insert(head3, -1 * (p1->coeff), p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        head3 = insert(head3, (p2->coeff), p2->exp);
        p2 = p2->next;
    }
    printf("Subtracted polynomial is :");
    print(head3);
}

void LargestCoeff(node *head)
{
    node *b = head;
    node *c = head;
    int a = b->coeff;

    while (c != NULL)
    {
        if (c->coeff > a)
        {
            a = c->coeff;
            b = c;
        }
        c = c->next;
    }
    printf("Term with largest co-efficiebt is (%dx^%d)\n", b->coeff, b->exp);
}

void LargestExp(node *head)
{
    node *b = head;
    node *c = head;
    int a = b->exp;

    while (c != NULL)
    {
        if (c->exp > a)
        {
            a = c->exp;
            b = c;
        }
        c = c->next;
    }
    printf("Term with largest exp is (%dx^%d)\n", b->coeff, b->exp);
}

int main()
{
    node *head1 = NULL;
    printf("Enter the polynomial\n");
    head1 = create(head1);
    print(head1);

    node *head2 = NULL;
    printf("Enter the polynomial\n");
    head2 = create(head2);
    print(head2);

    printf("\n");
    polyAdd(head1, head2);

    printf("\n");
    polySub1(head1, head2);

    printf("\n");
    polySub2(head1, head2);

    LargestCoeff(head1);
    LargestCoeff(head2);

    LargestExp(head1);
    LargestExp(head2);
}
