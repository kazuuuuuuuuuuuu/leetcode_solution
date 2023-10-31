// entended usage of the binary search

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        if(dist.size()>ceil(hour))
            return -1;

        int left = 1;
        // 求指数
        int right = pow(10, 7);
        // impossible possible
        // the speed distribution
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(!check(dist, hour, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;


    }

    // check funtion
    bool check(vector<int>& dists, double limit, int speed)
    {
        double hour = 0;
        for(int dist : dists)
        {
            // round up!! -> ceilling function
            hour = ceil(hour);
            // type conversion!!
            hour += (double(dist)) / speed; 
        }
        return hour <= limit;
    }
};