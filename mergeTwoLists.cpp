struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (list1 == nullptr || list2 == nullptr)
        { return (list1 ? list1 : list2); }

    ListNode* head = nullptr;

    list1->val <= list2->val ? 
    (head = list1, list1 = list1->next, head->next = nullptr): 
    (head = list2, list2 = list2->next, head->next = nullptr);

    ListNode* prev = head;
    ListNode* curr = nullptr; 

    while (list1 != nullptr || list2 != nullptr)
    {
        if (list1 != nullptr && list2 != nullptr)
        {
            list1->val <= list2->val ? 
            (curr = list1, list1 = list1->next, curr->next = nullptr): 
            (curr = list2, list2 = list2->next, curr->next = nullptr);
        }
        else if (list1 != nullptr)
        {
            curr = list1;
            list1 = list1->next;
            curr->next = nullptr;
        }
        else 
        {
            curr = list2;
            list2 = list2->next;
            curr->next = nullptr;
        }
        prev->next = curr;
        prev = prev->next;
    }
    return head;    
}