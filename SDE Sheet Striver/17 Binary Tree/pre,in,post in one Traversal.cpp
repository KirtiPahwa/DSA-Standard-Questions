/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void traversal(BinaryTreeNode<int> *root, vector<int> &pre, vector<int> &in, vector<int> &pos)
{
    if (!root)
    {
        return;
    }
    pre.push_back(root->data);
    traversal(root->left, pre, in, pos);
    in.push_back(root->data);
    traversal(root->right, pre, in, pos);
    pos.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    vector<int> pre;
    vector<int> in;
    vector<int> pos;
    traversal(root, pre, in, pos);
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
}