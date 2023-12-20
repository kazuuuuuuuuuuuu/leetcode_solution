// state and state transfer
// what dp takes and returns
// memo

// 这个方法是正确的但是会超时
class Solution {
public:
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

        // INT_MAX代表重新开始 -> 对这个元素没有要求
        if(next==INT_MAX)
        {
            int num = arr[i];
            int ans = dp(i+1, INT_MAX);
            ans = max(ans, dp(i+1, num+difference)+1);
            memo[i][next] = ans;
            return ans;
        }
        else
        {
            int num = arr[i];
            int ans;
            if(num==next)
                ans = dp(i+1, num+difference)+1;
            else
                ans = dp(i+1, next);
            memo[i][next] = ans;
            return ans;
        }

    }
};


// 实验一下backtrack
// 算法是对的但是也会超时
class Solution {
public:
    vector<int> arr;
    int n;
    int difference;
    int ans = 0;
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        n = arr.size();
        this->arr = arr;
        this->difference = difference;
        backtrack(0, 0);
        return ans;

    }

    void backtrack(int start, int length)
    {   
        if(start==n)
            ans = max(ans, length);

        if(length==0)
        {
            for(int i=0;i<n;i++)
            {
                backtrack(i+1, length+1);
            }
        }
        else
        {
            int target = arr[start-1] + difference;
            for(int i=start;i<n;i++)
            {
                if(target==arr[i])
                    backtrack(i+1, length+1);
            }
            ans = max(ans, length);
        }
    }
};



class Solution {
public:
    // there are repetitive numbers in the arr
    unordered_map<int, vector<int>> map;
    vector<int> arr;
    int difference;
    vector<int> memo;
    int ans = 0;

    int longestSubsequence(vector<int>& arr, int difference) 
    {
        this->difference = difference;
        this->arr = arr;
        memo = vector<int> (arr.size(), -1);

        for(int i=0;i<arr.size();i++)
        {   
            // value : indices of that value
            // vector is ordered
            map[arr[i]].push_back(i);
        }
        dp(0);
        return ans;
    }

    // the current index -> return the ans to the original question
    int dp(int i)
    {
        // base case
        if(i==arr.size())
            return 0;
        if(memo[i]!=-1)
            return memo[i];

        int local = 1;
        int value = arr[i];
        int next_value = value + difference;
        if(map.find(next_value)!=map.end())
        {
            vector<int> &target_vector = map[next_value];
            auto next_index = upper_bound(target_vector.begin(), target_vector.end(), i);
            if(next_index!=target_vector.end())
            {
                local += dp(*next_index);
            }
        }
        dp(i+1);
        ans = max(ans, local);
        memo[i] = local;
        return local;
    }    
};


