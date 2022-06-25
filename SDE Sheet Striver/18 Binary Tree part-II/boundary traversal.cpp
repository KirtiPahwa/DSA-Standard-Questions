/************************************************************
My recursive Code
    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void leftTraversal(vector<int>& ans,TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    if(!root->left && root->right==NULL){
        return;
    }
   else if(root->left){
    ans.push_back(root->data);
    leftTraversal(ans,root->left);
    }else{
    ans.push_back(root->data);
    leftTraversal(ans,root->right);
   }
    
    
}
void leafTraversal(vector<int>&ans,TreeNode<int>* root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return ;
    }else{
    leafTraversal(ans,root->left);
    leafTraversal(ans,root->right);
}}
void rightTraversal(vector<int>&ans,TreeNode<int>*root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        return;
    }else if(root->right){
    rightTraversal(ans,root->right); 
        ans.push_back(root->data);

    }else{
    rightTraversal(ans,root->left);
                ans.push_back(root->data);

    }
    
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!root){
        return ans;
    }
//     left traversal
    if(root->left){ 
    leftTraversal(ans,root);
    }else{
        ans.push_back(root->data);
    }
//     ans.pop_back();
//     leaf traversal
    if(root->left || root->right)
    leafTraversal(ans,root);
//     ans.pop_back();
//     right Traversal
    if(root->right)
    rightTraversal(ans,root->right);
   
    
    
    return ans;
    
}


// striver iterative code for left and right boundaries and for leaf recursion is used




#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}

