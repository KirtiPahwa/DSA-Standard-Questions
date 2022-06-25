/*************************************************************

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
#include<deque>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(!root){
        return ans;
    }
//     ans.push_back(root->data);
    deque<BinaryTreeNode<int>*> d;
    d.push_back(root);
    int level=0;
    while(!d.empty()){
        int size=d.size();
            while(size-->0){
               if(level%2==0){
                   BinaryTreeNode<int>*node=d.front();
                   ans.push_back(node->data);
                   d.pop_front();
                   if(node->left){
                       d.push_back(node->left);
                   }
                   if(node->right){
                       d.push_back(node->right);
                   }
                   
            }else{
                    BinaryTreeNode<int>*node=d.back();
                   ans.push_back(node->data);
                   d.pop_back();
                   if(node->right){
                       d.push_front(node->right);
                   }
                   if(node->left){
                       d.push_front(node->left);
                   }
                   
               }
        }
        level^=1;
    }
}







// Second approach:

/*************************************************************

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
#include <stack>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(!root){
        return ans;
    }
    bool level=1;
    queue<BinaryTreeNode<int>*>q;
    queue<BinaryTreeNode<int>*>temp;
    
    q.push(root); 
    stack<BinaryTreeNode<int>*>s;
    ans.push_back(root->data);
    while(!q.empty()){
        int size=q.size();
        while(size-->0){
            BinaryTreeNode<int>* front=q.front();
            if(front->left){
            q.push(front->left);
                if(level==1){
            s.push(front->left);
                }else{
                    ans.push_back(front->left->data);
                }
            }
            if(front->right){
            q.push(front->right);
                if(level==1){
            s.push(front->right);
                }else{
                    ans.push_back(front->right->data);
                }
            }
            q.pop();
        }
            if(level==1){
                while(!s.empty()){
            BinaryTreeNode<int>* front=s.top();
                    ans.push_back(front->data);
                    s.pop();
                }
        }
        level^=1;
    }
}
