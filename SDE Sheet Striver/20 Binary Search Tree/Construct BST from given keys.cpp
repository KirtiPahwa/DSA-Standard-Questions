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
TreeNode<int> *helper(vector<int> &arr, int l, int r, int n)
{
    if (l > r)
    {
        return NULL;
    }
    else
    {
        int mid = (l + r) / 2;
        TreeNode<int> *temp = new TreeNode<int>(arr[mid]);
        temp->left = helper(arr, l, mid - 1, n);
        temp->right = helper(arr, mid + 1, r, n);
        return temp;
    }
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return helper(arr, 0, n - 1, n);
}