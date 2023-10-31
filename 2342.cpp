// my method using a map to record the numbers that have the same digit sum
// digit sum is regarded as a key
// using sort() to find the biggest and the second biggest number in the same group
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int> > group;
        for(int num : nums)
        {
            int digit_sum = 0;
            int i = num; // Temporary variables
            while(i>0)
            {
                digit_sum += i % 10;
                i /= 10;
            }
            group[digit_sum].push_back(num);
        }

        int ans = -1;
        for(auto [key, value] : group)
        {

            int n = value.size();
            if(n>=2)
            {   sort(value.begin(), value.end());
                ans = max(ans, value[n-1] + value[n-2]);
            }
        }
        return ans;
    }
};

int maximumSum(vector<int>& nums)
{
    unordered_map<int, int> dic;        
    int ans = -1;
    for(int num : nums)
    {

        int digit_sum = 0;
        int i = num;
        while(i>0)
        {
            digit_sum += i % 10;
            i /= 10;
        }
        if(dic.find(digit_sum)!=dic.end())
        {
            ans = max(ans, num + dic[digit_sum]);
            if(num>dic[digit_sum])
                dic[digit_sum] = num;
        }
        else
        {
            dic[digit_sum] = num;
        }
    }

    return ans;
}