/************************************************************

Following is the Binary Tree node clas

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include <bits/stdc++.h>
#include <queue>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //     map<vertical,map<level,node> mp;
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        TreeNode<int> *node = tmp.first;
        int level = tmp.second.first;
        int vertical = tmp.second.second;
        mp[vertical][level].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {vertical - 1, level + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {vertical + 1, level + 1}});
        }
    }

    for (auto x : mp)
    {
        for (auto y : x.second)
        {
            for (auto z : y.second)
            {
                ans.push_back(z);
            }
        }
    }
    return ans;
}