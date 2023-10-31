class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> matching{{'(',')'}, {'{','}'}, {'[',']'}};
        stack<char> stack;

        for(char a : s)
        {
            // a is found as a key in the matching
            // push it into the stack
            if(matching.find(a)!=matching.end())
                stack.push(a);
            else
            {
                if(stack.empty())
                    return false;
                char priv_opening = stack.top();
                stack.pop();
                if(matching[priv_opening]!=a)
                    return false; 
            }
        }
        return stack.empty();
    }
};