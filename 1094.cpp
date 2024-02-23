class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        // find the farthest position
        int farthest = 0;
        for(auto trip : trips)
        {
            int to = trip[2];
            farthest = max(farthest, to);
        }    

        // create a difference array (0, farthest)
        vector<int> road(farthest+1, 0);
        // record every change 
        for(auto trip : trips)
        {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            road[from] += numPassengers;
            road[to] -= numPassengers;
        } 

        // prefix sum
        int curr = 0;
        for(int i=0;i<=farthest;i++)
        {
            curr += road[i];
            if(curr>capacity)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<vector<int>> changes;
        for(auto trip : trips)
        {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            vector<int> pick{from, numPassengers};
            vector<int> drop{to, -numPassengers};
            changes.push_back(pick);
            changes.push_back(drop);
        } 

        sort(changes.begin(), changes.end());
        int curr = 0;
        for(auto change : changes)
        {
            int position = change[0];
            int numPassengers = change[1];
            curr += numPassengers;
            if(curr>capacity)
                return false;
        }
        return true;
    }
};