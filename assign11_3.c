#include <stdio.h>
#include <stdlib.h>
//create mirror of binary tree

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void mirror(struct Node *node)
{
    if (node == NULL)
        return;
    else
    {
        struct Node *temp;

        mirror(node->left);
        mirror(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void inOrder(struct Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

struct Node *newNode(int num)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int main()
{

    struct Node *root = NULL;

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

    printf("Inorder traversal of the constructed tree is \n");

    inOrder(root);

    mirror(root);

    printf("\nInorder traversal of the mirror tree is \n");

    inOrder(root);
}
