bool helper(BinaryTreeNode<int>*root1,BinaryTreeNode<int>*root2){
    if(!root1 && !root2){
        return 1;
    }else if(!root1 || !root2){
        return 0;
    }
    if(root1->data==root2->data && helper(root1->left,root2->right) && helper(root1->right,root2->left) ){
        return 1;
    }
    return 0;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root){return -1;}
    return helper(root->left,root->right);
    
    
          
}