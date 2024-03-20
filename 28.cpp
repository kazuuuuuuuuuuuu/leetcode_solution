// KMP
class Solution {
public:
    void build_next(int next[], int n, const string &pattern)
    {
        int j = 0;
        next[0] = 0;
        for(int i=1;i<n;i++)
        {
            while(j>0&&pattern[i]!=pattern[j])
            {
                j = next[j-1];
            }

            if(pattern[i]==pattern[j])
            {
                j ++;
                next[i] = j;
            }
            else
            {
                next[i] = 0;
            }
        }
    }

    int strStr(string haystack, string needle) 
    {
        int n = needle.size();
        int next[n];

        build_next(next, n, needle); 
        int j = 0;
        int i = 0;
        n = haystack.size();
        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i ++;
                j ++;
                if(j==needle.size())
                    return i - j;
            }
            else if(j>0)
            {
                j = next[j-1];
            }
            else
            {
                i ++;
            }
        }   
        return -1;
    }
};