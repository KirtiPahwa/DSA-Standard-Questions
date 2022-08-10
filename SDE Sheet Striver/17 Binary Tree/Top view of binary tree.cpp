/************************************************************

    Following is the TreeNode class structure:

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
#include <queue>
#include <map>
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> tempans;
    //     queue<node,vertical>
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> tmp = q.front();
        cout << tmp.first->val << endl;
        if (tempans.find(tmp.first->val) = tempans.end())
        {
            tempans[tmp.second] = tmp.first->val;
        }
        if ((tmp.first)->left)
        {
            q.push({(tmp.first)->left, tmp.second - 1});
        }
        if ((tmp.first)->right)
        {
            q.push({(tmp.first)->right, tmp.second + 1});
        }
        q.pop();
    }
    for (auto x : tempans)
    {
        //         cout<<x.second<<" ";
        ans.push_back(x.second);
    }
    return ans;
}