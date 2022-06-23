/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    if(root==NULL){
        return ans;
    }
    while(!q.empty()){
        BinaryTreeNode<int>* f=q.front();
        ans.push_back(f->val);
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
       q.pop();
    }
    return ans;
}