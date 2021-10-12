#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *insert_rec(struct node *root, int key)
{
    if (root && root->key == key)
        printf("Key already present. Duplicates not allowed!!\n");
    else if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
    }
    else if (root->key > key)
        root->left = insert_rec(root->left, key);
    else
        root->right = insert_rec(root->right, key);
    return root;
}

void inorder(struct node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
void preorder(struct node *root)
{
    if (!root)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void addSmallerUtil(struct node *root, int *sum_ptr)
{
    if (root == NULL)
        return;

    addSmallerUtil(root->left, sum_ptr);

    *sum_ptr = *sum_ptr + root->key;

    root->key = *sum_ptr;

    addSmallerUtil(root->right, sum_ptr);

}

void addSmaller(struct node *root)
{
    int sum = 0;
    addSmallerUtil(root, &sum);
    
}

int main()
{
    struct node *root = NULL, *temp;
    int a, b, p, q;
repeat:
    printf("\n\nENTER THE CHOICE :\n1.Insert  \n2.Convert all keys to key + sum of all smaller keys  \n3.Inorder  \n4.Preorder  \n5.Postorder  \n6.Exit\n\n");
    scanf("%d", &a);
    switch (a)
    {

    case 1:
        printf("Enter the key to be inserted : ");
        scanf("%d", &p);
        root = insert_rec(root, p);
        goto repeat;

    case 2:
        addSmaller(root);
        inorder(root);
        goto repeat;

    case 3:
        printf("INORDER TRAVERSAL: \n");
        inorder(root);
        goto repeat;

    case 4:
        printf("PREORDER TRAVERSAL: \n");
        preorder(root);
        goto repeat;

    case 5:
        printf("POSTORDER TRAVERSAL: \n");
        postorder(root);
        goto repeat;

    case 6:
        break;
    default:
        printf("\nEnter valid choice!!\n");
        goto repeat;
    }

}