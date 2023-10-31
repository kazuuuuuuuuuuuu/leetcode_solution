class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_set<string> destination;
        unordered_set<string> setout;
        for(vector<string> path : paths)
        {
            setout.insert(path[0]);
            destination.insert(path[1]);
        }
        for(auto des : destination)
        {
            if(setout.find(des)==setout.end())
                return des;
        }
        return " ";
    }
};