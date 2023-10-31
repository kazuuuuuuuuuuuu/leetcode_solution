//算法1
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        // 1 sort batteries
        sort(batteries.begin(), batteries.end());
        
        // 选出最大的前n个电池 为n台电脑持续供电 -> 生成live数组
        // 0 1 2 3 4 5
        int m = batteries.size();
        vector<int> live;
        for(int i=m-n;i<m;i++)
        {
            live.push_back(batteries[i]);
        }

        // 剩余的电池都放到extra中
        long long  extra = 0;
        for(int i=0;i<m-n;i++)
            extra += batteries[i];

        for(int i=0;i<=n-2;i++)
        {
            if(extra>=(live[i+1]-live[i])*1ll*(i+1))
                extra -= (live[i+1]-live[i])*1ll*(i+1);
            else
                return live[i] + extra * 1ll / (i+1);
        }

        return live[n-1] + extra / n;
    }
};

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long left = 1;
        long long right = 100000000000000;
        // possible impossible
        while(left<=right)
        {
            long long mid = left + (right -left) / 2;
            if(check(n, batteries, mid))
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return right;
    }

    bool check(int n, vector<int>& batteries, long long target)
    {
        long long extra = 0;
        for(auto &battery : batteries)
        {
            if(battery>=target)
                n --;
            else
                extra += battery;
        }
        return extra>=n*target;
    }
};