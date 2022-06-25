/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1!=NULL ^ root2!=NULL){
        return false;
    }else if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1->data!=root2->data){
        return false;
    }
    bool lf=identicalTrees(root1->left,root2->left);
    if(!lf){
        return false;
    }
    bool rt=identicalTrees(root1->right,root2->right);
    if(!rt){
        return false;
    }
    return true;
}