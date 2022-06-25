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
int height(TreeNode<int> *root){
    if(!root){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
void diameter(TreeNode<int>*root,int& d){
    if(!root){
        return;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    d=max(d,lh+rh);
    diameter(root->left,d);
    diameter(root->right,d);
    
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int d=0;
    diameter(root,d);
    return d;
}




// Approach2:optimised





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

int diameter(TreeNode<int>*root,int& d){
    if(!root){
        return 0;
    }
    int lh=diameter(root->left,d);
    int rh=diameter(root->right,d);
    d=max(d,lh+rh);
    return (max(lh,rh)+1);
    
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int d=0;
    diameter(root,d);
    return d;
}

