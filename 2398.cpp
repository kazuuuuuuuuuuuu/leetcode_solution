// using a decreasing stack to find the max in the sliding window

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) 
    {
        int ans = 0;
        int n = chargeTimes.size();
        long long total_cost = 0;
        int max_ = 0;
        long long sum = 0;
        int left = 0;
        int right = 0;
        int k = 0;
        deque<int> decre;

        for(;right<n;right++)
        {
            // find max_ -> using a decreaing stack
            while(!decre.empty()&&chargeTimes[decre.back()]<=chargeTimes[right])
            {
                decre.pop_back();
            }
            decre.push_back(right);
            max_ = chargeTimes[decre.front()];
            sum += runningCosts[right];
            k ++;
            total_cost = max_ + k * sum;
            while(left<right&&total_cost>budget)
            {
                sum -= runningCosts[left];
                if(decre.front()==left)
                {
                    decre.pop_front();
                    max_ = chargeTimes[decre.front()];
                }
                k --;
                total_cost = max_ + k * sum;
                left ++;
            }
            // 可能即使只有一个robot 也不满足条件那么 不计入ans中
            if(total_cost<=budget)
                ans = max(ans, k);
        }    
        return ans;
    }
};