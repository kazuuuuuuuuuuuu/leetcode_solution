// impossible possible

class Solution {
public:    
    int minEatingSpeed(vector<int>& piles, int h) {
        int limit = h;
        int left = 1;
        int right = 0;
        for(int pile : piles)
            right = max(right, pile);

        // 这道题寻找不满足条件上界 或满足条件的下界
        // 上界返回left 下界返回right
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(!check(mid, piles, limit))
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        
        return left;
    }
    
    bool check(int k, vector<int>& piles, int limit)
    {
        long hours = 0;
        for(int pile : piles)
        {
            hours += (pile + k - 1) / k;
        }
        return hours <= limit;
    }
};