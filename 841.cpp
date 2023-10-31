
class Solution {
public:
    // the time complexity for searching across set is o1 if needed    
    unordered_set<int> seen;
    vector<vector<int>> rooms;
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        this->rooms = rooms;
        seen.insert(0);
        dfs(0);
        return seen.size()==rooms.size();    
    }

    void dfs(int node)
    {
        for(int neighbor : rooms[node])
        {
            if(seen.find(neighbor)==seen.end())
            {
                seen.insert(neighbor);
                dfs(neighbor);
            }
        }
    }
};


bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    unordered_set<int> seen;
    stack<int> stack;
    int n = rooms.size();

    seen.insert(0);
    stack.push(0);

    while(!stack.empty())
    {
        int node = stack.top();
        stack.pop();

        for(int neighbor : rooms[node])
        {
            if(seen.find(neighbor)==seen.end())
            {
                seen.insert(neighbor);
                stack.push(neighbor);
            }
        }
    }
    return seen.size()==rooms.size();
}