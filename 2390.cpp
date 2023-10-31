// basic usage of a stack
class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char a : s)
        {
            if(a!='*')
                ans.push_back(a);
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};