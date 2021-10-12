
#include <stdio.h>
#include <stdlib.h>
//Hashing: Collision resolved using chaining

typedef struct node_t *Node;
typedef struct node_t node;

struct node_t
{
    int data;
    Node next;
};

Node newNode(int data1, Node next)
{

    Node node = (Node)calloc(1, sizeof(node));
    node->data = data1;

    node->next = next;
    return node;
}

void addAtBegining(Node *pList, int data1)
{
    *pList = newNode(data1, *pList);
    return;
}

Node addAtLast(Node *pList, int data1)
{

    if (*pList == NULL)
    {
        addAtBegining(pList, data1);
        return *pList;
    }
    Node node = *pList;

    while (node->next)
        node = node->next;

    node->next = newNode(data1, NULL);
    return *pList;
}

int hash_function(int key, int size)
{
    return key % size;
}

void printList(Node List)
{
    while (List)
    {
        printf("%d ", List->data);

        List = List->next;
    }
}

void traversing(Node hash_table[], int i)
{
    if (hash_table[i] == NULL)
        return;
    else
    {

        printf("hash table[%d] = ", i);
        printList(hash_table[i]);
        printf("\n");

        return;
    }
}

int removeAtBegining(Node *pList)
{

    Node node = *pList;
    int data1 = node->data;

    *pList = (*pList)->next;
    free(node);

    return data1;
}

int removeAt(Node *pList, int location)
{
    int data;
    if (location == 1)
    {
        int l = removeAtBegining(pList);
        return l;
    }
    Node node = *pList;
    Node node2 = *pList;
    while (node && location >= 2)
    {
        node2 = node;
        node = node->next;
        location--;
    }
    if (node->next == NULL)
    {
        node2->next = NULL;
    }
    else
    {
        node2->next = node->next;
        data = node->data;
        free(node);
        node = NULL;
    }

    return data;
}

int search(Node hash_table[], int key, int i)
{
    Node x = hash_table[i];
    int l = 0;
    while (x != NULL)
    {
        l++;
        if (x->data == key)
        {

            printf("the number %d is present in hash table[%d]\n", key, i);
            return l;
        }
        else
            x = x->next;
    }
    printf("the number %d is not present in the hash table\n", key);
    return l;
}

int main()
{

    int size, i, m;
    printf("enter the size of the hash table\n");
    scanf("%d", &size);

    Node hash_table[size];
    for (i = 0; i < size; i++)
    {

        hash_table[i] = NULL;
    }

    int a[100];
    for (i = 0; i < 100; i++)
    {

        printf("enter the number for insertion otherwise enter 0 if u want to stop\n");
        scanf("%d", &a[i]);
        if (a[i] == 0)
            break;
    }

    int n = i;
    for (i = 0; i < n; i++)
    {
        int key = a[i];

        int index = hash_function(key, size);
        hash_table[index] = addAtLast(&hash_table[index], key);
    }

    for (i = 0; i < size; i++)
    {
        traversing(hash_table, i);
    }

    printf("enter the number for searching\n");
    scanf("%d", &m);
    int index = hash_function(m, size);
    int s = search(hash_table, m, index);

    printf("enter the number for deletion\n");
    scanf("%d", &m);
    index = hash_function(m, size);
    s = search(hash_table, m, index);
    if (s)
    {
        printf("%d\n", s);
        removeAt(&hash_table[index], s);
        printf("hi\n");
    }

    for (i = 0; i < size; i++)
    {
        traversing(hash_table, i);
    }
}
