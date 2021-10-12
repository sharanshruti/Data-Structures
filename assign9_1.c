#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

int preIndex;

struct node *construct_binary_tree(int in_array[], int pre_array[], int a1, int z1)
{
    if (z1 < a1)
        return NULL;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->key = pre_array[preIndex++];
    int curr_index;
    for (int i = a1; i <= z1; i++)
        if (root->key == in_array[i])
        {
            curr_index = i;
            break;
        }
    root->left = construct_binary_tree(in_array, pre_array, a1, curr_index - 1);
    root->right = construct_binary_tree(in_array, pre_array, curr_index + 1, z1);
    return root;
}

void preorder(struct node *root)
{
    if (!root)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
void inorder(struct node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    int n;
    printf("Enter the number of nodes in the BST \n");
    scanf("%d", &n);
    // int in_array[] = {4, 2, 8, 5, 9, 1, 6, 3, 7},
    //     pre_array[] = {1, 2, 4, 5, 8, 9, 3, 6, 7};

    int in_array[n];
    int pre_array[n];

    printf("Enter the inorder of the BST \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in_array[i]);
    }

    printf("Enter the preorder of the BST \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre_array[i]);
    }

    struct node *root = construct_binary_tree(in_array, pre_array, 0, n - 1);

    // Printing inorder, preorder, postorder traversals of the tree
    printf("\n The inorder traversal of the constructed BST is \n");
    inorder(root);
    printf("\n The preorder traversal of the constructed BST is \n");
    preorder(root);
    printf("\n The postorder traversal of the constructed BST is \n");
    postorder(root);
}