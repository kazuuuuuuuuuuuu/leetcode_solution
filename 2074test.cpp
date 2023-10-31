#include <iostream>
using namespace std;

 struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
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
        if(count==length)
        {
            if(length%2==0||(&&count%2==0))
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

int main()
{
	ListNode* ten = new ListNode(10, nullptr);
	ListNode* nine = new ListNode(9, ten);
	ListNode* eight = new ListNode(8, nine);
	ListNode* seven = new ListNode(7, eight);
	ListNode* six = new ListNode(6, seven);
	ListNode* five = new ListNode(5, nullptr);
	ListNode* four = new ListNode(6, five);
	ListNode* three = new ListNode(0, four);
	ListNode* two = new ListNode(1, three);
	ListNode* one = new ListNode(1, two);
	
	Solution kazu;
	kazu.reverseEvenLengthGroups(one);
	while(one)
	{
		cout << one->val << "  ";
		one = one->next;
	
	}
	return 0;
}

