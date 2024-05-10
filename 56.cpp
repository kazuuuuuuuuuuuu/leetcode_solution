class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        if(intervals.size()==0) return ans;
        
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> interval = intervals[i];
            int start = interval[0];
            int end = interval[1];
            if(start<=ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], end);
            }
            else
            {
                ans.push_back(interval);
            }
        }
        return ans;
    }

    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};