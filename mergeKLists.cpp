#include <vector>
#include <queue>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) 
{
    auto comp = [](const ListNode* lhs, const ListNode* rhs)
                {
                    return lhs->val > rhs->val;
                };
    std::priority_queue<ListNode*, 
                        std::vector<ListNode*>, 
                        decltype(comp)> min_heap(comp);
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    ListNode* temp = nullptr;
    for (int i = 0; i < lists.size(); ++i)
    {
        if (lists[i]) { min_heap.push(lists[i]); }
    }
    if (min_heap.empty()) { return nullptr; }
    head = new ListNode(min_heap.top()->val);
    curr = head;
    temp = min_heap.top()->next;
    min_heap.pop();
    if (temp) { min_heap.push(temp); }
    while (!min_heap.empty())
    {
        curr->next = new ListNode(min_heap.top()->val);
        curr = curr->next;
        temp = min_heap.top()->next;
        min_heap.pop();
        if (temp) { min_heap.push(temp); }
    }
    return head;
}