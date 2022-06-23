/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    
    TreeNode* curr=root;
    while(curr){
        if(curr->left){
//             right most child
            TreeNode* temp=curr->left;
            while(temp->right && temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right==curr){
                ans.push_back(curr->data);
                temp->right=NULL;
                curr=curr->right;
            }else{
                temp->right=curr;
                curr=curr->left;
            }
        }else{
            ans.push_back(curr->data);
            curr=curr->right;
        }
    }
    return ans;
}  