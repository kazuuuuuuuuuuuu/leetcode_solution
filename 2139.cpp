class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int ans = 0;

        while(target!=1)
        {
            if(maxDoubles!=0)
            {
                if(target%2==0)
                {
                    maxDoubles --;
                    target /= 2;
                    ans ++;
                }
                else
                {
                    target --;
                    ans ++;
                }
            }
            else
            {
                ans += target - 1;
                break;
            }

        }

        return ans;
    }
};