class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        if(intervals.size()==0)
        {
            ans.push_back(newInterval);
            return ans;    
        }
        // the array is already sorted
        bool inserted = false;
        for(vector<int> &interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            if(!inserted)
            {
                // overlapped
                if(end>=newInterval[0])
                {
                    if(start>newInterval[1])
                    {
                        ans.push_back(newInterval);
                        ans.push_back(interval);
                        inserted = true;
                        continue;
                    }
                    vector<int> newone;
                    start = min(start, newInterval[0]);
                    end = max(end, newInterval[1]);
                    newone.push_back(start);
                    newone.push_back(end);
                    ans.push_back(newone);
                    inserted = true;
                }
                // not overlapped
                else
                {
                    ans.push_back(interval);
                }
            }
            else
            {
                if(!ans.empty()&&ans[ans.size()-1][1]>=start)
                {
                    // the end is equal to the maximum one of the two overlapping intervals
                    ans[ans.size()-1][1] = max(end, ans[ans.size()-1][1]);
                }
                else
                    ans.push_back(interval);
            } 
        }
        if(!inserted)
        {
            ans.push_back(newInterval);
        }
        return ans;
    }
};