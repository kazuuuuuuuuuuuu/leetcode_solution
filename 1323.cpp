// alter the most significant bit with 6 into 9

class Solution {
public:
    int maximum69Number (int num) 
    {
        vector<int> nums;
        while(num!=0)
        {
            int digit = num % 10;
            nums.push_back(digit);
            num = num / 10;
        }

        int length = nums.size();
        for(int i=length-1;i>=0;i--)
        {
            if(nums[i]==6)
            {
                nums[i] = 9;
                break;
            }
        }

        for(int i=0;i<length;i++)
        {
            num += nums[i] * pow(10, i);
        }

        return num;
    }
};