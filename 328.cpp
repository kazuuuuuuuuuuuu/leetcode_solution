// a typical usage of the Tail insertion method

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;

        ListNode* odd_after = head;
        ListNode* even_first = head->next;
        ListNode* even_after = head->next;;

        ListNode* curr = head->next->next;
        int i = 1;
        while(curr)
        {
            if(i==1)
            {
                odd_after->next = curr;
                odd_after = curr;
                i = 0;
            }
            else
            {
                even_after->next = curr;
                even_after = curr;
                i = 1;
            }
            curr = curr->next;
        }
        even_after->next = nullptr;
        odd_after->next = even_first;
        return head;

    }
};