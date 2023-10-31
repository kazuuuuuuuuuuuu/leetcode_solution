//using slow and fast pointers
// to find the kth node from the end of the linked list;
// move the fast pointer k ahead of the slow pointer
// if it reaches the end, the slow pointer is the answer
// since they always have a gap of k nodes 

ListNode* findNode(ListNode* head, int k)
{
	ListNode *slow = head;
	ListNode *fast = head;
	for(int i=0;i<k;i++)
	{
		fast = fast->next;
	}
	while(fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}