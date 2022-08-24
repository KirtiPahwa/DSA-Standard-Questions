/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool helper(BinaryTreeNode<int> *root, int lbound, int rbound)
{
    if (!root)
    {
        return 1;
    }
    if (root->data < rbound && root->data > lbound && helper(root->left, lbound, root->data) && helper(root->right, root->data, rbound))
    {
        return 1;
    }
    return 0;
}
bool validateBST(BinaryTreeNode<int> *root)
{
    return helper(root, INT_MIN, INT_MAX);
}