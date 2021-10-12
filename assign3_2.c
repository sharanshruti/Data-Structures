#include <stdio.h>
#include <stdlib.h>
//Operations on Doubly LInked lists

struct node
{
  int data;
  struct node *next;
};

void printlinkedlist(struct node *ptr)
{
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}
struct node *insertatfirst(struct node *head, int data)
{
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->next = head;
  return ptr;
}

struct node *insertatend(struct node *head, int data)
{
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr = head;
  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  struct node *p = (struct node *)malloc(sizeof(struct node));
  p->data = data;
  p->next = NULL;
  ptr->next = p;

  return head;
}

struct node *insertafterelement(struct node *head, int x, int data)
{

  struct node *ptr = head;
  while (ptr->data != x)
  {
    ptr = ptr->next;
  }
  struct node *p = malloc(sizeof(struct node));
  p->data = data;
  p->next = ptr->next;
  ptr->next = p;
  return head;
}

struct node *deleteatindex(struct node *head, int index)
{
  struct node *p = head;
  struct node *q = p->next;
  for (int i = 1; i < index - 1; i++)
  {
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  free(q);
  return head;
}

struct node *deletelastnode(struct node *head)
{
  struct node *p = head;
  struct node *q = p->next;
  while (q->next != NULL)
  {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}

int sumofoddposition(struct node *head)
{
  int sum = 0;
  struct node *ptr = head;
  while (ptr != NULL)
  {
    sum += ptr->data;
    ptr = ptr->next;
    if (ptr == NULL)
    {
      break;
    }
    ptr = ptr->next;
  }
  return sum;
}

int countelements(struct node *head)
{
  int count = 0;
  struct node *ptr = head;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    count++;
  }
  return count;
}

void printevenposition(struct node *head)
{
  struct node *ptr = head->next;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
    if (ptr == NULL)
    {
      break;
    }
    ptr = ptr->next;
  }
  printf("\n");
}

struct node *deletealternate(struct node *head)
{

  struct node *p = head;
  struct node *q = p->next;

  while (q != NULL)
  {
    p->next = q->next;
    if (p == NULL)
    {
      break;
    }
    p = p->next;
    q = p->next;
  }
  return head;
}

struct node *reverselinkedlist(struct node *head)
{
  struct node *previous = NULL;
  struct node *current = head;
  struct node *next = current->next;
  while (1)
  {
    current->next = previous;
    previous = current;
    if (next == NULL)
    {
      head = current;
      break;
    }
    current = next;
    next = next->next;
  }

  return head;
}

int main()
{
  struct node *head = (struct node *)malloc(sizeof(struct node));
  struct node *second = (struct node *)malloc(sizeof(struct node));
  struct node *third = (struct node *)malloc(sizeof(struct node));
  struct node *fourth = (struct node *)malloc(sizeof(struct node));

  head->data = 5;
  head->next = second;

  second->data = 6;
  second->next = third;

  third->data = 7;
  third->next = fourth;

  fourth->data = 8;
  fourth->next = NULL;
  printf("the initial linked list is: \n");
  printlinkedlist(head);
  printf("\n");
  head = insertatfirst(head, 2);
  printf("linked list afer adding node at beginning :\n");
  printlinkedlist(head);
  printf("\n");
  head = insertatend(head, 4);
  printf("linked list afer adding node at the end :\n");
  printlinkedlist(head);
  printf("\n");

  int x;
  printf("enter the value of x :");
  scanf("%d", &x);
  printf("\n");
  head = insertafterelement(head, x, 1);
  printf("linked list afer adding node after element x :\n");
  printlinkedlist(head);
  printf("\n");
  int index = countelements(head);
  if (index % 2 == 0)
  {
    index = index / 2;
  }
  else
  {
    index = (index + 1) / 2;
  }
  head = deleteatindex(head, index);
  printf("linked list afer deleting the middle node is :\n");
  printlinkedlist(head);
  printf("\n");

  head = deletelastnode(head);
  printf("linked list afer deleting the last node is :\n");
  printlinkedlist(head);
  printf("\n");
  printf("the elements at even indexes are \n");
  printevenposition(head);
  printf("\n");
  printf("the sum of value of elements at odd indexes is %d \n", sumofoddposition(head));

  printf("\n");
  printf("linked list afer reversing is :\n");
  head = reverselinkedlist(head);
  printlinkedlist(head);

  printf("\n");

  head = deletealternate(head);
  printf("linked list afer deleting the alternate nodes is :\n");
  printlinkedlist(head);

}
