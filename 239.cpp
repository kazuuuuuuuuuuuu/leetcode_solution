// usage of dequeue
// it allows for efficient insertion and deletion of elements at both the beginning and end of the container
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque 
        deque<int> queue1;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!queue1.empty()&&nums[queue1.back()]<nums[i])
                queue1.pop_back();
            queue1.push_back(i);
            if(queue.front()<=i-k)
                queue.pop_front();
            // when the i have passed k-1 elements, we can push max onto the answer vector
            if(i>=k-1)
                ans.push_back(nums[queue1.front()]);
        }
        return ans;
    }
};

class Solution {
public:
    deque<int> deque;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;
        int i = 0;
        for(int j=0;j<nums.size();j++)
        {
            push(nums[j]);
            if(j-i+1==k)
            {
                ans.push_back(get_max());
            }
            else if(j-i+1>k)
            {
                pop(nums[i]);
                i ++;
                ans.push_back(get_max());
            }

        }
        return ans;
    }

    void pop(int num)
    {
        if(!deque.empty()&&deque.front()==num)
        {
            deque.pop_front();
        }
    }

    void push(int num)
    {
        while(!deque.empty()&&deque.back()<num)
        {
            deque.pop_back();
        }
        deque.push_back(num);
    }

    int get_max()
    {
        return deque.front();
    }
};