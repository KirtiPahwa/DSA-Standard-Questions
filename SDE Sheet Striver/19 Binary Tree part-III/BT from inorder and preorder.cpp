/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <unordered_map>
TreeNode<int> *func(vector<int> &inorder, vector<int> &preorder, int l, int r, int &key, unordered_map<int, int> &mp)
{
    if (l > r)
    {
        return NULL;
    }
    int index = mp[preorder[key]];
    TreeNode<int> *node = new TreeNode<int>(inorder[index]);
    key++;

    if (l == r)
    {
        return node;
    }
    node->left = func(inorder, preorder, l, index - 1, (key), mp);
    node->right = func(inorder, preorder, index + 1, r, (key), mp);
    return node;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int k = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return func(inorder, preorder, 0, inorder.size() - 1, k, mp);
}