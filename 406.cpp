class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size()==0) return 0;
        int ans = 1;
        sort(points.begin(), points.end(), cmp);
        int end = points[0][1];
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0]>end)
            {
                ans ++;
                end = points[i][1];
            }
            else if(points[i][0]<=end)
            {
                end = min(points[i][1], end);
            }
        }
        return ans;
    }

    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};