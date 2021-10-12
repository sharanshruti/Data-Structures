#include <stdio.h>
#include <stdlib.h>
//A Balanced Binary Search Tree ;if sum of triplet=0 then true else false
 
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

void convertBSTtoDLL(struct node *root, struct node **head, struct node **tail)
{
    if (root == NULL)
        return;

    if (root->left)
        convertBSTtoDLL(root->left, head, tail);

    root->left = *tail;

    if (*tail)
        (*tail)->right = root;
    else
        *head = root;

    *tail = root;

    if (root->right)
        convertBSTtoDLL(root->right, head, tail);
}

int isPresentInDLL(struct node *head, struct node *tail, int sum)
{
    while (head != tail)
    {
        int curr = head->key + tail->key;
        if (curr == sum)
            return 1;
        else if (curr > sum)
            tail = tail->left;
        else
            head = head->right;
    }
    return 0;
}

int isTripletPresent(struct node *root)
{
    if (root == NULL)
        return 0;

    struct node *head = NULL;
    struct node *tail = NULL;
    convertBSTtoDLL(root, &head, &tail);

    while ((head->right != tail) && (head->key < 0))
    {
        if (isPresentInDLL(head->right, tail, -1 * head->key))
            return 1;
        else
            head = head->right;
    }

    return 0;
}

struct node *newNode(int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = num;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (root->key > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int main()
{
    struct node *root = NULL;

    printf("\nAdd nodes of the tree\n");

    int x = 1, val = 0, y;

    while (x)
    {
        printf("Enter value to insert: ");
        scanf("%d", &val);
        root = insert(root, val);
        printf("\n%d added to the tree successfully!", val);
    y:
        printf("\nEnter 1 to add more values\nEnter 0 to exit\n");
        scanf("%d", &y);
        if (y == 1)
            x = 1;
        else if (y == 0)
            x = 0;
        else
        {
            printf("\nPlease enter a valid command\n");
            goto y;
        }
    }

    if (isTripletPresent(root))
        printf("\nTriplet with sum 0 is Present\n");
    else
        printf("\nTriplet with sum 0 is Not Present\n");
}
