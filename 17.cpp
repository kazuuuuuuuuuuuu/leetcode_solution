class Solution {
public:
    unordered_map<char, string> map;
    string digits;
    vector<string> ans;
    string s;
    vector<string> letterCombinations(string digits) 
    {
        if(digits=="")
            return ans;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        this->digits = digits;
        backtrack(0);
        return ans;
    }

    void backtrack(int index)
    {
        if(index==digits.size())
        {
            ans.push_back(s);
        }
        char num = digits[index];
        string chars = map[num];
        for(auto a : chars)
        {
            s.push_back(a);
            backtrack(index+1);
            s.pop_back();
        }
    }
};