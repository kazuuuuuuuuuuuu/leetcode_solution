class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char, vector<char>> map;
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        if(digits=="")
            return ans;
        string curr = "";
        backtrack(digits, 0, curr, ans, map);
        return ans;

    }

    void backtrack(string &digits, int i, string &curr, vector<string> &ans, unordered_map<char, vector<char>> &map)
    {
        // base case -> recursion
        if(i==digits.size())
        {
            ans.push_back(curr);
            return;
        }

        for(char a : map[digits[i]])
        {
            curr += a;
            backtrack(digits, i+1, curr, ans, map);
            curr.pop_back();
        }
    }
};


