#include<iostream>
#include<vector>
using namespace std;
// state and state transfer
// dp takes and returns
// memo

class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> memo;
    int rob(vector<int>& nums) 
    {
        n = nums.size();
        this->nums = nums;
        memo = vector<vector<int>> (n, vector<int> (2, -1));
        return dp(0, 0);
    }

    int dp(int i, int flag)
    {
    	cout << "beign\n";
        if(i==n-1)
        {
        	cout << "beign\n";
            int num = nums[i];
            if(flag==1)
                return 0;
            else
                return num;
        }
        if(i>n-1)
        {
        	cout << "i: " << i << endl;
        	cout << "n-1: " << n-1 << endl;
        	return 0;
		}
            
		cout << "beign\n";
        if(memo[i][flag]!=-1)
            return memo[i][flag];

        if(i==0)
        {
            int num = nums[i];
            int ans = dp(i+1, 0);;
            // do nothing
            ans = max(ans, dp(i+2, 1)+num);
            memo[i][flag] = ans;
            cout << i << ":  " << ans;
            return ans;
        } 

        int num = nums[i];
        int ans = dp(i+1, flag);
        // do nothing
        ans = max(ans, dp(i+2, flag)+num);
        memo[i][flag] = ans;
        cout << i << ":  " << ans;
        return ans;        
    }
};

int main()
{
	vector<int> nums = {2, 3 , 2};
	Solution solution;
	cout << solution.rob(nums);
}
