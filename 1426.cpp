// method by myself using hashset
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> arr_set(arr.begin(), arr.end());
        int ans = 0;
        for(int x : arr)
        {
            if(arr_set.find(x+1)!=arr_set.end())
            {
                ans ++;
            }
        }
        return ans;
    }
};

// method 2 using sorted array by myself
class Solution {
public:
    int countElements(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int ans = 0;
        int same_num = 0;
        int curr_num;
        int last_num = arr[0];
        for(int i=0;i<arr.size();i++)
        {
            curr_num = arr[i];
            if(last_num==curr_num)
                same_num ++;
            else
            {
                if(curr_num==last_num+1)
                {
                    ans += same_num;
                }
                same_num = 1;
                last_num = curr_num;
            }
        } 
        return ans;
    }
};