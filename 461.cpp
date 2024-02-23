class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int ans = 0;
        int num = x ^ y;
        for(int i=0;i<32;i++)
        {
            int check = (1<<i) & num;
            if(check!=0)
                ans ++;
        }    
        return ans;
    }
};