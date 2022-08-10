#include<bits/stdc++.h>
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool s(TreeNode* node, int key,vector<int>&v){
    if(!node){
        return 0;
    }
    if(node->val==key){
        v.push_back(node->val);
        return 1;
    }
    if(s(node->left,key,v)){
        v.push_back(node->val);
        return 1;
    }
    if(s(node->right,key,v)){
        v.push_back(node->val);
        return 1;
    }
    return 0;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    s(A,B,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
