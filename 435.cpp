class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1];
        int ans = 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<end)
            {
                ans ++;
                end = min(end, intervals[i][1]);
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return ans;
    }

    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};