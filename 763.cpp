class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> last(26, 0);
        // the last position where the char occurs
        for(int i=0;i<s.size();i++)
        {
            last[s[i]-'a'] = i;
        }    

        vector<int> ans;
        int left = 0;
        int right = 0;
        for(int i=0;i<s.size();i++)
        {
            right = max(right, last[s[i]-'a']);
            if(i==right)
            {
                ans.push_back(right-left+1);
                left = i + 1;
                right = i + 1;
            }
        }         
        return ans;
    }
};