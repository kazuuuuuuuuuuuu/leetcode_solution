// 因为要lexicographically smallest所以尽量填a
// 当剩下的次数全写z都不能满足的时候 这个位置就不可以写a了
class Solution {
public:
    string getSmallestString(int n, int k) 
    {

        // 首先计算a的个数
        int a_count = 0;


        while(k<=n*26)
        {
            a_count ++;
            n --;
            k --;
        }

        // correct 
        a_count --;
        n ++;
        k ++;

        int z_count = k / 26;
    
        char other = 'a' + (k % 26) - 1;

        string ans;

        for(int i=0;i<a_count;i++)
        {
            ans += 'a';
        }
        if((k % 26)!=0)
            ans += other;
        for(int i=0;i<z_count;i++)
        {
            ans += 'z';
        }
        return ans;
    }
};