ListNode* reverseList(ListNode* head)
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

ListNode* find_mid(ListNode* head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

class Solution {
public:
    int pairSum(ListNode* head) 
    {
		int sum = 0;
		ListNode *mid_node = find_mid(head);
		ListNode *head_2 = reverseList(mid_node);
		while(head_2)
		{
			sum = max(sum, head_2->val+head->val);
			head = head->next;
			head_2 = head_2->next;
		}
		return sum;
    }
    //  a standard usage of the fast slow pointers method to find the middle node
    ListNode* find_mid(ListNode* head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
// a standard usage of the reversing a linked list
ListNode* reverseList(ListNode* head)
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