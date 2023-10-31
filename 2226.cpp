class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        long long sum = 0;
        for(auto num : candies)
            sum += num;
        if(sum<k)
            return 0;
        
        int left = 1;
        // 找一个足够大的数
        int right = 100000000;
        // possible impossible
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(check(candies, k, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

    //  模拟一遍发糖的过程 -> 可能会超时
    // 算算一共可以发多少人 -> 是否大于等于需要发的人数
    bool check(vector<int> candies, long long k, int test)
    {
        long long cnt = 0;
        for(auto pile : candies)
        {
            cnt += pile / test;
        }
        return cnt >= k;
    }
};