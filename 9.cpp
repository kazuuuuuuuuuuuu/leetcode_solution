#include <iostream>;
#include <vector>;
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int curr = 0, left = 0, ans = 0;
        int count = 0;
        for(int right=0;right<nums.size();right++)
        {
            curr ++;
            if(nums[right]==0')
            {               
                count ++;

            }
            while(count>k)
            {
                cout << "test\n";
                if(nums[left]=='0')
                {
                    count --;
                }
                left ++;
                curr --;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << a.longestOnes(nums, k);
    return 0;
}
