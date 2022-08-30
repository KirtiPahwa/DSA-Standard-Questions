/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
#include <unordered_map>
TreeNode<int> *helper(vector<int> &postorder, vector<int> &inorder, int l, int r, int &key, unordered_map<int, int> &mp)
{
    if (l > r)
    {
        return NULL;
    }
    int index = mp[postorder[key]];
    TreeNode<int> *node = new TreeNode<int>(postorder[key--]);
    if (l == r)
    {
        return node;
    }
    node->right = helper(postorder, inorder, index + 1, r, key, mp);
    node->left = helper(postorder, inorder, l, index - 1, key, mp);
    return node;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    unordered_map<int, int> mp; 
    for (int i = 0; i < inOrder.size(); i++)
    {
        mp[inOrder[i]] = i;
    }
    int key = inOrder.size() - 1;
    return helper(postOrder, inOrder, 0, inOrder.size() - 1, key, mp);
}
