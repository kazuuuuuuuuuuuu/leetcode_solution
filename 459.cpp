class Solution {
public:
    // 用next数组中计算该字符串的最长相等前后缀 
    // 如果和总长度可以整除总长度和最长相等前后缀的差值 -> 整个数组就是用除最长相等前后缀串中之外的部分重复组成的 
    void build_next(int next[], int n, const string &pattern)
    {
        int j = 0;
        next[j] = 0;
        for(int i=1;i<n;i++)
        {
            // j 是前缀的末尾待检查位置
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

    bool repeatedSubstringPattern(string s) 
    {
        int n = s.size();
        int next[n];
        build_next(next, n, s);

        int last = next[n-1];
        if(last==0)
            return false;        
        int substring_length = n - last;

        return (n%substring_length)==0;
    }
};