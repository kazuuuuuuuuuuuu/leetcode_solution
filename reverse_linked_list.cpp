ListNode* reverseList(ListNode* head)
{
	reverseList *prev = nullptr;
	reverseList *cur = head;
	while(cur)
	{
		ListNode *next_node = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next_node;
	}
	return prev;
}