#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next_) : val(x), next(next_) {}
};


class MyLinkedList {
private:
    int length;
    ListNode *dummy;
    ListNode *tail; 
public:
    MyLinkedList() : length(0)
    {
        dummy = new ListNode(0, nullptr);
        tail = dummy;
    }
    
    int get(int index) {
        if(index>=length)
            return -1;
        int i = 0;
        ListNode *curr = dummy->next;
        while(i<index)
        {
            i++;
            curr = curr->next;
        }
        return curr->val;
    }
    
   
    void addAtHead(int val) 
    {
    	
        length ++;
        ListNode * add = new ListNode(val, nullptr);
        add->next = dummy->next;
        dummy->next = add;
         // 头插法更改 
        if(tail==dummy)
        	tail = add;
    }
    
    void addAtTail(int val) 
    {
        length ++;
        ListNode * add = new ListNode(val, nullptr);
        tail->next = add;
        tail = add;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index>length)
            return;
        if(index==length)
        {
            addAtTail(val);
            return;       	
		}

        else if(index==0)
        {
        	addAtHead(val);
		}
        else
        {
            length ++;
            int i = 0;
            ListNode *curr = dummy->next;
            while(i!=index-1)
            {
                curr = curr->next;
                i ++;
            }
            ListNode * add = new ListNode(val, nullptr);
            add->next = curr->next;
            curr->next = add;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(length==0||index>=length||index<0)
            return;
        if(index==0)
        {
        	dummy->next =dummy->next->next;
        	return;
		}
        int i = 0;
        ListNode *curr = dummy->next;
        while(i!=index-1)
        {
            curr = curr->next;
            i ++;
        }
        curr->next = curr->next->next;
        length --;
    }

    void show()
    {
    	ListNode *curr = dummy->next;
    	int i = 0;
    	cout << "length: " << length << endl;
    	while(curr)
    	{
    		cout << "index " << i << ": " << curr->val << endl;
    		i++;
    		curr = curr->next;
		}
	}
};


int main()
{
	MyLinkedList kazu;
	kazu.addAtHead(1);
	kazu.addAtHead(2);
	kazu.addAtHead(3);
	kazu.addAtHead(4);
	kazu.addAtHead(5);
	kazu.show();
	cout << "-------------------------\n";
	kazu.deleteAtIndex(4); 
	kazu.show();	
	//cout << kazu.get(5);
}
