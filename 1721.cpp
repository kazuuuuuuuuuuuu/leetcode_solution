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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
            
        // find the kth node from the beginning
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for(int i=0;i<k;i++)
        {
            fast = fast->next;
        }

        ListNode* target1 = fast;
  
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* target2 = slow;

        int temp = target1->val;
        target1->val = target2->val;
        target2->val = temp;

        
        return dummy->next;
    }
};


int main()
{
	//head = [1,2,3,4,5]
    ListNode *five = new ListNode(5, nullptr);
    ListNode *four = new ListNode(4, five);
    ListNode *three = new ListNode(3, four);
    ListNode *two = new ListNode(2, three);
    ListNode *head = new ListNode(1, two);
    ListNode *curr = head;
    Solution a;
    curr = a.swapNodes(head,2);
    while(curr)
    {
    	cout << curr->val << endl;
    	curr = curr->next;
	}

}
