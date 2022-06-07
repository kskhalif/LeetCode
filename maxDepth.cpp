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

int helper(TreeNode* ptr, std::vector<std::pair<int, int>>& list, int& index)
{
    if (!ptr) { return 0; }

    int i = index;

    list.push_back({1, 1});

    if (ptr->left) { list[i].first = 1 + helper(ptr->left, list, ++index); }
    if (ptr->right) { list[i].second = 1 + helper(ptr->right, list, ++index); }

    return (list[i].first > list[i].second ? list[i].first : list[i].second);
}

int maxDepth(TreeNode* root) 
{
    if (!root) { return 0; }

    std::vector<std::pair<int, int>> list;
    int index = 0;

    list.push_back({1, 1});

    if (root->left) { list[0].first = 1 + helper(root->left, list, ++index); }
    if (root->right) { list[0].second = 1 + helper(root->right, list, ++index); }

    int max = 0, curr = 0;
    for (auto& x : list)
    {
        curr = x.first > x.second ? x.first : x.second;
        max = curr > max ? curr : max;
    }
    return max;
}