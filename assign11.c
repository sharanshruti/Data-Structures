using System;
 
// C#  program to convert BST to binary tree 
// such that sum of all smaller keys is added 
// to every key
 
public class Node
{
 
    public int data;
    public Node left, right;
 
    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}
 
public class Sum
{
 
    public int addvalue = 0;
}
 
public class BSTtoBinaryTree
{
 
    public static Node root;
    public Sum add = new Sum();
 
    // A recursive function that traverses 
    // the given BST in inorder and for every 
    // key, adds all smaller keys to it
    public virtual void addSmallerUtil(Node node, Sum sum)
    {
 
        // Base Case
        if (node == null)
        {
            return;
        }
 
        // Recur for left subtree first so that
        //  sum of all smaller Nodes is stored at sum
        addSmallerUtil(node.left, sum);
 
        // Update the value at sum
        sum.addvalue = sum.addvalue + node.data;
 
        // Update key of this Node
        node.data = sum.addvalue;
 
        // Recur for right subtree so that the 
        // updated sum is added to greater Nodes
        addSmallerUtil(node.right, sum);
    }
 
    // A wrapper over addSmallerUtil().  It 
    // initializes addvalue and calls
    // addSmallerUtil() to recursively update 
    // and use value of addvalue
    public virtual Node addSmaller(Node node)
    {
        addSmallerUtil(node, add);
        return node;
    }
 
    // A utility function to print inorder
    // traversal of Binary Tree
    public virtual void printInorder(Node node)
    {
        if (node == null)
        {
            return;
        }
        printInorder(node.left);
        Console.Write(node.data + " ");
        printInorder(node.right);
    }
 
    // Driver program to test the above functions
    public static void Main(string[] args)
    {
        BSTtoBinaryTree tree = new BSTtoBinaryTree();
        BSTtoBinaryTree.root = new Node(9);
        BSTtoBinaryTree.root.left = new Node(6);
        BSTtoBinaryTree.root.right = new Node(15);
 
        Console.WriteLine("Original BST");
        tree.printInorder(root);
        Node Node = tree.addSmaller(root);
        Console.WriteLine("");
        Console.WriteLine("BST To Binary Tree");
        tree.printInorder(Node);
    }
}