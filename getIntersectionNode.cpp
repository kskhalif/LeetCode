struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    int numA = 0, numB = 0;
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    
    while (tempA || tempB)
    {
        if (tempA) { ++numA; tempA = tempA->next; }
        if (tempB) { ++numB; tempB = tempB->next; }
    }

    if (numA == numB) { numA = 0; numB = 0; }
    else if (numA > numB) { numA -= numB; numB = 0; }
    else { numB -= numA; numA = 0; }
    
    tempA = headA;
    tempB = headB;

    while (tempA && tempB)
    {
        if (tempA == tempB) { return tempA; }

        if (numB == 0) { tempA = tempA->next; }
        else { --numB; }

        if (numA == 0) { tempB = tempB->next; }
        else { --numA; }
    }
    return nullptr;
}