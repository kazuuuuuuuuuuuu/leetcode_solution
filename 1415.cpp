// 1-indexed
class Solution {
public:
    vector<char> letters = {'a', 'b', 'c'};
    int n;
    int k;
    int finish = 0;
    string getHappyString(int n, int k) 
    {
        this->n = n;
        this->k = k;
        string ans = "";
        return backtrack(0, ans, 'd');
    }

    string backtrack(int length, string &curr, char letter)
    {
        // 已经完成一个
        if(length==n)
        {
            // 标记这是第几个完成的
            finish ++;
            if(finish==k)
                return curr;
            else
                return "";
        }

        for(char &a : letters)
        {
            // 确保下一个字母和此次的字母不相同 并且每次都从尽量靠前的字母开始 
            if(a!=letter)
            {
                curr += a;
                string result = backtrack(length+1, curr, a);
                if(result!="")
                    return result;
                curr.pop_back();
            }
        }
        return "";
    }
};