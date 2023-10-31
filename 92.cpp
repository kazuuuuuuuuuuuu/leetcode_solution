// my method is limited 
// but it is partially right


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *joint1 = find_starter(head , left-1);
        ListNode *start = find_starter(head , left);
        ListNode *end = find_starter(head , right);       
        ListNode *joint2 = end->next;

        joint1->next = nullptr;
        end->next =nullptr;

        reverse_partial(start);
        start->next = joint2;
        joint1->next = end;

        return head;

    }

    ListNode *reverse_partial(ListNode *start)
    {
    ListNode *prev = nullptr;
    ListNode *curr = start;
    while(curr)
    {
        ListNode *next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
    }

    ListNode *find_starter(ListNode *start, int m)
    {
        ListNode *curr = start;
        m --;
        while(m!=0)
        {
            m --;
            curr = curr->next;
        }
        return curr;
    }
};


// the recursive method
// exercise
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    // create a dummy node pointing to the head to generalize the function to fit all the conditions 
    ListNode *dummy = new ListNode(0, head);
    // the reverse function needs the node before the sublist to be conversed
    ListNode *before = dummy;
    // find the node
    for(int i=1;i<left;i++)
    {
        before = before->next;
    }

    reverse(before, left, right);

    return dummy->next;
}

ListNode *reverse(ListNode* before, int left, int right)
{
    ListNode *first, *sub_first, *sub_last, *last, *after;
    first = before->next;

    // consider the base cases for the recursion function
    if(left==right)
        // the sublist fitted our requirements already 
        return first;
    if(right-left==1)
    {
        // record the pointers required
        last = first->next;
        after = last->next;

        // swap
        before->next = last;
        last->next = first;
        first->next = after;

        // return
        return first;
    }


    // assume the reverse function has done the job for us as we expected
    // the reverse function will return the last node of the sublist after reversed
    sub_last = reverse(first, left+1, right-1);
    sub_first = first->next;
    last = sub_last->next;
    after = last->next;

    // Execute this round of swap (first and last)
    before->next = last;
    last->next = sub_first;

    sub_last->next = first;
    first->next = after;

    // return the last node of the reversed sublist
    // in this round, it is first
    return first;

}

//method 3
// written by myself, can be used in limited conditions
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *before, *after, *left_pointer, *right_pointer;

    // record the pointer needed
    ListNode* curr = dummy;
    for(int i=0;i<right;i++)
    {
        if(i==left-1)
            before = curr;
        else if(i==left)
            left_pointer = curr;
        curr = curr->next;
    }
    right_pointer = curr;
    after = right_pointer->next;

    // start to swap
    ListNode *prev = after;
    ListNode *next_node;
    curr = left_pointer;
    right_pointer->next = nullptr;
    while(curr)
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    before->next = right_pointer;

    return head;
}

// method3, the version came from the tutorial
// the basic method
// record the node before the sublist, process swapping, and then swap the remaining incorrect nodes
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    // create a dummy node to generalize this algorithm
    ListNode *dummy = new ListNode(0, head);

    ListNode *before = dummy;
    for(int i=1;i<left;i++)
        before = before->next;

    ListNode *prev = before;
    ListNode *curr = before->next;
    // swap the sublist nodes
    for(int i=left;i<=right;i++)
    {
        ListNode *next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    // remaining nodes
    before->next->next = curr;
    before->next = prev;

    // must return dummy->next 
    // because the head will be swap to other position in some cases
    return dummy->next;

} 