class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    if(head==nullptr||head->next==nullptr)
    {
        return head;
    }
    ListNode *prev = nullptr;
    ListNode *dummy = head->next;
    while(head&& head->next != nullptr)
    {   
        if(prev)
            prev->next = head->next;
        ListNode *next_node = head->next->next;
        head->next->next = head;
        prev = head;
        head->next = next_node;
        head = next_node;

    }
    return dummy;
    }
};


class Solution {
public:
ListNode* swapPairs(ListNode* head)
{
    if(!head||!head->next)
        return head;
    ListNode *dummy = head->next;
    ListNode *prev = nullptr;
    while(head&&head->next)
    {
        if(prev)
            prev->next = head->next;
        ListNode *next_node = head->next->next;
        head->next->next = head;
        head->next = next_node;
        prev = head;
        head = next_node;
    }
    return dummy;
}
};