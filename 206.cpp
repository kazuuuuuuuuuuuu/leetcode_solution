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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr)
        {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        return reverse(head, nullptr);
    }

    ListNode* reverse(ListNode* curr, ListNode *prev)
    {
        if(curr==nullptr)
            return prev;
        ListNode* temp = curr->next;
        curr->next = prev;
        return reverse(temp, curr);
    }
};