/*************************************************************

    Following is the Binary Tree node structure.

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
vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<BinaryTreeNode<int> *, int> node = q.front();
        mp[node.second] = node.first->data;
        //         cout<<mp[node.second]<<" ";
        if (node.first->left)
        {
            q.push({node.first->left, node.second - 1});
        }
        if (node.first->right)
        {
            q.push({node.first->right, node.second + 1});
        }
        q.pop();
    }
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}
