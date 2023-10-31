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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *fast = head;
        //ListNode *slow = head;
        for(int i=1;i<=n;i++)
        {
            fast = fast->next;
        }
        while(fast)
        {
            fast = fast->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return dummy->next;
        
    }
};