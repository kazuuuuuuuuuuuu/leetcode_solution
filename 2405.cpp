class Solution {
public:
    int partitionString(string s) 
    {
        int ans = 1;
        unordered_set<char> seen;
        for(char a : s)
        {
            if(seen.find(a)!=seen.end())
            {
                ans ++;
                seen.clear();
                seen.insert(a);
            }
            else
                seen.insert(a);
        }
        return ans;
    }
};