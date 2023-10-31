//这个算法可以倒转偶数长度的部分 但是没法解决最后长度不够的队列
//除非用一个指针先遍历到最后看看长度是否和预期的相等
// this algorithm can solve part of this problem
// but it cant deal with the last group if its not equal to its expected length

// the problem has been solved by kazu li!!!!
// just have a look

 class Solution {
public:
    ListNode *reverse_even(ListNode *before, int n)
    {
        // base cases
        if(n==2)
        {
            ListNode *first = before->next;
            ListNode *last = first->next;
            ListNode *after = last->next;

            // swap
            before->next = last;
            last->next = first;
            first->next = after;

            return first;
        }

        // record important locations
        ListNode *first = before->next;
        ListNode *sub_last =  reverse_even(first, n-2);
        ListNode *sub_first = first->next;
        ListNode *last = sub_last->next;
        ListNode *after = last->next;

        //swap the first and the last
        before->next = last;
        last->next = sub_first;

        sub_last->next = first;
        first->next = after;

        return first;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head)
{
    ListNode *curr = head;
    ListNode *before = head;
    int length = 1;
    int count = 0;

    while(curr)
    {
        count ++;
        if(count==length||curr->next==nullptr)
        {
            if(count%2==0)
            {
                curr = reverse_even(before, count);
            }
            length ++;
            count = 0;
            before = curr;
        }
        curr = curr->next;
    }
    return head;
}
};