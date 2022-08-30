/************************************************************

    Following is the Binary Tree node structure

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
class values
{
public:
    int size;
    int mx;
    int mn;
    values(int size, int mx, int mn)
    {
        this->size = size;
        this->mx = mx;
        this->mn = mn;
    }
};
values helper(TreeNode<int> *root)
{
    if (!root)
    {
        return values(0, INT_MIN, INT_MAX);
    }
    values l = helper(root->left);
    values r = helper(root->right);
    values v(0, 0, 0);
    if (root->data < r.mn && root->data > l.mx)
    {
        v.size = r.size + 1 + l.size;
        v.mn = min(root->data, l.mn);
        v.mx = max(r.mx, root->data);
    }
    else
    {
        v.size = max(r.size, l.size);
        v.mx = INT_MAX;
        v.mn = INT_MIN;
    }
    return v;
}
int largestBST(TreeNode<int> *root)
{
    return helper(root).size;
}
