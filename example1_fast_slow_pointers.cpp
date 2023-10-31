//return the value of the node in the middle of a linked list

//method 1
// iterate the linked list to find out the length of it
int getMiddle(ListNode* head)
{
	int length = 0;
	ListNode *dummy = head;
	while(dummy)
	{
		length ++;
		dummy = dummy->next;
	}
	for(int i=0;i<length/2;i++)
	{
		head = head->next;
	}
	return head->val;
}

// fast and slow pointers
// to find the middle
int getMiddle(ListNode* head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->val;
}