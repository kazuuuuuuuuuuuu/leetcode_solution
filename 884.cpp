class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string s)
    {
        string stack = "";
        for(char a : s)
        {
            if(a!='#')
                stack.push_back(a);
            else if(!stack.empty())
                stack.pop_back();
        }
        return stack;

    }
};