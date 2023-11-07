#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nums;
    // memo�������ʽ ��Ϊtarget�ǲ�ȷ���Ĳ�������������ʾ -> ������map
    vector<unordered_map<int, int>> memo;
    int n;
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        this->nums = nums;
        n = nums.size();
        memo = vector<unordered_map<int, int>> (n, unordered_map<int, int> {});
        return dp(0, target);
    }

    int dp(int i, int sum)
    {
        // base case
        if(i==n)
        {
            // û��Ԫ�ؿ���ʹ����
            if(sum==0)
                return 1;
            else
                return 0;
        }


        if(memo[i].find(sum)!=memo[i].end())
        {
        	cout << i << " : " << sum << endl;
        	cout << "access the map!!!\n";
        	return memo[i][sum];
		}
            

        int ans = 0;
        int num = nums[i];
        ans += dp(i+1, sum+num);
        ans += dp(i+1, sum-num);

        memo[i][sum] = ans;
        return ans;
    }
};

int main()
{
	Solution solution;
	vector<int> input = {1,1,1,1,1};
	int target = 3;
	int ans = solution.findTargetSumWays(input, target);
	cout << ans << endl;
	
}


