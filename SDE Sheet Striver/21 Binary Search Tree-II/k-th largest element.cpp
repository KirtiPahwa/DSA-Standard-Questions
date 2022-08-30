/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
int helper(TreeNode<int> *root, int &k)
{
    if (!root)
    {
        return -1;
    }
    int r = helper(root->right, k);
    if (r != -1)
    {
        return r;
    }
    if (--k == 1)
    {
        return root->data;
    }
    int l = helper(root->left, k);
    if (l != -1)
    {
        return l;
    }
    return -1;
}
int KthLargestNumber(TreeNode<int> *root, int k)
{
    return helper(root, (++k));
}
