// most greedy problems involve sorting the input
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
            }
            j--;
            ans++;
        }      
        return ans;
    }
};

// time complexity O(n log n)
// space complexity O(1)