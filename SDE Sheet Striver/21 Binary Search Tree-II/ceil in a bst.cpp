/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    BinaryTreeNode<int> *temp=node;
    int ans=-1;
    while(temp){
        if(temp->data==x){
            ans=temp->data;
           break;
        }
        else 
            if(temp->data>x){
            ans=temp->data;
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return ans;
    
    
    
    
    
    
    
    
}