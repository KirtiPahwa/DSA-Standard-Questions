#include <queue>
void connectNodes(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            //     BinaryTreeNode<int>* temp=q.front();
            BinaryTreeNode<int> *top = q.front();
            q.pop();
            if (i == size - 1)
            {
                top->next = NULL;
            }
            else
            {
                top->next = q.front();
            }
            if (top->left)
            {
                q.push(top->left);
            }
            if (top->right)
            {
                q.push(top->right);
            }
        }
    }
}