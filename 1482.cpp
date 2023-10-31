class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {   
        int left = 0;
        int right = 10000000000;
        int limit = right;
        // impossible possible
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(!check(bloomDay, m, k, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        // impossible的右端点超界 代表不可能 返回-1
        if(left > limit)
            return -1;
        return left;
        
    }

    bool check(vector<int>& bloomDay, int m, int k, int test)
    {
        int n = 0;
        int continuity = 0;
        for(int flower : bloomDay)
        {
            if(flower<=test)
            {
                continuity ++;
                if(continuity==k)
                {
                    continuity = 0;
                    n ++;
                }
            }
            // restoration
            else
                continuity = 0;
        }
        return n >= m;
    }
};