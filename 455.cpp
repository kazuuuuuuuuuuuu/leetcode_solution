class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        // if each vector has been sorted
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int n = s.size();
        int ans = 0;
        for(int child : g)
        {
            while(i<n&&s[i]<child)
            {
                i ++;
            }
            //  如果是合理的结果  答案增加 并且移动到下一个曲奇
            if(i<n)
            {
                ans ++;
                i ++;
            }
            else
                break;
        }
        return ans;
    }
};