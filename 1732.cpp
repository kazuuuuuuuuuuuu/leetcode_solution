class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n = gain.size();
        int ans = 0;
        vector<int> altitude(n+1, 0);
        for(int i=1;i<n+1;i++)
        {
            altitude[i] = altitude[i-1] + gain[i-1];
            ans = max(ans, altitude[i]);
        }    
        return ans;
    }
};