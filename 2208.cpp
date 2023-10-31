// 需要在一个元素变化的集合中连续寻找最大值 -> heap


class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        double target;
        for(int num : nums)
        {
            target += num;
        }    
        target = target / 2;

        priority_queue<double> heap(nums.begin(), nums.end());
        int ans = 0;
        while(target>0)
        {
            ans ++;
            double num = heap.top();
            heap.pop();
            target -= num/2;
            heap.push(num/2);
        }
        return ans;
    }
};

// 关于heap的操作每一个都takes o(log n) time