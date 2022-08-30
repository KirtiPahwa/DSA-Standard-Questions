/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int helper(TreeNode<int>*root,int& k){
if(!root){
        return -1;
    }
    int r=helper(root->left,k);
    if(r!=-1){
        return r;
    }
    k--;
    if(k==1){
        return root->data;
    }
    int l=helper(root->right,k);
    if(l!=-1){
        return l;
    }
    return -1;

}
int kthSmallest(TreeNode<int> *root, int k)
{
	return helper(root,++k);
}