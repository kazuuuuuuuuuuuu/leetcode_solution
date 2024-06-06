// 一维dp滚动数组
#include <bits/stdc++.h>
using namespace std;

int n, bagweight;// bagweight代表行李箱空间


vector<int> weight;
vector<int> value;
 
void solve() {
    vector<int> weight_(n, 0); // 存储每件物品所占空间
    vector<int> value_(n, 0);  // 存储每件物品价值
    for(int i = 0; i < n; ++i) {
        cin >> weight_[i];
    }
    for(int j = 0; j < n; ++j) {
        cin >> value_[j];
    }
    
    weight = weight_;
    value = value_;
    
    vector<int> dp(bagweight+1, 0);
    for(int i=0;i<n;i++)
    {
        // 从后往前 防止需要用来计算的dp值被覆盖
        // j>weight[i]时才需要计算 其他时候并不改变
        for(int j=bagweight;j>=weight[i];j--)
        {
            dp[j] = max(dp[j-weight[i]] + value[i], dp[j]);
        }       
    }

    cout << dp[bagweight] << endl;
}

int main() {
    while(cin >> n >> bagweight) {
        solve();
    }
    return 0;
}



int main() {
    while(cin >> n >> bagweight) {
        solve();
    }
    return 0;
}

// 正常dp memo为2维（用两个维度的信息来记录一个状态） 记录所有的状态信息

#include <bits/stdc++.h>
using namespace std;

int n, bagweight;// bagweight代表行李箱空间

vector<vector<int>> memo;
vector<int> weight;
vector<int> value;
 
int dp(int i, int currweight);

void solve() {
    vector<int> weight_(n, 0); // 存储每件物品所占空间
    vector<int> value_(n, 0);  // 存储每件物品价值
    for(int i = 0; i < n; ++i) {
        cin >> weight_[i];
    }
    for(int j = 0; j < n; ++j) {
        cin >> value_[j];
    }
    
    weight = weight_;
    value = value_;
    
    memo = vector<vector<int>> (n, vector<int> (bagweight+1, -1));

    cout << dp(n-1, bagweight) << endl;
}

int dp(int i, int currweight)
{
    if(currweight==0)
        return 0;
    if(i==0&&currweight<weight[i])
        return 0;
    if(i==0&&currweight>=weight[i])
        return value[i];
        
    if(memo[i][currweight]!=-1)
        return memo[i][currweight];
    int ans = 0;
    if(currweight<weight[i])
        ans = dp(i-1, currweight);
    else
        ans = max(dp(i-1, currweight), dp(i-1, currweight-weight[i])+value[i]);
        
    memo[i][currweight] = ans;
    return ans;
}

int main() {
    while(cin >> n >> bagweight) {
        solve();
    }
    return 0;
}