class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long left = 1;
        long long right = (long long)time[0] * totalTrips;
        // solution space
        // impossible possible
        while(left<=right)
        {
            long long mid = left + (right - left) / 2;
            if(!check(mid, time, totalTrips))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    bool check(long long test, vector<int>& time, int totalTrips)
    {
        // 主要注意数据类型
        long long trips = 0;
        for(auto &bus : time)
        {
            trips += test / bus;
        }
        return trips>=totalTrips;
    }
};