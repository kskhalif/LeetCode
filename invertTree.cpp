#include <vector>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Iterative Solution */
TreeNode* invertTree(TreeNode* root)
{
    std::vector<TreeNode*> stack;
    TreeNode* curr = root;
    TreeNode* temp = nullptr;
    stack.push_back(curr);
    while (!stack.empty())
    {
        curr = stack.back();
        stack.pop_back();
        if (curr)
        {
            temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            stack.push_back(curr->right);
            stack.push_back(curr->left);
        }
    }
    return root;
}

/* Recursive Solution */
TreeNode* invertTree(TreeNode* root)
{
    if (!root) { return nullptr; }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}