/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> *root, int x)
{
    TreeNode<int> *ans = root;
    while (root)
    {
        if (root->val == x)
        {
            return root->val;
        }
        else if (root->val > x)
        {
            root = root->left;
        }
        else
        {
            ans = root;
            root = root->right;
        }
    }
    return ans->val;
}