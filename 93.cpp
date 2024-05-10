
// substr(begin_index, substr_length)
class Solution {
public:
    vector<string> ans;
    string path;
    string s;
    vector<string> restoreIpAddresses(string s) 
    {
        this->s = s;
        backtrack(0, 0);
        return ans;
    }

    void backtrack(int startindex, int division_numbers)
    {
        if(division_numbers==3)
        {
            if(isvalid(startindex, s.size()-1))
            {
                string last_part = s.substr(startindex, s.size()-startindex);
                ans.push_back(path+last_part);
            }
            return;
        }

        string level = "";
        int origin_size = path.size();
        for(int i=startindex;i<s.size();i++)
        {
            level += s[i];
            if(!isvalid(startindex, i))
                continue;

            path += level + '.';
            backtrack(i+1, division_numbers+1);
            path = path.substr(0, origin_size); //回溯
        }
    }

    // 判断数字是否合法 -> 0 - 255 inclusive without leading zero
    bool isvalid(int start, int end)
    {
        if(end-start>2) return false;
        if(start>=s.size()) return false;
        if(start<end&&s[start]=='0') return false;
        
        int num = stoi(s.substr(start, end-start+1));
        if(num>=0&&num<=255) return true;
        else return false;
    }
};
