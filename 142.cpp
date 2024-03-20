// fast and slow pointer to find the entrance of a circle
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *index;
        ListNode *index2 = head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
            {
                index = slow;
                while(index2!=index)
                {
                    index2 = index2->next;
                    index = index->next;
                }
                return index;                
            }
        }
        return NULL;
    }
};