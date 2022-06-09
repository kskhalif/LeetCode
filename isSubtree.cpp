struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* root, TreeNode* subRoot, bool prev_nodes_equal)
{
    if (!root && !subRoot) { return true; }
    if (root && !subRoot) { return false; }
    if (!root && subRoot) { return false; }

    if (root->val == subRoot->val && 
        helper(root->left, subRoot->left, true) && 
        helper(root->right, subRoot->right, true)) 
    { 
        return true; 
    }
    else if (prev_nodes_equal) 
    { 
        return false; 
    }
    else 
    { 
        return (helper(root->left, subRoot, false) ||
                helper(root->right, subRoot, false)); 
    }
}

bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
    return helper(root, subRoot, false);
}