// 双指针 遍历两个数组 + 贪婪
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        // g -> child array
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;

        int i = g.size()-1;
        int j = s.size()-1;
        while(i>=0&&j>=0)
        {
            if(s[j]>=g[i])
            {
                result ++;
                i --;
                j --;
            }
            else
            {
                i --;
            }
        }
        return result;
    }
};