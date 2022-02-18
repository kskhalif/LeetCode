struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* l3 = new ListNode();
    ListNode* temp = l3;

    while (l1 != nullptr || l2 != nullptr)
    {
        temp->val += l1 != nullptr ? l1->val : 0;
        temp->val += l2 != nullptr ? l2->val : 0;

        l1 = l1 != nullptr ? l1->next : nullptr;
        l2 = l2 != nullptr ? l2->next : nullptr;

        if (temp->val > 9)
        {
            temp->val -= 10;
            temp->next = new ListNode(1);
            temp = temp->next;
        }
        else if (l1 != nullptr || l2 != nullptr)
        {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
    }
    return l3;
}