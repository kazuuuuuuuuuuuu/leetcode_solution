#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	void display(int i, int next, int ans)
	{
		cout << endl;
		cout << "difference+num:" <<  difference+arr[i] << endl;
		cout << "i:"<<i<<" ,num:"<<arr[i]<<" ,next:"<<next<<" ,ans:"<<ans<<endl;
		cout << endl;
	}
	
	
    vector<int> arr;
    int n;
    int difference;
    vector<unordered_map<int, int>> memo;
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        n = arr.size();
        this->arr = arr;
        this->difference = difference;
        memo = vector<unordered_map<int, int>> (n, unordered_map<int, int> {});
        return dp(0, INT_MAX);

    }

  int dp(int i, int next)
    {
        if(memo[i].find(next)!=memo[i].end())
            return memo[i][next];

        if(i==n-1)
        {
            int num = arr[i];
            if(next==INT_MAX)
                return 1;
            else
            {
                if(num==next)
                    return 1;
                else
                    return 0;
            }
        }

        // INT_MAX代表重新开始对这个元素没有要求
        if(next==INT_MAX)
        {
            int num = arr[i];
            int ans = dp(i+1, INT_MAX);
            ans = max(ans, dp(i+1, num+difference)+1);
            memo[i][next] = ans;
            display( i,  next,  ans);
            return ans;
        }
        else
        {
            int num = arr[i];
            int ans = 0;
            if(num==next)
                ans = dp(i+1, num+difference)+1;
            memo[i][next] = ans;
            display( i,  next,  ans);
            return ans;
        }

    }
};

int main()
{
	vector<int> arr = {1,5,7,8,5,3,4,2,1};
	int difference = -2;
	Solution solution;
	int ans = solution.longestSubsequence(arr, difference);
	cout << ans;
	
}


