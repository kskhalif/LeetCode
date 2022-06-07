struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (!p && !q) { return true; }
    if (p && !q) { return false; }
    if (!p && q) { return false; }
    if (p->val != q->val) { return false; }

    bool left_side = isSameTree(p->left, q->left);
    bool right_side = isSameTree(p->right, q->right);

    if (left_side && right_side) { return true; }
    else { return false; }
}