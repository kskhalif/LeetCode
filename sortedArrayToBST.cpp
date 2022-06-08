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

void helper(const std::vector<int>& nums, TreeNode*& node, int l, int r)
{ 
    int mid = l + (r - l) / 2;
    node = new TreeNode(nums[mid]);
    if (mid > l) { helper(nums, node->left, l, (mid - 1)); }
    if (r > mid) { helper(nums, node->right, (mid + 1), r); }
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) 
{
    if (nums.empty()) { return nullptr; }
    TreeNode* root = nullptr;
    helper(nums, root, 0, (nums.size() - 1));
    return root;
}