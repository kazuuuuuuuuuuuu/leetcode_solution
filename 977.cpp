// double pointers -> two way merge

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        vector<int> result(n);
        for(int k=n-1;k>=0;k--)
        {
            if(abs(nums[i])>abs(nums[j]))
            {
                int square = nums[i] * nums[i];
                i ++;
                result[k] = square;
            }
            else
            {
                int square = nums[j] * nums[j];
                j --;
                result[k] = square;
            }
        }   

        return result;
    }
};