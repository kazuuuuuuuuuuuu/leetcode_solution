// method using a map to track the positon of each number
// iterate the value of the map to find the nearest distance
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int> > pos;
        for(int i=0;i<cards.size();i++)
        {
            pos[cards[i]].push_back(i);
        }

        int ans = INT_MAX;
        // in this part, the time complexity is still O(n), because we iterate all positions of each number from the array 
        // from a macro perspective
        for(auto [key, vector_nums] : pos)
        {
            for(int i=1;i<vector_nums.size();i++)
            {
                int dictance = vector_nums[i] - vector_nums[i-1] + 1;
                ans = min(ans, dictance);
            }
        }
        return ans==INT_MAX?-1:ans;       
    }
};

// enhanced addition, we just store the last position and calculate the distance immediately
int minimumCardPickup(vector<int>& cards)
{
    int ans = INT_MAX;
    unordered_map<int, int> pos;
    for(int i=0;i<cards.size();i++)
    {
        if(pos.find(cards[i])!=pos.end())
        {
            ans = min(ans, i - pos[cards[i]] + 1);
        }
        pos[cards[i]] = i;
    }

    //save on one iteration
    return ans==INT_MAX?-1:ans;
}


