struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* p, TreeNode* q)
{
    if (!p && !q) { return true; }
    if (p && !q) { return false; }
    if (!p && q) { return false; }
    if (p->val != q->val) { return false; }
    if (helper(p->left, q->right) &&
        helper(p->right, q->left)) { return true; }
    return false;
}

bool isSymmetric(TreeNode* root)
{
    if (!root) { return true;}
    return helper(root->left, root->right);
}