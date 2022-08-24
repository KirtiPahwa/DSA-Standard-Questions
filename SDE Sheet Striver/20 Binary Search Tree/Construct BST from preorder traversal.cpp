/*
    Time Complexity: O(N^2)
    Space Complexity: O(N^2)

    Where N is the number nodes in the tree.
*/

// Utility function to get the the tree from preOrder traversal
TreeNode<int> *util(vector<int> preOrder)
{

    // If the length of the preOrder traversal is 0 return NULL.
    if (preOrder.size() == 0)
    {
        return NULL;
    }

    // Set the root as the first element of the preOrder traversal.
    TreeNode<int> *root = new TreeNode<int>(preOrder[0]);

    // All the nodes smaller than the root will go in the left subtree.
    vector<int> leftPreOrder;
    for (int i = 1; i < preOrder.size(); i++)
    {
        if (preOrder[i] < preOrder[0])
        {
            leftPreOrder.push_back(preOrder[i]);
        }
    }

    // All the nodes greater than the root will go in the right subtree.
    vector<int> rightPreOrder;
    for (int i = 1; i < preOrder.size(); i++)
    {
        if (preOrder[i] > preOrder[0])
        {
            rightPreOrder.push_back(preOrder[i]);
        }
    }

    // Call the util function on left and right subtree of the root.
    root->left = util(leftPreOrder);
    root->right = util(rightPreOrder);

    // Return the root.
    return root;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{

    // Return the util function.
    return util(preOrder);
}