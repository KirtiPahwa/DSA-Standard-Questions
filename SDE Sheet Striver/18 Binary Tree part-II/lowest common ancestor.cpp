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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(!root || root->data==x || root->data==y){
        if(!root){
            return -1;
        }else{
            return root->data;
        }
    }	
    int l=lowestCommonAncestor(root->left,x,y);
    int r=lowestCommonAncestor(root->right,x,y);
    if(l==-1){
        return r;
    }
    if(r==-1){
        return l;
    }
    return root->data;
    
}