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
enum Direction { Right, Left };
std::vector<int> inorderTraversal(TreeNode* root)
{
    if (!root) { return { }; }
    std::vector<TreeNode*> stack;
    std::vector<int> answer;
    TreeNode* curr = root;
    Direction dir = Right;
    stack.push_back(curr);
    while (!stack.empty())
    {
        if (dir == Right)
        {
            while (curr->left)
            { 
                stack.push_back(curr->left);
                curr = curr->left;
            }
            dir = Left;
        }
        answer.push_back(curr->val);
        stack.pop_back();
        if (curr->right)
        {
            stack.push_back(curr->right);
            curr = curr->right;
            dir = Right;
        }
        else if (!stack.empty())
        {
            curr = stack.back();
            answer.push_back(curr->val);
            stack.pop_back();
            if (curr->right)
            {
                stack.push_back(curr->right);
                curr = curr->right;
                dir = Right;
            }
            else if (!stack.empty()) { curr = stack.back(); }
        }
    }
    return answer;
}

/* Recursive Solution */
void helper(std::vector<int>& vec, TreeNode* node)
{
    if (node->left) { helper(vec, node->left); }
    vec.push_back(node->val);
    if (node->right) { helper(vec, node->right); }
}
std::vector<int> inorderTraversal(TreeNode* root) 
{
    if (!root) { return { }; }
    std::vector<int> answer;
    helper(answer, root);
    return answer;
}