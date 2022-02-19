struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (head->next == nullptr) 
    { 
        delete head; 
        head = nullptr; 
        return head; 
    }
    if (n == 1)
    {
        ListNode* curr = head->next;
        ListNode* prev = head;
        while (curr->next != nullptr) 
        { 
            curr = curr->next;
            prev = prev->next; 
        }
        delete curr;
        curr = nullptr;
        prev->next = nullptr;
        return head;
    }
    int count = 2;
    ListNode* nthNode = head;
    ListNode* prev = head;
    ListNode* temp = head->next;

    while (count < n)
    {
        temp = temp-> next;
        ++count;
    }
    if (temp->next != nullptr)
    {
        temp = temp->next;
        nthNode = nthNode->next;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
        nthNode = nthNode->next;
        prev = prev->next;
    }
    if (prev == nthNode)
    {
        ListNode* temp = head->next;
        delete head;
        head = temp;
        return head;
    }
    prev->next = nthNode->next;
    delete nthNode;
    nthNode = nullptr;
    return head;
}