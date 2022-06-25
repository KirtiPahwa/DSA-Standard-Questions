

/**Approach:Optimised***********************************************************
 
    Following is the Binary Tree node structure

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
int helper(BinaryTreeNode<int>* root){
    if(!root){
        return 0;
    }
    int lh=helper(root->left);
    int rh=helper(root->right);
    if(lh>-1 && rh>-1){
       if(abs(rh-lh)<=1){
           return max(lh,rh)+1;
       }
    }
    return -1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(helper(root)==-1){
        return 0;
    }
    return 1;
    
    
}