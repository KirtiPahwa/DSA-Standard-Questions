// Type 1:code studio(easy approach)

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
// #include<queue>
// int getMaxWidth(TreeNode<int> *root)
// {
//     if(!root){
//         return 0;
//     }
//     queue<TreeNode<int> *>q;
//     int ans=1;
//     q.push(root);
//     while(!q.empty()){
//         int size=q.size();
//         int levelSize=0;
//         while(size--){
//             TreeNode<int> * node=q.front();
//             q.pop();
//             if(node->left){
//                 q.push(node->left);
//             }
//             if(node->right){
//                 q.push(node->right);
//             }
//             levelSize++;
//         }
//         ans=max(ans,levelSize);
//     }
//    return ans;
//     }

// Type2:Leetcode(difficult)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        long long mx = 1;
        while (!q.empty())
        {
            int size = q.size();
            long long l = INT_MAX;
            long long currId = q.front().second;
            long long r = -2;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front().first;
                long long id = q.front().second - currId;
                q.pop();
                if (curr->left)
                {
                    l = min(l, 2 * id + 1);
                    r = max(r, 2 * id + 1);
                }
                if (curr->right)
                {
                    l = min(l, 2 * id + 2);
                    r = max(r, 2 * id + 2);
                }

                if (curr->left)
                {
                    q.push({curr->left, 2 * id + 1});
                }
                if (curr->right)
                {
                    q.push({curr->right, 2 * id + 2});
                }
            }
            if (l != -1 && r != -1)
            {
                mx = max(mx, r - l + 1);

                // cout<<"flag "<<l<<" "<<r<<" "<<mx<<endl;
            }
        }
        return mx;
    }
};