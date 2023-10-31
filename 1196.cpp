class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) 
    {
        // sort 默认是升序
        int total = 5000;
        int ans = 0
        sort(weight.begin(), weight.end());
        for(auto each : weight)
        {
            if(total>=each)
            {
                total -= each;
                ans ++;
            }
            else
                break;
        }
        return ans;
    }
};