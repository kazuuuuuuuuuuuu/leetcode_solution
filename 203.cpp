// record the previous node and traverse the linked list.
// remove the node that meets the requirements

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;
        while(curr)
        {
            if(curr->val==val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }

        }
        return dummy->next;
    }
};