class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // o(n*logn)
        // space complexity is dependent on the implementation
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(vector<int> &interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            if(!ans.empty()&&ans[ans.size()-1][1]>=start)
            {
                // the end is equal to the maximum one of the two overlapping intervals
                ans[ans.size()-1][1] = max(end, ans[ans.size()-1][1]);
            }
            else
                ans.push_back(interval);
        }  
        return ans; 
    }
};