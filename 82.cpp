/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// create a dummy node
// check if the next node meets the requirements, if not skip them 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;
        while(curr)
        {
            if(!curr->next||curr->next&&curr->val!=curr->next->val)
            {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
            else
            {   
                int num = curr->val; 
                while(curr&&curr->val==num)
                    curr = curr->next;
            }
        }
        prev->next = nullptr;
        return dummy->next;
    }
};