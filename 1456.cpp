class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int ans = 0;
        int cur_cost = 0;
        int i;
        int j;
        for(int j=0;j<s.size();j++)
        {
            cur_cost += abs(t[j]-s[j]);
            while(cur_cost>maxCost)
            {
                cur_cost -= abs(t[i]-s[i]);
                i ++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
        
    }
};