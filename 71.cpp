class Solution {
public:
    string simplifyPath(string path) 
    {
        vector<string> stack;
        path += '/';
        
        string word = "";
        
        for(char a : path)
        {
            // every time we meet the slash, its the Settlement time

            if(a=='/')
            {   if(!word.empty())
                {
                    if(word=="..")
                    {
                       if(!stack.empty())
                        stack.pop_back();                        
                    }
                    
                    else if(word==".");
                    else
                    {
                        stack.push_back(word);
                    }                   
                }
                word = "";
            }
            else
            {
                word += a;
            }
        }   
        string ans = ""; 
        for(string s : stack)
        {
            ans += '/';
            ans += s;
        }
        if(ans.empty())
            ans = "/";
        return ans;
    }
};