/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

//         ~BinaryTreeNode() {
//             if (left)
//             {
//                 delete left;
//             }
//             if (right)
//             {
//                 delete right;
//             }
//         }
//     };

// *************************************************************/
int inorderPred(BinaryTreeNode<int> *root, int key)
{
    int ans = -1;
    while (root)
    {
        if (root->data >= key)
        {
            root = root->left;
        }
        else
        {
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}
int inordersuccessor(BinaryTreeNode<int> *root, int key)
{
    int ans = -1;
    while (root)
    {
        if (root->data <= key)
        {
            root = root->right;
        }
        else
        {
            ans = root->data;
            root = root->left;
        }
    }
    return ans;
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    pair<int, int> p;
    int found = inorderPred(root, key);
    int found1 = inordersuccessor(root, key);
    p.first = found;
    p.second = found1;
    return p;
}
