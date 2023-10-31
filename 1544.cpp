class Solution {
public:
    string makeGood(string s) {
        int distance = abs('a'-'A');
        string stack;
        for(char a : s)
        {
            if(stack.empty())
                stack.push_back(a);
            else
            {
                if(abs(stack.back()-a)==distance)
                    stack.pop_back();
                else
                    stack.push_back(a);
            }
        }
        return stack;

    }
};