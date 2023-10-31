class Solution {
public:
    string removeDuplicates(string s) 
    {
        string stack = "";
        for(char a : s)
        {
            if(stack.empty())
                stack.push_back(a);
            else
            {
                if(stack.back()==a)
                    stack.pop_back();
                else
                   stack.push_back(a); 
            }
        }
        return stack;
    }
};