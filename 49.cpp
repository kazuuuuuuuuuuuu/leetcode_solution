// my method using the sorted string as the key to establish the map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> count;
        for(string str : strs)
        {
            string key = str; 
            sort(key.begin(), key.end());
            count[key].push_back(str);
        } 
        vector<vector<string>> ans;
        for(auto [key, value] : count)
        {
            ans.push_back(value);
        }      
        return ans;
    }
};

