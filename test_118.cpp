#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
	void display(vector<vector<int>> &ans, int i)
	{
		cout << "test(i):  " << i << endl;
		for(auto &nums : ans)
		{
			for(auto &num : nums)
			{
				cout << num << " ";
			}
			cout << endl;
		}
		cout << "ans ends here!\n";
	}
	
    vector<vector<int>> ans;
    vector<vector<int>> generate(int numRows) 
    {
        dp(numRows);
        return ans;
    }

    void dp(int i)
    {
    	
        if(i==1)
        {
            ans.push_back({1});
            display(ans, i);
            return;
        }
        if(i==2)
        {
        	dp(1);    	
            ans.push_back({1, 1});
            display(ans, i);
            return;
        }

        dp(i-1);
        vector<int> curr;
        curr.push_back(1);
        const vector<int> &prev = ans[i-2];
        int n = prev.size();
        for(int j=0;j<n-1;j++)
        {
            curr.push_back(prev[j]+prev[j+1]);
        }
        
        curr.push_back(1);
        ans.push_back(curr);
        display(ans, i);
    }
};



int main()
{
	Solution solution;
	vector<vector<int>> ans;
	ans = solution.generate(1);


}
