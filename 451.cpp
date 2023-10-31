class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;
        for(char a: s)
        {
            freq[a] ++;
        }

        priority_queue<pair<int ,char> > que;
        for(auto [key, value] : freq)
        {
            que.push(make_pair(value, key));
        }

        string ans;
        while(!que.empty())
        {
            auto pair = que.top();
            que.pop();
            ans.append(pair.first, pair.second);
        }
        return ans;
    }
};