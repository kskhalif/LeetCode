#include <vector>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if (head->next == nullptr || left == right)  { return head; }

    int tempVal = 0;
    ListNode* tempPtr = head;
    const int NUM_NODES = (right - left + 1);
    std::vector<ListNode*> ptrs;
    ptrs.reserve(NUM_NODES);

    while (left > 1)
    {
        tempPtr = tempPtr->next;
        --left;
    }
    for (int k = 0; k < NUM_NODES; ++k)
    {
        ptrs.push_back(tempPtr);
        tempPtr = tempPtr->next;
    }
    int i = 0, j = (ptrs.size() - 1);
    while (i < j)
    {
        tempVal = ptrs[i]->val;
        ptrs[i]->val = ptrs[j]->val;
        ptrs[j]->val = tempVal;
        ++i; --j;
    }
    return head;
}