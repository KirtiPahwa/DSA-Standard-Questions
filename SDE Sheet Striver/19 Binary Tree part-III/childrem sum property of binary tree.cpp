/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void helper(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    int l = 0, r = 0;
    if (root->left)
    {
        l = root->left->data;
    }
    if (root->right)
    {
        r = root->right->data;
    }
    if (l + r < root->data)
    {
        if (root->left)
            root->left->data = root->data - r;
        else if (root->right)
            root->right->data = root->data - l;
    }
    else if (l + r < root->data)
    {
        root->data = l + r;
    }
    helper(root->left);
    helper(root->right);
    l = 0, r = 0;
    if (root->left)
    {
        l = root->left->data;
    }
    if (root->right)
    {
        r = root->right->data;
    }
    if (root->left || root->right)
        root->data = l + r;
    //     cout<<root->data<<endl;
}

void changeTree(BinaryTreeNode<int> *root)
{
    helper(root);
    helper(root);
    helper(root);
}