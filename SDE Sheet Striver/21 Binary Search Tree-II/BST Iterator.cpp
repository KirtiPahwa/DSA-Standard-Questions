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
static int i = 0;
class BSTiterator
{
public:
    vector<int> v;
    void inorder(TreeNode<int> *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
    BSTiterator(TreeNode<int> *root)
    {
        i = 0;
        inorder(root);
    }

    int next()
    {
        return v[i++];
    }

    bool hasNext()
    {
        if (i < v.size())
        {
            return true;
        }
        return false;
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/