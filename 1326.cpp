class Solution {
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        // 沿用上一题的思路 视频拼接的思路
        // 只不过这道题是离散的
        vector<vector<int>> taps;
        for(int i=0;i<n;i++)
        {
            int start = i - ranges[i];
            int end = i + ranges[i];
            vector<int> tap;
            tap.push_back(start);
            tap.push_back(end);
            taps.push_back(tap);
        }

        sort(taps.begin(), taps.end())
        // curr 存储下一个需要浇的位置
        int curr = 0;
        int i = 0;
        int ans = 0;
        while(curr<=n&&i<=n)
        {
            int temp = -1;
            for(;i<=n;i++)
            {
                int start = taps[i][0];
                int end = taps[i][1];
                if(start<=curr)
                {
                    temp = max(temp, end);
                }
                else
                    break;
            }
            if(temp==-1)
                return -1;
            else
            {
                ans ++;
                curr = temp + 1;
            }
        }
        if(curr>=n)
            return ans;
        else
            return -1;
    }
};