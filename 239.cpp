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