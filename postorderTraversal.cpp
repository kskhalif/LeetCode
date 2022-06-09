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
struct POT
{
    TreeNode* ptr;
    bool checked_left;
    bool checked_right;
    POT() : ptr(nullptr), checked_left(false), checked_right(false) {}
    POT(TreeNode* p, bool l, bool r) : ptr(p), checked_left(l), checked_right(r) {}
};

std::vector<int> postorderTraversal(TreeNode* root)
{
    if (!root) { return { }; }
    std::vector<POT> stack;
    std::vector<int> answer;
    POT temp(root, false, false);
    TreeNode* curr = root;
    stack.push_back(temp);
    while (!stack.empty())
    {
        if (!stack.back().checked_left && curr->left)
        {
            while (curr->left)
            {
                stack.back().checked_left = true;
                temp.ptr = curr->left; 
                stack.push_back(temp);
                curr = curr->left;
            }
        }
        if (!stack.back().checked_right && curr->right)
        {
            stack.back().checked_right = true;
            temp.ptr = curr->right;
            stack.push_back(temp);
            curr = curr->right;
        }
        else
        {
            answer.push_back(curr->val);
            stack.pop_back();
            if (!stack.empty()) { curr = stack.back().ptr; }
        }
    }
    return answer;
}

/* Recursive Solution */
void helper(std::vector<int>& vec, TreeNode* node)
{
    if (node->left) { helper(vec, node->left); }
    if (node->right) { helper(vec, node->right); }
    vec.push_back(node->val);
}
std::vector<int> postorderTraversal(TreeNode* root) 
{
    if (!root) { return { }; }
    std::vector<int> answer;
    helper(answer, root);
    return answer;
}