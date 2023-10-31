class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode *fast = head;
        ListNode *slow = head;
        fast = fast->next;
        while(fast)
        {
            if(fast->val==slow->val)
            {
                slow->next=fast->next;
                fast = fast->next;
                continue;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return head;
    }
};