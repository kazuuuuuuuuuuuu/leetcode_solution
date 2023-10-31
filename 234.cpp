class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {   
        // find the middle node -> slow fast pointers
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast&&fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the back half of the list
        ListNode *prev = nullptr;
        while(slow)
        {
            ListNode *next_node = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next_node;
        }
        // from both sides to check if those two nodes are the same
        while(head&&prev)
        {
            if(head->val!=prev->val)
                return false;

            head = head->next;
            prev = prev->next;
        }
        return true;
        
    }
};