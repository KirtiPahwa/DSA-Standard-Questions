/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <bits/stdc++.h>
long long int func(TreeNode<int>* root,long long int &mx){
    if(!root){
        return 0;
    }
    long long  int left=func(root->left,mx);
    long long int right=func(root->right,mx);
    mx=max(mx,left+right+root->val);
//     cout<<root->val<<" has maximum "<<mx<<endl;
//     cout<<root->val<<" has return maximum "<<max(left,right)+root->val<<endl;
    return max(left,right)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root || (!root->left || !root->right)){
        return -1;
    }
   long long int mx=INT_MIN;
    func(root,mx);
    return mx;
    
}