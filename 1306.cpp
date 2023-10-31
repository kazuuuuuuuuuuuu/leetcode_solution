// dfs -> seen + recursion over the neighbours of each node
class Solution {
public:
    vector<int> arr;
    int n;
    vector<bool> seen;

    bool canReach(vector<int>& arr, int start) 
    {
        this->arr = arr;
        n = arr.size();
        seen = vector<bool>(n, false);
        seen[start] = true;
        return dfs(start);

    }

    bool valid(int i)
    {
        return i>=0&&i<n;
    }

    bool dfs(int i)
    {
        if(arr[i]==0)
            return true;
        bool ans = false;
        for(int neighbour : {i+arr[i], i-arr[i]})
        {
            if(valid(neighbour)&&seen[neighbour]==false)
            {
                seen[neighbour] = true;
                ans = ans||dfs(neighbour);
            }
        }
        return ans;
    }
};