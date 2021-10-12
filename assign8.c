#include <stdio.h>
#include <stdlib.h>
//Implementing operations in Binary Search Tree

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int found = 0;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root;

void iter_insert(int val)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;

    if (root == NULL)
    {
        root = new;
        return;
    }

    struct Node *temp = root, *prev;
    {
        prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            if (val < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (val < prev->data)
        {
            prev->left = new;
        }
        else
        {
            prev->right = new;
        }
    }
}

struct Node *rec_insert(struct Node *root, int val)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;

    if (root == NULL)
    {
        root = new;
        return root;
    }

    if (val < root->data)
        root->left = rec_insert(root->left, val);
    else if (val > root->data)
        root->right = rec_insert(root->right, val);
    return root;
}
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node *maxValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->right != NULL)
        current = current->right;

    return current;
}

struct Node *rec_deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = rec_deleteNode(root->left, data);
    else if (data > root->data)
        root->right = rec_deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minValueNode(root->right);

        root->data = temp->data;
        root->right = rec_deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node *iter_deleteNode(struct Node *root, int val)
{
    if (root == NULL)
        printf("Empty BST\n");
    struct Node *temp = root, *temp2 = NULL;
    int flag = 0, flag_2 = -1;
    while (temp && (!flag))
    {
        if (temp->data == val)
        {
            flag = 1;
            if (!(temp->left || temp->right))
            {
                if (!temp2)
                    return NULL;
                else
                {
                    free(temp);
                    if (flag_2)
                        temp2->right = NULL;
                    else
                        temp2->left = NULL;
                }
            }
            else if (!(temp->left && temp->right))
            {
                if (temp->left)
                {
                    if (!temp2)
                        return temp->left;
                    if (flag_2)
                        temp2->right = temp->left;
                    else
                        temp2->left = temp->left;
                    free(temp);
                }
                else if (temp->right)
                {
                    if (!temp2)
                        return temp->right;
                    if (flag_2)
                        temp2->right = temp->right;
                    else
                        temp2->left = temp->right;
                    free(temp);
                }
            }
            else
            {
                struct Node *beta = temp->right, *alpha = temp;
                while (beta->left)
                {
                    alpha = beta;
                    beta = beta->left;
                }
                if (alpha == temp)
                {
                    beta->left = alpha->left;
                    free(temp);
                    if (!temp2)
                        return beta;
                    if (flag_2)
                        temp2->right = beta;
                    else
                        temp2->left = beta;
                }
                else
                {
                    alpha->left = NULL;
                    beta->left = temp->left;
                    beta->right = temp->right;
                    free(temp);
                    if (!temp2)
                        return beta;
                    if (flag_2)
                        temp2->right = beta;
                    else
                        temp2->left = beta;
                }
            }
        }
        else if (temp->data > val)
        {
            temp2 = temp;
            temp = temp->left;
            flag_2 = 0;
        }
        else if (temp->data < val)
        {
            temp2 = temp;
            temp = temp->right;
            flag_2 = 1;
        }
    }
    if (flag != 1)
        printf("Element not found\n");
    return root;
}

void inorder(struct Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void Search(struct Node *root, int val)
{
    if (root == NULL)
    {
        found = 0;
        return;
    }
    if (root->data == val)
    {
        printf("val found\n\n");
        found = 1;
        return;
    }
    else
    {
        if (val > root->data)
            Search(root->right, val);
        if (val < root->data)
            Search(root->left, val);
    }
}
struct Node *inorderSuccessor(struct Node *root, int val)
{

    struct Node *successor = NULL;
    struct Node *current = root;
    if (!root)
        return NULL;

    while (current && current->data != val)
    {
        if (current->data > val)
        {
            successor = current;
            current = current->left;
        }
        else
            current = current->right;
    }
    if (current && current->right)
    {
        successor = minValueNode(current->right);
    }

    return successor;
}

struct Node *inorderPredecessor(struct Node *root, int val)
{

    struct Node *predecessor = NULL;
    struct Node *current = root;

    if (!root)
        return NULL;

    while (current && current->data != val)
    {
        if (current->data > val)
        {
            current = current->left;
        }
        else
        {
            predecessor = current;
            current = current->right;
        }
    }
    if (current && current->left)
    {
        predecessor = maxValueNode(current->left);
    }
    return predecessor;
}

int findHeight(struct Node *root, int val, int *height)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftHeight = findHeight(root->left, val, height);

    int rightHeight = findHeight(root->right, val, height);

    int ans = MAX(leftHeight, rightHeight) + 1;

    if (root->data == val)
        *height = ans;

    return ans;
}

int findDepth(struct Node *root, int val)
{
    if (root == NULL)
        return -1;

    int dist = -1;
    if ((root->data == val) || (dist = findDepth(root->left, val)) >= 0 || (dist = findDepth(root->right, val)) >= 0)
        return dist + 1;

    return dist;
}

void main()
{
    root = NULL;
    printf("Inserting Nodes\n");
    iter_insert(50);
    rec_insert(root, 30);
    iter_insert(20);
    rec_insert(root, 40);
    iter_insert(70);
    rec_insert(root, 60);
    iter_insert(80);

    printf("Inorder Traversal\n");
    inorder(root);
    printf("\n\n");
    printf("Preorder Traversal\n");
    preorder(root);
    printf("\n\n");
    printf("Postorder Traversal\n");
    postorder(root);
    printf("\n\n");

    printf("Search for 60\n");
    Search(root, 60);
    if (found == 0)
        printf("Key not found\n\n");

    printf("Search for 10\n");
    Search(root, 10);
    if (found == 0)
        printf("Key not found\n\n");

    printf("Max key in the Tree\n");
    printf("%d\n\n", maxValueNode(root)->data);

    printf("Min key in the Tree\n");
    printf("%d\n\n", minValueNode(root)->data);

    printf("Finding successor of 40\n");
    printf("%d\n\n", inorderSuccessor(root, 40)->data);

    printf("Finding successor of 75\n");
    printf("%d\n\n", inorderSuccessor(root, 70)->data);

    printf("Finding predecessor of 30\n");
    printf("%d\n\n", inorderPredecessor(root, 30)->data);

    printf("Finding predecessor of 62\n");
    printf("%d\n\n", inorderPredecessor(root, 62)->data);

    int height = -1;
    printf("Height of 50\n");
    findHeight(root, 50, &height);
    printf("%d\n\n", height);

    printf("Depth of 80\n");
    printf("%d\n\n", findDepth(root, 80));

    printf("Removing Key 30\n");
    rec_deleteNode(root, 30);
    printf("Inorder Traversal\n");
    inorder(root);
    printf("\n\n");

    printf("Removing Key 60\n");
    iter_deleteNode(root, 60);
    printf("Inorder Traversal\n");
    inorder(root);
}
