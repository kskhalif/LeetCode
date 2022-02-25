struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) 
{
    while (node->next->next != nullptr)
    {
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    delete node->next;
    node->next = nullptr;
}