class Solution {
public:
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        ListNode *curr = head;
        int exponent = 0;
        int result = 0;
        while(curr)
        {
            result += (curr->val)*(pow(2, exponent));
            exponent ++;
            curr = curr->next;
        }
        return result;


    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr)
        {
            ListNode *next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
};